#include <TFile.h>
#include <TDirectory.h>
#include <TKey.h>
#include <TGraph.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TPaveText.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TString.h>

void lognormal() {
  
  gStyle->SetOptFit(1);
  // Open the ROOT file
  TFile *file = TFile::Open("AveragedSPEWaveforms.root");
  if (!file || file->IsZombie()) {
    std::cerr << "Error opening file!" << std::endl;
    return;
  }
  
  std::ofstream outFile("PMTfittingparametersWhitespace.csv");
  if (!outFile.is_open()) {
    std::cerr << "Error opening CSV file!" << std::endl;
    return;
  }
  
  outFile << "PMTID p0 p1 p2" << std::endl;
  
  TCanvas *canvas = new TCanvas("canvas", "Log-Normal Fits", 800, 600);
  canvas->Print("lognormal.pdf[");
  
  TIter nextDir(file->GetListOfKeys());
  TKey *key;
  
  while ((key = (TKey*)nextDir())) {
    TObject *obj = key->ReadObj();
    
    // Check if the object is a directory
    if (obj->InheritsFrom("TDirectory")) {
      TDirectory *dir = (TDirectory*)obj;
      std::string dirName = dir->GetName();  // Get the directory name
      int pmtID = std::stoi(dirName); 
      
      dir->cd();  // Move to this directory
      
      TIter nextGraph(dir->GetListOfKeys());
      TKey *graphKey;
      
      while ((graphKey = (TKey*)nextGraph())) {
	TObject *graphObj = graphKey->ReadObj();
	
	if (graphObj->InheritsFrom("TGraph")) {
	  TGraph *graph = (TGraph*)graphObj;
	  
	  TGraph *positiveGraph = new TGraph();
          for (int i = 0; i < graph->GetN(); ++i) {
            double x, y;
            graph->GetPoint(i, x, y);
            if (y >= 0) {
              positiveGraph->AddPoint(x, y);
            }
          }
	  
	  canvas->Clear();
	  graph->Draw();

	  // Fit the average waveform with a log-normal function
	  TF1 *logNormalFit = new TF1("logNormalFit", "[0] * exp(-pow(log(x) - [1], 2) / (2 * pow([2], 2)))", 10, 32);
	  logNormalFit->SetParameters(19, 3.05, -0.17); // Initial guess for parameters
	  positiveGraph->Fit(logNormalFit, "R");
	  positiveGraph->GetXaxis()->SetTitle("ADC (ns)");
	  positiveGraph->GetYaxis()->SetTitle("TDC");
	  TString title = TString::Format("Average waveform and log-normal fit - PMT ID: %d", pmtID);
	  positiveGraph->SetTitle(title);
	  positiveGraph->Draw("AL same");
	  logNormalFit->Draw("same");

	  //legend on middle right corner
	  TLegend *leg = new TLegend(0.72,0.63,0.9,0.73);
	  leg->AddEntry(positiveGraph,"Average waveform","l");
	  leg->AddEntry(logNormalFit,"Log-normal fit","l");
	  leg->Draw();
	  
          double p0 = logNormalFit->GetParameter(0);
          double p1 = logNormalFit->GetParameter(1);
          double p2 = logNormalFit->GetParameter(2);
	  
          // Write PMT ID and fitting parameters to CSV file
          outFile << pmtID << " " << p0 << " " << p1 << " " << p2 << std::endl;
	  canvas->Print("lognormal.pdf");
	}
      }
      file->cd();
    }
  }
  // Close the PDF
  canvas->Print("lognormal.pdf]");
  // Close the file
  file->Close();
  outFile.close();
}

