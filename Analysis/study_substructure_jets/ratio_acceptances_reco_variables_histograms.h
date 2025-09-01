// *************************************
// Declaration of x limits for histograms
// *************************************

float x_min_mHH = 200.0;
float x_max_mHH = 2000.0;

float x_min_ptHH = 200.0;
float x_max_ptHH = 1000.0;

float x_min_mHbb = 0.0;
float x_max_mHbb = 400.0;

float x_min_ptHbb = 0.0;
float x_max_ptHbb = 1000.0;

float x_min_mHtautau = 0.0;
float x_max_mHtautau = 400.0;

float x_min_ptHtautau = 0.0;
float x_max_ptHtautau = 1000.0;

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

TH1F *hist_acceptance_all_Bbb_mHbb_numerator_r1_r2 = new TH1F("hist_acceptance_all_Bbb_mHbb_numerator_r1_r2", "Acceptance plot using mHbb variable (r_{1,2}); m(H #rightarrow bb) [GeV]; Ratio", 35, x_min_mHbb, x_max_mHbb);

TH1F *hist_acceptance_all_Bbb_mHbb_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Bbb_mHbb_denominator_r2_numerator_r4", "Acceptance plot using mHbb variable (r_{2,4}); m(H #rightarrow bb) [GeV]; Ratio", 35, x_min_mHbb, x_max_mHbb);

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

TH1F *hist_acceptance_all_Btautau_mHtautau_numerator_r1_r2 = new TH1F("hist_acceptance_all_Btautau_mHtautau_numerator_r1_r2", "Acceptance plot using mHtautau variable (r_{1,2}); m(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_mHtautau, x_max_mHtautau);

TH1F *hist_acceptance_all_Btautau_mHtautau_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Btautau_mHtautau_denominator_r2_numerator_r4", "Acceptance plot using mHtautau variable (r_{2,4}); m(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_mHtautau, x_max_mHtautau);

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

TH1F *hist_acceptance_all_Bbb_ptHbb_numerator_r1_r2 = new TH1F("hist_acceptance_all_Bbb_ptHbb_numerator_r1_r2", "Acceptance plot using ptHbb variable (r_{1,2}); p_{T}(H #rightarrow bb) [GeV]; Ratio", 35, x_min_ptHbb, x_max_ptHbb);

TH1F *hist_acceptance_all_Bbb_ptHbb_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Bbb_ptHbb_denominator_r2_numerator_r4", "Acceptance plot using ptHbb variable (r_{2,4}); p_{T}(H #rightarrow bb) [GeV]; Ratio", 35, x_min_ptHbb, x_max_ptHbb);

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

TH1F *hist_acceptance_all_Btautau_ptHtautau_numerator_r1_r2 = new TH1F("hist_acceptance_all_Btautau_ptHtautau_numerator_r1_r2", "Acceptance plot using ptHtautau variable (r_{1,2}); p_{T}(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

TH1F *hist_acceptance_all_Btautau_ptHtautau_denominator_r2_numerator_r4 = new TH1F("hist_acceptance_all_Btautau_ptHtautau_denominator_r2_numerator_r4", "Acceptance plot using ptHtautau variable (r_{2,4}); p_{T}(H #rightarrow #tau#tau) [GeV]; Ratio", 35, x_min_ptHtautau, x_max_ptHtautau);

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
