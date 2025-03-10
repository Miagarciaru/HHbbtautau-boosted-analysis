#include "declaration_of_variables.h"

// *************************************
// Declaration of functions
// *************************************

void define_preselected_events();
void apply_preselection(float min_pT_cut_in_MeV);
void process_label(TString name_sample, const std::string& min_pT_recojets_str);
void fill_acceptance_ratios();
void fill_all_events_histograms_acceptance_ratios();
void fill_resolved_selection_histograms_acceptance_ratios();
void fill_preselected_events_histograms_acceptance_ratios();
void fill_boosted_events_histograms_acceptance_ratios();
void define_reconstructed_objects();
void define_output_branches();
void define_classes();
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m);
void define_truth_tau_and_b_jets();
void fill_histograms_matched_truth_recojets();
void fill_histograms_preselected_jets();
void set_branch_address_inTree(TTree *inTree);
void define_output_branches(TTree *outTree);
void print_list_of_branches(TTree* tree);
void default_values_for_truth_variables();
void default_values_for_preselected_variables();


// *************************************
// Definition of the functions declared above
// *************************************


void process_label(TString name_sample, const std::string& min_pT_recojets_str){

  // string min_pT_recojets_str = std::to_string(min_pT_recojets);
  
  // ggF processes had-had channel
  if(name_sample.Contains("600459")==true){ process_name = "ggF HH SM had-had channel"; name_output_root_file = "ggF_SM_hh_600459_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("600460")==true){ process_name = "ggF HH #lambda = 10 had-had channel"; name_output_root_file = "ggF_lambda10_hh_600460_pT"+TString(min_pT_recojets_str)+"GeV.root";}

  // ggF processes lep-had channel
  if(name_sample.Contains("600461")==true){ process_name = "ggF HH SM lep-had channel"; name_output_root_file = "ggF_SM_lh_600461_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("600462")==true){ process_name = "ggF HH #lambda = 10 lep-had channel"; name_output_root_file = "ggF_lambda10_lh_600462_pT"+TString(min_pT_recojets_str)+"GeV.root";}

  //vbf processes had-had channel
  if(name_sample.Contains("502982")==true){ process_name = "VBF HH SM had-had channel"; name_output_root_file = "VBF_SM_hh_502982_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("502985")==true){ process_name = "VBF HH C_{VV} = 1.5 had-had channel"; name_output_root_file = "VBF_cvv1p5_hh_502985_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("502989")==true){ process_name = "VBF HH #lambda = 2.0 had-had channel"; name_output_root_file = "VBF_l2_hh_502989_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("502990")==true){ process_name = "VBF HH #lambda = 10.0 had-had channel"; name_output_root_file = "VBF_l10_hh_502990_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("502991")==true){ process_name = "VBF HH C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_cv0p5_hh_502991_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("508690")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_l5cv0p5_hh_508690_pT"+TString(min_pT_recojets_str)+"GeV.root";}

  //vbf processes lep-had channel
  if(name_sample.Contains("502993")==true){ process_name = "VBF HH SM lep-had channel"; name_output_root_file = "VBF_SM_lh_502993_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("502996")==true){ process_name = "VBF HH C_{VV} = 1.5 lep-had channel"; name_output_root_file = "VBF_cvv1p5_lh_502996_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("503000")==true){ process_name = "VBF HH #lambda = 2.0 lep-had channel"; name_output_root_file = "VBF_l2_lh_503000_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("503001")==true){ process_name = "VBF HH #lambda = 10.0 lep-had channel"; name_output_root_file = "VBF_l10_lh_503001_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("503002")==true){ process_name = "VBF HH C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_cv0p5_lh_503002_pT"+TString(min_pT_recojets_str)+"GeV.root";}
  if(name_sample.Contains("508691")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_l5cv0p5_lh_508691_pT"+TString(min_pT_recojets_str)+"GeV.root";}

  //vbf SM processes both channels channel
  if(name_sample.Contains("vbf_SM_both_channels")==true){ process_name = "VBF HH SM"; }

  //vbf SM processes both channels channel
  if(name_sample.Contains("ggf_SM_both_channels")==true){ process_name = "ggF HH SM"; }

  //vbf Cvv=1.5 processes both channels channel
  if(name_sample.Contains("vbf_l1cvv1p5cv1_both_channels")==true){ process_name = "VBF HH C_{VV} = 1.5"; }

  //ggf cHHH = 10 processes both channels channel
  if(name_sample.Contains("ggf_cHHH10d0_both_channels")==true){ process_name = "ggF HH #lambda = 10"; }
}

void define_preselected_events(){

  matched_preselection = false;
  
  if( recojet_antikt10UFO_NOSYS_pt->size() >= 2){

    float min_tagger_Hbb_value = 0.85;
    float value_phbb_current = 0;
    float value_phbb_previous = min_tagger_Hbb_value;
    float max_nsubjetiness_value_for_bb = 0.45;
    float tau_n2_over_n1_subjettiness_bb_current = 1.0;
    float tau_n2_over_n1_subjettiness_bb_previous = 1.0;
    float min_nsubjetiness_value_for_bb = 0.05;

    bool matched_preselected_bb = false;
    
    //Selecting preselected boosted bb jet 
    for(Int_t ii=0; ii<recojet_antikt10UFO_GN2Xv01_phbb->size(); ii++){
      value_phbb_current = recojet_antikt10UFO_GN2Xv01_phbb->at(ii);
      if(value_phbb_current >= min_tagger_Hbb_value){
	if(value_phbb_current >= value_phbb_previous){
	  tau_n2_over_n1_subjettiness_bb_current = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
	  if( (tau_n2_over_n1_subjettiness_bb_current <= max_nsubjetiness_value_for_bb) && (tau_n2_over_n1_subjettiness_bb_current >= min_nsubjetiness_value_for_bb) ){
	    if(tau_n2_over_n1_subjettiness_bb_current <= tau_n2_over_n1_subjettiness_bb_previous){
	      tau_n2_over_n1_subjettiness_bb_previous = tau_n2_over_n1_subjettiness_bb_current;
	      value_phbb_previous = value_phbb_current;
	      idx_b1_preselected = ii;
	      matched_preselected_bb = true;
	    }
	  }
	}
      }
    }

    float max_nsubjetiness_value_for_tautau = 0.30;
    float tau_n2_over_n1_subjettiness_tautau_current = 1.0;
    float tau_n2_over_n1_subjettiness_tautau_previous = 1.0;
    float min_nsubjetiness_value_for_tautau = 0.05;
    bool matched_preselected_tautau = false;
    
    if(matched_preselected_bb == true){
      for(Int_t ii=0; ii < recojet_antikt10UFO_Tau2_wta->size(); ii++){
	if( ii != idx_b1_preselected ){
	  tau_n2_over_n1_subjettiness_tautau_current = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
	  if( (tau_n2_over_n1_subjettiness_tautau_current <= max_nsubjetiness_value_for_tautau) && (tau_n2_over_n1_subjettiness_tautau_current >= min_nsubjetiness_value_for_tautau) ){
	    if(tau_n2_over_n1_subjettiness_tautau_current <= tau_n2_over_n1_subjettiness_tautau_previous){
	      tau_n2_over_n1_subjettiness_tautau_previous = tau_n2_over_n1_subjettiness_tautau_current;
	      idx_tau1_preselected = ii;
	      matched_preselected_tautau = true;
	    }
	  }
	}
      }
    }
    
    if( (matched_preselected_bb == true) && (matched_preselected_tautau == true) ){
      matched_preselection = true;
    }

    // Save the values for bb, tautau and HH objects if it was posible to find the preselected bb and tautau boosted jets
    if( matched_preselection == true ){

      TLorentzVector bb = TLorentzVector();
      TLorentzVector tautau = TLorentzVector();
      TLorentzVector HH = TLorentzVector();
      
      preselected_bb_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected);
      preselected_bb_eta = recojet_antikt10UFO_eta->at(idx_b1_preselected);
      preselected_bb_phi = recojet_antikt10UFO_phi->at(idx_b1_preselected);
      preselected_bb_m = recojet_antikt10UFO_m->at(idx_b1_preselected);
      
      preselected_tautau_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected);
      preselected_tautau_eta = recojet_antikt10UFO_eta->at(idx_tau1_preselected);
      preselected_tautau_phi = recojet_antikt10UFO_phi->at(idx_tau1_preselected);
      preselected_tautau_m = recojet_antikt10UFO_m->at(idx_tau1_preselected);
      
      bb.SetPtEtaPhiM(preselected_bb_pt, preselected_bb_eta, preselected_bb_phi, preselected_bb_m);
      tautau.SetPtEtaPhiM(preselected_tautau_pt, preselected_tautau_eta, preselected_tautau_phi, preselected_tautau_m);
      
      HH = bb + tautau;
      
      preselected_HH_pt = HH.Pt();
      preselected_HH_eta = HH.Eta();
      preselected_HH_phi = HH.Phi();
      preselected_HH_m = HH.M();	
      
    }
    // Save the default values if it was not possible to find the bb and tautau objects
    if( matched_preselection == false ){
      default_values_for_preselected_variables();
    }
  }
  // Save the default values if it the fisrt preselection was not passed
  if( matched_preselection == false ){
    default_values_for_preselected_variables();
  }
}


void apply_preselection(float min_pT_cut_in_MeV){

  // default value for the preselection
  passed_preselection = false;
  
  bool min_pT_cut = false;
  
  float min_pT_recojets_MeV = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());

  if( min_pT_recojets_MeV >= min_pT_cut_in_MeV ){
    min_pT_cut = true;
  }

  bool recojets_number_condition = true;
  if( recojet_antikt10UFO_NOSYS_pt->size() < 2){
    recojets_number_condition = false;
  }
  
  if( (min_pT_recojets_MeV >= min_pT_cut_in_MeV) && (recojets_number_condition==true) ){
    passed_preselection = true;
  }
  
}

void fill_acceptance_ratios(){

  // all events histograms

  fill_all_events_histograms_acceptance_ratios();

  // resolved selection event histograms
  if(bbtt_HH_vis_m > 0){
    fill_resolved_selection_histograms_acceptance_ratios();
  }
  
  // Boosted analysis events histograms
  if(class_event != -1){
    fill_boosted_events_histograms_acceptance_ratios();
  }

  // Preselected analysis events histograms
  if(matched_preselection == true){
    fill_preselected_events_histograms_acceptance_ratios();
  }

}

void fill_all_events_histograms_acceptance_ratios(){

  // all events histograms
  hist_acceptance_mHH_denominator_r3_r4->Fill(reco_bbtt_HH_m_BA/1000.);
  hist_acceptance_ptHbb_denominator_r3_r4->Fill(reco_bbtt_bb_pt_BA/1000.);
  hist_acceptance_ptHtautau_denominator_r3_r4->Fill(reco_bbtt_tautau_pt_BA/1000.);

  // truth variables
  hist_acceptance_truth_mHH_denominator_r3_r4->Fill(truth_HH_m/1000.);
  hist_acceptance_truth_ptHH_denominator_r3_r4->Fill(truth_HH_pt/1000.);
  hist_acceptance_truth_etaHH_denominator_r3_r4->Fill(truth_HH_eta);
  hist_acceptance_truth_phiHH_denominator_r3_r4->Fill(truth_HH_phi);
  hist_acceptance_truth_mHbb_denominator_r3_r4->Fill(truth_bb_m/1000.);
  hist_acceptance_truth_ptHbb_denominator_r3_r4->Fill(truth_bb_pt/1000.);
  hist_acceptance_truth_etaHbb_denominator_r3_r4->Fill(truth_bb_eta);
  hist_acceptance_truth_phiHbb_denominator_r3_r4->Fill(truth_bb_phi);
  hist_acceptance_truth_mHtautau_denominator_r3_r4->Fill(truth_tautau_m/1000.);
  hist_acceptance_truth_ptHtautau_denominator_r3_r4->Fill(truth_tautau_pt/1000.);
  hist_acceptance_truth_etaHtautau_denominator_r3_r4->Fill(truth_tautau_eta);
  hist_acceptance_truth_phiHtautau_denominator_r3_r4->Fill(truth_tautau_phi);

  // preselected events variables
  
  hist_acceptance_preselected_mHH_denominator_r3_r4->Fill(preselected_HH_m/1000.);
  hist_acceptance_preselected_ptHH_denominator_r3_r4->Fill(preselected_HH_pt/1000.);
  hist_acceptance_preselected_etaHH_denominator_r3_r4->Fill(preselected_HH_eta);
  hist_acceptance_preselected_phiHH_denominator_r3_r4->Fill(preselected_HH_phi);
  hist_acceptance_preselected_mHbb_denominator_r3_r4->Fill(preselected_bb_m/1000.);
  hist_acceptance_preselected_ptHbb_denominator_r3_r4->Fill(preselected_bb_pt/1000.);
  hist_acceptance_preselected_etaHbb_denominator_r3_r4->Fill(preselected_bb_eta);
  hist_acceptance_preselected_phiHbb_denominator_r3_r4->Fill(preselected_bb_phi);
  hist_acceptance_preselected_mHtautau_denominator_r3_r4->Fill(preselected_tautau_m/1000.);
  hist_acceptance_preselected_ptHtautau_denominator_r3_r4->Fill(preselected_tautau_pt/1000.);
  hist_acceptance_preselected_etaHtautau_denominator_r3_r4->Fill(preselected_tautau_eta);
  hist_acceptance_preselected_phiHtautau_denominator_r3_r4->Fill(preselected_tautau_phi);

}

void fill_resolved_selection_histograms_acceptance_ratios(){

  // resolved selection event histograms
  
  hist_acceptance_mHH_denominator_r1->Fill(reco_bbtt_HH_m_BA/1000.);
  hist_acceptance_ptHbb_denominator_r1->Fill(reco_bbtt_bb_pt_BA/1000.);
  hist_acceptance_ptHtautau_denominator_r1->Fill(reco_bbtt_tautau_pt_BA/1000.);

  // truth variables
  hist_acceptance_truth_mHH_denominator_r1->Fill(truth_HH_m/1000.);
  hist_acceptance_truth_ptHH_denominator_r1->Fill(truth_HH_pt/1000.);
  hist_acceptance_truth_etaHH_denominator_r1->Fill(truth_HH_eta);
  hist_acceptance_truth_phiHH_denominator_r1->Fill(truth_HH_phi);
  hist_acceptance_truth_mHbb_denominator_r1->Fill(truth_bb_m/1000.);
  hist_acceptance_truth_ptHbb_denominator_r1->Fill(truth_bb_pt/1000.);
  hist_acceptance_truth_etaHbb_denominator_r1->Fill(truth_bb_eta);
  hist_acceptance_truth_phiHbb_denominator_r1->Fill(truth_bb_phi);
  hist_acceptance_truth_mHtautau_denominator_r1->Fill(truth_tautau_m/1000.);
  hist_acceptance_truth_ptHtautau_denominator_r1->Fill(truth_tautau_pt/1000.);
  hist_acceptance_truth_etaHtautau_denominator_r1->Fill(truth_tautau_eta);
  hist_acceptance_truth_phiHtautau_denominator_r1->Fill(truth_tautau_phi);

  // preselected events variables
  hist_acceptance_preselected_mHH_denominator_r1->Fill(preselected_HH_m/1000.);
  hist_acceptance_preselected_ptHH_denominator_r1->Fill(preselected_HH_pt/1000.);
  hist_acceptance_preselected_etaHH_denominator_r1->Fill(preselected_HH_eta);
  hist_acceptance_preselected_phiHH_denominator_r1->Fill(preselected_HH_phi);
  hist_acceptance_preselected_mHbb_denominator_r1->Fill(preselected_bb_m/1000.);
  hist_acceptance_preselected_ptHbb_denominator_r1->Fill(preselected_bb_pt/1000.);
  hist_acceptance_preselected_etaHbb_denominator_r1->Fill(preselected_bb_eta);
  hist_acceptance_preselected_phiHbb_denominator_r1->Fill(preselected_bb_phi);
  hist_acceptance_preselected_mHtautau_denominator_r1->Fill(preselected_tautau_m/1000.);
  hist_acceptance_preselected_ptHtautau_denominator_r1->Fill(preselected_tautau_pt/1000.);
  hist_acceptance_preselected_etaHtautau_denominator_r1->Fill(preselected_tautau_eta);
  hist_acceptance_preselected_phiHtautau_denominator_r1->Fill(preselected_tautau_phi);

  
  // recovariables
  hist_acceptance_mHH_numerator_r3->Fill(reco_bbtt_HH_m_BA/1000.);
  hist_acceptance_ptHbb_numerator_r3->Fill(reco_bbtt_bb_pt_BA/1000.);
  hist_acceptance_ptHtautau_numerator_r3->Fill(reco_bbtt_tautau_pt_BA/1000.);

  // truth variables
  hist_acceptance_truth_mHH_numerator_r3->Fill(truth_HH_m/1000.);
  hist_acceptance_truth_ptHH_numerator_r3->Fill(truth_HH_pt/1000.);
  hist_acceptance_truth_etaHH_numerator_r3->Fill(truth_HH_eta);
  hist_acceptance_truth_phiHH_numerator_r3->Fill(truth_HH_phi);
  hist_acceptance_truth_mHbb_numerator_r3->Fill(truth_bb_m/1000.);
  hist_acceptance_truth_ptHbb_numerator_r3->Fill(truth_bb_pt/1000.);
  hist_acceptance_truth_etaHbb_numerator_r3->Fill(truth_bb_eta);
  hist_acceptance_truth_phiHbb_numerator_r3->Fill(truth_bb_phi);
  hist_acceptance_truth_mHtautau_numerator_r3->Fill(truth_tautau_m/1000.);
  hist_acceptance_truth_ptHtautau_numerator_r3->Fill(truth_tautau_pt/1000.);
  hist_acceptance_truth_etaHtautau_numerator_r3->Fill(truth_tautau_eta);
  hist_acceptance_truth_phiHtautau_numerator_r3->Fill(truth_tautau_phi);

  // preselected events variables
  hist_acceptance_preselected_mHH_numerator_r3->Fill(preselected_HH_m/1000.);
  hist_acceptance_preselected_ptHH_numerator_r3->Fill(preselected_HH_pt/1000.);
  hist_acceptance_preselected_etaHH_numerator_r3->Fill(preselected_HH_eta);
  hist_acceptance_preselected_phiHH_numerator_r3->Fill(preselected_HH_phi);
  hist_acceptance_preselected_mHbb_numerator_r3->Fill(preselected_bb_m/1000.);
  hist_acceptance_preselected_ptHbb_numerator_r3->Fill(preselected_bb_pt/1000.);
  hist_acceptance_preselected_etaHbb_numerator_r3->Fill(preselected_bb_eta);
  hist_acceptance_preselected_phiHbb_numerator_r3->Fill(preselected_bb_phi);
  hist_acceptance_preselected_mHtautau_numerator_r3->Fill(preselected_tautau_m/1000.);
  hist_acceptance_preselected_ptHtautau_numerator_r3->Fill(preselected_tautau_pt/1000.);
  hist_acceptance_preselected_etaHtautau_numerator_r3->Fill(preselected_tautau_eta);
  hist_acceptance_preselected_phiHtautau_numerator_r3->Fill(preselected_tautau_phi);

}

void fill_preselected_events_histograms_acceptance_ratios(){

  // Preselected analysis events histograms

  hist_acceptance_preselected_mHH_denominator_class3_r2->Fill(preselected_HH_m/1000.);
  hist_acceptance_preselected_ptHH_denominator_class3_r2->Fill(preselected_HH_pt/1000.);
  hist_acceptance_preselected_etaHH_denominator_class3_r2->Fill(preselected_HH_eta);
  hist_acceptance_preselected_phiHH_denominator_class3_r2->Fill(preselected_HH_phi);
  hist_acceptance_preselected_mHbb_denominator_class3_r2->Fill(preselected_bb_m/1000.);
  hist_acceptance_preselected_ptHbb_denominator_class3_r2->Fill(preselected_bb_pt/1000.);
  hist_acceptance_preselected_etaHbb_denominator_class3_r2->Fill(preselected_bb_eta);
  hist_acceptance_preselected_phiHbb_denominator_class3_r2->Fill(preselected_bb_phi);
  hist_acceptance_preselected_mHtautau_denominator_class3_r2->Fill(preselected_tautau_m/1000.);
  hist_acceptance_preselected_ptHtautau_denominator_class3_r2->Fill(preselected_tautau_pt/1000.);
  hist_acceptance_preselected_etaHtautau_denominator_class3_r2->Fill(preselected_tautau_eta);
  hist_acceptance_preselected_phiHtautau_denominator_class3_r2->Fill(preselected_tautau_phi);
      
  hist_acceptance_preselected_mHH_numerator_class3_r4->Fill(preselected_HH_m/1000.);
  hist_acceptance_preselected_ptHH_numerator_class3_r4->Fill(preselected_HH_pt/1000.);
  hist_acceptance_preselected_etaHH_numerator_class3_r4->Fill(preselected_HH_eta);
  hist_acceptance_preselected_phiHH_numerator_class3_r4->Fill(preselected_HH_phi);
  hist_acceptance_preselected_mHbb_numerator_class3_r4->Fill(preselected_bb_m/1000.);
  hist_acceptance_preselected_ptHbb_numerator_class3_r4->Fill(preselected_bb_pt/1000.);
  hist_acceptance_preselected_etaHbb_numerator_class3_r4->Fill(preselected_bb_eta);
  hist_acceptance_preselected_phiHbb_numerator_class3_r4->Fill(preselected_bb_phi);
  hist_acceptance_preselected_mHtautau_numerator_class3_r4->Fill(preselected_tautau_m/1000.);
  hist_acceptance_preselected_ptHtautau_numerator_class3_r4->Fill(preselected_tautau_pt/1000.);
  hist_acceptance_preselected_etaHtautau_numerator_class3_r4->Fill(preselected_tautau_eta);
  hist_acceptance_preselected_phiHtautau_numerator_class3_r4->Fill(preselected_tautau_phi);
    
  hist_acceptance_all_Bbb_preselected_mHbb_denominator_r2_numerator_r4->Fill(preselected_bb_m/1000.);
  hist_acceptance_all_Bbb_preselected_ptHbb_denominator_r2_numerator_r4->Fill(preselected_bb_pt/1000.);
    
  hist_acceptance_all_Btautau_preselected_mHtautau_denominator_r2_numerator_r4->Fill(preselected_tautau_m/1000.);
  hist_acceptance_all_Btautau_preselected_ptHtautau_denominator_r2_numerator_r4->Fill(preselected_tautau_pt/1000.);
  
  // Overlap region
  // Rbb-Rtautau
  if( (bbtt_HH_vis_m > 0) && (passed_preselection == true) ){ // Events being selected bythe resolved selection and the boosted analysis
    
    hist_acceptance_preselected_mHH_numerator_class3_r1_r2->Fill(preselected_HH_m/1000.);
    hist_acceptance_preselected_ptHH_numerator_class3_r1_r2->Fill(preselected_HH_pt/1000.);
    hist_acceptance_preselected_etaHH_numerator_class3_r1_r2->Fill(preselected_HH_eta);
    hist_acceptance_preselected_phiHH_numerator_class3_r1_r2->Fill(preselected_HH_phi);
    hist_acceptance_preselected_mHbb_numerator_class3_r1_r2->Fill(preselected_bb_m/1000.);
    hist_acceptance_preselected_ptHbb_numerator_class3_r1_r2->Fill(preselected_bb_pt/1000.);
    hist_acceptance_preselected_etaHbb_numerator_class3_r1_r2->Fill(preselected_bb_eta);
    hist_acceptance_preselected_phiHbb_numerator_class3_r1_r2->Fill(preselected_bb_phi);
    hist_acceptance_preselected_mHtautau_numerator_class3_r1_r2->Fill(preselected_tautau_m/1000.);
    hist_acceptance_preselected_ptHtautau_numerator_class3_r1_r2->Fill(preselected_tautau_pt/1000.);
    hist_acceptance_preselected_etaHtautau_numerator_class3_r1_r2->Fill(preselected_tautau_eta);
    hist_acceptance_preselected_phiHtautau_numerator_class3_r1_r2->Fill(preselected_tautau_phi);
    
    hist_acceptance_all_Bbb_preselected_mHbb_numerator_r1_r2->Fill(preselected_bb_m/1000.);
    hist_acceptance_all_Bbb_preselected_ptHbb_numerator_r1_r2->Fill(preselected_bb_pt/1000.);
    
    hist_acceptance_all_Btautau_preselected_mHtautau_numerator_r1_r2->Fill(preselected_tautau_m/1000.);
    hist_acceptance_all_Btautau_preselected_ptHtautau_numerator_r1_r2->Fill(preselected_tautau_pt/1000.);
    
  }
}


void fill_boosted_events_histograms_acceptance_ratios(){

  // Boosted analysis events histograms

  if(class_event == 3){
    hist_acceptance_mHH_denominator_class3_r2->Fill(reco_bbtt_HH_m_BA/1000.);
    hist_acceptance_ptHbb_denominator_class3_r2->Fill(reco_bbtt_bb_pt_BA/1000.);
    hist_acceptance_ptHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_pt_BA/1000.);
    
    hist_acceptance_truth_mHH_denominator_class3_r2->Fill(truth_HH_m/1000.);
    hist_acceptance_truth_ptHH_denominator_class3_r2->Fill(truth_HH_pt/1000.);
    hist_acceptance_truth_etaHH_denominator_class3_r2->Fill(truth_HH_eta);
    hist_acceptance_truth_phiHH_denominator_class3_r2->Fill(truth_HH_phi);
    hist_acceptance_truth_mHbb_denominator_class3_r2->Fill(truth_bb_m/1000.);
    hist_acceptance_truth_ptHbb_denominator_class3_r2->Fill(truth_bb_pt/1000.);
    hist_acceptance_truth_etaHbb_denominator_class3_r2->Fill(truth_bb_eta);
    hist_acceptance_truth_phiHbb_denominator_class3_r2->Fill(truth_bb_phi);
    hist_acceptance_truth_mHtautau_denominator_class3_r2->Fill(truth_tautau_m/1000.);
    hist_acceptance_truth_ptHtautau_denominator_class3_r2->Fill(truth_tautau_pt/1000.);
    hist_acceptance_truth_etaHtautau_denominator_class3_r2->Fill(truth_tautau_eta);
    hist_acceptance_truth_phiHtautau_denominator_class3_r2->Fill(truth_tautau_phi);
    
    hist_acceptance_mHH_numerator_class3_r4->Fill(reco_bbtt_HH_m_BA/1000.);
    hist_acceptance_ptHbb_numerator_class3_r4->Fill(reco_bbtt_bb_pt_BA/1000.);
    hist_acceptance_ptHtautau_numerator_class3_r4->Fill(reco_bbtt_tautau_pt_BA/1000.);
    
    hist_acceptance_truth_mHH_numerator_class3_r4->Fill(truth_HH_m/1000.);
    hist_acceptance_truth_ptHH_numerator_class3_r4->Fill(truth_HH_pt/1000.);
    hist_acceptance_truth_etaHH_numerator_class3_r4->Fill(truth_HH_eta);
    hist_acceptance_truth_phiHH_numerator_class3_r4->Fill(truth_HH_phi);
    hist_acceptance_truth_mHbb_numerator_class3_r4->Fill(truth_bb_m/1000.);
    hist_acceptance_truth_ptHbb_numerator_class3_r4->Fill(truth_bb_pt/1000.);
    hist_acceptance_truth_etaHbb_numerator_class3_r4->Fill(truth_bb_eta);
    hist_acceptance_truth_phiHbb_numerator_class3_r4->Fill(truth_bb_phi);
    hist_acceptance_truth_mHtautau_numerator_class3_r4->Fill(truth_tautau_m/1000.);
    hist_acceptance_truth_ptHtautau_numerator_class3_r4->Fill(truth_tautau_pt/1000.);
    hist_acceptance_truth_etaHtautau_numerator_class3_r4->Fill(truth_tautau_eta);
    hist_acceptance_truth_phiHtautau_numerator_class3_r4->Fill(truth_tautau_phi);
  }
  
  if( (class_event==2) || (class_event==3) ){
    hist_acceptance_all_Bbb_mHbb_denominator_r2_numerator_r4->Fill(reco_bbtt_bb_m_BA/1000.);
    hist_acceptance_all_Bbb_ptHbb_denominator_r2_numerator_r4->Fill(reco_bbtt_bb_pt_BA/1000.);
    
    hist_acceptance_all_Bbb_truth_mHbb_denominator_r2_numerator_r4->Fill(truth_bb_m/1000.);
    hist_acceptance_all_Bbb_truth_ptHbb_denominator_r2_numerator_r4->Fill(truth_bb_pt/1000.);
  }
  
  if( (class_event==1) || (class_event==3) ){
    hist_acceptance_all_Btautau_mHtautau_denominator_r2_numerator_r4->Fill(reco_bbtt_tautau_m_BA/1000.);
    hist_acceptance_all_Btautau_ptHtautau_denominator_r2_numerator_r4->Fill(reco_bbtt_tautau_pt_BA/1000.);
    
    hist_acceptance_all_Btautau_truth_mHtautau_denominator_r2_numerator_r4->Fill(truth_tautau_m/1000.);
    hist_acceptance_all_Btautau_truth_ptHtautau_denominator_r2_numerator_r4->Fill(truth_tautau_pt/1000.);
  }
  
  // Overlap region
  // Rbb-Rtautau
  if( (bbtt_HH_vis_m > 0) && (passed_preselection == true) ){ // Events being selected bythe resolved selection and the boosted analysis
    
    // Bbb-Btautau
    if(class_event == 3){
      
      hist_acceptance_mHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_m_BA/1000.);
      hist_acceptance_ptHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_pt_BA/1000.);
      hist_acceptance_ptHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_pt_BA/1000.);
      
      hist_acceptance_truth_mHH_numerator_class3_r1_r2->Fill(truth_HH_m/1000.);
      hist_acceptance_truth_ptHH_numerator_class3_r1_r2->Fill(truth_HH_pt/1000.);
      hist_acceptance_truth_etaHH_numerator_class3_r1_r2->Fill(truth_HH_eta);
      hist_acceptance_truth_phiHH_numerator_class3_r1_r2->Fill(truth_HH_phi);
      hist_acceptance_truth_mHbb_numerator_class3_r1_r2->Fill(truth_bb_m/1000.);
      hist_acceptance_truth_ptHbb_numerator_class3_r1_r2->Fill(truth_bb_pt/1000.);
      hist_acceptance_truth_etaHbb_numerator_class3_r1_r2->Fill(truth_bb_eta);
      hist_acceptance_truth_phiHbb_numerator_class3_r1_r2->Fill(truth_bb_phi);
      hist_acceptance_truth_mHtautau_numerator_class3_r1_r2->Fill(truth_tautau_m/1000.);
      hist_acceptance_truth_ptHtautau_numerator_class3_r1_r2->Fill(truth_tautau_pt/1000.);
      hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2->Fill(truth_tautau_eta);
      hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2->Fill(truth_tautau_phi);

    }
    
    if( (class_event==2) || (class_event==3) ){
      
      hist_acceptance_all_Bbb_mHbb_numerator_r1_r2->Fill(reco_bbtt_bb_m_BA/1000.);
      hist_acceptance_all_Bbb_ptHbb_numerator_r1_r2->Fill(reco_bbtt_bb_pt_BA/1000.);
      
      hist_acceptance_all_Bbb_truth_mHbb_numerator_r1_r2->Fill(truth_bb_m/1000.);
      hist_acceptance_all_Bbb_truth_ptHbb_numerator_r1_r2->Fill(truth_bb_pt/1000.);
      
    }
    
    if( (class_event==1) || (class_event==3) ){
      
      hist_acceptance_all_Btautau_mHtautau_numerator_r1_r2->Fill(reco_bbtt_tautau_m_BA/1000.);
      hist_acceptance_all_Btautau_ptHtautau_numerator_r1_r2->Fill(reco_bbtt_tautau_pt_BA/1000.);
      
      hist_acceptance_all_Btautau_truth_mHtautau_numerator_r1_r2->Fill(truth_tautau_m/1000.);
      hist_acceptance_all_Btautau_truth_ptHtautau_numerator_r1_r2->Fill(truth_tautau_pt/1000.);
      
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
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin));
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin));
      bb = b1+b2;
      tautau = tau1+tau2;
      HH = b1+b2+tau1+tau2;
    }

    if( class_event == 1){ // R_bb - B_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin));
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      bb = b1+b2;
      HH = b1+b2+tautau;
    }

    if( class_event == 2){ // B_bb - R_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin));
      tautau = tau1+tau2;
      HH = bb+tau1+tau2;
    }

    if( class_event == 3){ // B_bb - B_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
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
      
  jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
  jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

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
      
      truth_jet.SetPtEtaPhiM(truth_pt, truth_eta, truth_phi, truth_m);
      reco_jet.SetPtEtaPhiM(reco_pt, reco_eta, reco_phi, reco_m);
      
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

  if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){

    int sum_type_H1 = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1));
    int sum_type_H2 = TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
    int sum_type_HH = sum_type_H1+sum_type_H2;
    
    // Here we assume that all the jets are listed from the highest pT to the lowest pT
    int index_b1 = 0;
    int index_b2 = 1;
    int index_tau1 = 0;
    int index_tau2 = 1;

    TLorentzVector b1_jet  = TLorentzVector();
    TLorentzVector b2_jet  = TLorentzVector();
    TLorentzVector bb_jet  = TLorentzVector();

    TLorentzVector tau1_jet  = TLorentzVector();
    TLorentzVector tau2_jet  = TLorentzVector();
    TLorentzVector tautau_jet  = TLorentzVector();

    TLorentzVector HH_jet  = TLorentzVector();

    if( sum_type_HH == 40 ){
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

      b1_jet.SetPtEtaPhiM(truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
      b2_jet.SetPtEtaPhiM(truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      bb_jet = b1_jet + b2_jet;
      
      truth_bb_pt = bb_jet.Pt();
      truth_bb_eta = bb_jet.Eta();
      truth_bb_phi = bb_jet.Phi();
      truth_bb_m = bb_jet.M();
	
      tau1_jet.SetPtEtaPhiM(truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
      tau2_jet.SetPtEtaPhiM(truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
      tautau_jet = tau1_jet + tau2_jet;
      
      truth_tautau_pt = tautau_jet.Pt();
      truth_tautau_eta = tautau_jet.Eta();
      truth_tautau_phi = tautau_jet.Phi();
      truth_tautau_m = tautau_jet.M();
      
      HH_jet = bb_jet + tautau_jet;
	
      truth_HH_pt = HH_jet.Pt();
      truth_HH_eta = HH_jet.Eta();
      truth_HH_phi = HH_jet.Phi();
      truth_HH_m = HH_jet.M();	
    }
    else{
      // set -99 to truth variables
      default_values_for_truth_variables();
    }
  }
  else{
    // set -99 to truth variables
    default_values_for_truth_variables();
  }
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void fill_histograms_matched_truth_recojets(){
  
  //**********************************************
  // Filling the mass, pT and eta distributions of the boosted bb and tautau objects
  //**********************************************
 
  if(class_event != -1){

    // Fill m, pt, eta... distribution of those recojets that were matched to be boosted bb (classes Bbb-Rtautau or Bbb-Btautua)
    
    if( (class_event == 2) || (class_event == 3) ){
      
      float dR_bb = 0;
      float tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_b1truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_b1truth_recoak10_dRmin);

      deltaR(dR_bb, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      
      hist_matched_recojet_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_bb_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_bb_eta->Fill(recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin));
      hist_matched_recojet_bb_phi->Fill(recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin));

      hist_matched_recojet_bb_tau_n1_subjettiness->Fill(recojet_antikt10UFO_Tau1_wta->at(idx_b1truth_recoak10_dRmin));
      hist_matched_recojet_bb_tau_n2_subjettiness->Fill(recojet_antikt10UFO_Tau2_wta->at(idx_b1truth_recoak10_dRmin));
      hist_matched_recojet_bb_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);

      hist_matched_recojet_bb_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_b1truth_recoak10_dRmin));
      hist_matched_recojet_bb_ak10_GN2Xv01_pqcd->Fill(recojet_antikt10UFO_GN2Xv01_pqcd->at(idx_b1truth_recoak10_dRmin));
      
      hist_matched_recojet_bb_dR->Fill(dR_bb);
      hist2d_dR_per_class_bb->Fill(class_event, dR_bb);

      if(tau_nProng->size()!=0){
	for(int ii=0; ii<tau_nProng->size(); ii++){
	  hist_matched_recojet_bb_tau_n_prong->Fill(tau_nProng->at(ii));
	}
      }

    }

    // Fill m, pt, eta... distribution of those recojets that were matched to be boosted tautau (classes Rbb-Btautau or Bbb-Btautua)
    
    if( (class_event == 1) || (class_event == 3) ){
      
      float dR_tautau = 0;
      float tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_tau1truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_tau1truth_recoak10_dRmin);
      deltaR(dR_tautau, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
      
      hist_matched_recojet_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_tautau_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_tautau_eta->Fill(recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_phi->Fill(recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_dR->Fill(dR_tautau);
      
      hist_matched_recojet_tautau_tau_n1_subjettiness->Fill(recojet_antikt10UFO_Tau1_wta->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_tau_n2_subjettiness->Fill(recojet_antikt10UFO_Tau2_wta->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);

      hist_matched_recojet_tautau_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Fill(recojet_antikt10UFO_GN2Xv01_pqcd->at(idx_tau1truth_recoak10_dRmin));
      
      hist2d_dR_per_class_tautau->Fill(class_event, dR_tautau);

      if(tau_nProng->size()!=0){
	for(int ii=0; ii<tau_nProng->size(); ii++){
	  hist_matched_recojet_tautau_tau_n_prong->Fill(tau_nProng->at(ii));
	}
      }
    }

    // Fill m, pt, eta... distribution of those recojets that were not matched to be boosted bb (classes Rbb-Rtautau or Rbb-Btautua)

    if( (class_event == 0) || (class_event == 1) ){

      float tau_n2_over_n1_subjettiness = 0;
      
      hist_non_matched_recojet_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_bb_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_bb_eta->Fill(recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin));
      hist_non_matched_recojet_bb_phi->Fill(recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin));

      hist_non_matched_recojet_bb_tau_n1_subjettiness->Fill(recojet_antikt10UFO_Tau1_wta->at(idx_b1truth_recoak10_dRmin));
      hist_non_matched_recojet_bb_tau_n2_subjettiness->Fill(recojet_antikt10UFO_Tau2_wta->at(idx_b1truth_recoak10_dRmin));

      hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_b1truth_recoak10_dRmin));
      hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd->Fill(recojet_antikt10UFO_GN2Xv01_pqcd->at(idx_b1truth_recoak10_dRmin));
        
      tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_b1truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_b1truth_recoak10_dRmin);
      hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);  
      
      hist_non_matched_recojet_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_bb_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_bb_eta->Fill(recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin));
      hist_non_matched_recojet_bb_phi->Fill(recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin));

      hist_non_matched_recojet_bb_tau_n1_subjettiness->Fill(recojet_antikt10UFO_Tau1_wta->at(idx_b2truth_recoak10_dRmin));
      hist_non_matched_recojet_bb_tau_n2_subjettiness->Fill(recojet_antikt10UFO_Tau2_wta->at(idx_b2truth_recoak10_dRmin));

      hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_b2truth_recoak10_dRmin));
      hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd->Fill(recojet_antikt10UFO_GN2Xv01_pqcd->at(idx_b2truth_recoak10_dRmin));

      tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_b2truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_b2truth_recoak10_dRmin);
      hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);  
      
      if(tau_nProng->size()!=0){
	for(int ii=0; ii<tau_nProng->size(); ii++){
	  hist_non_matched_recojet_bb_tau_n_prong->Fill(tau_nProng->at(ii));
	}
      }
      
    }

    // Fill m, pt, eta... distribution of those recojets that were not matched to be boosted tautau (classes Rbb-Rtautau or Bbb-Rtautua)
    if( (class_event == 0) || (class_event == 2) ){

      float tau_n2_over_n1_subjettiness = 0;
      
      hist_non_matched_recojet_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_tautau_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_tautau_eta->Fill(recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin));
      hist_non_matched_recojet_tautau_phi->Fill(recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin));
      
      hist_non_matched_recojet_tautau_tau_n1_subjettiness->Fill(recojet_antikt10UFO_Tau1_wta->at(idx_tau1truth_recoak10_dRmin));
      hist_non_matched_recojet_tautau_tau_n2_subjettiness->Fill(recojet_antikt10UFO_Tau2_wta->at(idx_tau1truth_recoak10_dRmin));

      hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_tau1truth_recoak10_dRmin));
      hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Fill(recojet_antikt10UFO_GN2Xv01_pqcd->at(idx_tau1truth_recoak10_dRmin));
      
      tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_tau1truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_tau1truth_recoak10_dRmin);
      hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
    
      hist_non_matched_recojet_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_tautau_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin)/1000.);
      hist_non_matched_recojet_tautau_eta->Fill(recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin));
      hist_non_matched_recojet_tautau_phi->Fill(recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin));
      
      hist_non_matched_recojet_tautau_tau_n1_subjettiness->Fill(recojet_antikt10UFO_Tau1_wta->at(idx_tau2truth_recoak10_dRmin));
      hist_non_matched_recojet_tautau_tau_n2_subjettiness->Fill(recojet_antikt10UFO_Tau2_wta->at(idx_tau2truth_recoak10_dRmin));

      hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_tau2truth_recoak10_dRmin));
      hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Fill(recojet_antikt10UFO_GN2Xv01_pqcd->at(idx_tau2truth_recoak10_dRmin));
      
      tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_tau2truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_tau2truth_recoak10_dRmin);
      
      hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
      
      if(tau_nProng->size()!=0){
	for(int ii=0; ii<tau_nProng->size(); ii++){
	  hist_non_matched_recojet_tautau_tau_n_prong->Fill(tau_nProng->at(ii));
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
    hist_computed_HH_pt->Fill(reco_bbtt_HH_pt_BA/1000.);
    
    hist_truth_HH_m->Fill(truth_HH_m/1000.);
    hist_computed_HH_m->Fill(reco_bbtt_HH_m_BA/1000.);
  }
}


void fill_histograms_preselected_jets(){
  
  //**********************************************
  // Filling the mass, pT and eta distributions of the boosted bb and tautau objects
  //**********************************************
 
  if(matched_preselection == true){

    // Fill m, pt, eta... distributions of those recojets that were preselected matched to be boosted bb
    
    float tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_b1_preselected)/recojet_antikt10UFO_Tau1_wta->at(idx_b1_preselected);
    
    hist_matched_preselected_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b1_preselected)/1000.);
    hist_matched_preselected_bb_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected)/1000.);
    hist_matched_preselected_bb_eta->Fill(recojet_antikt10UFO_eta->at(idx_b1_preselected));
    hist_matched_preselected_bb_phi->Fill(recojet_antikt10UFO_phi->at(idx_b1_preselected));
    
    hist_matched_preselected_bb_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
    hist_matched_preselected_bb_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_b1_preselected));


    // Fill m, pt, eta... distributions of those recojets that were preselected matched to be boosted tautau
    
    tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(idx_tau1_preselected)/recojet_antikt10UFO_Tau1_wta->at(idx_tau1_preselected);
    
    hist_matched_preselected_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau1_preselected)/1000.);
    hist_matched_preselected_tautau_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected)/1000.);
    hist_matched_preselected_tautau_eta->Fill(recojet_antikt10UFO_eta->at(idx_tau1_preselected));
    hist_matched_preselected_tautau_phi->Fill(recojet_antikt10UFO_phi->at(idx_tau1_preselected));
    
    hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
    hist_matched_preselected_tautau_ak10_GN2Xv01_phbb->Fill(recojet_antikt10UFO_GN2Xv01_phbb->at(idx_tau1_preselected));
    
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

  /*
  inTree->SetBranchAddress("truth_HH_pt", &truth_HH_pt, &b_truth_HH_pt);
  inTree->SetBranchAddress("truth_HH_eta", &truth_HH_eta, &b_truth_HH_eta);
  inTree->SetBranchAddress("truth_HH_phi", &truth_HH_phi, &b_truth_HH_phi);
  inTree->SetBranchAddress("truth_HH_m", &truth_HH_m, &b_truth_HH_m);
  */

  inTree->SetBranchAddress("tau_nProng", &tau_nProng, &b_tau_nProng);

  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phbb", &recojet_antikt10UFO_GN2Xv01_phbb, &b_recojet_antikt10UFO_GN2Xv01_phbb);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_pqcd", &recojet_antikt10UFO_GN2Xv01_pqcd, &b_recojet_antikt10UFO_GN2Xv01_pqcd);
  
  inTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt, &b_recojet_antikt10UFO_NOSYS_pt);
  inTree->SetBranchAddress("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta, &b_recojet_antikt10UFO_eta);
  inTree->SetBranchAddress("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi, &b_recojet_antikt10UFO_phi);
  inTree->SetBranchAddress("recojet_antikt10UFO_m", &recojet_antikt10UFO_m, &b_recojet_antikt10UFO_m);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau1_wta", &recojet_antikt10UFO_Tau1_wta, &b_recojet_antikt10UFO_Tau1_wta);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau2_wta", &recojet_antikt10UFO_Tau2_wta, &b_recojet_antikt10UFO_Tau2_wta);

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

  outTree->Branch("truth_bb_pt", &truth_bb_pt);
  outTree->Branch("truth_bb_eta", &truth_bb_eta);
  outTree->Branch("truth_bb_phi", &truth_bb_phi);
  outTree->Branch("truth_bb_m", &truth_bb_m);

  outTree->Branch("truth_tautau_pt", &truth_tautau_pt);
  outTree->Branch("truth_tautau_eta", &truth_tautau_eta);
  outTree->Branch("truth_tautau_phi", &truth_tautau_phi);
  outTree->Branch("truth_tautau_m", &truth_tautau_m);

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

  outTree->Branch("tau_nProng", &tau_nProng);

  outTree->Branch("recojet_antikt10UFO_GN2Xv01_phbb", &recojet_antikt10UFO_GN2Xv01_phbb);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_pqcd", &recojet_antikt10UFO_GN2Xv01_pqcd);

  outTree->Branch("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt);
  outTree->Branch("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta);
  outTree->Branch("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi);
  outTree->Branch("recojet_antikt10UFO_m", &recojet_antikt10UFO_m);
  outTree->Branch("recojet_antikt10UFO_Tau1_wta", &recojet_antikt10UFO_Tau1_wta);
  outTree->Branch("recojet_antikt10UFO_Tau2_wta", &recojet_antikt10UFO_Tau2_wta);
  
  outTree->Branch("idx_b1truth_recoak10_dRmin", &idx_b1truth_recoak10_dRmin);
  outTree->Branch("idx_b2truth_recoak10_dRmin", &idx_b2truth_recoak10_dRmin);
  outTree->Branch("idx_tau1truth_recoak10_dRmin", &idx_tau1truth_recoak10_dRmin);
  outTree->Branch("idx_tau2truth_recoak10_dRmin", &idx_tau2truth_recoak10_dRmin);

  outTree->Branch("dR_min_b1truth_recoak10_fatjet", &dR_min_b1truth_recoak10_fatjet);
  outTree->Branch("dR_min_b2truth_recoak10_fatjet", &dR_min_b2truth_recoak10_fatjet);
  outTree->Branch("dR_min_tau1truth_recoak10_fatjet", &dR_min_tau1truth_recoak10_fatjet);
  outTree->Branch("dR_min_tau2truth_recoak10_fatjet", &dR_min_tau2truth_recoak10_fatjet);

  outTree->Branch("reco_bbtt_HH_pt_BA", &reco_bbtt_HH_pt_BA);
  outTree->Branch("reco_bbtt_HH_eta_BA", &reco_bbtt_HH_eta_BA);
  outTree->Branch("reco_bbtt_HH_phi_BA", &reco_bbtt_HH_phi_BA);
  outTree->Branch("reco_bbtt_HH_m_BA", &reco_bbtt_HH_m_BA);

  outTree->Branch("reco_bbtt_bb_pt_BA", &reco_bbtt_bb_pt_BA);
  outTree->Branch("reco_bbtt_bb_eta_BA", &reco_bbtt_bb_eta_BA);
  outTree->Branch("reco_bbtt_bb_phi_BA", &reco_bbtt_bb_phi_BA);
  outTree->Branch("reco_bbtt_bb_m_BA", &reco_bbtt_bb_m_BA);

  outTree->Branch("reco_bbtt_tautau_pt_BA", &reco_bbtt_tautau_pt_BA);
  outTree->Branch("reco_bbtt_tautau_eta_BA", &reco_bbtt_tautau_eta_BA);
  outTree->Branch("reco_bbtt_tautau_phi_BA", &reco_bbtt_tautau_phi_BA);
  outTree->Branch("reco_bbtt_tautau_m_BA", &reco_bbtt_tautau_m_BA);

  outTree->Branch("class_event", &class_event);
  outTree->Branch("passed_preselection", &passed_preselection);

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
  hist_matched_recojet_bb_phi->Write();
  hist_matched_recojet_tautau_phi->Write();
  
  hist_matched_recojet_bb_tau_n_prong->Write();
  hist_matched_recojet_tautau_tau_n_prong->Write();

  hist_matched_recojet_bb_tau_n1_subjettiness->Write();
  hist_matched_recojet_tautau_tau_n1_subjettiness->Write();
  hist_matched_recojet_bb_tau_n2_subjettiness->Write();
  hist_matched_recojet_tautau_tau_n2_subjettiness->Write();
  hist_matched_recojet_bb_tau_n2_over_n1_subjettiness->Write();
  hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Write();

  hist_matched_recojet_bb_ak10_GN2Xv01_phbb->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_phbb->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_pqcd->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Write();

  hist_matched_recojet_bb_dR->Write();
  hist_matched_recojet_tautau_dR->Write();

  //non_matched_recojets_histograms
  
  hist_non_matched_recojet_bb_m->Write();
  hist_non_matched_recojet_tautau_m->Write();
  hist_non_matched_recojet_bb_pt->Write();
  hist_non_matched_recojet_tautau_pt->Write();
  hist_non_matched_recojet_bb_eta->Write();
  hist_non_matched_recojet_tautau_eta->Write();
  hist_non_matched_recojet_bb_phi->Write();
  hist_non_matched_recojet_tautau_phi->Write();
  
  hist_non_matched_recojet_bb_tau_n_prong->Write();
  hist_non_matched_recojet_tautau_tau_n_prong->Write();

  hist_non_matched_recojet_bb_tau_n1_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n1_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n2_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n2_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Write();

  hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Write();
  
  hist_nevents_per_class->Write();
  hist2d_dR_per_class_bb->Write();
  hist2d_dR_per_class_tautau->Write();

  //matched_preselected_histograms
  
  hist_matched_preselected_bb_m->Write();
  hist_matched_preselected_tautau_m->Write();
  hist_matched_preselected_bb_pt->Write();
  hist_matched_preselected_tautau_pt->Write();
  hist_matched_preselected_bb_eta->Write();
  hist_matched_preselected_tautau_eta->Write();
  hist_matched_preselected_bb_phi->Write();
  hist_matched_preselected_tautau_phi->Write();
  
  hist_matched_preselected_bb_tau_n2_over_n1_subjettiness->Write();
  hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness->Write();

  hist_matched_preselected_bb_ak10_GN2Xv01_phbb->Write();
  hist_matched_preselected_tautau_ak10_GN2Xv01_phbb->Write();
  
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

  hist_acceptance_preselected_mHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_mHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_mHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_mHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_mHH_denominator_r1->Write();
  hist_acceptance_preselected_mHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_mHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_mHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_mHH_denominator_class3_r2->Write();
  
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

  hist_acceptance_preselected_ptHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_ptHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_ptHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_ptHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_r1->Write();
  hist_acceptance_preselected_ptHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_class3_r2->Write();
  
  //ratios for etaHH

  hist_acceptance_truth_etaHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_etaHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_etaHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_etaHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_etaHH_denominator_r1->Write();
  hist_acceptance_truth_etaHH_denominator_class0_r2->Write();
  hist_acceptance_truth_etaHH_denominator_class1_r2->Write();
  hist_acceptance_truth_etaHH_denominator_class2_r2->Write();
  hist_acceptance_truth_etaHH_denominator_class3_r2->Write();

  hist_acceptance_preselected_etaHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_etaHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_etaHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_etaHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_r1->Write();
  hist_acceptance_preselected_etaHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_class3_r2->Write();
  
  //ratios for phiHH

  hist_acceptance_truth_phiHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_phiHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_phiHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_phiHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_phiHH_denominator_r1->Write();
  hist_acceptance_truth_phiHH_denominator_class0_r2->Write();
  hist_acceptance_truth_phiHH_denominator_class1_r2->Write();
  hist_acceptance_truth_phiHH_denominator_class2_r2->Write();
  hist_acceptance_truth_phiHH_denominator_class3_r2->Write();

  hist_acceptance_preselected_phiHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_phiHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_phiHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_phiHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_r1->Write();
  hist_acceptance_preselected_phiHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_class3_r2->Write();
  
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

  hist_acceptance_all_Bbb_mHbb_numerator_r1_r2->Write();
  hist_acceptance_all_Bbb_mHbb_denominator_r2_numerator_r4->Write();
      
  hist_acceptance_truth_mHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_mHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_mHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_mHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_mHbb_denominator_r1->Write();
  hist_acceptance_truth_mHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_mHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_mHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_mHbb_denominator_class3_r2->Write();
  
  hist_acceptance_all_Bbb_truth_mHbb_numerator_r1_r2->Write();
  hist_acceptance_all_Bbb_truth_mHbb_denominator_r2_numerator_r4->Write();

  hist_acceptance_preselected_mHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_mHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_mHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_mHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_mHbb_denominator_r1->Write();
  hist_acceptance_preselected_mHbb_denominator_class0_r2->Write();
  hist_acceptance_preselected_mHbb_denominator_class1_r2->Write();
  hist_acceptance_preselected_mHbb_denominator_class2_r2->Write();
  hist_acceptance_preselected_mHbb_denominator_class3_r2->Write();
  
  hist_acceptance_all_Bbb_preselected_mHbb_numerator_r1_r2->Write();
  hist_acceptance_all_Bbb_preselected_mHbb_denominator_r2_numerator_r4->Write();
  
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

  hist_acceptance_all_Btautau_mHtautau_numerator_r1_r2->Write();
  hist_acceptance_all_Btautau_mHtautau_denominator_r2_numerator_r4->Write();
  
  hist_acceptance_truth_mHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_mHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_mHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_mHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_r1->Write();
  hist_acceptance_truth_mHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_mHtautau_denominator_class3_r2->Write();

  hist_acceptance_all_Btautau_truth_mHtautau_numerator_r1_r2->Write();
  hist_acceptance_all_Btautau_truth_mHtautau_denominator_r2_numerator_r4->Write();

  hist_acceptance_preselected_mHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_mHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_mHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_mHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_mHtautau_denominator_r1->Write();
  hist_acceptance_preselected_mHtautau_denominator_class0_r2->Write();
  hist_acceptance_preselected_mHtautau_denominator_class1_r2->Write();
  hist_acceptance_preselected_mHtautau_denominator_class2_r2->Write();
  hist_acceptance_preselected_mHtautau_denominator_class3_r2->Write();

  hist_acceptance_all_Btautau_preselected_mHtautau_numerator_r1_r2->Write();
  hist_acceptance_all_Btautau_preselected_mHtautau_denominator_r2_numerator_r4->Write();
  
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

  hist_acceptance_all_Bbb_ptHbb_numerator_r1_r2->Write();
  hist_acceptance_all_Bbb_ptHbb_denominator_r2_numerator_r4->Write();
  
  hist_acceptance_truth_ptHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_ptHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_ptHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_ptHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_r1->Write();
  hist_acceptance_truth_ptHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_ptHbb_denominator_class3_r2->Write();

  hist_acceptance_all_Bbb_truth_ptHbb_numerator_r1_r2->Write();
  hist_acceptance_all_Bbb_truth_ptHbb_denominator_r2_numerator_r4->Write();

  hist_acceptance_preselected_ptHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_ptHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_ptHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_ptHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_ptHbb_denominator_r1->Write();
  hist_acceptance_preselected_ptHbb_denominator_class0_r2->Write();
  hist_acceptance_preselected_ptHbb_denominator_class1_r2->Write();
  hist_acceptance_preselected_ptHbb_denominator_class2_r2->Write();
  hist_acceptance_preselected_ptHbb_denominator_class3_r2->Write();

  hist_acceptance_all_Bbb_preselected_ptHbb_numerator_r1_r2->Write();
  hist_acceptance_all_Bbb_preselected_ptHbb_denominator_r2_numerator_r4->Write();
      
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

  hist_acceptance_all_Btautau_ptHtautau_numerator_r1_r2->Write();
  hist_acceptance_all_Btautau_ptHtautau_denominator_r2_numerator_r4->Write();
  
  hist_acceptance_truth_ptHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_r1->Write();
  hist_acceptance_truth_ptHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_ptHtautau_denominator_class3_r2->Write();  

  hist_acceptance_all_Btautau_truth_ptHtautau_numerator_r1_r2->Write();
  hist_acceptance_all_Btautau_truth_ptHtautau_denominator_r2_numerator_r4->Write();

  hist_acceptance_preselected_ptHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_ptHtautau_denominator_r1->Write();
  hist_acceptance_preselected_ptHtautau_denominator_class0_r2->Write();
  hist_acceptance_preselected_ptHtautau_denominator_class1_r2->Write();
  hist_acceptance_preselected_ptHtautau_denominator_class2_r2->Write();
  hist_acceptance_preselected_ptHtautau_denominator_class3_r2->Write();  

  hist_acceptance_all_Btautau_preselected_ptHtautau_numerator_r1_r2->Write();
  hist_acceptance_all_Btautau_preselected_ptHtautau_denominator_r2_numerator_r4->Write();

  //ratios for etaHbb

  hist_acceptance_truth_etaHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_etaHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_etaHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_etaHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_r1->Write();
  hist_acceptance_truth_etaHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_class3_r2->Write();

  hist_acceptance_preselected_etaHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_r1->Write();
  hist_acceptance_preselected_etaHbb_denominator_class0_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_class1_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_class2_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_class3_r2->Write();

  //ratios for etaHtautau

  hist_acceptance_truth_etaHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_r1->Write();
  hist_acceptance_truth_etaHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_class3_r2->Write();

  hist_acceptance_preselected_etaHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_r1->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class0_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class1_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class2_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class3_r2->Write();

  //ratios for phiHbb

  hist_acceptance_truth_phiHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_phiHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_phiHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_phiHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_r1->Write();
  hist_acceptance_truth_phiHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_class3_r2->Write();

  hist_acceptance_preselected_phiHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_r1->Write();
  hist_acceptance_preselected_phiHbb_denominator_class0_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_class1_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_class2_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_class3_r2->Write();

  //ratios for phiHtautau

  hist_acceptance_truth_phiHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_r1->Write();
  hist_acceptance_truth_phiHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_class3_r2->Write();

  hist_acceptance_preselected_phiHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_r1->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class0_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class1_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class2_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class3_r2->Write();

  
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

  // ratios r3 and r4 for truth ptHH
  hist_acceptance_truth_ptHH_numerator_r3->Write();
  hist_acceptance_truth_ptHH_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth etaHH
  hist_acceptance_truth_etaHH_numerator_r3->Write();
  hist_acceptance_truth_etaHH_denominator_r3_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class0_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class1_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class2_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth phiHH
  hist_acceptance_truth_phiHH_numerator_r3->Write();
  hist_acceptance_truth_phiHH_denominator_r3_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class0_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class1_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class2_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class3_r4->Write();
  
  // ratios r3 and r4 for truth mHbb
  hist_acceptance_truth_mHbb_numerator_r3->Write();
  hist_acceptance_truth_mHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth ptHbb
  hist_acceptance_truth_ptHbb_numerator_r3->Write();
  hist_acceptance_truth_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth etaHbb
  hist_acceptance_truth_etaHbb_numerator_r3->Write();
  hist_acceptance_truth_etaHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth phiHbb
  hist_acceptance_truth_phiHbb_numerator_r3->Write();
  hist_acceptance_truth_phiHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class3_r4->Write();
  
  // ratios r3 and r4 for truth mHtautau
  hist_acceptance_truth_mHtautau_numerator_r3->Write();
  hist_acceptance_truth_mHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth ptHtautau
  hist_acceptance_truth_ptHtautau_numerator_r3->Write();
  hist_acceptance_truth_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth etaHtautau
  hist_acceptance_truth_etaHtautau_numerator_r3->Write();
  hist_acceptance_truth_etaHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class3_r4->Write();

  // ratios r3 and r4 for truth phiHtautau
  hist_acceptance_truth_phiHtautau_numerator_r3->Write();
  hist_acceptance_truth_phiHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class3_r4->Write();


  // ratios r3 and r4 for preselected truth mHH
  hist_acceptance_preselected_mHH_numerator_r3->Write();
  hist_acceptance_preselected_mHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth ptHH
  hist_acceptance_preselected_ptHH_numerator_r3->Write();
  hist_acceptance_preselected_ptHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth etaHH
  hist_acceptance_preselected_etaHH_numerator_r3->Write();
  hist_acceptance_preselected_etaHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth phiHH
  hist_acceptance_preselected_phiHH_numerator_r3->Write();
  hist_acceptance_preselected_phiHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class3_r4->Write();
  
  // ratios r3 and r4 for preselected truth mHbb
  hist_acceptance_preselected_mHbb_numerator_r3->Write();
  hist_acceptance_preselected_mHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth ptHbb
  hist_acceptance_preselected_ptHbb_numerator_r3->Write();
  hist_acceptance_preselected_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth etaHbb
  hist_acceptance_preselected_etaHbb_numerator_r3->Write();
  hist_acceptance_preselected_etaHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth phiHbb
  hist_acceptance_preselected_phiHbb_numerator_r3->Write();
  hist_acceptance_preselected_phiHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class3_r4->Write();
  
  // ratios r3 and r4 for preselected truth mHtautau
  hist_acceptance_preselected_mHtautau_numerator_r3->Write();
  hist_acceptance_preselected_mHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth ptHtautau
  hist_acceptance_preselected_ptHtautau_numerator_r3->Write();
  hist_acceptance_preselected_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth etaHtautau
  hist_acceptance_preselected_etaHtautau_numerator_r3->Write();
  hist_acceptance_preselected_etaHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class3_r4->Write();

  // ratios r3 and r4 for preselected truth phiHtautau
  hist_acceptance_preselected_phiHtautau_numerator_r3->Write();
  hist_acceptance_preselected_phiHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class3_r4->Write();

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

// This function set the values -99 for truth variables when HH->bbtautau is not identified
void default_values_for_truth_variables(){

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
  
  truth_HH_pt = -99;
  truth_HH_eta = -99;
  truth_HH_phi = -99;
  truth_HH_m = -99;

  truth_bb_pt = -99;
  truth_bb_eta = -99;
  truth_bb_phi = -99;
  truth_bb_m = -99;

  truth_tautau_pt = -99;
  truth_tautau_eta = -99;
  truth_tautau_phi = -99;
  truth_tautau_m = -99;
}

// This function set the values -99 for preselected variables when HH->bbtautau is not identified
void default_values_for_preselected_variables(){

  preselected_HH_pt = -99;
  preselected_HH_eta = -99;
  preselected_HH_phi = -99;
  preselected_HH_m = -99;
  
  preselected_bb_pt = -99;
  preselected_bb_eta = -99;
  preselected_bb_phi = -99;
  preselected_bb_m = -99;

  preselected_tautau_pt = -99;
  preselected_tautau_eta = -99;
  preselected_tautau_phi = -99;
  preselected_tautau_m = -99;

  idx_b1_preselected = -99;
  idx_b2_preselected = -99;
  idx_tau1_preselected = -99;
  idx_tau2_preselected = -99;
  
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
  /*
  cout << "Number of events that passed the resolved selection (counting b1_pt positive values): " << count_pos_resolved_b1_config << endl;
  cout << "Number of events that passed the resolved selection (counting b2_pt positive values): " << count_pos_resolved_b2_config << endl;
  cout << "Number of events that passed the resolved selection (counting tau1_pt positive values): " << count_pos_resolved_tau1_config << endl;
  cout << "Number of events that passed the resolved selection (counting tau2_pt positive values): " << count_pos_resolved_tau2_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_pt positive values): " << count_pos_resolved_HH_pt_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_m positive values): " << count_pos_resolved_HH_m_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_vis_pt positive values): " << count_pos_resolved_HH_vis_pt_config << endl;
  */
  
  cout << "Number of events that passed the resolved selection (counting bbtt_HH_vis_m positive values): " << count_pos_resolved_HH_vis_m_config << endl;

  /*
  cout << "Number of events that passed the resolved selection (counting all possible objects values): " << count_all_objects_resolved_config << endl;

  cout << "The number of positive values for truth_HH_pt is: " << count_truth_HH_pt_pos_values << endl;

  cout << "The number of positive values for truth_HH_m is: " << count_truth_HH_m_pos_values << endl;
  */
}
