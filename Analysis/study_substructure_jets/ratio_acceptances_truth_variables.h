// *************************************
// Declaration of x limits for histograms
// *************************************

float x_min_truth_mHH = 200.0;
float x_max_truth_mHH = 1500.0;
float x_min_truth_ptHH = 200.0;
float x_max_truth_ptHH = 1000.0;
float x_min_truth_etaHH = -5.0;
float x_max_truth_etaHH = 5.0;
float x_min_truth_phiHH = -5.0;
float x_max_truth_phiHH = 5.0;

float x_min_truth_mHbb = 0.0;
float x_max_truth_mHbb = 400.0;
float x_min_truth_ptHbb = 0.0;
float x_max_truth_ptHbb = 1000.0;
float x_min_truth_etaHbb = -5.0;
float x_max_truth_etaHbb = 5.0;
float x_min_truth_phiHbb = -5.0;
float x_max_truth_phiHbb = 5.0;

float x_min_truth_mHtautau = 0.0;
float x_max_truth_mHtautau = 400.0;
float x_min_truth_ptHtautau = 0.0;
float x_max_truth_ptHtautau = 1000.0;
float x_min_truth_etaHtautau = -5.0;
float x_max_truth_etaHtautau = 5.0;
float x_min_truth_phiHtautau = -5.0;
float x_max_truth_phiHtautau = 5.0;

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

TH1F *hist_acceptance_truth_ptHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class0_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class1_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class2_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_ptHH_numerator_class3_r1_r2", "Acceptance plot using the truth_ptHH variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

TH1F *hist_acceptance_truth_ptHH_denominator_r1 = new TH1F("hist_acceptance_truth_ptHH_denominator_r1", "Acceptance plot using the truth_ptHH variable; Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

TH1F *hist_acceptance_truth_ptHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class0_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class1_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class2_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_ptHH_denominator_class3_r2", "Acceptance plot using the truth_ptHH variable (r_{2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

//******************************************************
// Histograms for eta of truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_etaHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class0_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class1_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class2_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_etaHH_numerator_class3_r1_r2", "Acceptance plot using the truth_etaHH variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

TH1F *hist_acceptance_truth_etaHH_denominator_r1 = new TH1F("hist_acceptance_truth_etaHH_denominator_r1", "Acceptance plot using the truth_etaHH variable; Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

TH1F *hist_acceptance_truth_etaHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class0_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class1_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class2_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_etaHH_denominator_class3_r2", "Acceptance plot using the truth_etaHH variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

//******************************************************
// Histograms for phi of truth HH cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_phiHH_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class0_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class1_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class2_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_phiHH_numerator_class3_r1_r2", "Acceptance plot using the truth_phiHH variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

TH1F *hist_acceptance_truth_phiHH_denominator_r1 = new TH1F("hist_acceptance_truth_phiHH_denominator_r1", "Acceptance plot using the truth_phiHH variable; Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

TH1F *hist_acceptance_truth_phiHH_denominator_class0_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class0_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_denominator_class1_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class1_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_denominator_class2_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class2_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_denominator_class3_r2 = new TH1F("hist_acceptance_truth_phiHH_denominator_class3_r2", "Acceptance plot using the truth_phiHH variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

//******************************************************
// Histograms for mass of truth bb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_mHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_mHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_mHbb variable (r_{1,2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_truth_mHbb_denominator_r1 = new TH1F("hist_acceptance_truth_mHbb_denominator_r1", "Acceptance plot using the truth_mHbb variable; Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_truth_mHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class0_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class1_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class2_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_mHbb_denominator_class3_r2", "Acceptance plot using the truth_mHbb variable (r_{2}); Truth m(H #rightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_all_Bbb_truth_mHbb_numerator_r1_r2 = new TH1F("hist_acceptance_all_Bbb_truth_mHbb_numerator_r1_r2", "Acceptance plot using truth_mHbb variable (r_{1,2}); Truth m(H #rightarrow bb) [GeV]; Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_all_Bbb_truth_mHbb_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Bbb_truth_mHbb_denominator_r2_numerator_r4", "Acceptance plot using truth_mHbb variable (r_{2,4}); Truth m(H #rightarrow bb) [GeV]; Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

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

TH1F *hist_acceptance_all_Bbb_truth_ptHbb_numerator_r1_r2 = new TH1F("hist_acceptance_all_Bbb_truth_ptHbb_numerator_r1_r2", "Acceptance plot using truth_ptHbb variable (r_{1,2}); Truth p_{T}(H #rightarrow bb) [GeV]; Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

TH1F *hist_acceptance_all_Bbb_truth_ptHbb_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Bbb_truth_ptHbb_denominator_r2_numerator_r4", "Acceptance plot using truth_ptHbb variable (r_{2,4}); Truth p_{T}(H #rightarrow bb) [GeV]; Ratio", 35, x_min_truth_ptHbb, x_max_truth_ptHbb);

//******************************************************
// Histograms for eta of truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_etaHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_etaHbb variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

TH1F *hist_acceptance_truth_etaHbb_denominator_r1 = new TH1F("hist_acceptance_truth_etaHbb_denominator_r1", "Acceptance plot using the truth_etaHbb variable; Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

TH1F *hist_acceptance_truth_etaHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class0_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class1_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class2_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_etaHbb_denominator_class3_r2", "Acceptance plot using the truth_etaHbb variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

//******************************************************
// Histograms for phi of truth Hbb cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_phiHbb_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class0_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class1_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class2_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class3_r1_r2", "Acceptance plot using the truth_phiHbb variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

TH1F *hist_acceptance_truth_phiHbb_denominator_r1 = new TH1F("hist_acceptance_truth_phiHbb_denominator_r1", "Acceptance plot using the truth_phiHbb variable; Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

TH1F *hist_acceptance_truth_phiHbb_denominator_class0_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class0_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_denominator_class1_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class1_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_denominator_class2_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class2_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_denominator_class3_r2 = new TH1F("hist_acceptance_truth_phiHbb_denominator_class3_r2", "Acceptance plot using the truth_phiHbb variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

//******************************************************
// Histograms for mass of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_mHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_mHtautau variable (r_{1,2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_truth_mHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_mHtautau_denominator_r1", "Acceptance plot using the truth_mHtautau variable; Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_truth_mHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class0_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class1_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class2_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_mHtautau_denominator_class3_r2", "Acceptance plot using the truth_mHtautau variable (r_{2}); Truth m(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_all_Btautau_truth_mHtautau_numerator_r1_r2 = new TH1F("hist_acceptance_all_Btautau_truth_mHtautau_numerator_r1_r2", "Acceptance plot using truth_mHtautau variable (r_{1,2}); Truth m(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_all_Btautau_truth_mHtautau_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Btautau_truth_mHtautau_denominator_r2_numerator_r4", "Acceptance plot using truth_mHtautau variable (r_{2,4}); Truth m(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

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

TH1F *hist_acceptance_all_Btautau_truth_ptHtautau_numerator_r1_r2 = new TH1F("hist_acceptance_all_Btautau_truth_ptHtautau_numerator_r1_r2", "Acceptance plot using truth_ptHtautau variable (r_{1,2}); Truth p_{T}(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_all_Btautau_truth_ptHtautau_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Btautau_truth_ptHtautau_denominator_r2_numerator_r4", "Acceptance plot using truth_ptHtautau variable (r_{2,4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

//******************************************************
// Histograms for eta of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_etaHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{1,2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

TH1F *hist_acceptance_truth_etaHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_r1", "Acceptance plot using the truth_etaHtautau variable; Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

TH1F *hist_acceptance_truth_etaHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class0_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class1_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class2_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_class3_r2", "Acceptance plot using the truth_etaHtautau variable (r_{2}); Truth #eta(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

//******************************************************
// Histograms for phi of truth Htautau cuts ratio_1 and ratio_2
//******************************************************

TH1F *hist_acceptance_truth_phiHtautau_numerator_class0_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class0_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class1_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class1_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class2_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class2_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{1,2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

TH1F *hist_acceptance_truth_phiHtautau_denominator_r1 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_r1", "Acceptance plot using the truth_phiHtautau variable; Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

TH1F *hist_acceptance_truth_phiHtautau_denominator_class0_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class0_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_denominator_class1_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class1_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_denominator_class2_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class2_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_denominator_class3_r2 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_class3_r2", "Acceptance plot using the truth_phiHtautau variable (r_{2}); Truth #phi(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

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
// Histograms for pT of truth HH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_ptHH_numerator_r3 = new TH1F("hist_acceptance_truth_ptHH_numerator_r3", "Acceptance plot using the truth ptHH variable (r_{3}); Truth p_{T}(HH) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

TH1F *hist_acceptance_truth_ptHH_denominator_r3_r4 = new TH1F("hist_acceptance_truth_ptHH_denominator_r3_r4", "Acceptance plot using the truth ptHH variable (r_{3,4}); Truth p_{T}(HH) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);

TH1F *hist_acceptance_truth_ptHH_numerator_class0_r4 = new TH1F("hist_acceptance_truth_ptHH_numerator_class0_r4", "Acceptance plot using the truth ptHH variable (r_{4}); Truth p_{T}(HH) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class1_r4 = new TH1F("hist_acceptance_truth_ptHH_numerator_class1_r4", "Acceptance plot using the truth ptHH variable (r_{4}); Truth p_{T}(HH) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class2_r4 = new TH1F("hist_acceptance_truth_ptHH_numerator_class2_r4", "Acceptance plot using the truth ptHH variable (r_{4}); Truth p_{T}(HH) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);
TH1F *hist_acceptance_truth_ptHH_numerator_class3_r4 = new TH1F("hist_acceptance_truth_ptHH_numerator_class3_r4", "Acceptance plot using the truth ptHH variable (r_{4}); Truth p_{T}(HH) [GeV];Ratio", 35, x_min_truth_ptHH, x_max_truth_ptHH);


//******************************************************
// Histograms for truth etaHH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_etaHH_numerator_r3 = new TH1F("hist_acceptance_truth_etaHH_numerator_r3", "Acceptance plot using the truth etaHH variable (r_{3}); Truth #eta(HH);Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

TH1F *hist_acceptance_truth_etaHH_denominator_r3_r4 = new TH1F("hist_acceptance_truth_etaHH_denominator_r3_r4", "Acceptance plot using the truth etaHH variable (r_{3,4}); Truth #eta(HH);Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

TH1F *hist_acceptance_truth_etaHH_numerator_class0_r4 = new TH1F("hist_acceptance_truth_etaHH_numerator_class0_r4", "Acceptance plot using the truth etaHH variable (r_{4}); Truth #eta(HH);Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class1_r4 = new TH1F("hist_acceptance_truth_etaHH_numerator_class1_r4", "Acceptance plot using the truth etaHH variable (r_{4}); Truth #eta(HH);Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class2_r4 = new TH1F("hist_acceptance_truth_etaHH_numerator_class2_r4", "Acceptance plot using the truth etaHH variable (r_{4}); Truth #eta(HH);Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);
TH1F *hist_acceptance_truth_etaHH_numerator_class3_r4 = new TH1F("hist_acceptance_truth_etaHH_numerator_class3_r4", "Acceptance plot using the truth etaHH variable (r_{4}); Truth #eta(HH);Ratio", 35, x_min_truth_etaHH, x_max_truth_etaHH);

//******************************************************                                                                                                      
// Histograms for truth phiHH cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_phiHH_numerator_r3 = new TH1F("hist_acceptance_truth_phiHH_numerator_r3", "Acceptance plot using the truth phiHH variable (r_{3}); Truth #phi(HH);Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

TH1F *hist_acceptance_truth_phiHH_denominator_r3_r4 = new TH1F("hist_acceptance_truth_phiHH_denominator_r3_r4", "Acceptance plot using the truth phiHH variable (r_{3,4}); Truth #phi(HH);Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);

TH1F *hist_acceptance_truth_phiHH_numerator_class0_r4 = new TH1F("hist_acceptance_truth_phiHH_numerator_class0_r4", "Acceptance plot using the truth phiHH variable (r_{4}); Truth #phi(HH);Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class1_r4 = new TH1F("hist_acceptance_truth_phiHH_numerator_class1_r4", "Acceptance plot using the truth phiHH variable (r_{4}); Truth #phi(HH);Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class2_r4 = new TH1F("hist_acceptance_truth_phiHH_numerator_class2_r4", "Acceptance plot using the truth phiHH variable (r_{4}); Truth #phi(HH);Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);
TH1F *hist_acceptance_truth_phiHH_numerator_class3_r4 = new TH1F("hist_acceptance_truth_phiHH_numerator_class3_r4", "Acceptance plot using the truth phiHH variable (r_{4}); Truth #phi(HH);Ratio", 35, x_min_truth_phiHH, x_max_truth_phiHH);


//******************************************************
// Histograms for truth mHbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_mHbb_numerator_r3 = new TH1F("hist_acceptance_truth_mHbb_numerator_r3", "Acceptance plot using the truth mHbb variable (r_{3}); Truth m(H #rightarrow bb) \
[GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_truth_mHbb_denominator_r3_r4 = new TH1F("hist_acceptance_truth_mHbb_denominator_r3_r4", "Acceptance plot using the truth mHbb variable (r_{3,4}); Truth m(H #rig\
htarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

TH1F *hist_acceptance_truth_mHbb_numerator_class0_r4 = new TH1F("hist_acceptance_truth_mHbb_numerator_class0_r4", "Acceptance plot using the truth mHbb variable (r_{4}); Truth m(H #r\
ightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class1_r4 = new TH1F("hist_acceptance_truth_mHbb_numerator_class1_r4", "Acceptance plot using the truth mHbb variable (r_{4}); Truth m(H #r\
ightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class2_r4 = new TH1F("hist_acceptance_truth_mHbb_numerator_class2_r4", "Acceptance plot using the truth mHbb variable (r_{4}); Truth m(H #r\
ightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);
TH1F *hist_acceptance_truth_mHbb_numerator_class3_r4 = new TH1F("hist_acceptance_truth_mHbb_numerator_class3_r4", "Acceptance plot using the truth mHbb variable (r_{4}); Truth m(H #r\
ightarrow bb) [GeV];Ratio", 35, x_min_truth_mHbb, x_max_truth_mHbb);

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
// Histograms for truth etaHbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_etaHbb_numerator_r3 = new TH1F("hist_acceptance_truth_etaHbb_numerator_r3", "Acceptance plot using the truth etaHbb variable (r_{3}); Truth #eta(H #rightarrow bb);Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

TH1F *hist_acceptance_truth_etaHbb_denominator_r3_r4 = new TH1F("hist_acceptance_truth_etaHbb_denominator_r3_r4", "Acceptance plot using the truth etaHbb variable (r_{3,4}); Truth #eta(H #rightarrow bb);Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

TH1F *hist_acceptance_truth_etaHbb_numerator_class0_r4 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class0_r4", "Acceptance plot using the truth etaHbb variable (r_{4}); Truth #eta(H #rightarrow bb);Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class1_r4 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class1_r4", "Acceptance plot using the truth etaHbb variable (r_{4}); Truth #eta(H #rightarrow bb);Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class2_r4 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class2_r4", "Acceptance plot using the truth etaHbb variable (r_{4}); Truth #eta(H #rightarrow bb);Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);
TH1F *hist_acceptance_truth_etaHbb_numerator_class3_r4 = new TH1F("hist_acceptance_truth_etaHbb_numerator_class3_r4", "Acceptance plot using the truth etaHbb variable (r_{4}); Truth #eta(H #rightarrow bb);Ratio", 35, x_min_truth_etaHbb, x_max_truth_etaHbb);

//******************************************************
// Histograms for truth phiHbb cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_phiHbb_numerator_r3 = new TH1F("hist_acceptance_truth_phiHbb_numerator_r3", "Acceptance plot using the truth phiHbb variable (r_{3}); Truth #phi(H #rightarrow bb);Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

TH1F *hist_acceptance_truth_phiHbb_denominator_r3_r4 = new TH1F("hist_acceptance_truth_phiHbb_denominator_r3_r4", "Acceptance plot using the truth phiHbb variable (r_{3,4}); Truth #phi(H #rightarrow bb);Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

TH1F *hist_acceptance_truth_phiHbb_numerator_class0_r4 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class0_r4", "Acceptance plot using the truth phiHbb variable (r_{4}); Truth #phi(H #rightarrow bb);Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class1_r4 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class1_r4", "Acceptance plot using the truth phiHbb variable (r_{4}); Truth #phi(H #rightarrow bb);Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class2_r4 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class2_r4", "Acceptance plot using the truth phiHbb variable (r_{4}); Truth #phi(H #rightarrow bb);Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);
TH1F *hist_acceptance_truth_phiHbb_numerator_class3_r4 = new TH1F("hist_acceptance_truth_phiHbb_numerator_class3_r4", "Acceptance plot using the truth phiHbb variable (r_{4}); Truth #phi(H #rightarrow bb);Ratio", 35, x_min_truth_phiHbb, x_max_truth_phiHbb);

//******************************************************
// Histograms for mass of truth Htautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_mHtautau_numerator_r3 = new TH1F("hist_acceptance_truth_mHtautau_numerator_r3", "Acceptance plot using the truth mHtautau variable (r_{3}); Truth m(H # rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_truth_mHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_truth_mHtautau_denominator_r3_r4", "Acceptance plot using the truth mHtautau variable (r_{3,4}); Truth m(H # rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);

TH1F *hist_acceptance_truth_mHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class0_r4", "Acceptance plot using the truth mHtautau variable (r_{4}); Truth m(H # rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class1_r4", "Acceptance plot using the truth mHtautau variable (r_{4}); Truth m(H # rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class2_r4", "Acceptance plot using the truth mHtautau variable (r_{4}); Truth m(H # rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);
TH1F *hist_acceptance_truth_mHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_truth_mHtautau_numerator_class3_r4", "Acceptance plot using the truth mHtautau variable (r_{4}); Truth m(H # rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_mHtautau, x_max_truth_mHtautau);


//******************************************************
// Histograms for pT of truth Htautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_ptHtautau_numerator_r3 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_r3", "Acceptance plot using the truth ptHtautau variable (r_{3}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_truth_ptHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_truth_ptHtautau_denominator_r3_r4", "Acceptance plot using the truth ptHtautau variable (r_{3,4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);

TH1F *hist_acceptance_truth_ptHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class0_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class1_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class2_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);
TH1F *hist_acceptance_truth_ptHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_truth_ptHtautau_numerator_class3_r4", "Acceptance plot using the truth ptHtautau variable (r_{4}); Truth p_{T}(H #rightarrow #tau#tau) [GeV];Ratio", 35, x_min_truth_ptHtautau, x_max_truth_ptHtautau);


//******************************************************
// Histograms for truth etaHtautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_etaHtautau_numerator_r3 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_r3", "Acceptance plot using the truth #eta(H #rightarrow #tau#tau) variable (r_{3}); Truth #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

TH1F *hist_acceptance_truth_etaHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_truth_etaHtautau_denominator_r3_r4", "Acceptance plot using the truth #eta(H #rightarrow #tau#tau) variable (r_{3,4}); Truth #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

TH1F *hist_acceptance_truth_etaHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class0_r4", "Acceptance plot using the truth #eta(H #rightarrow #tau#tau) variable (r_{4}); Truth #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class1_r4", "Acceptance plot using the truth #eta(H #rightarrow #tau#tau) variable (r_{4}); Truth #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class2_r4", "Acceptance plot using the truth #eta(H #rightarrow #tau#tau) variable (r_{4}); Truth #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);
TH1F *hist_acceptance_truth_etaHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_truth_etaHtautau_numerator_class3_r4", "Acceptance plot using the truth #eta(H #rightarrow #tau#tau) variable (r_{4}); Truth #eta(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_etaHtautau, x_max_truth_etaHtautau);

//******************************************************
// Histograms for truth phiHtautau cuts ratio_3 and ratio_4
//******************************************************

TH1F *hist_acceptance_truth_phiHtautau_numerator_r3 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_r3", "Acceptance plot using the truth #phi(H #rightarrow #tau#tau) variable (r_{3}); Truth #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

TH1F *hist_acceptance_truth_phiHtautau_denominator_r3_r4 = new TH1F("hist_acceptance_truth_phiHtautau_denominator_r3_r4", "Acceptance plot using the truth #phi(H #rightarrow #tau#tau) variable (r_{3,4}); Truth #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);

TH1F *hist_acceptance_truth_phiHtautau_numerator_class0_r4 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class0_r4", "Acceptance plot using the truth #phi(H #rightarrow #tau#tau) variable (r_{4}); Truth #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class1_r4 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class1_r4", "Acceptance plot using the truth #phi(H #rightarrow #tau#tau) variable (r_{4}); Truth #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class2_r4 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class2_r4", "Acceptance plot using the truth #phi(H #rightarrow #tau#tau) variable (r_{4}); Truth #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
TH1F *hist_acceptance_truth_phiHtautau_numerator_class3_r4 = new TH1F("hist_acceptance_truth_phiHtautau_numerator_class3_r4", "Acceptance plot using the truth #phi(H #rightarrow #tau#tau) variable (r_{4}); Truth #phi(H #rightarrow #tau#tau);Ratio", 35, x_min_truth_phiHtautau, x_max_truth_phiHtautau);
