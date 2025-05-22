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

  hist_boosted_jet12_m->Fill(two_jets_j12_m/1000.);
  hist_boosted_jet12_pt->Fill(two_jets_j12_pt/1000.);
  hist_boosted_jet12_eta->Fill(two_jets_j12_eta);
  hist_boosted_jet12_phi->Fill(two_jets_j12_phi);
  hist_boosted_jet12_deta->Fill(two_jets_j12_deta);
  hist_boosted_jet12_dphi->Fill(two_jets_j12_dphi);
  hist_boosted_jet12_dR->Fill(two_jets_j12_dR);

  float eta_Hbb = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_bb);
  float eta_Htautau = recojet_antikt10UFO_eta___NOSYS->at(idx_boosted_tautau);
  float eta_jet1 = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet1_VBF_topology);
  float eta_jet2 = recojet_antikt4PFlow_eta___NOSYS->at(idx_jet2_VBF_topology);
  
  float Zeppenfeld_Hbb_variable = std::abs( eta_Hbb-(eta_jet1+eta_jet2) )/2;
  float Zeppenfeld_Htautau_variable = std::abs( eta_Htautau-(eta_jet1+eta_jet2) )/2;
  float Zeppenfeld_jet12_variable = std::abs( two_jets_j12_eta-(eta_jet1+eta_jet2) )/2; 

  hist_boosted_jet12_Zeppenfeld_Hbb->Fill(Zeppenfeld_Hbb_variable);
  hist_boosted_jet12_Zeppenfeld_Htautau->Fill(Zeppenfeld_Htautau_variable);
  hist_boosted_jet12_Zeppenfeld_jet12->Fill(Zeppenfeld_jet12_variable);

  hist_boosted_bbtautau_m->Fill(boosted_bb_tautau_system_m/1000.);
  hist_boosted_bbtautau_pt->Fill(boosted_bb_tautau_system_pt/1000.);
  hist_boosted_bbtautau_eta->Fill(boosted_bb_tautau_system_eta);
  hist_boosted_bbtautau_phi->Fill(boosted_bb_tautau_system_phi);
  hist_boosted_bbtautau_deta->Fill(boosted_bb_tautau_system_deta);
  hist_boosted_bbtautau_dphi->Fill(boosted_bb_tautau_system_dphi);
  hist_boosted_bbtautau_dR->Fill(boosted_bb_tautau_system_dR);

  hist_boosted_bb_jet1_m->Fill(boosted_bb_j1_system_m/1000.);
  hist_boosted_bb_jet1_pt->Fill(boosted_bb_j1_system_pt/1000.);
  hist_boosted_bb_jet1_eta->Fill(boosted_bb_j1_system_eta);
  hist_boosted_bb_jet1_phi->Fill(boosted_bb_j1_system_phi);
  hist_boosted_bb_jet1_deta->Fill(boosted_bb_j1_system_deta);
  hist_boosted_bb_jet1_dphi->Fill(boosted_bb_j1_system_dphi);
  hist_boosted_bb_jet1_dR->Fill(boosted_bb_j1_system_dR);

  hist_boosted_bb_jet2_m->Fill(boosted_bb_j2_system_m/1000.);
  hist_boosted_bb_jet2_pt->Fill(boosted_bb_j2_system_pt/1000.);
  hist_boosted_bb_jet2_eta->Fill(boosted_bb_j2_system_eta);
  hist_boosted_bb_jet2_phi->Fill(boosted_bb_j2_system_phi);
  hist_boosted_bb_jet2_deta->Fill(boosted_bb_j2_system_deta);
  hist_boosted_bb_jet2_dphi->Fill(boosted_bb_j2_system_dphi);
  hist_boosted_bb_jet2_dR->Fill(boosted_bb_j2_system_dR);

  hist_boosted_tautau_jet1_m->Fill(boosted_tautau_j1_system_m/1000.);
  hist_boosted_tautau_jet1_pt->Fill(boosted_tautau_j1_system_pt/1000.);
  hist_boosted_tautau_jet1_eta->Fill(boosted_tautau_j1_system_eta);
  hist_boosted_tautau_jet1_phi->Fill(boosted_tautau_j1_system_phi);
  hist_boosted_tautau_jet1_deta->Fill(boosted_tautau_j1_system_deta);
  hist_boosted_tautau_jet1_dphi->Fill(boosted_tautau_j1_system_dphi);
  hist_boosted_tautau_jet1_dR->Fill(boosted_tautau_j1_system_dR);

  hist_boosted_tautau_jet2_m->Fill(boosted_tautau_j2_system_m/1000.);
  hist_boosted_tautau_jet2_pt->Fill(boosted_tautau_j2_system_pt/1000.);
  hist_boosted_tautau_jet2_eta->Fill(boosted_tautau_j2_system_eta);
  hist_boosted_tautau_jet2_phi->Fill(boosted_tautau_j2_system_phi);
  hist_boosted_tautau_jet2_deta->Fill(boosted_tautau_j2_system_deta);
  hist_boosted_tautau_jet2_dphi->Fill(boosted_tautau_j2_system_dphi);
  hist_boosted_tautau_jet2_dR->Fill(boosted_tautau_j2_system_dR);

  hist_boosted_all_jets_m->Fill(boosted_all_jets_system_m/1000.);
  hist_boosted_all_jets_pt->Fill(boosted_all_jets_system_pt/1000.);
  hist_boosted_all_jets_eta->Fill(boosted_all_jets_system_eta);
  hist_boosted_all_jets_phi->Fill(boosted_all_jets_system_phi);
  hist_boosted_all_jets_deta->Fill(boosted_all_jets_system_deta);
  hist_boosted_all_jets_dphi->Fill(boosted_all_jets_system_dphi);
  hist_boosted_all_jets_dR->Fill(boosted_all_jets_system_dR);
  
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
  
  hist_boosted_jet12_m->Write();
  hist_boosted_jet12_pt->Write();
  hist_boosted_jet12_eta->Write();
  hist_boosted_jet12_phi->Write();
  hist_boosted_jet12_deta->Write();
  hist_boosted_jet12_dphi->Write();
  hist_boosted_jet12_dR->Write();

  hist_boosted_bbtautau_m->Write();
  hist_boosted_bbtautau_pt->Write();
  hist_boosted_bbtautau_eta->Write();
  hist_boosted_bbtautau_phi->Write();
  hist_boosted_bbtautau_deta->Write();
  hist_boosted_bbtautau_dphi->Write();
  hist_boosted_bbtautau_dR->Write();

  hist_boosted_bb_jet1_m->Write();
  hist_boosted_bb_jet1_pt->Write();
  hist_boosted_bb_jet1_eta->Write();
  hist_boosted_bb_jet1_phi->Write();
  hist_boosted_bb_jet1_deta->Write();
  hist_boosted_bb_jet1_dphi->Write();
  hist_boosted_bb_jet1_dR->Write();

  hist_boosted_bb_jet2_m->Write();
  hist_boosted_bb_jet2_pt->Write();
  hist_boosted_bb_jet2_eta->Write();
  hist_boosted_bb_jet2_phi->Write();
  hist_boosted_bb_jet2_deta->Write();
  hist_boosted_bb_jet2_dphi->Write();
  hist_boosted_bb_jet2_dR->Write();

  hist_boosted_tautau_jet1_m->Write();
  hist_boosted_tautau_jet1_pt->Write();
  hist_boosted_tautau_jet1_eta->Write();
  hist_boosted_tautau_jet1_phi->Write();
  hist_boosted_tautau_jet1_deta->Write();
  hist_boosted_tautau_jet1_dphi->Write();
  hist_boosted_tautau_jet1_dR->Write();

  hist_boosted_tautau_jet2_m->Write();
  hist_boosted_tautau_jet2_pt->Write();
  hist_boosted_tautau_jet2_eta->Write();
  hist_boosted_tautau_jet2_phi->Write();
  hist_boosted_tautau_jet2_deta->Write();
  hist_boosted_tautau_jet2_dphi->Write();
  hist_boosted_tautau_jet2_dR->Write();

  hist_boosted_all_jets_m->Write();
  hist_boosted_all_jets_pt->Write();
  hist_boosted_all_jets_eta->Write();
  hist_boosted_all_jets_phi->Write();
  hist_boosted_all_jets_deta->Write();
  hist_boosted_all_jets_dphi->Write();
  hist_boosted_all_jets_dR->Write();

  hist_boosted_jet12_Zeppenfeld_Hbb->Write();
  hist_boosted_jet12_Zeppenfeld_Htautau->Write();
  hist_boosted_jet12_Zeppenfeld_jet12->Write();

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
  outTree->Branch("idx_jet1_VBF_topology", &idx_jet1_VBF_topology);
  outTree->Branch("idx_jet2_VBF_topology", &idx_jet2_VBF_topology);
  outTree->Branch("is_jet12_matched", &is_jet12_matched);
  
  outTree->Branch("count_bb_candidates", &count_bb_candidates);
  outTree->Branch("count_tautau_candidates", &count_tautau_candidates);

  outTree->Branch("two_jets_j12_m", &two_jets_j12_m);
  outTree->Branch("two_jets_j12_pt", &two_jets_j12_pt);
  outTree->Branch("two_jets_j12_eta", &two_jets_j12_eta);
  outTree->Branch("two_jets_j12_phi", &two_jets_j12_phi);
  outTree->Branch("two_jets_j12_deta", &two_jets_j12_deta);
  outTree->Branch("two_jets_j12_dphi", &two_jets_j12_dphi);
  outTree->Branch("two_jets_j12_dR", &two_jets_j12_dR);

  outTree->Branch("boosted_bb_tautau_system_m", &boosted_bb_tautau_system_m);
  outTree->Branch("boosted_bb_tautau_system_pt", &boosted_bb_tautau_system_pt);
  outTree->Branch("boosted_bb_tautau_system_eta", &boosted_bb_tautau_system_eta);
  outTree->Branch("boosted_bb_tautau_system_phi", &boosted_bb_tautau_system_phi);
  outTree->Branch("boosted_bb_tautau_system_deta", &boosted_bb_tautau_system_deta);
  outTree->Branch("boosted_bb_tautau_system_dphi", &boosted_bb_tautau_system_dphi);
  outTree->Branch("boosted_bb_tautau_system_dR", &boosted_bb_tautau_system_dR);

  // Boosted bb and small jets j1 variables                                                                                   
  outTree->Branch("boosted_bb_j1_system_m", &boosted_bb_j1_system_m);
  outTree->Branch("boosted_bb_j1_system_pt", &boosted_bb_j1_system_pt);
  outTree->Branch("boosted_bb_j1_system_eta", &boosted_bb_j1_system_eta);
  outTree->Branch("boosted_bb_j1_system_phi", &boosted_bb_j1_system_phi);
  outTree->Branch("boosted_bb_j1_system_deta", &boosted_bb_j1_system_deta);
  outTree->Branch("boosted_bb_j1_system_dphi", &boosted_bb_j1_system_dphi);
  outTree->Branch("boosted_bb_j1_system_dR", &boosted_bb_j1_system_dR);

  // Boosted tautau and small jets j1 variables                                                                               
  outTree->Branch("boosted_tautau_j1_system_m", &boosted_tautau_j1_system_m);
  outTree->Branch("boosted_tautau_j1_system_pt", &boosted_tautau_j1_system_pt);
  outTree->Branch("boosted_tautau_j1_system_eta", &boosted_tautau_j1_system_eta);
  outTree->Branch("boosted_tautau_j1_system_phi", &boosted_tautau_j1_system_phi);
  outTree->Branch("boosted_tautau_j1_system_deta", &boosted_tautau_j1_system_deta);
  outTree->Branch("boosted_tautau_j1_system_dphi", &boosted_tautau_j1_system_dphi);
  outTree->Branch("boosted_tautau_j1_system_dR", &boosted_tautau_j1_system_dR);
  
  // Boosted bb and small jets j2 variables                                                                                   

  outTree->Branch("boosted_bb_j2_system_m", &boosted_bb_j2_system_m);
  outTree->Branch("boosted_bb_j2_system_pt", &boosted_bb_j2_system_pt);
  outTree->Branch("boosted_bb_j2_system_eta", &boosted_bb_j2_system_eta);
  outTree->Branch("boosted_bb_j2_system_phi", &boosted_bb_j2_system_phi);
  outTree->Branch("boosted_bb_j2_system_deta", &boosted_bb_j2_system_deta);
  outTree->Branch("boosted_bb_j2_system_dphi", &boosted_bb_j2_system_dphi);
  outTree->Branch("boosted_bb_j2_system_dR", &boosted_bb_j2_system_dR);
  
  // Boosted tautau and small jets j1 variables                                                                               
  outTree->Branch("boosted_tautau_j2_system_m", &boosted_tautau_j2_system_m);
  outTree->Branch("boosted_tautau_j2_system_pt", &boosted_tautau_j2_system_pt);
  outTree->Branch("boosted_tautau_j2_system_eta", &boosted_tautau_j2_system_eta);
  outTree->Branch("boosted_tautau_j2_system_phi", &boosted_tautau_j2_system_phi);
  outTree->Branch("boosted_tautau_j2_system_deta", &boosted_tautau_j2_system_deta);
  outTree->Branch("boosted_tautau_j2_system_dphi", &boosted_tautau_j2_system_dphi);
  outTree->Branch("boosted_tautau_j2_system_dR", &boosted_tautau_j2_system_dR);
  
  // All jets system variables                                                                                                
  outTree->Branch("boosted_all_jets_system_m", &boosted_all_jets_system_m);
  outTree->Branch("boosted_all_jets_system_pt", &boosted_all_jets_system_pt);
  outTree->Branch("boosted_all_jets_system_eta", &boosted_all_jets_system_eta);
  outTree->Branch("boosted_all_jets_system_phi", &boosted_all_jets_system_phi);
  outTree->Branch("boosted_all_jets_system_deta", &boosted_all_jets_system_deta);
  outTree->Branch("boosted_all_jets_system_dphi", &boosted_all_jets_system_dphi);
  outTree->Branch("boosted_all_jets_system_dR", &boosted_all_jets_system_dR);

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
