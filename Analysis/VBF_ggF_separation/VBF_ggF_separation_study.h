// **************************************************************************************************
// Declaration of variables, branches, etc
// **************************************************************************************************

// *************************************
// Candidates for boosted jets
// *************************************
string process_name = "";
string name_output_root_file = "";
int process_type_like;

int idx_boosted_bb;
int idx_boosted_tautau;
bool is_boosted_bb;
bool is_boosted_tautau;
bool is_boosted_bbtautau;
int idx_preselected_small_j1_mjj_sel;
int idx_preselected_small_j2_mjj_sel;
int idx_preselected_small_j1_ptjj_sel;
int idx_preselected_small_j2_ptjj_sel;
bool matched_preselected_j12_mjj_sel;
bool matched_preselected_j12_ptjj_sel;

int count_bb_candidates;
int count_tautau_candidates;

int overlap_jj_selection_methods = 0;
int eta_smalljets_cutflow = 0;
int minpt_smalljets_cutflow = 0;
int min_mjj_smalljets_cutflow = 0;
int min_dR_smalljets_cutflow = 0;
int all_cuts_applied_cutflow = 0;

int number_of_desordered_small_jets_pT_candidates = 0;

// *************************************
// Declaration of leaf variables
// *************************************

// Declaration of leaf types for truth_children branches for boosted tree variables

// Declaration of leaf types for boosted VBF tree variables

// Large R-jets variables
vector<float> *recojet_antikt10UFO_GN2XTauV00_disc___NOSYS;
vector<float> *recojet_antikt10UFO_ECF1___NOSYS;
vector<float> *recojet_antikt10UFO_ECF2___NOSYS;
vector<float> *recojet_antikt10UFO_ECF3___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv01_phbb___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv01_phcc___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv01_ptop___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv02_phbb___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv02_phcc___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS;
vector<float> *recojet_antikt10UFO_GN2Xv02_ptop___NOSYS;
vector<int> *recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS;
vector<int> *recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS;
vector<int> *recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS;
vector<int> *recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS;
vector<float> *recojet_antikt10UFO_Split12___NOSYS;
vector<float> *recojet_antikt10UFO_Split23___NOSYS;
vector<float> *recojet_antikt10UFO_Tau1_wta___NOSYS;
vector<float> *recojet_antikt10UFO_Tau2_wta___NOSYS;
vector<float> *recojet_antikt10UFO_Tau3_wta___NOSYS;
vector<float> *recojet_antikt10UFO_eta___NOSYS;
vector<char> *recojet_antikt10UFO_isAnalysisJet___NOSYS;
vector<char> *recojet_antikt10UFO_isjet1___NOSYS;
vector<char> *recojet_antikt10UFO_isjet2___NOSYS;
vector<float> *recojet_antikt10UFO_m___NOSYS;
vector<float> *recojet_antikt10UFO_phi___NOSYS;
vector<float> *recojet_antikt10UFO_pt___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS;
vector<int> *recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS;

// Small R-jets variables
vector<float> *recojet_antikt4PFlow_m___NOSYS;
vector<float> *recojet_antikt4PFlow_eta___NOSYS;
vector<float> *recojet_antikt4PFlow_phi___NOSYS;
vector<float> *recojet_antikt4PFlow_pt___NOSYS;

// *******************************************************************
// New variables for VBF topology
// *******************************************************************

int smallR_jets_n;
int largeR_jets_n;

// Two small jets j1 and j2 variables
float preselected_j12_m;
float preselected_j12_pt;
float preselected_j12_eta;
float preselected_j12_phi;
float preselected_j12_deta;
float preselected_j12_dphi;
float preselected_j12_dR;

// Boosted bb and boosted tautau variables
float preselected_bbtautau_system_m;
float preselected_bbtautau_system_pt;
float preselected_bbtautau_system_eta;
float preselected_bbtautau_system_phi;
float preselected_bbtautau_system_deta;
float preselected_bbtautau_system_dphi;
float preselected_bbtautau_system_dR;

// Boosted bb and small jets j1 variables
float preselected_bb_j1_system_m;
float preselected_bb_j1_system_pt;
float preselected_bb_j1_system_eta;
float preselected_bb_j1_system_phi;
float preselected_bb_j1_system_deta;
float preselected_bb_j1_system_dphi;
float preselected_bb_j1_system_dR;

// Boosted tautau and small jets j1 variables
float preselected_tautau_j1_system_m;
float preselected_tautau_j1_system_pt;
float preselected_tautau_j1_system_eta;
float preselected_tautau_j1_system_phi;
float preselected_tautau_j1_system_deta;
float preselected_tautau_j1_system_dphi;
float preselected_tautau_j1_system_dR;

// Boosted bb and small jets j2 variables
float preselected_bb_j2_system_m;
float preselected_bb_j2_system_pt;
float preselected_bb_j2_system_eta;
float preselected_bb_j2_system_phi;
float preselected_bb_j2_system_deta;
float preselected_bb_j2_system_dphi;
float preselected_bb_j2_system_dR;

// Boosted tautau and small jets j1 variables
float preselected_tautau_j2_system_m;
float preselected_tautau_j2_system_pt;
float preselected_tautau_j2_system_eta;
float preselected_tautau_j2_system_phi;
float preselected_tautau_j2_system_deta;
float preselected_tautau_j2_system_dphi;
float preselected_tautau_j2_system_dR;

// All jets system variables
float preselected_all_jets_system_m;
float preselected_all_jets_system_pt;
float preselected_all_jets_system_eta;
float preselected_all_jets_system_phi;
float preselected_all_jets_system_deta;
float preselected_all_jets_system_dphi;
float preselected_all_jets_system_dR;

// *************************************
// Declaration of branches
// *************************************

// Declaration of branches for boosted VBF tree
TBranch *b_recojet_antikt10UFO_ECF1___NOSYS;
TBranch *b_recojet_antikt10UFO_ECF2___NOSYS;
TBranch *b_recojet_antikt10UFO_ECF3___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2XTauV00_disc___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS;
TBranch *b_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS;
TBranch *b_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS;
TBranch *b_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS;
TBranch *b_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS;
TBranch *b_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS;
TBranch *b_recojet_antikt10UFO_Split12___NOSYS;
TBranch *b_recojet_antikt10UFO_Split23___NOSYS;
TBranch *b_recojet_antikt10UFO_Tau1_wta___NOSYS;
TBranch *b_recojet_antikt10UFO_Tau2_wta___NOSYS;
TBranch *b_recojet_antikt10UFO_Tau3_wta___NOSYS;
TBranch *b_recojet_antikt10UFO_eta___NOSYS;
TBranch *b_recojet_antikt10UFO_isAnalysisJet___NOSYS;
TBranch *b_recojet_antikt10UFO_isjet1___NOSYS;
TBranch *b_recojet_antikt10UFO_isjet2___NOSYS;
TBranch *b_recojet_antikt10UFO_m___NOSYS;
TBranch *b_recojet_antikt10UFO_phi___NOSYS;
TBranch *b_recojet_antikt10UFO_pt___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS;
TBranch *b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS;

// Small R-jets variables
TBranch *b_recojet_antikt4PFlow_m___NOSYS;
TBranch *b_recojet_antikt4PFlow_eta___NOSYS;
TBranch *b_recojet_antikt4PFlow_phi___NOSYS;
TBranch *b_recojet_antikt4PFlow_pt___NOSYS;
