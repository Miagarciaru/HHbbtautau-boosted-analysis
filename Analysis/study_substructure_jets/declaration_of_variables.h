#include "ratio_acceptances_reco_variables_histograms.h"
#include "ratio_acceptances_truth_variables_histograms.h"
#include "ratio_acceptances_preselected_events_variables_histograms.h"

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

string process_name = "";
string name_output_root_file = "";
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

// Declaration of leafs types for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
vector<float> *recojet_antikt10UFO_NOSYS_pt;
vector<float> *recojet_antikt10UFO_eta;
vector<float> *recojet_antikt10UFO_phi;
vector<float> *recojet_antikt10UFO_m;
vector<float> *recojet_antikt10UFO_Tau1_wta;
vector<float> *recojet_antikt10UFO_Tau2_wta;

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
bool passed_preselection;

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

// Declaration branches for reconstructed_ak10UFO jets (fat-jets) branches for boosted tree variables
TBranch *b_recojet_antikt10UFO_NOSYS_pt;
TBranch *b_recojet_antikt10UFO_eta;
TBranch *b_recojet_antikt10UFO_phi;
TBranch *b_recojet_antikt10UFO_m;
TBranch *b_recojet_antikt10UFO_Tau1_wta;
TBranch *b_recojet_antikt10UFO_Tau2_wta;

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
TBranch *b_passed_preselection;

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

// Declaration of distributions for recojets variables

// GN2X variables distributions

// pbhh GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_phbb = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_phbb", "GN2X phbb for boosted bb jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_phbb = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_phbb", "GN2X phbb for boosted tautau jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb", "GN2X phbb for jets with one b; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb", "GN2X phbb for jets with only one #tau; GN2X phbb Score;Events", 25, 0, 1);

// pqcd GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for boosted bb jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for boosted tautau jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for jets with one b; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for jets with only one #tau; GN2X pqcd Score;Events", 25, 0, 1);


// tau n_prong distribution histograms
TH1F *hist_matched_recojet_bb_tau_n_prong = new TH1F("hist_matched_recojet_bb_tau_n_prong", "Tau n prong for boosted bb jets; #tau n_prong;Events", 25, 0, 25);
TH1F *hist_matched_recojet_tautau_tau_n_prong = new TH1F("hist_matched_recojet_tautau_tau_n_prong", "Tau n prong for boosted #tau#tau jets; #tau n_prong;Events", 25, 0, 25);
TH1F *hist_non_matched_recojet_bb_tau_n_prong = new TH1F("hist_non_matched_recojet_bb_tau_n_prong", "Tau n prong for jets with one b; #tau n_prong;Events", 25, 0, 25);
TH1F *hist_non_matched_recojet_tautau_tau_n_prong = new TH1F("hist_non_matched_recojet_tautau_tau_n_prong", "Tau n prong for jets with one #tau; #tau n_prong;Events", 25, 0, 25);

// n_subjettines distribution histograms

//n1 subjettiness
TH1F *hist_matched_recojet_bb_tau_n1_subjettiness = new TH1F("hist_matched_recojet_bb_tau_n1_subjettiness", "Tau n1 subjettiness for boosted bb jets; #tau n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_recojet_tautau_tau_n1_subjettiness = new TH1F("hist_matched_recojet_tautau_tau_n1_subjettiness", "Tau n1 subjettiness for boosted #tau#tau jets; #tau n1_subjettiness;Events", 50, 0, 1);

TH1F *hist_non_matched_recojet_bb_tau_n1_subjettiness = new TH1F("hist_non_matched_recojet_bb_tau_n1_subjettiness", "Tau n1 subjettiness for jets with one b; #tau n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_tautau_tau_n1_subjettiness = new TH1F("hist_non_matched_recojet_tautau_tau_n1_subjettiness", "Tau n1 subjettiness for jets with one #tau; #tau n1_subjettiness;Events", 50, 0, 1);


//n2 subjettiness
TH1F *hist_matched_recojet_bb_tau_n2_subjettiness = new TH1F("hist_matched_recojet_bb_tau_n2_subjettiness", "Tau n2 subjettiness for boosted bb jets; #tau n2_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_recojet_tautau_tau_n2_subjettiness = new TH1F("hist_matched_recojet_tautau_tau_n2_subjettiness", "Tau n2 subjettiness for boosted #tau#tau jets; #tau n2_subjettiness;Events", 50, 0, 1);

TH1F *hist_non_matched_recojet_bb_tau_n2_subjettiness = new TH1F("hist_non_matched_recojet_bb_tau_n2_subjettiness", "Tau n2 subjettiness for jets with one b; #tau n2_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_tautau_tau_n2_subjettiness = new TH1F("hist_non_matched_recojet_tautau_tau_n2_subjettiness", "Tau n2 subjettiness for jets with one #tau; #tau n2_subjettiness;Events", 50, 0, 1);


//n2 over n1 subjettiness
TH1F *hist_matched_recojet_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_matched_recojet_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for boosted bb jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for boosted #tau#tau jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);

TH1F *hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for jets with one b; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for jets with one #tau; #tau n2/n1_subjettiness;Events", 50, 0, 1);


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

// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_phi = new TH1F("hist_matched_recojet_bb_phi", "#phi distribution of the recojets that are bb boosted jets; #phi_{j(bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_recojet_tautau_phi = new TH1F("hist_matched_recojet_tautau_phi", "#phi distribution of the recojets that are #tau#tau boosted jets; #phi_{j(#tau#tau)} [GeV];Events", 100, -5, 5);


// Histograms for the dRmin of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_dR = new TH1F("hist_matched_recojet_bb_dR", "dR distribution of the two truth b that were matched to the same fatjet; dR(bb) [GeV];Events", 50, -1, 3);
TH1F *hist_matched_recojet_tautau_dR = new TH1F("hist_matched_recojet_tautau_dR", "dR distribution of the two truth tau that were matched to the same fatjet; dR(#tau#tau) [GeV];Events", 50, -1, 3);


// Histograms for the mass of the fatjets with only one b and one tau jets
TH1F *hist_non_matched_recojet_bb_m = new TH1F("hist_non_matched_recojet_bb_m", "Mass distribution of the recojets that are not bb boosted jets; m(b) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_recojet_tautau_m = new TH1F("hist_non_matched_recojet_tautau_m", "Mass distribution of the recojets that are not #tau#tau boosted jets; m(#tau) [GeV];Events / 5 bins", 70, 0, 350);


// Histograms for the pT of the fatjets with only one b or one tau jets
TH1F *hist_non_matched_recojet_bb_pt = new TH1F("hist_non_matched_recojet_bb_pt", "pT distribution of the recojets that are not bb boosted jets; p_{T}(b) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_non_matched_recojet_tautau_pt = new TH1F("hist_non_matched_recojet_tautau_pt", "pT distribution of the recojets that are not #tau#tau boosted jets; p_{T}(#tau) [GeV];Events / 20 bins", 100, 0, 2000);


// Histograms for the eta of the fatjets with only one b or one tau jets
TH1F *hist_non_matched_recojet_bb_eta = new TH1F("hist_non_matched_recojet_bb_eta", "#eta distribution of the recojets that are not bb boosted jets; #eta_{j(b)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_tautau_eta = new TH1F("hist_non_matched_recojet_tautau_eta", "#eta distribution of the recojets that are not #tau#tau boosted jets; #eta_{j(#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the eta of the fatjets with only one b or one tau jets
TH1F *hist_non_matched_recojet_bb_phi = new TH1F("hist_non_matched_recojet_bb_phi", "#phi distribution of the recojets that are not bb boosted jets; #phi_{j(b)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_tautau_phi = new TH1F("hist_non_matched_recojet_tautau_phi", "#phi distribution of the recojets that are not #tau#tau boosted jets; #phi_{j(#tau)} [GeV];Events", 100, -5, 5);



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
