// *************************************
// Declaration of useful structures
// *************************************

struct PlotInfo {
  TH1F* hist_num;
  TH1F* hist_den;
  TString label;
  TString title;
};

// *************************************
// Declaration of global variables
// *************************************

TString process_name = "";
TString name_output_root_file = "";
float fraction = 1.0;

// values to be printed in the screen for statistical checks
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


// *************************************
// Declaration of x limits for histograms
// *************************************

float x_min_mHH = 200.0;
float x_max_mHH = 1000.0;

float x_min_ptHH = 200.0;
float x_max_ptHH = 1000.0;

float x_min_mHbb = 0.0;
float x_max_mHbb = 400.0;

float x_min_ptHbb = 0.0;
float x_max_ptHbb = 600.0;

float x_min_mHtautau = 0.0;
float x_max_mHtautau = 400.0;

float x_min_ptHtautau = 0.0;
float x_max_ptHtautau = 600.0;

float x_min_truth_mHH = 200.0;
float x_max_truth_mHH = 1000.0;
float x_min_truth_ptHH = 200.0;
float x_max_truth_ptHH = 1000.0;
float x_min_truth_etaHH = -5.0;
float x_max_truth_etaHH = 5.0;
float x_min_truth_phiHH = -5.0;
float x_max_truth_phiHH = 5.0;

float x_min_truth_mHbb = 0.0;
float x_max_truth_mHbb = 400.0;
float x_min_truth_ptHbb = 0.0;
float x_max_truth_ptHbb = 600.0;
float x_min_truth_etaHbb = -5.0;
float x_max_truth_etaHbb = 5.0;
float x_min_truth_phiHbb = -5.0;
float x_max_truth_phiHbb = 5.0;

float x_min_truth_mHtautau = 0.0;
float x_max_truth_mHtautau = 400.0;
float x_min_truth_ptHtautau = 0.0;
float x_max_truth_ptHtautau = 600.0;
float x_min_truth_etaHtautau = -5.0;
float x_max_truth_etaHtautau = 5.0;
float x_min_truth_phiHtautau = -5.0;
float x_max_truth_phiHtautau = 5.0;

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

// Declaration of leafs types for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
vector<float> *recojet_antikt10UFO_NOSYS_pt;
vector<float> *recojet_antikt10UFO_eta;
vector<float> *recojet_antikt10UFO_phi;
vector<float> *recojet_antikt10UFO_m;

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

int truth_boosted_bb;
int truth_boosted_tautau;
int truth_resolved_bb;
int truth_resolved_tautau;
int class_event;


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

// Declaration branches for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
TBranch *b_recojet_antikt10UFO_NOSYS_pt;
TBranch *b_recojet_antikt10UFO_eta;
TBranch *b_recojet_antikt10UFO_phi;
TBranch *b_recojet_antikt10UFO_m;

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
// Declaration of histograms
// *************************************

// Declaration of histograms for truth b-jets variables

TH1F *hist_truth_b1_m = new TH1F("hist_truth_b1_m", "Mass of the truth b1; m(b_1) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b2_m = new TH1F("hist_truth_b2_m", "Mass of the truth b2; m(b_2) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b1_plus_b2_m = new TH1F("hist_truth_b1_plus_b2_m", "Mass of the two truth b; m(b_1+b_2) [GeV];Events / 5 bins", 100, 0, 5000);

// Histograms for the mass of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_m = new TH1F("hist_matched_recojet_bb_m", "Mass distribution of the recojets that are bb boosted jets; m(bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_tautau_m = new TH1F("hist_matched_recojet_tautau_m", "Mass distribution of the recojets that are #tau#tau boosted jets; m(#tau#tau) [GeV];Events / 5 bins", 70, 0, 350);


// Histograms for the pT of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_pt = new TH1F("hist_matched_recojet_bb_pt", "pT distribution of the recojets that are bb boosted jets; pT(bb) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_matched_recojet_tautau_pt = new TH1F("hist_matched_recojet_tautau_pt", "pT distribution of the recojets that are #tau#tau boosted jets; pT(#tau#tau) [GeV];Events / 20 bins", 100, 0, 2000);


// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_eta = new TH1F("hist_matched_recojet_bb_eta", "#eta distribution of the recojets that are bb boosted jets; #eta_{j(bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_recojet_tautau_eta = new TH1F("hist_matched_recojet_tautau_eta", "#eta distribution of the recojets that are #tau#tau boosted jets; #eta_{j(#tau#tau)} [GeV];Events", 100, -5, 5);


// Histograms for the dRmin of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_dR = new TH1F("hist_matched_recojet_bb_dR", "dR distribution of the two truth b that were matched to the same fatjet; dR(bb) [GeV];Events", 50, -1, 3);
TH1F *hist_matched_recojet_tautau_dR = new TH1F("hist_matched_recojet_tautau_dR", "dR distribution of the two truth tau that were matched to the same fatjet; dR(#tau#tau) [GeV];Events", 50, -1, 3);


// Histograms for the pT distributions of the non matched recojets with class != -1
TH1F *hist_non_matched_recojet_pt = new TH1F("hist_non_matched_recojet_pt", "pT distribution of the recojets that were not matched to a truth object; pT_{j} [GeV];Events / 10 bins", 150, 0, 1500);

// Histograms for the eta distributions of the non matched recojets
TH1F *hist_non_matched_recojet_eta = new TH1F("hist_non_matched_recojet_eta", "#eta distribution of the recojets that were not matched to a truth object; #eta_{j} [GeV];Events", 100, -5, 5);



// Histograms for the pT distributions of the non matched recojets with class -1
TH1F *hist_non_matched_recojet_pt_no_class = new TH1F("hist_non_matched_recojet_pt_no_class", "pT distribution of the recojets that were not matched to a truth object (no class); pT_{j} [GeV];Events / 10 bins", 150, 0, 1500);

// Histograms for the eta distributions of the non matched recojets
TH1F *hist_non_matched_recojet_eta_no_class = new TH1F("hist_non_matched_recojet_eta_no_class", "#eta distribution of the recojets that were not matched to a truth object (no class); #eta_{j} [GeV];Events", 100, -5, 5);


// Histograms for the number of events per each class
TH1F *hist_nevents_per_class = new TH1F("hist_nevents_per_class", "Number of events per class; ;Events", 6, -1, 5);

// 2D histogram for the dR values per each class
TH2F *hist2d_dR_per_class_bb = new TH2F("hist2d_dR_per_class_bb", "dR values per each class for boosted bb jets; class; dR", 4, 0, 4, 50, 0, 5);
TH2F *hist2d_dR_per_class_tautau = new TH2F("hist2d_dR_per_class_tautau", "dR values per each class for boosted #tau#tau jets; class; dR", 4, 0, 4, 50, 0, 5);


// Histograms for comparison of distributions of pt
TH1F *hist_truth_HH_pt = new TH1F("hist_truth_HH_pt", "Truth HH pT distribution comparison; p_{T}(HH) [GeV];Events / 10 bins", 100, 0, 1000);
TH1F *hist_computed_HH_pt = new TH1F("hist_computed_HH_pt", "Truth HH pT distribution comparison; p_{T}(HH) [GeV];Events  / 10 bins", 100, 0, 1000);

// Histograms for comparison of distributions of masses
TH1F *hist_truth_HH_m = new TH1F("hist_truth_HH_m", "Truth HH mass distribution comparison; m(HH) [GeV];Events  / 10 bins", 300, 0, 3000);
TH1F *hist_computed_HH_m = new TH1F("hist_computed_HH_m", "Truth HH mass distribution comparison; m(HH) [GeV];Events  / 10 bins", 300, 0, 3000);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************
// Histograms for ratio_1 and ratio_2 for reco-level variables 
//******************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//******************************************************
// Histograms for mass of HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_mHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_mHH_numerator_class0_r1_r2", "Acceptance plot using the mass mHH variable (r_{1,2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_mHH_numerator_class1_r1_r2", "Acceptance plot using the mass mHH variable (r_{1,2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_mHH_numerator_class2_r1_r2", "Acceptance plot using the mass mHH variable (r_{1,2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_mHH_numerator_class3_r1_r2", "Acceptance plot using the mass mHH variable (r_{1,2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);

TH1F *hist_acceptance_mHH_denominator_r1 = new TH1F("hist_acceptance_mHH_denominator_r1", "Acceptance plot using the mass mHH variable; m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);

TH1F *hist_acceptance_mHH_denominator_class0_r2 = new TH1F("hist_acceptance_mHH_denominator_class0_r2", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_denominator_class1_r2 = new TH1F("hist_acceptance_mHH_denominator_class1_r2", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_denominator_class2_r2 = new TH1F("hist_acceptance_mHH_denominator_class2_r2", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_denominator_class3_r2 = new TH1F("hist_acceptance_mHH_denominator_class3_r2", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);

//******************************************************
// Histograms for pT of HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_ptHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_ptHH_numerator_class0_r1_r2", "Acceptance plot using the ptHH variable (r_{1,2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);
TH1F *hist_acceptance_ptHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_ptHH_numerator_class1_r1_r2", "Acceptance plot using the ptHH variable (r_{1,2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);
TH1F *hist_acceptance_ptHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_ptHH_numerator_class2_r1_r2", "Acceptance plot using the ptHH variable (r_{1,2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);
TH1F *hist_acceptance_ptHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_ptHH_numerator_class3_r1_r2", "Acceptance plot using the ptHH variable (r_{1,2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);

TH1F *hist_acceptance_ptHH_denominator_r1 = new TH1F("hist_acceptance_ptHH_denominator_r1", "Acceptance plot using the ptHH variable; p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);

TH1F *hist_acceptance_ptHH_denominator_class0_r2 = new TH1F("hist_acceptance_ptHH_denominator_class0_r2", "Acceptance plot using the ptHH variable (r_{2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);
TH1F *hist_acceptance_ptHH_denominator_class1_r2 = new TH1F("hist_acceptance_ptHH_denominator_class1_r2", "Acceptance plot using the ptHH variable (r_{2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);
TH1F *hist_acceptance_ptHH_denominator_class2_r2 = new TH1F("hist_acceptance_ptHH_denominator_class2_r2", "Acceptance plot using the ptHH variable (r_{2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);
TH1F *hist_acceptance_ptHH_denominator_class3_r2 = new TH1F("hist_acceptance_ptHH_denominator_class3_r2", "Acceptance plot using the ptHH variable (r_{2}); p_{T}(HH) [GeV];Ratio", 35, x_min_ptHH, x_max_ptHH);

//******************************************************
// Histograms for mass of H->bb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_mHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_mHbb_numerator_class0_r1_r2", "Acceptance plot using the mHbb variable (r_{1,2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);
TH1F *hist_acceptance_mHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_mHbb_numerator_class1_r1_r2", "Acceptance plot using the mHbb variable (r_{1,2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);
TH1F *hist_acceptance_mHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_mHbb_numerator_class2_r1_r2", "Acceptance plot using the mHbb variable (r_{1,2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);
TH1F *hist_acceptance_mHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_mHbb_numerator_class3_r1_r2", "Acceptance plot using the mHbb variable (r_{1,2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);

TH1F *hist_acceptance_mHbb_denominator_r1 = new TH1F("hist_acceptance_mHbb_denominator_r1", "Acceptance plot using the mHbb variable; m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);

TH1F *hist_acceptance_mHbb_denominator_class0_r2 = new TH1F("hist_acceptance_mHbb_denominator_class0_r2", "Acceptance plot using the mHbb variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);
TH1F *hist_acceptance_mHbb_denominator_class1_r2 = new TH1F("hist_acceptance_mHbb_denominator_class1_r2", "Acceptance plot using the mHbb variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);
TH1F *hist_acceptance_mHbb_denominator_class2_r2 = new TH1F("hist_acceptance_mHbb_denominator_class2_r2", "Acceptance plot using the mHbb variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);
TH1F *hist_acceptance_mHbb_denominator_class3_r2 = new TH1F("hist_acceptance_mHbb_denominator_class3_r2", "Acceptance plot using the mHbb variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio", 35, x_min_mHbb, x_max_mHbb);

//******************************************************
// Histograms for mass of H->tautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_mHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_mHtautau_numerator_class0_r1_r2", "Acceptance plot using the mHtautau variable (r_{1,2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);
TH1F *hist_acceptance_mHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_mHtautau_numerator_class1_r1_r2", "Acceptance plot using the mHtautau variable (r_{1,2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);
TH1F *hist_acceptance_mHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_mHtautau_numerator_class2_r1_r2", "Acceptance plot using the mHtautau variable (r_{1,2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);
TH1F *hist_acceptance_mHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_mHtautau_numerator_class3_r1_r2", "Acceptance plot using the mHtautau variable (r_{1,2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);

TH1F *hist_acceptance_mHtautau_denominator_r1 = new TH1F("hist_acceptance_mHtautau_denominator_r1", "Acceptance plot using the mHtautau variable; m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);

TH1F *hist_acceptance_mHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_mHtautau_denominator_class0_r2", "Acceptance plot using the mHtautau variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);
TH1F *hist_acceptance_mHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_mHtautau_denominator_class1_r2", "Acceptance plot using the mHtautau variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);
TH1F *hist_acceptance_mHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_mHtautau_denominator_class2_r2", "Acceptance plot using the mHtautau variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);
TH1F *hist_acceptance_mHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_mHtautau_denominator_class3_r2", "Acceptance plot using the mHtautau variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_mHtautau, x_max_mHtautau);

//******************************************************
// Histograms for pT of H->bb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_ptHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_ptHbb_numerator_class0_r1_r2", "Acceptance plot using the ptHbb variable (r_{1,2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_ptHbb_numerator_class1_r1_r2", "Acceptance plot using the ptHbb variable (r_{1,2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_ptHbb_numerator_class2_r1_r2", "Acceptance plot using the ptHbb variable (r_{1,2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_ptHbb_numerator_class3_r1_r2", "Acceptance plot using the ptHbb variable (r_{1,2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);

TH1F *hist_acceptance_ptHbb_denominator_r1 = new TH1F("hist_acceptance_ptHbb_denominator_r1", "Acceptance plot using the ptHbb variable; p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);

TH1F *hist_acceptance_ptHbb_denominator_class0_r2 = new TH1F("hist_acceptance_ptHbb_denominator_class0_r2", "Acceptance plot using the ptHbb variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_denominator_class1_r2 = new TH1F("hist_acceptance_ptHbb_denominator_class1_r2", "Acceptance plot using the ptHbb variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_denominator_class2_r2 = new TH1F("hist_acceptance_ptHbb_denominator_class2_r2", "Acceptance plot using the ptHbb variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_denominator_class3_r2 = new TH1F("hist_acceptance_ptHbb_denominator_class3_r2", "Acceptance plot using the ptHbb variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);

//******************************************************
// Histograms for pT of H->tautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_ptHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_ptHtautau_numerator_class0_r1_r2", "Acceptance plot using the ptHtautau variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_ptHtautau_numerator_class1_r1_r2", "Acceptance plot using the ptHtautau variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_ptHtautau_numerator_class2_r1_r2", "Acceptance plot using the ptHtautau variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_ptHtautau_numerator_class3_r1_r2", "Acceptance plot using the ptHtautau variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

TH1F *hist_acceptance_ptHtautau_denominator_r1 = new TH1F("hist_acceptance_ptHtautau_denominator_r1", "Acceptance plot using the ptHtautau variable; p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

TH1F *hist_acceptance_ptHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_ptHtautau_denominator_class0_r2", "Acceptance plot using the ptHtautau variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_ptHtautau_denominator_class1_r2", "Acceptance plot using the ptHtautau variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_ptHtautau_denominator_class2_r2", "Acceptance plot using the ptHtautau variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_ptHtautau_denominator_class3_r2", "Acceptance plot using the ptHtautau variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************
// Histograms for ratio_1 and ratio_2 for truth-level variables 
//******************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//******************************************************
// Histograms for mass of truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_mHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_mHH_numerator_class0_r1_r2", "Acceptance plot using the truth_mHH variable (r_{1,2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_mHH_numerator_class1_r1_r2", "Acceptance plot using the truth_mHH variable (r_{1,2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_mHH_numerator_class2_r1_r2", "Acceptance plot using the truth_mHH variable (r_{1,2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_mHH_numerator_class3_r1_r2", "Acceptance plot using the truth_mHH variable (r_{1,2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);

TH1F *hist_acceptance_truth_mHH_denominator_r1 = new TH1F("hist_acceptance_truth_mHH_denominator_r1", "Acceptance plot using the truth_mHH variable; Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);

TH1F *hist_acceptance_truth_mHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_mHH_denominator_class0_r2", "Acceptance plot using the truth_mHH variable (r_{2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_mHH_denominator_class1_r2", "Acceptance plot using the truth_mHH variable (r_{2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_mHH_denominator_class2_r2", "Acceptance plot using the truth_mHH variable (r_{2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_mHH_denominator_class3_r2", "Acceptance plot using the truth_mHH variable (r_{2}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);

//******************************************************
// Histograms for pT of truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_ptHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class0_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class1_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class2_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class3_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

TH1F *hist_acceptance_truth_ptHH_denominator_r1 = new TH1F("hist_acceptance_truth_ptHH_denominator_r1", "Acceptance plot using the truth_ptHH variable; truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

TH1F *hist_acceptance_truth_ptHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class0_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class1_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class2_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class3_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); truth_pt(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

//******************************************************
// Histograms for eta of truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_etaHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class0_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class1_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class2_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class3_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

TH1F *hist_acceptance_truth_etaHH_denominator_r1 = new TH1F("hist_acceptance_truth_etaHH_denominator_r1", "Acceptance plot using the truth_etaHH variable; truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

TH1F *hist_acceptance_truth_etaHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class0_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class1_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class2_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class3_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

//******************************************************
// Histograms for phi of truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_phiHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class0_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class1_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class2_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class3_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

TH1F *hist_acceptance_truth_phiHH_denominator_r1 = new TH1F("hist_acceptance_truth_phiHH_denominator_r1", "Acceptance plot using the truth_phiHH variable; truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

TH1F *hist_acceptance_truth_phiHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class0_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class1_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class2_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class3_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

//******************************************************
// Histograms for mass of truth bb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_mHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_truth_mHbb_denominator_r1 = new TH1F("hist_acceptance_truth_mHbb_denominator_r1", "Acceptance plot using the truth_mHbb variable; truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_truth_mHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class0_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class1_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class2_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class3_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

//******************************************************
// Histograms for pT of truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_ptHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_ptHbb variable (r_{1,2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_ptHbb variable (r_{1,2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_ptHbb variable (r_{1,2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_ptHbb variable (r_{1,2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

TH1F *hist_acceptance_truth_ptHbb_denominator_r1 = new TH1F("hist_acceptance_truth_ptHbb_denominator_r1", "Acceptance plot using the truth_ptHbb variable; Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

TH1F *hist_acceptance_truth_ptHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_ptHbb_denominator_class0_r2", "Acceptance plot using the truth_ptHbb variable (r_{2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_ptHbb_denominator_class1_r2", "Acceptance plot using the truth_ptHbb variable (r_{2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_ptHbb_denominator_class2_r2", "Acceptance plot using the truth_ptHbb variable (r_{2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_ptHbb_denominator_class3_r2", "Acceptance plot using the truth_ptHbb variable (r_{2}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

//******************************************************
// Histograms for eta of truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_etaHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

TH1F *hist_acceptance_truth_etaHbb_denominator_r1 = new TH1F("hist_acceptance_truth_etaHbb_denominator_r1", "Acceptance plot using the truth_etaHbb variable; truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

TH1F *hist_acceptance_truth_etaHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class0_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class1_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class2_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class3_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

//******************************************************
// Histograms for phi of truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_phiHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

TH1F *hist_acceptance_truth_phiHbb_denominator_r1 = new TH1F("hist_acceptance_truth_phiHbb_denominator_r1", "Acceptance plot using the truth_phiHbb variable; truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

TH1F *hist_acceptance_truth_phiHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class0_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class1_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class2_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class3_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

//******************************************************
// Histograms for mass of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_mHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_truth_mHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_mHtautau_denominator_r1", "Acceptance plot using the truth_mHtautau variable; truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_truth_mHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class0_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class1_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class2_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class3_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); truth_m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

//******************************************************
// Histograms for pT of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_ptHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_ptHtautau variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_ptHtautau variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_ptHtautau variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_ptHtautau variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_truth_ptHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_r1", "Acceptance plot using the truth_ptHtautau variable; Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_truth_ptHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_class0_r2", "Acceptance plot using the truth_ptHtautau variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_class1_r2", "Acceptance plot using the truth_ptHtautau variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_class2_r2", "Acceptance plot using the truth_ptHtautau variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_class3_r2", "Acceptance plot using the truth_ptHtautau variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

//******************************************************
// Histograms for eta of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_etaHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

TH1F *hist_acceptance_truth_etaHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_r1", "Acceptance plot using the truth_etaHtautau variable; truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

TH1F *hist_acceptance_truth_etaHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class0_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class2_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class3_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); truth_eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

//******************************************************
// Histograms for phi of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_phiHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

TH1F *hist_acceptance_truth_phiHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_r1", "Acceptance plot using the truth_phiHtautau variable; truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

TH1F *hist_acceptance_truth_phiHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class0_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class2_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class3_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); truth_phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************
// Histograms for ratio_3 and ratio_4 for reco-level variables 
//******************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//******************************************************                                                                                     
// Histograms for mass of HH cuts ratio_3 and ratio_4                                                                                   
//******************************************************

TH1F *hist_acceptance_mHH_numerator_r3 = new TH1F("hist_acceptance_mHH_numerator_r3", "Acceptance plot using the mHH variable (r_{3}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);

TH1F *hist_acceptance_mHH_denominator_r3_r4 = new TH1F("hist_acceptance_mHH_denominator_r3_r4", "Acceptance plot using the mHH variable (r_{3,4}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);

TH1F *hist_acceptance_mHH_numerator_class0_r4 = new TH1F("hist_acceptance_mHH_numerator_class0_r4", "Acceptance plot using the mHH variable (r_{4}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_numerator_class1_r4 = new TH1F("hist_acceptance_mHH_numerator_class1_r4", "Acceptance plot using the mHH variable (r_{4}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_numerator_class2_r4 = new TH1F("hist_acceptance_mHH_numerator_class2_r4", "Acceptance plot using the mHH variable (r_{4}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);
TH1F *hist_acceptance_mHH_numerator_class3_r4 = new TH1F("hist_acceptance_mHH_numerator_class3_r4", "Acceptance plot using the mHH variable (r_{4}); m(HH) [GeV];Ratio", 35, x_min_mHH, x_max_mHH);

//******************************************************                                                                                     
// Histograms for pT of Hbb cuts ratio_3 and ratio_4                                                                                    
//******************************************************                                                                                      
TH1F *hist_acceptance_ptHbb_numerator_r3 = new TH1F("hist_acceptance_ptHbb_numerator_r3", "Acceptance plot using the ptHbb variable (r_{3}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);

TH1F *hist_acceptance_ptHbb_denominator_r3_r4 = new TH1F("hist_acceptance_ptHbb_denominator_r3_r4", "Acceptance plot using the ptHbb variable (r_{3,4}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class0_r4 = new TH1F("hist_acceptance_ptHbb_numerator_class0_r4", "Acceptance plot using the ptHbb variable (r_{4}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class1_r4 = new TH1F("hist_acceptance_ptHbb_numerator_class1_r4", "Acceptance plot using the ptHbb variable (r_{4}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class2_r4 = new TH1F("hist_acceptance_ptHbb_numerator_class2_r4", "Acceptance plot using the ptHbb variable (r_{4}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);
TH1F *hist_acceptance_ptHbb_numerator_class3_r4 = new TH1F("hist_acceptance_ptHbb_numerator_class3_r4", "Acceptance plot using the ptHbb variable (r_{4}); p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_ptHbb, x_max_ptHbb);

//******************************************************                                                                                     
// Histograms for pT of Htautau cuts ratio_3 and ratio_4                                                                                
//******************************************************                                                                                     

TH1F *hist_acceptance_ptHtautau_numerator_r3 = new TH1F("hist_acceptance_ptHtautau_numerator_r3", "Acceptance plot using the ptHtautau variable (r_{3}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

TH1F *hist_acceptance_ptHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_ptHtautau_denominator_r3_r4", "Acceptance plot using the ptHtautau variable (r_{3,4}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

TH1F *hist_acceptance_ptHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_ptHtautau_numerator_class0_r4", "Acceptance plot using the ptHtautau variable (r_{4}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_ptHtautau_numerator_class1_r4", "Acceptance plot using the ptHtautau variable (r_{4}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_ptHtautau_numerator_class2_r4", "Acceptance plot using the ptHtautau variable (r_{4}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);
TH1F *hist_acceptance_ptHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_ptHtautau_numerator_class3_r4", "Acceptance plot using the ptHtautau variable (r_{4}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************
// Histograms for ratio_3 and ratio_4 for truth-level variables 
//******************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//******************************************************
// Histograms for mass of truth HH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_mHH_numerator_r3 = new TH1F("hist_acceptance_truth_mHH_numerator_r3", "Acceptance plot using the truth mHH variable (r_{3}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);

TH1F *hist_acceptance_truth_mHH_denominator_r3_r4 = new TH1F("hist_acceptance_truth_mHH_denominator_r3_r4", "Acceptance plot using the truth mHH variable (r_{3,4}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);

TH1F *hist_acceptance_truth_mHH_numerator_class0_r4 = new TH1F("hist_acceptance_truth_mHH_numerator_class0_r4", "Acceptance plot using the truth mHH variable (r_{4}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_numerator_class1_r4 = new TH1F("hist_acceptance_truth_mHH_numerator_class1_r4", "Acceptance plot using the truth mHH variable (r_{4}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_numerator_class2_r4 = new TH1F("hist_acceptance_truth_mHH_numerator_class2_r4", "Acceptance plot using the truth mHH variable (r_{4}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);
TH1F *hist_acceptance_truth_mHH_numerator_class3_r4 = new TH1F("hist_acceptance_truth_mHH_numerator_class3_r4", "Acceptance plot using the truth mHH variable (r_{4}); Truth m(HH) [GeV];Ratio", 35, x_min_truth_mHH, x_max_truth_mHH);

//******************************************************
// Histograms for pT of truth Hbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_ptHbb_numerator_r3 = new TH1F("hist_acceptance_truth_ptHbb_numerator_r3", "Acceptance plot using the truth ptHbb variable (r_{3}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

TH1F *hist_acceptance_truth_ptHbb_denominator_r3_r4 = new TH1F("hist_acceptance_truth_ptHbb_denominator_r3_r4", "Acceptance plot using the truth ptHbb variable (r_{3,4}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

TH1F *hist_acceptance_truth_ptHbb_numerator_class0_r4 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class0_r4", "Acceptance plot using the truth ptHbb variable (r_{4}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_numerator_class1_r4 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class1_r4", "Acceptance plot using the truth ptHbb variable (r_{4}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_numerator_class2_r4 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class2_r4", "Acceptance plot using the truth ptHbb variable (r_{4}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);
TH1F *hist_acceptance_truth_ptHbb_numerator_class3_r4 = new TH1F("hist_acceptance_truth_ptHbb_numerator_class3_r4", "Acceptance plot using the truth ptHbb variable (r_{4}); Truth p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

//******************************************************
// Histograms for pT of truth Htautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_ptHtautau_numerator_r3 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_r3", "Acceptance plot using the truth ptHtautau variable (r_{3}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_truth_ptHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_r3_r4", "Acceptance plot using the truth ptHtautau variable (r_{3,4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_truth_ptHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class0_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class1_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class2_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class3_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);


// Initialize the map with plot information
std::unordered_map<std::string, PlotInfo> plotMap = {
  // mHH histograms
  {"class0_r1_mHH", {hist_acceptance_mHH_numerator_class0_r1_r2, hist_acceptance_mHH_denominator_r1, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio"}},
  {"class1_r1_mHH", {hist_acceptance_mHH_numerator_class1_r1_r2, hist_acceptance_mHH_denominator_r1, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio"}},
  {"class2_r1_mHH", {hist_acceptance_mHH_numerator_class2_r1_r2, hist_acceptance_mHH_denominator_r1, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio"}},
  {"class3_r1_mHH", {hist_acceptance_mHH_numerator_class3_r1_r2, hist_acceptance_mHH_denominator_r1, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio"}},
  {"class0_r2_mHH", {hist_acceptance_mHH_numerator_class0_r1_r2, hist_acceptance_mHH_denominator_class0_r2, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio"}},
  {"class1_r2_mHH", {hist_acceptance_mHH_numerator_class1_r1_r2, hist_acceptance_mHH_denominator_class1_r2, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio"}},
  {"class2_r2_mHH", {hist_acceptance_mHH_numerator_class2_r1_r2, hist_acceptance_mHH_denominator_class2_r2, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio"}},
  {"class3_r2_mHH", {hist_acceptance_mHH_numerator_class3_r1_r2, hist_acceptance_mHH_denominator_class3_r2, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio"}},
  // ptHH histograms
  {"class0_r1_ptHH", {hist_acceptance_ptHH_numerator_class0_r1_r2, hist_acceptance_ptHH_denominator_r1, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{1}); p_{T}(HH) [GeV];Ratio"}},
  {"class1_r1_ptHH", {hist_acceptance_ptHH_numerator_class1_r1_r2, hist_acceptance_ptHH_denominator_r1, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{1}); p_{T}(HH) [GeV];Ratio"}},
  {"class2_r1_ptHH", {hist_acceptance_ptHH_numerator_class2_r1_r2, hist_acceptance_ptHH_denominator_r1, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{1}); p_{T}(HH) [GeV];Ratio"}},
  {"class3_r1_ptHH", {hist_acceptance_ptHH_numerator_class3_r1_r2, hist_acceptance_ptHH_denominator_r1, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{1}); p_{T}(HH) [GeV];Ratio"}},
  {"class0_r2_ptHH", {hist_acceptance_ptHH_numerator_class0_r1_r2, hist_acceptance_ptHH_denominator_class0_r2, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{2}); p_{T}(HH) [GeV];Ratio"}},
  {"class1_r2_ptHH", {hist_acceptance_ptHH_numerator_class1_r1_r2, hist_acceptance_ptHH_denominator_class1_r2, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{2}); p_{T}(HH) [GeV];Ratio"}},
  {"class2_r2_ptHH", {hist_acceptance_ptHH_numerator_class2_r1_r2, hist_acceptance_ptHH_denominator_class2_r2, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{2}); p_{T}(HH) [GeV];Ratio"}},
  {"class3_r2_ptHH", {hist_acceptance_ptHH_numerator_class3_r1_r2, hist_acceptance_ptHH_denominator_class3_r2, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(HH) variable (r_{2}); p_{T}(HH) [GeV];Ratio"}},
  // mHbb histograms
  {"class0_r1_mHbb", {hist_acceptance_mHbb_numerator_class0_r1_r2, hist_acceptance_mHbb_denominator_r1, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{1}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class1_r1_mHbb", {hist_acceptance_mHbb_numerator_class1_r1_r2, hist_acceptance_mHbb_denominator_r1, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{1}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class2_r1_mHbb", {hist_acceptance_mHbb_numerator_class2_r1_r2, hist_acceptance_mHbb_denominator_r1, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{1}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class3_r1_mHbb", {hist_acceptance_mHbb_numerator_class3_r1_r2, hist_acceptance_mHbb_denominator_r1, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{1}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class0_r2_mHbb", {hist_acceptance_mHbb_numerator_class0_r1_r2, hist_acceptance_mHbb_denominator_class0_r2, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class1_r2_mHbb", {hist_acceptance_mHbb_numerator_class1_r1_r2, hist_acceptance_mHbb_denominator_class1_r2, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class2_r2_mHbb", {hist_acceptance_mHbb_numerator_class2_r1_r2, hist_acceptance_mHbb_denominator_class2_r2, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio"}},
  {"class3_r2_mHbb", {hist_acceptance_mHbb_numerator_class3_r1_r2, hist_acceptance_mHbb_denominator_class3_r2, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow bb) variable (r_{2}); m(H #rightarrow bb) [GeV];Ratio"}},
  // mHtautau histograms
  {"class0_r1_mHtautau", {hist_acceptance_mHtautau_numerator_class0_r1_r2, hist_acceptance_mHtautau_denominator_r1, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{1}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class1_r1_mHtautau", {hist_acceptance_mHtautau_numerator_class1_r1_r2, hist_acceptance_mHtautau_denominator_r1, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{1}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class2_r1_mHtautau", {hist_acceptance_mHtautau_numerator_class2_r1_r2, hist_acceptance_mHtautau_denominator_r1, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{1}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class3_r1_mHtautau", {hist_acceptance_mHtautau_numerator_class3_r1_r2, hist_acceptance_mHtautau_denominator_r1, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{1}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class0_r2_mHtautau", {hist_acceptance_mHtautau_numerator_class0_r1_r2, hist_acceptance_mHtautau_denominator_class0_r2, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class1_r2_mHtautau", {hist_acceptance_mHtautau_numerator_class1_r1_r2, hist_acceptance_mHtautau_denominator_class1_r2, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class2_r2_mHtautau", {hist_acceptance_mHtautau_numerator_class2_r1_r2, hist_acceptance_mHtautau_denominator_class2_r2, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class3_r2_mHtautau", {hist_acceptance_mHtautau_numerator_class3_r1_r2, hist_acceptance_mHtautau_denominator_class3_r2, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the m(H #rightarrow #tau#tau) variable (r_{2}); m(H #rightarrow #tau#tau) [GeV];Ratio"}},
  // ptHbb histograms
  {"class0_r1_ptHbb", {hist_acceptance_ptHbb_numerator_class0_r1_r2, hist_acceptance_ptHbb_denominator_r1, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{1}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class1_r1_ptHbb", {hist_acceptance_ptHbb_numerator_class1_r1_r2, hist_acceptance_ptHbb_denominator_r1, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{1}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class2_r1_ptHbb", {hist_acceptance_ptHbb_numerator_class2_r1_r2, hist_acceptance_ptHbb_denominator_r1, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{1}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class3_r1_ptHbb", {hist_acceptance_ptHbb_numerator_class3_r1_r2, hist_acceptance_ptHbb_denominator_r1, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{1}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class0_r2_ptHbb", {hist_acceptance_ptHbb_numerator_class0_r1_r2, hist_acceptance_ptHbb_denominator_class0_r2, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class1_r2_ptHbb", {hist_acceptance_ptHbb_numerator_class1_r1_r2, hist_acceptance_ptHbb_denominator_class1_r2, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class2_r2_ptHbb", {hist_acceptance_ptHbb_numerator_class2_r1_r2, hist_acceptance_ptHbb_denominator_class2_r2, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  {"class3_r2_ptHbb", {hist_acceptance_ptHbb_numerator_class3_r1_r2, hist_acceptance_ptHbb_denominator_class3_r2, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow bb) variable (r_{2}); p_{T}(H #rightarrow bb) [GeV];Ratio"}},
  // ptHtautau histograms
  {"class0_r1_ptHtautau", {hist_acceptance_ptHtautau_numerator_class0_r1_r2, hist_acceptance_ptHtautau_denominator_r1, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class1_r1_ptHtautau", {hist_acceptance_ptHtautau_numerator_class1_r1_r2, hist_acceptance_ptHtautau_denominator_r1, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class2_r1_ptHtautau", {hist_acceptance_ptHtautau_numerator_class2_r1_r2, hist_acceptance_ptHtautau_denominator_r1, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class3_r1_ptHtautau", {hist_acceptance_ptHtautau_numerator_class3_r1_r2, hist_acceptance_ptHtautau_denominator_r1, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{1}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class0_r2_ptHtautau", {hist_acceptance_ptHtautau_numerator_class0_r1_r2, hist_acceptance_ptHtautau_denominator_class0_r2, "R_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class1_r2_ptHtautau", {hist_acceptance_ptHtautau_numerator_class1_r1_r2, hist_acceptance_ptHtautau_denominator_class1_r2, "R_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class2_r2_ptHtautau", {hist_acceptance_ptHtautau_numerator_class2_r1_r2, hist_acceptance_ptHtautau_denominator_class2_r2, "B_{bb}-R_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}},
  {"class3_r2_ptHtautau", {hist_acceptance_ptHtautau_numerator_class3_r1_r2, hist_acceptance_ptHtautau_denominator_class3_r2, "B_{bb}-B_{#tau#tau}", "Acceptance plot using the p_{T}(H #rightarrow #tau#tau) variable (r_{2}); p_{T}(H #rightarrow #tau#tau) [GeV];Ratio"}}
};
