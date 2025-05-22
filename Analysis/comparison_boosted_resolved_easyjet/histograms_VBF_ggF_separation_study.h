// **********************************************************************************************************************
// **********************************************************************************************************************
// ** Declaration of histograms
// **********************************************************************************************************************
// **********************************************************************************************************************

int n_bins_pT = 30;

// Declaration of histograms for boosted  VBF variables

TH1F *hist_boosted_tautau_pt_NOSYS = new TH1F("hist_boosted_tautau_pt_NOSYS", "p_{T}(#tau #tau) comparison between boosted and resolved configurations; p_{T}(H #rightarrow #tau#tau) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_tautau_m = new TH1F("hist_boosted_tautau_m", "Mass m_{#tau #tau} comparison between boosted and resolved configurations; m(H #rightarrow #tau#tau) [GeV];Events", n_bins_pT, 0, 250);
TH1F *hist_boosted_tautau_ECF1 = new TH1F("hist_boosted_tautau_ECF1", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_tautau_ECF2 = new TH1F("hist_boosted_tautau_ECF2", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_boosted_tautau_ECF3 = new TH1F("hist_boosted_tautau_ECF3", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_boosted_tautau_Split12 = new TH1F("hist_boosted_tautau_Split12", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_tautau_Split23 = new TH1F("hist_boosted_tautau_Split23", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_tautau_n1_nsubjettiness = new TH1F("hist_boosted_tautau_n1_nsubjettiness", "n1 nsubjettiness for boosted tautau jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n2_nsubjettiness = new TH1F("hist_boosted_tautau_n2_nsubjettiness", "n2 nsubjettiness for boosted tautau jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n3_nsubjettiness = new TH1F("hist_boosted_tautau_n3_nsubjettiness", "n3 nsubjettiness for boosted tautau jets; n_3 nsubjettiness;Events", 50, 0, 1);


TH1F *hist_boosted_bb_pt_NOSYS = new TH1F("hist_boosted_bb_pt_NOSYS", "p_{T}(bb) comparison between boosted and resolved configurations; p_{T}(H #rightarrow bb) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_bb_m = new TH1F("hist_boosted_bb_m", "Mass m_{bb} comparison between boosted and resolved configurations; m(H #rightarrow bb) [GeV];Events", n_bins_pT, 0, 250);
TH1F *hist_boosted_bb_ECF1 = new TH1F("hist_boosted_bb_ECF1", "ECF1 for boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_bb_ECF2 = new TH1F("hist_boosted_bb_ECF2", "ECF2 for boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_boosted_bb_ECF3 = new TH1F("hist_boosted_bb_ECF3", "ECF3 for boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_boosted_bb_Split12 = new TH1F("hist_boosted_bb_Split12", "Split12 for boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_bb_Split23 = new TH1F("hist_boosted_bb_Split23", "Split23 for boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_bb_n1_nsubjettiness = new TH1F("hist_boosted_bb_n1_nsubjettiness", "n1 nsubjettiness for boosted bb jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_n2_nsubjettiness = new TH1F("hist_boosted_bb_n2_nsubjettiness", "n2 nsubjettiness for boosted bb jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_n3_nsubjettiness = new TH1F("hist_boosted_bb_n3_nsubjettiness", "n3 nsubjettiness for boosted bb jets; n_3 nsubjettiness;Events", 50, 0, 1);


TH1F *hist_boosted_njets = new TH1F("hist_boosted_njets", "Number of small jets for VBF; small n jets;Events", 10, 0, 10);
TH1F *hist_boosted_bb_candidates = new TH1F("hist_boosted_bb_candidates", "Number of jets passing the phbb tagger for VBF; n jets;Events", 5, 0, 5);
TH1F *hist_boosted_tautau_candidates = new TH1F("hist_boosted_tautau_candidates", "Number of jets not passing the phbb tagger for VBF; n jets;Events", 5, 0, 5);
TH1F *hist_non_boosted_jets_m = new TH1F("hist_non_boosted_jets_m", "Mass of jets that are non boosted; m(jet) [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_non_boosted_jets_pt_NOSYS = new TH1F("hist_non_boosted_jets_pt_NOSYS", "p_{T} of jets that are non boosted; p_{T}(jet) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_non_boosted_jets_ECF1 = new TH1F("hist_non_boosted_jets_ECF1", "ECF1 of jets that are non boosted; ECF1;Events", 50, 0, 700);
TH1F *hist_non_boosted_jets_ECF2 = new TH1F("hist_non_boosted_jets_ECF2", "ECF2 of jets that are non boosted; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_boosted_jets_ECF3 = new TH1F("hist_non_boosted_jets_ECF3", "ECF3 of jets that are non boosted; ECF3;Events", 50, 0, 10000);

//***************************************************************************************************************
// Topological variable histograms of VBF processes
//***************************************************************************************************************

// Two small jets j1 and j2 histograms
TH1F *hist_boosted_jet12_m = new TH1F("hist_boosted_jet12_m", "Mass of the two jets j1 and j2; m_{j_{1},j_{2}}^{system} [GeV];Events", 30, 0, 4000);
TH1F *hist_boosted_jet12_pt = new TH1F("hist_boosted_jet12_pt", "pT of the two jets j1 and j2; p_{T}_{j_{1,2}}^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_jet12_eta = new TH1F("hist_boosted_jet12_eta", "#eta of the two jets j1 and j2; #eta (j_{1},j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_jet12_phi = new TH1F("hist_boosted_jet12_phi", "#eta of the two jets j1 and j2; #phi (j_{1},j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_jet12_deta = new TH1F("hist_boosted_jet12_deta", "#Delta #eta of the two jets j1 and j2; #Delta #eta(j_{1},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_jet12_dphi = new TH1F("hist_boosted_jet12_dphi", "#Delta #eta of the two jets j1 and j2; #Delta #phi(j_{1},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_jet12_dR = new TH1F("hist_boosted_jet12_dR", "#Delta #eta of the two jets j1 and j2; #Delta R(j_{1},j_{2}) [GeV];Events", 30, 0, 10);

// Boosted bb and tautau system histograms
TH1F *hist_boosted_bbtautau_m = new TH1F("hist_boosted_bbtautau_m", "Mass of the boosted bb#tau#tau jets system; m_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 3000);
TH1F *hist_boosted_bbtautau_pt = new TH1F("hist_boosted_bbtautau_pt", "pT of boosted bb#tau#tau jets system; p_{T}_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_bbtautau_eta = new TH1F("hist_boosted_bbtautau_eta", "#eta of the boosted bb#tau#tau jets system; #eta_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_bbtautau_phi = new TH1F("hist_boosted_bbtautau_phi", "#eta of the boosted bb#tau#tau jets system; #phi_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_bbtautau_deta = new TH1F("hist_boosted_bbtautau_deta", "#Delta #eta of the boosted bb and #tau#tau; #Delta #eta(h_{1}, h_{2}) [GeV];Events", 30, 0, 4);
TH1F *hist_boosted_bbtautau_dphi = new TH1F("hist_boosted_bbtautau_dphi", "#Delta #eta of the boosted bb and #tau#tau; #Delta #phi(h_{1}, h_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_bbtautau_dR = new TH1F("hist_boosted_bbtautau_dR", "#Delta #eta of the boosted bb and #tau#tau; #Delta R(h_{1}, h_{2}) [GeV];Events", 30, 0, 5);

// Boosted bb and jet1 histograms
TH1F *hist_boosted_bb_jet1_m = new TH1F("hist_boosted_bb_jet1_m", "Mass of the boosted bb and j1 system; m_(H_{bb}, j_{1})^{system} [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_bb_jet1_pt = new TH1F("hist_boosted_bb_jet1_pt", "pT of boosted bb and j1 system; p_{T}(h_{1}, j_{1})^{system} [GeV];Events", 30, 0, 1800);
TH1F *hist_boosted_bb_jet1_eta = new TH1F("hist_boosted_bb_jet1_eta", "#eta of the boosted bb and j1 system; #eta_(H_{bb}, j_{1})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_bb_jet1_phi = new TH1F("hist_boosted_bb_jet1_phi", "#eta of the boosted bb and j1 system; #phi_(H_{bb}, j_{1})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_bb_jet1_deta = new TH1F("hist_boosted_bb_jet1_deta", "#Delta #eta of the boosted bb and j1; #Delta #eta(H_{bb},j_{1}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_bb_jet1_dphi = new TH1F("hist_boosted_bb_jet1_dphi", "#Delta #eta of the boosted bb and j1; #Delta #phi(H_{bb},j_{1}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_bb_jet1_dR = new TH1F("hist_boosted_bb_jet1_dR", "#Delta #eta of the boosted bb and j1; #Delta R(H_{bb},j_{1}) [GeV];Events", 30, 0, 10);

// Boosted bb and jet2 histograms
TH1F *hist_boosted_bb_jet2_m = new TH1F("hist_boosted_bb_jet2_m", "Mass of the boosted bb and j2 system; m_(h_{1}, j_{2})^{system} [GeV];Events", 30, 0, 3000);
TH1F *hist_boosted_bb_jet2_pt = new TH1F("hist_boosted_bb_jet2_pt", "pT of boosted bb and j2 system; p_{T}_(h_{1}, j_{2})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_bb_jet2_eta = new TH1F("hist_boosted_bb_jet2_eta", "#eta of the boosted bb and j2 system; #eta_(H_{bb}, j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_bb_jet2_phi = new TH1F("hist_boosted_bb_jet2_phi", "#eta of the boosted bb and j2 system; #phi_(h_{1}, j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_bb_jet2_deta = new TH1F("hist_boosted_bb_jet2_deta", "#Delta #eta of the boosted bb and j2; #Delta #eta(h_{1},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_bb_jet2_dphi = new TH1F("hist_boosted_bb_jet2_dphi", "#Delta #eta of the boosted bb and j2; #Delta #phi(h_{1},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_bb_jet2_dR = new TH1F("hist_boosted_bb_jet2_dR", "#Delta #eta of the boosted bb and j2; #Delta R(h_{1},j_{2}) [GeV];Events", 30, 0, 8);

// Boosted tautau and jet1 histograms
TH1F *hist_boosted_tautau_jet1_m = new TH1F("hist_boosted_tautau_jet1_m", "Mass of the boosted #tau#tau and j1 system; m_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_tautau_jet1_pt = new TH1F("hist_boosted_tautau_jet1_pt", "pT of boosted #tau#tau and j1 system; p_{T}_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_tautau_jet1_eta = new TH1F("hist_boosted_tautau_jet1_eta", "#eta of the boosted #tau#tau and j1 system; #eta_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_tautau_jet1_phi = new TH1F("hist_boosted_tautau_jet1_phi", "#eta of the boosted #tau#tau and j1 system; #phi_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_tautau_jet1_deta = new TH1F("hist_boosted_tautau_jet1_deta", "#Delta #eta of the boosted #tau#tau and j1; #Delta #eta(h_{2},j_{1}) [GeV];Events", 30, 0, 8);
TH1F *hist_boosted_tautau_jet1_dphi = new TH1F("hist_boosted_tautau_jet1_dphi", "#Delta #eta of the boosted #tau#tau and j1; #Delta #phi(h_{2},j_{1}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_tautau_jet1_dR = new TH1F("hist_boosted_tautau_jet1_dR", "#Delta #eta of the boosted #tau#tau and j1; #Delta R(h_{2},j_{1}) [GeV];Events", 30, 0, 10);

// Boosted tautau and jet2 histograms
TH1F *hist_boosted_tautau_jet2_m = new TH1F("hist_boosted_tautau_jet2_m", "Mass of the boosted #tau#tau and j2 system; m_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_tautau_jet2_pt = new TH1F("hist_boosted_tautau_jet2_pt", "pT of boosted #tau#tau and j2 system; p_{T}_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_tautau_jet2_eta = new TH1F("hist_boosted_tautau_jet2_eta", "#eta of the boosted #tau#tau and j2 system; #eta_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_tautau_jet2_phi = new TH1F("hist_boosted_tautau_jet2_phi", "#eta of the boosted #tau#tau and j2 system; #phi_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_tautau_jet2_deta = new TH1F("hist_boosted_tautau_jet2_deta", "#Delta #eta of the boosted #tau#tau and j2; #Delta #eta(h_{2},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_tautau_jet2_dphi = new TH1F("hist_boosted_tautau_jet2_dphi", "#Delta #eta of the boosted #tau#tau and j2; #Delta #phi(h_{2},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_tautau_jet2_dR = new TH1F("hist_boosted_tautau_jet2_dR", "#Delta #eta of the boosted #tau#tau and j2; #Delta R(h_{2},j_{2}) [GeV];Events", 30, 0, 10);

// All jets system variables
TH1F *hist_boosted_all_jets_m = new TH1F("hist_boosted_all_jets_m", "Mass of the boosted jets system; m_{(h_{1}, h_{2}, j_{1}, j_{2})}^{system} [GeV];Events", 30, 500, 6000);
TH1F *hist_boosted_all_jets_pt = new TH1F("hist_boosted_all_jets_pt", "pT of boosted jets system; p_{T}_(h_{1}, h_{2}, j_{1}, j_{2})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_all_jets_eta = new TH1F("hist_boosted_all_jets_eta", "#eta of the boosted jets system; #eta_(h_{1}, h_{2}, j_{1}, j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_all_jets_phi = new TH1F("hist_boosted_all_jets_phi", "#eta of the boosted jets system; #phi_(h_{1}, h_{2}, j_{1}, j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_all_jets_deta = new TH1F("hist_boosted_all_jets_deta", "#Delta #eta of the boosted bb#tau#tau and j12; #Delta #eta(h_{1}, h_{2},j_{1}j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_all_jets_dphi = new TH1F("hist_boosted_all_jets_dphi", "#Delta #eta of the boosted bb#tau#tau and j12; #Delta #phi(h_{1}, h_{2},j_{1}j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_all_jets_dR = new TH1F("hist_boosted_all_jets_dR", "#Delta #eta of the boosted bb#tau#tau and j12; #Delta R(H_{bb#tau#tau},j_{12}) [GeV];Events", 30, 0, 10);

// Zeppenfeld variables
TH1F *hist_boosted_jet12_Zeppenfeld_Hbb = new TH1F("hist_boosted_jet12_Zeppenfeld_Hbb", "Zeppenfeld Z_{Hbb}^{*} of the two jets j1 and j2; Z_{H #rightarrow bb}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_jet12_Zeppenfeld_Htautau = new TH1F("hist_boosted_jet12_Zeppenfeld_Htautau", "Zeppenfeld Z_{Htautau}^{*} of the two jets j1 and j2; Z_{H #rightarrow #tau#tau}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_jet12_Zeppenfeld_jet12 = new TH1F("hist_boosted_jet12_Zeppenfeld_jet12", "Zeppenfeld Z_{jet12}^{*} of the two jets j1 and j2; Z_{j_{12}}^{*};Events", 30, 0, 5);
