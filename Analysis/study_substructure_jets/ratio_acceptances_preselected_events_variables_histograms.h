// *************************************
// Declaration of x limits for histograms
// *************************************

float x_min_preselected_mHH = 200.0;
float x_max_preselected_mHH = 1500.0;
float x_min_preselected_ptHH = 200.0;
float x_max_preselected_ptHH = 1000.0;
float x_min_preselected_etaHH = -5.0;
float x_max_preselected_etaHH = 5.0;
float x_min_preselected_phiHH = -5.0;
float x_max_preselected_phiHH = 5.0;

float x_min_preselected_mHbb = 0.0;
float x_max_preselected_mHbb = 400.0;
float x_min_preselected_ptHbb = 0.0;
float x_max_preselected_ptHbb = 1000.0;
float x_min_preselected_etaHbb = -5.0;
float x_max_preselected_etaHbb = 5.0;
float x_min_preselected_phiHbb = -5.0;
float x_max_preselected_phiHbb = 5.0;

float x_min_preselected_mHtautau = 0.0;
float x_max_preselected_mHtautau = 400.0;
float x_min_preselected_ptHtautau = 0.0;
float x_max_preselected_ptHtautau = 1000.0;
float x_min_preselected_etaHtautau = -5.0;
float x_max_preselected_etaHtautau = 5.0;
float x_min_preselected_phiHtautau = -5.0;
float x_max_preselected_phiHtautau = 5.0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************
// Histograms for ratio_1 and ratio_2 for preselected events variables 
//******************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//******************************************************
// Histograms for mass of preselected events truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_mHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_mHH_numerator_class0_r1_r2", "Acceptance plot using the preselected_mHH variable (r_{1,2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_mHH_numerator_class1_r1_r2", "Acceptance plot using the preselected_mHH variable (r_{1,2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_mHH_numerator_class2_r1_r2", "Acceptance plot using the preselected_mHH variable (r_{1,2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_mHH_numerator_class3_r1_r2", "Acceptance plot using the preselected_mHH variable (r_{1,2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);

TH1F *hist_acceptance_preselected_mHH_denominator_r1 = new TH1F("hist_acceptance_preselected_mHH_denominator_r1", "Acceptance plot using the preselected_mHH variable; preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);

TH1F *hist_acceptance_preselected_mHH_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_mHH_denominator_class0_r2", "Acceptance plot using the preselected_mHH variable (r_{2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_mHH_denominator_class1_r2", "Acceptance plot using the preselected_mHH variable (r_{2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_mHH_denominator_class2_r2", "Acceptance plot using the preselected_mHH variable (r_{2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_mHH_denominator_class3_r2", "Acceptance plot using the preselected_mHH variable (r_{2}); preselected mHH [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);

//******************************************************
// Histograms for pT of preselected events truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_ptHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class0_r1_r2", "Acceptance plot using the preselected_ptHH variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class1_r1_r2", "Acceptance plot using the preselected_ptHH variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class2_r1_r2", "Acceptance plot using the preselected_ptHH variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class3_r1_r2", "Acceptance plot using the preselected_ptHH variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);

TH1F *hist_acceptance_preselected_ptHH_denominator_r1 = new TH1F("hist_acceptance_preselected_ptHH_denominator_r1", "Acceptance plot using the preselected_ptHH variable; preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);

TH1F *hist_acceptance_preselected_ptHH_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_ptHH_denominator_class0_r2", "Acceptance plot using the preselected_ptHH variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_ptHH_denominator_class1_r2", "Acceptance plot using the preselected_ptHH variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_ptHH_denominator_class2_r2", "Acceptance plot using the preselected_ptHH variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_ptHH_denominator_class3_r2", "Acceptance plot using the preselected_ptHH variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);

//******************************************************
// Histograms for eta of preselected events truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_etaHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class0_r1_r2", "Acceptance plot using the preselected_etaHH variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class1_r1_r2", "Acceptance plot using the preselected_etaHH variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class2_r1_r2", "Acceptance plot using the preselected_etaHH variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class3_r1_r2", "Acceptance plot using the preselected_etaHH variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);

TH1F *hist_acceptance_preselected_etaHH_denominator_r1 = new TH1F("hist_acceptance_preselected_etaHH_denominator_r1", "Acceptance plot using the preselected_etaHH variable; preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);

TH1F *hist_acceptance_preselected_etaHH_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_etaHH_denominator_class0_r2", "Acceptance plot using the preselected_etaHH variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_etaHH_denominator_class1_r2", "Acceptance plot using the preselected_etaHH variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_etaHH_denominator_class2_r2", "Acceptance plot using the preselected_etaHH variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_etaHH_denominator_class3_r2", "Acceptance plot using the preselected_etaHH variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);

//******************************************************
// Histograms for phi of preselected events truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_phiHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class0_r1_r2", "Acceptance plot using the preselected_phiHH variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class1_r1_r2", "Acceptance plot using the preselected_phiHH variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class2_r1_r2", "Acceptance plot using the preselected_phiHH variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class3_r1_r2", "Acceptance plot using the preselected_phiHH variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);

TH1F *hist_acceptance_preselected_phiHH_denominator_r1 = new TH1F("hist_acceptance_preselected_phiHH_denominator_r1", "Acceptance plot using the preselected_phiHH variable; preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);

TH1F *hist_acceptance_preselected_phiHH_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_phiHH_denominator_class0_r2", "Acceptance plot using the preselected_phiHH variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_phiHH_denominator_class1_r2", "Acceptance plot using the preselected_phiHH variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_phiHH_denominator_class2_r2", "Acceptance plot using the preselected_phiHH variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_phiHH_denominator_class3_r2", "Acceptance plot using the preselected_phiHH variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);

//******************************************************
// Histograms for mass of preselected events truth bb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_mHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class0_r1_r2", "Acceptance plot using the preselected_mHbb variable (r_{1,2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class1_r1_r2", "Acceptance plot using the preselected_mHbb variable (r_{1,2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class2_r1_r2", "Acceptance plot using the preselected_mHbb variable (r_{1,2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class3_r1_r2", "Acceptance plot using the preselected_mHbb variable (r_{1,2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

TH1F *hist_acceptance_preselected_mHbb_denominator_r1 = new TH1F("hist_acceptance_preselected_mHbb_denominator_r1", "Acceptance plot using the preselected_mHbb variable; preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

TH1F *hist_acceptance_preselected_mHbb_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_mHbb_denominator_class0_r2", "Acceptance plot using the preselected_mHbb variable (r_{2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_mHbb_denominator_class1_r2", "Acceptance plot using the preselected_mHbb variable (r_{2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_mHbb_denominator_class2_r2", "Acceptance plot using the preselected_mHbb variable (r_{2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_mHbb_denominator_class3_r2", "Acceptance plot using the preselected_mHbb variable (r_{2}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

TH1F *hist_acceptance_all_Bbb_preselected_mHbb_numerator_r1_r2 = new TH1F("hist_acceptance_all_Bbb_preselected_mHbb_numerator_r1_r2", "Acceptance plot using preselected_mHbb variable (r_{1,2}); preselected m(H #rightarrow bb) [GeV]; Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

TH1F *hist_acceptance_all_Bbb_preselected_mHbb_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Bbb_preselected_mHbb_denominator_r2_numerator_r4", "Acceptance plot using preselected_mHbb variable (r_{2,4}); preselected m(H #rightarrow bb) [GeV]; Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

//******************************************************
// Histograms for pT of preselected events truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_ptHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class0_r1_r2", "Acceptance plot using the preselected_ptHbb variable (r_{1,2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class1_r1_r2", "Acceptance plot using the preselected_ptHbb variable (r_{1,2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class2_r1_r2", "Acceptance plot using the preselected_ptHbb variable (r_{1,2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class3_r1_r2", "Acceptance plot using the preselected_ptHbb variable (r_{1,2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

TH1F *hist_acceptance_preselected_ptHbb_denominator_r1 = new TH1F("hist_acceptance_preselected_ptHbb_denominator_r1", "Acceptance plot using the preselected_ptHbb variable; preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

TH1F *hist_acceptance_preselected_ptHbb_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_ptHbb_denominator_class0_r2", "Acceptance plot using the preselected_ptHbb variable (r_{2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_ptHbb_denominator_class1_r2", "Acceptance plot using the preselected_ptHbb variable (r_{2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_ptHbb_denominator_class2_r2", "Acceptance plot using the preselected_ptHbb variable (r_{2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_ptHbb_denominator_class3_r2", "Acceptance plot using the preselected_ptHbb variable (r_{2}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

TH1F *hist_acceptance_all_Bbb_preselected_ptHbb_numerator_r1_r2 = new TH1F("hist_acceptance_all_Bbb_preselected_ptHbb_numerator_r1_r2", "Acceptance plot using preselected_ptHbb variable (r_{1,2}); preselected p_{T}(H #rightarrow bb) [GeV]; Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

TH1F *hist_acceptance_all_Bbb_preselected_ptHbb_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Bbb_preselected_ptHbb_denominator_r2_numerator_r4", "Acceptance plot using preselected_ptHbb variable (r_{2,4}); preselected p_{T}(H #rightarrow bb) [GeV]; Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

//******************************************************
// Histograms for eta of preselected events truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_etaHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class0_r1_r2", "Acceptance plot using the preselected_etaHbb variable (r_{1,2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class1_r1_r2", "Acceptance plot using the preselected_etaHbb variable (r_{1,2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class2_r1_r2", "Acceptance plot using the preselected_etaHbb variable (r_{1,2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class3_r1_r2", "Acceptance plot using the preselected_etaHbb variable (r_{1,2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);

TH1F *hist_acceptance_preselected_etaHbb_denominator_r1 = new TH1F("hist_acceptance_preselected_etaHbb_denominator_r1", "Acceptance plot using the preselected_etaHbb variable; preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);

TH1F *hist_acceptance_preselected_etaHbb_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_etaHbb_denominator_class0_r2", "Acceptance plot using the preselected_etaHbb variable (r_{2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_etaHbb_denominator_class1_r2", "Acceptance plot using the preselected_etaHbb variable (r_{2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_etaHbb_denominator_class2_r2", "Acceptance plot using the preselected_etaHbb variable (r_{2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_etaHbb_denominator_class3_r2", "Acceptance plot using the preselected_etaHbb variable (r_{2}); preselected #eta(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);

//******************************************************
// Histograms for phi of preselected events truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_phiHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class0_r1_r2", "Acceptance plot using the preselected_phiHbb variable (r_{1,2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class1_r1_r2", "Acceptance plot using the preselected_phiHbb variable (r_{1,2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class2_r1_r2", "Acceptance plot using the preselected_phiHbb variable (r_{1,2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class3_r1_r2", "Acceptance plot using the preselected_phiHbb variable (r_{1,2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);

TH1F *hist_acceptance_preselected_phiHbb_denominator_r1 = new TH1F("hist_acceptance_preselected_phiHbb_denominator_r1", "Acceptance plot using the preselected_phiHbb variable; preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);

TH1F *hist_acceptance_preselected_phiHbb_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_phiHbb_denominator_class0_r2", "Acceptance plot using the preselected_phiHbb variable (r_{2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_phiHbb_denominator_class1_r2", "Acceptance plot using the preselected_phiHbb variable (r_{2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_phiHbb_denominator_class2_r2", "Acceptance plot using the preselected_phiHbb variable (r_{2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_phiHbb_denominator_class3_r2", "Acceptance plot using the preselected_phiHbb variable (r_{2}); preselected #phi(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);

//******************************************************
// Histograms for mass of preselected events truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_mHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class0_r1_r2", "Acceptance plot using the preselected_mHtautau variable (r_{1,2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class1_r1_r2", "Acceptance plot using the preselected_mHtautau variable (r_{1,2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class2_r1_r2", "Acceptance plot using the preselected_mHtautau variable (r_{1,2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class3_r1_r2", "Acceptance plot using the preselected_mHtautau variable (r_{1,2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

TH1F *hist_acceptance_preselected_mHtautau_denominator_r1 = new TH1F("hist_acceptance_preselected_mHtautau_denominator_r1", "Acceptance plot using the preselected_mHtautau variable; preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

TH1F *hist_acceptance_preselected_mHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_mHtautau_denominator_class0_r2", "Acceptance plot using the preselected_mHtautau variable (r_{2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_mHtautau_denominator_class1_r2", "Acceptance plot using the preselected_mHtautau variable (r_{2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_mHtautau_denominator_class2_r2", "Acceptance plot using the preselected_mHtautau variable (r_{2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_mHtautau_denominator_class3_r2", "Acceptance plot using the preselected_mHtautau variable (r_{2}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

TH1F *hist_acceptance_all_Btautau_preselected_mHtautau_numerator_r1_r2 = new TH1F("hist_acceptance_all_Btautau_preselected_mHtautau_numerator_r1_r2", "Acceptance plot using preselected_mHtautau variable (r_{1,2}); preselected m(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

TH1F *hist_acceptance_all_Btautau_preselected_mHtautau_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Btautau_preselected_mHtautau_denominator_r2_numerator_r4", "Acceptance plot using preselected_mHtautau variable (r_{2,4}); preselected m(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

//******************************************************
// Histograms for pT of preselected events truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_ptHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class0_r1_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class1_r1_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class2_r1_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class3_r1_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

TH1F *hist_acceptance_preselected_ptHtautau_denominator_r1 = new TH1F("hist_acceptance_preselected_ptHtautau_denominator_r1", "Acceptance plot using the preselected_ptHtautau variable; preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

TH1F *hist_acceptance_preselected_ptHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_denominator_class0_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_denominator_class1_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_denominator_class2_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_ptHtautau_denominator_class3_r2", "Acceptance plot using the preselected_ptHtautau variable (r_{2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

TH1F *hist_acceptance_all_Btautau_preselected_ptHtautau_numerator_r1_r2 = new TH1F("hist_acceptance_all_Btautau_preselected_ptHtautau_numerator_r1_r2", "Acceptance plot using preselected_ptHtautau variable (r_{1,2}); preselected p_{T}(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

TH1F *hist_acceptance_all_Btautau_preselected_ptHtautau_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Btautau_preselected_ptHtautau_denominator_r2_numerator_r4", "Acceptance plot using preselected_ptHtautau variable (r_{2,4}); preselected p_{T}(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

//******************************************************
// Histograms for eta of preselected events truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_etaHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class0_r1_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class1_r1_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class2_r1_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class3_r1_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{1,2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);

TH1F *hist_acceptance_preselected_etaHtautau_denominator_r1 = new TH1F("hist_acceptance_preselected_etaHtautau_denominator_r1", "Acceptance plot using the preselected_etaHtautau variable; preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);

TH1F *hist_acceptance_preselected_etaHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_denominator_class0_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_denominator_class1_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_denominator_class2_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_etaHtautau_denominator_class3_r2", "Acceptance plot using the preselected_etaHtautau variable (r_{2}); preselected #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);

//******************************************************
// Histograms for phi of preselected events truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_preselected_phiHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class0_r1_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class1_r1_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class2_r1_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class3_r1_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{1,2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);

TH1F *hist_acceptance_preselected_phiHtautau_denominator_r1 = new TH1F("hist_acceptance_preselected_phiHtautau_denominator_r1", "Acceptance plot using the preselected_phiHtautau variable; preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);

TH1F *hist_acceptance_preselected_phiHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_denominator_class0_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_denominator_class1_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_denominator_class2_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_preselected_phiHtautau_denominator_class3_r2", "Acceptance plot using the preselected_phiHtautau variable (r_{2}); preselected #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************
// Histograms for ratio_3 and ratio_4 for preselected events variables 
//******************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//******************************************************
// Histograms for mass of preselected events truth HH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_mHH_numerator_r3 = new TH1F("hist_acceptance_preselected_mHH_numerator_r3", "Acceptance plot using the preselected mHH variable (r_{3}); preselected m(HH) [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);

TH1F *hist_acceptance_preselected_mHH_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_mHH_denominator_r3_r4", "Acceptance plot using the preselected mHH variable (r_{3,4}); preselected m(HH) [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);

TH1F *hist_acceptance_preselected_mHH_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_mHH_numerator_class0_r4", "Acceptance plot using the preselected mHH variable (r_{4}); preselected m(HH) [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_mHH_numerator_class1_r4", "Acceptance plot using the preselected mHH variable (r_{4}); preselected m(HH) [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_mHH_numerator_class2_r4", "Acceptance plot using the preselected mHH variable (r_{4}); preselected m(HH) [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);
TH1F *hist_acceptance_preselected_mHH_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_mHH_numerator_class3_r4", "Acceptance plot using the preselected mHH variable (r_{4}); preselected m(HH) [GeV];Ratio", 35, x_min_preselected_mHH, x_max_preselected_mHH);


//******************************************************
// Histograms for pT of preselected events truth HH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_ptHH_numerator_r3 = new TH1F("hist_acceptance_preselected_ptHH_numerator_r3", "Acceptance plot using the preselected ptHH variable (r_{3}); preselected p_{T}(HH) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);

TH1F *hist_acceptance_preselected_ptHH_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_ptHH_denominator_r3_r4", "Acceptance plot using the preselected ptHH variable (r_{3,4}); preselected p_{T}(HH) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);

TH1F *hist_acceptance_preselected_ptHH_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class0_r4", "Acceptance plot using the preselected ptHH variable (r_{4}); preselected p_{T}(HH) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class1_r4", "Acceptance plot using the preselected ptHH variable (r_{4}); preselected p_{T}(HH) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class2_r4", "Acceptance plot using the preselected ptHH variable (r_{4}); preselected p_{T}(HH) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);
TH1F *hist_acceptance_preselected_ptHH_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_ptHH_numerator_class3_r4", "Acceptance plot using the preselected ptHH variable (r_{4}); preselected p_{T}(HH) [GeV];Ratio", 35, x_min_preselected_ptHH, x_max_preselected_ptHH);


//******************************************************
// Histograms for preselected events truth etaHH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_etaHH_numerator_r3 = new TH1F("hist_acceptance_preselected_etaHH_numerator_r3", "Acceptance plot using the preselected etaHH variable (r_{3}); preselected #eta(HH);Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);

TH1F *hist_acceptance_preselected_etaHH_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_etaHH_denominator_r3_r4", "Acceptance plot using the preselected etaHH variable (r_{3,4}); preselected #eta(HH);Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);

TH1F *hist_acceptance_preselected_etaHH_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class0_r4", "Acceptance plot using the preselected etaHH variable (r_{4}); preselected #eta(HH);Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class1_r4", "Acceptance plot using the preselected etaHH variable (r_{4}); preselected #eta(HH);Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class2_r4", "Acceptance plot using the preselected etaHH variable (r_{4}); preselected #eta(HH);Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);
TH1F *hist_acceptance_preselected_etaHH_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_etaHH_numerator_class3_r4", "Acceptance plot using the preselected etaHH variable (r_{4}); preselected #eta(HH);Ratio", 35, x_min_preselected_etaHH, x_max_preselected_etaHH);

//******************************************************
// Histograms for preselected events truth phiHH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_phiHH_numerator_r3 = new TH1F("hist_acceptance_preselected_phiHH_numerator_r3", "Acceptance plot using the preselected phiHH variable (r_{3}); preselected #phi(HH);Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);

TH1F *hist_acceptance_preselected_phiHH_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_phiHH_denominator_r3_r4", "Acceptance plot using the preselected phiHH variable (r_{3,4}); preselected #phi(HH);Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);

TH1F *hist_acceptance_preselected_phiHH_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class0_r4", "Acceptance plot using the preselected phiHH variable (r_{4}); preselected #phi(HH);Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class1_r4", "Acceptance plot using the preselected phiHH variable (r_{4}); preselected #phi(HH);Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class2_r4", "Acceptance plot using the preselected phiHH variable (r_{4}); preselected #phi(HH);Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);
TH1F *hist_acceptance_preselected_phiHH_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_phiHH_numerator_class3_r4", "Acceptance plot using the preselected phiHH variable (r_{4}); preselected #phi(HH);Ratio", 35, x_min_preselected_phiHH, x_max_preselected_phiHH);


//******************************************************
// Histograms for preselected events truth mHbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_mHbb_numerator_r3 = new TH1F("hist_acceptance_preselected_mHbb_numerator_r3", "Acceptance plot using the preselected mHbb variable (r_{3}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

TH1F *hist_acceptance_preselected_mHbb_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_mHbb_denominator_r3_r4", "Acceptance plot using the preselected mHbb variable (r_{3,4}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

TH1F *hist_acceptance_preselected_mHbb_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class0_r4", "Acceptance plot using the preselected mHbb variable (r_{4}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class1_r4", "Acceptance plot using the preselected mHbb variable (r_{4}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class2_r4", "Acceptance plot using the preselected mHbb variable (r_{4}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);
TH1F *hist_acceptance_preselected_mHbb_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_mHbb_numerator_class3_r4", "Acceptance plot using the preselected mHbb variable (r_{4}); preselected m(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_mHbb, x_max_preselected_mHbb);

//******************************************************
// Histograms for pT of preselected events truth Hbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_ptHbb_numerator_r3 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_r3", "Acceptance plot using the preselected ptHbb variable (r_{3}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

TH1F *hist_acceptance_preselected_ptHbb_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_ptHbb_denominator_r3_r4", "Acceptance plot using the preselected ptHbb variable (r_{3,4}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

TH1F *hist_acceptance_preselected_ptHbb_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class0_r4", "Acceptance plot using the preselected ptHbb variable (r_{4}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class1_r4", "Acceptance plot using the preselected ptHbb variable (r_{4}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class2_r4", "Acceptance plot using the preselected ptHbb variable (r_{4}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);
TH1F *hist_acceptance_preselected_ptHbb_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_ptHbb_numerator_class3_r4", "Acceptance plot using the preselected ptHbb variable (r_{4}); preselected p_{T}(H #rightarrow bb) [GeV];Ratio", 35, x_min_preselected_ptHbb, x_max_preselected_ptHbb);

//******************************************************
// Histograms for preselected events truth etaHbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_etaHbb_numerator_r3 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_r3", "Acceptance plot using the preselected etaHbb variable (r_{3}); preselected #eta(H #rightarrow bb);Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);

TH1F *hist_acceptance_preselected_etaHbb_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_etaHbb_denominator_r3_r4", "Acceptance plot using the preselected etaHbb variable (r_{3,4}); preselected #eta(H #rightarrow bb);Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);

TH1F *hist_acceptance_preselected_etaHbb_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class0_r4", "Acceptance plot using the preselected etaHbb variable (r_{4}); preselected #eta(H #rightarrow bb);Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class1_r4", "Acceptance plot using the preselected etaHbb variable (r_{4}); preselected #eta(H #rightarrow bb);Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class2_r4", "Acceptance plot using the preselected etaHbb variable (r_{4}); preselected #eta(H #rightarrow bb);Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);
TH1F *hist_acceptance_preselected_etaHbb_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_etaHbb_numerator_class3_r4", "Acceptance plot using the preselected etaHbb variable (r_{4}); preselected #eta(H #rightarrow bb);Ratio", 35, x_min_preselected_etaHbb, x_max_preselected_etaHbb);

//******************************************************
// Histograms for preselected events truth phiHbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_phiHbb_numerator_r3 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_r3", "Acceptance plot using the preselected phiHbb variable (r_{3}); preselected #phi(H #rightarrow bb);Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);

TH1F *hist_acceptance_preselected_phiHbb_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_phiHbb_denominator_r3_r4", "Acceptance plot using the preselected phiHbb variable (r_{3,4}); preselected #phi(H #rightarrow bb);Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);

TH1F *hist_acceptance_preselected_phiHbb_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class0_r4", "Acceptance plot using the preselected phiHbb variable (r_{4}); preselected #phi(H #rightarrow bb);Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class1_r4", "Acceptance plot using the preselected phiHbb variable (r_{4}); preselected #phi(H #rightarrow bb);Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class2_r4", "Acceptance plot using the preselected phiHbb variable (r_{4}); preselected #phi(H #rightarrow bb);Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);
TH1F *hist_acceptance_preselected_phiHbb_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_phiHbb_numerator_class3_r4", "Acceptance plot using the preselected phiHbb variable (r_{4}); preselected #phi(H #rightarrow bb);Ratio", 35, x_min_preselected_phiHbb, x_max_preselected_phiHbb);

//******************************************************
// Histograms for mass of preselected events truth Htautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_mHtautau_numerator_r3 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_r3", "Acceptance plot using the preselected mHtautau variable (r_{3}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

TH1F *hist_acceptance_preselected_mHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_mHtautau_denominator_r3_r4", "Acceptance plot using the preselected mHtautau variable (r_{3,4}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);

TH1F *hist_acceptance_preselected_mHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class0_r4", "Acceptance plot using the preselected mHtautau variable (r_{4}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class1_r4", "Acceptance plot using the preselected mHtautau variable (r_{4}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class2_r4", "Acceptance plot using the preselected mHtautau variable (r_{4}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);
TH1F *hist_acceptance_preselected_mHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_mHtautau_numerator_class3_r4", "Acceptance plot using the preselected mHtautau variable (r_{4}); preselected m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_mHtautau, x_max_preselected_mHtautau);


//******************************************************
// Histograms for pT of preselected events truth Htautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_ptHtautau_numerator_r3 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_r3", "Acceptance plot using the preselected ptHtautau variable (r_{3}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

TH1F *hist_acceptance_preselected_ptHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_ptHtautau_denominator_r3_r4", "Acceptance plot using the preselected ptHtautau variable (r_{3,4}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);

TH1F *hist_acceptance_preselected_ptHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class0_r4", "Acceptance plot using the preselected ptHtautau variable (r_{4}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class1_r4", "Acceptance plot using the preselected ptHtautau variable (r_{4}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class2_r4", "Acceptance plot using the preselected ptHtautau variable (r_{4}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);
TH1F *hist_acceptance_preselected_ptHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_ptHtautau_numerator_class3_r4", "Acceptance plot using the preselected ptHtautau variable (r_{4}); preselected p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_preselected_ptHtautau, x_max_preselected_ptHtautau);


//******************************************************
// Histograms for preselected events truth etaHtautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_etaHtautau_numerator_r3 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_r3", "Acceptance plot using the preselected #eta(H #rightarrow #tau#tau) variable (r_{3}); preselected #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);

TH1F *hist_acceptance_preselected_etaHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_etaHtautau_denominator_r3_r4", "Acceptance plot using the preselected #eta(H #rightarrow #tau#tau) variable (r_{3,4}); preselected #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);

TH1F *hist_acceptance_preselected_etaHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class0_r4", "Acceptance plot using the preselected #eta(H #rightarrow #tau#tau) variable (r_{4}); preselected #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class1_r4", "Acceptance plot using the preselected #eta(H #rightarrow #tau#tau) variable (r_{4}); preselected #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class2_r4", "Acceptance plot using the preselected #eta(H #rightarrow #tau#tau) variable (r_{4}); preselected #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);
TH1F *hist_acceptance_preselected_etaHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_etaHtautau_numerator_class3_r4", "Acceptance plot using the preselected #eta(H #rightarrow #tau#tau) variable (r_{4}); preselected #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_etaHtautau, x_max_preselected_etaHtautau);

//******************************************************
// Histograms for preselected events truth phiHtautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_preselected_phiHtautau_numerator_r3 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_r3", "Acceptance plot using the preselected #phi(H #rightarrow #tau#tau) variable (r_{3}); preselected #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);

TH1F *hist_acceptance_preselected_phiHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_preselected_phiHtautau_denominator_r3_r4", "Acceptance plot using the preselected #phi(H #rightarrow #tau#tau) variable (r_{3,4}); preselected #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);

TH1F *hist_acceptance_preselected_phiHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class0_r4", "Acceptance plot using the preselected #phi(H #rightarrow #tau#tau) variable (r_{4}); preselected #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class1_r4", "Acceptance plot using the preselected #phi(H #rightarrow #tau#tau) variable (r_{4}); preselected #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class2_r4", "Acceptance plot using the preselected #phi(H #rightarrow #tau#tau) variable (r_{4}); preselected #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
TH1F *hist_acceptance_preselected_phiHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_preselected_phiHtautau_numerator_class3_r4", "Acceptance plot using the preselected #phi(H #rightarrow #tau#tau) variable (r_{4}); preselected #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_preselected_phiHtautau, x_max_preselected_phiHtautau);
