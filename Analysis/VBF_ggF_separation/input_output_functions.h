// *************************************
// Declaration of some functions
// *************************************

//void plot_distributions(TString name_plot);
void fill_histograms();
void write_histograms();
void set_branch_address_inTree(TTree *inTree);
void define_output_branches(TTree *outTree);
void process_label(TString name_sample);

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void fill_histograms(){

  hist_boosted_tautau_ECF1->Fill(recojet_antikt10UFO_ECF1___NOSYS->at(idx_boosted_tautau)/1000.);
  hist_boosted_tautau_ECF2->Fill(recojet_antikt10UFO_ECF2___NOSYS->at(idx_boosted_tautau)/10000000.);
  hist_boosted_tautau_ECF3->Fill(recojet_antikt10UFO_ECF3___NOSYS->at(idx_boosted_tautau)/1000000000.);
  hist_boosted_tautau_Split12->Fill(recojet_antikt10UFO_Split12___NOSYS->at(idx_boosted_tautau)/1000.);
  hist_boosted_tautau_Split23->Fill(recojet_antikt10UFO_Split23___NOSYS->at(idx_boosted_tautau)/1000.);
  hist_boosted_tautau_n1_nsubjettiness->Fill(recojet_antikt10UFO_Tau1_wta___NOSYS->at(idx_boosted_tautau));
  hist_boosted_tautau_n2_nsubjettiness->Fill(recojet_antikt10UFO_Tau2_wta___NOSYS->at(idx_boosted_tautau));
  hist_boosted_tautau_n3_nsubjettiness->Fill(recojet_antikt10UFO_Tau3_wta___NOSYS->at(idx_boosted_tautau));
  hist_boosted_tautau_pt_NOSYS->Fill(recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_tautau)/1000.);
  hist_boosted_tautau_m->Fill(recojet_antikt10UFO_m___NOSYS->at(idx_boosted_tautau)/1000.);

  hist_boosted_bb_ECF1->Fill(recojet_antikt10UFO_ECF1___NOSYS->at(idx_boosted_bb)/1000.);
  hist_boosted_bb_ECF2->Fill(recojet_antikt10UFO_ECF2___NOSYS->at(idx_boosted_bb)/10000000.);
  hist_boosted_bb_ECF3->Fill(recojet_antikt10UFO_ECF3___NOSYS->at(idx_boosted_bb)/1000000000.);
  hist_boosted_bb_Split12->Fill(recojet_antikt10UFO_Split12___NOSYS->at(idx_boosted_bb)/1000.);
  hist_boosted_bb_Split23->Fill(recojet_antikt10UFO_Split23___NOSYS->at(idx_boosted_bb)/1000.);
  hist_boosted_bb_n1_nsubjettiness->Fill(recojet_antikt10UFO_Tau1_wta___NOSYS->at(idx_boosted_bb));
  hist_boosted_bb_n2_nsubjettiness->Fill(recojet_antikt10UFO_Tau2_wta___NOSYS->at(idx_boosted_bb));
  hist_boosted_bb_n3_nsubjettiness->Fill(recojet_antikt10UFO_Tau3_wta___NOSYS->at(idx_boosted_bb));
  hist_boosted_bb_pt_NOSYS->Fill(recojet_antikt10UFO_pt___NOSYS->at(idx_boosted_bb)/1000.);
  hist_boosted_bb_m->Fill(recojet_antikt10UFO_m___NOSYS->at(idx_boosted_bb)/1000.);

  hist_boosted_preselected_j12_m->Fill(preselected_j12_m/1000.);
  hist_boosted_preselected_j12_pt->Fill(preselected_j12_pt/1000.);
  hist_boosted_preselected_j12_eta->Fill(preselected_j12_eta);
  hist_boosted_preselected_j12_phi->Fill(preselected_j12_phi);
  hist_boosted_preselected_j12_deta->Fill(preselected_j12_deta);
  hist_boosted_preselected_j12_dphi->Fill(preselected_j12_dphi);
  hist_boosted_preselected_j12_dR->Fill(preselected_j12_dR);

  float eta_Hbb = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_bb);
  float eta_Htautau = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_tautau);
  float eta_jet1 = recojet_antikt4PFlow_eta___NOSYS->at(idx_preselected_small_j1_mjj_sel);
  float eta_jet2 = recojet_antikt4PFlow_eta___NOSYS->at(idx_preselected_small_j2_mjj_sel);
  
  float Zeppenfeld_Hbb_variable = std::abs( eta_Hbb-(eta_jet1+eta_jet2) )/2;
  float Zeppenfeld_Htautau_variable = std::abs( eta_Htautau-(eta_jet1+eta_jet2) )/2;
  float Zeppenfeld_jet12_variable = std::abs( preselected_j12_eta-(eta_jet1+eta_jet2) )/2; 

  hist_boosted_preselected_j12_Zeppenfeld_Hbb->Fill(Zeppenfeld_Hbb_variable);
  hist_boosted_preselected_j12_Zeppenfeld_Htautau->Fill(Zeppenfeld_Htautau_variable);
  hist_boosted_preselected_j12_Zeppenfeld_jet12->Fill(Zeppenfeld_jet12_variable);

  hist_boosted_preselected_bbtautau_system_m->Fill(preselected_bbtautau_system_m/1000.);
  hist_boosted_preselected_bbtautau_system_pt->Fill(preselected_bbtautau_system_pt/1000.);
  hist_boosted_preselected_bbtautau_system_eta->Fill(preselected_bbtautau_system_eta);
  hist_boosted_preselected_bbtautau_system_phi->Fill(preselected_bbtautau_system_phi);
  hist_boosted_preselected_bbtautau_system_deta->Fill(preselected_bbtautau_system_deta);
  hist_boosted_preselected_bbtautau_system_dphi->Fill(preselected_bbtautau_system_dphi);
  hist_boosted_preselected_bbtautau_system_dR->Fill(preselected_bbtautau_system_dR);

  hist_boosted_preselected_bb_j1_system_m->Fill(preselected_bb_j1_system_m/1000.);
  hist_boosted_preselected_bb_j1_system_pt->Fill(preselected_bb_j1_system_pt/1000.);
  hist_boosted_preselected_bb_j1_system_eta->Fill(preselected_bb_j1_system_eta);
  hist_boosted_preselected_bb_j1_system_phi->Fill(preselected_bb_j1_system_phi);
  hist_boosted_preselected_bb_j1_system_deta->Fill(preselected_bb_j1_system_deta);
  hist_boosted_preselected_bb_j1_system_dphi->Fill(preselected_bb_j1_system_dphi);
  hist_boosted_preselected_bb_j1_system_dR->Fill(preselected_bb_j1_system_dR);

  hist_boosted_preselected_bb_j2_system_m->Fill(preselected_bb_j2_system_m/1000.);
  hist_boosted_preselected_bb_j2_system_pt->Fill(preselected_bb_j2_system_pt/1000.);
  hist_boosted_preselected_bb_j2_system_eta->Fill(preselected_bb_j2_system_eta);
  hist_boosted_preselected_bb_j2_system_phi->Fill(preselected_bb_j2_system_phi);
  hist_boosted_preselected_bb_j2_system_deta->Fill(preselected_bb_j2_system_deta);
  hist_boosted_preselected_bb_j2_system_dphi->Fill(preselected_bb_j2_system_dphi);
  hist_boosted_preselected_bb_j2_system_dR->Fill(preselected_bb_j2_system_dR);

  hist_boosted_preselected_tautau_j1_system_m->Fill(preselected_tautau_j1_system_m/1000.);
  hist_boosted_preselected_tautau_j1_system_pt->Fill(preselected_tautau_j1_system_pt/1000.);
  hist_boosted_preselected_tautau_j1_system_eta->Fill(preselected_tautau_j1_system_eta);
  hist_boosted_preselected_tautau_j1_system_phi->Fill(preselected_tautau_j1_system_phi);
  hist_boosted_preselected_tautau_j1_system_deta->Fill(preselected_tautau_j1_system_deta);
  hist_boosted_preselected_tautau_j1_system_dphi->Fill(preselected_tautau_j1_system_dphi);
  hist_boosted_preselected_tautau_j1_system_dR->Fill(preselected_tautau_j1_system_dR);

  hist_boosted_preselected_tautau_j2_system_m->Fill(preselected_tautau_j2_system_m/1000.);
  hist_boosted_preselected_tautau_j2_system_pt->Fill(preselected_tautau_j2_system_pt/1000.);
  hist_boosted_preselected_tautau_j2_system_eta->Fill(preselected_tautau_j2_system_eta);
  hist_boosted_preselected_tautau_j2_system_phi->Fill(preselected_tautau_j2_system_phi);
  hist_boosted_preselected_tautau_j2_system_deta->Fill(preselected_tautau_j2_system_deta);
  hist_boosted_preselected_tautau_j2_system_dphi->Fill(preselected_tautau_j2_system_dphi);
  hist_boosted_preselected_tautau_j2_system_dR->Fill(preselected_tautau_j2_system_dR);

  hist_boosted_preselected_all_jets_system_m->Fill(preselected_all_jets_system_m/1000.);
  hist_boosted_preselected_all_jets_system_pt->Fill(preselected_all_jets_system_pt/1000.);
  hist_boosted_preselected_all_jets_system_eta->Fill(preselected_all_jets_system_eta);
  hist_boosted_preselected_all_jets_system_phi->Fill(preselected_all_jets_system_phi);
  hist_boosted_preselected_all_jets_system_deta->Fill(preselected_all_jets_system_deta);
  hist_boosted_preselected_all_jets_system_dphi->Fill(preselected_all_jets_system_dphi);
  hist_boosted_preselected_all_jets_system_dR->Fill(preselected_all_jets_system_dR);
  
  for(int ii=0; ii<recojet_antikt10UFO_ECF1___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb && ii!=idx_boosted_tautau){
      hist_non_boosted_jets_ECF1->Fill(recojet_antikt10UFO_ECF1___NOSYS->at(ii)/1000.);
    }
  }
  for(int ii=0; ii<recojet_antikt10UFO_ECF2___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb && ii!=idx_boosted_tautau){
      hist_non_boosted_jets_ECF2->Fill(recojet_antikt10UFO_ECF2___NOSYS->at(ii)/10000000.);
    }
  }
  for(int ii=0; ii<recojet_antikt10UFO_ECF3___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb && ii!=idx_boosted_tautau){
      hist_non_boosted_jets_ECF3->Fill(recojet_antikt10UFO_ECF3___NOSYS->at(ii)/1000000000.);
    }
  }
  for(int ii=0; ii<recojet_antikt10UFO_m___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb && ii!=idx_boosted_tautau){
      hist_non_boosted_jets_m->Fill(recojet_antikt10UFO_m___NOSYS->at(ii)/1000.);
    }
  }
  for(int ii=0; ii<recojet_antikt10UFO_pt___NOSYS->size(); ii++){
    if(ii!=idx_boosted_bb && ii!=idx_boosted_tautau){
      hist_non_boosted_jets_pt_NOSYS->Fill(recojet_antikt10UFO_pt___NOSYS->at(ii)/1000.);
    }
  }
  
}

void write_histograms(){

  //***********************************************************
  // Histograms for large R jets matched to be tautau
  //***********************************************************

  hist_boosted_tautau_ECF1->Write();
  hist_boosted_tautau_ECF2->Write();
  hist_boosted_tautau_ECF3->Write();
  hist_boosted_tautau_Split12->Write();
  hist_boosted_tautau_Split23->Write();
  hist_boosted_tautau_n1_nsubjettiness->Write();
  hist_boosted_tautau_n2_nsubjettiness->Write();
  hist_boosted_tautau_n3_nsubjettiness->Write();
  hist_boosted_tautau_pt_NOSYS->Write();
  hist_boosted_tautau_m->Write();

  //***********************************************************
  // Histograms for large R jets matched to be bb
  //***********************************************************
  
  hist_boosted_bb_ECF1->Write();
  hist_boosted_bb_ECF2->Write();
  hist_boosted_bb_ECF3->Write();
  hist_boosted_bb_Split12->Write();
  hist_boosted_bb_Split23->Write();
  hist_boosted_bb_n1_nsubjettiness->Write();
  hist_boosted_bb_n2_nsubjettiness->Write();
  hist_boosted_bb_n3_nsubjettiness->Write();
  hist_boosted_bb_pt_NOSYS->Write();
  hist_boosted_bb_m->Write();

  //***********************************************************
  // Histograms for large R jets matched to be jet 1 and jet 2 in the VBF topology
  //***********************************************************
  
  hist_boosted_preselected_j12_m->Write();
  hist_boosted_preselected_j12_pt->Write();
  hist_boosted_preselected_j12_eta->Write();
  hist_boosted_preselected_j12_phi->Write();
  hist_boosted_preselected_j12_deta->Write();
  hist_boosted_preselected_j12_dphi->Write();
  hist_boosted_preselected_j12_dR->Write();

  hist_boosted_preselected_bbtautau_system_m->Write();
  hist_boosted_preselected_bbtautau_system_pt->Write();
  hist_boosted_preselected_bbtautau_system_eta->Write();
  hist_boosted_preselected_bbtautau_system_phi->Write();
  hist_boosted_preselected_bbtautau_system_deta->Write();
  hist_boosted_preselected_bbtautau_system_dphi->Write();
  hist_boosted_preselected_bbtautau_system_dR->Write();

  hist_boosted_preselected_bb_j1_system_m->Write();
  hist_boosted_preselected_bb_j1_system_pt->Write();
  hist_boosted_preselected_bb_j1_system_eta->Write();
  hist_boosted_preselected_bb_j1_system_phi->Write();
  hist_boosted_preselected_bb_j1_system_deta->Write();
  hist_boosted_preselected_bb_j1_system_dphi->Write();
  hist_boosted_preselected_bb_j1_system_dR->Write();

  hist_boosted_preselected_bb_j2_system_m->Write();
  hist_boosted_preselected_bb_j2_system_pt->Write();
  hist_boosted_preselected_bb_j2_system_eta->Write();
  hist_boosted_preselected_bb_j2_system_phi->Write();
  hist_boosted_preselected_bb_j2_system_deta->Write();
  hist_boosted_preselected_bb_j2_system_dphi->Write();
  hist_boosted_preselected_bb_j2_system_dR->Write();

  hist_boosted_preselected_tautau_j1_system_m->Write();
  hist_boosted_preselected_tautau_j1_system_pt->Write();
  hist_boosted_preselected_tautau_j1_system_eta->Write();
  hist_boosted_preselected_tautau_j1_system_phi->Write();
  hist_boosted_preselected_tautau_j1_system_deta->Write();
  hist_boosted_preselected_tautau_j1_system_dphi->Write();
  hist_boosted_preselected_tautau_j1_system_dR->Write();

  hist_boosted_preselected_tautau_j2_system_m->Write();
  hist_boosted_preselected_tautau_j2_system_pt->Write();
  hist_boosted_preselected_tautau_j2_system_eta->Write();
  hist_boosted_preselected_tautau_j2_system_phi->Write();
  hist_boosted_preselected_tautau_j2_system_deta->Write();
  hist_boosted_preselected_tautau_j2_system_dphi->Write();
  hist_boosted_preselected_tautau_j2_system_dR->Write();

  hist_boosted_preselected_all_jets_system_m->Write();
  hist_boosted_preselected_all_jets_system_pt->Write();
  hist_boosted_preselected_all_jets_system_eta->Write();
  hist_boosted_preselected_all_jets_system_phi->Write();
  hist_boosted_preselected_all_jets_system_deta->Write();
  hist_boosted_preselected_all_jets_system_dphi->Write();
  hist_boosted_preselected_all_jets_system_dR->Write();

  hist_boosted_preselected_j12_Zeppenfeld_Hbb->Write();
  hist_boosted_preselected_j12_Zeppenfeld_Htautau->Write();
  hist_boosted_preselected_j12_Zeppenfeld_jet12->Write();

  hist_boosted_cutflow_small_jets->Write();
  
  //***********************************************************
  // Histograms for small R jets
  //***********************************************************

  hist_boosted_njets->Write();
  
  //***********************************************************
  // Histograms for large R jets non matched
  //***********************************************************
  
  hist_non_boosted_jets_ECF1->Write();
  hist_non_boosted_jets_ECF2->Write();
  hist_non_boosted_jets_ECF3->Write();
  hist_non_boosted_jets_m->Write();
  hist_non_boosted_jets_pt_NOSYS->Write();
  
}

// This function saves the branches info for a given tree in the variables defined above
void set_branch_address_inTree(TTree *inTree){

  // Declaration of branches for boosted tree
  
  inTree->SetBranchAddress("recojet_antikt10UFO_ECF1___NOSYS", &recojet_antikt10UFO_ECF1___NOSYS, &b_recojet_antikt10UFO_ECF1___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_ECF2___NOSYS", &recojet_antikt10UFO_ECF2___NOSYS, &b_recojet_antikt10UFO_ECF2___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_ECF3___NOSYS", &recojet_antikt10UFO_ECF3___NOSYS, &b_recojet_antikt10UFO_ECF3___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2XTauV00_disc___NOSYS", &recojet_antikt10UFO_GN2XTauV00_disc___NOSYS, &b_recojet_antikt10UFO_GN2XTauV00_disc___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phbb___NOSYS", &recojet_antikt10UFO_GN2Xv01_phbb___NOSYS, &b_recojet_antikt10UFO_GN2Xv01_phbb___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phcc___NOSYS", &recojet_antikt10UFO_GN2Xv01_phcc___NOSYS, &b_recojet_antikt10UFO_GN2Xv01_phcc___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS", &recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS, &b_recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_ptop___NOSYS", &recojet_antikt10UFO_GN2Xv01_ptop___NOSYS, &b_recojet_antikt10UFO_GN2Xv01_ptop___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_phbb___NOSYS", &recojet_antikt10UFO_GN2Xv02_phbb___NOSYS, &b_recojet_antikt10UFO_GN2Xv02_phbb___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_phcc___NOSYS", &recojet_antikt10UFO_GN2Xv02_phcc___NOSYS, &b_recojet_antikt10UFO_GN2Xv02_phcc___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS", &recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS, &b_recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv02_ptop___NOSYS", &recojet_antikt10UFO_GN2Xv02_ptop___NOSYS, &b_recojet_antikt10UFO_GN2Xv02_ptop___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS", &recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS, &b_recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS", &recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS, &b_recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS", &recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS, &b_recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS", &recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS, &b_recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_Split12___NOSYS", &recojet_antikt10UFO_Split12___NOSYS, &b_recojet_antikt10UFO_Split12___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_Split23___NOSYS", &recojet_antikt10UFO_Split23___NOSYS, &b_recojet_antikt10UFO_Split23___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau1_wta___NOSYS", &recojet_antikt10UFO_Tau1_wta___NOSYS, &b_recojet_antikt10UFO_Tau1_wta___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau2_wta___NOSYS", &recojet_antikt10UFO_Tau2_wta___NOSYS, &b_recojet_antikt10UFO_Tau2_wta___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau3_wta___NOSYS", &recojet_antikt10UFO_Tau3_wta___NOSYS, &b_recojet_antikt10UFO_Tau3_wta___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_eta___NOSYS", &recojet_antikt10UFO_eta___NOSYS, &b_recojet_antikt10UFO_eta___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_isAnalysisJet___NOSYS", &recojet_antikt10UFO_isAnalysisJet___NOSYS, &b_recojet_antikt10UFO_isAnalysisJet___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_isjet1___NOSYS", &recojet_antikt10UFO_isjet1___NOSYS, &b_recojet_antikt10UFO_isjet1___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_isjet2___NOSYS", &recojet_antikt10UFO_isjet2___NOSYS, &b_recojet_antikt10UFO_isjet2___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_m___NOSYS", &recojet_antikt10UFO_m___NOSYS, &b_recojet_antikt10UFO_m___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_phi___NOSYS", &recojet_antikt10UFO_phi___NOSYS, &b_recojet_antikt10UFO_phi___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_pt___NOSYS", &recojet_antikt10UFO_pt___NOSYS, &b_recojet_antikt10UFO_pt___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS);
  inTree->SetBranchAddress("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS, &b_recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS);

  inTree->SetBranchAddress("recojet_antikt4PFlow_m___NOSYS", &recojet_antikt4PFlow_m___NOSYS, &b_recojet_antikt4PFlow_m___NOSYS);
  inTree->SetBranchAddress("recojet_antikt4PFlow_eta___NOSYS", &recojet_antikt4PFlow_eta___NOSYS, &b_recojet_antikt4PFlow_eta___NOSYS);
  inTree->SetBranchAddress("recojet_antikt4PFlow_phi___NOSYS", &recojet_antikt4PFlow_phi___NOSYS, &b_recojet_antikt4PFlow_phi___NOSYS);
  inTree->SetBranchAddress("recojet_antikt4PFlow_pt___NOSYS", &recojet_antikt4PFlow_pt___NOSYS, &b_recojet_antikt4PFlow_pt___NOSYS);
  
}

void define_output_branches(TTree *outTree){

  // Declaration of branches for boosted tree
  
  outTree->Branch("recojet_antikt10UFO_ECF1___NOSYS", &recojet_antikt10UFO_ECF1___NOSYS);
  outTree->Branch("recojet_antikt10UFO_ECF2___NOSYS", &recojet_antikt10UFO_ECF2___NOSYS);
  outTree->Branch("recojet_antikt10UFO_ECF3___NOSYS", &recojet_antikt10UFO_ECF3___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2XTauV00_disc___NOSYS", &recojet_antikt10UFO_GN2XTauV00_disc___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_phbb___NOSYS", &recojet_antikt10UFO_GN2Xv01_phbb___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_phcc___NOSYS", &recojet_antikt10UFO_GN2Xv01_phcc___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS", &recojet_antikt10UFO_GN2Xv01_pqcd___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_ptop___NOSYS", &recojet_antikt10UFO_GN2Xv01_ptop___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv02_phbb___NOSYS", &recojet_antikt10UFO_GN2Xv02_phbb___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv02_phcc___NOSYS", &recojet_antikt10UFO_GN2Xv02_phcc___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS", &recojet_antikt10UFO_GN2Xv02_pqcd___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GN2Xv02_ptop___NOSYS", &recojet_antikt10UFO_GN2Xv02_ptop___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS", &recojet_antikt10UFO_GhostBHadronsFinalCount___NOSYS);
  outTree->Branch("recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS", &recojet_antikt10UFO_GhostCHadronsFinalCount___NOSYS);
  outTree->Branch("recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS", &recojet_antikt10UFO_R10TruthLabel_R21Precision_2022v1___NOSYS);
  outTree->Branch("recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS", &recojet_antikt10UFO_R10TruthLabel_R22v1___NOSYS);
  outTree->Branch("recojet_antikt10UFO_Split12___NOSYS", &recojet_antikt10UFO_Split12___NOSYS);
  outTree->Branch("recojet_antikt10UFO_Split23___NOSYS", &recojet_antikt10UFO_Split23___NOSYS);
  outTree->Branch("recojet_antikt10UFO_Tau1_wta___NOSYS", &recojet_antikt10UFO_Tau1_wta___NOSYS);
  outTree->Branch("recojet_antikt10UFO_Tau2_wta___NOSYS", &recojet_antikt10UFO_Tau2_wta___NOSYS);
  outTree->Branch("recojet_antikt10UFO_Tau3_wta___NOSYS", &recojet_antikt10UFO_Tau3_wta___NOSYS);
  outTree->Branch("recojet_antikt10UFO_eta___NOSYS", &recojet_antikt10UFO_eta___NOSYS);
  outTree->Branch("recojet_antikt10UFO_isAnalysisJet___NOSYS", &recojet_antikt10UFO_isAnalysisJet___NOSYS);
  outTree->Branch("recojet_antikt10UFO_isjet1___NOSYS", &recojet_antikt10UFO_isjet1___NOSYS);
  outTree->Branch("recojet_antikt10UFO_isjet2___NOSYS", &recojet_antikt10UFO_isjet2___NOSYS);
  outTree->Branch("recojet_antikt10UFO_m___NOSYS", &recojet_antikt10UFO_m___NOSYS);
  outTree->Branch("recojet_antikt10UFO_phi___NOSYS", &recojet_antikt10UFO_phi___NOSYS);
  outTree->Branch("recojet_antikt10UFO_pt___NOSYS", &recojet_antikt10UFO_pt___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p25___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p37___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p3___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p46___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p58___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p74___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_0p94___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p25___NOSYS);
  outTree->Branch("recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS", &recojet_antikt10UFO_xbb_select_GN2Xv01_FlatMassQCDEff_1p55___NOSYS);

  outTree->Branch("recojet_antikt4PFlow_m___NOSYS", &recojet_antikt4PFlow_m___NOSYS);
  outTree->Branch("recojet_antikt4PFlow_eta___NOSYS", &recojet_antikt4PFlow_eta___NOSYS);
  outTree->Branch("recojet_antikt4PFlow_phi___NOSYS", &recojet_antikt4PFlow_phi___NOSYS);
  outTree->Branch("recojet_antikt4PFlow_pt___NOSYS", &recojet_antikt4PFlow_pt___NOSYS);

  // Variables defined for VBF topology

  outTree->Branch("process_name", &process_name);
  outTree->Branch("name_output_root_file", &name_output_root_file);
  outTree->Branch("process_type_like", &process_type_like);

  outTree->Branch("idx_boosted_bb", &idx_boosted_bb);
  outTree->Branch("idx_boosted_tautau", &idx_boosted_tautau);
  outTree->Branch("is_boosted_bb", &is_boosted_bb);
  outTree->Branch("is_boosted_tautau", &is_boosted_tautau);
  outTree->Branch("is_boosted_bbtautau", &is_boosted_bbtautau);
  outTree->Branch("idx_jet1_VBF_topology", &idx_preselected_small_j1_mjj_sel);
  outTree->Branch("idx_jet2_VBF_topology", &idx_preselected_small_j2_mjj_sel);
  outTree->Branch("is_jet12_matched", &matched_preselected_j12_mjj_sel);
  
  outTree->Branch("count_bb_candidates", &count_bb_candidates);
  outTree->Branch("count_tautau_candidates", &count_tautau_candidates);

  outTree->Branch("preselected_j12_m", &preselected_j12_m);
  outTree->Branch("preselected_j12_pt", &preselected_j12_pt);
  outTree->Branch("preselected_j12_eta", &preselected_j12_eta);
  outTree->Branch("preselected_j12_phi", &preselected_j12_phi);
  outTree->Branch("preselected_j12_deta", &preselected_j12_deta);
  outTree->Branch("preselected_j12_dphi", &preselected_j12_dphi);
  outTree->Branch("preselected_j12_dR", &preselected_j12_dR);

  outTree->Branch("preselected_bbtautau_system_m", &preselected_bbtautau_system_m);
  outTree->Branch("preselected_bbtautau_system_pt", &preselected_bbtautau_system_pt);
  outTree->Branch("preselected_bbtautau_system_eta", &preselected_bbtautau_system_eta);
  outTree->Branch("preselected_bbtautau_system_phi", &preselected_bbtautau_system_phi);
  outTree->Branch("preselected_bbtautau_system_deta", &preselected_bbtautau_system_deta);
  outTree->Branch("preselected_bbtautau_system_dphi", &preselected_bbtautau_system_dphi);
  outTree->Branch("preselected_bbtautau_system_dR", &preselected_bbtautau_system_dR);

  // Boosted bb and small jets j1 variables                                                                                   
  outTree->Branch("preselected_bb_j1_system_m", &preselected_bb_j1_system_m);
  outTree->Branch("preselected_bb_j1_system_pt", &preselected_bb_j1_system_pt);
  outTree->Branch("preselected_bb_j1_system_eta", &preselected_bb_j1_system_eta);
  outTree->Branch("preselected_bb_j1_system_phi", &preselected_bb_j1_system_phi);
  outTree->Branch("preselected_bb_j1_system_deta", &preselected_bb_j1_system_deta);
  outTree->Branch("preselected_bb_j1_system_dphi", &preselected_bb_j1_system_dphi);
  outTree->Branch("preselected_bb_j1_system_dR", &preselected_bb_j1_system_dR);

  // Boosted tautau and small jets j1 variables                                                                               
  outTree->Branch("preselected_tautau_j1_system_m", &preselected_tautau_j1_system_m);
  outTree->Branch("preselected_tautau_j1_system_pt", &preselected_tautau_j1_system_pt);
  outTree->Branch("preselected_tautau_j1_system_eta", &preselected_tautau_j1_system_eta);
  outTree->Branch("preselected_tautau_j1_system_phi", &preselected_tautau_j1_system_phi);
  outTree->Branch("preselected_tautau_j1_system_deta", &preselected_tautau_j1_system_deta);
  outTree->Branch("preselected_tautau_j1_system_dphi", &preselected_tautau_j1_system_dphi);
  outTree->Branch("preselected_tautau_j1_system_dR", &preselected_tautau_j1_system_dR);
  
  // Boosted bb and small jets j2 variables                                                                                   

  outTree->Branch("preselected_bb_j2_system_m", &preselected_bb_j2_system_m);
  outTree->Branch("preselected_bb_j2_system_pt", &preselected_bb_j2_system_pt);
  outTree->Branch("preselected_bb_j2_system_eta", &preselected_bb_j2_system_eta);
  outTree->Branch("preselected_bb_j2_system_phi", &preselected_bb_j2_system_phi);
  outTree->Branch("preselected_bb_j2_system_deta", &preselected_bb_j2_system_deta);
  outTree->Branch("preselected_bb_j2_system_dphi", &preselected_bb_j2_system_dphi);
  outTree->Branch("preselected_bb_j2_system_dR", &preselected_bb_j2_system_dR);
  
  // Boosted tautau and small jets j1 variables                                                                               
  outTree->Branch("preselected_tautau_j2_system_m", &preselected_tautau_j2_system_m);
  outTree->Branch("preselected_tautau_j2_system_pt", &preselected_tautau_j2_system_pt);
  outTree->Branch("preselected_tautau_j2_system_eta", &preselected_tautau_j2_system_eta);
  outTree->Branch("preselected_tautau_j2_system_phi", &preselected_tautau_j2_system_phi);
  outTree->Branch("preselected_tautau_j2_system_deta", &preselected_tautau_j2_system_deta);
  outTree->Branch("preselected_tautau_j2_system_dphi", &preselected_tautau_j2_system_dphi);
  outTree->Branch("preselected_tautau_j2_system_dR", &preselected_tautau_j2_system_dR);
  
  // All jets system variables                                                                                                
  outTree->Branch("preselected_all_jets_system_m", &preselected_all_jets_system_m);
  outTree->Branch("preselected_all_jets_system_pt", &preselected_all_jets_system_pt);
  outTree->Branch("preselected_all_jets_system_eta", &preselected_all_jets_system_eta);
  outTree->Branch("preselected_all_jets_system_phi", &preselected_all_jets_system_phi);
  outTree->Branch("preselected_all_jets_system_deta", &preselected_all_jets_system_deta);
  outTree->Branch("preselected_all_jets_system_dphi", &preselected_all_jets_system_dphi);
  outTree->Branch("preselected_all_jets_system_dR", &preselected_all_jets_system_dR);

  outTree->Branch("smallR_jets_n", &smallR_jets_n);
  outTree->Branch("largeR_jets_n", &largeR_jets_n);

}

void process_label(TString name_sample){
  
  // ggF processes had-had channel
  if(name_sample.Contains("ggF")==true){
    process_name = "ggF HH SM had-had channel";
    name_output_root_file = "ggF_SM_hh_600459.root";
    process_type_like = 0; // For ggF we choose 0
  }                                       
                                                                                       
  //vbf processes had-had channel
  //if(name_sample.Contains("502982")==true){
  if(name_sample.Contains("vbf")==true){
    process_name = "VBF HH SM had-had channel";
    name_output_root_file = "VBF_SM_hh_502982.root";
    process_type_like = 1; // for VBF we choose 1
  }                                       
  
}   
