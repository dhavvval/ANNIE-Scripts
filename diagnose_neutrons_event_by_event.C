// save as diagnose_neutrons_event_by_event.C
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <TH2D.h>
#include <TCanvas.h>
#include <TStyle.h>

void diagnose_neutrons_event_by_event(const char* filename="/Users/dajana/Documents/ANNIETree_MC.root") {
  TFile f(filename, "READ");
  if (f.IsZombie()) { std::cout << "Cannot open file\n"; return; }

  TTree* t = (TTree*)f.Get("Event");
  if (!t) { std::cout << "No Event tree\n"; return; }

  int eventNumber = -1;
  std::vector<unsigned long>* pmt = nullptr;
  std::vector<double>* ht = nullptr;
  std::vector<int>* na_tid = nullptr;
  std::vector<int>* na_pdg = nullptr;
  std::vector<int>* na_class = nullptr;
  
  t->SetBranchAddress("eventNumber", &eventNumber);
  t->SetBranchAddress("DirectParent_PMTID", &pmt);
  t->SetBranchAddress("DirectParent_HitTime", &ht);
  t->SetBranchAddress("DirectParent_NeutronAncestorTrackID", &na_tid);
  t->SetBranchAddress("DirectParent_NeutronAncestorPDG", &na_pdg);
  t->SetBranchAddress("DirectParent_NeutronAncestorClass", &na_class);
 
  TH2D* hHeatmap = new TH2D("hHeatmap", "Neutron Multiplicity wrt Total MCHits of the Event", 15, 0, 15, 10, 0, 200);
hHeatmap->SetDirectory(0);
  for (Long64_t e = 0; e < t->GetEntries(); ++e) {
    t->GetEntry(e);

    std::map<int,int> neutronHitRefs;   // trackID -> number of hit-level references
    std::map<int, int> neutronClasses;
    std::set<int> uniqueNeutrons;

    size_t n = na_tid ? na_tid->size() : 0;
    for (size_t i = 0; i < n; ++i) {
      int id  = na_tid->at(i);
      int pdg = na_pdg->at(i);
      int nClass = (na_class) ? na_class->at(i) : -5;

      if (id != -5 && pdg == 2112) {
        neutronHitRefs[id]++;
        uniqueNeutrons.insert(id);
        neutronClasses[id] = nClass; 
     }
    }

    std::cout << " eventNumber=" << eventNumber
              << " uniqueNeutronAncestors=" << uniqueNeutrons.size()
              << " #MCHitsToAllNeutrons=";
    int total=0; for (auto const& kv: neutronHitRefs) total += kv.second;
    std::cout << total << "\n";

    hHeatmap->Fill(uniqueNeutrons.size(), total);
    
    for (auto const& kv : neutronHitRefs) {
      int trackID = kv.first;
      int hitCount = kv.second;
      int nClass = neutronClasses[trackID];

std::string classDesc;
      switch(nClass) {
        case 1:  classDesc = "Primary"; break;
        case 2:  classDesc = "from Proton"; break;
        case 3:  classDesc = "from Neutron (scatter)"; break;
        case 4:  classDesc = "from Other"; break;
        default: classDesc = "Unknown"; break;
      }


      std::cout << "  neutronTrackID=" << kv.first
                << " | Class=" << nClass << " (" << classDesc << ")"
                << " #MCHits=" << kv.second << "\n";
    }
  }
TCanvas *c1 = new TCanvas("c1", "Diagnosis Canvas", 800, 600);
hHeatmap->Draw("COLZ");
gStyle->SetPalette(kRainBow);
c1->Update();
 c1->Modified();
}
