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
void default_values_for_topological_processes();

void fix_underflow_overflow(TH1F* histo){
  
  // Adding the underflow to the first bin
  histo->AddBinContent(1, histo->GetBinContent(0));
  
  // Adding the overflow to the last bin
  histo->AddBinContent(histo->GetNbinsX(), histo->GetBinContent(histo->GetNbinsX() + 1));

}

void default_values_for_topological_processes(){

  // Two small jets j1 and j2 variables
  two_jets_j12_m = -99;
  two_jets_j12_pt = -99;
  two_jets_j12_eta = -99;
  two_jets_j12_phi = -99;
  two_jets_j12_deta = -99;
  two_jets_j12_dphi = -99;
  two_jets_j12_dR = -99;

  // Boosted bb and boosted tautau variables
  boosted_bb_tautau_system_m = -99;
  boosted_bb_tautau_system_pt = -99;
  boosted_bb_tautau_system_eta = -99;
  boosted_bb_tautau_system_phi = -99;
  boosted_bb_tautau_system_deta = -99;
  boosted_bb_tautau_system_dphi = -99;
  boosted_bb_tautau_system_dR = -99;

  // Boosted bb and small jets j1 variables
  boosted_bb_j1_system_m = -99;
  boosted_bb_j1_system_pt = -99;
  boosted_bb_j1_system_eta = -99;
  boosted_bb_j1_system_phi = -99;
  boosted_bb_j1_system_deta = -99;
  boosted_bb_j1_system_dphi = -99;
  boosted_bb_j1_system_dR = -99;

  // Boosted tautau and small jets j1 variables
  boosted_tautau_j1_system_m = -99;
  boosted_tautau_j1_system_pt = -99;
  boosted_tautau_j1_system_eta = -99;
  boosted_tautau_j1_system_phi = -99;
  boosted_tautau_j1_system_deta = -99;
  boosted_tautau_j1_system_dphi = -99;
  boosted_tautau_j1_system_dR = -99;
  
  // Boosted bb and small jets j2 variables
  boosted_bb_j2_system_m = -99;
  boosted_bb_j2_system_pt = -99;
  boosted_bb_j2_system_eta = -99;
  boosted_bb_j2_system_phi = -99;
  boosted_bb_j2_system_deta = -99;
  boosted_bb_j2_system_dphi = -99;
  boosted_bb_j2_system_dR = -99;
  
  // Boosted tautau and small jets j1 variables
  boosted_tautau_j2_system_m = -99;
  boosted_tautau_j2_system_pt = -99;
  boosted_tautau_j2_system_eta = -99;
  boosted_tautau_j2_system_phi = -99;
  boosted_tautau_j2_system_deta = -99;
  boosted_tautau_j2_system_dphi = -99;
  boosted_tautau_j2_system_dR = -99;

  // All jets system variables
  boosted_all_jets_system_m = -99;
  boosted_all_jets_system_pt = -99;
  boosted_all_jets_system_eta = -99;
  boosted_all_jets_system_phi = -99;
  boosted_all_jets_system_deta = -99;
  boosted_all_jets_system_dphi = -99;
  boosted_all_jets_system_dR = -99;

}

// This functions computes some useful variables to determine characteristics of topological processes
void compute_variables_for_topological_processes(){

  default_values_for_topological_processes();
    
  if( is_jet12_matched == true ){

    TLorentzVector jet1 = TLorentzVector();
    TLorentzVector jet2 = TLorentzVector();
    TLorentzVector Hbb = TLorentzVector();
    TLorentzVector Htautau = TLorentzVector();
    TLorentzVector jet12 = TLorentzVector();
    TLorentzVector bb_jet1 = TLorentzVector();
    TLorentzVector bb_jet2 = TLorentzVector();
    TLorentzVector tautau_jet1 = TLorentzVector();
    TLorentzVector tautau_jet2 = TLorentzVector();
    TLorentzVector bb_tautau = TLorentzVector();
    TLorentzVector all_jets = TLorentzVector();
    
    float jet1_pt = recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1_VBF_topology);
    float jet1_eta = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1_VBF_topology);
    float jet1_phi = recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1_VBF_topology);
    float jet1_m = recojet_antikt4PFlow_m___NOSYS->at(idx_jet1_VBF_topology);
    
    float jet2_pt = recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2_VBF_topology);
    float jet2_eta = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2_VBF_topology);
    float jet2_phi = recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2_VBF_topology);
    float jet2_m = recojet_antikt4PFlow_m___NOSYS->at(idx_jet2_VBF_topology);

    float Hbb_pt = recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb);
    float Hbb_eta = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_bb);
    float Hbb_phi = recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_bb);
    float Hbb_m = recojet_antikt10UFO_m___NOSYS->at(idx_boosted_bb);
    
    float Htautau_pt = recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau);
    float Htautau_eta = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_tautau);
    float Htautau_phi = recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_tautau);
    float Htautau_m = recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau);
      
    jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
    jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);
    Hbb.SetPtEtaPhiM(Hbb_pt, Hbb_eta, Hbb_phi, Hbb_m);
    Htautau.SetPtEtaPhiM(Htautau_pt, Htautau_eta, Htautau_phi, Htautau_m);
    
    jet12 = jet1 + jet2;
    bb_jet1 = Hbb + jet1;
    bb_jet2 = Hbb + jet2;
    tautau_jet1 = Htautau + jet1;
    tautau_jet2 = Htautau + jet2;
    bb_tautau = Hbb + Htautau;
    all_jets = Hbb + Htautau + jet1 + jet2;

    two_jets_j12_m = jet12.M();
    two_jets_j12_pt = jet12.Pt();
    two_jets_j12_eta = jet12.Eta();
    two_jets_j12_phi = jet12.Phi();
    two_jets_j12_deta = std::abs(jet1.Eta()-jet2.Eta());
    two_jets_j12_dphi = std::abs(jet1.Phi()-jet2.Phi());
    two_jets_j12_dR = jet1.DeltaR(jet2);

    // Boosted bb and boosted tautau variables
    boosted_bb_tautau_system_m = bb_tautau.M();
    boosted_bb_tautau_system_pt = bb_tautau.Pt();
    boosted_bb_tautau_system_eta = bb_tautau.Eta();
    boosted_bb_tautau_system_phi = bb_tautau.Phi();
    boosted_bb_tautau_system_deta = std::abs(Hbb.Eta()-Htautau.Eta());
    boosted_bb_tautau_system_dphi = std::abs(Hbb.Phi()-Htautau.Phi());
    boosted_bb_tautau_system_dR = Hbb.DeltaR(Htautau);
    
    // Boosted bb and small jets j1 variables
    boosted_bb_j1_system_m = bb_jet1.M();
    boosted_bb_j1_system_pt = bb_jet1.Pt();
    boosted_bb_j1_system_eta = bb_jet1.Eta();
    boosted_bb_j1_system_phi = bb_jet1.Phi();
    boosted_bb_j1_system_deta = std::abs(Hbb.Eta()-jet1.Eta());
    boosted_bb_j1_system_dphi = std::abs(Hbb.Phi()-jet1.Phi());
    boosted_bb_j1_system_dR = Hbb.DeltaR(jet1);
    
    // Boosted tautau and small jets j1 variables
    boosted_tautau_j1_system_m = tautau_jet1.M();
    boosted_tautau_j1_system_pt = tautau_jet1.Pt();
    boosted_tautau_j1_system_eta = tautau_jet1.Eta();
    boosted_tautau_j1_system_phi = tautau_jet1.Phi();
    boosted_tautau_j1_system_deta = std::abs(Htautau.Eta()-jet1.Eta());
    boosted_tautau_j1_system_dphi = std::abs(Htautau.Phi()-jet1.Phi());
    boosted_tautau_j1_system_dR = Htautau.DeltaR(jet1);
    
    // Boosted bb and small jets j2 variables
    boosted_bb_j2_system_m = bb_jet2.M();
    boosted_bb_j2_system_pt = bb_jet2.Pt();
    boosted_bb_j2_system_eta = bb_jet2.Eta();
    boosted_bb_j2_system_phi = bb_jet2.Phi();
    boosted_bb_j2_system_deta = std::abs(Hbb.Eta()-jet2.Eta());
    boosted_bb_j2_system_dphi = std::abs(Hbb.Phi()-jet2.Phi());
    boosted_bb_j2_system_dR = Hbb.DeltaR(jet2);
    
    // Boosted tautau and small jets j1 variables
    boosted_tautau_j2_system_m = tautau_jet2.M();
    boosted_tautau_j2_system_pt = tautau_jet2.Pt();
    boosted_tautau_j2_system_eta = tautau_jet2.Eta();
    boosted_tautau_j2_system_phi = tautau_jet2.Phi();
    boosted_tautau_j2_system_deta = std::abs(Htautau.Eta()-jet2.Eta());
    boosted_tautau_j2_system_dphi = std::abs(Htautau.Phi()-jet2.Phi());
    boosted_tautau_j2_system_dR = Htautau.DeltaR(jet2);

    // All jets system variables
    boosted_all_jets_system_m = all_jets.M();
    boosted_all_jets_system_pt = all_jets.Pt();
    boosted_all_jets_system_eta = all_jets.Eta();
    boosted_all_jets_system_phi = all_jets.Phi();
    boosted_all_jets_system_deta = std::abs(bb_tautau.Eta()-jet12.Eta());
    boosted_all_jets_system_dphi = std::abs(bb_tautau.Eta()-jet12.Eta());
    boosted_all_jets_system_dR = bb_tautau.DeltaR(jet12);
  
  }
  
}

// This functions pairs the 2 small jets in the VBF topology
void pairs_small_jets(){

  idx_jet1_VBF_topology = -99;
  idx_jet2_VBF_topology = -99;
  is_jet12_matched = false;
  
  float dR_min = 1.0;
  
  if(is_boosted_bbtautau == true){

    int idx_leading_jet = 0;
    int idx_subleading_jet = 0;
  
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
    
    /*
    // Mathod 1 (leading and subleading jet)
    if( candidates_smallJets.size()>=2 ){

      int idx_jet1 = candidates_smallJets.at(0);
      int idx_jet2 = candidates_smallJets.at(1);

      
      if(){
	idx_jet1_VBF_topology = candidates_smallJets.at(0);
	idx_jet2_VBF_topology = candidates_smallJets.at(1);
	is_jet12_matched = true;
      }
      
    }
    */
    
    // Method 2 (highest invariant mass mjj)
    if( candidates_smallJets.size()>=2 ){

      float current_jet12_m = 0;

      int current_pT_value = 0;
    
      for(int ii=0; ii<candidates_smallJets.size(); ii++){
	if(recojet_antikt4PFlow_pt___NOSYS->at(candidates_smallJets.at(ii)) > current_pT_value){
	  current_pT_value = recojet_antikt4PFlow_pt___NOSYS->at(candidates_smallJets.at(ii));
	  idx_leading_jet = candidates_smallJets.at(ii);
	}
      }
    
      current_pT_value = 0;
      for(int jj=0; jj<candidates_smallJets.size(); jj++){
	if(candidates_smallJets.at(jj) != idx_leading_jet){
	  if(recojet_antikt4PFlow_pt___NOSYS->at(candidates_smallJets.at(jj)) > current_pT_value){
	    current_pT_value = recojet_antikt4PFlow_pt___NOSYS->at(candidates_smallJets.at(jj));
	    idx_subleading_jet = candidates_smallJets.at(jj);
	  }
	}
      }
      
      //idx_jet1_VBF_topology = idx_leading_jet;
      //idx_jet2_VBF_topology = idx_subleading_jet;
      //is_jet12_matched = true;
      
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
	    
	    // Takes the jet1 as the highest pT jet and the jet2 as the subleading jet
	    if(jet1_pt < jet2_pt){
	      idx_jet1_VBF_topology = idx_jet2;
	      idx_jet2_VBF_topology = idx_jet1;
	    }
	    else{
	      idx_jet1_VBF_topology = idx_jet1;
	      idx_jet2_VBF_topology = idx_jet2;
	    }
	    
	    is_jet12_matched = true;
	  }
        }
      }
      
      if( (recojet_antikt4PFlow_pt___NOSYS->at(idx_leading_jet) < recojet_antikt4PFlow_pt___NOSYS->at(idx_subleading_jet)) || (recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1_VBF_topology) < recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2_VBF_topology)) ){
	//cout << "The jets are not organized by pT" << endl;
	number_of_desordered_small_jets_pT_candidates++;
	cout << "idx leading jet " << recojet_antikt4PFlow_pt___NOSYS->at(idx_leading_jet) << endl;
	cout << "idx subleading jet " << recojet_antikt4PFlow_pt___NOSYS->at(idx_subleading_jet) << endl;

	cout << "idx jet1 mjj " << recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1_VBF_topology) << endl;
	cout << "idx jet2 mjj " << recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2_VBF_topology) << endl;
      }
      
      //if( (idx_jet1_VBF_topology==idx_leading_jet && idx_jet2_VBF_topology==idx_subleading_jet) || (idx_jet1_VBF_topology==idx_subleading_jet && idx_jet2_VBF_topology==idx_leading_jet) ){

      if( idx_jet1_VBF_topology==idx_leading_jet && idx_jet2_VBF_topology==idx_subleading_jet ){
        overlap_jj_selection_methods++;
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
