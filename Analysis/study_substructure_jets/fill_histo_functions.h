// *************************************
// Definition of the functions declared above
// *************************************

void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m);
void fill_acceptance_ratios();
void fill_all_events_histograms_acceptance_ratios();
void fill_resolved_selection_histograms_acceptance_ratios();
void fill_preselected_events_histograms_acceptance_ratios();
void fill_boosted_events_histograms_acceptance_ratios();
void fill_histograms_matched_truth_recojets();
void fill_histograms_preselected_jets();


void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m){
  
  TLorentzVector jet1  = TLorentzVector();
  TLorentzVector jet2  = TLorentzVector();

  jet1.SetPtEtaPhiM(jet1_pt, jet1_eta, jet1_phi, jet1_m);
  jet2.SetPtEtaPhiM(jet2_pt, jet2_eta, jet2_phi, jet2_m);

  dR = jet1.DeltaR(jet2);
}

void fill_acceptance_ratios(){

  // all events histograms

  fill_all_events_histograms_acceptance_ratios();

  // resolved selection event histograms
  if(bbtt_HH_vis_m > 0){
    fill_resolved_selection_histograms_acceptance_ratios();
  }
  
  // Boosted analysis events histograms
  if( class_event != -1 ){
    fill_boosted_events_histograms_acceptance_ratios();
  }
  
  // Preselected analysis events histograms
  if( matched_preselection == true ){
    fill_preselected_events_histograms_acceptance_ratios();
  }

}

void fill_all_events_histograms_acceptance_ratios(){

  // all events histograms
  hist_acceptance_mHH_denominator_r3_r4->Fill(reco_bbtt_HH_m_BA/1000.);
  //hist_acceptance_ptHH_denominator_r3_r4->Fill(reco_bbtt_HH_pt_BA/1000.);
  //hist_acceptance_etaHH_denominator_r3_r4->Fill(reco_bbtt_HH_eta_BA);
  //hist_acceptance_phiHH_denominator_r3_r4->Fill(reco_bbtt_HH_phi_BA);

  //hist_acceptance_mHbb_denominator_r3_r4->Fill(reco_bbtt_bb_m_BA/1000.);
  hist_acceptance_ptHbb_denominator_r3_r4->Fill(reco_bbtt_bb_pt_BA/1000.);
  //hist_acceptance_etaHbb_denominator_r3_r4->Fill(reco_bbtt_bb_eta_BA);
  //hist_acceptance_phiHbb_denominator_r3_r4->Fill(reco_bbtt_bb_phi_BA);

  //hist_acceptance_mHtautau_denominator_r3_r4->Fill(reco_bbtt_tautau_m_BA/1000.);
  hist_acceptance_ptHtautau_denominator_r3_r4->Fill(reco_bbtt_tautau_pt_BA/1000.);
  //hist_acceptance_etaHtautau_denominator_r3_r4->Fill(reco_bbtt_tautau_eta_BA);
  //hist_acceptance_phiHtautau_denominator_r3_r4->Fill(reco_bbtt_tautau_phi_BA);

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
  //hist_acceptance_ptHH_denominator_r1->Fill(reco_bbtt_HH_pt_BA/1000.);
  //hist_acceptance_etaHH_denominator_r1->Fill(reco_bbtt_HH_eta_BA);
  //hist_acceptance_phiHH_denominator_r1->Fill(reco_bbtt_HH_phi_BA);

  //hist_acceptance_mHbb_denominator_r1->Fill(reco_bbtt_bb_m_BA/1000.);
  hist_acceptance_ptHbb_denominator_r1->Fill(reco_bbtt_bb_pt_BA/1000.);
  //hist_acceptance_etaHbb_denominator_r1->Fill(reco_bbtt_bb_eta_BA);
  //hist_acceptance_phiHbb_denominator_r1->Fill(reco_bbtt_bb_phi_BA);

  //hist_acceptance_mHtautau_denominator_r1->Fill(reco_bbtt_tautau_m_BA/1000.);
  hist_acceptance_ptHtautau_denominator_r1->Fill(reco_bbtt_tautau_pt_BA/1000.);
  //hist_acceptance_etaHtautau_denominator_r1->Fill(reco_bbtt_tautau_eta_BA);
  //hist_acceptance_phiHtautau_denominator_r1->Fill(reco_bbtt_tautau_phi_BA);

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
  //hist_acceptance_ptHH_numerator_r3->Fill(reco_bbtt_HH_pt_BA/1000.);
  //hist_acceptance_etaHH_numerator_r3->Fill(reco_bbtt_HH_eta_BA);
  //hist_acceptance_phiHH_numerator_r3->Fill(reco_bbtt_HH_phi_BA);

  //hist_acceptance_mHbb_numerator_r3->Fill(reco_bbtt_bb_m_BA/1000.);
  hist_acceptance_ptHbb_numerator_r3->Fill(reco_bbtt_bb_pt_BA/1000.);
  //hist_acceptance_etaHbb_numerator_r3->Fill(reco_bbtt_bb_eta_BA);
  //hist_acceptance_phiHbb_numerator_r3->Fill(reco_bbtt_bb_phi_BA);

  //hist_acceptance_mHtautau_numerator_r3->Fill(reco_bbtt_tautau_m_BA/1000.);
  hist_acceptance_ptHtautau_numerator_r3->Fill(reco_bbtt_tautau_pt_BA/1000.);
  //hist_acceptance_etaHtautau_numerator_r3->Fill(reco_bbtt_tautau_eta_BA);
  //hist_acceptance_phiHtautau_numerator_r3->Fill(reco_bbtt_tautau_phi_BA);

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

    // Reco variables
    hist_acceptance_mHH_denominator_class3_r2->Fill(reco_bbtt_HH_m_BA/1000.);
    //hist_acceptance_ptHH_denominator_class3_r2->Fill(reco_bbtt_HH_pt_BA/1000.);
    //hist_acceptance_etaHH_denominator_class3_r2->Fill(reco_bbtt_HH_eta_BA);
    //hist_acceptance_phiHH_denominator_class3_r2->Fill(reco_bbtt_HH_phi_BA);

    //hist_acceptance_mHbb_denominator_class3_r2->Fill(reco_bbtt_bb_m_BA/1000.);
    hist_acceptance_ptHbb_denominator_class3_r2->Fill(reco_bbtt_bb_pt_BA/1000.);
    //hist_acceptance_etaHbb_denominator_class3_r2->Fill(reco_bbtt_bb_eta_BA);
    //hist_acceptance_phiHbb_denominator_class3_r2->Fill(reco_bbtt_bb_phi_BA);

    //hist_acceptance_mHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_m_BA/1000.);
    hist_acceptance_ptHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_pt_BA/1000.);
    //hist_acceptance_etaHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_eta_BA);
    //hist_acceptance_phiHtautau_denominator_class3_r2->Fill(reco_bbtt_tautau_phi_BA);

    // truth objects
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

    // Reco variables
    
    hist_acceptance_mHH_numerator_class3_r4->Fill(reco_bbtt_HH_m_BA/1000.);
    //hist_acceptance_ptHH_numerator_class3_r4->Fill(reco_bbtt_HH_pt_BA/1000.);
    //hist_acceptance_etaHH_numerator_class3_r4->Fill(reco_bbtt_HH_eta_BA);
    //hist_acceptance_phiHH_numerator_class3_r4->Fill(reco_bbtt_HH_phi_BA);

    //hist_acceptance_mHbb_numerator_class3_r4->Fill(reco_bbtt_bb_m_BA/1000.);
    hist_acceptance_ptHbb_numerator_class3_r4->Fill(reco_bbtt_bb_pt_BA/1000.);
    //hist_acceptance_etaHbb_numerator_class3_r4->Fill(reco_bbtt_bb_eta_BA);
    //hist_acceptance_phiHbb_numerator_class3_r4->Fill(reco_bbtt_bb_phi_BA);

    //hist_acceptance_mHtautau_numerator_class3_r4->Fill(reco_bbtt_tautau_m_BA/1000.);
    hist_acceptance_ptHtautau_numerator_class3_r4->Fill(reco_bbtt_tautau_pt_BA/1000.);
    //hist_acceptance_etaHtautau_numerator_class3_r4->Fill(reco_bbtt_tautau_eta_BA);
    //hist_acceptance_phiHtautau_numerator_class3_r4->Fill(reco_bbtt_tautau_phi_BA);

    // truth variables
    
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

      // Reco variables

      hist_acceptance_mHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_m_BA/1000.);
      //hist_acceptance_ptHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_pt_BA/1000.);
      //hist_acceptance_etaHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_eta_BA);
      //hist_acceptance_phiHH_numerator_class3_r1_r2->Fill(reco_bbtt_HH_phi_BA);

      //hist_acceptance_mHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_m_BA/1000.);
      hist_acceptance_ptHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_pt_BA/1000.);
      //hist_acceptance_etaHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_eta_BA);
      //hist_acceptance_phiHbb_numerator_class3_r1_r2->Fill(reco_bbtt_bb_phi_BA);

      //hist_acceptance_mHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_m_BA/1000.);
      hist_acceptance_ptHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_pt_BA/1000.);
      //hist_acceptance_etaHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_eta_BA);
      //hist_acceptance_phiHtautau_numerator_class3_r1_r2->Fill(reco_bbtt_tautau_phi_BA);

      // truth variables
      
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

      
      float min_tagger_Hbb_value = 0.85;
      float value_phbb = 0;
      
      float max_nsubjetiness_value_for_bb = 0.45;
      float min_nsubjetiness_value_for_bb = 0.05;
      
      float tau_n2_over_n1_subjettiness_bb = 0;
      
      bool taggerHbb_score_cut = false;
      value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(idx_b1truth_recoak10_dRmin);
      
      if(value_phbb >= min_tagger_Hbb_value){
	taggerHbb_score_cut = true;
	if(passed_preselection == true){
	  hist_matched_recojet_bb_m_only_Hbb_tagger->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
	}
      }
      
      bool nsubjettiness_cut = false;
      tau_n2_over_n1_subjettiness_bb = recojet_antikt10UFO_Tau2_wta->at(idx_b1truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_b1truth_recoak10_dRmin);
      if( (tau_n2_over_n1_subjettiness_bb <= max_nsubjetiness_value_for_bb) && (tau_n2_over_n1_subjettiness_bb >= min_nsubjetiness_value_for_bb) ){
	nsubjettiness_cut = true;
	if(passed_preselection == true){
	  hist_matched_recojet_bb_m_only_nsubjettiness->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
	}
      }
      
      if( (taggerHbb_score_cut == true) && (nsubjettiness_cut == true) ){
	hist_matched_recojet_bb_m_until_nsubjettiness->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
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


      float min_tagger_Hbb_value = 0.85;
      float value_phbb = 0;
      
      float max_nsubjetiness_value_for_tautau = 0.30;
      float min_nsubjetiness_value_for_tautau = 0.05;
      
      float tau_n2_over_n1_subjettiness_tautau = 0;
      
      bool taggerHbb_score_cut = false;
      value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(idx_tau1truth_recoak10_dRmin);
      
      if(value_phbb < min_tagger_Hbb_value){
	taggerHbb_score_cut = true;
	if(passed_preselection == true){
	  hist_matched_recojet_tautau_m_only_Hbb_tagger->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
	}
      }
      
      bool nsubjettiness_cut = false;
      tau_n2_over_n1_subjettiness_tautau = recojet_antikt10UFO_Tau2_wta->at(idx_tau1truth_recoak10_dRmin)/recojet_antikt10UFO_Tau1_wta->at(idx_tau1truth_recoak10_dRmin);
      if( (tau_n2_over_n1_subjettiness_tautau <= max_nsubjetiness_value_for_tautau) && (tau_n2_over_n1_subjettiness_tautau >= min_nsubjetiness_value_for_tautau) ){
	nsubjettiness_cut = true;
	if(passed_preselection == true){
	  hist_matched_recojet_tautau_m_only_nsubjettiness->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
	}
      }
      
      if( (taggerHbb_score_cut == true) && (nsubjettiness_cut == true) ){
	hist_matched_recojet_tautau_m_until_nsubjettiness->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
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

  
  // Fill number of jets with taggerHbb score >= 0.85 per event

  float min_taggerHbb_score = 0.85;
  int n_tagged_bb_jets = 0;
  
  for(Int_t ii=0; ii<recojet_antikt10UFO_GN2Xv01_phbb->size(); ii++){
    if(recojet_antikt10UFO_GN2Xv01_phbb->at(ii) >= min_taggerHbb_score){
      n_tagged_bb_jets++;
    }
  }
  hist_taggedHbb_recojet_bb_per_event->Fill(n_tagged_bb_jets); 

  // Fill n2/n1 subjettiness for non preselected boosted bb jets. This is done to known the distribution of possible candidates for boosted tautau when there is a matched preselection for Hbb

  if( matched_preselected_bb==true ){
    for(Int_t ii=0; ii<recojet_antikt10UFO_Tau2_wta->size(); ii++){
      float tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
      if( ii != idx_b1_preselected ){
	hist_candidates_preselected_tautau_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
	if( matched_preselected_tautau==true ){
	  if( ii == idx_tau1_preselected ){
	    hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
	  }
	}
      }
      if( ii == idx_b1_preselected ){
	hist_matched_preselected_bb_tau_n2_over_n1_subjettiness->Fill(tau_n2_over_n1_subjettiness);
      }
    }
  }
  
}
