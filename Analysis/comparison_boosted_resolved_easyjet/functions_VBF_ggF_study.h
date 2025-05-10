#include "VBF_ggF_separation_study.h"
#include "histograms_VBF_ggF_separation_study.h"
#include "../../Plotting/AtlasStyle/AtlasStyle.C"
#include "../../Plotting/AtlasStyle/AtlasUtils.C"
#include "../../Plotting/AtlasStyle/AtlasLabels.C"

// *************************************
// Declaration of some functions
// *************************************

void fix_underflow_overflow(TH1F* histo);
void compute_variables_for_topological_processes_ggF();
void compute_variables_for_topological_processes_VBF();
void pairs_small_jets_ggF();
void pairs_small_jets_VBF();
void plot_distributions(TString name_plot);
void boosted_candidates_ggF();
void boosted_candidates_VBF();
void fill_histograms_VBF();
void fill_histograms_ggF();
void set_branch_address();


void fix_underflow_overflow(TH1F* histo){
  
  // Adding the underflow to the first bin
  histo->AddBinContent(1, histo->GetBinContent(0));
  
  // Adding the overflow to the last bin
  histo->AddBinContent(histo->GetNbinsX(), histo->GetBinContent(histo->GetNbinsX() + 1));

}

// This functions computes some useful variables to determine characteristics of topological processes
void compute_variables_for_topological_processes_ggF(){

  two_jets_j12_m_ggF = -99;
  two_jets_j12_pt_ggF = -99;
  two_jets_j12_eta_ggF = -99;
  two_jets_j12_phi_ggF = -99;
  two_jets_j12_deta_ggF = -99;
  two_jets_j12_dphi_ggF = -99;
  two_jets_j12_dR_ggF = -99;
  
  if( is_jet12_matched_ggF == true ){
    TLorentzVector jet1 = TLorentzVector();
    TLorentzVector jet2 = TLorentzVector();
    
    float jet1_pt = ggF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1_ggF);
    float jet1_eta = ggF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1_ggF);
    float jet1_phi = ggF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1_ggF);
    float jet1_m = ggF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet1_ggF);
    
    float jet2_pt = ggF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2_ggF);
    float jet2_eta = ggF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2_ggF);
    float jet2_phi = ggF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2_ggF);
    float jet2_m = ggF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet2_ggF);
    
    jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
    jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

    TLorentzVector jet12 = TLorentzVector();
    jet12 = jet1 + jet2;
    two_jets_j12_m_ggF = jet12.M();
    two_jets_j12_pt_ggF = jet12.Pt();
    two_jets_j12_eta_ggF = jet12.Eta();
    two_jets_j12_phi_ggF = jet12.Phi();
    two_jets_j12_deta_ggF = std::abs(jet1.Eta()-jet2.Eta());
    two_jets_j12_dphi_ggF = std::abs(jet1.Phi()-jet2.Phi());
    two_jets_j12_dR_ggF = jet1.DeltaR(jet2);
  
  }
  
}

// This functions computes some useful variables to determine characteristics of topological processes
void compute_variables_for_topological_processes_VBF(){

  two_jets_j12_m_VBF = -99;
  two_jets_j12_pt_VBF = -99;
  two_jets_j12_eta_VBF = -99;
  two_jets_j12_phi_VBF = -99;
  two_jets_j12_deta_VBF = -99;
  two_jets_j12_dphi_VBF = -99;
  two_jets_j12_dR_VBF = -99;
  
  if( is_jet12_matched_VBF == true ){
    TLorentzVector jet1 = TLorentzVector();
    TLorentzVector jet2 = TLorentzVector();
    
    float jet1_pt = VBF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1_VBF);
    float jet1_eta = VBF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1_VBF);
    float jet1_phi = VBF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1_VBF);
    float jet1_m = VBF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet1_VBF);
    
    float jet2_pt = VBF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2_VBF);
    float jet2_eta = VBF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2_VBF);
    float jet2_phi = VBF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2_VBF);
    float jet2_m = VBF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet2_VBF);
    
    jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
    jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

    TLorentzVector jet12 = TLorentzVector();
    jet12 = jet1 + jet2;
    two_jets_j12_m_VBF = jet12.M();
    two_jets_j12_pt_VBF = jet12.Pt();
    two_jets_j12_eta_VBF = jet12.Eta();
    two_jets_j12_phi_VBF = jet12.Phi();
    two_jets_j12_deta_VBF = std::abs(jet1.Eta()-jet2.Eta());
    two_jets_j12_dphi_VBF = std::abs(jet1.Phi()-jet2.Phi());
    two_jets_j12_dR_VBF = jet1.DeltaR(jet2);
    
  }
  
}

// This functions pairs the 2 small jets in the VBF
void pairs_small_jets_ggF(){

  idx_jet1_ggF = -99;
  idx_jet2_ggF = -99;
  is_jet12_matched_ggF = false;
  
  float dR_min = 1.0;
  
  if(is_boosted_bbtautau_ggF == true){

    std::vector<int> candidates_smallJets;
      
    for(int ii=0; ii<ggF_recojet_antikt4PFlow_pt___NOSYS->size(); ii++){

      TLorentzVector small_jet = TLorentzVector();
      TLorentzVector large_R1_jet = TLorentzVector();
      TLorentzVector large_R2_jet = TLorentzVector();
      
      float small_jet_pt = ggF_recojet_antikt4PFlow_pt___NOSYS->at(ii);
      float small_jet_eta = ggF_recojet_antikt4PFlow_eta___NOSYS->at(ii);
      float small_jet_phi = ggF_recojet_antikt4PFlow_phi___NOSYS->at(ii);
      float small_jet_m = ggF_recojet_antikt4PFlow_m___NOSYS->at(ii);

      float large_R1_jet_pt = ggF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb_ggF);
      float large_R1_jet_eta = ggF_recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_bb_ggF);
      float large_R1_jet_phi = ggF_recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_bb_ggF);
      float large_R1_jet_m = ggF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_bb_ggF);

      float large_R2_jet_pt = ggF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau_ggF);
      float large_R2_jet_eta = ggF_recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_tautau_ggF);
      float large_R2_jet_phi = ggF_recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_tautau_ggF);
      float large_R2_jet_m = ggF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau_ggF);
      
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

	  float jet1_pt = ggF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1);
	  float jet1_eta = ggF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1);
	  float jet1_phi = ggF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1);
	  float jet1_m = ggF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet1);

	  float jet2_pt = ggF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2);
	  float jet2_eta = ggF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2);
	  float jet2_phi = ggF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2);
	  float jet2_m = ggF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet2);
	    
	  jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
	  jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);
	  
	  TLorentzVector jet12 = TLorentzVector();
	  jet12 = jet1 + jet2;
	  float jet12_m = jet12.M();

	  if( jet12_m>current_jet12_m ){
	    current_jet12_m = jet12_m;
	    idx_jet1_ggF = idx_jet1;
	    idx_jet2_ggF = idx_jet2;
	    is_jet12_matched_ggF = true;
	  }
	}
      }
    }
  }  
}

// This functions pairs the 2 small jets in the VBF
void pairs_small_jets_VBF(){

  idx_jet1_VBF = -99;
  idx_jet2_VBF = -99;
  is_jet12_matched_VBF = false;
  
  float dR_min = 1.0;
  
  if(is_boosted_bbtautau_VBF == true){

    std::vector<int> candidates_smallJets;
      
    for(int ii=0; ii<VBF_recojet_antikt4PFlow_pt___NOSYS->size(); ii++){

      TLorentzVector small_jet = TLorentzVector();
      TLorentzVector large_R1_jet = TLorentzVector();
      TLorentzVector large_R2_jet = TLorentzVector();
      
      float small_jet_pt = VBF_recojet_antikt4PFlow_pt___NOSYS->at(ii);
      float small_jet_eta = VBF_recojet_antikt4PFlow_eta___NOSYS->at(ii);
      float small_jet_phi = VBF_recojet_antikt4PFlow_phi___NOSYS->at(ii);
      float small_jet_m = VBF_recojet_antikt4PFlow_m___NOSYS->at(ii);

      float large_R1_jet_pt = VBF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb_VBF);
      float large_R1_jet_eta = VBF_recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_bb_VBF);
      float large_R1_jet_phi = VBF_recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_bb_VBF);
      float large_R1_jet_m = VBF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_bb_VBF);

      float large_R2_jet_pt = VBF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau_VBF);
      float large_R2_jet_eta = VBF_recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_tautau_VBF);
      float large_R2_jet_phi = VBF_recojet_antikt10UFO_phi___NOSYS->at(idx_boosted_tautau_VBF);
      float large_R2_jet_m = VBF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau_VBF);
      
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

	  float jet1_pt = VBF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet1);
	  float jet1_eta = VBF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1);
	  float jet1_phi = VBF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet1);
	  float jet1_m = VBF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet1);

	  float jet2_pt = VBF_recojet_antikt4PFlow_pt___NOSYS->at(idx_jet2);
	  float jet2_eta = VBF_recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2);
	  float jet2_phi = VBF_recojet_antikt4PFlow_phi___NOSYS->at(idx_jet2);
	  float jet2_m = VBF_recojet_antikt4PFlow_m___NOSYS->at(idx_jet2);
	    
	  jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
	  jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

	  TLorentzVector jet12 = TLorentzVector();
	  jet12 = jet1 + jet2;
	  float jet12_m = jet12.M();

	  if( jet12_m>current_jet12_m ){
	    current_jet12_m = jet12_m;
	    idx_jet1_VBF = idx_jet1;
	    idx_jet2_VBF = idx_jet2;
	    is_jet12_matched_VBF = true;
	  }
	}
      }
    }
  }  
}

// This functions selects the recojets largeR-jets that are candidates to be boosted bb or boosted tautau
void boosted_candidates_ggF(){

  idx_boosted_bb_ggF = -99;
  is_boosted_bb_ggF = false;
  idx_boosted_tautau_ggF = -99;
  is_boosted_tautau_ggF = false;
  is_boosted_bbtautau_ggF = false;

  count_bb_candidates_ggF = 0;
  count_tautau_candidates_ggF = 0;
  
  for(int ii=0; ii<ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS->size(); ii++){
    if(ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS->at(ii) == 1){
      if( count_bb_candidates_ggF == 0){
	idx_boosted_bb_ggF = ii;
	is_boosted_bb_ggF = true;
      }
      count_bb_candidates_ggF++;
    }
    else{
      if( count_tautau_candidates_ggF == 0){
	idx_boosted_tautau_ggF = ii;
	is_boosted_tautau_ggF = true;
      }
      count_tautau_candidates_ggF++;
    }
  }

  if( is_boosted_bb_ggF == true && is_boosted_tautau_ggF == true ){
    is_boosted_bbtautau_ggF = true;
  }

}

// This functions selects the recojets largeR-jets that are candidates to be boosted bb or boosted tautau
void boosted_candidates_VBF(){

  idx_boosted_bb_VBF = -99;
  is_boosted_bb_VBF = false;
  idx_boosted_tautau_VBF = -99;
  is_boosted_tautau_VBF = false;
  is_boosted_bbtautau_VBF = false;

  count_bb_candidates_VBF = 0;
  count_tautau_candidates_VBF = 0;
  
  for(int ii=0; ii<VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS->size(); ii++){
    if(VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS->at(ii) == 1){
      if( count_bb_candidates_VBF == 0){
	idx_boosted_bb_VBF = ii;
	is_boosted_bb_VBF = true;
      }
      count_bb_candidates_VBF++;
    }
    else{
      if( count_tautau_candidates_VBF == 0){
	idx_boosted_tautau_VBF = ii;
	is_boosted_tautau_VBF = true;
      }
      count_tautau_candidates_VBF++;
    }
  }

  if( is_boosted_bb_VBF == true && is_boosted_tautau_VBF == true ){
    is_boosted_bbtautau_VBF = true;
  }
  
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved

void fill_histograms_VBF(){

  hist_boosted_tautau_ECF1_VBF->Fill(VBF_recojet_antikt10UFO_ECF1___NOSYS->at(idx_boosted_tautau_VBF)/1000.);
  hist_boosted_tautau_ECF2_VBF->Fill(VBF_recojet_antikt10UFO_ECF2___NOSYS->at(idx_boosted_tautau_VBF)/10000000.);
  hist_boosted_tautau_ECF3_VBF->Fill(VBF_recojet_antikt10UFO_ECF3___NOSYS->at(idx_boosted_tautau_VBF)/1000000000.);
  hist_boosted_tautau_Split12_VBF->Fill(VBF_recojet_antikt10UFO_Split12___NOSYS->at(idx_boosted_tautau_VBF)/1000.);
  hist_boosted_tautau_Split23_VBF->Fill(VBF_recojet_antikt10UFO_Split23___NOSYS->at(idx_boosted_tautau_VBF)/1000.);
  hist_boosted_tautau_n1_nsubjettiness_VBF->Fill(VBF_recojet_antikt10UFO_Tau1_wta___NOSYS->at(idx_boosted_tautau_VBF));
  hist_boosted_tautau_n2_nsubjettiness_VBF->Fill(VBF_recojet_antikt10UFO_Tau2_wta___NOSYS->at(idx_boosted_tautau_VBF));
  hist_boosted_tautau_n3_nsubjettiness_VBF->Fill(VBF_recojet_antikt10UFO_Tau3_wta___NOSYS->at(idx_boosted_tautau_VBF));
  hist_boosted_tautau_pt_NOSYS_VBF->Fill(VBF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau_VBF)/1000.);
  hist_boosted_tautau_m_VBF->Fill(VBF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau_VBF)/1000.);

  hist_boosted_bb_ECF1_VBF->Fill(VBF_recojet_antikt10UFO_ECF1___NOSYS->at(idx_boosted_bb_VBF)/1000.);
  hist_boosted_bb_ECF2_VBF->Fill(VBF_recojet_antikt10UFO_ECF2___NOSYS->at(idx_boosted_bb_VBF)/10000000.);
  hist_boosted_bb_ECF3_VBF->Fill(VBF_recojet_antikt10UFO_ECF3___NOSYS->at(idx_boosted_bb_VBF)/1000000000.);
  hist_boosted_bb_Split12_VBF->Fill(VBF_recojet_antikt10UFO_Split12___NOSYS->at(idx_boosted_bb_VBF)/1000.);
  hist_boosted_bb_Split23_VBF->Fill(VBF_recojet_antikt10UFO_Split23___NOSYS->at(idx_boosted_bb_VBF)/1000.);
  hist_boosted_bb_n1_nsubjettiness_VBF->Fill(VBF_recojet_antikt10UFO_Tau1_wta___NOSYS->at(idx_boosted_bb_VBF));
  hist_boosted_bb_n2_nsubjettiness_VBF->Fill(VBF_recojet_antikt10UFO_Tau2_wta___NOSYS->at(idx_boosted_bb_VBF));
  hist_boosted_bb_n3_nsubjettiness_VBF->Fill(VBF_recojet_antikt10UFO_Tau3_wta___NOSYS->at(idx_boosted_bb_VBF));
  hist_boosted_bb_pt_NOSYS_VBF->Fill(VBF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb_VBF)/1000.);
  hist_boosted_bb_m_VBF->Fill(VBF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau_VBF)/1000.);

  hist_boosted_jet12_m_VBF->Fill(two_jets_j12_m_VBF/1000.);
  hist_boosted_jet12_pt_VBF->Fill(two_jets_j12_m_VBF/1000.);
  hist_boosted_jet12_deta_VBF->Fill(two_jets_j12_deta_VBF);
  hist_boosted_jet12_dphi_VBF->Fill(two_jets_j12_dphi_VBF);
  hist_boosted_jet12_dR_VBF->Fill(two_jets_j12_dR_VBF);
    
  for(int ii=0; ii<VBF_recojet_antikt10UFO_ECF1___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_VBF && ii!=idx_boosted_tautau_VBF){
      hist_non_boosted_jets_ECF1_VBF->Fill(VBF_recojet_antikt10UFO_ECF1___NOSYS->at(ii)/1000.);
    }
  }
  for(int ii=0; ii<VBF_recojet_antikt10UFO_ECF2___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_VBF && ii!=idx_boosted_tautau_VBF){
      hist_non_boosted_jets_ECF2_VBF->Fill(VBF_recojet_antikt10UFO_ECF2___NOSYS->at(ii)/10000000.);
    }
  }
  for(int ii=0; ii<VBF_recojet_antikt10UFO_ECF3___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_VBF && ii!=idx_boosted_tautau_VBF){
      hist_non_boosted_jets_ECF3_VBF->Fill(VBF_recojet_antikt10UFO_ECF3___NOSYS->at(ii)/1000000000.);
    }
  }
  for(int ii=0; ii<VBF_recojet_antikt10UFO_m___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_VBF && ii!=idx_boosted_tautau_VBF){
      hist_non_boosted_jets_m_VBF->Fill(VBF_recojet_antikt10UFO_m___NOSYS->at(ii)/1000.);
    }
  }
  for(int ii=0; ii<VBF_recojet_antikt10UFO_pt___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_VBF && ii!=idx_boosted_tautau_VBF){
      hist_non_boosted_jets_pt_NOSYS_VBF->Fill(VBF_recojet_antikt10UFO_pt___NOSYS->at(ii)/1000.);
    }
  }
  
}

void fill_histograms_ggF(){

  hist_boosted_tautau_ECF1_ggF->Fill(ggF_recojet_antikt10UFO_ECF1___NOSYS->at(idx_boosted_tautau_ggF)/1000.);
  hist_boosted_tautau_ECF2_ggF->Fill(ggF_recojet_antikt10UFO_ECF2___NOSYS->at(idx_boosted_tautau_ggF)/10000000.);
  hist_boosted_tautau_ECF3_ggF->Fill(ggF_recojet_antikt10UFO_ECF3___NOSYS->at(idx_boosted_tautau_ggF)/1000000000.);
  hist_boosted_tautau_Split12_ggF->Fill(ggF_recojet_antikt10UFO_Split12___NOSYS->at(idx_boosted_tautau_VBF)/1000.);
  hist_boosted_tautau_Split23_ggF->Fill(ggF_recojet_antikt10UFO_Split23___NOSYS->at(idx_boosted_tautau_VBF)/1000.);
  hist_boosted_tautau_n1_nsubjettiness_ggF->Fill(ggF_recojet_antikt10UFO_Tau1_wta___NOSYS->at(idx_boosted_tautau_VBF));
  hist_boosted_tautau_n2_nsubjettiness_ggF->Fill(ggF_recojet_antikt10UFO_Tau2_wta___NOSYS->at(idx_boosted_tautau_VBF));
  hist_boosted_tautau_n3_nsubjettiness_ggF->Fill(ggF_recojet_antikt10UFO_Tau3_wta___NOSYS->at(idx_boosted_tautau_VBF));
  hist_boosted_tautau_pt_NOSYS_ggF->Fill(ggF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau_ggF)/1000.);
  hist_boosted_tautau_m_ggF->Fill(ggF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau_ggF)/1000.);

  hist_boosted_bb_ECF1_ggF->Fill(ggF_recojet_antikt10UFO_ECF1___NOSYS->at(idx_boosted_bb_ggF)/1000.);
  hist_boosted_bb_ECF2_ggF->Fill(ggF_recojet_antikt10UFO_ECF2___NOSYS->at(idx_boosted_bb_ggF)/10000000.);
  hist_boosted_bb_ECF3_ggF->Fill(ggF_recojet_antikt10UFO_ECF3___NOSYS->at(idx_boosted_bb_ggF)/1000000000.);
  hist_boosted_bb_Split12_ggF->Fill(ggF_recojet_antikt10UFO_Split12___NOSYS->at(idx_boosted_bb_VBF)/1000.);
  hist_boosted_bb_Split23_ggF->Fill(ggF_recojet_antikt10UFO_Split23___NOSYS->at(idx_boosted_bb_VBF)/1000.);
  hist_boosted_bb_n1_nsubjettiness_ggF->Fill(ggF_recojet_antikt10UFO_Tau1_wta___NOSYS->at(idx_boosted_bb_VBF));
  hist_boosted_bb_n2_nsubjettiness_ggF->Fill(ggF_recojet_antikt10UFO_Tau2_wta___NOSYS->at(idx_boosted_bb_VBF));
  hist_boosted_bb_n3_nsubjettiness_ggF->Fill(ggF_recojet_antikt10UFO_Tau3_wta___NOSYS->at(idx_boosted_bb_VBF));
  hist_boosted_bb_pt_NOSYS_ggF->Fill(ggF_recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb_ggF)/1000.);
  hist_boosted_bb_m_ggF->Fill(ggF_recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau_ggF)/1000.);

  hist_boosted_jet12_m_ggF->Fill(two_jets_j12_m_ggF/1000.);
  hist_boosted_jet12_pt_ggF->Fill(two_jets_j12_m_ggF/1000.);
  hist_boosted_jet12_deta_ggF->Fill(two_jets_j12_deta_ggF);
  hist_boosted_jet12_dphi_ggF->Fill(two_jets_j12_dphi_ggF);
  hist_boosted_jet12_dR_ggF->Fill(two_jets_j12_dR_ggF);
  
  for(int ii=0; ii<ggF_recojet_antikt10UFO_ECF1___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_ggF && ii!=idx_boosted_tautau_ggF){
      hist_non_boosted_jets_ECF1_ggF->Fill(ggF_recojet_antikt10UFO_ECF1___NOSYS->at(ii)/1000.);
    }
  }
  for(int ii=0; ii<ggF_recojet_antikt10UFO_ECF2___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_ggF && ii!=idx_boosted_tautau_ggF){
      hist_non_boosted_jets_ECF2_ggF->Fill(ggF_recojet_antikt10UFO_ECF2___NOSYS->at(ii)/10000000.);
    }
  }
  for(int ii=0; ii<ggF_recojet_antikt10UFO_ECF3___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_ggF && ii!=idx_boosted_tautau_ggF){
      hist_non_boosted_jets_ECF3_ggF->Fill(ggF_recojet_antikt10UFO_ECF3___NOSYS->at(ii)/1000000000.);
    }
  }
  for(int ii=0; ii<ggF_recojet_antikt10UFO_m___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_ggF && ii!=idx_boosted_tautau_ggF){
      hist_non_boosted_jets_m_ggF->Fill(ggF_recojet_antikt10UFO_m___NOSYS->at(ii)/1000.);
    }
  }
  for(int ii=0; ii<ggF_recojet_antikt10UFO_pt___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb_ggF && ii!=idx_boosted_tautau_ggF){
      hist_non_boosted_jets_pt_NOSYS_ggF->Fill(ggF_recojet_antikt10UFO_pt___NOSYS->at(ii)/1000.);
    }
  }
  
}


// This function saves the branches info for a given tree in the variables defined above
void set_branch_address(){

  // Declaration of branches for boosted VBF tree
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_ECF1___NOSYS", &VBF_recojet_antikt10UFO_ECF1___NOSYS, &b_VBF_recojet_antikt10UFO_ECF1___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_ECF2___NOSYS", &VBF_recojet_antikt10UFO_ECF2___NOSYS, &b_VBF_recojet_antikt10UFO_ECF2___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_ECF3___NOSYS", &VBF_recojet_antikt10UFO_ECF3___NOSYS, &b_VBF_recojet_antikt10UFO_ECF3___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phbb___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phcc___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_ptop___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_phbb___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_phcc___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_ptop___NOSYS", &VBF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS, &b_VBF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS", &VBF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS, &b_VBF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS", &VBF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS, &b_VBF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS", &VBF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS, &b_VBF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS", &VBF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS, &b_VBF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_Split12___NOSYS", &VBF_recojet_antikt10UFO_Split12___NOSYS, &b_VBF_recojet_antikt10UFO_Split12___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_Split23___NOSYS", &VBF_recojet_antikt10UFO_Split23___NOSYS, &b_VBF_recojet_antikt10UFO_Split23___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_Tau1_wta___NOSYS", &VBF_recojet_antikt10UFO_Tau1_wta___NOSYS, &b_VBF_recojet_antikt10UFO_Tau1_wta___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_Tau2_wta___NOSYS", &VBF_recojet_antikt10UFO_Tau2_wta___NOSYS, &b_VBF_recojet_antikt10UFO_Tau2_wta___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_Tau3_wta___NOSYS", &VBF_recojet_antikt10UFO_Tau3_wta___NOSYS, &b_VBF_recojet_antikt10UFO_Tau3_wta___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_eta___NOSYS", &VBF_recojet_antikt10UFO_eta___NOSYS, &b_VBF_recojet_antikt10UFO_eta___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_isAnalysisJet___NOSYS", &VBF_recojet_antikt10UFO_isAnalysisJet___NOSYS, &b_VBF_recojet_antikt10UFO_isAnalysisJet___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_isjet1___NOSYS", &VBF_recojet_antikt10UFO_isjet1___NOSYS, &b_VBF_recojet_antikt10UFO_isjet1___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_isjet2___NOSYS", &VBF_recojet_antikt10UFO_isjet2___NOSYS, &b_VBF_recojet_antikt10UFO_isjet2___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_m___NOSYS", &VBF_recojet_antikt10UFO_m___NOSYS, &b_VBF_recojet_antikt10UFO_m___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_phi___NOSYS", &VBF_recojet_antikt10UFO_phi___NOSYS, &b_VBF_recojet_antikt10UFO_phi___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_pt___NOSYS", &VBF_recojet_antikt10UFO_pt___NOSYS, &b_VBF_recojet_antikt10UFO_pt___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS", &VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS, &b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS);

  VBF_inTree->SetBranchAddress("recojet_antikt4PFlow_m___NOSYS", &VBF_recojet_antikt4PFlow_m___NOSYS, &b_VBF_recojet_antikt4PFlow_m___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt4PFlow_eta___NOSYS", &VBF_recojet_antikt4PFlow_eta___NOSYS, &b_VBF_recojet_antikt4PFlow_eta___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt4PFlow_phi___NOSYS", &VBF_recojet_antikt4PFlow_phi___NOSYS, &b_VBF_recojet_antikt4PFlow_phi___NOSYS);
  VBF_inTree->SetBranchAddress("recojet_antikt4PFlow_pt___NOSYS", &VBF_recojet_antikt4PFlow_pt___NOSYS, &b_VBF_recojet_antikt4PFlow_pt___NOSYS);
  
  
  // Declaration of branches for boosted ggF tree
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_ECF1___NOSYS", &ggF_recojet_antikt10UFO_ECF1___NOSYS, &b_ggF_recojet_antikt10UFO_ECF1___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_ECF2___NOSYS", &ggF_recojet_antikt10UFO_ECF2___NOSYS, &b_ggF_recojet_antikt10UFO_ECF2___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_ECF3___NOSYS", &ggF_recojet_antikt10UFO_ECF3___NOSYS, &b_ggF_recojet_antikt10UFO_ECF3___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phbb___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phcc___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_ptop___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_phbb___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_phcc___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_ptop___NOSYS", &ggF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS, &b_ggF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS", &ggF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS, &b_ggF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS", &ggF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS, &b_ggF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS", &ggF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS, &b_ggF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS", &ggF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS, &b_ggF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_Split12___NOSYS", &ggF_recojet_antikt10UFO_Split12___NOSYS, &b_ggF_recojet_antikt10UFO_Split12___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_Split23___NOSYS", &ggF_recojet_antikt10UFO_Split23___NOSYS, &b_ggF_recojet_antikt10UFO_Split23___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_Tau1_wta___NOSYS", &ggF_recojet_antikt10UFO_Tau1_wta___NOSYS, &b_ggF_recojet_antikt10UFO_Tau1_wta___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_Tau2_wta___NOSYS", &ggF_recojet_antikt10UFO_Tau2_wta___NOSYS, &b_ggF_recojet_antikt10UFO_Tau2_wta___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_Tau3_wta___NOSYS", &ggF_recojet_antikt10UFO_Tau3_wta___NOSYS, &b_ggF_recojet_antikt10UFO_Tau3_wta___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_eta___NOSYS", &ggF_recojet_antikt10UFO_eta___NOSYS, &b_ggF_recojet_antikt10UFO_eta___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_isAnalysisJet___NOSYS", &ggF_recojet_antikt10UFO_isAnalysisJet___NOSYS, &b_ggF_recojet_antikt10UFO_isAnalysisJet___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_isjet1___NOSYS", &ggF_recojet_antikt10UFO_isjet1___NOSYS, &b_ggF_recojet_antikt10UFO_isjet1___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_isjet2___NOSYS", &ggF_recojet_antikt10UFO_isjet2___NOSYS, &b_ggF_recojet_antikt10UFO_isjet2___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_m___NOSYS", &ggF_recojet_antikt10UFO_m___NOSYS, &b_ggF_recojet_antikt10UFO_m___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_phi___NOSYS", &ggF_recojet_antikt10UFO_phi___NOSYS, &b_ggF_recojet_antikt10UFO_phi___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_pt___NOSYS", &ggF_recojet_antikt10UFO_pt___NOSYS, &b_ggF_recojet_antikt10UFO_pt___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS", &ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS, &b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS);

  ggF_inTree->SetBranchAddress("recojet_antikt4PFlow_m___NOSYS", &ggF_recojet_antikt4PFlow_m___NOSYS, &b_ggF_recojet_antikt4PFlow_m___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt4PFlow_eta___NOSYS", &ggF_recojet_antikt4PFlow_eta___NOSYS, &b_ggF_recojet_antikt4PFlow_eta___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt4PFlow_phi___NOSYS", &ggF_recojet_antikt4PFlow_phi___NOSYS, &b_ggF_recojet_antikt4PFlow_phi___NOSYS);
  ggF_inTree->SetBranchAddress("recojet_antikt4PFlow_pt___NOSYS", &ggF_recojet_antikt4PFlow_pt___NOSYS, &b_ggF_recojet_antikt4PFlow_pt___NOSYS);
  
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void plot_distributions(TString name_plot){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  TLegend *leg = new TLegend(0.7, 0.75, 0.85, 0.85);
  TH1F *hist_VBF = new TH1F();
  TH1F *hist_ggF = new TH1F();
  TString name_image = "plots_comparison/";
  name_image+=name_plot+".png";
  
  if(name_plot=="tautau_m"){
    hist_VBF = hist_boosted_tautau_m_VBF;
    hist_ggF = hist_boosted_tautau_m_ggF;
  }

  if(name_plot=="bb_m"){
    hist_VBF = hist_boosted_bb_m_VBF;
    hist_ggF = hist_boosted_bb_m_ggF;
  }
  if(name_plot=="tautau_pT"){
    hist_VBF = hist_boosted_tautau_pt_NOSYS_VBF;
    hist_ggF = hist_boosted_tautau_pt_NOSYS_ggF;
  }
  if(name_plot=="bb_pT"){
    hist_VBF = hist_boosted_bb_pt_NOSYS_VBF;
    hist_ggF = hist_boosted_bb_pt_NOSYS_ggF;
  }
  if(name_plot=="tautau_ECF1"){
    hist_VBF = hist_boosted_tautau_ECF1_VBF;
    hist_ggF = hist_boosted_tautau_ECF1_ggF;
  }
  if(name_plot=="bb_ECF1"){
    hist_VBF = hist_boosted_bb_ECF1_VBF;
    hist_ggF = hist_boosted_bb_ECF1_ggF;
  }
  if(name_plot=="tautau_ECF2"){
    hist_VBF = hist_boosted_tautau_ECF2_VBF;
    hist_ggF = hist_boosted_tautau_ECF2_ggF;
  }
  if(name_plot=="bb_ECF2"){
    hist_VBF = hist_boosted_bb_ECF2_VBF;
    hist_ggF = hist_boosted_bb_ECF2_ggF;
  }
  if(name_plot=="tautau_ECF3"){
    hist_VBF = hist_boosted_tautau_ECF3_VBF;
    hist_ggF = hist_boosted_tautau_ECF3_ggF;
  }
  if(name_plot=="bb_ECF3"){
    hist_VBF = hist_boosted_bb_ECF3_VBF;
    hist_ggF = hist_boosted_bb_ECF3_ggF;
  }
  if(name_plot=="tautau_Split12"){
    hist_VBF = hist_boosted_tautau_Split12_VBF;
    hist_ggF = hist_boosted_tautau_Split12_ggF;
  }
  if(name_plot=="bb_Split12"){
    hist_VBF = hist_boosted_bb_Split12_VBF;
    hist_ggF = hist_boosted_bb_Split12_ggF;
  }
  if(name_plot=="tautau_Split23"){
    hist_VBF = hist_boosted_tautau_Split23_VBF;
    hist_ggF = hist_boosted_tautau_Split23_ggF;
  }
  if(name_plot=="bb_Split23"){
    hist_VBF = hist_boosted_bb_Split23_VBF;
    hist_ggF = hist_boosted_bb_Split23_ggF;
  }
  if(name_plot=="tautau_n1_nsubjettiness"){
    hist_VBF = hist_boosted_tautau_n1_nsubjettiness_VBF;
    hist_ggF = hist_boosted_tautau_n1_nsubjettiness_ggF;
  }
  if(name_plot=="bb_n1_nsubjettiness"){
    hist_VBF = hist_boosted_bb_n1_nsubjettiness_VBF;
    hist_ggF = hist_boosted_bb_n1_nsubjettiness_ggF;
  }
  if(name_plot=="tautau_n2_nsubjettiness"){
    hist_VBF = hist_boosted_tautau_n2_nsubjettiness_VBF;
    hist_ggF = hist_boosted_tautau_n2_nsubjettiness_ggF;
  }
  if(name_plot=="bb_n2_nsubjettiness"){
    hist_VBF = hist_boosted_bb_n2_nsubjettiness_VBF;
    hist_ggF = hist_boosted_bb_n2_nsubjettiness_ggF;
  }
  if(name_plot=="tautau_n3_nsubjettiness"){
    hist_VBF = hist_boosted_tautau_n3_nsubjettiness_VBF;
    hist_ggF = hist_boosted_tautau_n3_nsubjettiness_ggF;
  }
  if(name_plot=="bb_n3_nsubjettiness"){
    hist_VBF = hist_boosted_bb_n3_nsubjettiness_VBF;
    hist_ggF = hist_boosted_bb_n3_nsubjettiness_ggF;
  }
  if(name_plot=="njets"){
    hist_VBF = hist_boosted_njets_VBF;
    hist_ggF = hist_boosted_njets_ggF;
  }
  if(name_plot=="bb_jets_n"){
    hist_VBF = hist_boosted_bb_candidates_VBF;
    hist_ggF = hist_boosted_bb_candidates_ggF;
  }
  if(name_plot=="tautau_jets_n"){
    hist_VBF = hist_boosted_tautau_candidates_VBF;
    hist_ggF = hist_boosted_tautau_candidates_ggF;
  }
  if(name_plot=="neither_bb_nor_tautau_jets_m"){
    hist_VBF = hist_non_boosted_jets_m_VBF;
    hist_ggF = hist_non_boosted_jets_m_ggF;
  }
  if(name_plot=="neither_bb_nor_tautau_jets_pT"){
    hist_VBF = hist_non_boosted_jets_pt_NOSYS_VBF;
    hist_ggF = hist_non_boosted_jets_pt_NOSYS_ggF;
  }
  if(name_plot=="neither_bb_nor_tautau_jets_ECF1"){
    hist_VBF = hist_non_boosted_jets_ECF1_VBF;
    hist_ggF = hist_non_boosted_jets_ECF1_ggF;
  }
  if(name_plot=="neither_bb_nor_tautau_jets_ECF2"){
    hist_VBF = hist_non_boosted_jets_ECF2_VBF;
    hist_ggF = hist_non_boosted_jets_ECF2_ggF;
  }
  if(name_plot=="neither_bb_nor_tautau_jets_ECF3"){
    hist_VBF = hist_non_boosted_jets_ECF3_VBF;
    hist_ggF = hist_non_boosted_jets_ECF3_ggF;
  }
  if(name_plot=="jet12_m"){
    hist_VBF = hist_boosted_jet12_m_VBF;
    hist_ggF = hist_boosted_jet12_m_ggF;
  }
  if(name_plot=="jet12_pt"){
    hist_VBF = hist_boosted_jet12_pt_VBF;
    hist_ggF = hist_boosted_jet12_pt_ggF;
  }
  if(name_plot=="jet12_deta"){
    hist_VBF = hist_boosted_jet12_deta_VBF;
    hist_ggF = hist_boosted_jet12_deta_ggF;
  }
  if(name_plot=="jet12_dphi"){
    hist_VBF = hist_boosted_jet12_dphi_VBF;
    hist_ggF = hist_boosted_jet12_dphi_ggF;
  }
  if(name_plot=="jet12_dR"){
    hist_VBF = hist_boosted_jet12_dR_VBF;
    hist_ggF = hist_boosted_jet12_dR_ggF;
  }
  
  // Step 1: Normalize the histograms manually (or use DrawNormalized to visualize them directly).
  //hist_VBF->Scale(1.0 / hist_VBF->Integral());
  //hist_ggF->Scale(1.0 / hist_ggF->Integral());
  
  // Step 2: Get the maximum value of each histogram after normalization.
  double max_VBF = hist_VBF->GetMaximum();
  double max_ggF = hist_ggF->GetMaximum();
  
  // Step 3: Set the y-axis maximum to the maximum of the two histograms.
  double y_max = std::max(max_VBF, max_ggF);
  
  // Optionally, you can set the y-axis maximum slightly higher than the actual maximum value for better visualization.
  y_max = y_max*1.5;  // Increase by 10% for padding
  
  // Step 4: Draw the histograms and set the maximum.
  hist_VBF->SetMaximum(y_max);
  hist_ggF->SetMaximum(y_max);
  
  hist_VBF->SetStats(0);
  hist_VBF->SetFillStyle(3001);
  hist_VBF->SetFillColorAlpha(kBlue, 0.45);
  hist_VBF->SetLineColor(4);
  
  hist_ggF->SetStats(0);
  hist_ggF->SetFillStyle(3003);
  hist_ggF->SetFillColorAlpha(kRed, 0.45);
  hist_ggF->SetLineColor(2);
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);

  hist_VBF->Draw("H");
  hist_ggF->Draw("sameH");
  
  leg->AddEntry(hist_VBF, "VBF SM process", "l");
  leg->AddEntry(hist_ggF,"ggF SM process","l");
  leg->SetBorderSize();
  leg->Draw();

  double dely = 0.05;
  myText(0.2, 0.9, kBlack, name_plot);
    
  can->Draw();
  can->SaveAs(name_image);
}
