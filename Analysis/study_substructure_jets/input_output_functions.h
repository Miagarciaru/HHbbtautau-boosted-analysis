// *************************************
// Declaration of functions
// *************************************

void process_label(TString name_sample, const std::string& min_pT_recojets_str);
void set_branch_address_inTree(TTree *inTree);
void define_output_branches(TTree *outTree);
void print_list_of_branches(TTree* tree);
void counter_for_stat();
void print_stat(Int_t nentries);


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

  outTree->Branch("idx_b1_preselected", &idx_b1_preselected);
  outTree->Branch("idx_b2_preselected", &idx_b2_preselected);
  outTree->Branch("idx_tau1_preselected", &idx_tau1_preselected);
  outTree->Branch("idx_tau2_preselected", &idx_tau2_preselected);

  outTree->Branch("preselected_bb_pt", &preselected_bb_pt);
  outTree->Branch("preselected_bb_eta", &preselected_bb_eta);
  outTree->Branch("preselected_bb_phi", &preselected_bb_phi);
  outTree->Branch("preselected_bb_m", &preselected_bb_m);

  outTree->Branch("preselected_tautau_pt", &preselected_tautau_pt);
  outTree->Branch("preselected_tautau_eta", &preselected_tautau_eta);
  outTree->Branch("preselected_tautau_phi", &preselected_tautau_phi);
  outTree->Branch("preselected_tautau_m", &preselected_tautau_m);
  
  outTree->Branch("preselected_HH_pt", &preselected_HH_pt);
  outTree->Branch("preselected_HH_eta", &preselected_HH_eta);
  outTree->Branch("preselected_HH_phi", &preselected_HH_phi);
  outTree->Branch("preselected_HH_m", &preselected_HH_m);

  outTree->Branch("passed_preselection", &passed_preselection);
  outTree->Branch("matched_preselection", &matched_preselection);
  outTree->Branch("matched_preselected_bb", &matched_preselected_bb);
  outTree->Branch("matched_preselected_tautau", &matched_preselected_tautau);

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

  //********************************************************************************************
  // Distributions histograms
  //********************************************************************************************
  
  //matched_recojets_histograms
  hist_matched_recojet_bb_m->Write();
  hist_matched_recojet_bb_pt->Write();
  hist_matched_recojet_bb_eta->Write();
  hist_matched_recojet_bb_phi->Write();
  hist_matched_recojet_bb_tau_n_prong->Write();
  hist_matched_recojet_bb_tau_n1_subjettiness->Write();
  hist_matched_recojet_bb_tau_n2_subjettiness->Write();
  hist_matched_recojet_bb_tau_n2_over_n1_subjettiness->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_phbb->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_pqcd->Write();
  hist_matched_recojet_bb_dR->Write();

  hist_matched_recojet_bb_m_only_Hbb_tagger->Write();
  hist_matched_recojet_bb_m_only_nsubjettiness->Write();
  hist_matched_recojet_bb_m_until_nsubjettiness->Write();

  
  hist_matched_recojet_tautau_m->Write();
  hist_matched_recojet_tautau_pt->Write();
  hist_matched_recojet_tautau_eta->Write();
  hist_matched_recojet_tautau_phi->Write();
  hist_matched_recojet_tautau_tau_n_prong->Write();
  hist_matched_recojet_tautau_tau_n1_subjettiness->Write();
  hist_matched_recojet_tautau_tau_n2_subjettiness->Write();
  hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_phbb->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Write();
  hist_matched_recojet_tautau_dR->Write();

  hist_matched_recojet_tautau_m_only_Hbb_tagger->Write();
  hist_matched_recojet_tautau_m_only_nsubjettiness->Write();
  hist_matched_recojet_tautau_m_until_nsubjettiness->Write();

  //non_matched_recojets_histograms
  
  hist_non_matched_recojet_bb_m->Write();
  hist_non_matched_recojet_bb_pt->Write();
  hist_non_matched_recojet_bb_eta->Write();
  hist_non_matched_recojet_bb_phi->Write();
  hist_non_matched_recojet_bb_tau_n_prong->Write();
  hist_non_matched_recojet_bb_tau_n1_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n2_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd->Write();
  
  hist_non_matched_recojet_tautau_m->Write();
  hist_non_matched_recojet_tautau_pt->Write();
  hist_non_matched_recojet_tautau_eta->Write();
  hist_non_matched_recojet_tautau_phi->Write();
  hist_non_matched_recojet_tautau_tau_n_prong->Write();
  hist_non_matched_recojet_tautau_tau_n1_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n2_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Write();
  
  hist_nevents_per_class->Write();
  hist2d_dR_per_class_bb->Write();
  hist2d_dR_per_class_tautau->Write();

  hist_taggedHbb_recojet_bb_per_event->Write();
  hist_candidates_preselected_tautau_tau_n2_over_n1_subjettiness->Write();
  
  //matched_preselected_histograms
  
  hist_matched_preselected_bb_m->Write();
  hist_matched_preselected_bb_pt->Write();
  hist_matched_preselected_bb_eta->Write();
  hist_matched_preselected_bb_phi->Write();
  hist_matched_preselected_bb_tau_n2_over_n1_subjettiness->Write();
  hist_matched_preselected_bb_ak10_GN2Xv01_phbb->Write();

  hist_matched_preselected_bb_m_only_Hbb_tagger->Write();
  hist_matched_preselected_bb_m_until_nsubjettiness->Write();
  hist_matched_preselected_bb_m_order_by_nsubjettiness->Write();
  
  hist_matched_preselected_tautau_m->Write();
  hist_matched_preselected_tautau_pt->Write();
  hist_matched_preselected_tautau_eta->Write();
  hist_matched_preselected_tautau_phi->Write();
  hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_matched_preselected_tautau_ak10_GN2Xv01_phbb->Write();

  hist_matched_preselected_tautau_m_only_Hbb_tagger->Write();
  hist_matched_preselected_tautau_m_until_nsubjettiness->Write();
  
  //comparison_histograms
  hist_truth_HH_pt->Write();
  hist_computed_HH_pt->Write();
  hist_truth_HH_m->Write();
  hist_computed_HH_m->Write();

  //********************************************************************************************
  // Ratio histograms for recovariables r1 and r2
  //********************************************************************************************
  
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

  // reco ptHtautau
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

  //********************************************************************************************
  // Ratio histograms for truth variables r1 and r2
  //********************************************************************************************

  // truth mHH
  hist_acceptance_truth_mHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_mHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_mHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_mHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_mHH_denominator_r1->Write();
  hist_acceptance_truth_mHH_denominator_class0_r2->Write();
  hist_acceptance_truth_mHH_denominator_class1_r2->Write();
  hist_acceptance_truth_mHH_denominator_class2_r2->Write();
  hist_acceptance_truth_mHH_denominator_class3_r2->Write();

  // truth ptHH
  hist_acceptance_truth_ptHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_ptHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_ptHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_ptHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_ptHH_denominator_r1->Write();
  hist_acceptance_truth_ptHH_denominator_class0_r2->Write();
  hist_acceptance_truth_ptHH_denominator_class1_r2->Write();
  hist_acceptance_truth_ptHH_denominator_class2_r2->Write();
  hist_acceptance_truth_ptHH_denominator_class3_r2->Write();

  // truth etaHH
  hist_acceptance_truth_etaHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_etaHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_etaHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_etaHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_etaHH_denominator_r1->Write();
  hist_acceptance_truth_etaHH_denominator_class0_r2->Write();
  hist_acceptance_truth_etaHH_denominator_class1_r2->Write();
  hist_acceptance_truth_etaHH_denominator_class2_r2->Write();
  hist_acceptance_truth_etaHH_denominator_class3_r2->Write();

  // truth phiHH
  hist_acceptance_truth_phiHH_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_phiHH_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_phiHH_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_phiHH_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_phiHH_denominator_r1->Write();
  hist_acceptance_truth_phiHH_denominator_class0_r2->Write();
  hist_acceptance_truth_phiHH_denominator_class1_r2->Write();
  hist_acceptance_truth_phiHH_denominator_class2_r2->Write();
  hist_acceptance_truth_phiHH_denominator_class3_r2->Write();

  // truth mHbb
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

  // truth ptHbb
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

  // truth etaHbb 
  hist_acceptance_truth_etaHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_etaHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_etaHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_etaHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_r1->Write();
  hist_acceptance_truth_etaHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_etaHbb_denominator_class3_r2->Write();

  // truth phiHbb
  hist_acceptance_truth_phiHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_phiHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_phiHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_phiHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_r1->Write();
  hist_acceptance_truth_phiHbb_denominator_class0_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_class1_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_class2_r2->Write();
  hist_acceptance_truth_phiHbb_denominator_class3_r2->Write();
  
  // truth mHtautau
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

  // truth ptHtautau
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
  
  // truth etaHtautau
  hist_acceptance_truth_etaHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_r1->Write();
  hist_acceptance_truth_etaHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_etaHtautau_denominator_class3_r2->Write();

  // truth phiHtautau
  hist_acceptance_truth_phiHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_r1->Write();
  hist_acceptance_truth_phiHtautau_denominator_class0_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_class1_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_class2_r2->Write();
  hist_acceptance_truth_phiHtautau_denominator_class3_r2->Write();

  //********************************************************************************************
  // Ratio histograms for preselected variables r1 and r2
  //********************************************************************************************

  // preselected mHH
  hist_acceptance_preselected_mHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_mHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_mHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_mHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_mHH_denominator_r1->Write();
  hist_acceptance_preselected_mHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_mHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_mHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_mHH_denominator_class3_r2->Write();

  // preselected ptHH
  hist_acceptance_preselected_ptHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_ptHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_ptHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_ptHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_r1->Write();
  hist_acceptance_preselected_ptHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_ptHH_denominator_class3_r2->Write();

  // preselected etaHH
  hist_acceptance_preselected_etaHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_etaHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_etaHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_etaHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_r1->Write();
  hist_acceptance_preselected_etaHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_etaHH_denominator_class3_r2->Write();

  // preselected phiHH
  hist_acceptance_preselected_phiHH_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_phiHH_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_phiHH_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_phiHH_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_r1->Write();
  hist_acceptance_preselected_phiHH_denominator_class0_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_class1_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_class2_r2->Write();
  hist_acceptance_preselected_phiHH_denominator_class3_r2->Write();
  
  // preselected mHbb
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

  // preselected ptHbb
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

  // preselected etaHbb
  hist_acceptance_preselected_etaHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_r1->Write();
  hist_acceptance_preselected_etaHbb_denominator_class0_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_class1_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_class2_r2->Write();
  hist_acceptance_preselected_etaHbb_denominator_class3_r2->Write();

  // preselected phiHbb
  hist_acceptance_preselected_phiHbb_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_r1->Write();
  hist_acceptance_preselected_phiHbb_denominator_class0_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_class1_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_class2_r2->Write();
  hist_acceptance_preselected_phiHbb_denominator_class3_r2->Write();
  
  // preselected mHtautau
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

  // preselected ptHtautau
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

  // preselected etaHtautau
  hist_acceptance_preselected_etaHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_r1->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class0_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class1_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class2_r2->Write();
  hist_acceptance_preselected_etaHtautau_denominator_class3_r2->Write();

  // preselected phiHtautau
  hist_acceptance_preselected_phiHtautau_numerator_class0_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class1_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class2_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_numerator_class3_r1_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_r1->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class0_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class1_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class2_r2->Write();
  hist_acceptance_preselected_phiHtautau_denominator_class3_r2->Write();

  //********************************************************************************************
  // Ratio histograms for recovariables r3 and r4
  //********************************************************************************************

  // reco mHH
  hist_acceptance_mHH_numerator_r3->Write();
  hist_acceptance_mHH_denominator_r3_r4->Write();
  hist_acceptance_mHH_numerator_class0_r4->Write();
  hist_acceptance_mHH_numerator_class1_r4->Write();
  hist_acceptance_mHH_numerator_class2_r4->Write();
  hist_acceptance_mHH_numerator_class3_r4->Write();
  
  // reco ptHbb                                                                                                              
  hist_acceptance_ptHbb_numerator_r3->Write();
  hist_acceptance_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_ptHbb_numerator_class3_r4->Write();

  // reco ptHtautau                                                                                                         
  hist_acceptance_ptHtautau_numerator_r3->Write();
  hist_acceptance_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_ptHtautau_numerator_class3_r4->Write();

  //********************************************************************************************
  // Ratio histograms for truth variables r3 and r4
  //********************************************************************************************
  
  // truth mHH
  hist_acceptance_truth_mHH_numerator_r3->Write();
  hist_acceptance_truth_mHH_denominator_r3_r4->Write();
  hist_acceptance_truth_mHH_numerator_class0_r4->Write();
  hist_acceptance_truth_mHH_numerator_class1_r4->Write();
  hist_acceptance_truth_mHH_numerator_class2_r4->Write();
  hist_acceptance_truth_mHH_numerator_class3_r4->Write();

  // truth ptHH
  hist_acceptance_truth_ptHH_numerator_r3->Write();
  hist_acceptance_truth_ptHH_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHH_numerator_class3_r4->Write();

  // truth etaHH
  hist_acceptance_truth_etaHH_numerator_r3->Write();
  hist_acceptance_truth_etaHH_denominator_r3_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class0_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class1_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class2_r4->Write();
  hist_acceptance_truth_etaHH_numerator_class3_r4->Write();

  // truth phiHH
  hist_acceptance_truth_phiHH_numerator_r3->Write();
  hist_acceptance_truth_phiHH_denominator_r3_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class0_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class1_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class2_r4->Write();
  hist_acceptance_truth_phiHH_numerator_class3_r4->Write();
  
  // truth mHbb
  hist_acceptance_truth_mHbb_numerator_r3->Write();
  hist_acceptance_truth_mHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_mHbb_numerator_class3_r4->Write();

  // truth ptHbb
  hist_acceptance_truth_ptHbb_numerator_r3->Write();
  hist_acceptance_truth_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHbb_numerator_class3_r4->Write();

  // truth etaHbb
  hist_acceptance_truth_etaHbb_numerator_r3->Write();
  hist_acceptance_truth_etaHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_etaHbb_numerator_class3_r4->Write();

  // truth phiHbb
  hist_acceptance_truth_phiHbb_numerator_r3->Write();
  hist_acceptance_truth_phiHbb_denominator_r3_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class0_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class1_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class2_r4->Write();
  hist_acceptance_truth_phiHbb_numerator_class3_r4->Write();
  
  // truth mHtautau
  hist_acceptance_truth_mHtautau_numerator_r3->Write();
  hist_acceptance_truth_mHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_mHtautau_numerator_class3_r4->Write();

  // truth ptHtautau
  hist_acceptance_truth_ptHtautau_numerator_r3->Write();
  hist_acceptance_truth_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_ptHtautau_numerator_class3_r4->Write();

  // truth etaHtautau
  hist_acceptance_truth_etaHtautau_numerator_r3->Write();
  hist_acceptance_truth_etaHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_etaHtautau_numerator_class3_r4->Write();

  // truth phiHtautau
  hist_acceptance_truth_phiHtautau_numerator_r3->Write();
  hist_acceptance_truth_phiHtautau_denominator_r3_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class0_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class1_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class2_r4->Write();
  hist_acceptance_truth_phiHtautau_numerator_class3_r4->Write();

  //********************************************************************************************
  // Ratio histograms for preselected variables r3 and r4
  //********************************************************************************************

  // preselected mHH
  hist_acceptance_preselected_mHH_numerator_r3->Write();
  hist_acceptance_preselected_mHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_mHH_numerator_class3_r4->Write();

  // preselected ptHH
  hist_acceptance_preselected_ptHH_numerator_r3->Write();
  hist_acceptance_preselected_ptHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_ptHH_numerator_class3_r4->Write();

  // preselected etaHH
  hist_acceptance_preselected_etaHH_numerator_r3->Write();
  hist_acceptance_preselected_etaHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_etaHH_numerator_class3_r4->Write();

  // preselected phiHH
  hist_acceptance_preselected_phiHH_numerator_r3->Write();
  hist_acceptance_preselected_phiHH_denominator_r3_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class0_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class1_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class2_r4->Write();
  hist_acceptance_preselected_phiHH_numerator_class3_r4->Write();
  
  // preselected mHbb
  hist_acceptance_preselected_mHbb_numerator_r3->Write();
  hist_acceptance_preselected_mHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_mHbb_numerator_class3_r4->Write();

  // preselected ptHbb
  hist_acceptance_preselected_ptHbb_numerator_r3->Write();
  hist_acceptance_preselected_ptHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_ptHbb_numerator_class3_r4->Write();

  // preselected etaHbb
  hist_acceptance_preselected_etaHbb_numerator_r3->Write();
  hist_acceptance_preselected_etaHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_etaHbb_numerator_class3_r4->Write();

  // preselected phiHbb
  hist_acceptance_preselected_phiHbb_numerator_r3->Write();
  hist_acceptance_preselected_phiHbb_denominator_r3_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class0_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class1_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class2_r4->Write();
  hist_acceptance_preselected_phiHbb_numerator_class3_r4->Write();
  
  // preselected mHtautau
  hist_acceptance_preselected_mHtautau_numerator_r3->Write();
  hist_acceptance_preselected_mHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_mHtautau_numerator_class3_r4->Write();

  // preselected ptHtautau
  hist_acceptance_preselected_ptHtautau_numerator_r3->Write();
  hist_acceptance_preselected_ptHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_ptHtautau_numerator_class3_r4->Write();

  // preselected etaHtautau
  hist_acceptance_preselected_etaHtautau_numerator_r3->Write();
  hist_acceptance_preselected_etaHtautau_denominator_r3_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class0_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class1_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class2_r4->Write();
  hist_acceptance_preselected_etaHtautau_numerator_class3_r4->Write();

  // preselected phiHtautau
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
