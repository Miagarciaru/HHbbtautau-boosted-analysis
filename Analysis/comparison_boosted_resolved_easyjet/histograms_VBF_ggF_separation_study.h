// **********************************************************************************************************************
// **********************************************************************************************************************
// ** Declaration of histograms
// **********************************************************************************************************************
// **********************************************************************************************************************

int n_bins_pT = 30;

// Declaration of histograms for boosted  VBF variables

TH1F *hist_boosted_tautau_pt_NOSYS_VBF = new TH1F("hist_boosted_tautau_pt_NOSYS_VBF", "p_{T}(#tau #tau) comparison between boosted and resolved configurations; p_{T}(H #rightarrow #tau#tau) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_tautau_m_VBF = new TH1F("hist_boosted_tautau_m_VBF", "Mass m_{#tau #tau} comparison between boosted and resolved configurations; m_{#tau#tau} [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_boosted_tautau_ECF1_VBF = new TH1F("hist_boosted_tautau_ECF1_VBF", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_tautau_ECF2_VBF = new TH1F("hist_boosted_tautau_ECF2_VBF", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_boosted_tautau_ECF3_VBF = new TH1F("hist_boosted_tautau_ECF3_VBF", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_boosted_tautau_Split12_VBF = new TH1F("hist_boosted_tautau_Split12_VBF", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_tautau_Split23_VBF = new TH1F("hist_boosted_tautau_Split23_VBF", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_tautau_n1_nsubjettiness_VBF = new TH1F("hist_boosted_tautau_n1_nsubjettiness_VBF", "n1 nsubjettiness for boosted tautau jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n2_nsubjettiness_VBF = new TH1F("hist_boosted_tautau_n2_nsubjettiness_VBF", "n2 nsubjettiness for boosted tautau jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n3_nsubjettiness_VBF = new TH1F("hist_boosted_tautau_n3_nsubjettiness_VBF", "n3 nsubjettiness for boosted tautau jets; n_3 nsubjettiness;Events", 50, 0, 1);


TH1F *hist_boosted_bb_pt_NOSYS_VBF = new TH1F("hist_boosted_bb_pt_NOSYS_VBF", "p_{T}(bb) comparison between boosted and resolved configurations; p_{T}(H #rightarrow bb) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_bb_m_VBF = new TH1F("hist_boosted_bb_m_VBF", "Mass m_{bb} comparison between boosted and resolved configurations; m_{bb} [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_boosted_bb_ECF1_VBF = new TH1F("hist_boosted_bb_ECF1_VBF", "ECF1 for boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_bb_ECF2_VBF = new TH1F("hist_boosted_bb_ECF2_VBF", "ECF2 for boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_boosted_bb_ECF3_VBF = new TH1F("hist_boosted_bb_ECF3_VBF", "ECF3 for boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_boosted_bb_Split12_VBF = new TH1F("hist_boosted_bb_Split12_VBF", "Split12 for boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_bb_Split23_VBF = new TH1F("hist_boosted_bb_Split23_VBF", "Split23 for boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_bb_n1_nsubjettiness_VBF = new TH1F("hist_boosted_bb_n1_nsubjettiness_VBF", "n1 nsubjettiness for boosted bb jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_n2_nsubjettiness_VBF = new TH1F("hist_boosted_bb_n2_nsubjettiness_VBF", "n2 nsubjettiness for boosted bb jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_n3_nsubjettiness_VBF = new TH1F("hist_boosted_bb_n3_nsubjettiness_VBF", "n3 nsubjettiness for boosted bb jets; n_3 nsubjettiness;Events", 50, 0, 1);


TH1F *hist_boosted_njets_VBF = new TH1F("hist_boosted_njets_VBF", "Number of small jets for VBF; small n jets;Events", 10, 0, 10);
TH1F *hist_boosted_bb_candidates_VBF = new TH1F("hist_boosted_bb_candidates_VBF", "Number of jets passing the phbb tagger for VBF; n jets;Events", 5, 0, 5);
TH1F *hist_boosted_tautau_candidates_VBF = new TH1F("hist_boosted_tautau_candidates_VBF", "Number of jets not passing the phbb tagger for VBF; n jets;Events", 5, 0, 5);
TH1F *hist_non_boosted_jets_m_VBF = new TH1F("hist_non_boosted_jets_m_VBF", "Mass of jets that are non boosted; m(jet) [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_non_boosted_jets_pt_NOSYS_VBF = new TH1F("hist_non_boosted_jets_pt_NOSYS_VBF", "p_{T} of jets that are non boosted; p_{T}(jet) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_non_boosted_jets_ECF1_VBF = new TH1F("hist_non_boosted_jets_ECF1_VBF", "ECF1 of jets that are non boosted; ECF1;Events", 50, 0, 700);
TH1F *hist_non_boosted_jets_ECF2_VBF = new TH1F("hist_non_boosted_jets_ECF2_VBF", "ECF2 of jets that are non boosted; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_boosted_jets_ECF3_VBF = new TH1F("hist_non_boosted_jets_ECF3_VBF", "ECF3 of jets that are non boosted; ECF3;Events", 50, 0, 10000);

// Declaration of histograms for ggF variables

TH1F *hist_boosted_tautau_pt_NOSYS_ggF = new TH1F("hist_boosted_tautau_pt_NOSYS_ggF", "p_{T}(#tau #tau) comparison between boosted and resolved configurations; p_{T}(H #rightarrow #tau#tau) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_tautau_m_ggF = new TH1F("hist_boosted_tautau_m_ggF", "Mass m_{#tau #tau} comparison between boosted and resolved configurations; m_{#tau #tau} [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_boosted_tautau_ECF1_ggF = new TH1F("hist_boosted_tautau_ECF1_ggF", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_tautau_ECF2_ggF = new TH1F("hist_boosted_tautau_ECF2_ggF", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_boosted_tautau_ECF3_ggF = new TH1F("hist_boosted_tautau_ECF3_ggF", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_boosted_tautau_Split12_ggF = new TH1F("hist_boosted_tautau_Split12_ggF", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_tautau_Split23_ggF = new TH1F("hist_boosted_tautau_Split23_ggF", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_tautau_n1_nsubjettiness_ggF = new TH1F("hist_boosted_tautau_n1_nsubjettiness_ggF", "n1 nsubjettiness for boosted tautau jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n2_nsubjettiness_ggF = new TH1F("hist_boosted_tautau_n2_nsubjettiness_ggF", "n2 nsubjettiness for boosted tautau jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_tautau_n3_nsubjettiness_ggF = new TH1F("hist_boosted_tautau_n3_nsubjettiness_ggF", "n3 nsubjettiness for boosted tautau jets; n_3 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_Split12_ggF = new TH1F("hist_boosted_bb_Split12_ggF", "Split12 for boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_boosted_bb_Split23_ggF = new TH1F("hist_boosted_bb_Split23_ggF", "Split23 for boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_boosted_bb_n1_nsubjettiness_ggF = new TH1F("hist_boosted_bb_n1_nsubjettiness_ggF", "n1 nsubjettiness for boosted bb jets; n_1 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_n2_nsubjettiness_ggF = new TH1F("hist_boosted_bb_n2_nsubjettiness_ggF", "n2 nsubjettiness for boosted bb jets; n_2 nsubjettiness;Events", 50, 0, 1);
TH1F *hist_boosted_bb_n3_nsubjettiness_ggF = new TH1F("hist_boosted_bb_n3_nsubjettiness_ggF", "n3 nsubjettiness for boosted bb jets; n_3 nsubjettiness;Events", 50, 0, 1);


TH1F *hist_boosted_bb_pt_NOSYS_ggF = new TH1F("hist_boosted_bb_pt_NOSYS_ggF", "p_{T}(bb) comparison between boosted and resolved configurations; p_{T}(H #rightarrow bb) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_boosted_bb_m_ggF = new TH1F("hist_boosted_bb_m_ggF", "Mass m_{bb} comparison between boosted and resolved configurations; m_{bb} [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_boosted_bb_ECF1_ggF = new TH1F("hist_boosted_bb_ECF1_ggF", "ECF1 for boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_boosted_bb_ECF2_ggF = new TH1F("hist_boosted_bb_ECF2_ggF", "ECF2 for boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_boosted_bb_ECF3_ggF = new TH1F("hist_boosted_bb_ECF3_ggF", "ECF3 for boosted bb jets; ECF3;Events", 50, 0, 10000);

TH1F *hist_boosted_njets_ggF = new TH1F("hist_boosted_njets_ggF", "Number of small jets for ggF; small n jets;Events", 10, 0, 10);
TH1F *hist_boosted_bb_candidates_ggF = new TH1F("hist_boosted_bb_candidates_ggF", "Number of jets passing the phbb tagger for ggF; n jets;Events", 5, 0, 5);
TH1F *hist_boosted_tautau_candidates_ggF = new TH1F("hist_boosted_tautau_candidates_ggF", "Number of jets not passing the phbb tagger for ggF; n jets;Events", 5, 0, 5);
TH1F *hist_non_boosted_jets_m_ggF = new TH1F("hist_non_boosted_jets_m_ggF", "Mass of jets that are non boosted; m(jet) [GeV];Events", n_bins_pT, 0, 350);
TH1F *hist_non_boosted_jets_pt_NOSYS_ggF = new TH1F("hist_non_boosted_jets_pt_NOSYS_ggF", "p_{T} of jets that are non boosted; p_{T}(jet) [GeV];Events", n_bins_pT, 0, 800);
TH1F *hist_non_boosted_jets_ECF1_ggF = new TH1F("hist_non_boosted_jets_ECF1_ggF", "ECF1 of jets that are non boosted; ECF1;Events", 50, 0, 700);
TH1F *hist_non_boosted_jets_ECF2_ggF = new TH1F("hist_non_boosted_jets_ECF2_ggF", "ECF2 of jets that are non boosted; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_boosted_jets_ECF3_ggF = new TH1F("hist_non_boosted_jets_ECF3_ggF", "ECF3 of jets that are non boosted; ECF3;Events", 50, 0, 10000);

/// Topological variable histograms of VBF processes

TH1F *hist_boosted_jet12_m_VBF = new TH1F("hist_boosted_jet12_m_VBF", "Mass of the two jets j1 and j2; m(j_{1,2}) [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_jet12_m_ggF = new TH1F("hist_boosted_jet12_m_ggF", "Mass of the two jets j1 and j2; m(j_{1,2}) [GeV];Events", 30, 0, 2500);

TH1F *hist_boosted_jet12_pt_VBF = new TH1F("hist_boosted_jet12_pt_VBF", "pT of the two jets j1 and j2; p_{T}(j_{1,2}) [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_jet12_pt_ggF = new TH1F("hist_boosted_jet12_pt_ggF", "pT of the two jets j1 and j2; p_{T}(j_{1,2}) [GeV];Events", 30, 0, 2000);

TH1F *hist_boosted_jet12_deta_VBF = new TH1F("hist_boosted_jet12_deta_VBF", "#Delta #eta of the two jets j1 and j2; #Delta #eta(j_{1},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_jet12_deta_ggF = new TH1F("hist_boosted_jet12_deta_ggF", "#Delta #eta of the two jets j1 and j2; #Delta #eta(j_{1},j_{2}) [GeV];Events", 30, 0, 10);

TH1F *hist_boosted_jet12_dphi_VBF = new TH1F("hist_boosted_jet12_phi_VBF", "#Delta #eta of the two jets j1 and j2; #Delta #phi(j_{1},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_jet12_dphi_ggF = new TH1F("hist_boosted_jet12_phi_ggF", "#Delta #eta of the two jets j1 and j2; #Delta #phi(j_{1},j_{2}) [GeV];Events", 30, 0, 5);

TH1F *hist_boosted_jet12_dR_VBF = new TH1F("hist_boosted_jet12_dR_VBF", "#Delta #eta of the two jets j1 and j2; #Delta R(j_{1},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_jet12_dR_ggF = new TH1F("hist_boosted_jet12_dR_ggF", "#Delta #eta of the two jets j1 and j2; #Delta R(j_{1},j_{2}) [GeV];Events", 30, 0, 10);

TH1F *hist_boosted_jet12_Zeppenfeld_Hbb_VBF = new TH1F("hist_boosted_jet12_Zeppenfeld_Hbb_VBF", "Zeppenfeld Z_{Hbb}^{*} of the two jets j1 and j2; Z_{H #rightarrow bb}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_jet12_Zeppenfeld_Hbb_ggF = new TH1F("hist_boosted_jet12_Zeppenfeld_Hbb_ggF", "Zeppenfeld Z_{Hbb}^{*} of the two jets j1 and j2; Z_{H #rightarrow bb}^{*};Events", 30, 0, 5);

TH1F *hist_boosted_jet12_Zeppenfeld_Htautau_VBF = new TH1F("hist_boosted_jet12_Zeppenfeld_Htautau_VBF", "Zeppenfeld Z_{Htautau}^{*} of the two jets j1 and j2; Z_{H #rightarrow #tau#tau}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_jet12_Zeppenfeld_Htautau_ggF = new TH1F("hist_boosted_jet12_Zeppenfeld_Htautau_ggF", "Zeppenfeld Z_{Htautau}^{*} of the two jets j1 and j2; Z_{H #rightarrow #tau#tau}^{*};Events", 30, 0, 5);

TH1F *hist_boosted_jet12_Zeppenfeld_jet12_VBF = new TH1F("hist_boosted_jet12_Zeppenfeld_jet12_VBF", "Zeppenfeld Z_{jet12}^{*} of the two jets j1 and j2; Z_{j_{12}}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_jet12_Zeppenfeld_jet12_ggF = new TH1F("hist_boosted_jet12_Zeppenfeld_jet12_ggF", "Zeppenfeld Z_{jet12}^{*} of the two jets j1 and j2; Z_{j_{12}}^{*};Events", 30, 0, 5);
