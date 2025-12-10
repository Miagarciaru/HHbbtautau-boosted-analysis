#include "declaration_of_variables.h"
#include "fill_histo_functions.h"
#include "input_output_functions.h"
using namespace TMVA::Experimental;

// *************************************
// Constant variables
// *************************************
float bdt_boosted_bb_jet_cut = 0.8;
float bdt_boosted_tautau_jet_cut = 0.9;
float bdt_boosted_bbtautau_event_cut = 0.9;
float bdt_boosted_VBF_event_cut = 0.6;
const int max_jets = 15;

// *************************************
// Declaration of functions
// *************************************

void cutflow_small_R_jets(TMVA::Experimental::RBDT& model_VBF);
void compute_variables_for_topological_processes();
void pairs_small_jets();
void compute_small_jets_index(int &idx_small_jet1_mjj, int &idx_small_jet2_mjj, int &idx_small_jet1_ptjj, int &idx_small_jet2_ptjj, int idx_h1_jet, int idx_h2_jet, bool bbtautau_event, bool &is_jet12_ptjj_sel, bool &is_jet12_mjj_sel);
void default_values_for_topological_processes();
void compute_statistical_parameters();
void counting_statistical_parameters();
void correct_match_between_truth_reco_and_preselected_objects();
void define_preselected_events(float min_pT_cut_in_MeV, TMVA::Experimental::RBDT& model_bb, TMVA::Experimental::RBDT& model_tautau, TMVA::Experimental::RBDT& model_bbtautau_events);
float evaluate_bdt_model(TMVA::Experimental::RBDT& model, const std::vector<float>& jet_features);
void define_reconstructed_objects();
void define_output_branches();
void define_classes();
void define_reco_truth_boosted_jets_hh();
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void define_truth_tau_and_b_jets();
void default_values_for_truth_variables();
void default_values_for_preselected_variables();

// *************************************
// Definition of the functions declared above
// *************************************

// This function tries to develop different cuts on the selected pair of small jets
void cutflow_small_R_jets(TMVA::Experimental::RBDT& model_VBF){

  if( matched_preselected_j12_mjj_sel == true ){

    // Verify if the two small jets chosen by mjj method are the ones for the highest pT pair
    if( idx_preselected_small_j1_mjj_sel==idx_preselected_small_j1_ptjj_sel && idx_preselected_small_j2_mjj_sel==idx_preselected_small_j2_ptjj_sel ){
      overlap_jj_selection_methods++;
    }

    // Verify if the candidates have an opposite eta sign
    if( recojet_antikt4PFlow_eta->at(idx_preselected_small_j1_mjj_sel)*recojet_antikt4PFlow_eta->at(idx_preselected_small_j2_mjj_sel) < 0 ){
      eta_smalljets_cutflow++;
    }
    
    // Verify that each chosen jets pass the pt>30GeV
    if( recojet_antikt4PFlow_NOSYS_pt->at(idx_preselected_small_j2_mjj_sel) > 30000){
      minpt_smalljets_cutflow++;
    }

    // Verify if the invariant mass of the two jets is larger than 500 GeV
    if( preselected_j12_m > 500000 ){
      min_mjj_smalljets_cutflow++;
    }

    // Verify if the dR of the two jets is larger than 3
    if( preselected_j12_dR > 5.0 ){
      min_dR_smalljets_cutflow++;
    }

    bool cond_pt_sel = idx_preselected_small_j1_mjj_sel==idx_preselected_small_j1_ptjj_sel && idx_preselected_small_j2_mjj_sel==idx_preselected_small_j2_ptjj_sel;
    bool cond_eta_sig = recojet_antikt4PFlow_eta->at(idx_preselected_small_j1_mjj_sel)*recojet_antikt4PFlow_eta->at(idx_preselected_small_j2_mjj_sel) < 0;
    bool cond_minpt = recojet_antikt4PFlow_NOSYS_pt->at(idx_preselected_small_j2_mjj_sel) > 30000;
    bool cond_min_mjj = preselected_j12_m > 500000;
    bool cond_min_dR = preselected_j12_dR > 5.0;
    
    if( cond_eta_sig==true && cond_minpt==true && cond_min_mjj==true && cond_min_dR==true){
      all_cuts_applied_cutflow++;
    }

    std::vector<float> VBF_variables = {
      preselected_j12_m, 
      preselected_j12_deta, 
      preselected_j12_dphi, 
      preselected_j12_dR, 
      preselected_tautau_j1_system_pt,
      preselected_tautau_j1_system_deta,
      preselected_tautau_j1_system_dphi,
      preselected_tautau_j1_system_dR,
      preselected_tautau_j2_system_pt,
      preselected_tautau_j2_system_deta,
      preselected_tautau_j2_system_dphi,
      preselected_tautau_j2_system_dR,
      preselected_bb_j1_system_pt,
      preselected_bb_j1_system_deta,
      preselected_bb_j1_system_dphi,
      preselected_bb_j1_system_dR,
      preselected_bb_j2_system_pt,
      preselected_bb_j2_system_deta,
      preselected_bb_j2_system_dphi,
      preselected_bb_j2_system_dR,
      preselected_bbtautau_system_m,
      preselected_bbtautau_system_pt,
      preselected_bbtautau_system_eta,
      preselected_bbtautau_system_phi,
      preselected_bbtautau_system_deta,
      preselected_bbtautau_system_dphi,
      preselected_bbtautau_system_dR
    };

    float score_VBF_event = evaluate_bdt_model(model_VBF, VBF_variables);
    if( score_VBF_event >= bdt_boosted_VBF_event_cut ){
      n_VBF_events_bdt_cut++;
    }
  }
  
}

void default_values_for_topological_processes(){

  //****************************************************************************
  // Recojet variables
  //****************************************************************************

  // Two small jets j1 and j2 variables
  recojet_j12_m = -99;
  recojet_j12_pt = -99;
  recojet_j12_eta = -99;
  recojet_j12_phi = -99;
  recojet_j12_deta = -99;
  recojet_j12_dphi = -99;
  recojet_j12_dR = -99;

  // Boosted bb and boosted tautau variables
  recojet_bbtautau_system_m = -99;
  recojet_bbtautau_system_pt = -99;
  recojet_bbtautau_system_eta = -99;
  recojet_bbtautau_system_phi = -99;
  recojet_bbtautau_system_deta = -99;
  recojet_bbtautau_system_dphi = -99;
  recojet_bbtautau_system_dR = -99;

  // Boosted bb and small jets j1 variables
  recojet_bb_j1_system_m = -99;
  recojet_bb_j1_system_pt = -99;
  recojet_bb_j1_system_eta = -99;
  recojet_bb_j1_system_phi = -99;
  recojet_bb_j1_system_deta = -99;
  recojet_bb_j1_system_dphi = -99;
  recojet_bb_j1_system_dR = -99;

  // Boosted tautau and small jets j1 variables
  recojet_tautau_j1_system_m = -99;
  recojet_tautau_j1_system_pt = -99;
  recojet_tautau_j1_system_eta = -99;
  recojet_tautau_j1_system_phi = -99;
  recojet_tautau_j1_system_deta = -99;
  recojet_tautau_j1_system_dphi = -99;
  recojet_tautau_j1_system_dR = -99;
  
  // Boosted bb and small jets j2 variables
  recojet_bb_j2_system_m = -99;
  recojet_bb_j2_system_pt = -99;
  recojet_bb_j2_system_eta = -99;
  recojet_bb_j2_system_phi = -99;
  recojet_bb_j2_system_deta = -99;
  recojet_bb_j2_system_dphi = -99;
  recojet_bb_j2_system_dR = -99;
  
  // Boosted tautau and small jets j1 variables
  recojet_tautau_j2_system_m = -99;
  recojet_tautau_j2_system_pt = -99;
  recojet_tautau_j2_system_eta = -99;
  recojet_tautau_j2_system_phi = -99;
  recojet_tautau_j2_system_deta = -99;
  recojet_tautau_j2_system_dphi = -99;
  recojet_tautau_j2_system_dR = -99;

  // All jets system variables
  recojet_all_jets_system_m = -99;
  recojet_all_jets_system_pt = -99;
  recojet_all_jets_system_eta = -99;
  recojet_all_jets_system_phi = -99;
  recojet_all_jets_system_deta = -99;
  recojet_all_jets_system_dphi = -99;
  recojet_all_jets_system_dR = -99;

  //****************************************************************************
  // Preselected variables
  //****************************************************************************

  // Two small jets j1 and j2 variables
  preselected_j12_m = -99;
  preselected_j12_pt = -99;
  preselected_j12_eta = -99;
  preselected_j12_phi = -99;
  preselected_j12_deta = -99;
  preselected_j12_dphi = -99;
  preselected_j12_dR = -99;

  // Boosted bb and boosted tautau variables
  preselected_bbtautau_system_m = -99;
  preselected_bbtautau_system_pt = -99;
  preselected_bbtautau_system_eta = -99;
  preselected_bbtautau_system_phi = -99;
  preselected_bbtautau_system_deta = -99;
  preselected_bbtautau_system_dphi = -99;
  preselected_bbtautau_system_dR = -99;

  // Boosted bb and small jets j1 variables
  preselected_bb_j1_system_m = -99;
  preselected_bb_j1_system_pt = -99;
  preselected_bb_j1_system_eta = -99;
  preselected_bb_j1_system_phi = -99;
  preselected_bb_j1_system_deta = -99;
  preselected_bb_j1_system_dphi = -99;
  preselected_bb_j1_system_dR = -99;

  // Boosted tautau and small jets j1 variables
  preselected_tautau_j1_system_m = -99;
  preselected_tautau_j1_system_pt = -99;
  preselected_tautau_j1_system_eta = -99;
  preselected_tautau_j1_system_phi = -99;
  preselected_tautau_j1_system_deta = -99;
  preselected_tautau_j1_system_dphi = -99;
  preselected_tautau_j1_system_dR = -99;
  
  // Boosted bb and small jets j2 variables
  preselected_bb_j2_system_m = -99;
  preselected_bb_j2_system_pt = -99;
  preselected_bb_j2_system_eta = -99;
  preselected_bb_j2_system_phi = -99;
  preselected_bb_j2_system_deta = -99;
  preselected_bb_j2_system_dphi = -99;
  preselected_bb_j2_system_dR = -99;
  
  // Boosted tautau and small jets j1 variables
  preselected_tautau_j2_system_m = -99;
  preselected_tautau_j2_system_pt = -99;
  preselected_tautau_j2_system_eta = -99;
  preselected_tautau_j2_system_phi = -99;
  preselected_tautau_j2_system_deta = -99;
  preselected_tautau_j2_system_dphi = -99;
  preselected_tautau_j2_system_dR = -99;

  // All jets system variables
  preselected_all_jets_system_m = -99;
  preselected_all_jets_system_pt = -99;
  preselected_all_jets_system_eta = -99;
  preselected_all_jets_system_phi = -99;
  preselected_all_jets_system_deta = -99;
  preselected_all_jets_system_dphi = -99;
  preselected_all_jets_system_dR = -99;

}

// This functions computes some useful variables to determine characteristics of topological processes
void compute_variables_for_topological_processes(){

  default_values_for_topological_processes();
  
  // For truth-reco variables
  if( matched_recojet_j12_mjj_sel == true && class_event == 3 ){

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
    
    float jet1_pt = recojet_antikt4PFlow_NOSYS_pt->at(idx_recojet_small_j1_mjj_sel);
    float jet1_eta = recojet_antikt4PFlow_eta->at(idx_recojet_small_j1_mjj_sel);
    float jet1_phi = recojet_antikt4PFlow_phi->at(idx_recojet_small_j1_mjj_sel);
    float jet1_m = recojet_antikt4PFlow_m->at(idx_recojet_small_j1_mjj_sel);
    
    float jet2_pt = recojet_antikt4PFlow_NOSYS_pt->at(idx_recojet_small_j2_mjj_sel);
    float jet2_eta = recojet_antikt4PFlow_eta->at(idx_recojet_small_j2_mjj_sel);
    float jet2_phi = recojet_antikt4PFlow_phi->at(idx_recojet_small_j2_mjj_sel);
    float jet2_m = recojet_antikt4PFlow_m->at(idx_recojet_small_j2_mjj_sel);

    float Hbb_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin);
    float Hbb_eta = recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin);
    float Hbb_phi = recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin);
    float Hbb_m = recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin);
    
    float Htautau_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin);
    float Htautau_eta = recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin);
    float Htautau_phi = recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin);
    float Htautau_m = recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin);
      
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

    recojet_j12_m = jet12.M();
    recojet_j12_pt = jet12.Pt();
    recojet_j12_eta = jet12.Eta();
    recojet_j12_phi = jet12.Phi();
    recojet_j12_deta = std::abs(jet1.Eta()-jet2.Eta());
    recojet_j12_dphi = std::abs(jet1.Phi()-jet2.Phi());
    recojet_j12_dR = jet1.DeltaR(jet2);

    // Boosted bb and boosted tautau variables
    recojet_bbtautau_system_m = bb_tautau.M();
    recojet_bbtautau_system_pt = bb_tautau.Pt();
    recojet_bbtautau_system_eta = bb_tautau.Eta();
    recojet_bbtautau_system_phi = bb_tautau.Phi();
    recojet_bbtautau_system_deta = std::abs(Hbb.Eta()-Htautau.Eta());
    recojet_bbtautau_system_dphi = std::abs(Hbb.Phi()-Htautau.Phi());
    recojet_bbtautau_system_dR = Hbb.DeltaR(Htautau);
    
    // Boosted bb and small jets j1 variables
    recojet_bb_j1_system_m = bb_jet1.M();
    recojet_bb_j1_system_pt = bb_jet1.Pt();
    recojet_bb_j1_system_eta = bb_jet1.Eta();
    recojet_bb_j1_system_phi = bb_jet1.Phi();
    recojet_bb_j1_system_deta = std::abs(Hbb.Eta()-jet1.Eta());
    recojet_bb_j1_system_dphi = std::abs(Hbb.Phi()-jet1.Phi());
    recojet_bb_j1_system_dR = Hbb.DeltaR(jet1);
    
    // Boosted tautau and small jets j1 variables
    recojet_tautau_j1_system_m = tautau_jet1.M();
    recojet_tautau_j1_system_pt = tautau_jet1.Pt();
    recojet_tautau_j1_system_eta = tautau_jet1.Eta();
    recojet_tautau_j1_system_phi = tautau_jet1.Phi();
    recojet_tautau_j1_system_deta = std::abs(Htautau.Eta()-jet1.Eta());
    recojet_tautau_j1_system_dphi = std::abs(Htautau.Phi()-jet1.Phi());
    recojet_tautau_j1_system_dR = Htautau.DeltaR(jet1);
    
    // Boosted bb and small jets j2 variables
    recojet_bb_j2_system_m = bb_jet2.M();
    recojet_bb_j2_system_pt = bb_jet2.Pt();
    recojet_bb_j2_system_eta = bb_jet2.Eta();
    recojet_bb_j2_system_phi = bb_jet2.Phi();
    recojet_bb_j2_system_deta = std::abs(Hbb.Eta()-jet2.Eta());
    recojet_bb_j2_system_dphi = std::abs(Hbb.Phi()-jet2.Phi());
    recojet_bb_j2_system_dR = Hbb.DeltaR(jet2);
    
    // Boosted tautau and small jets j1 variables
    recojet_tautau_j2_system_m = tautau_jet2.M();
    recojet_tautau_j2_system_pt = tautau_jet2.Pt();
    recojet_tautau_j2_system_eta = tautau_jet2.Eta();
    recojet_tautau_j2_system_phi = tautau_jet2.Phi();
    recojet_tautau_j2_system_deta = std::abs(Htautau.Eta()-jet2.Eta());
    recojet_tautau_j2_system_dphi = std::abs(Htautau.Phi()-jet2.Phi());
    recojet_tautau_j2_system_dR = Htautau.DeltaR(jet2);

    // All jets system variables
    recojet_all_jets_system_m = all_jets.M();
    recojet_all_jets_system_pt = all_jets.Pt();
    recojet_all_jets_system_eta = all_jets.Eta();
    recojet_all_jets_system_phi = all_jets.Phi();
    recojet_all_jets_system_deta = std::abs(bb_tautau.Eta()-jet12.Eta());
    recojet_all_jets_system_dphi = std::abs(bb_tautau.Eta()-jet12.Eta());
    recojet_all_jets_system_dR = bb_tautau.DeltaR(jet12);
  
  }

  // For preselected variables

  if( matched_preselected_j12_mjj_sel == true ){

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
    
    float jet1_pt = recojet_antikt4PFlow_NOSYS_pt->at(idx_preselected_small_j1_mjj_sel);
    float jet1_eta = recojet_antikt4PFlow_eta->at(idx_preselected_small_j1_mjj_sel);
    float jet1_phi = recojet_antikt4PFlow_phi->at(idx_preselected_small_j1_mjj_sel);
    float jet1_m = recojet_antikt4PFlow_m->at(idx_preselected_small_j1_mjj_sel);
    
    float jet2_pt = recojet_antikt4PFlow_NOSYS_pt->at(idx_preselected_small_j2_mjj_sel);
    float jet2_eta = recojet_antikt4PFlow_eta->at(idx_preselected_small_j2_mjj_sel);
    float jet2_phi = recojet_antikt4PFlow_phi->at(idx_preselected_small_j2_mjj_sel);
    float jet2_m = recojet_antikt4PFlow_m->at(idx_preselected_small_j2_mjj_sel);

    float Hbb_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected);
    float Hbb_eta = recojet_antikt10UFO_eta->at(idx_b1_preselected);
    float Hbb_phi = recojet_antikt10UFO_phi->at(idx_b1_preselected);
    float Hbb_m = recojet_antikt10UFO_m->at(idx_b1_preselected);
    
    float Htautau_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected);
    float Htautau_eta = recojet_antikt10UFO_eta->at(idx_tau1_preselected);
    float Htautau_phi = recojet_antikt10UFO_phi->at(idx_tau1_preselected);
    float Htautau_m = recojet_antikt10UFO_m->at(idx_tau1_preselected);
      
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

    preselected_j12_m = jet12.M();
    preselected_j12_pt = jet12.Pt();
    preselected_j12_eta = jet12.Eta();
    preselected_j12_phi = jet12.Phi();
    preselected_j12_deta = std::abs(jet1.Eta()-jet2.Eta());
    preselected_j12_dphi = std::abs(jet1.Phi()-jet2.Phi());
    preselected_j12_dR = jet1.DeltaR(jet2);

    // Boosted bb and boosted tautau variables
    preselected_bbtautau_system_m = bb_tautau.M();
    preselected_bbtautau_system_pt = bb_tautau.Pt();
    preselected_bbtautau_system_eta = bb_tautau.Eta();
    preselected_bbtautau_system_phi = bb_tautau.Phi();
    preselected_bbtautau_system_deta = std::abs(Hbb.Eta()-Htautau.Eta());
    preselected_bbtautau_system_dphi = std::abs(Hbb.Phi()-Htautau.Phi());
    preselected_bbtautau_system_dR = Hbb.DeltaR(Htautau);
    
    // Boosted bb and small jets j1 variables
    preselected_bb_j1_system_m = bb_jet1.M();
    preselected_bb_j1_system_pt = bb_jet1.Pt();
    preselected_bb_j1_system_eta = bb_jet1.Eta();
    preselected_bb_j1_system_phi = bb_jet1.Phi();
    preselected_bb_j1_system_deta = std::abs(Hbb.Eta()-jet1.Eta());
    preselected_bb_j1_system_dphi = std::abs(Hbb.Phi()-jet1.Phi());
    preselected_bb_j1_system_dR = Hbb.DeltaR(jet1);
    
    // Boosted tautau and small jets j1 variables
    preselected_tautau_j1_system_m = tautau_jet1.M();
    preselected_tautau_j1_system_pt = tautau_jet1.Pt();
    preselected_tautau_j1_system_eta = tautau_jet1.Eta();
    preselected_tautau_j1_system_phi = tautau_jet1.Phi();
    preselected_tautau_j1_system_deta = std::abs(Htautau.Eta()-jet1.Eta());
    preselected_tautau_j1_system_dphi = std::abs(Htautau.Phi()-jet1.Phi());
    preselected_tautau_j1_system_dR = Htautau.DeltaR(jet1);
    
    // Boosted bb and small jets j2 variables
    preselected_bb_j2_system_m = bb_jet2.M();
    preselected_bb_j2_system_pt = bb_jet2.Pt();
    preselected_bb_j2_system_eta = bb_jet2.Eta();
    preselected_bb_j2_system_phi = bb_jet2.Phi();
    preselected_bb_j2_system_deta = std::abs(Hbb.Eta()-jet2.Eta());
    preselected_bb_j2_system_dphi = std::abs(Hbb.Phi()-jet2.Phi());
    preselected_bb_j2_system_dR = Hbb.DeltaR(jet2);
    
    // Boosted tautau and small jets j1 variables
    preselected_tautau_j2_system_m = tautau_jet2.M();
    preselected_tautau_j2_system_pt = tautau_jet2.Pt();
    preselected_tautau_j2_system_eta = tautau_jet2.Eta();
    preselected_tautau_j2_system_phi = tautau_jet2.Phi();
    preselected_tautau_j2_system_deta = std::abs(Htautau.Eta()-jet2.Eta());
    preselected_tautau_j2_system_dphi = std::abs(Htautau.Phi()-jet2.Phi());
    preselected_tautau_j2_system_dR = Htautau.DeltaR(jet2);

    // All jets system variables
    preselected_all_jets_system_m = all_jets.M();
    preselected_all_jets_system_pt = all_jets.Pt();
    preselected_all_jets_system_eta = all_jets.Eta();
    preselected_all_jets_system_phi = all_jets.Phi();
    preselected_all_jets_system_deta = std::abs(bb_tautau.Eta()-jet12.Eta());
    preselected_all_jets_system_dphi = std::abs(bb_tautau.Eta()-jet12.Eta());
    preselected_all_jets_system_dR = bb_tautau.DeltaR(jet12);
  
  }
  
}

// This functions pairs the 2 small jets in the VBF topology
void pairs_small_jets(){

  idx_recojet_small_j1_mjj_sel = -99; 
  idx_recojet_small_j2_mjj_sel = -99;
  idx_recojet_small_j1_ptjj_sel = -99; 
  idx_recojet_small_j2_ptjj_sel = -99;
  matched_recojet_j12_mjj_sel = false;
  matched_recojet_j12_ptjj_sel = false;

  // Only for the Bbb-Btautau class
  if(class_event==3){
    compute_small_jets_index(
      idx_recojet_small_j1_mjj_sel, 
      idx_recojet_small_j2_mjj_sel, 
      idx_recojet_small_j1_ptjj_sel, 
      idx_recojet_small_j2_ptjj_sel, 
      idx_b1truth_recoak10_dRmin, 
      idx_tau1truth_recoak10_dRmin, 
      truth_reco_match_for_boosted_bbtautau, 
      matched_recojet_j12_ptjj_sel, 
      matched_recojet_j12_mjj_sel
    );
  }

  idx_preselected_small_j1_mjj_sel = -99; 
  idx_preselected_small_j2_mjj_sel = -99;
  idx_preselected_small_j1_ptjj_sel = -99; 
  idx_preselected_small_j2_ptjj_sel = -99;
  matched_preselected_j12_mjj_sel = false;
  matched_preselected_j12_ptjj_sel = false;

  compute_small_jets_index(
    idx_preselected_small_j1_mjj_sel, 
    idx_preselected_small_j2_mjj_sel, 
    idx_preselected_small_j1_ptjj_sel, 
    idx_preselected_small_j2_ptjj_sel, 
    idx_b1_preselected, 
    idx_tau1_preselected, 
    matched_preselected_bbtautau,
    matched_preselected_j12_ptjj_sel, 
    matched_preselected_j12_mjj_sel
  );

}

void compute_small_jets_index(int &idx_small_jet1_mjj, int &idx_small_jet2_mjj, int &idx_small_jet1_ptjj, int &idx_small_jet2_ptjj, int idx_h1_jet, int idx_h2_jet, bool bbtautau_event, bool &is_jet12_ptjj_sel, bool &is_jet12_mjj_sel){
     
  float dR_min = 1.0;
  
  if( bbtautau_event == true ){

    int idx_leading_jet = 0;
    int idx_subleading_jet = 0;
  
    std::vector<int> candidates_smallJets;
    
    for(int ii=0; ii<recojet_antikt4PFlow_NOSYS_pt->size(); ii++){

      TLorentzVector small_jet = TLorentzVector();
      TLorentzVector large_R1_jet = TLorentzVector();
      TLorentzVector large_R2_jet = TLorentzVector();
      
      float small_jet_pt = recojet_antikt4PFlow_NOSYS_pt->at(ii);
      float small_jet_eta = recojet_antikt4PFlow_eta->at(ii);
      float small_jet_phi = recojet_antikt4PFlow_phi->at(ii);
      float small_jet_m = recojet_antikt4PFlow_m->at(ii);

      float large_R1_jet_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_h1_jet);
      float large_R1_jet_eta = recojet_antikt10UFO_eta->at(idx_h1_jet);
      float large_R1_jet_phi = recojet_antikt10UFO_phi->at(idx_h1_jet);
      float large_R1_jet_m = recojet_antikt10UFO_m->at(idx_h1_jet);

      float large_R2_jet_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_h2_jet);
      float large_R2_jet_eta = recojet_antikt10UFO_eta->at(idx_h2_jet);
      float large_R2_jet_phi = recojet_antikt10UFO_phi->at(idx_h2_jet);
      float large_R2_jet_m = recojet_antikt10UFO_m->at(idx_h2_jet);
      
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

      // Method 1 (leading and subleading jet)
      int current_pT_value = 0;
      
      for(int ii=0; ii<candidates_smallJets.size(); ii++){
	      if(recojet_antikt4PFlow_NOSYS_pt->at(candidates_smallJets.at(ii)) > current_pT_value){
	        current_pT_value = recojet_antikt4PFlow_NOSYS_pt->at(candidates_smallJets.at(ii));
	        idx_leading_jet = candidates_smallJets.at(ii);
	      }
      }
    
      current_pT_value = 0;
      for(int jj=0; jj<candidates_smallJets.size(); jj++){
      	if(candidates_smallJets.at(jj) != idx_leading_jet){
	        if(recojet_antikt4PFlow_NOSYS_pt->at(candidates_smallJets.at(jj)) > current_pT_value){
	          current_pT_value = recojet_antikt4PFlow_NOSYS_pt->at(candidates_smallJets.at(jj));
	          idx_subleading_jet = candidates_smallJets.at(jj);
	        }
	      }
      }
      
      idx_small_jet1_ptjj = idx_leading_jet;
      idx_small_jet2_ptjj = idx_subleading_jet;
      is_jet12_ptjj_sel = true;

      // Method 2 (largest mjj)
      float current_jet12_m = 0;
      
      for(int ii=0; ii<candidates_smallJets.size(); ii++){
      	for(int jj=ii+1; jj<candidates_smallJets.size(); jj++){

      	  int idx_jet1 = candidates_smallJets.at(ii);
	        int idx_jet2 = candidates_smallJets.at(jj);

      	  TLorentzVector jet1 = TLorentzVector();
	        TLorentzVector jet2 = TLorentzVector();

	        float jet1_pt = recojet_antikt4PFlow_NOSYS_pt->at(idx_jet1);
	        float jet1_eta = recojet_antikt4PFlow_eta->at(idx_jet1);
	        float jet1_phi = recojet_antikt4PFlow_phi->at(idx_jet1);
	        float jet1_m = recojet_antikt4PFlow_m->at(idx_jet1);
	  
	        float jet2_pt = recojet_antikt4PFlow_NOSYS_pt->at(idx_jet2);
	        float jet2_eta = recojet_antikt4PFlow_eta->at(idx_jet2);
	        float jet2_phi = recojet_antikt4PFlow_phi->at(idx_jet2);
	        float jet2_m = recojet_antikt4PFlow_m->at(idx_jet2);
	    
	        jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
	        jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

	        TLorentzVector jet12 = TLorentzVector();
	        jet12 = jet1 + jet2;
	        float jet12_m = jet12.M();
	  
	        if( jet12_m>current_jet12_m ){
	          current_jet12_m = jet12_m;
	    
	          // Takes the jet1 as the highest pT jet and the jet2 as the subleading jet
	          if(jet1_pt < jet2_pt){
	            idx_small_jet1_mjj = idx_jet2;
	            idx_small_jet2_mjj = idx_jet1;
	          }
      	    else{
	            idx_small_jet1_mjj = idx_jet1;
	            idx_small_jet2_mjj = idx_jet2;
	          }
	    
      	    is_jet12_mjj_sel = true;
	        }
        }
      }
      
      if( (recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet1_ptjj) < recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet2_ptjj)) || (recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet1_mjj) < recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet2_mjj)) ){
	      //cout << "The jets are not organized by pT" << endl;
	      number_of_desordered_small_jets_pT_candidates++;
	      cout << "pT leading jet " << recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet1_ptjj) << endl;
	      cout << "pT subleading jet " << recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet2_ptjj) << endl;

	      cout << "pT jet1 mjj " << recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet1_mjj) << endl;
	      cout << "pT jet2 mjj " << recojet_antikt4PFlow_NOSYS_pt->at(idx_small_jet2_mjj) << endl;
      }
    }
  }

}

void compute_statistical_parameters(){

  //***************************************************************************
  // Parameters for Boosted bb
  //***************************************************************************
  
  efficiency_Bbb = 100.0*TP_Bbb/(TP_Bbb+FN_Bbb);
  purity_Bbb = 100.0*TP_Bbb/(TP_Bbb+FP_Bbb);
  accuracy_Bbb = 100.0*(TP_Bbb+TN_Bbb)/(TP_Bbb+FP_Bbb+TN_Bbb+FN_Bbb);
  significance_Bbb = TP_Bbb/TMath::Sqrt(TN_Bbb);

  //***************************************************************************
  // Parameters for Boosted tautau
  //***************************************************************************
  
  efficiency_Btautau = 100.0*TP_Btautau/(TP_Btautau+FN_Btautau);
  purity_Btautau = 100.0*TP_Btautau/(TP_Btautau+FP_Btautau);
  accuracy_Btautau = 100.0*(TP_Btautau+TN_Btautau)/(TP_Btautau+FP_Btautau+TN_Btautau+FN_Btautau);
  significance_Btautau = TP_Btautau/TMath::Sqrt(TN_Btautau);

  //***************************************************************************
  // Parameters for Boosted bbtautau
  //***************************************************************************
  
  efficiency_BbbBtautau = 100.0*TP_BbbBtautau/(TP_BbbBtautau+FN_BbbBtautau);
  purity_BbbBtautau = 100.0*TP_BbbBtautau/(TP_BbbBtautau+FP_BbbBtautau);
  accuracy_BbbBtautau = 100.0*(TP_BbbBtautau+TN_BbbBtautau)/(TP_BbbBtautau+FP_BbbBtautau+TN_BbbBtautau+FN_BbbBtautau);
  significance_BbbBtautau = TP_BbbBtautau/TMath::Sqrt(TN_BbbBtautau);

  // Saving the parameters in the TH2F histogram
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 1, efficiency_BbbBtautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 2, purity_BbbBtautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 3, accuracy_BbbBtautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 4, significance_BbbBtautau);

  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 1, efficiency_Bbb);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 2, purity_Bbb);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 3, accuracy_Bbb);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 4, significance_Bbb);

  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 1, efficiency_Btautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 2, purity_Btautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 3, accuracy_Btautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 4, significance_Btautau);
  
  percentages_statistical_parameters_for_preselected_events->GetXaxis()->SetBinLabel(1, "B_{bb}-B_{#tau#tau} Preselected Events");
  percentages_statistical_parameters_for_preselected_events->GetXaxis()->SetBinLabel(2, "B_{bb} Preselected Events");
  percentages_statistical_parameters_for_preselected_events->GetXaxis()->SetBinLabel(3, "B_{#tau#tau} Preselected Events");
  
  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(1, "Efficency (%)");
  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(2, "Purity (%)");
  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(3, "Accuracy (%)");
  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(4, "Significance (%)");

  cout << "Efficiency for Bbb: " << efficiency_Bbb << endl;
  cout << "Purity for Bbb: " << purity_Bbb << endl;
  cout << "Accuracy for Bbb: " << accuracy_Bbb << endl;
  cout << "Significance for Bbb: " << significance_Bbb << endl;  
  cout << "--------------------------------" << endl;
  cout << "Efficiency for Bbb: " << percentages_statistical_parameters_for_preselected_events->GetBinContent(2,1) << endl;
  cout << "Purity for Bbb: " << percentages_statistical_parameters_for_preselected_events->GetBinContent(2,2) << endl;
  cout << "Accuracy for Bbb: " << percentages_statistical_parameters_for_preselected_events->GetBinContent(2,3) << endl;
  cout << "Significance for Bbb: " << percentages_statistical_parameters_for_preselected_events->GetBinContent(2,4) << endl;
  
  // Fill percentages Bbb
  
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 1, 100.0*matched_bb_non_preselected/matched_bb_events); // Matched events percentages wrongly preselected                                     
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 2, 100.0*overlap_matched_preselected_bb_events/matched_bb_events); // Matched events percentages being preselected                            
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 3, 100.0*matched_bb_non_preselected_info/matched_bb_events); // Matched events percentages with no preselected info                           
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 1, 100.0*preselected_bb_non_matched/matched_preselected_bb_events); // Preselected events percentages wrongly matched                         
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 2, 100.0*overlap_matched_preselected_bb_events/matched_preselected_bb_events); // Preselected events percentages being matched                
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 3, 100.0*preselected_bb_non_matched_truth_reco_info/matched_preselected_bb_events); // Preselected events percentages with no truth-reco info 

  percentages_matched_and_preselected_events_only_Bbb->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{bb} events");
  percentages_matched_and_preselected_events_only_Bbb->GetXaxis()->SetBinLabel(2, "Preselected B_{bb} events");

  percentages_matched_and_preselected_events_only_Bbb->GetYaxis()->SetBinLabel(1, "Wrong");
  percentages_matched_and_preselected_events_only_Bbb->GetYaxis()->SetBinLabel(2, "Correct");
  percentages_matched_and_preselected_events_only_Bbb->GetYaxis()->SetBinLabel(3, "No info match");

  // Fill percentages Btautau
  
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 1, 100.0*matched_tautau_non_preselected/matched_tautau_events); // Matched events percentages wrongly preselected                         
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 2, 100.0*overlap_matched_preselected_tautau_events/matched_tautau_events); // Matched events percentages being preselected                
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 3, 100.0*matched_tautau_non_preselected_info/matched_tautau_events); // Matched events percentages with no preselected info               
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 1, 100.0*preselected_tautau_non_matched/matched_preselected_tautau_events); // Preselected events percentages not being matched           
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 2, 100.0*overlap_matched_preselected_tautau_events/matched_preselected_tautau_events); // Preselected events percentages being matched    
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 3, 100.0*preselected_tautau_non_matched_truth_reco_info/matched_preselected_tautau_events); // Preselected events percentages with no truth-reco info                                                                                                                                                                                                          

  percentages_matched_and_preselected_events_only_Btautau->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{#tau#tau} events");
  percentages_matched_and_preselected_events_only_Btautau->GetXaxis()->SetBinLabel(2, "Preselected B_{#tau#tau} events");

  percentages_matched_and_preselected_events_only_Btautau->GetYaxis()->SetBinLabel(1, "Wrong");
  percentages_matched_and_preselected_events_only_Btautau->GetYaxis()->SetBinLabel(2, "Correct");
  percentages_matched_and_preselected_events_only_Btautau->GetYaxis()->SetBinLabel(3, "No info match");

  // Fill percentages Bbb-Btautau
  
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 1, 100.0*matched_bbtautau_non_preselected/matched_bbtautau_events); // Matched events percentages wrongly preselected
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 2, 100.0*overlap_matched_preselected_bbtautau_events/matched_bbtautau_events); // Matched events percentages being preselected
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 3, 100.0*matched_bbtautau_non_preselected_info/matched_bbtautau_events); // Matched events percentages with no preselected info
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 1, 100.0*preselected_bbtautau_non_matched/matched_preselected_bbtautau_events); // Preselected events percentages not being matched
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 2, 100.0*overlap_matched_preselected_bbtautau_events/matched_preselected_bbtautau_events); // Preselected events percentages being matched
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 3, 100.0*preselected_bbtautau_non_matched_truth_reco_info/matched_preselected_bbtautau_events); // Preselected events percentages with no truth-reco info
  
  percentages_matched_and_preselected_events_BbbBtautau->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{bb}-B_{#tau#tau} events");
  percentages_matched_and_preselected_events_BbbBtautau->GetXaxis()->SetBinLabel(2, "Preselected B_{bb}-B_{#tau#tau} events");

  percentages_matched_and_preselected_events_BbbBtautau->GetYaxis()->SetBinLabel(1, "Wrong");
  percentages_matched_and_preselected_events_BbbBtautau->GetYaxis()->SetBinLabel(2, "Correct");
  percentages_matched_and_preselected_events_BbbBtautau->GetYaxis()->SetBinLabel(3, "No info match");  
}

void counting_statistical_parameters(){

  //******************************************************************************************
  // Counting TP, FP, TN and FN boosted bb
  //******************************************************************************************

  if( truth_reco_match_for_boosted_bb == true ){ // All truth-reco Bbb
    // Since Bbb has the same index for b1 and b2, we only compare the b1 indexes
    if( matched_preselected_bb == true && idx_b1truth_recoak10_dRmin==idx_b1_preselected ){
      // Truth Boosted bb that are preselected as boosted bb (Correct clasiffication)
      TP_Bbb++;
    }
    else{
      // Truth Boosted bb that are preselected as non boosted bb (Lost of correct boosted events)
      FN_Bbb++;
    }
  }
  else{
    if( matched_preselected_bb == true ){
      // False Boosted bb that are preselected as boosted bb (Wrong classification)
      FP_Bbb++;
    }
    else{
      // False boosted bb that are non preselected bb (Correctly discarded)
      TN_Bbb++;
    }
  }

  //******************************************************************************************
  // Counting TP, FP, TN and FN boosted tautau
  //******************************************************************************************

  if( truth_reco_match_for_boosted_tautau== true ){ // All truth-reco Btautau
    // Since Btautau has the same index for tau1 and tau2, we only compare the b1 indexes
    if( matched_preselected_tautau == true && idx_tau1truth_recoak10_dRmin==idx_tau1_preselected ){ 
      // Truth Boosted tautau that are preselected as boosted tautau (Correct clasiffication)
      TP_Btautau++;
    }
    else{
      // Truth Boosted tautau that are preselected as non boosted tautau (Lost of correct boosted events)
      FN_Btautau++;
    }
  }
  else{
    if( matched_preselected_tautau == true ){
      // False Boosted tautau that are preselected as boosted tautau (Wrong classification)
      FP_Btautau++;
    }
    else{
      // False boosted tautau that are non preselected tautau (Correctly discarded)
      TN_Btautau++;
    }
  }

  //******************************************************************************************
  // Counting TP, FP, TN and FN boosted bbtautau
  //******************************************************************************************

  if( truth_reco_match_for_boosted_bbtautau == true ){ // All truth-reco Btautau
    if( matched_preselected_bbtautau == true && idx_b1truth_recoak10_dRmin==idx_b1_preselected && idx_tau1truth_recoak10_dRmin==idx_tau1_preselected ){ 
      // Truth Boosted BbbBtautau that are preselected as boosted BbbBtautau (Correct clasiffication)
      TP_BbbBtautau++;
    }
    else{
      // Truth Boosted BbbBtautau that are preselected as non boosted BbbBtautau (Lost of correct boosted events)
      FN_BbbBtautau++;
    }
  }
  else{
    if( matched_preselected_bbtautau == true ){
      // False Boosted BbbBtautau that are preselected as boosted BbbBtautau (Wrong classification)
      FP_BbbBtautau++;
    }
    else{
      // False boosted BbbBtautau that are non preselected BbbBtautau (Correctly discarded)
      TN_BbbBtautau++;
    }
  }
  
}

void correct_match_between_truth_reco_and_preselected_objects(){

  //**************************************************************
  // Preselected verification
  //**************************************************************

  correct_matched_preselected_Bbb = false;
  wrong_matched_preselected_Bbb = false;
  matched_preselected_Bbb_non_matched_truth_reco_info = false;
  
  correct_matched_preselected_Btautau = false;
  wrong_matched_preselected_Btautau = false;
  matched_preselected_Btautau_non_matched_truth_reco_info = false;
  
  correct_matched_preselected_BbbBtautau = false;
  wrong_matched_preselected_BbbBtautau = false;
  matched_preselected_BbbBtautau_non_matched_truth_reco_info = false;
  
  if( matched_preselected_bb == true ){
    matched_preselected_bb_events++;
    if( class_event != -1 ){
      // Since Bbb has the same index for b1 and b2, we only compare the b1 indexes
      if( (class_event == 2 || class_event == 3) && idx_b1truth_recoak10_dRmin == idx_b1_preselected ){
	correct_matched_preselected_Bbb = true;
	preselected_bb_well_matched++;
      }
      else{
	wrong_matched_preselected_Bbb = true;
	preselected_bb_non_matched++;
      }
    }
    else{
      matched_preselected_Bbb_non_matched_truth_reco_info = true;
      preselected_bb_non_matched_truth_reco_info++;
    }
  }

  if( matched_preselected_tautau == true ){
    matched_preselected_tautau_events++;
    if( class_event != -1 ){
      // Since Btautau has the same index for tau1 and tau2, we only compare the tau1 indexes
      if( (class_event == 1 || class_event == 3) && idx_tau1truth_recoak10_dRmin == idx_tau1_preselected ){
	correct_matched_preselected_Btautau = true;
	preselected_tautau_well_matched++;
      }
      else{
	wrong_matched_preselected_Btautau = true;
	preselected_tautau_non_matched++;
      }
    }
    else{
      matched_preselected_Btautau_non_matched_truth_reco_info = true;
      preselected_tautau_non_matched_truth_reco_info++;
    }
  }

  
  if( matched_preselection == true ){
    matched_preselected_bbtautau_events++;
    if( class_event != -1  ){ // class != -1 means all truth-reco info
      if( correct_matched_preselected_Bbb == true && correct_matched_preselected_Btautau == true){ // only possible when class3
	correct_matched_preselected_BbbBtautau = true;
	preselected_bbtautau_well_matched++;
      }
      else{ // other classes different from 3, means wrong matches
	wrong_matched_preselected_BbbBtautau = true;
	preselected_bbtautau_non_matched++;
      }
    }
    else{ // No info truth-reco to determine if the preselction was done correctly or not
      matched_preselected_BbbBtautau_non_matched_truth_reco_info = true;
      preselected_bbtautau_non_matched_truth_reco_info++;
    }
  }

  //**************************************************************
  // Truth-reco verification
  //**************************************************************

  truth_reco_matched_preselected_Bbb = false;
  truth_reco_non_matched_preselected_Bbb = false;
  truth_reco_Bbb_non_matched_preselected_info = false;
  
  truth_reco_matched_preselected_Btautau = false;
  truth_reco_non_matched_preselected_Btautau = false;
  truth_reco_Btautau_non_matched_preselected_info = false;

  truth_reco_matched_preselected_BbbBtautau = false;
  truth_reco_non_matched_preselected_BbbBtautau = false;
  truth_reco_BbbBtautau_non_matched_preselected_info = false;
  
  if( (class_event == 2 || class_event == 3) ){ // All truth-reco Bbb
    matched_bb_events++;
    // Since Bbb has the same index for b1 and b2, we only compare the b1 indexes
    if( matched_preselected_bb == true ){
      if( idx_b1truth_recoak10_dRmin == idx_b1_preselected ){
	truth_reco_matched_preselected_Bbb = true;
	matched_bb_well_preselection++;
      }
      else{
	truth_reco_non_matched_preselected_Bbb = true;
	matched_bb_non_preselected++;
      }
    }
    else{
      truth_reco_Bbb_non_matched_preselected_info = true;
      matched_bb_non_preselected_info++;
    }
  }

  if( (class_event == 1 || class_event == 3) ){ // All truth-reco Btautau
    matched_tautau_events++;
    if( matched_preselected_tautau == true ){ 
      // Since Btautau has the same index for tau1 and tau2, we only compare the tau1 indexes
      if( idx_tau1truth_recoak10_dRmin == idx_tau1_preselected ){
	truth_reco_matched_preselected_Btautau = true;
	matched_tautau_well_preselection++;
      }
      else{
	truth_reco_non_matched_preselected_Btautau = true;
	matched_tautau_non_preselected++;
      }
    }
    else{
      truth_reco_Btautau_non_matched_preselected_info = true;
      matched_tautau_non_preselected_info++;
    }
  }

  if( class_event == 3 ){ // All truth-reco BbbBtautau
    matched_bbtautau_events++;
    if( matched_preselection == true ){
      if( truth_reco_matched_preselected_Bbb == true && truth_reco_matched_preselected_Btautau == true ){
	truth_reco_matched_preselected_BbbBtautau = true;
	matched_bbtautau_well_preselected++;
      }
      else{
	truth_reco_non_matched_preselected_BbbBtautau = true;
	matched_bbtautau_non_preselected++;
      }
    }
    else{
      truth_reco_BbbBtautau_non_matched_preselected_info = true;
      matched_bbtautau_non_preselected_info++;
    }
  }

  //**************************************************************
  // Overlaps truth-reco and preselection verification
  //**************************************************************

  if( correct_matched_preselected_Bbb == true && truth_reco_matched_preselected_Bbb == true){
    overlap_matched_preselected_bb_events++;
  }

  if( correct_matched_preselected_Btautau == true && truth_reco_matched_preselected_Btautau == true){
    overlap_matched_preselected_tautau_events++;
  }
  
  if( correct_matched_preselected_BbbBtautau == true && truth_reco_matched_preselected_BbbBtautau == true){
    overlap_matched_preselected_bbtautau_events++;
  }
  
}

float evaluate_bdt_model(TMVA::Experimental::RBDT& model, const std::vector<float>& jet_features){

  std::vector<float> score = model.Compute(jet_features);

  return score[0];  // score for boosted jet

}

void define_preselected_events(float min_pT_cut_in_MeV, TMVA::Experimental::RBDT& model_bb, TMVA::Experimental::RBDT& model_tautau, TMVA::Experimental::RBDT& model_bbtautau_events){

  // Assign default values for preselected bb and tautau objects
  default_values_for_preselected_variables();
    
  matched_preselected_bb = false;
  matched_preselected_tautau = false;
  matched_preselection = false;
  matched_preselected_bbtautau = false;

  // std::vector<std::vector<float>> jet_features_vector_list = {
  //   recojet_antikt10UFO_NOSYS_pt,
  //   recojet_antikt10UFO_eta,
  //   recojet_antikt10UFO_phi,
  //   recojet_antikt10UFO_m,
  //   recojet_antikt10UFO_Tau1_wta,
  //   recojet_antikt10UFO_Tau2_wta,
  //   recojet_antikt10UFO_Tau3_wta,
  //   recojet_antikt10UFO_ECF1,
  //   recojet_antikt10UFO_ECF2,
  //   recojet_antikt10UFO_ECF3,
  //   recojet_antikt10UFO_Split12,
  //   recojet_antikt10UFO_Split23,
  //   recojet_antikt10UFO_GN2Xv01_phbb,
  //   recojet_antikt10UFO_GN2Xv01_pqcd,
  //   recojet_antikt10UFO_GN2Xv01_phcc,
  //   recojet_antikt10UFO_GN2Xv01_ptop
  // };

  std::vector<float> features_event;
  
  // Add number of large R jets as fisrt input

  int n_largeR_jets = recojet_antikt10UFO_NOSYS_pt->size();
  features_event.push_back(static_cast<float>(n_largeR_jets));

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_NOSYS_pt->size()) {
      features_event.push_back(recojet_antikt10UFO_NOSYS_pt->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_eta->size()) {
      features_event.push_back(recojet_antikt10UFO_eta->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_phi->size()) {
      features_event.push_back(recojet_antikt10UFO_phi->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_m->size()) {
      features_event.push_back(recojet_antikt10UFO_m->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_Tau1_wta->size()) {
      features_event.push_back(recojet_antikt10UFO_Tau1_wta->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_Tau2_wta->size()) {
      features_event.push_back(recojet_antikt10UFO_Tau2_wta->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_Tau3_wta->size()) {
      features_event.push_back(recojet_antikt10UFO_Tau3_wta->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_ECF1->size()) {
      features_event.push_back(recojet_antikt10UFO_ECF1->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }
  
  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_ECF2->size()) {
      features_event.push_back(recojet_antikt10UFO_ECF2->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_ECF3->size()) {
      features_event.push_back(recojet_antikt10UFO_ECF3->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_Split12->size()) {
      features_event.push_back(recojet_antikt10UFO_Split12->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_Split23->size()) {
      features_event.push_back(recojet_antikt10UFO_Split23->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_GN2Xv01_phbb->size()) {
      features_event.push_back(recojet_antikt10UFO_GN2Xv01_phbb->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_GN2Xv01_pqcd->size()) {
      features_event.push_back(recojet_antikt10UFO_GN2Xv01_pqcd->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_GN2Xv01_phcc->size()) {
      features_event.push_back(recojet_antikt10UFO_GN2Xv01_phcc->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  for (int ii = 0; ii < max_jets; ii++) {
    if (ii < recojet_antikt10UFO_GN2Xv01_ptop->size()) {
      features_event.push_back(recojet_antikt10UFO_GN2Xv01_ptop->at(ii));
    } 
    else {
      features_event.push_back(0.0f);
    }
  }

  float score_bbtautau_event = evaluate_bdt_model(model_bbtautau_events, features_event);
  if(score_bbtautau_event>bdt_boosted_bbtautau_event_cut){
    matched_preselected_bbtautau = true;
    hist_matched_preselected_bbtautau_score_bdt_HHbbtautau->Fill(score_bbtautau_event);
  }
  else{
    hist_non_matched_preselected_bbtautau_score_bdt_HHbbtautau->Fill(score_bbtautau_event);
  }

  int number_of_tagged_bb_jets = 0;  
  if( recojet_antikt10UFO_NOSYS_pt->size() >= 2 && matched_preselected_bbtautau==true ){
    //Selecting preselected boosted bb jet 
    for(Int_t ii=0; ii<recojet_antikt10UFO_NOSYS_pt->size(); ii++){
      std::vector jet_features = {
        recojet_antikt10UFO_NOSYS_pt->at(ii),
        recojet_antikt10UFO_eta->at(ii),
        recojet_antikt10UFO_phi->at(ii),
        recojet_antikt10UFO_m->at(ii),
        recojet_antikt10UFO_Tau1_wta->at(ii),
        recojet_antikt10UFO_Tau2_wta->at(ii),
        recojet_antikt10UFO_Tau3_wta->at(ii),
        recojet_antikt10UFO_ECF1->at(ii),
        recojet_antikt10UFO_ECF2->at(ii),
        recojet_antikt10UFO_ECF3->at(ii),
        recojet_antikt10UFO_Split12->at(ii),
        recojet_antikt10UFO_Split23->at(ii),
        recojet_antikt10UFO_GN2Xv01_phbb->at(ii),
        recojet_antikt10UFO_GN2Xv01_pqcd->at(ii),
        recojet_antikt10UFO_GN2Xv01_phcc->at(ii),
        recojet_antikt10UFO_GN2Xv01_ptop->at(ii)
      };

      float score_truth_reco_boosted_bb = evaluate_bdt_model(model_bb, jet_features);
      if(truth_reco_match_for_boosted_bb == true && ii==idx_b1truth_recoak10_dRmin){
        hist_matched_recojet_bb_score_bdt_Hbb->Fill(score_truth_reco_boosted_bb);
      }
      else{
        hist_non_matched_recojet_bb_score_bdt_Hbb->Fill(score_truth_reco_boosted_bb);
      }

      float score_truth_reco_boosted_tautau = evaluate_bdt_model(model_tautau, jet_features);
      if(truth_reco_match_for_boosted_tautau == true && ii==idx_tau1truth_recoak10_dRmin){
        hist_matched_recojet_tautau_score_bdt_Htautau->Fill(score_truth_reco_boosted_tautau);
      }
      else{
        hist_non_matched_recojet_tautau_score_bdt_Htautau->Fill(score_truth_reco_boosted_tautau);
      }

      float max_score_bb_current = 0.0;
      float max_score_bb_previous = 0.0;
      float max_score_tautau_current = 0.0;
      float max_score_tautau_previous = 0.0;

      if(recojet_antikt10UFO_NOSYS_pt->at(ii)>min_pT_cut_in_MeV && recojet_antikt10UFO_eta->at(ii)<2.5){
        
        float score_preselected_boosted_bb = evaluate_bdt_model(model_bb, jet_features);
        float score_preselected_boosted_tautau = evaluate_bdt_model(model_tautau, jet_features);

        if( score_preselected_boosted_bb>=bdt_boosted_bb_jet_cut && score_preselected_boosted_tautau<bdt_boosted_tautau_jet_cut ){
	        max_score_bb_current = score_preselected_boosted_bb;
        	if(max_score_bb_current >= max_score_bb_previous){
	          max_score_bb_previous = max_score_bb_current;
	          idx_b1_preselected = ii;
	          idx_b2_preselected = ii;
	          matched_preselected_bb = true;
            hist_matched_preselected_bb_score_bdt_Hbb->Fill(score_preselected_boosted_bb);
          }
        }
        else{
          hist_non_matched_preselected_bb_score_bdt_Hbb->Fill(score_preselected_boosted_bb);
        }

        if( score_preselected_boosted_tautau>=bdt_boosted_tautau_jet_cut && score_preselected_boosted_bb<bdt_boosted_bb_jet_cut ){
	        max_score_tautau_current = score_preselected_boosted_tautau;
        	if(max_score_tautau_current >= max_score_tautau_previous){
	          max_score_tautau_previous = max_score_tautau_current;
	          idx_tau1_preselected = ii;
	          idx_tau2_preselected = ii;
	          matched_preselected_tautau = true;
            hist_matched_preselected_tautau_score_bdt_Htautau->Fill(score_preselected_boosted_tautau);
          }
        }
        else{
          hist_non_matched_preselected_tautau_score_bdt_Htautau->Fill(score_preselected_boosted_tautau);
        }
      }
    }

    if( matched_preselected_bb == true && matched_preselected_tautau == true ){
      if(idx_b1_preselected != idx_tau1_preselected){
        matched_preselection = true;
      }
    }
    else{
      matched_preselected_bbtautau = false;
    }

    // Save the values for bb, tautau and HH objects if it was posible to find the preselected bb and tautau boosted jets

    TLorentzVector bb = TLorentzVector();
    TLorentzVector tautau = TLorentzVector();
    TLorentzVector HH = TLorentzVector();
    
    if( matched_preselected_bb == true ){
      
      preselected_bb_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected);
      preselected_bb_eta = recojet_antikt10UFO_eta->at(idx_b1_preselected);
      preselected_bb_phi = recojet_antikt10UFO_phi->at(idx_b1_preselected);
      preselected_bb_m = recojet_antikt10UFO_m->at(idx_b1_preselected);
        
      bb.SetPtEtaPhiM(preselected_bb_pt, preselected_bb_eta, preselected_bb_phi, preselected_bb_m);
     
    }

    if( matched_preselected_tautau == true ){
      
      preselected_tautau_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected);
      preselected_tautau_eta = recojet_antikt10UFO_eta->at(idx_tau1_preselected);
      preselected_tautau_phi = recojet_antikt10UFO_phi->at(idx_tau1_preselected);
      preselected_tautau_m = recojet_antikt10UFO_m->at(idx_tau1_preselected);
      
      tautau.SetPtEtaPhiM(preselected_tautau_pt, preselected_tautau_eta, preselected_tautau_phi, preselected_tautau_m);
      
    }

    if( matched_preselected_bbtautau == true ){
      
      HH = bb + tautau;
      
      preselected_HH_pt = HH.Pt();
      preselected_HH_eta = HH.Eta();
      preselected_HH_phi = HH.Phi();
      preselected_HH_m = HH.M();	
      
    }
  }

}

void define_reconstructed_objects(){
  
  TLorentzVector b1 = TLorentzVector();
  TLorentzVector b2 = TLorentzVector();
  TLorentzVector bb = TLorentzVector();

  TLorentzVector tau1 = TLorentzVector();
  TLorentzVector tau2 = TLorentzVector();
  TLorentzVector tautau = TLorentzVector();

  TLorentzVector HH = TLorentzVector();

  if( class_event != -1 ){
    if( class_event == 0){ // R_bb - R_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin));
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin));
      bb = b1+b2;
      tautau = tau1+tau2;
      HH = b1+b2+tau1+tau2;
    }

    if( class_event == 1){ // R_bb - B_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin));
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      bb = b1+b2;
      HH = b1+b2+tautau;
    }

    if( class_event == 2){ // B_bb - R_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin));
      tautau = tau1+tau2;
      HH = bb+tau1+tau2;
    }

    if( class_event == 3){ // B_bb - B_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      HH = bb+tautau;
    }
    
    reco_bbtt_bb_pt_BA = bb.Pt();
    reco_bbtt_bb_eta_BA = bb.Eta();
    reco_bbtt_bb_phi_BA = bb.Phi();
    reco_bbtt_bb_m_BA = bb.M();
    
    reco_bbtt_tautau_pt_BA = tautau.Pt();
    reco_bbtt_tautau_eta_BA = tautau.Eta();
    reco_bbtt_tautau_phi_BA = tautau.Phi();
    reco_bbtt_tautau_m_BA = tautau.M();
    
    reco_bbtt_HH_pt_BA = HH.Pt();
    reco_bbtt_HH_eta_BA = HH.Eta();
    reco_bbtt_HH_phi_BA = HH.Phi();
    reco_bbtt_HH_m_BA = HH.M();
  }

  else{
    reco_bbtt_bb_pt_BA = -99;
    reco_bbtt_bb_eta_BA = -99;
    reco_bbtt_bb_phi_BA = -99;
    reco_bbtt_bb_m_BA = -99;
    
    reco_bbtt_tautau_pt_BA = -99;
    reco_bbtt_tautau_eta_BA = -99;
    reco_bbtt_tautau_phi_BA = -99;
    reco_bbtt_tautau_m_BA = -99;

    reco_bbtt_HH_pt_BA = -99;
    reco_bbtt_HH_eta_BA = -99;
    reco_bbtt_HH_phi_BA = -99;
    reco_bbtt_HH_m_BA = -99;
  }
}


// This function tell us on which class the event is given the next description:
/*
// Condition 1: To classify the events in the 4 classes, all the truth objects must have been matched to one recojet, i.e, all the truth
// idx must be different to -1. If not, the class_event will be set to -1 (no belong to any of the 4 casses)

// Condition 2: Those events where at least one b and one tau jets were matched to the same fat jet will be discarded because we
// already know that this wouldn't be possible, so the class_event will be set to -1 (no belong to any of the 4 casses)

// Condition 3: For boosted events, we need to ensure at leats two conditions: 1- The two truth objects (bb or tautau) must be matched to
// the same fat jet and 2- the deltaR between these two truth objects must be less than 1. Thus, when we are considering the bb or tautau
// truth jets, these criteria is going to tell us when the two jets are boosted.

// Condition 4: For resolved events, we need to ensure that 1- the two truth objects (bb or tautau) have been matched to a different fat
// jet and 2- the deltaR between these two truth objects are higher than 1.

// Condition 4: Definition of the 4 classes:
For R_bb R_tautau we setup 0
For R_bb B_tautau we setup 1
For B_bb R_tautau we setup 2
For B_bb B_tautau we setup 3

*/

void define_classes(float min_pT_cut_in_MeV){

  class_event = -1;

  truth_reco_match_for_boosted_bb = false;
  truth_reco_match_for_boosted_tautau = false;
  truth_reco_match_for_boosted_bbtautau = false;
  
  if( (idx_b1truth_recoak10_dRmin!=idx_tau1truth_recoak10_dRmin) && (idx_b1truth_recoak10_dRmin!=idx_tau2truth_recoak10_dRmin) && (idx_b2truth_recoak10_dRmin!=idx_tau1truth_recoak10_dRmin) && (idx_b2truth_recoak10_dRmin!=idx_tau2truth_recoak10_dRmin)){
    if( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) ){
      if(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)>min_pT_cut_in_MeV && recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin)>min_pT_cut_in_MeV ){
        if( idx_b1truth_recoak10_dRmin == idx_b2truth_recoak10_dRmin ){
          truth_reco_match_for_boosted_bb = true;
        }
      }
    }
    
    if( (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){
      if(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)>min_pT_cut_in_MeV && recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin)>min_pT_cut_in_MeV ){
        if( idx_tau1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin ){
          truth_reco_match_for_boosted_tautau = true;
        }
      }
    }
   
    if( truth_reco_match_for_boosted_bb==true && truth_reco_match_for_boosted_tautau==true ){
      truth_reco_match_for_boosted_bbtautau = true;
    }

    // ************************************
    // For the boosted and resolved jets that are correctly identified matched to fat jets
    
    if( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){
      // For the R_bb R_tautau class
      if( (truth_reco_match_for_boosted_bb==false) && (truth_reco_match_for_boosted_tautau==false) ){
        class_event = 0;
      }
      
      // For the R_bb B_tautau class
      if( (truth_reco_match_for_boosted_bb==false) && (truth_reco_match_for_boosted_tautau==true) ){
        class_event = 1;
      }
      
      // For the B_bb R_tautau class
      if( (truth_reco_match_for_boosted_bb==true) && (truth_reco_match_for_boosted_tautau==false) ){
        class_event = 2;
      }

      // For the B_bb B_tautau class
      if( (truth_reco_match_for_boosted_bb==true) && (truth_reco_match_for_boosted_tautau==true) ){
        class_event = 3;
      }
    }

  }
  
  if(class_event==-1 && truth_reco_match_for_boosted_bb==false && truth_reco_match_for_boosted_tautau==false){
    idx_b1truth_recoak10_dRmin = -1;
    idx_b2truth_recoak10_dRmin = -1;
    idx_tau1truth_recoak10_dRmin = -1;
    idx_tau2truth_recoak10_dRmin = -1;
  } 

}

// This function set a bool variable to determine which truth-recojet is the boosted one in boosted events
void define_reco_truth_boosted_jets_hh(){

  char boosted_bbjet = 0;
  char boosted_tautaujet = 0;

  for(int ii=0; ii<recojet_antikt10UFO_NOSYS_pt->size(); ii++){
    if(class_event!=-1 && class_event!=0){
      boosted_bbjet = 0;
      // if(truth_reco_match_for_boosted_bb==true){
      if(class_event==2 || class_event==3){
        if(ii==idx_b1truth_recoak10_dRmin){
          boosted_bbjet = 1;
        }
      }
      is_truth_reco_boosted_bb_jet->push_back(boosted_bbjet);

      boosted_tautaujet = 0;
      // if(truth_reco_match_for_boosted_tautau==true){
      if(class_event==1 || class_event==3){
        if(ii==idx_tau1truth_recoak10_dRmin){
          boosted_tautaujet = 1;
        }
      }
      is_truth_reco_boosted_tautau_jet->push_back(boosted_tautaujet);
    }
    else{
      boosted_bbjet = 0;
      boosted_tautaujet = 0;
      is_truth_reco_boosted_bb_jet->push_back(boosted_bbjet);
      is_truth_reco_boosted_tautau_jet->push_back(boosted_tautaujet);
    }
  }
}

// This function give us the min deltaR between the truth_objects and the objects in the recojets_ak10UFO fat-jets
void compute_dR_min_index_fat_jets(){
  
  compute_dR_min(idx_b1truth_recoak10_dRmin, dR_min_b1truth_recoak10_fatjet, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
  compute_dR_min(idx_b2truth_recoak10_dRmin, dR_min_b2truth_recoak10_fatjet, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
  compute_dR_min(idx_tau1truth_recoak10_dRmin, dR_min_tau1truth_recoak10_fatjet, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
  compute_dR_min(idx_tau2truth_recoak10_dRmin, dR_min_tau2truth_recoak10_fatjet, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
  
}

void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m){

  dR_min = 1.0; // Min dR value for which a truth object can be matched to a recojet
  idx = -1;
  
  if(recojet_antikt10UFO_NOSYS_pt->size() > 0){
    for(int ii = 0; ii < recojet_antikt10UFO_NOSYS_pt->size(); ii++){
      
      TLorentzVector truth_jet  = TLorentzVector();
      TLorentzVector reco_jet  = TLorentzVector();
      
      float reco_pt = recojet_antikt10UFO_NOSYS_pt->at(ii);
      float reco_eta = recojet_antikt10UFO_eta->at(ii);
      float reco_phi = recojet_antikt10UFO_phi->at(ii);
      float reco_m = recojet_antikt10UFO_m->at(ii);
      
      truth_jet.SetPtEtaPhiM(truth_pt, truth_eta, truth_phi, truth_m);
      reco_jet.SetPtEtaPhiM(reco_pt, reco_eta, reco_phi, reco_m);
      
      float deltaR_truth_recojet = truth_jet.DeltaR(reco_jet);
      
      if( (deltaR_truth_recojet < dR_min) ){
	dR_min = deltaR_truth_recojet;
	idx = ii;
      }
    }
  }
  else{
    idx = -1;
    dR_min = -1;
  }
}

void define_truth_tau_and_b_jets(){

  // set -99 to truth variables
  default_values_for_truth_variables();
  
  if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){

    int sum_type_H1 = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1));
    int sum_type_H2 = TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
    int sum_type_HH = sum_type_H1+sum_type_H2;
    
    // Here we assume that all the jets are listed from the highest pT to the lowest pT
    int index_b1 = 0;
    int index_b2 = 1;
    int index_tau1 = 0;
    int index_tau2 = 1;

    TLorentzVector b1_jet  = TLorentzVector();
    TLorentzVector b2_jet  = TLorentzVector();
    TLorentzVector bb_jet  = TLorentzVector();

    TLorentzVector tau1_jet  = TLorentzVector();
    TLorentzVector tau2_jet  = TLorentzVector();
    TLorentzVector tautau_jet  = TLorentzVector();

    TLorentzVector HH_jet  = TLorentzVector();

    if( sum_type_HH == 40 ){
      // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1bb_H2tautau scenario
      if( (sum_type_H1 == 10) && (sum_type_H2 == 30) ){
	      if(truth_children_fromH1_pt->at(0) < truth_children_fromH1_pt->at(1)){
          index_b1 = 1;
          index_b2 = 0;
        }
	
        if(truth_children_fromH2_pt->at(0) < truth_children_fromH2_pt->at(1)){
          index_tau1 = 1;
          index_tau2 = 0;
        }
          
        truth_b1_pt = truth_children_fromH1_pt->at(index_b1);
        truth_b1_eta = truth_children_fromH1_eta->at(index_b1);
        truth_b1_phi = truth_children_fromH1_phi->at(index_b1);
        truth_b1_m = truth_children_fromH1_m->at(index_b1);

        truth_b2_pt = truth_children_fromH1_pt->at(index_b2);
        truth_b2_eta = truth_children_fromH1_eta->at(index_b2);
        truth_b2_phi = truth_children_fromH1_phi->at(index_b2);
        truth_b2_m = truth_children_fromH1_m->at(index_b2);
        
        truth_tau1_pt = truth_children_fromH2_pt->at(index_tau1);
        truth_tau1_eta = truth_children_fromH2_eta->at(index_tau1);
        truth_tau1_phi = truth_children_fromH2_phi->at(index_tau1);
        truth_tau1_m = truth_children_fromH2_m->at(index_tau1);	
        
        truth_tau2_pt = truth_children_fromH2_pt->at(index_tau2);
        truth_tau2_eta = truth_children_fromH2_eta->at(index_tau2);
        truth_tau2_phi = truth_children_fromH2_phi->at(index_tau2);
        truth_tau2_m = truth_children_fromH2_m->at(index_tau2);
      } 

      if( (sum_type_H1 == 30) && (sum_type_H2 == 10) ){
	
        // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1tautau_H2bb scenario
        if(truth_children_fromH2_pt->at(0) < truth_children_fromH2_pt->at(1)){
          index_b1 = 1;
          index_b2 = 0;
        } 
        if(truth_children_fromH1_pt->at(0) < truth_children_fromH1_pt->at(1)){
          index_tau1 = 1;
          index_tau2 = 0;
        }
        
        truth_b1_pt = truth_children_fromH2_pt->at(index_b1);
        truth_b1_eta = truth_children_fromH2_eta->at(index_b1);
        truth_b1_phi = truth_children_fromH2_phi->at(index_b1);
        truth_b1_m = truth_children_fromH2_m->at(index_b1);
        
        truth_b2_pt = truth_children_fromH2_pt->at(index_b2);
        truth_b2_eta = truth_children_fromH2_eta->at(index_b2);
        truth_b2_phi = truth_children_fromH2_phi->at(index_b2);
        truth_b2_m = truth_children_fromH2_m->at(index_b2);
        
        truth_tau1_pt = truth_children_fromH1_pt->at(index_tau1);
        truth_tau1_eta = truth_children_fromH1_eta->at(index_tau1);
        truth_tau1_phi = truth_children_fromH1_phi->at(index_tau1);
        truth_tau1_m = truth_children_fromH1_m->at(index_tau1);	
            
        truth_tau2_pt = truth_children_fromH1_pt->at(index_tau2);
        truth_tau2_eta = truth_children_fromH1_eta->at(index_tau2);
        truth_tau2_phi = truth_children_fromH1_phi->at(index_tau2);
        truth_tau2_m = truth_children_fromH1_m->at(index_tau2);	
      }

      b1_jet.SetPtEtaPhiM(truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
      b2_jet.SetPtEtaPhiM(truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      bb_jet = b1_jet + b2_jet;
      
      truth_bb_pt = bb_jet.Pt();
      truth_bb_eta = bb_jet.Eta();
      truth_bb_phi = bb_jet.Phi();
      truth_bb_m = bb_jet.M();
	
      tau1_jet.SetPtEtaPhiM(truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
      tau2_jet.SetPtEtaPhiM(truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
      tautau_jet = tau1_jet + tau2_jet;
      
      truth_tautau_pt = tautau_jet.Pt();
      truth_tautau_eta = tautau_jet.Eta();
      truth_tautau_phi = tautau_jet.Phi();
      truth_tautau_m = tautau_jet.M();
      
      HH_jet = bb_jet + tautau_jet;
	
      truth_HH_pt = HH_jet.Pt();
      truth_HH_eta = HH_jet.Eta();
      truth_HH_phi = HH_jet.Phi();
      truth_HH_m = HH_jet.M();	

      truth_events++;
    }
  }
}

// This function set the values -99 for truth variables when HH->bbtautau is not identified
void default_values_for_truth_variables(){

  truth_b1_pt = -99;
  truth_b1_eta = -99;
  truth_b1_phi = -99;
  truth_b1_m = -99;
  
  truth_b2_pt = -99;
  truth_b2_eta = -99;
  truth_b2_phi = -99;
  truth_b2_m = -99;
  
  truth_tau1_pt = -99;
  truth_tau1_eta = -99;
  truth_tau1_phi = -99;
  truth_tau1_m = -99;
  
  truth_tau2_pt = -99;
  truth_tau2_eta = -99;
  truth_tau2_phi = -99;
  truth_tau2_m = -99;
  
  truth_HH_pt = -99;
  truth_HH_eta = -99;
  truth_HH_phi = -99;
  truth_HH_m = -99;

  truth_bb_pt = -99;
  truth_bb_eta = -99;
  truth_bb_phi = -99;
  truth_bb_m = -99;

  truth_tautau_pt = -99;
  truth_tautau_eta = -99;
  truth_tautau_phi = -99;
  truth_tautau_m = -99;
}

// This function set the values -99 for preselected variables when HH->bbtautau is not identified
void default_values_for_preselected_variables(){

  preselected_HH_pt = -99;
  preselected_HH_eta = -99;
  preselected_HH_phi = -99;
  preselected_HH_m = -99;
  
  preselected_bb_pt = -99;
  preselected_bb_eta = -99;
  preselected_bb_phi = -99;
  preselected_bb_m = -99;

  preselected_tautau_pt = -99;
  preselected_tautau_eta = -99;
  preselected_tautau_phi = -99;
  preselected_tautau_m = -99;

  idx_b1_preselected = -99;
  idx_b2_preselected = -99;
  idx_tau1_preselected = -99;
  idx_tau2_preselected = -99;
  
}
