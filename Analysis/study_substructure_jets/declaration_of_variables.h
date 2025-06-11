#include "ratio_acceptances_reco_variables_histograms.h"
#include "ratio_acceptances_truth_variables_histograms.h"
#include "ratio_acceptances_preselected_events_variables_histograms.h"
#include "truth_recojets_histograms.h"
#include "preselected_recojets_histograms.h"

// *************************************
// Declaration of global variables
// *************************************

string process_name = "";
string process_type_like = "";
string name_output_root_file = "";
int class_label;
float fraction = 1.0;

// values to be printed in the screen for statistical checks
int count_preselected_bb_jets_ordered_by_pT = 0;
int count_preselected_bb_jets_ordered_by_nsubjettiness = 0;

int count_b_tau_matched_recojets = 0;

int count_non_matched_events = 0;
int count_truth_Rbb_Rtautau = 0;
int count_truth_Rbb_Btautau = 0;
int count_truth_Bbb_Rtautau = 0;
int count_truth_Bbb_Btautau = 0;

int count_pos_resolved_b1_config = 0;
int count_pos_resolved_b2_config = 0;
int count_pos_resolved_tau1_config = 0;
int count_pos_resolved_tau2_config = 0;

int count_pos_resolved_HH_pt_config = 0;
int count_pos_resolved_HH_phi_config = 0;
int count_pos_resolved_HH_eta_config = 0;
int count_pos_resolved_HH_m_config = 0;
int count_pos_resolved_HH_vis_pt_config = 0;
int count_pos_resolved_HH_vis_m_config = 0;

int count_all_objects_resolved_config = 0;

int count_truth_HH_pt_pos_values = 0;
int count_truth_HH_m_pos_values = 0;

// *******************************************************************
// New variables for VBF topology
// *******************************************************************

// small jets matching variables
int idx_jet1_VBF_topology_mjj_sel;
int idx_jet2_VBF_topology_mjj_sel;
int idx_jet1_VBF_topology_ptjj_sel;
int idx_jet2_VBF_topology_ptjj_sel;
bool is_jet12_matched_mjj_sel;
bool is_jet12_matched_ptjj_sel;

int count_bb_candidates;
int count_tautau_candidates;

int overlap_jj_selection_methods = 0;
int eta_smalljets_cutflow = 0;
int minpt_smalljets_cutflow = 0;
int min_mjj_smalljets_cutflow = 0;
int min_dR_smalljets_cutflow = 0;
int all_cuts_applied_cutflow = 0;

int number_of_desordered_small_jets_pT_candidates = 0;

int smallR_jets_n;
int largeR_jets_n;

// Two small jets j1 and j2 variables
float two_jets_j12_m;
float two_jets_j12_pt;
float two_jets_j12_eta;
float two_jets_j12_phi;
float two_jets_j12_deta;
float two_jets_j12_dphi;
float two_jets_j12_dR;

// Boosted bb and boosted tautau variables
float boosted_bb_tautau_system_m;
float boosted_bb_tautau_system_pt;
float boosted_bb_tautau_system_eta;
float boosted_bb_tautau_system_phi;
float boosted_bb_tautau_system_deta;
float boosted_bb_tautau_system_dphi;
float boosted_bb_tautau_system_dR;

// Boosted bb and small jets j1 variables
float boosted_bb_j1_system_m;
float boosted_bb_j1_system_pt;
float boosted_bb_j1_system_eta;
float boosted_bb_j1_system_phi;
float boosted_bb_j1_system_deta;
float boosted_bb_j1_system_dphi;
float boosted_bb_j1_system_dR;

// Boosted tautau and small jets j1 variables
float boosted_tautau_j1_system_m;
float boosted_tautau_j1_system_pt;
float boosted_tautau_j1_system_eta;
float boosted_tautau_j1_system_phi;
float boosted_tautau_j1_system_deta;
float boosted_tautau_j1_system_dphi;
float boosted_tautau_j1_system_dR;

// Boosted bb and small jets j2 variables
float boosted_bb_j2_system_m;
float boosted_bb_j2_system_pt;
float boosted_bb_j2_system_eta;
float boosted_bb_j2_system_phi;
float boosted_bb_j2_system_deta;
float boosted_bb_j2_system_dphi;
float boosted_bb_j2_system_dR;

// Boosted tautau and small jets j1 variables
float boosted_tautau_j2_system_m;
float boosted_tautau_j2_system_pt;
float boosted_tautau_j2_system_eta;
float boosted_tautau_j2_system_phi;
float boosted_tautau_j2_system_deta;
float boosted_tautau_j2_system_dphi;
float boosted_tautau_j2_system_dR;

// All jets system variables
float boosted_all_jets_system_m;
float boosted_all_jets_system_pt;
float boosted_all_jets_system_eta;
float boosted_all_jets_system_phi;
float boosted_all_jets_system_deta;
float boosted_all_jets_system_dphi;
float boosted_all_jets_system_dR;

// preselected matched counter variables

// for preselected-matched bb

int matched_bb_events = 0;
int matched_bb_well_preselection = 0;
int matched_bb_non_preselected = 0;
int matched_bb_non_preselected_info = 0;
int matched_preselected_bb_events = 0;
int preselected_bb_well_matched = 0;
int preselected_bb_non_matched = 0;
int preselected_bb_non_matched_truth_reco_info = 0;
int overlap_matched_preselected_bb_events = 0;

int TP_Bbb = 0;
int FP_Bbb = 0;
int TN_Bbb = 0;
int FN_Bbb = 0;
float efficiency_Bbb = 0;
float purity_Bbb = 0;
float accuracy_Bbb = 0;

// Truth reco matching for boosted events
bool truth_reco_match_for_boosted_bb;
bool truth_reco_match_for_boosted_tautau;
bool truth_reco_match_for_boosted_bbtautau;

// for preselected-matched tautau

int matched_tautau_events = 0;
int matched_tautau_well_preselection = 0;
int matched_tautau_non_preselected = 0;
int matched_tautau_non_preselected_info = 0;
int matched_preselected_tautau_events = 0;
int preselected_tautau_well_matched = 0;
int preselected_tautau_non_matched = 0;
int preselected_tautau_non_matched_truth_reco_info = 0;
int overlap_matched_preselected_tautau_events = 0;

int TP_Btautau = 0;
int FP_Btautau = 0;
int TN_Btautau = 0;
int FN_Btautau = 0;
float efficiency_Btautau = 0;
float purity_Btautau = 0;
float accuracy_Btautau = 0;

// for preselected-matched Bbb-Btautau

int matched_bbtautau_events = 0;
int matched_bbtautau_well_preselected = 0;
int matched_bbtautau_non_preselected = 0;
int matched_bbtautau_non_preselected_info = 0;
int matched_preselected_bbtautau_events = 0;
int preselected_bbtautau_well_matched = 0;
int preselected_bbtautau_non_matched = 0;
int preselected_bbtautau_non_matched_truth_reco_info = 0;
int overlap_matched_preselected_bbtautau_events = 0;

int TP_BbbBtautau = 0;
int FP_BbbBtautau = 0;
int TN_BbbBtautau = 0;
int FN_BbbBtautau = 0;
float efficiency_BbbBtautau = 0;
float purity_BbbBtautau = 0;
float accuracy_BbbBtautau = 0;

// *************************************
// Declaration of leaf variables
// *************************************

// Declaration of leaf types for truth_children branches for boosted tree variables

// truth children from Higgs
vector<int> *truth_children_fromH1_pdgId;
vector<int> *truth_children_fromH2_pdgId;
vector<float> *truth_children_fromH1_pt;
vector<float> *truth_children_fromH1_eta;
vector<float> *truth_children_fromH1_phi;
vector<float> *truth_children_fromH1_m;
vector<float> *truth_children_fromH2_pt;
vector<float> *truth_children_fromH2_eta;
vector<float> *truth_children_fromH2_phi;
vector<float> *truth_children_fromH2_m;

// GN2X variables
vector<float> *recojet_antikt10UFO_GN2Xv01_phbb;
vector<float> *recojet_antikt10UFO_GN2Xv01_pqcd;
vector<float> *recojet_antikt10UFO_GN2Xv01_phcc;
vector<float> *recojet_antikt10UFO_GN2Xv01_ptop;

// Truth HH variables
Float_t truth_HH_pt;
Float_t truth_HH_eta;
Float_t truth_HH_phi;
Float_t truth_HH_m;

vector<float> *truthjet_antikt4_pt;
vector<float> *truthjet_antikt4_eta;
vector<float> *truthjet_antikt4_phi;
vector<float> *truthjet_antikt4_m;
vector<int> *truthjet_antikt4_HadronConeExclTruthLabelID;

// Matching of truth b and tau jets from truth children
Float_t truth_b1_pt;
Float_t truth_b1_eta;
Float_t truth_b1_phi;
Float_t truth_b1_m;

Float_t truth_b2_pt;
Float_t truth_b2_eta;
Float_t truth_b2_phi;
Float_t truth_b2_m;

Float_t truth_tau1_pt;
Float_t truth_tau1_eta;
Float_t truth_tau1_phi;
Float_t truth_tau1_m;

Float_t truth_tau2_pt;
Float_t truth_tau2_eta;
Float_t truth_tau2_phi;
Float_t truth_tau2_m;

Float_t truth_bb_pt;
Float_t truth_bb_eta;
Float_t truth_bb_phi;
Float_t truth_bb_m;

Float_t truth_tautau_pt;
Float_t truth_tautau_eta;
Float_t truth_tautau_phi;
Float_t truth_tautau_m;

vector<float> *tau_nProng;

// Declaration of leafs types for reconstructed_ak4 jets (small-jets) branches for boosted tree variables
vector<float> *recojet_antikt4PFlow_NOSYS_pt;
vector<float> *recojet_antikt4PFlow_eta;
vector<float> *recojet_antikt4PFlow_phi;
vector<float> *recojet_antikt4PFlow_m;

// Declaration of leafs types for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
vector<float> *recojet_antikt10UFO_NOSYS_pt;
vector<float> *recojet_antikt10UFO_eta;
vector<float> *recojet_antikt10UFO_phi;
vector<float> *recojet_antikt10UFO_m;
vector<float> *recojet_antikt10UFO_Tau1_wta;
vector<float> *recojet_antikt10UFO_Tau2_wta;
vector<float> *recojet_antikt10UFO_Tau3_wta;
vector<float> *recojet_antikt10UFO_ECF1;
vector<float> *recojet_antikt10UFO_ECF2;
vector<float> *recojet_antikt10UFO_ECF3;
vector<float> *recojet_antikt10UFO_Split12;
vector<float> *recojet_antikt10UFO_Split23;
vector<char> *recojet_antikt10UFO_NOSYS_passesOR;

// Declaration idx and dRmin values

Int_t idx_b1truth_recoak10_dRmin;
Int_t idx_b2truth_recoak10_dRmin;
Int_t idx_tau1truth_recoak10_dRmin;
Int_t idx_tau2truth_recoak10_dRmin;

Float_t dR_min_b1truth_recoak10_fatjet;
Float_t dR_min_b2truth_recoak10_fatjet;
Float_t dR_min_tau1truth_recoak10_fatjet;
Float_t dR_min_tau2truth_recoak10_fatjet;

Float_t reco_bbtt_bb_pt_BA;
Float_t reco_bbtt_bb_eta_BA;
Float_t reco_bbtt_bb_phi_BA;
Float_t reco_bbtt_bb_m_BA;

Float_t reco_bbtt_tautau_pt_BA;
Float_t reco_bbtt_tautau_eta_BA;
Float_t reco_bbtt_tautau_phi_BA;
Float_t reco_bbtt_tautau_m_BA;

Float_t reco_bbtt_HH_pt_BA;
Float_t reco_bbtt_HH_eta_BA;
Float_t reco_bbtt_HH_phi_BA;
Float_t reco_bbtt_HH_m_BA;

int class_event;

//Declaration of preselected events

Int_t idx_b1_preselected;
Int_t idx_b2_preselected;
Int_t idx_tau1_preselected;
Int_t idx_tau2_preselected;

Float_t preselected_bb_pt;
Float_t preselected_bb_eta;
Float_t preselected_bb_phi;
Float_t preselected_bb_m;

Float_t preselected_tautau_pt;
Float_t preselected_tautau_eta;
Float_t preselected_tautau_phi;
Float_t preselected_tautau_m;

Float_t preselected_HH_pt;
Float_t preselected_HH_eta;
Float_t preselected_HH_phi;
Float_t preselected_HH_m;

bool matched_preselection; // Tell us if the bb and tautau objects were defined with the preselection cuts on recovariables
bool correct_matched_preselected_BbbBtautau;
bool wrong_matched_preselected_BbbBtautau;
bool matched_preselected_BbbBtautau_non_matched_truth_reco_info;
bool truth_reco_matched_preselected_BbbBtautau;
bool truth_reco_non_matched_preselected_BbbBtautau;
bool truth_reco_BbbBtautau_non_matched_preselected_info;

bool matched_preselected_bb;
bool correct_matched_preselected_Bbb;
bool wrong_matched_preselected_Bbb;
bool matched_preselected_Bbb_non_matched_truth_reco_info;
bool truth_reco_matched_preselected_Bbb;
bool truth_reco_non_matched_preselected_Bbb;
bool truth_reco_Bbb_non_matched_preselected_info;

bool matched_preselected_tautau;
bool correct_matched_preselected_Btautau;
bool wrong_matched_preselected_Btautau;
bool matched_preselected_Btautau_non_matched_truth_reco_info;
bool truth_reco_matched_preselected_Btautau;
bool truth_reco_non_matched_preselected_Btautau;
bool truth_reco_Btautau_non_matched_preselected_info;

// Declaration of the resolved variables results

Float_t bbtt_Jet_b1_pt_NOSYS;
Float_t bbtt_Jet_b1_eta;
Float_t bbtt_Jet_b1_phi;
Float_t bbtt_Jet_b1_E;

Float_t bbtt_Jet_b2_pt_NOSYS;
Float_t bbtt_Jet_b2_eta;
Float_t bbtt_Jet_b2_phi;
Float_t bbtt_Jet_b2_E;

Float_t bbtt_Tau1_pt_NOSYS;
Float_t bbtt_Tau1_eta;
Float_t bbtt_Tau1_phi;
Float_t bbtt_Tau1_E;

Float_t bbtt_Tau2_pt_NOSYS;
Float_t bbtt_Tau2_eta;
Float_t bbtt_Tau2_phi;
Float_t bbtt_Tau2_E;

Float_t bbtt_HH_pt_NOSYS;
Float_t bbtt_HH_eta;
Float_t bbtt_HH_phi;
Float_t bbtt_HH_m;

Float_t bbtt_HH_vis_pt_NOSYS;
Float_t bbtt_HH_vis_m;

Float_t generatorWeight_NOSYS;
vector<char> *recojet_antikt4PFlow_NOSYS_passesOR;

// *************************************
// Declaration of branches
// *************************************

// truth children from Higgs
TBranch *b_truth_children_fromH1_pdgId;
TBranch *b_truth_children_fromH2_pdgId;
TBranch *b_truth_children_fromH1_pt;
TBranch *b_truth_children_fromH1_eta;
TBranch *b_truth_children_fromH1_phi;
TBranch *b_truth_children_fromH1_m;
TBranch *b_truth_children_fromH2_pt;
TBranch *b_truth_children_fromH2_eta;
TBranch *b_truth_children_fromH2_phi;
TBranch *b_truth_children_fromH2_m;

// GN2X variables
TBranch *b_recojet_antikt10UFO_GN2Xv01_phbb;
TBranch *b_recojet_antikt10UFO_GN2Xv01_pqcd;
TBranch *b_recojet_antikt10UFO_GN2Xv01_phcc;
TBranch *b_recojet_antikt10UFO_GN2Xv01_ptop;

// Truth HH variables
TBranch *b_truth_HH_pt;
TBranch *b_truth_HH_eta;
TBranch *b_truth_HH_phi;
TBranch *b_truth_HH_m;

TBranch *b_truthjet_antikt4_pt;
TBranch *b_truthjet_antikt4_eta;
TBranch *b_truthjet_antikt4_phi;
TBranch *b_truthjet_antikt4_m;
TBranch *b_truthjet_antikt4_HadronConeExclTruthLabelID;

// Matching of truth b and tau jets from truth children
TBranch *b_truth_b1_pt;
TBranch *b_truth_b1_eta;
TBranch *b_truth_b1_phi;
TBranch *b_truth_b1_m;

TBranch *b_truth_b2_pt;
TBranch *b_truth_b2_eta;
TBranch *b_truth_b2_phi;
TBranch *b_truth_b2_m;

TBranch *b_truth_tau1_pt;
TBranch *b_truth_tau1_eta;
TBranch *b_truth_tau1_phi;
TBranch *b_truth_tau1_m;

TBranch *b_truth_tau2_pt;
TBranch *b_truth_tau2_eta;
TBranch *b_truth_tau2_phi;
TBranch *b_truth_tau2_m;

TBranch *b_tau_nProng;

// Declaration branches for reconstructed_ak4 jets (small-jets) branches for boosted tree variables
TBranch *b_recojet_antikt4PFlow_NOSYS_pt;
TBranch *b_recojet_antikt4PFlow_eta;
TBranch *b_recojet_antikt4PFlow_phi;
TBranch *b_recojet_antikt4PFlow_m;

// Declaration branches for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
TBranch *b_recojet_antikt10UFO_NOSYS_pt;
TBranch *b_recojet_antikt10UFO_eta;
TBranch *b_recojet_antikt10UFO_phi;
TBranch *b_recojet_antikt10UFO_m;
TBranch *b_recojet_antikt10UFO_Tau1_wta;
TBranch *b_recojet_antikt10UFO_Tau2_wta;
TBranch *b_recojet_antikt10UFO_Tau3_wta;
TBranch *b_recojet_antikt10UFO_ECF1;
TBranch *b_recojet_antikt10UFO_ECF2;
TBranch *b_recojet_antikt10UFO_ECF3;
TBranch *b_recojet_antikt10UFO_Split12;
TBranch *b_recojet_antikt10UFO_Split23;
TBranch *b_recojet_antikt10UFO_NOSYS_passesOR;

// Declaration idx and dRmin values

TBranch *b_idx_b1truth_recoak10_dRmin;
TBranch *b_idx_b2truth_recoak10_dRmin;
TBranch *b_idx_tau1truth_recoak10_dRmin;
TBranch *b_idx_tau2truth_recoak10_dRmin;

TBranch *b_dR_min_b1truth_recoak10_fatjet;
TBranch *b_dR_min_b2truth_recoak10_fatjet;
TBranch *b_dR_min_tau1truth_recoak10_fatjet;
TBranch *b_dR_min_tau2truth_recoak10_fatjet;

TBranch *b_truth_boosted_bb;
TBranch *b_truth_boosted_tautau;
TBranch *b_truth_resolved_bb;
TBranch *b_truth_resolved_tautau;
TBranch *b_class_event;

TBranch *b_idx_b1_preselected;
TBranch *b_idx_b2_preselected;
TBranch *b_idx_tau1_preselected;
TBranch *b_idx_tau2_preselected;

TBranch *b_preselected_bb_pt;
TBranch *b_preselected_bb_eta;
TBranch *b_preselected_bb_phi;
TBranch *b_preselected_bb_m;

TBranch *b_preselected_tautau_pt;
TBranch *b_preselected_tautau_eta;
TBranch *b_preselected_tautau_phi;
TBranch *b_preselected_tautau_m;

TBranch *b_preselected_HH_pt;
TBranch *b_preselected_HH_eta;
TBranch *b_preselected_HH_phi;
TBranch *b_preselected_HH_m;

TBranch *b_matched_preselection;
TBranch *b_matched_preselected_bb;
TBranch *b_matched_preselected_tautau;

// Declaration of the resolved variables results

TBranch *b_bbtt_Jet_b1_pt_NOSYS;
TBranch *b_bbtt_Jet_b1_eta;
TBranch *b_bbtt_Jet_b1_phi;
TBranch *b_bbtt_Jet_b1_E;

TBranch *b_bbtt_Jet_b2_pt_NOSYS;
TBranch *b_bbtt_Jet_b2_eta;
TBranch *b_bbtt_Jet_b2_phi;
TBranch *b_bbtt_Jet_b2_E;

TBranch *b_bbtt_Tau1_pt_NOSYS;
TBranch *b_bbtt_Tau1_eta;
TBranch *b_bbtt_Tau1_phi;
TBranch *b_bbtt_Tau1_E;

TBranch *b_bbtt_Tau2_pt_NOSYS;
TBranch *b_bbtt_Tau2_eta;
TBranch *b_bbtt_Tau2_phi;
TBranch *b_bbtt_Tau2_E;

TBranch *b_bbtt_HH_pt_NOSYS;
TBranch *b_bbtt_HH_eta;
TBranch *b_bbtt_HH_phi;
TBranch *b_bbtt_HH_m;

TBranch *b_bbtt_HH_vis_pt_NOSYS;
TBranch *b_bbtt_HH_vis_m;

TBranch *b_generatorWeight_NOSYS;
TBranch *b_recojet_antikt4PFlow_NOSYS_passesOR;

// *************************************
// Declaration of temporary variables to fill acceptance ratio histograms
// *************************************

// reco
Float_t reco_HH_m_temp_hist;
Float_t reco_HH_pt_temp_hist;
Float_t reco_HH_eta_temp_hist;
Float_t reco_HH_phi_temp_hist;

Float_t reco_bb_m_temp_hist;
Float_t reco_bb_pt_temp_hist;
Float_t reco_bb_eta_temp_hist;
Float_t reco_bb_phi_temp_hist;

Float_t reco_tautau_m_temp_hist;
Float_t reco_tautau_pt_temp_hist;
Float_t reco_tautau_eta_temp_hist;
Float_t reco_tautau_phi_temp_hist;

// truth

Float_t truth_HH_m_temp_hist;
Float_t truth_HH_pt_temp_hist;
Float_t truth_HH_eta_temp_hist;
Float_t truth_HH_phi_temp_hist;

Float_t truth_bb_m_temp_hist;
Float_t truth_bb_pt_temp_hist;
Float_t truth_bb_eta_temp_hist;
Float_t truth_bb_phi_temp_hist;

Float_t truth_tautau_m_temp_hist;
Float_t truth_tautau_pt_temp_hist;
Float_t truth_tautau_eta_temp_hist;
Float_t truth_tautau_phi_temp_hist;

//preselected

Float_t preselected_HH_m_temp_hist;
Float_t preselected_HH_pt_temp_hist;
Float_t preselected_HH_eta_temp_hist;
Float_t preselected_HH_phi_temp_hist;

Float_t preselected_bb_m_temp_hist;
Float_t preselected_bb_pt_temp_hist;
Float_t preselected_bb_eta_temp_hist;
Float_t preselected_bb_phi_temp_hist;

Float_t preselected_tautau_m_temp_hist;
Float_t preselected_tautau_pt_temp_hist;
Float_t preselected_tautau_eta_temp_hist;
Float_t preselected_tautau_phi_temp_hist;
