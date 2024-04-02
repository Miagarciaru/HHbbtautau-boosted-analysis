// *************************************
// Reading the input files
// *************************************

// Path of the input samples                                                                                                               

//TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/outputfiles-easyjet-march21-2024/mc20_13TeV_502985_vbf_hadhad_l1cvv1 \
p5cv1_PHYS_merged_";

TString path="../run/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_";
TString path_sample=path+"boosted_bypass_config.root";

// Open the input files and access to the trees                                                                                             

TFile* inFile = TFile::Open(path_sample);
TTree* inTree = (TTree*) inFile->Get("AnalysisMiniTree");

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

// Declaration of leafs types for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
vector<float> *recojet_antikt10UFO_NOSYS_pt;
vector<float> *recojet_antikt10UFO_eta;
vector<float> *recojet_antikt10UFO_phi;
vector<float> *recojet_antikt10UFO_m;


// Declaration of leaf types for bbtt_H boosted tree variables
Float_t bbtt_H_vis_tautau_pt_NOSYS;
Float_t bbtt_H_vis_tautau_m;
Float_t bbtt_H_bb_pt_NOSYS;
Float_t bbtt_H_bb_m;
Float_t bbtt_Jet_b1_pt_NOSYS;
Float_t bbtt_Jet_b2_pt_NOSYS;
Float_t generatorWeight_NOSYS;
//vector<char> *tau_NOSYS_passesOR;
vector<char> *recojet_antikt4PFlow_NOSYS_passesOR;

// Declaration idx and dRmin values

Int_t idx_b1truth_recoak10_dRmin;
Int_t idx_b2truth_recoak10_dRmin;
Int_t idx_tau1truth_recoak10_dRmin;
Int_t idx_tau2truth_recoak10_dRmin;

Float_t dR_min_b1truth_recoak10_fatjet;
Float_t dR_min_b2truth_recoak10_fatjet;
Float_t dR_min_tau1truth_recoak10_fatjet;
Float_t dR_min_tau2truth_recoak10_fatjet;

int truth_boosted_bb;
int truth_boosted_tautau;
int truth_resolved_bb;
int truth_resolved_tautau;
int class_event;

// *************************************
// Declaration of branches
// *************************************


// truth childre from Higgs
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

// Declaration branches for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
TBranch *b_recojet_antikt10UFO_NOSYS_pt;
TBranch *b_recojet_antikt10UFO_eta;
TBranch *b_recojet_antikt10UFO_phi;
TBranch *b_recojet_antikt10UFO_m;

// Declaration of branches for boosted tree
TBranch *b_bbtt_H_vis_tautau_pt_NOSYS;
TBranch *b_bbtt_H_vis_tautau_m;
TBranch *b_bbtt_H_bb_pt_NOSYS;
TBranch *b_bbtt_H_bb_m;
TBranch *b_bbtt_Jet_b1_pt_NOSYS;
TBranch *b_bbtt_Jet_b2_pt_NOSYS;
TBranch *b_generatorWeight_NOSYS;
//TBranch *b_tau_NOSYS_passesOR;
TBranch *b_recojet_antikt4PFlow_NOSYS_passesOR;

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


// *************************************
// Declaration of histograms
// *************************************

// Declaration of histograms for truth b-jets variables

TH1F *hist_truth_b1_m = new TH1F("hist_truth_b1_m", "Mass of the truth b1; m(b_1) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b2_m = new TH1F("hist_truth_b2_m", "Mass of the truth b2; m(b_2) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b1_plus_b2_m = new TH1F("hist_truth_b1_plus_b2_m", "Mass of the two truth b; m(b_1+b_2) [GeV];Events / 5 bins", 100, 0, 5000);

// Histograms for the mass of the chosen fatjets for bb and tautau jets
TH1F *hist_recojet_bb_m = new TH1F("hist_recojet_bb_m", "Mass of the recojets that were matched to the truth bb; m(bb) [GeV];Events / 10 bins", 100, 10, 1010);
TH1F *hist_recojet_tautau_m = new TH1F("hist_recojet_tautau_m", "Mass of the recojets that were matched to the truth tau-tau; m(#tau #tau) [GeV];Events / 10 bins", 100, 10, 1010);
