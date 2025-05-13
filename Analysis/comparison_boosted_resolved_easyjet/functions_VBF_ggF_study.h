#include "VBF_ggF_separation_study.h"
#include "histograms_VBF_ggF_separation_study.h"
#include "input_output_functions.h"
#include "../../Plotting/AtlasStyle/AtlasStyle.C"
#include "../../Plotting/AtlasStyle/AtlasUtils.C"
#include "../../Plotting/AtlasStyle/AtlasLabels.C"

// *************************************
// Declaration of some functions
// *************************************

void fix_underflow_overflow(TH1F* histo);
void compute_variables_for_topological_processes();
void pairs_small_jets();
void boosted_candidates();


void fix_underflow_overflow(TH1F* histo){
  
  // Adding the underflow to the first bin
  histo->AddBinContent(1, histo->GetBinContent(0));
  
  // Adding the overflow to the last bin
  histo->AddBinContent(histo->GetNbinsX(), histo->GetBinContent(histo->GetNbinsX() + 1));

}

// This functions computes some useful variables to determine characteristics of topological processes
void compute_variables_for_topological_processes(){

  two_jets_j12_m = -99;
  two_jets_j12_pt = -99;
  two_jets_j12_eta = -99;
  two_jets_j12_phi = -99;
  two_jets_j12_deta = -99;
  two_jets_j12_dphi = -99;
  two_jets_j12_dR = -99;
  
  if( is_jet12_matched == true ){

    TLorentzVector jet1 = TLorentzVector();
    TLorentzVector jet2 = TLorentzVector();
    
    float jet1_pt = recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1_VBF_topology);
    float jet1_eta = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1_VBF_topology);
    float jet1_phi = recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1_VBF_topology);
    float jet1_m = recojet_antikt4PFlow_m___NOSYS->at(idx_jet1_VBF_topology);
    
    float jet2_pt = recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2_VBF_topology);
    float jet2_eta = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2_VBF_topology);
    float jet2_phi = recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2_VBF_topology);
    float jet2_m = recojet_antikt4PFlow_m___NOSYS->at(idx_jet2_VBF_topology);
    
    jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
    jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

    TLorentzVector jet12 = TLorentzVector();
    jet12 = jet1 + jet2;
    two_jets_j12_m = jet12.M();
    two_jets_j12_pt = jet12.Pt();
    two_jets_j12_eta = jet12.Eta();
    two_jets_j12_phi = jet12.Phi();
    two_jets_j12_deta = std::abs(jet1.Eta()-jet2.Eta());
    two_jets_j12_dphi = std::abs(jet1.Phi()-jet2.Phi());
    two_jets_j12_dR = jet1.DeltaR(jet2);
    
  }
  
}

// This functions pairs the 2 small jets in the VBF topology
void pairs_small_jets(){

  idx_jet1_VBF_topology = -99;
  idx_jet2_VBF_topology = -99;
  is_jet12_matched = false;
  
  float dR_min = 1.0;
  
  if(is_boosted_bbtautau == true){

    std::vector<int> candidates_smallJets;
      
    for(int ii=0; ii<recojet_antikt4PFlow_pt___NOSYS->size(); ii++){

      TLorentzVector small_jet = TLorentzVector();
      TLorentzVector large_R1_jet = TLorentzVector();
      TLorentzVector large_R2_jet = TLorentzVector();
      
      float small_jet_pt = recojet_antikt4PFlow_pt___NOSYS->at(ii);
      float small_jet_eta = recojet_antikt4PFlow_eta___NOSYS->at(ii);
      float small_jet_phi = recojet_antikt4PFlow_phi___NOSYS->at(ii);
      float small_jet_m = recojet_antikt4PFlow_m___NOSYS->at(ii);

      float large_R1_jet_pt = recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb);
      float large_R1_jet_eta = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_bb);
      float large_R1_jet_phi = recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_bb);
      float large_R1_jet_m = recojet_antikt10UFO_m___NOSYS->at(idx_boosted_bb);

      float large_R2_jet_pt = recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau);
      float large_R2_jet_eta = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_tautau);
      float large_R2_jet_phi = recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_tautau);
      float large_R2_jet_m = recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau);
      
      large_R1_jet.SetPtEtaPhiM(large_R1_jet_pt, large_R1_jet_eta, large_R1_jet_phi, large_R1_jet_m);
      large_R2_jet.SetPtEtaPhiM(large_R2_jet_pt, large_R2_jet_eta, large_R2_jet_phi, large_R2_jet_m);
      small_jet.SetPtEtaPhiM(small_jet_pt, small_jet_eta, small_jet_phi, small_jet_m);
      
      float deltaR_smallJet_largeR1_jet = large_R1_jet.DeltaR(small_jet);
      float deltaR_smallJet_largeR2_jet = large_R2_jet.DeltaR(small_jet);
      
      if( deltaR_smallJet_largeR1_jet>dR_min && deltaR_smallJet_largeR2_jet>dR_min ){
	candidates_smallJets.push_back(ii);
      }
    }

    if( candidates_smallJets.size()>=2 ){

      float current_jet12_m = 0;
      
      for(int ii=0; ii<candidates_smallJets.size(); ii++){
	for(int jj=ii+1; jj<candidates_smallJets.size(); jj++){

	  int idx_jet1 = candidates_smallJets.at(ii);
	  int idx_jet2 = candidates_smallJets.at(jj);
	  
	  TLorentzVector jet1 = TLorentzVector();
	  TLorentzVector jet2 = TLorentzVector();

	  float jet1_pt = recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1);
	  float jet1_eta = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1);
	  float jet1_phi = recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1);
	  float jet1_m = recojet_antikt4PFlow_m___NOSYS->at(idx_jet1);

	  float jet2_pt = recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2);
	  float jet2_eta = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2);
	  float jet2_phi = recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2);
	  float jet2_m = recojet_antikt4PFlow_m___NOSYS->at(idx_jet2);
	    
	  jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
	  jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

	  TLorentzVector jet12 = TLorentzVector();
	  jet12 = jet1 + jet2;
	  float jet12_m = jet12.M();

	  if( jet12_m>current_jet12_m ){
	    current_jet12_m = jet12_m;
	    idx_jet1_VBF_topology = idx_jet1;
	    idx_jet2_VBF_topology = idx_jet2;
	    is_jet12_matched = true;
	  }
	}
      }
    }
  }  
}

// This functions selects the recojets largeR-jets that are candidates to be boosted bb or boosted tautau
void boosted_candidates(){

  idx_boosted_bb = -99;
  is_boosted_bb = false;
  idx_boosted_tautau = -99;
  is_boosted_tautau = false;
  is_boosted_bbtautau = false;

  count_bb_candidates = 0;
  count_tautau_candidates = 0;
  
  for(int ii=0; ii<recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS->size(); ii++){
    if(recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS->at(ii) == 1){
      if( count_bb_candidates == 0){
	idx_boosted_bb = ii;
	is_boosted_bb = true;
      }
      count_bb_candidates++;
    }
    else{
      if( count_tautau_candidates == 0){
	idx_boosted_tautau = ii;
	is_boosted_tautau = true;
      }
      count_tautau_candidates++;
    }
  }

  if( is_boosted_bb == true && is_boosted_tautau == true ){
    is_boosted_bbtautau = true;
  }
  
}
