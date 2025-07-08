// *************************************
// Declaration of histograms
// *************************************

// 2D histogram for matched and preselected percentages
TH2F *percentages_matched_and_preselected_events_BbbBtautau = new TH2F("percentages_matched_and_preselected_events_BbbBtautau", "Percentages between matched and preselected events for B_{bb} B_{#tau#tau}", 2, 0, 2, 3, 0, 3);
TH2F *percentages_matched_and_preselected_events_only_Bbb = new TH2F("percentages_matched_and_preselected_events_only_Bbb", "Percentages between matched and preselected events for B_{bb}", 2, 0, 2, 3, 0, 3);
TH2F *percentages_matched_and_preselected_events_only_Btautau = new TH2F("percentages_matched_and_preselected_events_only_Btautau", "Percentages between matched and preselected events for B_{#tau#tau}", 2, 0, 2, 3, 0, 3);

TH2F *percentages_statistical_parameters_for_preselected_events = new TH2F("percentages_statistical_parameters_for_preselected_events", "Statistical parameters between matched and preselected events", 3, 0, 3, 3, 0, 3);

//***************************************************************************
//Preselected events variables histograms 
//***************************************************************************

// pbhh GN2X
TH1F *hist_matched_preselected_bb_ak10_GN2Xv01_phbb = new TH1F("hist_matched_preselected_bb_ak10_GN2Xv01_phbb", "GN2X phbb for boosted bb jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_matched_preselected_tautau_ak10_GN2Xv01_phbb = new TH1F("hist_matched_preselected_tautau_ak10_GN2Xv01_phbb", "GN2X phbb for boosted tautau jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_bb_ak10_GN2Xv01_phbb = new TH1F("hist_non_matched_preselected_bb_ak10_GN2Xv01_phbb", "GN2X phbb for non boosted bb jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_tautau_ak10_GN2Xv01_phbb = new TH1F("hist_non_matched_preselected_tautau_ak10_GN2Xv01_phbb", "GN2X phbb for non boosted tautau jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_bb_ak10_GN2Xv01_phbb = new TH1F("hist_non_matched_info_preselected_bb_ak10_GN2Xv01_phbb", "GN2X phbb for non boosted bb jets; GN2X phbb Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_phbb = new TH1F("hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_phbb", "GN2X phbb for non boosted tautau jets; GN2X phbb Score;Events", 25, 0, 1);

// pqcd GN2X
TH1F *hist_matched_preselected_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_matched_preselected_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for boosted bb jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_matched_preselected_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_matched_preselected_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for boosted tautau jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_preselected_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for non boosted bb jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_preselected_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for non boosted tautau jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_bb_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_info_preselected_bb_ak10_GN2Xv01_pqcd", "GN2X pqcd for non boosted bb jets; GN2X pqcd Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_pqcd = new TH1F("hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_pqcd", "GN2X pqcd for non boosted tautau jets; GN2X pqcd Score;Events", 25, 0, 1);

// phcc GN2X
TH1F *hist_matched_preselected_bb_ak10_GN2Xv01_phcc = new TH1F("hist_matched_preselected_bb_ak10_GN2Xv01_phcc", "GN2X phcc for boosted bb jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_matched_preselected_tautau_ak10_GN2Xv01_phcc = new TH1F("hist_matched_preselected_tautau_ak10_GN2Xv01_phcc", "GN2X phcc for boosted tautau jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_bb_ak10_GN2Xv01_phcc = new TH1F("hist_non_matched_preselected_bb_ak10_GN2Xv01_phcc", "GN2X phcc for non boosted bb jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_tautau_ak10_GN2Xv01_phcc = new TH1F("hist_non_matched_preselected_tautau_ak10_GN2Xv01_phcc", "GN2X phcc for non boosted tautau jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_bb_ak10_GN2Xv01_phcc = new TH1F("hist_non_matched_info_preselected_bb_ak10_GN2Xv01_phcc", "GN2X phcc for non boosted bb jets; GN2X phcc Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_phcc = new TH1F("hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_phcc", "GN2X phcc for non boosted tautau jets; GN2X phcc Score;Events", 25, 0, 1);

// ptop GN2X
TH1F *hist_matched_preselected_bb_ak10_GN2Xv01_ptop = new TH1F("hist_matched_preselected_bb_ak10_GN2Xv01_ptop", "GN2X ptop for boosted bb jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_matched_preselected_tautau_ak10_GN2Xv01_ptop = new TH1F("hist_matched_preselected_tautau_ak10_GN2Xv01_ptop", "GN2X ptop for boosted tautau jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_bb_ak10_GN2Xv01_ptop = new TH1F("hist_non_matched_preselected_bb_ak10_GN2Xv01_ptop", "GN2X ptop for non boosted bb jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_preselected_tautau_ak10_GN2Xv01_ptop = new TH1F("hist_non_matched_preselected_tautau_ak10_GN2Xv01_ptop", "GN2X ptop for non boosted tautau jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_bb_ak10_GN2Xv01_ptop = new TH1F("hist_non_matched_info_preselected_bb_ak10_GN2Xv01_ptop", "GN2X ptop for non boosted bb jets; GN2X ptop Score;Events", 25, 0, 1);
TH1F *hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_ptop = new TH1F("hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_ptop", "GN2X ptop for non boosted tautau jets; GN2X ptop Score;Events", 25, 0, 1);

//n2 over n1 subjettiness
TH1F *hist_matched_preselected_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_matched_preselected_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for boosted bb jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for boosted #tau#tau jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_preselected_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_preselected_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for non boosted bb jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_preselected_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_preselected_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for non boosted #tau#tau jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_info_preselected_bb_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_info_preselected_bb_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for non boosted bb jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);
TH1F *hist_non_matched_info_preselected_tautau_tau_n2_over_n1_subjettiness = new TH1F("hist_non_matched_info_preselected_tautau_tau_n2_over_n1_subjettiness", "Tau n2/n1 subjettiness for non boosted #tau#tau jets; #tau n2/n1_subjettiness;Events", 50, 0, 1);

// Histograms for the mass of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_m_only_Hbb_tagger = new TH1F("hist_matched_preselected_bb_m_only_Hbb_tagger", "Mass distribution of the recojets that are bb boosted jets (only tagger); m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_preselected_bb_m_until_nsubjettiness = new TH1F("hist_matched_preselected_bb_m_until_nsubjettiness", "Mass distribution of the recojets that are bb boosted jets (tagger and nsubjettiness); m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_preselected_bb_m_order_by_nsubjettiness = new TH1F("hist_matched_preselected_bb_m_order_by_nsubjettiness", "Mass distribution of the recojets that are bb boosted jets (order nsubjettiness); m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_preselected_tautau_m_only_Hbb_tagger = new TH1F("hist_matched_preselected_tautau_m_only_Hbb_tagger", "Mass distribution of the recojets that are #tau#tau boosted jets (only tagger); m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_preselected_tautau_m_until_nsubjettiness = new TH1F("hist_matched_preselected_tautau_m_until_nsubjettiness", "Mass distribution of the recojets that are #tau#tau boosted jets (tagger and nsubjettiness); m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);

TH1F *hist_matched_preselected_bb_m = new TH1F("hist_matched_preselected_bb_m", "Mass distribution of the recojets that are bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_matched_preselected_tautau_m = new TH1F("hist_matched_preselected_tautau_m", "Mass distribution of the recojets that are #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_preselected_bb_m = new TH1F("hist_non_matched_preselected_bb_m", "Mass distribution of the recojets that are non bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_preselected_tautau_m = new TH1F("hist_non_matched_preselected_tautau_m", "Mass distribution of the recojets that are non #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_info_preselected_bb_m = new TH1F("hist_non_matched_info_preselected_bb_m", "Mass distribution of the recojets that are non bb boosted jets; m(H #rightarrow bb) [GeV];Events / 5 bins", 70, 0, 350);
TH1F *hist_non_matched_info_preselected_tautau_m = new TH1F("hist_non_matched_info_preselected_tautau_m", "Mass distribution of the recojets that are non #tau#tau boosted jets; m(H #rightarrow #tau#tau) [GeV];Einfo_vents / 5 bins", 70, 0, 350);


// Histograms for the pT of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_pt = new TH1F("hist_matched_preselected_bb_pt", "pT distribution of the recojets that are bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_matched_preselected_tautau_pt = new TH1F("hist_matched_preselected_tautau_pt", "pT distribution of the recojets that are #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_non_matched_preselected_bb_pt = new TH1F("hist_non_matched_preselected_bb_pt", "pT distribution of the recojets that are non bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_non_matched_preselected_tautau_pt = new TH1F("hist_non_matched_preselected_tautau_pt", "pT distribution of the recojets that are non #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_non_matched_info_preselected_bb_pt = new TH1F("hist_non_matched_info_preselected_bb_pt", "pT distribution of the recojets that are non bb boosted jets; p_{T}(H #rightarrow bb) [GeV];Events / 20 bins", 100, 0, 2000);
TH1F *hist_non_matched_info_preselected_tautau_pt = new TH1F("hist_non_matched_info_preselected_tautau_pt", "pT distribution of the recojets that are non #tau#tau boosted jets; p_{T}(H #rightarrow #tau#tau) [GeV];Events / 20 bins", 100, 0, 2000);


// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_eta = new TH1F("hist_matched_preselected_bb_eta", "#eta distribution of the recojets that are bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_preselected_tautau_eta = new TH1F("hist_matched_preselected_tautau_eta", "#eta distribution of the recojets that are #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_preselected_bb_eta = new TH1F("hist_non_matched_preselected_bb_eta", "#eta distribution of the recojets that are non bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_preselected_tautau_eta = new TH1F("hist_non_matched_preselected_tautau_eta", "#eta distribution of the recojets that are non #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_preselected_bb_eta = new TH1F("hist_non_matched_info_preselected_bb_eta", "#eta distribution of the recojets that are non bb boosted jets; #eta_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_preselected_tautau_eta = new TH1F("hist_non_matched_info_preselected_tautau_eta", "#eta distribution of the recojets that are non #tau#tau boosted jets; #eta_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the eta of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_phi = new TH1F("hist_matched_preselected_bb_phi", "#phi distribution of the recojets that are bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_matched_preselected_tautau_phi = new TH1F("hist_matched_preselected_tautau_phi", "#phi distribution of the recojets that are #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_preselected_bb_phi = new TH1F("hist_non_matched_preselected_bb_phi", "#phi distribution of the recojets that are non bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_preselected_tautau_phi = new TH1F("hist_non_matched_preselected_tautau_phi", "#phi distribution of the recojets that are non #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_preselected_bb_phi = new TH1F("hist_non_matched_info_preselected_bb_phi", "#phi distribution of the recojets that are non bb boosted jets; #phi_{j(H #rightarrow bb)} [GeV];Events", 100, -5, 5);
TH1F *hist_non_matched_info_preselected_tautau_phi = new TH1F("hist_non_matched_info_preselected_tautau_phi", "#phi distribution of the recojets that are non #tau#tau boosted jets; #phi_{j(H #rightarrow #tau#tau)} [GeV];Events", 100, -5, 5);

// Histograms for the ECF1 of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_ak10_ECF1 = new TH1F("hist_matched_preselected_bb_ak10_ECF1", "ECF1 for boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_preselected_bb_ak10_ECF1 = new TH1F("hist_non_matched_preselected_bb_ak10_ECF1", "ECF1 for non boosted bb jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_info_preselected_bb_ak10_ECF1 = new TH1F("hist_non_matched_info_preselected_bb_ak10_ECF1", "ECF1 for non boosted bb jets; ECF1;Events", 50, 0, 700);

TH1F *hist_matched_preselected_tautau_ak10_ECF1 = new TH1F("hist_matched_preselected_tautau_ak10_ECF1", "ECF1 for boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_preselected_tautau_ak10_ECF1 = new TH1F("hist_non_matched_preselected_tautau_ak10_ECF1", "ECF1 for non boosted tautau jets; ECF1;Events", 50, 0, 700);
TH1F *hist_non_matched_info_preselected_tautau_ak10_ECF1 = new TH1F("hist_non_matched_info_preselected_tautau_ak10_ECF1", "ECF1 for non boosted tautau jets; ECF1;Events", 50, 0, 700);

// Histograms for the ECF2 of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_ak10_ECF2 = new TH1F("hist_matched_preselected_bb_ak10_ECF2", "ECF2 for boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_matched_preselected_bb_ak10_ECF2 = new TH1F("hist_non_matched_preselected_bb_ak10_ECF2", "ECF2 for non boosted bb jets; ECF2;Events", 50, 0, 5000);
TH1F *hist_non_matched_info_preselected_bb_ak10_ECF2 = new TH1F("hist_non_matched_info_preselected_bb_ak10_ECF2", "ECF2 for non boosted bb jets; ECF2;Events", 50, 0, 5000);

TH1F *hist_matched_preselected_tautau_ak10_ECF2 = new TH1F("hist_matched_preselected_tautau_ak10_ECF2", "ECF2 for boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_non_matched_preselected_tautau_ak10_ECF2 = new TH1F("hist_non_matched_preselected_tautau_ak10_ECF2", "ECF2 for non boosted tautau jets; ECF2;Events", 50, 0, 3000);
TH1F *hist_non_matched_info_preselected_tautau_ak10_ECF2 = new TH1F("hist_non_matched_info_preselected_tautau_ak10_ECF2", "ECF2 for non boosted tautau jets; ECF2;Events", 50, 0, 3000);

// Histograms for the ECF3 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_preselected_bb_ak10_ECF3 = new TH1F("hist_matched_preselected_bb_ak10_ECF3", "ECF3 for boosted bb jets; ECF3;Events" , 50, 0, 10000);
TH1F *hist_non_matched_preselected_bb_ak10_ECF3 = new TH1F("hist_non_matched_preselected_bb_ak10_ECF3", "ECF3 for non boosted bb jets; ECF3;Events", 50, 0, 10000);
TH1F *hist_non_matched_info_preselected_bb_ak10_ECF3 = new TH1F("hist_non_matched_info_preselected_bb_ak10_ECF3", "ECF3 for non boosted bb jets; ECF3;Events", 50, 0, 10000);

TH1F *hist_matched_preselected_tautau_ak10_ECF3 = new TH1F("hist_matched_preselected_tautau_ak10_ECF3", "ECF3 for boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_non_matched_preselected_tautau_ak10_ECF3 = new TH1F("hist_non_matched_preselected_tautau_ak10_ECF3", "ECF3 for non boosted tautau jets; ECF3;Events", 50, 0, 80);
TH1F *hist_non_matched_info_preselected_tautau_ak10_ECF3 = new TH1F("hist_non_matched_info_preselected_tautau_ak10_ECF3", "ECF3 for non boosted tautau jets; ECF3;Events", 50, 0, 80);

// Histograms for the Split12 of the chosen fatjets for bb and tautau jets

TH1F *hist_matched_preselected_bb_ak10_Split12 = new TH1F("hist_matched_preselected_bb_ak10_Split12", "Split12 for boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_preselected_bb_ak10_Split12 = new TH1F("hist_non_matched_preselected_bb_ak10_Split12", "Split12 for non boosted bb jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_info_preselected_bb_ak10_Split12 = new TH1F("hist_non_matched_info_preselected_bb_ak10_Split12", "Split12 for non boosted bb jets; Split12;Events", 50, 0, 150);

TH1F *hist_matched_preselected_tautau_ak10_Split12 = new TH1F("hist_matched_preselected_tautau_ak10_Split12", "Split12 for boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_preselected_tautau_ak10_Split12 = new TH1F("hist_non_matched_preselected_tautau_ak10_Split12", "Split12 for non boosted tautau jets; Split12;Events", 50, 0, 150);
TH1F *hist_non_matched_info_preselected_tautau_ak10_Split12 = new TH1F("hist_non_matched_info_preselected_tautau_ak10_Split12", "Split12 for non boosted tautau jets; Split12;Events", 50, 0, 150);

// Histograms for the Split23 of the chosen fatjets for bb and tautau jets
TH1F *hist_matched_preselected_bb_ak10_Split23 = new TH1F("hist_matched_preselected_bb_ak10_Split23", "Split23 for boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_preselected_bb_ak10_Split23 = new TH1F("hist_non_matched_preselected_bb_ak10_Split23", "Split23 for non boosted bb jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_info_preselected_bb_ak10_Split23 = new TH1F("hist_non_matched_info_preselected_bb_ak10_Split23", "Split23 for non boosted bb jets; Split23;Events", 50, 0, 100);

TH1F *hist_matched_preselected_tautau_ak10_Split23 = new TH1F("hist_matched_preselected_tautau_ak10_Split23", "Split23 for boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_preselected_tautau_ak10_Split23 = new TH1F("hist_non_matched_preselected_tautau_ak10_Split23", "Split23 for non boosted tautau jets; Split23;Events", 50, 0, 100);
TH1F *hist_non_matched_info_preselected_tautau_ak10_Split23 = new TH1F("hist_non_matched_info_preselected_tautau_ak10_Split23", "Split23 for non boosted tautau jets; Split23;Events", 50, 0, 100);

// Histograms of the score for preselected boosted bb jets
TH1F *hist_matched_preselected_bb_score_bdt_Hbb = new TH1F("hist_matched_preselected_bb_score_bdt_Hbb", "Score Hbb for boosted bb jets; Score bdt Hbb;Events", 50, 0, 1.0);
TH1F *hist_non_matched_preselected_bb_score_bdt_Hbb = new TH1F("hist_non_matched_preselected_bb_score_bdt_Hbb", "Score Hbb for non boosted bb jets; Score bdt Hbb;Events", 50, 0, 1.0);

// Histograms of the score for preselected boosted tautau jets
TH1F *hist_matched_preselected_tautau_score_bdt_Htautau = new TH1F("hist_matched_preselected_tautau_score_bdt_Htautau", "Score Htautau for boosted tautau jets; Score bdt Htautau;Events", 50, 0, 1.0);
TH1F *hist_non_matched_preselected_tautau_score_bdt_Htautau = new TH1F("hist_non_matched_preselected_tautau_score_bdt_Htautau", "Score Htautau for boosted tautau jets; Score bdt Htautau;Events", 50, 0, 1.0);

// Histograms of the score for preselected boosted tautau jets
TH1F *hist_matched_preselected_bbtautau_score_bdt_HHbbtautau = new TH1F("hist_matched_preselected_bbtautau_score_bdt_HHbbtautau", "Score HHbbtautau for boosted bbtautau events; Score bdt bbtautau;Events", 50, 0, 1.0);
TH1F *hist_non_matched_preselected_bbtautau_score_bdt_HHbbtautau = new TH1F("hist_non_matched_preselected_bbtautau_score_bdt_HHbbtautau", "Score HHbbtautau for boosted bbtautau events; Score bdt bbtautau;Events", 50, 0, 1.0);

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

TH1F *hist_boosted_cutflow_small_jets = new TH1F("hist_boosted_cutflow_small_jets", "Cutflow of the two jets j1 and j2; cut;Events", 8, 0, 8);
TH1F *hist_boosted_njets = new TH1F("hist_boosted_njets", "Number of small jets for VBF; small n jets;Events", 10, 0, 10);