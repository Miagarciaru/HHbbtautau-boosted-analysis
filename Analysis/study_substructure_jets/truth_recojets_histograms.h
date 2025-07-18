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

TH1F *hist_taggedHbb_recojet_bb_per_event = new TH1F("hist_taggedHbb_recojet_bb_per_event", "Number of tagged boosted bb jets per event; Number of boosted bb; Events", 10, 0, 10);

// pqcd GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for boosted bb jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for boosted tautau jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for jets with one b; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for jets with only one #tau; GN2X pqcd Score;Events", 25, 0, 1);

// phcc GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_phcc = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_phcc", "GN2X phcc for boosted bb jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_phcc = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_phcc", "GN2X phcc for boosted tautau jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_phcc = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_phcc", "GN2X phcc for jets with one b; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_phcc = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_phcc", "GN2X phcc for jets with only one #tau; GN2X phcc Score;Events", 25, 0, 1);

// ptop GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_ptop = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_ptop", "GN2X ptop for boosted bb jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_ptop = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_ptop", "GN2X ptop for boosted tautau jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_ptop = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_ptop", "GN2X ptop for jets with one b; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_ptop = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_ptop", "GN2X ptop for jets with only one #tau; GN2X ptop Score;Events", 25, 0, 1);

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

//n3 subjettiness
TH1F *hist_matched_recojet_bb_tau_n3_subjettiness = new TH1F("hist_matched_recojet_bb_tau_n3_subjettiness", "Tau n3 subjettiness for boosted bb jets; #tau n3_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_recojet_tautau_tau_n3_subjettiness = new TH1F("hist_matched_recojet_tautau_tau_n3_subjettiness", "Tau n3 subjettiness for boosted #tau#tau jets; #tau n3_subjettiness;Events", 50, 0, 1);

TH1F *hist_non_matched_recojet_bb_tau_n3_subjettiness = new TH1F("hist_non_matched_recojet_bb_tau_n3_subjettiness", "Tau n3 subjettiness for jets with one b; #tau n3_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_tautau_tau_n3_subjettiness = new TH1F("hist_non_matched_recojet_tautau_tau_n3_subjettiness", "Tau n3 subjettiness for jets with one #tau; #tau n3_subjettiness;Events", 50, 0, 1);

//n2 over n1 subjettiness
TH1F *hist_matched_recojet_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_matched_recojet_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for boosted bb jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for boosted #tau#tau jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);

TH1F *hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for jets with one b; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for jets with one #tau; #tau n2/n1_subjettiness;Events", 50, 0, 1);

TH1F *hist_candidates_preselected_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_candidates_preselected_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for possible candidates for preselected boosted #tau#tau jets; #tau n2/n1_subjettiness; Events", 50, 0, 1);

// Declaration of histograms for truth b-jets variables

TH1F *hist_truth_b1_m = new TH1F("hist_truth_b1_m", "Mass of the truth b1; m(b_1) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b2_m = new TH1F("hist_truth_b2_m", "Mass of the truth b2; m(b_2) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b1_plus_b2_m = new TH1F("hist_truth_b1_plus_b2_m", "Mass of the two truth b; m(b_1+b_2) [GeV];Events / 5 bins", 100, 0, 5000);

// Histograms for the mass of the chosen fatjets for bb and tautau recojets
TH1F *hist_matched_recojet_bb_m = new TH1F("hist_matched_recojet_bb_m", "Mass distribution of the recojets that are bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_bb_m_only_Hbb_tagger = new TH1F("hist_matched_recojet_bb_m_only_Hbb_tagger", "Mass distribution of the recojets that are bb boosted jets (only tagger); m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_bb_m_only_nsubjettiness = new TH1F("hist_matched_recojet_bb_m_only_nsubjettiness", "Mass distribution of the recojets that are bb boosted jets (only nsubjettiness); m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_bb_m_until_nsubjettiness = new TH1F("hist_matched_recojet_bb_m_until_nsubjettiness", "Mass distribution of the recojets that are bb boosted jets (tagger and nsubjettiness); m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);

TH1F *hist_matched_recojet_tautau_m = new TH1F("hist_matched_recojet_tautau_m", "Mass distribution of the recojets that are #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_tautau_m_only_Hbb_tagger = new TH1F("hist_matched_recojet_tautau_m_only_Hbb_tagger", "Mass distribution of the recojets that are #tau#tau boosted jets (only tagger); m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);

TH1F *hist_matched_recojet_tautau_m_only_nsubjettiness = new TH1F("hist_matched_recojet_tautau_m_only_nsubjettiness", "Mass distribution of the recojets that are #tau#tau boosted jets (only nsubjettiness); m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_tautau_m_until_nsubjettiness = new TH1F("hist_matched_recojet_tautau_m_until_nsubjettiness", "Mass distribution of the recojets that are #tau#tau boosted jets (tagger and nsubjettiness); m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);

TH1F *hist_non_matched_recojet_bb_m = new TH1F("hist_non_matched_recojet_bb_m", "Mass distribution of the recojets that are not bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_recojet_tautau_m = new TH1F("hist_non_matched_recojet_tautau_m", "Mass distribution of the recojets that are not #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);

// Histograms for the pT of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_pt = new TH1F("hist_matched_recojet_bb_pt", "pT distribution of the recojets that are bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_matched_recojet_tautau_pt = new TH1F("hist_matched_recojet_tautau_pt", "pT distribution of the recojets that are #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 1000);

TH1F *hist_non_matched_recojet_bb_pt = new TH1F("hist_non_matched_recojet_bb_pt", "pT distribution of the recojets that are not bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_non_matched_recojet_tautau_pt = new TH1F("hist_non_matched_recojet_tautau_pt", "pT distribution of the recojets that are not #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 1000);

// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_eta = new TH1F("hist_matched_recojet_bb_eta", "#eta distribution of the recojets that are bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_recojet_tautau_eta = new TH1F("hist_matched_recojet_tautau_eta", "#eta distribution of the recojets that are #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

TH1F *hist_non_matched_recojet_bb_eta = new TH1F("hist_non_matched_recojet_bb_eta", "#eta distribution of the recojets that are not bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_tautau_eta = new TH1F("hist_non_matched_recojet_tautau_eta", "#eta distribution of the recojets that are not #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_phi = new TH1F("hist_matched_recojet_bb_phi", "#phi distribution of the recojets that are bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_recojet_tautau_phi = new TH1F("hist_matched_recojet_tautau_phi", "#phi distribution of the recojets that are #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

TH1F *hist_non_matched_recojet_bb_phi = new TH1F("hist_non_matched_recojet_bb_phi", "#phi distribution of the recojets that are not bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_tautau_phi = new TH1F("hist_non_matched_recojet_tautau_phi", "#phi distribution of the recojets that are not #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the ECF1 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_ECF1 = new TH1F("hist_matched_recojet_bb_ak10_ECF1", "ECF1 for boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_recojet_bb_ak10_ECF1 = new TH1F("hist_non_matched_recojet_bb_ak10_ECF1", "ECF1 for non boosted bb jets; ECF1;Events", 50, 0, 700);

TH1F *hist_matched_recojet_tautau_ak10_ECF1 = new TH1F("hist_matched_recojet_tautau_ak10_ECF1", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_recojet_tautau_ak10_ECF1 = new TH1F("hist_non_matched_recojet_tautau_ak10_ECF1", "ECF1 for non boosted tautau jets; ECF1;Events", 50, 0, 700);

// Histograms for the ECF2 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_ECF2 = new TH1F("hist_matched_recojet_bb_ak10_ECF2", "ECF2 for boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_matched_recojet_bb_ak10_ECF2 = new TH1F("hist_non_matched_recojet_bb_ak10_ECF2", "ECF2 for non boosted bb jets; ECF2;Events", 50, 0, 5000);

TH1F *hist_matched_recojet_tautau_ak10_ECF2 = new TH1F("hist_matched_recojet_tautau_ak10_ECF2", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_non_matched_recojet_tautau_ak10_ECF2 = new TH1F("hist_non_matched_recojet_tautau_ak10_ECF2", "ECF2 for non boosted tautau jets; ECF2;Events", 50, 0, 3000);

// Histograms for the ECF3 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_ECF3 = new TH1F("hist_matched_recojet_bb_ak10_ECF3", "ECF3 for boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_non_matched_recojet_bb_ak10_ECF3 = new TH1F("hist_non_matched_recojet_bb_ak10_ECF3", "ECF3 for non boosted bb jets; ECF3;Events", 50, 0, 10000);

TH1F *hist_matched_recojet_tautau_ak10_ECF3 = new TH1F("hist_matched_recojet_tautau_ak10_ECF3", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_non_matched_recojet_tautau_ak10_ECF3 = new TH1F("hist_non_matched_recojet_tautau_ak10_ECF3", "ECF3 for non boosted tautau jets; ECF3;Events", 50, 0, 80);

// Histograms for the Split12 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_Split12 = new TH1F("hist_matched_recojet_bb_ak10_Split12", "Split12 for boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_recojet_bb_ak10_Split12 = new TH1F("hist_non_matched_recojet_bb_ak10_Split12", "Split12 for non boosted bb jets; Split12;Events", 50, 0, 150);

TH1F *hist_matched_recojet_tautau_ak10_Split12 = new TH1F("hist_matched_recojet_tautau_ak10_Split12", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_recojet_tautau_ak10_Split12 = new TH1F("hist_non_matched_recojet_tautau_ak10_Split12", "Split12 for non boosted tautau jets; Split12;Events", 50, 0, 150);

// Histograms for the Split23 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_Split23 = new TH1F("hist_matched_recojet_bb_ak10_Split23", "Split23 for boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_recojet_bb_ak10_Split23 = new TH1F("hist_non_matched_recojet_bb_ak10_Split23", "Split23 for non boosted bb jets; Split23;Events", 50, 0, 100);

TH1F *hist_matched_recojet_tautau_ak10_Split23 = new TH1F("hist_matched_recojet_tautau_ak10_Split23", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_recojet_tautau_ak10_Split23 = new TH1F("hist_non_matched_recojet_tautau_ak10_Split23", "Split23 for non boosted tautau jets; Split23;Events", 50, 0, 100);

// Histograms of the score for recojet boosted bb jets
TH1F *hist_matched_recojet_bb_score_bdt_Hbb = new TH1F("hist_matched_recojet_bb_score_bdt_Hbb", "Score Hbb for boosted bb jets; Score bdt Hbb;Events", 50, 0, 1.0);
TH1F *hist_non_matched_recojet_bb_score_bdt_Hbb = new TH1F("hist_non_matched_recojet_bb_score_bdt_Hbb", "Score Hbb for non boosted bb jets; Score bdt Hbb;Events", 50, 0, 1.0);

// Histograms of the score for preselected boosted tautau jets
TH1F *hist_matched_recojet_tautau_score_bdt_Htautau = new TH1F("hist_matched_recojet_tautau_score_bdt_Htautau", "Score Htautau for boosted tautau jets; Score bdt Htautau;Events", 50, 0, 1.0);
TH1F *hist_non_matched_recojet_tautau_score_bdt_Htautau = new TH1F("hist_non_matched_recojet_tautau_score_bdt_Htautau", "Score Htautau for boosted tautau jets; Score bdt Htautau;Events", 50, 0, 1.0);

// Histograms for the passesOR of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_passesOR = new TH1F("hist_matched_recojet_bb_ak10_passesOR", "passesOR for boosted bb jets; passesOR;Events", 2, 0, 2);
TH1F *hist_non_matched_recojet_bb_ak10_passesOR = new TH1F("hist_non_matched_recojet_bb_ak10_passesOR", "passesOR for non boosted bb jets; passesOR;Events", 2, 0, 2);

TH1F *hist_matched_recojet_tautau_ak10_passesOR = new TH1F("hist_matched_recojet_tautau_ak10_passesOR", "passesOR for boosted tautau jets; passesOR;Events", 2, 0, 2);
TH1F *hist_non_matched_recojet_tautau_ak10_passesOR = new TH1F("hist_non_matched_recojet_tautau_ak10_passesOR", "passesOR for non boosted tautau jets; passesOR;Events", 2, 0, 2);


// Histograms for the dRmin of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_dR = new TH1F("hist_matched_recojet_bb_dR", "dR distribution of the two truth b that were matched to the same fatjet; dR(bb) [GeV];Events", 50, -1, 3);
TH1F *hist_matched_recojet_tautau_dR = new TH1F("hist_matched_recojet_tautau_dR", "dR distribution of the two truth tau that were matched to the same fatjet; dR(#tau#tau) [GeV];Events", 50, -1, 3);

//***********************************************************************************************************
// Distributions of recojets with the comparison of preselected (cpr)
//***********************************************************************************************************

// GN2X variables distributions

// pbhh GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_phbb_cpr = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_phbb_cpr", "GN2X phbb for boosted bb jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_phbb_cpr = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_phbb_cpr", "GN2X phbb for boosted tautau jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb_cpr", "GN2X phbb for jets with one b; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb_cpr", "GN2X phbb for jets with only one #tau; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_bb_ak10_GN2Xv01_phbb_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_GN2Xv01_phbb_cpr", "GN2X phbb for jets with one b; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_phbb_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_phbb_cpr", "GN2X phbb for jets with only one #tau; GN2X phbb Score;Events", 25, 0, 1);


// pqcd GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_pqcd_cpr = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_pqcd_cpr", "GN2X pqcd for boosted bb jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd_cpr = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd_cpr", "GN2X pqcd for boosted tautau jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd_cpr", "GN2X pqcd for jets with one b; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd_cpr", "GN2X pqcd for jets with only one #tau; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_bb_ak10_GN2Xv01_pqcd_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_GN2Xv01_pqcd_cpr", "GN2X pqcd for jets with one b; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_pqcd_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_pqcd_cpr", "GN2X pqcd for jets with only one #tau; GN2X pqcd Score;Events", 25, 0, 1);

// phcc GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_phcc_cpr = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_phcc_cpr", "GN2X phcc for boosted bb jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_phcc_cpr = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_phcc_cpr", "GN2X phcc for boosted tautau jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_phcc_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_phcc_cpr", "GN2X phcc for jets with one b; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_phcc_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_phcc_cpr", "GN2X phcc for jets with only one #tau; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_bb_ak10_GN2Xv01_phcc_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_GN2Xv01_phcc_cpr", "GN2X phcc for jets with one b; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_phcc_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_phcc_cpr", "GN2X phcc for jets with only one #tau; GN2X phcc Score;Events", 25, 0, 1);

// ptop GN2X
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_ptop_cpr = new TH1F("hist_matched_recojet_bb_ak10_GN2Xv01_ptop_cpr", "GN2X ptop for boosted bb jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_ptop_cpr = new TH1F("hist_matched_recojet_tautau_ak10_GN2Xv01_ptop_cpr", "GN2X ptop for boosted tautau jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_ptop_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_GN2Xv01_ptop_cpr", "GN2X ptop for jets with one b; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_ptop_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_GN2Xv01_ptop_cpr", "GN2X ptop for jets with only one #tau; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_bb_ak10_GN2Xv01_ptop_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_GN2Xv01_ptop_cpr", "GN2X ptop for jets with one b; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_ptop_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_ptop_cpr", "GN2X ptop for jets with only one #tau; GN2X ptop Score;Events", 25, 0, 1);

//n2 over n1 subjettiness
TH1F *hist_matched_recojet_bb_tau_n2_over_n1_subjettiness_cpr = new TH1F("hist_matched_recojet_bb_tau_n2_over_n1_subjettiness_cpr", "Tau n2/n1 subjettiness for boosted bb jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness_cpr = new TH1F("hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness_cpr", "Tau n2/n1 subjettiness for boosted #tau#tau jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness_cpr = new TH1F("hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness_cpr", "Tau n2/n1 subjettiness for jets with one b; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness_cpr = new TH1F("hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness_cpr", "Tau n2/n1 subjettiness for jets with one #tau; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_info_recojet_bb_tau_n2_over_n1_subjettiness_cpr = new TH1F("hist_non_matched_info_recojet_bb_tau_n2_over_n1_subjettiness_cpr", "Tau n2/n1 subjettiness for jets with one b; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_info_recojet_tautau_tau_n2_over_n1_subjettiness_cpr = new TH1F("hist_non_matched_info_recojet_tautau_tau_n2_over_n1_subjettiness_cpr", "Tau n2/n1 subjettiness for jets with one #tau; #tau n2/n1_subjettiness;Events", 50, 0, 1);

// Histograms for the mass of the chosen fatjets for bb and tautau recojets
TH1F *hist_matched_recojet_bb_m_cpr = new TH1F("hist_matched_recojet_bb_m_cpr", "Mass distribution of the recojets that are bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_recojet_tautau_m_cpr = new TH1F("hist_matched_recojet_tautau_m_cpr", "Mass distribution of the recojets that are #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_recojet_bb_m_cpr = new TH1F("hist_non_matched_recojet_bb_m_cpr", "Mass distribution of the recojets that are not bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_recojet_tautau_m_cpr = new TH1F("hist_non_matched_recojet_tautau_m_cpr", "Mass distribution of the recojets that are not #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_info_recojet_bb_m_cpr = new TH1F("hist_non_matched_info_recojet_bb_m_cpr", "Mass distribution of the recojets that are not bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_info_recojet_tautau_m_cpr = new TH1F("hist_non_matched_info_recojet_tautau_m_cpr", "Mass distribution of the recojets that are not #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);

// Histograms for the pT of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_pt_cpr = new TH1F("hist_matched_recojet_bb_pt_cpr", "pT distribution of the recojets that are bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_matched_recojet_tautau_pt_cpr = new TH1F("hist_matched_recojet_tautau_pt_cpr", "pT distribution of the recojets that are #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_non_matched_recojet_bb_pt_cpr = new TH1F("hist_non_matched_recojet_bb_pt_cpr", "pT distribution of the recojets that are not bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_non_matched_recojet_tautau_pt_cpr = new TH1F("hist_non_matched_recojet_tautau_pt_cpr", "pT distribution of the recojets that are not #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_non_matched_info_recojet_bb_pt_cpr = new TH1F("hist_non_matched_info_recojet_bb_pt_cpr", "pT distribution of the recojets that are not bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 1000);
TH1F *hist_non_matched_info_recojet_tautau_pt_cpr = new TH1F("hist_non_matched_info_recojet_tautau_pt_cpr", "pT distribution of the recojets that are not #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 1000);

// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_eta_cpr = new TH1F("hist_matched_recojet_bb_eta_cpr", "#eta distribution of the recojets that are bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_recojet_tautau_eta_cpr = new TH1F("hist_matched_recojet_tautau_eta_cpr", "#eta distribution of the recojets that are #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_bb_eta_cpr = new TH1F("hist_non_matched_recojet_bb_eta_cpr", "#eta distribution of the recojets that are not bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_tautau_eta_cpr = new TH1F("hist_non_matched_recojet_tautau_eta_cpr", "#eta distribution of the recojets that are not #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_recojet_bb_eta_cpr = new TH1F("hist_non_matched_info_recojet_bb_eta_cpr", "#eta distribution of the recojets that are not bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_recojet_tautau_eta_cpr = new TH1F("hist_non_matched_info_recojet_tautau_eta_cpr", "#eta distribution of the recojets that are not #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_recojet_bb_phi_cpr = new TH1F("hist_matched_recojet_bb_phi_cpr", "#phi distribution of the recojets that are bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_recojet_tautau_phi_cpr = new TH1F("hist_matched_recojet_tautau_phi_cpr", "#phi distribution of the recojets that are #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_bb_phi_cpr = new TH1F("hist_non_matched_recojet_bb_phi_cpr", "#phi distribution of the recojets that are not bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_recojet_tautau_phi_cpr = new TH1F("hist_non_matched_recojet_tautau_phi_cpr", "#phi distribution of the recojets that are not #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_recojet_bb_phi_cpr = new TH1F("hist_non_matched_info_recojet_bb_phi_cpr", "#phi distribution of the recojets that are not bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_recojet_tautau_phi_cpr = new TH1F("hist_non_matched_info_recojet_tautau_phi_cpr", "#phi distribution of the recojets that are not #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the ECF1 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_ECF1_cpr = new TH1F("hist_matched_recojet_bb_ak10_ECF1_cpr", "ECF1 for boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_recojet_bb_ak10_ECF1_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_ECF1_cpr", "ECF1 for non boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_info_recojet_bb_ak10_ECF1_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_ECF1_cpr", "ECF1 for non boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_matched_recojet_tautau_ak10_ECF1_cpr = new TH1F("hist_matched_recojet_tautau_ak10_ECF1_cpr", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_recojet_tautau_ak10_ECF1_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_ECF1_cpr", "ECF1 for non boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_info_recojet_tautau_ak10_ECF1_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_ECF1_cpr", "ECF1 for non boosted tautau jets; ECF1;Events", 50, 0, 700);

// Histograms for the ECF2 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_ECF2_cpr = new TH1F("hist_matched_recojet_bb_ak10_ECF2_cpr", "ECF2 for boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_matched_recojet_bb_ak10_ECF2_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_ECF2_cpr", "ECF2 for non boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_matched_info_recojet_bb_ak10_ECF2_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_ECF2_cpr", "ECF2 for non boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_matched_recojet_tautau_ak10_ECF2_cpr = new TH1F("hist_matched_recojet_tautau_ak10_ECF2_cpr", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_non_matched_recojet_tautau_ak10_ECF2_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_ECF2_cpr", "ECF2 for non boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_non_matched_info_recojet_tautau_ak10_ECF2_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_ECF2_cpr", "ECF2 for non boosted tautau jets; ECF2;Events", 50, 0, 3000);

// Histograms for the ECF3 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_ECF3_cpr = new TH1F("hist_matched_recojet_bb_ak10_ECF3_cpr", "ECF3 for boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_non_matched_recojet_bb_ak10_ECF3_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_ECF3_cpr", "ECF3 for non boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_non_matched_info_recojet_bb_ak10_ECF3_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_ECF3_cpr", "ECF3 for non boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_matched_recojet_tautau_ak10_ECF3_cpr = new TH1F("hist_matched_recojet_tautau_ak10_ECF3_cpr", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_non_matched_recojet_tautau_ak10_ECF3_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_ECF3_cpr", "ECF3 for non boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_non_matched_info_recojet_tautau_ak10_ECF3_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_ECF3_cpr", "ECF3 for non boosted tautau jets; ECF3;Events", 50, 0, 80);

// Histograms for the Split12 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_Split12_cpr = new TH1F("hist_matched_recojet_bb_ak10_Split12_cpr", "Split12 for boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_recojet_bb_ak10_Split12_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_Split12_cpr", "Split12 for non boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_info_recojet_bb_ak10_Split12_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_Split12_cpr", "Split12 for non boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_matched_recojet_tautau_ak10_Split12_cpr = new TH1F("hist_matched_recojet_tautau_ak10_Split12_cpr", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_recojet_tautau_ak10_Split12_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_Split12_cpr", "Split12 for non boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_info_recojet_tautau_ak10_Split12_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_Split12_cpr", "Split12 for non boosted tautau jets; Split12;Events", 50, 0, 150);

// Histograms for the Split23 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_recojet_bb_ak10_Split23_cpr = new TH1F("hist_matched_recojet_bb_ak10_Split23_cpr", "Split23 for boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_recojet_bb_ak10_Split23_cpr = new TH1F("hist_non_matched_recojet_bb_ak10_Split23_cpr", "Split23 for non boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_info_recojet_bb_ak10_Split23_cpr = new TH1F("hist_non_matched_info_recojet_bb_ak10_Split23_cpr", "Split23 for non boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_matched_recojet_tautau_ak10_Split23_cpr = new TH1F("hist_matched_recojet_tautau_ak10_Split23_cpr", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_recojet_tautau_ak10_Split23_cpr = new TH1F("hist_non_matched_recojet_tautau_ak10_Split23_cpr", "Split23 for non boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_info_recojet_tautau_ak10_Split23_cpr = new TH1F("hist_non_matched_info_recojet_tautau_ak10_Split23_cpr", "Split23 for non boosted tautau jets; Split23;Events", 50, 0, 100);

//***********************************************************************************************************
// Distributions of recojets with class_event = -1
//***********************************************************************************************************

// Histograms for the pT distributions of the non matched recojets with class != -1
TH1F *hist_non_matched_recojet_pt = new TH1F("hist_non_matched_recojet_pt", "pT distribution of the recojets that were not matched to a truth object; pT_{j} [GeV];Events / 10 bins", 150, 0, 1500);

// Histograms for the eta distributions of the non matched recojets
TH1F *hist_non_matched_recojet_eta = new TH1F("hist_non_matched_recojet_eta", "#eta distribution of the recojets that were not matched to a truth object; #eta_{j} [GeV];Events", 100, -5, 5);


// Histograms for the pT distributions of the non matched recojets with class -1
TH1F *hist_non_matched_recojet_pt_no_class = new TH1F("hist_non_matched_recojet_pt_no_class", "pT distribution of the recojets that were not matched to a truth object (no class); pT_{j} [GeV];Events / 10 bins", 150, 0, 1500);

// Histograms for the eta distributions of the non matched recojets
TH1F *hist_non_matched_recojet_eta_no_class = new TH1F("hist_non_matched_recojet_eta_no_class", "#eta distribution of the recojets that were not matched to a truth object (no class); #eta_{j} [GeV];Events", 100, -5, 5);


// Histograms for the number of events per each class
TH1F *hist_nevents_per_class = new TH1F("hist_nevents_per_class", "Number of events per class; ;Events", 7, -2, 5);

// 2D histogram for the dR values per each class
TH2F *hist2d_dR_per_class_bb = new TH2F("hist2d_dR_per_class_bb", "dR values per each class for boosted bb jets; class; dR", 4, 0, 4, 50, 0, 5);
TH2F *hist2d_dR_per_class_tautau = new TH2F("hist2d_dR_per_class_tautau", "dR values per each class for boosted #tau#tau jets; class; dR", 4, 0, 4, 50, 0, 5);


// Histograms for comparison of distributions of pt
TH1F *hist_truth_HH_pt = new TH1F("hist_truth_HH_pt", "Truth HH pT distribution comparison; p_{T}(HH) [GeV];Events / 10 bins", 100, 0, 1000);
TH1F *hist_computed_HH_pt = new TH1F("hist_computed_HH_pt", "Truth HH pT distribution comparison; p_{T}(HH) [GeV];Events  / 10 bins", 100, 0, 1000);

// Histograms for comparison of distributions of masses
TH1F *hist_truth_HH_m = new TH1F("hist_truth_HH_m", "Truth HH mass distribution comparison; m(HH) [GeV];Events  / 10 bins", 300, 0, 3000);
TH1F *hist_computed_HH_m = new TH1F("hist_computed_HH_m", "Truth HH mass distribution comparison; m(HH) [GeV];Events  / 10 bins", 300, 0, 3000);

//***************************************************************************************************************
// Topological variable histograms of VBF processes
//***************************************************************************************************************

// Two small jets j1 and j2 histograms
TH1F *hist_boosted_recojet_j12_m = new TH1F("hist_boosted_recojet_j12_m", "Mass of the two jets j1 and j2; m_{j_{1},j_{2}}^{system} [GeV];Events", 30, 0, 4000);
TH1F *hist_boosted_recojet_j12_pt = new TH1F("hist_boosted_recojet_j12_pt", "pT of the two jets j1 and j2; p_{T}_{j_{1,2}}^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_recojet_j12_eta = new TH1F("hist_boosted_recojet_j12_eta", "#eta of the two jets j1 and j2; #eta (j_{1},j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_j12_phi = new TH1F("hist_boosted_recojet_j12_phi", "#eta of the two jets j1 and j2; #phi (j_{1},j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_j12_deta = new TH1F("hist_boosted_recojet_j12_deta", "#Delta #eta of the two jets j1 and j2; #Delta #eta(j_{1},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_j12_dphi = new TH1F("hist_boosted_recojet_j12_dphi", "#Delta #eta of the two jets j1 and j2; #Delta #phi(j_{1},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_j12_dR = new TH1F("hist_boosted_recojet_j12_dR", "#Delta #eta of the two jets j1 and j2; #Delta R(j_{1},j_{2}) [GeV];Events", 30, 0, 10);

// Boosted bb and tautau system histograms
TH1F *hist_boosted_recojet_bbtautau_system_m = new TH1F("hist_boosted_recojet_bbtautau_system_m", "Mass of the boosted bb#tau#tau jets system; m_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 3000);
TH1F *hist_boosted_recojet_bbtautau_system_pt = new TH1F("hist_boosted_recojet_bbtautau_system_pt", "pT of boosted bb#tau#tau jets system; p_{T}_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_recojet_bbtautau_system_eta = new TH1F("hist_boosted_recojet_bbtautau_system_eta", "#eta of the boosted bb#tau#tau jets system; #eta_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_bbtautau_system_phi = new TH1F("hist_boosted_recojet_bbtautau_system_phi", "#eta of the boosted bb#tau#tau jets system; #phi_{h_{1}, h_{2}}^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_bbtautau_system_deta = new TH1F("hist_boosted_recojet_bbtautau_system_deta", "#Delta #eta of the boosted bb and #tau#tau; #Delta #eta(h_{1}, h_{2}) [GeV];Events", 30, 0, 4);
TH1F *hist_boosted_recojet_bbtautau_system_dphi = new TH1F("hist_boosted_recojet_bbtautau_system_dphi", "#Delta #eta of the boosted bb and #tau#tau; #Delta #phi(h_{1}, h_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_bbtautau_system_dR = new TH1F("hist_boosted_recojet_bbtautau_system_dR", "#Delta #eta of the boosted bb and #tau#tau; #Delta R(h_{1}, h_{2}) [GeV];Events", 30, 0, 5);

// Boosted bb and jet1 histograms
TH1F *hist_boosted_recojet_bb_j1_system_m = new TH1F("hist_boosted_recojet_bb_j1_system_m", "Mass of the boosted bb and j1 system; m_(H_{bb}, j_{1})^{system} [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_recojet_bb_j1_system_pt = new TH1F("hist_boosted_recojet_bb_j1_system_pt", "pT of boosted bb and j1 system; p_{T}(h_{1}, j_{1})^{system} [GeV];Events", 30, 0, 1800);
TH1F *hist_boosted_recojet_bb_j1_system_eta = new TH1F("hist_boosted_recojet_bb_j1_system_eta", "#eta of the boosted bb and j1 system; #eta_(H_{bb}, j_{1})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_bb_j1_system_phi = new TH1F("hist_boosted_recojet_bb_j1_system_phi", "#eta of the boosted bb and j1 system; #phi_(H_{bb}, j_{1})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_bb_j1_system_deta = new TH1F("hist_boosted_recojet_bb_j1_system_deta", "#Delta #eta of the boosted bb and j1; #Delta #eta(H_{bb},j_{1}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_bb_j1_system_dphi = new TH1F("hist_boosted_recojet_bb_j1_system_dphi", "#Delta #eta of the boosted bb and j1; #Delta #phi(H_{bb},j_{1}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_bb_j1_system_dR = new TH1F("hist_boosted_recojet_bb_j1_system_dR", "#Delta #eta of the boosted bb and j1; #Delta R(H_{bb},j_{1}) [GeV];Events", 30, 0, 10);

// Boosted bb and jet2 histograms
TH1F *hist_boosted_recojet_bb_j2_system_m = new TH1F("hist_boosted_recojet_bb_j2_system_m", "Mass of the boosted bb and j2 system; m_(h_{1}, j_{2})^{system} [GeV];Events", 30, 0, 3000);
TH1F *hist_boosted_recojet_bb_j2_system_pt = new TH1F("hist_boosted_recojet_bb_j2_system_pt", "pT of boosted bb and j2 system; p_{T}_(h_{1}, j_{2})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_recojet_bb_j2_system_eta = new TH1F("hist_boosted_recojet_bb_j2_system_eta", "#eta of the boosted bb and j2 system; #eta_(H_{bb}, j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_bb_j2_system_phi = new TH1F("hist_boosted_recojet_bb_j2_system_phi", "#eta of the boosted bb and j2 system; #phi_(h_{1}, j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_bb_j2_system_deta = new TH1F("hist_boosted_recojet_bb_j2_system_deta", "#Delta #eta of the boosted bb and j2; #Delta #eta(h_{1},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_bb_j2_system_dphi = new TH1F("hist_boosted_recojet_bb_j2_system_dphi", "#Delta #eta of the boosted bb and j2; #Delta #phi(h_{1},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_bb_j2_system_dR = new TH1F("hist_boosted_recojet_bb_j2_system_dR", "#Delta #eta of the boosted bb and j2; #Delta R(h_{1},j_{2}) [GeV];Events", 30, 0, 8);

// Boosted tautau and jet1 histograms
TH1F *hist_boosted_recojet_tautau_j1_system_m = new TH1F("hist_boosted_recojet_tautau_j1_system_m", "Mass of the boosted #tau#tau and j1 system; m_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_recojet_tautau_j1_system_pt = new TH1F("hist_boosted_recojet_tautau_j1_system_pt", "pT of boosted #tau#tau and j1 system; p_{T}_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_recojet_tautau_j1_system_eta = new TH1F("hist_boosted_recojet_tautau_j1_system_eta", "#eta of the boosted #tau#tau and j1 system; #eta_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_tautau_j1_system_phi = new TH1F("hist_boosted_recojet_tautau_j1_system_phi", "#eta of the boosted #tau#tau and j1 system; #phi_(h_{2}, j_{1})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_tautau_j1_system_deta = new TH1F("hist_boosted_recojet_tautau_j1_system_deta", "#Delta #eta of the boosted #tau#tau and j1; #Delta #eta(h_{2},j_{1}) [GeV];Events", 30, 0, 8);
TH1F *hist_boosted_recojet_tautau_j1_system_dphi = new TH1F("hist_boosted_recojet_tautau_j1_system_dphi", "#Delta #eta of the boosted #tau#tau and j1; #Delta #phi(h_{2},j_{1}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_tautau_j1_system_dR = new TH1F("hist_boosted_recojet_tautau_j1_system_dR", "#Delta #eta of the boosted #tau#tau and j1; #Delta R(h_{2},j_{1}) [GeV];Events", 30, 0, 10);

// Boosted tautau and jet2 histograms
TH1F *hist_boosted_recojet_tautau_j2_system_m = new TH1F("hist_boosted_recojet_tautau_j2_system_m", "Mass of the boosted #tau#tau and j2 system; m_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 2500);
TH1F *hist_boosted_recojet_tautau_j2_system_pt = new TH1F("hist_boosted_recojet_tautau_j2_system_pt", "pT of boosted #tau#tau and j2 system; p_{T}_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_recojet_tautau_j2_system_eta = new TH1F("hist_boosted_recojet_tautau_j2_system_eta", "#eta of the boosted #tau#tau and j2 system; #eta_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_tautau_j2_system_phi = new TH1F("hist_boosted_recojet_tautau_j2_system_phi", "#eta of the boosted #tau#tau and j2 system; #phi_(h_{2}, j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_tautau_j2_system_deta = new TH1F("hist_boosted_recojet_tautau_j2_system_deta", "#Delta #eta of the boosted #tau#tau and j2; #Delta #eta(h_{2},j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_tautau_j2_system_dphi = new TH1F("hist_boosted_recojet_tautau_j2_system_dphi", "#Delta #eta of the boosted #tau#tau and j2; #Delta #phi(h_{2},j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_tautau_j2_system_dR = new TH1F("hist_boosted_recojet_tautau_j2_system_dR", "#Delta #eta of the boosted #tau#tau and j2; #Delta R(h_{2},j_{2}) [GeV];Events", 30, 0, 10);

// All jets system variables
TH1F *hist_boosted_recojet_all_jets_system_m = new TH1F("hist_boosted_recojet_all_jets_system_m", "Mass of the boosted jets system; m_{(h_{1}, h_{2}, j_{1}, j_{2})}^{system} [GeV];Events", 30, 500, 6000);
TH1F *hist_boosted_recojet_all_jets_system_pt = new TH1F("hist_boosted_recojet_all_jets_system_pt", "pT of boosted jets system; p_{T}_(h_{1}, h_{2}, j_{1}, j_{2})^{system} [GeV];Events", 30, 0, 2000);
TH1F *hist_boosted_recojet_all_jets_system_eta = new TH1F("hist_boosted_recojet_all_jets_system_eta", "#eta of the boosted jets system; #eta_(h_{1}, h_{2}, j_{1}, j_{2})^{system} [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_all_jets_system_phi = new TH1F("hist_boosted_recojet_all_jets_system_phi", "#eta of the boosted jets system; #phi_(h_{1}, h_{2}, j_{1}, j_{2})^{system} [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_all_jets_system_deta = new TH1F("hist_boosted_recojet_all_jets_system_deta", "#Delta #eta of the boosted bb#tau#tau and j12; #Delta #eta(h_{1}, h_{2},j_{1}j_{2}) [GeV];Events", 30, 0, 10);
TH1F *hist_boosted_recojet_all_jets_system_dphi = new TH1F("hist_boosted_recojet_all_jets_system_dphi", "#Delta #eta of the boosted bb#tau#tau and j12; #Delta #phi(h_{1}, h_{2},j_{1}j_{2}) [GeV];Events", 30, 0, 5);
TH1F *hist_boosted_recojet_all_jets_system_dR = new TH1F("hist_boosted_recojet_all_jets_system_dR", "#Delta #eta of the boosted bb#tau#tau and j12; #Delta R(H_{bb#tau#tau},j_{12}) [GeV];Events", 30, 0, 10);

// Zeppenfeld variables
TH1F *hist_boosted_recojet_j12_Zeppenfeld_Hbb = new TH1F("hist_boosted_recojet_j12_Zeppenfeld_Hbb", "Zeppenfeld Z_{Hbb}^{*} of the two jets j1 and j2; Z_{H #rightarrow bb}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_recojet_j12_Zeppenfeld_Htautau = new TH1F("hist_boosted_recojet_j12_Zeppenfeld_Htautau", "Zeppenfeld Z_{Htautau}^{*} of the two jets j1 and j2; Z_{H #rightarrow #tau#tau}^{*};Events", 30, 0, 5);
TH1F *hist_boosted_recojet_j12_Zeppenfeld_jet12 = new TH1F("hist_boosted_recojet_j12_Zeppenfeld_jet12", "Zeppenfeld Z_{jet12}^{*} of the two jets j1 and j2; Z_{j_{12}}^{*};Events", 30, 0, 5);