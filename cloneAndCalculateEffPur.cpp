#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TEfficiency.h>
#include <TStyle.h> 
#include <TColor.h>  
void cloneAndCalculateEffPur() {
  gStyle->Reset(); // Reset to default settings
  gStyle->SetPalette(kRainBow); // Set the desired palette again

  // Open the ROOT file that contains your histograms
    TFile *file = TFile::Open("SelectionEffnPurityCombined0924.root");
    //  gStyle->SetPalette(kRainBow);
    TDirectory *dir = (TDirectory*)file->Get("Histograms");
    // Retrieve the histograms from the file
    //Neutrino Energy
    TH1D *h_nTotalTrueNeutronsPromptNE = (TH1D*)dir->Get("h_nTotalTrueNeutronsPromptNE");
    TH1D *h_nTotalTrueNeutronsDelayedNE  = (TH1D*)dir->Get("h_nTotalTrueNeutronsDelayedNE");
    TH1D *h_nAllSelectedClustersPromptNE  = (TH1D*)dir->Get("h_nAllSelectedClustersPromptNE");
    TH1D *h_nSelectedTrueNeutronsPromptNE  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsPromptNE");
    TH1D *h_nAllSelectedClustersDelayedNE  = (TH1D*)dir->Get("h_nAllSelectedClustersDelayedNE");
    TH1D *h_nSelectedTrueNeutronsDelayedNE  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsDelayedNE");

    //X-Z position
    TH2D *h_nTotalTrueNeutronsPromptTVtxXZ  = (TH2D*)dir->Get("h_nTotalTrueNeutronsPromptTVtxXZ");
    TH2D *h_nTotalTrueNeutronsDelayedTVtxXZ  = (TH2D*)dir->Get("h_nTotalTrueNeutronsDelayedTVtxXZ");
    TH2D *h_nAllSelectedClustersPromptTVtxXZ  = (TH2D*)dir->Get("h_nAllSelectedClustersPromptTVtxXZ");
    TH2D *h_nSelectedTrueNeutronsPromptTVtxXZ  = (TH2D*)dir->Get("h_nSelectedTrueNeutronsPromptTVtxXZ");
    TH2D *h_nAllSelectedClustersDelayedTVtxXZ  = (TH2D*)dir->Get("h_nAllSelectedClustersDelayedTVtxXZ");
    TH2D *h_nSelectedTrueNeutronsDelayedTVtxXZ  = (TH2D*)dir->Get("h_nSelectedTrueNeutronsDelayedTVtxXZ");

    //X-Y position
    TH2D *h_nTotalTrueNeutronsPromptTVtxXY  = (TH2D*)dir->Get("h_nTotalTrueNeutronsPromptTVtxXY");
    TH2D *h_nTotalTrueNeutronsDelayedTVtxXY  = (TH2D*)dir->Get("h_nTotalTrueNeutronsDelayedTVtxXY");
    TH2D *h_nAllSelectedClustersPromptTVtxXY  = (TH2D*)dir->Get("h_nAllSelectedClustersPromptTVtxXY");
    TH2D *h_nSelectedTrueNeutronsPromptTVtxXY  = (TH2D*)dir->Get("h_nSelectedTrueNeutronsPromptTVtxXY");
    TH2D *h_nAllSelectedClustersDelayedTVtxXY  = (TH2D*)dir->Get("h_nAllSelectedClustersDelayedTVtxXY");
    TH2D *h_nSelectedTrueNeutronsDelayedTVtxXY  = (TH2D*)dir->Get("h_nSelectedTrueNeutronsDelayedTVtxXY");

    //Y-Z position
    TH2D *h_nTotalTrueNeutronsPromptTVtxYZ  = (TH2D*)dir->Get("h_nTotalTrueNeutronsPromptTVtxYZ");
    TH2D *h_nTotalTrueNeutronsDelayedTVtxYZ  = (TH2D*)dir->Get("h_nTotalTrueNeutronsDelayedTVtxYZ");
    TH2D *h_nAllSelectedClustersPromptTVtxYZ  = (TH2D*)dir->Get("h_nAllSelectedClustersPromptTVtxYZ");
    TH2D *h_nSelectedTrueNeutronsPromptTVtxYZ  = (TH2D*)dir->Get("h_nSelectedTrueNeutronsPromptTVtxYZ");
    TH2D *h_nAllSelectedClustersDelayedTVtxYZ  = (TH2D*)dir->Get("h_nAllSelectedClustersDelayedTVtxYZ");
    TH2D *h_nSelectedTrueNeutronsDelayedTVtxYZ  = (TH2D*)dir->Get("h_nSelectedTrueNeutronsDelayedTVtxYZ");

    //Cluster Time
    TH1D *h_nTotalTrueNeutronsPromptCT = (TH1D*)dir->Get("h_nTotalTrueNeutronsPromptCT");
    TH1D *h_nTotalTrueNeutronsDelayedCT  = (TH1D*)dir->Get("h_nTotalTrueNeutronsDelayedCT");
    TH1D *h_nAllSelectedClustersPromptCT  = (TH1D*)dir->Get("h_nAllSelectedClustersPromptCT");
    TH1D *h_nSelectedTrueNeutronsPromptCT  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsPromptCT");
    TH1D *h_nAllSelectedClustersDelayedCT  = (TH1D*)dir->Get("h_nAllSelectedClustersDelayedCT");
    TH1D *h_nSelectedTrueNeutronsDelayedCT  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsDelayedCT");


    //Particle PDG
    TH1D *h_nTotalTrueNeutronsPromptPDG = (TH1D*)dir->Get("h_nTotalTrueNeutronsPromptPDG");
    TH1D *h_nTotalTrueNeutronsDelayedPDG  = (TH1D*)dir->Get("h_nTotalTrueNeutronsDelayedPDG");
    TH1D *h_nAllSelectedClustersPromptPDG  = (TH1D*)dir->Get("h_nAllSelectedClustersPromptPDG");
    TH1D *h_nSelectedTrueNeutronsPromptPDG  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsPromptPDG");
    TH1D *h_nAllSelectedClustersDelayedPDG  = (TH1D*)dir->Get("h_nAllSelectedClustersDelayedPDG");
    TH1D *h_nSelectedTrueNeutronsDelayedPDG  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsDelayedPDG");

    //N hits cluster
    TH1D *h_nTotalTrueNeutronsPromptNhits = (TH1D*)dir->Get("h_nTotalTrueNeutronsPromptNhits");
    TH1D *h_nTotalTrueNeutronsDelayedNhits  = (TH1D*)dir->Get("h_nTotalTrueNeutronsDelayedNhits");
    TH1D *h_nAllSelectedClustersPromptNhits  = (TH1D*)dir->Get("h_nAllSelectedClustersPromptNhits");
    TH1D *h_nSelectedTrueNeutronsPromptNhits  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsPromptNhits");
    TH1D *h_nAllSelectedClustersDelayedNhits  = (TH1D*)dir->Get("h_nAllSelectedClustersDelayedNhits");
    TH1D *h_nSelectedTrueNeutronsDelayedNhits  = (TH1D*)dir->Get("h_nSelectedTrueNeutronsDelayedNhits");

    //gStyle->SetPalette(kRainBow);
    
    //eff and pur for Neutrino Energy
    TH1D *NEPromptEff = (TH1D*)h_nSelectedTrueNeutronsPromptNE->Clone("NEPromptEff");
    NEPromptEff->Divide(h_nTotalTrueNeutronsPromptNE);
    NEPromptEff->SetTitle("Efficiency for Neutrino Energy Prompt");
    //    NEPromptEff->SetMinimum(0);
    // NEPromptEff->SetMaximum(1);
      
    TH1D *NEPromptPurr = (TH1D*)h_nSelectedTrueNeutronsPromptNE->Clone("NEPromptPurr");
    NEPromptPurr->Divide(h_nAllSelectedClustersPromptNE);
    NEPromptPurr->SetTitle("Purity for Neutrino Energy Prompt");
    //    NEPromptPurr->SetMinimum(0);
    //    NEPromptPurr->SetMaximum(1);
    TH1D *NEDelayedEff = (TH1D*)h_nSelectedTrueNeutronsDelayedNE->Clone("NEDelayedEff");
    NEDelayedEff->Divide(h_nTotalTrueNeutronsDelayedNE);
    NEDelayedEff->SetTitle("Efficiency for Neutrino Energy Delayed");
    //    NEDelayedEff ->SetMinimum(0);
    //    NEDelayedEff->SetMaximum(1);
    
    TH1D *NEDelayedPurr = (TH1D*)h_nSelectedTrueNeutronsDelayedNE->Clone("NEDelayedPurr");
    NEDelayedPurr->Divide(h_nAllSelectedClustersDelayedNE);
    NEDelayedPurr->SetTitle("Purity for Neutrino Energy Delayed");
    //    NEDelayedPurr->SetMinimum(0);
    //    NEDelayedPurr->SetMaximum(1);
    
    //eff and pur for True vertex XZ
    TH2D *TVtxXZPromptEff = (TH2D*)h_nSelectedTrueNeutronsPromptTVtxXZ->Clone("TVtxXZPromptEff");
    TVtxXZPromptEff->Divide(h_nTotalTrueNeutronsPromptTVtxXZ);
    TVtxXZPromptEff->SetTitle("Efficiency for True Vertex XZ Prompt");
    //    TVtxXZPromptEff->SetMinimum(0);
    //    TVtxXZPromptEff->SetMaximum(1);
    
    TH2D *TVtxXZPromptPurr = (TH2D*)h_nSelectedTrueNeutronsPromptTVtxXZ->Clone("TVtxXZPromptPurr");
    TVtxXZPromptPurr->Divide(h_nAllSelectedClustersPromptTVtxXZ);
    TVtxXZPromptPurr->SetTitle("Purity for True vertex XZ Prompt");
    //    TVtxXZPromptPurr->SetMinimum(0);
    //    TVtxXZPromptPurr->SetMaximum(1);
    
    TH2D *TVtxXZDelayedEff = (TH2D*)h_nSelectedTrueNeutronsDelayedTVtxXZ->Clone("TVtxXZDelayedEff");
    TVtxXZDelayedEff->Divide(h_nTotalTrueNeutronsDelayedTVtxXZ);
    TVtxXZDelayedEff->SetTitle("Efficiency for True vertex XZ Delayed");
    //    TVtxXZDelayedEff->SetMinimum(0);
    //    TVtxXZDelayedEff->SetMaximum(1);
    
    TH2D *TVtxXZDelayedPurr	= (TH2D*)h_nSelectedTrueNeutronsDelayedTVtxXZ->Clone("TVtxXZDelayedPurr");
    TVtxXZDelayedPurr->Divide(h_nAllSelectedClustersDelayedTVtxXZ);
    TVtxXZDelayedPurr->SetTitle("Purity for True Vertex XZ Delayed");
    //    TVtxXZDelayedPurr->SetMinimum(0);
    //    TVtxXZDelayedPurr->SetMaximum(1);
    
    //eff and pur for True vertex XY
    TH2D *TVtxXYPromptEff = (TH2D*)h_nSelectedTrueNeutronsPromptTVtxXY->Clone("TVtxXYPromptEff");
    TVtxXYPromptEff->Divide(h_nTotalTrueNeutronsPromptTVtxXY);
    TVtxXYPromptEff->SetTitle("Efficiency for True vertex XY Prompt");
    //    TVtxXYPromptEff->SetMinimum(0);
    //    TVtxXYPromptEff->SetMaximum(1);
    
    TH2D *TVtxXYPromptPurr = (TH2D*)h_nSelectedTrueNeutronsPromptTVtxXY->Clone("TVtxXYPromptPurr");
    TVtxXYPromptPurr->Divide(h_nAllSelectedClustersPromptTVtxXY);
    TVtxXYPromptPurr->SetTitle("Purity for True vertex XY Prompt");
    //    TVtxXYPromptPurr->SetMinimum(0);
    //    TVtxXYPromptPurr->SetMaximum(1);
    
    TH2D *TVtxXYDelayedEff = (TH2D*)h_nSelectedTrueNeutronsDelayedTVtxXY->Clone("TVtxXYDelayedEff");
    TVtxXYDelayedEff->Divide(h_nTotalTrueNeutronsDelayedTVtxXY);
    TVtxXYDelayedEff->SetTitle("Efficiency for True vertex XY Delayed");
    //    TVtxXYDelayedEff->SetMinimum(0);
    //    TVtxXYDelayedEff->SetMaximum(1);
    
    TH2D *TVtxXYDelayedPurr  = (TH2D*)h_nSelectedTrueNeutronsDelayedTVtxXY->Clone("TVtxXYDelayedPurr");
    TVtxXYDelayedPurr->Divide(h_nAllSelectedClustersDelayedTVtxXY);
    TVtxXYDelayedPurr->SetTitle("Purity for True vertex XY Delayed");
    //    TVtxXYDelayedPurr->SetMinimum(0);
    //    TVtxXYDelayedPurr->SetMaximum(1);
    
    //eff and pur for True vertex YZ
    TH2D *TVtxYZPromptEff = (TH2D*)h_nSelectedTrueNeutronsPromptTVtxYZ->Clone("TVtxYZPromptEff");
    TVtxYZPromptEff->Divide(h_nTotalTrueNeutronsPromptTVtxYZ);
    TVtxYZPromptEff->SetTitle("Efficiency for True vertex YZ Prompt");
    //    TVtxYZPromptEff->SetMinimum(0);
    //    TVtxYZPromptEff->SetMaximum(1);
    
    TH2D *TVtxYZPromptPurr = (TH2D*)h_nSelectedTrueNeutronsPromptTVtxYZ->Clone("TVtxYZPromptPurr");
    TVtxYZPromptPurr->Divide(h_nAllSelectedClustersPromptTVtxYZ);
    TVtxYZPromptPurr->SetTitle("Purity for True vertex YZ prompt");
    //    TVtxYZPromptPurr->SetMinimum(0);
    //    TVtxYZPromptPurr->SetMaximum(1);
    
    TH2D *TVtxYZDelayedEff = (TH2D*)h_nSelectedTrueNeutronsDelayedTVtxYZ->Clone("TVtxYZDelayedEff");
    TVtxYZDelayedEff->Divide(h_nTotalTrueNeutronsDelayedTVtxYZ);
    TVtxYZDelayedEff->SetTitle("Efficiency for True vertex YZ Delayed");
    //    TVtxYZDelayedEff->SetMinimum(0);
    //    TVtxYZDelayedEff->SetMaximum(1);
    
    TH2D *TVtxYZDelayedPurr = (TH2D*)h_nSelectedTrueNeutronsDelayedTVtxYZ->Clone("TVtxYZDelayedPurr");
    TVtxYZDelayedPurr->Divide(h_nAllSelectedClustersDelayedTVtxYZ);
    TVtxYZDelayedPurr->SetTitle("Purity for True vertex YZ Delayed");
    //    TVtxYZDelayedPurr->SetMinimum(0);
    //    TVtxYZDelayedPurr->SetMaximum(1);
    
    //eff and pur for Cluster Time
    TH1D *CTPromptEff = (TH1D*)h_nSelectedTrueNeutronsPromptCT->Clone("CTPromptEff");
    CTPromptEff->Divide(h_nTotalTrueNeutronsPromptCT);
    CTPromptEff->SetTitle("Efficiency for Cluster Time Prompt");
    //    CTPromptEff->SetMinimum(0);
    //    CTPromptEff->SetMaximum(1);
    
    TH1D *CTPromptPurr = (TH1D*)h_nSelectedTrueNeutronsPromptCT->Clone("CTPromptPurr");
    CTPromptPurr->Divide(h_nAllSelectedClustersPromptCT);
    CTPromptPurr->SetTitle("Purity for Cluster Time Prompt");
    //    CTPromptPurr->SetMinimum(0);
    //    CTPromptPurr->SetMaximum(1);
    
    TH1D *CTDelayedEff = (TH1D*)h_nSelectedTrueNeutronsDelayedCT->Clone("CTDelayedEff");
    CTDelayedEff->Divide(h_nTotalTrueNeutronsDelayedCT);
    CTDelayedEff->SetTitle("Efficiency for Cluster Time Delayed");
    //    CTDelayedEff->SetMinimum(0);
    //    CTDelayedEff->SetMaximum(1);
    
    TH1D *CTDelayedPurr	= (TH1D*)h_nSelectedTrueNeutronsDelayedCT->Clone("CTDelayedPurr");
    CTDelayedPurr->Divide(h_nAllSelectedClustersDelayedCT);
    CTDelayedPurr->SetTitle("Purity for Cluster Time Delayed");
    //    CTDelayedPurr->SetMinimum(0);
    //    CTDelayedPurr->SetMaximum(1);
    
    //eff and pur for Particle PDG
    TH1D *PDGPromptEff = (TH1D*)h_nSelectedTrueNeutronsPromptPDG->Clone("PDGPromptEff");
    PDGPromptEff->Divide(h_nTotalTrueNeutronsPromptPDG);
    PDGPromptEff->SetTitle("Efficiency for Particle PDG prompt");
    
    TH1D *PDGPromptPurr = (TH1D*)h_nSelectedTrueNeutronsPromptPDG->Clone("PDGPromptPurr");
    PDGPromptPurr->Divide(h_nAllSelectedClustersPromptPDG);
    PDGPromptPurr->SetTitle("Purity for Particle PDG Prompt");

    TH1D *PDGDelayedEff = (TH1D*)h_nSelectedTrueNeutronsDelayedPDG->Clone("PDGDelayedEff");
    PDGDelayedEff->Divide(h_nTotalTrueNeutronsDelayedPDG);
    PDGDelayedEff->SetTitle("Efficiency for Particle PDG Delayed");

    TH1D *PDGDelayedPurr = (TH1D*)h_nSelectedTrueNeutronsDelayedPDG->Clone("PDGDelayedPurr");
    PDGDelayedPurr->Divide(h_nAllSelectedClustersDelayedPDG);
    PDGDelayedPurr->SetTitle("Purity for Particle PDG Delayed");

    //eff and pur for N Hits
    // TH1D *NEPromptEff = (TH1D*)h_nSelectedTrueNeutronsPromptNhits->Clone("NhitsPromptEff");
    // NhitsPromptEff->Divide(h_nTotalTrueNeutronsPromptNhits);

    TH1D *NhitsPromptPurr = (TH1D*)h_nSelectedTrueNeutronsPromptNhits->Clone("NhitsPromptPurr");
    NhitsPromptPurr->Divide(h_nAllSelectedClustersPromptNhits);
    NhitsPromptPurr->SetTitle("Purity for N hits cluster Prompt");
    //    NhitsPromptPurr->SetMinimum(0);
    //    NhitsPromptPurr->SetMaximum(1);
    // TH1D *NhitsDelayedEff = (TH1D*)h_nSelectedTrueNeutronsDelayedNhits->Clone("NhitsDelayedEff");
    // NhitsDelayedEff->Divide("h_nTotalTrueNeutronsDelayedNhits");

    TH1D *NhitsDelayedPurr = (TH1D*)h_nSelectedTrueNeutronsDelayedNhits->Clone("NhitsDelayedPurr");
    NhitsDelayedPurr->Divide(h_nAllSelectedClustersDelayedNhits);
    NhitsDelayedPurr->SetTitle("Purity for N hits cluster Delayed");
    //    NhitsDelayedPurr->SetMinimum(0);
    //    NhitsDelayedPurr->SetMaximum(1);

    // Save the results to a new ROOT file
    TFile *outputFile = new TFile("SelectionEffnPurityAll0924.root", "RECREATE");
    NEPromptEff->Write();
    NEPromptPurr->Write();
    NEDelayedEff->Write();
    NEDelayedPurr->Write();

    TVtxXZPromptEff->Write();
    TVtxXZPromptPurr->Write();
    TVtxXZDelayedEff->Write();
    TVtxXZDelayedPurr->Write();

    TVtxXYPromptEff->Write();
    TVtxXYPromptPurr->Write();
    TVtxXYDelayedEff->Write();
    TVtxXYDelayedPurr->Write();

    TVtxYZPromptEff->Write();
    TVtxYZPromptPurr->Write();
    TVtxYZDelayedEff->Write();
    TVtxYZDelayedPurr->Write();

    CTPromptEff->Write();
    CTPromptPurr->Write();
    CTDelayedEff->Write();
    CTDelayedPurr->Write();

    PDGPromptEff->Write();
    PDGPromptPurr->Write();
    PDGDelayedEff->Write();
    PDGDelayedPurr->Write();

    //NhitsPromptEff->Write();
    NhitsPromptPurr->Write();
    // NhitsDelayedEff->Write();
    NhitsDelayedPurr->Write();

    
    // Close the files
    outputFile->Close();
    file->Close();
}

int main() {
    cloneAndCalculateEffPur();
    return 0;
}
B
