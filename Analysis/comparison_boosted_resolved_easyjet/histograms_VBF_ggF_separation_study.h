// **********************************************************************************************************************
// **********************************************************************************************************************
// ** Declaration of histograms
// **********************************************************************************************************************
// **********************************************************************************************************************

int n_bins_pT = 30;

// Declaration of histograms for boosted  VBF variables

TH1F *hist_boosted_tautau_pt_NOSYS = new TH1F("hist_boosted_tautau_pt_NOSYS", "p_{T}(#tau #tau) comparison between boosted and resolved configurations; p_{T}(H #rightarrow #tau#tau) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_tautau_m = new TH1F("hist_boosted_tautau_m", "Mass m_{#tau #tau} comparison between boosted and resolved configurations; m_{#tau#tau} [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_boosted_tautau_ECF1 = new TH1F("hist_boosted_tautau_ECF1", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_tautau_ECF2 = new TH1F("hist_boosted_tautau_ECF2", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_boosted_tautau_ECF3 = new TH1F("hist_boosted_tautau_ECF3", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_boosted_tautau_Split12 = new TH1F("hist_boosted_tautau_Split12", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_tautau_Split23 = new TH1F("hist_boosted_tautau_Split23", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_tautau_n1_nsubjettiness = new TH1F("hist_boosted_tautau_n1_nsubjettiness", "n1 nsubjettiness for boosted tautau jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n2_nsubjettiness = new TH1F("hist_boosted_tautau_n2_nsubjettiness", "n2 nsubjettiness for boosted tautau jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n3_nsubjettiness = new TH1F("hist_boosted_tautau_n3_nsubjettiness", "n3 nsubjettiness for boosted tautau jets; n_3 nsubjettiness;Events", 50, 0, 1);


TH1F *hist_boosted_bb_pt_NOSYS = new TH1F("hist_boosted_bb_pt_NOSYS", "p_{T}(bb) comparison between boosted and resolved configurations; p_{T}(H #rightarrow bb) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_bb_m = new TH1F("hist_boosted_bb_m", "Mass m_{bb} comparison between boosted and resolved configurations; m_{bb} [GeV];Events", n_bins_pT, 0, 350);
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

/// Topological variable histograms of VBF processes

TH1F *hist_boosted_jet12_m = new TH1F("hist_boosted_jet12_m", "Mass of the two jets j1 and j2; m(j_{1,2}) [GeV];Events", 30, 0, 2500);

TH1F *hist_boosted_jet12_pt = new TH1F("hist_boosted_jet12_pt", "pT of the two jets j1 and j2; p_{T}(j_{1,2}) [GeV];Events", 30, 0, 2000);

TH1F *hist_boosted_jet12_deta = new TH1F("hist_boosted_jet12_deta", "#Delta #eta of the two jets j1 and j2; #Delta #eta(j_{1},j_{2}) [GeV];Events", 30, 0, 10);

TH1F *hist_boosted_jet12_dphi = new TH1F("hist_boosted_jet12_phi", "#Delta #eta of the two jets j1 and j2; #Delta #phi(j_{1},j_{2}) [GeV];Events", 30, 0, 5);

TH1F *hist_boosted_jet12_dR = new TH1F("hist_boosted_jet12_dR", "#Delta #eta of the two jets j1 and j2; #Delta R(j_{1},j_{2}) [GeV];Events", 30, 0, 10);

TH1F *hist_boosted_jet12_Zeppenfeld_Hbb = new TH1F("hist_boosted_jet12_Zeppenfeld_Hbb", "Zeppenfeld Z_{Hbb}^{*} of the two jets j1 and j2; Z_{H #rightarrow bb}^{*};Events", 30, 0, 5);

TH1F *hist_boosted_jet12_Zeppenfeld_Htautau = new TH1F("hist_boosted_jet12_Zeppenfeld_Htautau", "Zeppenfeld Z_{Htautau}^{*} of the two jets j1 and j2; Z_{H #rightarrow #tau#tau}^{*};Events", 30, 0, 5);

TH1F *hist_boosted_jet12_Zeppenfeld_jet12 = new TH1F("hist_boosted_jet12_Zeppenfeld_jet12", "Zeppenfeld Z_{jet12}^{*} of the two jets j1 and j2; Z_{j_{12}}^{*};Events", 30, 0, 5);
