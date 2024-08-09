#include "declaration_of_variables.h"

// *************************************
// Declaration of functions
// *************************************

void process_label(TString name_sample);
void fill_acceptance_ratios();
void define_reconstructed_objects();
void define_output_branches();
void define_classes();
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m);
void define_truth_tau_and_b_jets();
void fill_histograms();
void set_branch_address_inTree(TTree *inTree);
void define_output_branches(TTree *outTree);
void print_list_of_branches(TTree* tree);


// *************************************
// Definition of the functions declared above
// *************************************

void process_label(TString name_sample){

  // ggF processes had-had channel
  if(name_sample.Contains("600459")==true){ process_name = "ggF HH SM had-had channel"; name_output_root_file = "ggF_SM_hh_600459.root";}
  if(name_sample.Contains("600460")==true){ process_name = "ggF HH #lambda = 10 had-had channel"; name_output_root_file = "ggF_lambda10_hh_600460.root";}

  // ggF processes lep-had channel
  if(name_sample.Contains("600461")==true){ process_name = "ggF HH SM lep-had channel"; name_output_root_file = "ggF_SM_lh_600461.root";}
  if(name_sample.Contains("600462")==true){ process_name = "ggF HH #lambda = 10 lep-had channel"; name_output_root_file = "ggF_lambda10_lh_600462.root";}

  //vbf processes had-had channel
  if(name_sample.Contains("502982")==true){ process_name = "VBF HH SM had-had channel"; name_output_root_file = "VBF_SM_hh_502982.root";}
  if(name_sample.Contains("502985")==true){ process_name = "VBF HH C_{VV} = 1.5 had-had channel"; name_output_root_file = "VBF_cvv1p5_hh_502985.root";}
  if(name_sample.Contains("502989")==true){ process_name = "VBF HH #lambda = 2.0 had-had channel"; name_output_root_file = "VBF_l2_hh_502989.root";}
  if(name_sample.Contains("502990")==true){ process_name = "VBF HH #lambda = 10.0 had-had channel"; name_output_root_file = "VBF_l10_hh_502990.root";}
  if(name_sample.Contains("502991")==true){ process_name = "VBF HH C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_cv0p5_hh_502991.root";}
  if(name_sample.Contains("508690")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_l5cv0p5_hh_508690.root";}

  //vbf processes lep-had channel
  if(name_sample.Contains("502993")==true){ process_name = "VBF HH SM lep-had channel"; name_output_root_file = "VBF_SM_lh_502993.root";}
  if(name_sample.Contains("502996")==true){ process_name = "VBF HH C_{VV} = 1.5 lep-had channel"; name_output_root_file = "VBF_cvv1p5_lh_502996.root";}
  if(name_sample.Contains("503000")==true){ process_name = "VBF HH #lambda = 2.0 lep-had channel"; name_output_root_file = "VBF_l2_lh_503000.root";}
  if(name_sample.Contains("503001")==true){ process_name = "VBF HH #lambda = 10.0 lep-had channel"; name_output_root_file = "VBF_l10_lh_503001.root";}
  if(name_sample.Contains("503002")==true){ process_name = "VBF HH C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_cv0p5_lh_503002.root";}
  if(name_sample.Contains("508691")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_l5cv0p5_lh_508691.root";}

  //vbf SM processes both channels channel
  if(name_sample.Contains("vbf_SM_both_channels")==true){ process_name = "VBF HH SM"; }

  //vbf SM processes both channels channel
  if(name_sample.Contains("ggf_SM_both_channels")==true){ process_name = "ggF HH SM"; }

  //vbf Cvv=1.5 processes both channels channel
  if(name_sample.Contains("vbf_l1cvv1p5cv1_both_channels")==true){ process_name = "VBF HH C_{VV} = 1.5"; }

  //ggf cHHH = 10 processes both channels channel
  if(name_sample.Contains("ggf_cHHH10d0_both_channels")==true){ process_name = "ggF HH #lambda = 10"; }
}

void fill_acceptance_ratios(){

  hist_acceptance_mHH_denominator_r3_r4->Fill(reco_bbtt_HH_m_BA);
  hist_acceptance_ptHbb_denominator_r3_r4->Fill(reco_bbtt_bb_pt_BA);
  hist_acceptance_ptHtautau_denominator_r3_r4->Fill(reco_bbtt_tautau_pt_BA);
  
  hist_acceptance_truth_mHH_denominator_r3_r4->Fill(truth_HH_m/1000.);
  hist_acceptance_truth_ptHbb_denominator_r3_r4->Fill(truth_bb_pt);
  hist_acceptance_truth_ptHtautau_denominator_r3_r4->Fill(truth_tautau_pt);
  
  if(bbtt_HH_vis_m > 0){

    hist_acceptance_mHH_denominator_r1->Fill(reco_bbtt_HH_m_BA);
    hist_acceptance_mHbb_denominator_r1->Fill(reco_bbtt_bb_m_BA);
    hist_acceptance_mHtautau_denominator_r1->Fill(reco_bbtt_tautau_m_BA);
    hist_acceptance_ptHH_denominator_r1->Fill(reco_bbtt_HH_pt_BA);
    hist_acceptance_ptHbb_denominator_r1->Fill(reco_bbtt_bb_pt_BA);
    hist_acceptance_ptHtautau_denominator_r1->Fill(reco_bbtt_tautau_pt_BA);

    hist_acceptance_truth_mHH_denominator_r1->Fill(truth_HH_m/1000.);
    hist_acceptance_truth_mHbb_denominator_r1->Fill(truth_bb_m);
    hist_acceptance_truth_mHtautau_denominator_r1->Fill(truth_tautau_m);
    hist_acceptance_truth_ptHH_denominator_r1->Fill(truth_HH_pt);
    hist_acceptance_truth_ptHbb_denominator_r1->Fill(truth_bb_pt);
    hist_acceptance_truth_ptHtautau_denominator_r1->Fill(truth_tautau_pt); 

    hist_acceptance_mHH_numerator_r3->Fill(reco_bbtt_HH_m_BA);
    hist_acceptance_ptHbb_numerator_r3->Fill(reco_bbtt_bb_pt_BA);
    hist_acceptance_ptHtautau_numerator_r3->Fill(reco_bbtt_tautau_pt_BA);
    
    hist_acceptance_truth_mHH_numerator_r3->Fill(truth_HH_m/1000.);
    hist_acceptance_truth_ptHbb_numerator_r3->Fill(truth_bb_pt);
    hist_acceptance_truth_ptHtautau_numerator_r3->Fill(truth_tautau_pt);
  }

  if(class_event != -1){
    if(class_event == 0){
      hist_acceptance_mHH_denominator_class0_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_denominator_class0_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_denominator_class0_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_denominator_class0_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_denominator_class0_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_denominator_class0_r2->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_denominator_class0_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_denominator_class0_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_denominator_class0_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_denominator_class0_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_denominator_class0_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_denominator_class0_r2->Fill(truth_tautau_pt);

      hist_acceptance_mHH_numerator_class0_r4->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_ptHbb_numerator_class0_r4->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class0_r4->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_numerator_class0_r4->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_ptHbb_numerator_class0_r4->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class0_r4->Fill(truth_tautau_pt);
    }
    if(class_event == 1){
      hist_acceptance_mHH_denominator_class1_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_denominator_class1_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_denominator_class1_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_denominator_class1_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_denominator_class1_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_denominator_class1_r2->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_denominator_class1_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_denominator_class1_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_denominator_class1_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_denominator_class1_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_denominator_class1_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_denominator_class1_r2->Fill(truth_tautau_pt);

      hist_acceptance_mHH_numerator_class1_r4->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_ptHbb_numerator_class1_r4->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class1_r4->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_numerator_class1_r4->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_ptHbb_numerator_class1_r4->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class1_r4->Fill(truth_tautau_pt);
    }
    if(class_event == 2){
      hist_acceptance_mHH_denominator_class2_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_denominator_class2_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_denominator_class2_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_denominator_class2_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_denominator_class2_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_denominator_class2_r2->Fill(reco_bbtt_tautau_pt_BA);

      hist_acceptance_truth_mHH_denominator_class2_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_denominator_class2_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_denominator_class2_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_denominator_class2_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_denominator_class2_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_denominator_class2_r2->Fill(truth_tautau_pt);

      hist_acceptance_mHH_numerator_class2_r4->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_ptHbb_numerator_class2_r4->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class2_r4->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_numerator_class2_r4->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_ptHbb_numerator_class2_r4->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class2_r4->Fill(truth_tautau_pt);
    }
    if(class_event == 3){
      hist_acceptance_mHH_denominator_class3_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_denominator_class3_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_denominator_class3_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_denominator_class3_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_pt_BA);

      hist_acceptance_truth_mHH_denominator_class3_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_denominator_class3_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_denominator_class3_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_denominator_class3_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_denominator_class3_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_denominator_class3_r2->Fill(truth_tautau_pt);

      hist_acceptance_mHH_numerator_class3_r4->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_ptHbb_numerator_class3_r4->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class3_r4->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_numerator_class3_r4->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_ptHbb_numerator_class3_r4->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class3_r4->Fill(truth_tautau_pt);
    }
  }
  // Rbb-Rtautau
  if((bbtt_HH_vis_m > 0) && (class_event != -1)){
    if(class_event == 0){
      hist_acceptance_mHH_numerator_class0_r1_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_numerator_class0_r1_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_numerator_class0_r1_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_numerator_class0_r1_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_numerator_class0_r1_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class0_r1_r2->Fill(reco_bbtt_tautau_pt_BA);
      
      hist_acceptance_truth_mHH_numerator_class0_r1_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_numerator_class0_r1_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_numerator_class0_r1_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_numerator_class0_r1_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_numerator_class0_r1_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class0_r1_r2->Fill(truth_tautau_pt);
    }
    // Rbb-Btautau
    if(class_event == 1){
      hist_acceptance_mHH_numerator_class1_r1_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_numerator_class1_r1_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_numerator_class1_r1_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_numerator_class1_r1_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_numerator_class1_r1_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class1_r1_r2->Fill(reco_bbtt_tautau_pt_BA);

      hist_acceptance_truth_mHH_numerator_class1_r1_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_numerator_class1_r1_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_numerator_class1_r1_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_numerator_class1_r1_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_numerator_class1_r1_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class1_r1_r2->Fill(truth_tautau_pt);
    }
    // Bbb-Rtautau
    if(class_event == 2){
      hist_acceptance_mHH_numerator_class2_r1_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_numerator_class2_r1_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_numerator_class2_r1_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_numerator_class2_r1_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_numerator_class2_r1_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class2_r1_r2->Fill(reco_bbtt_tautau_pt_BA);

      hist_acceptance_truth_mHH_numerator_class2_r1_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_numerator_class2_r1_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_numerator_class2_r1_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_numerator_class2_r1_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_numerator_class2_r1_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class2_r1_r2->Fill(truth_tautau_pt);
    }
    // Bbb-Btautau
    if(class_event == 3){
      hist_acceptance_mHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_m_BA);
      hist_acceptance_mHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_m_BA);
      hist_acceptance_mHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_m_BA);
      hist_acceptance_ptHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_pt_BA);
      hist_acceptance_ptHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_pt_BA);
      hist_acceptance_ptHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_pt_BA);

      hist_acceptance_truth_mHH_numerator_class3_r1_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_mHbb_numerator_class3_r1_r2->Fill(truth_bb_m);
      hist_acceptance_truth_mHtautau_numerator_class3_r1_r2->Fill(truth_tautau_m);
      hist_acceptance_truth_ptHH_numerator_class3_r1_r2->Fill(truth_HH_pt);
      hist_acceptance_truth_ptHbb_numerator_class3_r1_r2->Fill(truth_bb_pt);
      hist_acceptance_truth_ptHtautau_numerator_class3_r1_r2->Fill(truth_tautau_pt);
    } 
  }
}

void define_reconstructed_objects(){
  
  TLorentzVector b1 = TLorentzVector();
  TLorentzVector b2 = TLorentzVector();
  TLorentzVector bb = TLorentzVector();

  TLorentzVector tau1 = TLorentzVector();
  TLorentzVector tau2 = TLorentzVector();
  TLorentzVector tautau = TLorentzVector();

  TLorentzVector HH = TLorentzVector();

  if( class_event != -1 ){
    if( class_event == 0){ // R_bb - R_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin)/1000.);
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin)/1000.);
      bb = b1+b2;
      tautau = tau1+tau2;
      HH = b1+b2+tau1+tau2;
    }

    if( class_event == 1){ // R_bb - B_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin)/1000.);
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      bb = b1+b2;
      HH = b1+b2+tautau;
    }

    if( class_event == 2){ // B_bb - R_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin)/1000.);
      tautau = tau1+tau2;
      HH = bb+tau1+tau2;
    }

    if( class_event == 3){ // B_bb - B_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      HH = bb+tautau;
    }
    
    reco_bbtt_bb_pt_BA = bb.Pt();
    reco_bbtt_bb_eta_BA = bb.Eta();
    reco_bbtt_bb_phi_BA = bb.Phi();
    reco_bbtt_bb_m_BA = bb.M();
    
    reco_bbtt_tautau_pt_BA = tautau.Pt();
    reco_bbtt_tautau_eta_BA = tautau.Eta();
    reco_bbtt_tautau_phi_BA = tautau.Phi();
    reco_bbtt_tautau_m_BA = tautau.M();
    
    reco_bbtt_HH_pt_BA = HH.Pt();
    reco_bbtt_HH_eta_BA = HH.Eta();
    reco_bbtt_HH_phi_BA = HH.Phi();
    reco_bbtt_HH_m_BA = HH.M();
  }

  else{
    reco_bbtt_bb_pt_BA = -99;
    reco_bbtt_bb_eta_BA = -99;
    reco_bbtt_bb_phi_BA = -99;
    reco_bbtt_bb_m_BA = -99;
    
    reco_bbtt_tautau_pt_BA = -99;
    reco_bbtt_tautau_eta_BA = -99;
    reco_bbtt_tautau_phi_BA = -99;
    reco_bbtt_tautau_m_BA = -99;

    reco_bbtt_HH_pt_BA = -99;
    reco_bbtt_HH_eta_BA = -99;
    reco_bbtt_HH_phi_BA = -99;
    reco_bbtt_HH_m_BA = -99;
  }
}


// This function tell us on which class the event is given the next description:
/*
// Condition 1: To classify the events in the 4 classes, all the truth objects must have been matched to one recojet, i.e, all the truth
// idx must be different to -1. If not, the class_event will be set to -1 (no belong to any of the 4 casses)

// Condition 2: Those events where at least one b and one tau jets were matched to the same fat jet will be discarded because we
// already know that this wouldn't be possible, so the class_event will be set to -1 (no belong to any of the 4 casses)

// Condition 3: For boosted events, we need to ensure at leats two conditions: 1- The two truth objects (bb or tautau) must be matched to
// the same fat jet and 2- the deltaR between these two truth objects must be less than 1. Thus, when we are considering the bb or tautau
// truth jets, these criteria is going to tell us when the two jets are boosted.

// Condition 4: For resolved events, we need to ensure that 1- the two truth objects (bb or tautau) have been matched to a different fat
// jet and 2- the deltaR between these two truth objects are higher than 1.

// Condition 4: Definition of the 4 classes:
For R_bb R_tautau we setup 0
For R_bb B_tautau we setup 1
For B_bb R_tautau we setup 2
For B_bb B_tautau we setup 3

*/

void define_classes(){

  class_event = -1;

  if( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){

    if( (idx_b1truth_recoak10_dRmin!=idx_tau1truth_recoak10_dRmin) && (idx_b1truth_recoak10_dRmin!=idx_tau2truth_recoak10_dRmin) && (idx_b2truth_recoak10_dRmin!=idx_tau1truth_recoak10_dRmin) && (idx_b2truth_recoak10_dRmin!=idx_tau2truth_recoak10_dRmin)){  
      
      bool are_boosted_bb_matched = false;
      bool are_boosted_tautau_matched = false;
      
      if( idx_b1truth_recoak10_dRmin == idx_b2truth_recoak10_dRmin ){
	are_boosted_bb_matched = true;
      }
      if( idx_tau1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin ){
	are_boosted_tautau_matched = true;
      }
      
      // ************************************
      // For the boosted and resolved jets that are correctly identified matched to fat jets
      
      // For the R_bb R_tautau class
      if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==false) ){
	class_event = 0;
      }
      
      // For the R_bb B_tautau class
      if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==true) ){
	class_event = 1;
      }
      
      // For the B_bb R_tautau class
      if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==false) ){
	class_event = 2;
      }

      // For the B_bb B_tautau class
      if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==true) ){
	class_event = 3;
      }
    }
  }
}

// This function give us the min deltaR between the truth_objects and the objects in the recojets_ak10UFO fat-jets
void compute_dR_min_index_fat_jets(){
  
  compute_dR_min(idx_b1truth_recoak10_dRmin, dR_min_b1truth_recoak10_fatjet, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
  compute_dR_min(idx_b2truth_recoak10_dRmin, dR_min_b2truth_recoak10_fatjet, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
  compute_dR_min(idx_tau1truth_recoak10_dRmin, dR_min_tau1truth_recoak10_fatjet, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
  compute_dR_min(idx_tau2truth_recoak10_dRmin, dR_min_tau2truth_recoak10_fatjet, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
  
}

void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m){

  TLorentzVector jet1  = TLorentzVector();
  TLorentzVector jet2  = TLorentzVector();
      
  jet1.SetPtEtaPhiM(jet1_pt/1000., jet1_eta, jet1_phi, jet1_m/1000.);
  jet2.SetPtEtaPhiM(jet2_pt/1000., jet2_eta, jet2_phi, jet2_m/1000.);

  dR = jet1.DeltaR(jet2);
}


void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m){

  dR_min = 1; // Min dR value for which a truth object can be matched to a recojet
  idx = -1;
  
  if(recojet_antikt10UFO_NOSYS_pt->size() > 0){
    for(int ii = 0; ii < recojet_antikt10UFO_NOSYS_pt->size(); ii++){
      
      TLorentzVector truth_jet  = TLorentzVector();
      TLorentzVector reco_jet  = TLorentzVector();
      
      float reco_pt = recojet_antikt10UFO_NOSYS_pt->at(ii);
      float reco_eta = recojet_antikt10UFO_eta->at(ii);
      float reco_phi = recojet_antikt10UFO_phi->at(ii);
      float reco_m = recojet_antikt10UFO_m->at(ii);
      
      truth_jet.SetPtEtaPhiM(truth_pt/1000., truth_eta, truth_phi, truth_m/1000.);
      reco_jet.SetPtEtaPhiM(reco_pt/1000., reco_eta, reco_phi, reco_m/1000.);
      
      float deltaR_truth_recojet = truth_jet.DeltaR(reco_jet);
      
      if( (deltaR_truth_recojet < dR_min) ){
	dR_min = deltaR_truth_recojet;
	idx = ii;
      }
    }
  }
  else{
    idx = -1;
    dR_min = -1;
  }
}

void define_truth_tau_and_b_jets(){

  truth_b1_pt = -99;
  truth_b1_eta = -99;
  truth_b1_phi = -99;
  truth_b1_m = -99;
  
  truth_b2_pt = -99;
  truth_b2_eta = -99;
  truth_b2_phi = -99;
  truth_b2_m = -99;
  
  truth_tau1_pt = -99;
  truth_tau1_eta = -99;
  truth_tau1_phi = -99;
  truth_tau1_m = -99;
  
  truth_tau2_pt = -99;
  truth_tau2_eta = -99;
  truth_tau2_phi = -99;
  truth_tau2_m = -99;

  truth_bb_m = -99;
  truth_bb_eta = -99;
  truth_bb_phi = -99;
  truth_bb_m = -99;

  truth_tautau_pt = -99;
  truth_tautau_eta = -99;
  truth_tautau_phi = -99;
  truth_tautau_m = -99;
  /*
  truth_HH_pt = -99;
  truth_HH_eta = -99;
  truth_HH_phi = -99;
  truth_HH_m = -99;
  */
  if( truthjet_antikt4_HadronConeExclTruthLabelID->size()!=0 ){
    
    // Here we assume that all the jets are listed from the highest pT to the lowest pT
    int index_b1 = 0;
    int index_b2 = 0;
    int index_tau1 = 0;
    int index_tau2 = 0;
    
    int n_b = 0;
    int n_tau = 0;
    float leading_bjet_pt = 0;
    float subleading_bjet_pt = 0;
    float leading_taujet_pt = 0;
    float subleading_taujet_pt = 0;
    
    // Here we save the information for the two possible bb and tautau for the leading and subleading jet pT
    for(int ii=0; ii<truthjet_antikt4_HadronConeExclTruthLabelID->size(); ii++){
      
      if( TMath::Abs(truthjet_antikt4_HadronConeExclTruthLabelID->at(ii)) == 5 ){
	n_b++;
	if( subleading_bjet_pt < truthjet_antikt4_pt->at(ii) ){
	  if( leading_bjet_pt < truthjet_antikt4_pt->at(ii) ){
	    subleading_bjet_pt = leading_bjet_pt;
	    leading_bjet_pt = truthjet_antikt4_pt->at(ii);
	    index_b2 = index_b1;
	    index_b1 = ii;
	  }
	  else{
	    subleading_bjet_pt = truthjet_antikt4_pt->at(ii);
	    index_b2 = ii;
	  }
	}
      }
      
      else if( TMath::Abs(truthjet_antikt4_HadronConeExclTruthLabelID->at(ii)) == 15 ){
	n_tau++;
	if( subleading_taujet_pt < truthjet_antikt4_pt->at(ii) ){
	  if( leading_taujet_pt < truthjet_antikt4_pt->at(ii) ){
	    subleading_taujet_pt = leading_taujet_pt;
	    leading_taujet_pt = truthjet_antikt4_pt->at(ii);
	    index_tau2 = index_tau1;
	    index_tau1 = ii;
	  }
	  else{
	    subleading_taujet_pt = truthjet_antikt4_pt->at(ii);
	    index_tau2 = ii;
	  }
	}
      }
      
      else{
	continue;
      }
    }
    
    // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1bb_H2tautau scenario
    if( (n_b>=2) && (n_tau>=2) ){
      truth_b1_pt = truthjet_antikt4_pt->at(index_b1)/1000.;
      truth_b1_eta = truthjet_antikt4_eta->at(index_b1);
      truth_b1_phi = truthjet_antikt4_phi->at(index_b1);
      truth_b1_m = truthjet_antikt4_m->at(index_b1)/1000.;

      truth_b2_pt = truthjet_antikt4_pt->at(index_b2)/1000.;
      truth_b2_eta = truthjet_antikt4_eta->at(index_b2);
      truth_b2_phi = truthjet_antikt4_phi->at(index_b2);
      truth_b2_m = truthjet_antikt4_m->at(index_b2)/1000.;

      truth_tau1_pt = truthjet_antikt4_pt->at(index_tau1)/1000.;
      truth_tau1_eta = truthjet_antikt4_eta->at(index_tau1);
      truth_tau1_phi = truthjet_antikt4_phi->at(index_tau1);
      truth_tau1_m = truthjet_antikt4_m->at(index_tau1)/1000.;

      truth_tau2_pt = truthjet_antikt4_pt->at(index_tau2)/1000.;
      truth_tau2_eta = truthjet_antikt4_eta->at(index_tau2);
      truth_tau2_phi = truthjet_antikt4_phi->at(index_tau2);
      truth_tau2_m = truthjet_antikt4_m->at(index_tau2)/1000.;

      TLorentzVector b1_jet  = TLorentzVector();
      TLorentzVector b2_jet  = TLorentzVector();
      TLorentzVector bb_jet  = TLorentzVector();
      
      b1_jet.SetPtEtaPhiM(truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
      b2_jet.SetPtEtaPhiM(truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      bb_jet = b1_jet + b2_jet;

      truth_bb_pt = bb_jet.Pt();
      truth_bb_eta = bb_jet.Eta();
      truth_bb_phi = bb_jet.Phi();
      truth_bb_m = bb_jet.M();

      TLorentzVector tau1_jet  = TLorentzVector();
      TLorentzVector tau2_jet  = TLorentzVector();
      TLorentzVector tautau_jet  = TLorentzVector();
      
      tau1_jet.SetPtEtaPhiM(truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
      tau2_jet.SetPtEtaPhiM(truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
      tautau_jet = tau1_jet + tau2_jet;

      truth_tautau_pt = tautau_jet.Pt();
      truth_tautau_eta = tautau_jet.Eta();
      truth_tautau_phi = tautau_jet.Phi();
      truth_tautau_m = tautau_jet.M();
      /*
      TLorentzVector HH_jet  = TLorentzVector();
      HH_jet = bb_jet + tautau_jet;

      truth_HH_pt = HH_jet.Pt();
      truth_HH_eta = HH_jet.Eta();
      truth_HH_phi = HH_jet.Phi();
      truth_HH_m = HH_jet.M();
      */
    }
  }
}

/*
void define_truth_tau_and_b_jets(){

  if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){

    int sum_type_H1 = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1));
    int sum_type_H2 = TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));

    // Here we assume that all the jets are listed from the highest pT to the lowest pT
    int index_b1 = 0;
    int index_b2 = 1;
    int index_tau1 = 0;
    int index_tau2 = 1;

    // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1bb_H2tautau scenario
    if( (sum_type_H1 == 10) && (sum_type_H2 == 30) ){
      if(truth_children_fromH1_pt->at(0) < truth_children_fromH1_pt->at(1)){
	index_b1 = 1;
	index_b2 = 0;
      } 
      if(truth_children_fromH2_pt->at(0) < truth_children_fromH2_pt->at(1)){
	index_tau1 = 1;
	index_tau2 = 0;
      }
      
      truth_b1_pt = truth_children_fromH1_pt->at(index_b1);
      truth_b1_eta = truth_children_fromH1_eta->at(index_b1);
      truth_b1_phi = truth_children_fromH1_phi->at(index_b1);
      truth_b1_m = truth_children_fromH1_m->at(index_b1);

      truth_b2_pt = truth_children_fromH1_pt->at(index_b2);
      truth_b2_eta = truth_children_fromH1_eta->at(index_b2);
      truth_b2_phi = truth_children_fromH1_phi->at(index_b2);
      truth_b2_m = truth_children_fromH1_m->at(index_b2);

      truth_tau1_pt = truth_children_fromH2_pt->at(index_tau1);
      truth_tau1_eta = truth_children_fromH2_eta->at(index_tau1);
      truth_tau1_phi = truth_children_fromH2_phi->at(index_tau1);
      truth_tau1_m = truth_children_fromH2_m->at(index_tau1);	
      
      truth_tau2_pt = truth_children_fromH2_pt->at(index_tau2);
      truth_tau2_eta = truth_children_fromH2_eta->at(index_tau2);
      truth_tau2_phi = truth_children_fromH2_phi->at(index_tau2);
      truth_tau2_m = truth_children_fromH2_m->at(index_tau2);
    } 

    else if( (sum_type_H1 == 30) && (sum_type_H2 == 10) ){
    
      // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1tautau_H2bb scenario
      if(truth_children_fromH2_pt->at(0) < truth_children_fromH2_pt->at(1)){
	index_b1 = 1;
	index_b2 = 0;
      } 
      if(truth_children_fromH1_pt->at(0) < truth_children_fromH1_pt->at(1)){
	index_tau1 = 1;
	index_tau2 = 0;
      }
	
      truth_b1_pt = truth_children_fromH2_pt->at(index_b1);
      truth_b1_eta = truth_children_fromH2_eta->at(index_b1);
      truth_b1_phi = truth_children_fromH2_phi->at(index_b1);
      truth_b1_m = truth_children_fromH2_m->at(index_b1);
      
      truth_b2_pt = truth_children_fromH2_pt->at(index_b2);
      truth_b2_eta = truth_children_fromH2_eta->at(index_b2);
      truth_b2_phi = truth_children_fromH2_phi->at(index_b2);
      truth_b2_m = truth_children_fromH2_m->at(index_b2);
      
      truth_tau1_pt = truth_children_fromH1_pt->at(index_tau1);
      truth_tau1_eta = truth_children_fromH1_eta->at(index_tau1);
      truth_tau1_phi = truth_children_fromH1_phi->at(index_tau1);
      truth_tau1_m = truth_children_fromH1_m->at(index_tau1);	
      
      truth_tau2_pt = truth_children_fromH1_pt->at(index_tau2);
      truth_tau2_eta = truth_children_fromH1_eta->at(index_tau2);
      truth_tau2_phi = truth_children_fromH1_phi->at(index_tau2);
      truth_tau2_m = truth_children_fromH1_m->at(index_tau2);	
    }	
  }
  else{
    truth_b1_pt = -99;
    truth_b1_eta = -99;
    truth_b1_phi = -99;
    truth_b1_m = -99;
    
    truth_b2_pt = -99;
    truth_b2_eta = -99;
    truth_b2_phi = -99;
    truth_b2_m = -99;

    truth_tau1_pt = -99;
    truth_tau1_eta = -99;
    truth_tau1_phi = -99;
    truth_tau1_m = -99;
    
    truth_tau2_pt = -99;
    truth_tau2_eta = -99;
    truth_tau2_phi = -99;
    truth_tau2_m = -99;
  }
}
*/

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void fill_histograms(){

  //**********************************************
  // Filling truth objects histograms
  //**********************************************
  
  if(truth_children_fromH1_pdgId->size() == 2){
    if((TMath::Abs(truth_children_fromH1_pdgId->at(0)) == 5) && (TMath::Abs(truth_children_fromH1_pdgId->at(1)) == 5)){
      float sum = truth_children_fromH1_m->at(0) + truth_children_fromH1_m->at(1); // Wrong assumption, we need to do it by using a TLorentzV
      hist_truth_b1_plus_b2_m->Fill(sum);
      hist_truth_b1_m->Fill(truth_children_fromH1_m->at(0));
      hist_truth_b2_m->Fill(truth_children_fromH1_m->at(1));
    }
  }

  //**********************************************
  // Filling the mass, pT and eta distributions of the boosted bb and tautau objects
  //**********************************************
 
  if(class_event != -1){

    // truth Boosted bb                                                                                                                     
    if( (class_event == 2) || (class_event == 3) ){

      float dR_bb = 0;
      deltaR(dR_bb, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      
      hist_matched_recojet_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_bb_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_bb_eta->Fill(recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin));
      hist_matched_recojet_bb_dR->Fill(dR_bb);
      hist2d_dR_per_class_bb->Fill(class_event, dR_bb);
    }

    // truth boosted tautau jets                                                                                                            
    if( (class_event == 1) || (class_event == 3) ){

      float dR_tautau = 0;
      deltaR(dR_tautau, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);

      hist_matched_recojet_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_tautau_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_tautau_eta->Fill(recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_dR->Fill(dR_tautau);
      hist2d_dR_per_class_tautau->Fill(class_event, dR_tautau);
    }

    // Fill the pt and eta distribution of those recojets that were not matched to a truth object but are in RR, RB, BR or BB classes
    if( recojet_antikt10UFO_NOSYS_pt->size() > 0 ){
      for(int jj=0; jj < recojet_antikt10UFO_NOSYS_pt->size(); jj++){
	if( (jj != idx_b1truth_recoak10_dRmin) && (jj != idx_b2truth_recoak10_dRmin) && (jj != idx_tau1truth_recoak10_dRmin) && (jj != idx_tau2truth_recoak10_dRmin) ){
	  hist_non_matched_recojet_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(jj)/1000.);
	}
      }
    }

    if( recojet_antikt10UFO_eta->size() > 0){
      for(int jj=0; jj < recojet_antikt10UFO_eta->size(); jj++){
	if( (jj != idx_b1truth_recoak10_dRmin) && (jj != idx_b2truth_recoak10_dRmin) && (jj != idx_tau1truth_recoak10_dRmin) && (jj != idx_tau2truth_recoak10_dRmin) ){
	  hist_non_matched_recojet_eta->Fill(recojet_antikt10UFO_eta->at(jj));
	}
      } 
    }
  }

  // Fill the pt and eta distribution of those recojets that were not matched to a truth object and are not in RR, RB, BR or BB classes
  if( class_event == -1){
    if( recojet_antikt10UFO_NOSYS_pt->size() > 0 ){
      for(int jj=0; jj < recojet_antikt10UFO_NOSYS_pt->size(); jj++){
	hist_non_matched_recojet_pt_no_class->Fill(recojet_antikt10UFO_NOSYS_pt->at(jj)/1000.);
      }
    }

    if( recojet_antikt10UFO_eta->size() > 0){
      for(int jj=0; jj < recojet_antikt10UFO_eta->size(); jj++){
	hist_non_matched_recojet_eta_no_class->Fill(recojet_antikt10UFO_eta->at(jj));
      }
    }
  }

  // Fill the number of events per class
  hist_nevents_per_class->Fill(class_event);

  // Fill the pT and mass distribution for truth and computed HH

  if( class_event != -1 ){
    hist_truth_HH_pt->Fill(truth_HH_pt/1000.);
    hist_computed_HH_pt->Fill(reco_bbtt_HH_pt_BA); // This value is already given in GeV

    hist_truth_HH_m->Fill(truth_HH_m/1000.);
    hist_computed_HH_m->Fill(reco_bbtt_HH_m_BA); // This value is already given in GeV
  }
}

// This function saves the branches info for a given tree in the variables defined above
void set_branch_address_inTree(TTree *inTree){

  inTree->SetBranchAddress("truth_children_fromH1_pdgId", &truth_children_fromH1_pdgId, &b_truth_children_fromH1_pdgId);
  inTree->SetBranchAddress("truth_children_fromH1_pt", &truth_children_fromH1_pt, &b_truth_children_fromH1_pt);
  inTree->SetBranchAddress("truth_children_fromH1_eta", &truth_children_fromH1_eta, &b_truth_children_fromH1_eta);
  inTree->SetBranchAddress("truth_children_fromH1_phi", &truth_children_fromH1_phi, &b_truth_children_fromH1_phi);
  inTree->SetBranchAddress("truth_children_fromH1_m", &truth_children_fromH1_m, &b_truth_children_fromH1_m);

  inTree->SetBranchAddress("truth_children_fromH2_pdgId", &truth_children_fromH2_pdgId, &b_truth_children_fromH2_pdgId);
  inTree->SetBranchAddress("truth_children_fromH2_pt", &truth_children_fromH2_pt, &b_truth_children_fromH2_pt);
  inTree->SetBranchAddress("truth_children_fromH2_eta", &truth_children_fromH2_eta, &b_truth_children_fromH2_eta);
  inTree->SetBranchAddress("truth_children_fromH2_phi", &truth_children_fromH2_phi, &b_truth_children_fromH2_phi);
  inTree->SetBranchAddress("truth_children_fromH2_m", &truth_children_fromH2_m, &b_truth_children_fromH2_m);

  inTree->SetBranchAddress("truthjet_antikt4_pt", &truthjet_antikt4_pt, &b_truthjet_antikt4_pt);
  inTree->SetBranchAddress("truthjet_antikt4_eta", &truthjet_antikt4_eta, &b_truthjet_antikt4_eta);
  inTree->SetBranchAddress("truthjet_antikt4_phi", &truthjet_antikt4_phi, &b_truthjet_antikt4_phi);
  inTree->SetBranchAddress("truthjet_antikt4_m", &truthjet_antikt4_m, &b_truthjet_antikt4_m);
  inTree->SetBranchAddress("truthjet_antikt4_HadronConeExclTruthLabelID", &truthjet_antikt4_HadronConeExclTruthLabelID, &b_truthjet_antikt4_HadronConeExclTruthLabelID);
  
  inTree->SetBranchAddress("truth_HH_pt", &truth_HH_pt, &b_truth_HH_pt);
  inTree->SetBranchAddress("truth_HH_eta", &truth_HH_eta, &b_truth_HH_eta);
  inTree->SetBranchAddress("truth_HH_phi", &truth_HH_phi, &b_truth_HH_phi);
  inTree->SetBranchAddress("truth_HH_m", &truth_HH_m, &b_truth_HH_m);
  
  inTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt, &b_recojet_antikt10UFO_NOSYS_pt);
  inTree->SetBranchAddress("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta, &b_recojet_antikt10UFO_eta);
  inTree->SetBranchAddress("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi, &b_recojet_antikt10UFO_phi);
  inTree->SetBranchAddress("recojet_antikt10UFO_m", &recojet_antikt10UFO_m, &b_recojet_antikt10UFO_m);
    
  inTree->SetBranchAddress("bbtt_Jet_b1_pt_NOSYS", &bbtt_Jet_b1_pt_NOSYS, &b_bbtt_Jet_b1_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Jet_b1_eta", &bbtt_Jet_b1_eta, &b_bbtt_Jet_b1_eta);
  inTree->SetBranchAddress("bbtt_Jet_b1_phi", &bbtt_Jet_b1_phi, &b_bbtt_Jet_b1_phi);
  inTree->SetBranchAddress("bbtt_Jet_b1_E", &bbtt_Jet_b1_E, &b_bbtt_Jet_b1_E);

  inTree->SetBranchAddress("bbtt_Jet_b2_pt_NOSYS", &bbtt_Jet_b2_pt_NOSYS, &b_bbtt_Jet_b2_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Jet_b2_eta", &bbtt_Jet_b2_eta, &b_bbtt_Jet_b2_eta);
  inTree->SetBranchAddress("bbtt_Jet_b2_phi", &bbtt_Jet_b2_phi, &b_bbtt_Jet_b2_phi);
  inTree->SetBranchAddress("bbtt_Jet_b2_E", &bbtt_Jet_b2_E, &b_bbtt_Jet_b2_E);

  inTree->SetBranchAddress("bbtt_Tau1_pt_NOSYS", &bbtt_Tau1_pt_NOSYS, &b_bbtt_Tau1_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Tau1_eta", &bbtt_Tau1_eta, &b_bbtt_Tau1_eta);
  inTree->SetBranchAddress("bbtt_Tau1_phi", &bbtt_Tau1_phi, &b_bbtt_Tau1_phi);
  inTree->SetBranchAddress("bbtt_Tau1_E", &bbtt_Tau1_E, &b_bbtt_Tau1_E);
  
  inTree->SetBranchAddress("bbtt_Tau2_pt_NOSYS", &bbtt_Tau2_pt_NOSYS, &b_bbtt_Tau2_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Tau2_eta", &bbtt_Tau2_eta, &b_bbtt_Tau2_eta);
  inTree->SetBranchAddress("bbtt_Tau2_phi", &bbtt_Tau2_phi, &b_bbtt_Tau2_phi);
  inTree->SetBranchAddress("bbtt_Tau2_E", &bbtt_Tau2_E, &b_bbtt_Tau2_E);
  
  inTree->SetBranchAddress("bbtt_HH_pt_NOSYS", &bbtt_HH_pt_NOSYS, &b_bbtt_HH_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_HH_eta", &bbtt_HH_eta, &b_bbtt_HH_eta);
  inTree->SetBranchAddress("bbtt_HH_phi", &bbtt_HH_phi, &b_bbtt_HH_phi);
  inTree->SetBranchAddress("bbtt_HH_m", &bbtt_HH_m, &b_bbtt_HH_m);

  inTree->SetBranchAddress("bbtt_HH_vis_pt_NOSYS", &bbtt_HH_vis_pt_NOSYS, &b_bbtt_HH_vis_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_HH_vis_m", &bbtt_HH_vis_m, &b_bbtt_HH_vis_m);
  
  inTree->SetBranchAddress("generatorWeight_NOSYS", &generatorWeight_NOSYS, &b_generatorWeight_NOSYS);
  inTree->SetBranchAddress("recojet_antikt4PFlow_NOSYS_passesOR", &recojet_antikt4PFlow_NOSYS_passesOR, &b_recojet_antikt4PFlow_NOSYS_passesOR);
  
}

void define_output_branches(TTree *outTree){

  outTree->Branch("truth_children_fromH1_pdgId", &truth_children_fromH1_pdgId);
  outTree->Branch("truth_children_fromH1_pt", &truth_children_fromH1_pt);
  outTree->Branch("truth_children_fromH1_eta", &truth_children_fromH1_eta);
  outTree->Branch("truth_children_fromH1_phi", &truth_children_fromH1_phi);
  outTree->Branch("truth_children_fromH1_m", &truth_children_fromH1_m);

  outTree->Branch("truth_children_fromH2_pdgId", &truth_children_fromH2_pdgId);
  outTree->Branch("truth_children_fromH2_pt", &truth_children_fromH2_pt);
  outTree->Branch("truth_children_fromH2_eta", &truth_children_fromH2_eta);
  outTree->Branch("truth_children_fromH2_phi", &truth_children_fromH2_phi);
  outTree->Branch("truth_children_fromH2_m", &truth_children_fromH2_m);

  outTree->Branch("truth_HH_pt", &truth_HH_pt);
  outTree->Branch("truth_HH_eta", &truth_HH_eta);
  outTree->Branch("truth_HH_phi", &truth_HH_phi);
  outTree->Branch("truth_HH_m", &truth_HH_m);

  outTree->Branch("truth_b1_pt", &truth_b1_pt);
  outTree->Branch("truth_b1_eta", &truth_b1_eta);
  outTree->Branch("truth_b1_phi", &truth_b1_phi);
  outTree->Branch("truth_b1_m", &truth_b1_m);

  outTree->Branch("truth_b2_pt", &truth_b2_pt);
  outTree->Branch("truth_b2_eta", &truth_b2_eta);
  outTree->Branch("truth_b2_phi", &truth_b2_phi);
  outTree->Branch("truth_b2_m", &truth_b2_m);

  outTree->Branch("truth_tau1_pt", &truth_tau1_pt);
  outTree->Branch("truth_tau1_eta", &truth_tau1_eta);
  outTree->Branch("truth_tau1_phi", &truth_tau1_phi);
  outTree->Branch("truth_tau1_m", &truth_tau1_m);
  
  outTree->Branch("truth_tau2_pt", &truth_tau2_pt);
  outTree->Branch("truth_tau2_eta", &truth_tau2_eta);
  outTree->Branch("truth_tau2_phi", &truth_tau2_phi);
  outTree->Branch("truth_tau2_m", &truth_tau2_m);

  outTree->Branch("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt);
  outTree->Branch("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta);
  outTree->Branch("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi);
  outTree->Branch("recojet_antikt10UFO_m", &recojet_antikt10UFO_m);
  
  outTree->Branch("idx_b1truth_recoak10_dRmin", &idx_b1truth_recoak10_dRmin);
  outTree->Branch("idx_b2truth_recoak10_dRmin", &idx_b2truth_recoak10_dRmin);
  outTree->Branch("idx_tau1truth_recoak10_dRmin", &idx_tau1truth_recoak10_dRmin);
  outTree->Branch("idx_tau2truth_recoak10_dRmin", &idx_tau2truth_recoak10_dRmin);

  outTree->Branch("dR_min_b1truth_recoak10_fatjet", &dR_min_b1truth_recoak10_fatjet);
  outTree->Branch("dR_min_b2truth_recoak10_fatjet", &dR_min_b2truth_recoak10_fatjet);
  outTree->Branch("dR_min_tau1truth_recoak10_fatjet", &dR_min_tau1truth_recoak10_fatjet);
  outTree->Branch("dR_min_tau2truth_recoak10_fatjet", &dR_min_tau2truth_recoak10_fatjet);

  outTree->Branch("class_event", &class_event);

  outTree->Branch("bbtt_Jet_b1_pt_NOSYS_Resolved_Selection", &bbtt_Jet_b1_pt_NOSYS);
  outTree->Branch("bbtt_Jet_b1_eta_Resolved_Selection", &bbtt_Jet_b1_eta);
  outTree->Branch("bbtt_Jet_b1_phi_Resolved_Selection", &bbtt_Jet_b1_phi);
  outTree->Branch("bbtt_Jet_b1_E_Resolved_Selection", &bbtt_Jet_b1_E);

  outTree->Branch("bbtt_Jet_b2_pt_NOSYS_Resolved_Selection", &bbtt_Jet_b2_pt_NOSYS);
  outTree->Branch("bbtt_Jet_b2_eta_Resolved_Selection", &bbtt_Jet_b2_eta);
  outTree->Branch("bbtt_Jet_b2_phi_Resolved_Selection", &bbtt_Jet_b2_phi);
  outTree->Branch("bbtt_Jet_b2_E_Resolved_Selection", &bbtt_Jet_b2_E);

  outTree->Branch("bbtt_Tau1_pt_NOSYS_Resolved_Selection", &bbtt_Tau1_pt_NOSYS);
  outTree->Branch("bbtt_Tau1_eta_Resolved_Selection", &bbtt_Tau1_eta);
  outTree->Branch("bbtt_Tau1_phi_Resolved_Selection", &bbtt_Tau1_phi);
  outTree->Branch("bbtt_Tau1_E_Resolved_Selection", &bbtt_Tau1_E);
  
  outTree->Branch("bbtt_Tau2_pt_NOSYS_Resolved_Selection", &bbtt_Tau2_pt_NOSYS);
  outTree->Branch("bbtt_Tau2_eta_Resolved_Selection", &bbtt_Tau2_eta);
  outTree->Branch("bbtt_Tau2_phi_Resolved_Selection", &bbtt_Tau2_phi);
  outTree->Branch("bbtt_Tau2_E_Resolved_Selection", &bbtt_Tau2_E);
  
  outTree->Branch("bbtt_HH_pt_NOSYS_Resolved_Selection", &bbtt_HH_pt_NOSYS);
  outTree->Branch("bbtt_HH_eta_Resolved_Selection", &bbtt_HH_eta);
  outTree->Branch("bbtt_HH_phi_Resolved_Selection", &bbtt_HH_phi);
  outTree->Branch("bbtt_HH_m_Resolved_Selection", &bbtt_HH_m);

  outTree->Branch("bbtt_HH_vis_pt_NOSYS", &bbtt_HH_vis_pt_NOSYS);
  outTree->Branch("bbtt_HH_vis_m", &bbtt_HH_vis_m);
}

// Write histograms in the output root file
void write_histograms(){

  // truth_object_histograms
  hist_truth_b1_m->Write();
  hist_truth_b2_m->Write();
  hist_truth_b1_plus_b2_m->Write();

  //matched_recojets_histograms
  hist_matched_recojet_bb_m->Write();
  hist_matched_recojet_tautau_m->Write();
  hist_matched_recojet_bb_pt->Write();
  hist_matched_recojet_tautau_pt->Write();
  hist_matched_recojet_bb_eta->Write();
  hist_matched_recojet_tautau_eta->Write();
  hist_matched_recojet_bb_dR->Write();
  hist_matched_recojet_tautau_dR->Write();

  //non_matched_recojets_histograms
  hist_non_matched_recojet_pt->Write();
  hist_non_matched_recojet_eta->Write();
  hist_non_matched_recojet_pt_no_class->Write();
  hist_non_matched_recojet_eta_no_class->Write();

  
  hist_nevents_per_class->Write();
  hist2d_dR_per_class_bb->Write();
  hist2d_dR_per_class_tautau->Write();

  //comparison_histograms
  hist_truth_HH_pt->Write();
  hist_computed_HH_pt->Write();
  hist_truth_HH_m->Write();
  hist_computed_HH_m->Write();

  //ratios for mHH
  hist_acceptance_mHH_numerator_class0_r1_r2->Write();
  hist_acceptance_mHH_numerator_class1_r1_r2->Write();
  hist_acceptance_mHH_numerator_class2_r1_r2->Write();
  hist_acceptance_mHH_numerator_class3_r1_r2->Write();
  hist_acceptance_mHH_denominator_r1->Write();
  hist_acceptance_mHH_denominator_class0_r2->Write();
  hist_acceptance_mHH_denominator_class1_r2->Write();
  hist_acceptance_mHH_denominator_class2_r2->Write();
  hist_acceptance_mHH_denominator_class3_r2->Write();

  hist_acceptance_truth_mHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_mHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_mHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_mHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_mHH_denominator_r1->Write();
  hist_acceptance_truth_mHH_denominator_class0_r2->Write();
  hist_acceptance_truth_mHH_denominator_class1_r2->Write();
  hist_acceptance_truth_mHH_denominator_class2_r2->Write();
  hist_acceptance_truth_mHH_denominator_class3_r2->Write();

  //ratios for ptHH
  hist_acceptance_ptHH_numerator_class0_r1_r2->Write();
  hist_acceptance_ptHH_numerator_class1_r1_r2->Write();
  hist_acceptance_ptHH_numerator_class2_r1_r2->Write();
  hist_acceptance_ptHH_numerator_class3_r1_r2->Write();
  hist_acceptance_ptHH_denominator_r1->Write();
  hist_acceptance_ptHH_denominator_class0_r2->Write();
  hist_acceptance_ptHH_denominator_class1_r2->Write();
  hist_acceptance_ptHH_denominator_class2_r2->Write();
  hist_acceptance_ptHH_denominator_class3_r2->Write();

  hist_acceptance_truth_ptHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_ptHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_ptHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_ptHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_ptHH_denominator_r1->Write();
  hist_acceptance_truth_ptHH_denominator_class0_r2->Write();
  hist_acceptance_truth_ptHH_denominator_class1_r2->Write();
  hist_acceptance_truth_ptHH_denominator_class2_r2->Write();
  hist_acceptance_truth_ptHH_denominator_class3_r2->Write();

  //ratios for mHbb
  hist_acceptance_mHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_mHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_mHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_mHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_mHbb_denominator_r1->Write();
  hist_acceptance_mHbb_denominator_class0_r2->Write();
  hist_acceptance_mHbb_denominator_class1_r2->Write();
  hist_acceptance_mHbb_denominator_class2_r2->Write();
  hist_acceptance_mHbb_denominator_class3_r2->Write();

  hist_acceptance_truth_mHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_mHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_mHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_mHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_mHbb_denominator_r1->Write();
  hist_acceptance_truth_mHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_mHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_mHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_mHbb_denominator_class3_r2->Write();  

  //ratios for mHtautau
  hist_acceptance_mHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_mHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_mHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_mHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_mHtautau_denominator_r1->Write();
  hist_acceptance_mHtautau_denominator_class0_r2->Write();
  hist_acceptance_mHtautau_denominator_class1_r2->Write();
  hist_acceptance_mHtautau_denominator_class2_r2->Write();
  hist_acceptance_mHtautau_denominator_class3_r2->Write();

  hist_acceptance_truth_mHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_mHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_mHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_mHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_r1->Write();
  hist_acceptance_truth_mHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_class3_r2->Write();

  //ratios for ptHbb
  hist_acceptance_ptHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_ptHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_ptHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_ptHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_ptHbb_denominator_r1->Write();
  hist_acceptance_ptHbb_denominator_class0_r2->Write();
  hist_acceptance_ptHbb_denominator_class1_r2->Write();
  hist_acceptance_ptHbb_denominator_class2_r2->Write();
  hist_acceptance_ptHbb_denominator_class3_r2->Write();

  hist_acceptance_truth_ptHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_ptHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_ptHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_ptHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_r1->Write();
  hist_acceptance_truth_ptHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_class3_r2->Write();

  //ratios for ptHtautau
  hist_acceptance_ptHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_ptHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_ptHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_ptHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_ptHtautau_denominator_r1->Write();
  hist_acceptance_ptHtautau_denominator_class0_r2->Write();
  hist_acceptance_ptHtautau_denominator_class1_r2->Write();
  hist_acceptance_ptHtautau_denominator_class2_r2->Write();
  hist_acceptance_ptHtautau_denominator_class3_r2->Write();

  hist_acceptance_truth_ptHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_r1->Write();
  hist_acceptance_truth_ptHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_class3_r2->Write();  

  //**************************************************************
  // Ratios r3 and r4 for level variables 
  //**************************************************************
  
  // ratios r3 and r4 for mHH
  hist_acceptance_mHH_numerator_r3->Write();
  hist_acceptance_mHH_denominator_r3_r4->Write();
  hist_acceptance_mHH_numerator_class0_r4->Write();
  hist_acceptance_mHH_numerator_class1_r4->Write();
  hist_acceptance_mHH_numerator_class2_r4->Write();
  hist_acceptance_mHH_numerator_class3_r4->Write();
  
  // ratios r3 and r4 for ptHbb                                                                                                              
  hist_acceptance_ptHbb_numerator_r3->Write();
  hist_acceptance_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_ptHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for ptHtautau                                                                                                         
  hist_acceptance_ptHtautau_numerator_r3->Write();
  hist_acceptance_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_ptHtautau_numerator_class3_r4->Write();
  
  // ratios r3 and r4 for truth mHH
  hist_acceptance_truth_mHH_numerator_r3->Write();
  hist_acceptance_truth_mHH_denominator_r3_r4->Write();
  hist_acceptance_truth_mHH_numerator_class0_r4->Write();
  hist_acceptance_truth_mHH_numerator_class1_r4->Write();
  hist_acceptance_truth_mHH_numerator_class2_r4->Write();
  hist_acceptance_truth_mHH_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth ptHbb
  hist_acceptance_truth_ptHbb_numerator_r3->Write();
  hist_acceptance_truth_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth ptHtautau
  hist_acceptance_truth_ptHtautau_numerator_r3->Write();
  hist_acceptance_truth_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class3_r4->Write();
}

// This function prints the list of branches of a given tree
void print_list_of_branches(TTree* tree){

  cout << "The number of entries is: " << tree->GetEntries() << endl;

  // Get the list of branches
  TObjArray *branchList = tree->GetListOfBranches();
  
  // Loop over branches and print their names and types
  for (int ii = 0; ii < branchList->GetEntries(); ++ii) {
    TBranch *branch = dynamic_cast<TBranch*>(branchList->At(ii));
    if (!branch) continue;
    
    const char* branchName = branch->GetName();
    const char* typeName = branch->GetClassName(); // Get the class name of the branch type

    std::cout << "Branch: " << branchName << "\t Type: " << (typeName ? typeName : "Unknown") << std::endl;
  }
}

void counter_for_stat(){

  if(class_event == -1){ count_non_matched_events+=1; }
  if(class_event == 0){ count_truth_Rbb_Rtautau+=1; }
  if(class_event == 1){ count_truth_Rbb_Btautau+=1; }
  if(class_event == 2){ count_truth_Bbb_Rtautau+=1; }
  if(class_event == 3){ count_truth_Bbb_Btautau+=1; }
  
  if(bbtt_Jet_b1_pt_NOSYS > 0){ count_pos_resolved_b1_config+=1;}
  if(bbtt_Jet_b2_pt_NOSYS > 0){ count_pos_resolved_b2_config+=1;}
  if(bbtt_Tau1_pt_NOSYS > 0){ count_pos_resolved_tau1_config+=1;}
  if(bbtt_Tau2_pt_NOSYS > 0){ count_pos_resolved_tau2_config+=1;}
  
  if(bbtt_HH_pt_NOSYS > 0){ count_pos_resolved_HH_pt_config+=1;}
  if(bbtt_HH_eta > 0){ count_pos_resolved_HH_eta_config+=1;}
  if(bbtt_HH_phi > 0){ count_pos_resolved_HH_phi_config+=1;}
  if(bbtt_HH_m > 0){ count_pos_resolved_HH_m_config+=1;}
  
  if(bbtt_HH_vis_pt_NOSYS > 0){ count_pos_resolved_HH_vis_pt_config+=1;}
  if(bbtt_HH_vis_m > 0){ count_pos_resolved_HH_vis_m_config+=1;}

  if( (bbtt_Jet_b1_pt_NOSYS > 0) && (bbtt_Jet_b2_pt_NOSYS > 0) && (bbtt_Tau1_pt_NOSYS > 0) && (bbtt_Tau2_pt_NOSYS > 0) ){
    count_all_objects_resolved_config+=1;
  }

  if(truth_HH_pt > 0){ count_truth_HH_pt_pos_values+=1;}
  if(truth_HH_m > 0){ count_truth_HH_m_pos_values+=1;}

}

void print_stat(Int_t nentries){

  int sum_all_events = count_non_matched_events + count_truth_Rbb_Rtautau + count_truth_Rbb_Btautau + count_truth_Bbb_Rtautau + count_truth_Bbb_Btautau;

  int sum_truth_matching_events = count_truth_Rbb_Rtautau + count_truth_Rbb_Btautau + count_truth_Bbb_Rtautau + count_truth_Bbb_Btautau;

  cout << "There are " << count_truth_Rbb_Rtautau << " in the truth R_bb-R_tautau (" << 100.0*count_truth_Rbb_Rtautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_truth_Rbb_Btautau << " in the truth R_bb-B_tautau (" << 100.0*count_truth_Rbb_Btautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_truth_Bbb_Rtautau << " in the truth B_bb-R_tautau (" << 100.0*count_truth_Bbb_Rtautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_truth_Bbb_Btautau << " in the truth B_bb-B_tautau (" << 100.0*count_truth_Bbb_Btautau/nentries << "% of the total entries)" << endl;
  /*                                                                                                                                          
  cout << "The number of events in which there are one of the two taus and one of the two bb jets matched to the same recojet is " << count_b\
_tau_matched_recojets << " of a total nentries " << nentries << " (" << 100.0*count_b_tau_matched_recojets/nentries << "% of the total nentri\
es)" << endl;                                                                                                                                 
  */
  cout << "The sum of all the events into one of the given classes plus the number of events which have at least one truth object without a match with a fat jet is: " << sum_all_events << " (" << 100.0*sum_all_events/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_non_matched_events << " events which have at least one truth object without a match with a fat jet (" << 100.0*count_non_matched_events/nentries << "% of the total entries)" << endl;

  cout << "The sum of all the events which were correctly classified with resolved and boosted bb and tautau jets: " << sum_truth_matching_events << " (" << 100.0*sum_truth_matching_events/nentries << "% of the total entries)" << endl;

  cout << "Total entries: " << nentries << endl;

  cout << "Number of events that passed the resolved selection (counting b1_pt positive values): " << count_pos_resolved_b1_config << endl;
  cout << "Number of events that passed the resolved selection (counting b2_pt positive values): " << count_pos_resolved_b2_config << endl;
  cout << "Number of events that passed the resolved selection (counting tau1_pt positive values): " << count_pos_resolved_tau1_config << endl;
  cout << "Number of events that passed the resolved selection (counting tau2_pt positive values): " << count_pos_resolved_tau2_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_pt positive values): " << count_pos_resolved_HH_pt_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_m positive values): " << count_pos_resolved_HH_m_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_vis_pt positive values): " << count_pos_resolved_HH_vis_pt_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_vis_m positive values): " << count_pos_resolved_HH_vis_m_config << endl;

  cout << "Number of events that passed the resolved selection (counting all possible objects values): " << count_all_objects_resolved_config << endl;

  cout << "The number of positive values for truth_HH_pt is: " << count_truth_HH_pt_pos_values << endl;

  cout << "The number of positive values for truth_HH_m is: " << count_truth_HH_m_pos_values << endl;

}
