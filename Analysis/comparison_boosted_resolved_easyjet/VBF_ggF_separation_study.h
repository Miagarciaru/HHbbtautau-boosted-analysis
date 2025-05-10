// *************************************                                                                                      
// Reading the input files                                                                                                    
// *************************************                                                                                      

// Path of the merged samples                                                                                                 

TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples_May_2025/";
TString path_VBF_sample=path+"mc20_13TeV_502982_vbf_hadhad_l1cvv1cv1_PHYS_merged_boosted_bypass_config.root";
TString path_ggF_sample=path+"mc20_13TeV_600459_ggf_hadhad_cHHH01d0_PHYS_merged_boosted_bypass_config.root";

// Open the input files and access to the trees                                                                               

TFile* VBF_inFile = TFile::Open(path_VBF_sample);
TTree* VBF_inTree = (TTree*) VBF_inFile->Get("AnalysisMiniTree");

TFile* ggF_inFile = TFile::Open(path_ggF_sample);
TTree* ggF_inTree = (TTree*) ggF_inFile->Get("AnalysisMiniTree");

// *************************************
// Candidates for boosted jets
// *************************************

// VBF
int idx_boosted_bb_VBF;
int idx_boosted_tautau_VBF;
bool is_boosted_bb_VBF;
bool is_boosted_tautau_VBF;
bool is_boosted_bbtautau_VBF;
int idx_jet1_VBF;
int idx_jet2_VBF;
bool is_jet12_matched_VBF;

int count_bb_candidates_VBF;
int count_tautau_candidates_VBF;

// ggF
int idx_boosted_bb_ggF;
int idx_boosted_tautau_ggF;
bool is_boosted_bb_ggF;
bool is_boosted_tautau_ggF;
bool is_boosted_bbtautau_ggF;
int idx_jet1_ggF;
int idx_jet2_ggF;
bool is_jet12_matched_ggF;

int count_bb_candidates_ggF;
int count_tautau_candidates_ggF;

// *************************************
// Declaration of leaf variables
// *************************************

// Declaration of leaf types for truth_children branches for boosted tree variables

// Declaration of leaf types for boosted VBF tree variables

// Large R-jets variables
vector<float> *VBF_recojet_antikt10UFO_ECF1___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_ECF2___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_ECF3___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_Split12___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_Split23___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_Tau1_wta___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_Tau2_wta___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_Tau3_wta___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_eta___NOSYS;
vector<char> *VBF_recojet_antikt10UFO_isAnalysisJet___NOSYS;
vector<char> *VBF_recojet_antikt10UFO_isjet1___NOSYS;
vector<char> *VBF_recojet_antikt10UFO_isjet2___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_m___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_phi___NOSYS;
vector<float> *VBF_recojet_antikt10UFO_pt___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS;
vector<int> *VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS;

// Small R-jets variables
vector<float> *VBF_recojet_antikt4PFlow_m___NOSYS;
vector<float> *VBF_recojet_antikt4PFlow_eta___NOSYS;
vector<float> *VBF_recojet_antikt4PFlow_phi___NOSYS;
vector<float> *VBF_recojet_antikt4PFlow_pt___NOSYS;

// Leafs for ggF variables

vector<float> *ggF_recojet_antikt10UFO_ECF1___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_ECF2___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_ECF3___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_Split12___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_Split23___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_Tau1_wta___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_Tau2_wta___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_Tau3_wta___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_eta___NOSYS;
vector<char> *ggF_recojet_antikt10UFO_isAnalysisJet___NOSYS;
vector<char> *ggF_recojet_antikt10UFO_isjet1___NOSYS;
vector<char> *ggF_recojet_antikt10UFO_isjet2___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_m___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_phi___NOSYS;
vector<float> *ggF_recojet_antikt10UFO_pt___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS;
vector<int> *ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS;

// Small R-jets variables
vector<float> *ggF_recojet_antikt4PFlow_m___NOSYS;
vector<float> *ggF_recojet_antikt4PFlow_eta___NOSYS;
vector<float> *ggF_recojet_antikt4PFlow_phi___NOSYS;
vector<float> *ggF_recojet_antikt4PFlow_pt___NOSYS;

// New variables to develop
float two_jets_j12_m_VBF;
float two_jets_j12_m_ggF;

float two_jets_j12_pt_VBF;
float two_jets_j12_pt_ggF;

float two_jets_j12_eta_VBF;
float two_jets_j12_eta_ggF;

float two_jets_j12_phi_VBF;
float two_jets_j12_phi_ggF;

float two_jets_j12_deta_VBF;
float two_jets_j12_deta_ggF;

float two_jets_j12_dphi_VBF;
float two_jets_j12_dphi_ggF;

float two_jets_j12_dR_VBF;
float two_jets_j12_dR_ggF;

// *************************************
// Declaration of branches
// *************************************

// Declaration of branches for boosted VBF tree
TBranch *b_VBF_recojet_antikt10UFO_ECF1___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_ECF2___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_ECF3___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_Split12___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_Split23___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_Tau1_wta___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_Tau2_wta___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_Tau3_wta___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_eta___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_isAnalysisJet___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_isjet1___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_isjet2___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_m___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_phi___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_pt___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS;
TBranch *b_VBF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS;

// Small R-jets variables
TBranch *b_VBF_recojet_antikt4PFlow_m___NOSYS;
TBranch *b_VBF_recojet_antikt4PFlow_eta___NOSYS;
TBranch *b_VBF_recojet_antikt4PFlow_phi___NOSYS;
TBranch *b_VBF_recojet_antikt4PFlow_pt___NOSYS;

// Declaration of branches for boosted ggF tree
TBranch *b_ggF_recojet_antikt10UFO_ECF1___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_ECF2___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_ECF3___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_Split12___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_Split23___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_Tau1_wta___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_Tau2_wta___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_Tau3_wta___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_eta___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_isAnalysisJet___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_isjet1___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_isjet2___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_m___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_phi___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_pt___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS;
TBranch *b_ggF_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS;

// Small R-jets variables
TBranch *b_ggF_recojet_antikt4PFlow_m___NOSYS;
TBranch *b_ggF_recojet_antikt4PFlow_eta___NOSYS;
TBranch *b_ggF_recojet_antikt4PFlow_phi___NOSYS;
TBranch *b_ggF_recojet_antikt4PFlow_pt___NOSYS;
