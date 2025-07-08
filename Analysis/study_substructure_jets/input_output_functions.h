// *************************************
// Declaration of functions
// *************************************

void process_like();
void process_label(TString name_sample, const std::string& min_pT_recojets_str);
void set_branch_address_inTree(TTree *inTree);
void define_output_branches(TTree *outTree);
void write_histograms();
void print_list_of_branches(TTree* tree);
void counter_for_stat();
void print_stat(Int_t nentries);

void process_like(){

  process_type_like = "NA";
  class_label = -99;

  if( matched_preselection == true ){
    
    process_type_like = "Boosted bbtt";
    class_label = -1;

    if( is_jet12_matched_mjj_sel == true ){
      
      if( process_name.find("ggF")!=std::string::npos){
        process_type_like = "ggF";
        class_label = 0; 
      }

      if( process_name.find("VBF")!=std::string::npos){
        process_type_like = "VBF"; 
        class_label = 1;
      }
    }
  }

}

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

  inTree->SetBranchAddress("recojet_antikt4PFlow_NOSYS_pt", &recojet_antikt4PFlow_NOSYS_pt, &b_recojet_antikt4PFlow_NOSYS_pt);
  inTree->SetBranchAddress("recojet_antikt4PFlow_eta", &recojet_antikt4PFlow_eta, &b_recojet_antikt4PFlow_eta);
  inTree->SetBranchAddress("recojet_antikt4PFlow_phi", &recojet_antikt4PFlow_phi, &b_recojet_antikt4PFlow_phi);
  inTree->SetBranchAddress("recojet_antikt4PFlow_m", &recojet_antikt4PFlow_m, &b_recojet_antikt4PFlow_m);

  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phbb", &recojet_antikt10UFO_GN2Xv01_phbb, &b_recojet_antikt10UFO_GN2Xv01_phbb);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_pqcd", &recojet_antikt10UFO_GN2Xv01_pqcd, &b_recojet_antikt10UFO_GN2Xv01_pqcd);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_phcc", &recojet_antikt10UFO_GN2Xv01_phcc, &b_recojet_antikt10UFO_GN2Xv01_phcc);
  inTree->SetBranchAddress("recojet_antikt10UFO_GN2Xv01_ptop", &recojet_antikt10UFO_GN2Xv01_ptop, &b_recojet_antikt10UFO_GN2Xv01_ptop);
  
  inTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt, &b_recojet_antikt10UFO_NOSYS_pt);
  inTree->SetBranchAddress("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta, &b_recojet_antikt10UFO_eta);
  inTree->SetBranchAddress("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi, &b_recojet_antikt10UFO_phi);
  inTree->SetBranchAddress("recojet_antikt10UFO_m", &recojet_antikt10UFO_m, &b_recojet_antikt10UFO_m);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau1_wta", &recojet_antikt10UFO_Tau1_wta, &b_recojet_antikt10UFO_Tau1_wta);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau2_wta", &recojet_antikt10UFO_Tau2_wta, &b_recojet_antikt10UFO_Tau2_wta);
  inTree->SetBranchAddress("recojet_antikt10UFO_Tau3_wta", &recojet_antikt10UFO_Tau3_wta, &b_recojet_antikt10UFO_Tau3_wta);

  inTree->SetBranchAddress("recojet_antikt10UFO_ECF1", &recojet_antikt10UFO_ECF1, &b_recojet_antikt10UFO_ECF1);
  inTree->SetBranchAddress("recojet_antikt10UFO_ECF2", &recojet_antikt10UFO_ECF2, &b_recojet_antikt10UFO_ECF2);
  inTree->SetBranchAddress("recojet_antikt10UFO_ECF3", &recojet_antikt10UFO_ECF3, &b_recojet_antikt10UFO_ECF3);
  inTree->SetBranchAddress("recojet_antikt10UFO_Split12", &recojet_antikt10UFO_Split12, &b_recojet_antikt10UFO_Split12);
  inTree->SetBranchAddress("recojet_antikt10UFO_Split23", &recojet_antikt10UFO_Split23, &b_recojet_antikt10UFO_Split23);
  inTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_passesOR", &recojet_antikt10UFO_NOSYS_passesOR, &b_recojet_antikt10UFO_NOSYS_passesOR);
    
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

  outTree->Branch("process_name", &process_name);
  outTree->Branch("process_type_like", &process_type_like); 
  outTree->Branch("class_label", &class_label);
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

  outTree->Branch("recojet_antikt4PFlow_NOSYS_pt", &recojet_antikt4PFlow_NOSYS_pt);
  outTree->Branch("recojet_antikt4PFlow_eta", &recojet_antikt4PFlow_eta);
  outTree->Branch("recojet_antikt4PFlow_phi", &recojet_antikt4PFlow_phi);
  outTree->Branch("recojet_antikt4PFlow_m", &recojet_antikt4PFlow_m);

  outTree->Branch("recojet_antikt10UFO_GN2Xv01_phbb", &recojet_antikt10UFO_GN2Xv01_phbb);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_pqcd", &recojet_antikt10UFO_GN2Xv01_pqcd);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_phcc", &recojet_antikt10UFO_GN2Xv01_phcc);
  outTree->Branch("recojet_antikt10UFO_GN2Xv01_ptop", &recojet_antikt10UFO_GN2Xv01_ptop);

  outTree->Branch("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt);
  outTree->Branch("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta);
  outTree->Branch("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi);
  outTree->Branch("recojet_antikt10UFO_m", &recojet_antikt10UFO_m);
  outTree->Branch("recojet_antikt10UFO_Tau1_wta", &recojet_antikt10UFO_Tau1_wta);
  outTree->Branch("recojet_antikt10UFO_Tau2_wta", &recojet_antikt10UFO_Tau2_wta);
  outTree->Branch("recojet_antikt10UFO_Tau3_wta", &recojet_antikt10UFO_Tau3_wta);

  outTree->Branch("recojet_antikt10UFO_ECF1", &recojet_antikt10UFO_ECF1);
  outTree->Branch("recojet_antikt10UFO_ECF2", &recojet_antikt10UFO_ECF2);
  outTree->Branch("recojet_antikt10UFO_ECF3", &recojet_antikt10UFO_ECF3);
  outTree->Branch("recojet_antikt10UFO_Split12", &recojet_antikt10UFO_Split12);
  outTree->Branch("recojet_antikt10UFO_Split23", &recojet_antikt10UFO_Split23);

  outTree->Branch("is_truth_reco_boosted_bb_jet", &is_truth_reco_boosted_bb_jet);
  outTree->Branch("is_truth_reco_boosted_tautau_jet", &is_truth_reco_boosted_tautau_jet);

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
  outTree->Branch("truth_reco_match_for_boosted_bb", &truth_reco_match_for_boosted_bb);
  outTree->Branch("truth_reco_match_for_boosted_tautau", &truth_reco_match_for_boosted_tautau);
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

  // small jets matching variables
  outTree->Branch("idx_jet1_VBF_topology_mjj_sel", &idx_jet1_VBF_topology_mjj_sel);
  outTree->Branch("idx_jet2_VBF_topology_mjj_sel", &idx_jet2_VBF_topology_mjj_sel);
  outTree->Branch("idx_jet1_VBF_topology_ptjj_sel", &idx_jet1_VBF_topology_ptjj_sel);
  outTree->Branch("idx_jet2_VBF_topology_ptjj_sel", &idx_jet2_VBF_topology_ptjj_sel);
  outTree->Branch("is_jet12_matched_mjj_sel", &is_jet12_matched_mjj_sel);
  outTree->Branch("is_jet12_matched_ptjj_sel", &is_jet12_matched_ptjj_sel);

  outTree->Branch("count_bb_candidates", &count_bb_candidates);
  outTree->Branch("count_tautau_candidates", &count_tautau_candidates);

  outTree->Branch("overlap_jj_selection_methods", &overlap_jj_selection_methods);
  outTree->Branch("eta_smalljets_cutflow", &eta_smalljets_cutflow);
  outTree->Branch("minpt_smalljets_cutflow", &minpt_smalljets_cutflow);
  outTree->Branch("min_mjj_smalljets_cutflow", &min_mjj_smalljets_cutflow);
  outTree->Branch("min_dR_smalljets_cutflow", &min_dR_smalljets_cutflow);
  outTree->Branch("all_cuts_applied_cutflow", &all_cuts_applied_cutflow);

  outTree->Branch("number_of_desordered_small_jets_pT_candidates", &number_of_desordered_small_jets_pT_candidates);

  outTree->Branch("smallR_jets_n", &smallR_jets_n);
  outTree->Branch("largeR_jets_n", &largeR_jets_n);

  // Two small jets j1 and j2 variables
  outTree->Branch("two_jets_j12_m", &two_jets_j12_m);
  outTree->Branch("two_jets_j12_pt", &two_jets_j12_pt);
  outTree->Branch("two_jets_j12_eta", &two_jets_j12_eta);
  outTree->Branch("two_jets_j12_phi", &two_jets_j12_phi);
  outTree->Branch("two_jets_j12_deta", &two_jets_j12_deta);
  outTree->Branch("two_jets_j12_dphi", &two_jets_j12_dphi);
  outTree->Branch("two_jets_j12_dR", &two_jets_j12_dR);

  // Boosted bb and boosted tautau variables
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

  //********************************************************************************************
  //********************************************************************************************
  // Distributions histograms
  //********************************************************************************************
  //********************************************************************************************

  //********************************************************************************************
  //matched_recojets_histograms
  //********************************************************************************************
  
  hist_matched_recojet_bb_m->Write();
  hist_matched_recojet_bb_pt->Write();
  hist_matched_recojet_bb_eta->Write();
  hist_matched_recojet_bb_phi->Write();
  hist_matched_recojet_bb_tau_n_prong->Write();
  hist_matched_recojet_bb_tau_n1_subjettiness->Write();
  hist_matched_recojet_bb_tau_n2_subjettiness->Write();
  hist_matched_recojet_bb_tau_n3_subjettiness->Write();
  hist_matched_recojet_bb_tau_n2_over_n1_subjettiness->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_phbb->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_pqcd->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_phcc->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_ptop->Write();
  hist_matched_recojet_bb_ak10_ECF1->Write();
  hist_matched_recojet_bb_ak10_ECF2->Write();
  hist_matched_recojet_bb_ak10_ECF3->Write();
  hist_matched_recojet_bb_ak10_Split12->Write();
  hist_matched_recojet_bb_ak10_Split23->Write();
  hist_matched_recojet_bb_score_bdt_Hbb->Write();
  hist_matched_recojet_bb_ak10_passesOR->Write();
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
  hist_matched_recojet_tautau_tau_n3_subjettiness->Write();
  hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_phbb->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_phcc->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_ptop->Write();
  hist_matched_recojet_tautau_ak10_ECF1->Write();
  hist_matched_recojet_tautau_ak10_ECF2->Write();
  hist_matched_recojet_tautau_ak10_ECF3->Write();
  hist_matched_recojet_tautau_ak10_Split12->Write();
  hist_matched_recojet_tautau_ak10_Split23->Write();
  hist_matched_recojet_tautau_score_bdt_Htautau->Write();
  hist_matched_recojet_tautau_ak10_passesOR->Write();
  hist_matched_recojet_tautau_dR->Write();

  hist_matched_recojet_tautau_m_only_Hbb_tagger->Write();
  hist_matched_recojet_tautau_m_only_nsubjettiness->Write();
  hist_matched_recojet_tautau_m_until_nsubjettiness->Write();

  //********************************************************************************************
  //matched_recojets_histograms for specific matches with preselected events (cpr - comparison preselected)
  //********************************************************************************************
  
  hist_matched_recojet_bb_m_cpr->Write();
  hist_matched_recojet_bb_pt_cpr->Write();
  hist_matched_recojet_bb_eta_cpr->Write();
  hist_matched_recojet_bb_phi_cpr->Write();
  hist_matched_recojet_bb_tau_n2_over_n1_subjettiness_cpr->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_phbb_cpr->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_pqcd_cpr->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_phcc_cpr->Write();
  hist_matched_recojet_bb_ak10_GN2Xv01_ptop_cpr->Write();
  hist_matched_recojet_bb_ak10_ECF1_cpr->Write();
  hist_matched_recojet_bb_ak10_ECF2_cpr->Write();
  hist_matched_recojet_bb_ak10_ECF3_cpr->Write();
  hist_matched_recojet_bb_ak10_Split12_cpr->Write();
  hist_matched_recojet_bb_ak10_Split23_cpr->Write();
  
  
  hist_matched_recojet_tautau_m_cpr->Write();
  hist_matched_recojet_tautau_pt_cpr->Write();
  hist_matched_recojet_tautau_eta_cpr->Write();
  hist_matched_recojet_tautau_phi_cpr->Write();
  hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness_cpr->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_phbb_cpr->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd_cpr->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_phcc_cpr->Write();
  hist_matched_recojet_tautau_ak10_GN2Xv01_ptop_cpr->Write();
  hist_matched_recojet_tautau_ak10_ECF1_cpr->Write();
  hist_matched_recojet_tautau_ak10_ECF2_cpr->Write();
  hist_matched_recojet_tautau_ak10_ECF3_cpr->Write();
  hist_matched_recojet_tautau_ak10_Split12_cpr->Write();
  hist_matched_recojet_tautau_ak10_Split23_cpr->Write();
  
  //********************************************************************************************
  //non_matched_recojets_histograms
  //********************************************************************************************
  
  hist_non_matched_recojet_bb_m->Write();
  hist_non_matched_recojet_bb_pt->Write();
  hist_non_matched_recojet_bb_eta->Write();
  hist_non_matched_recojet_bb_phi->Write();
  hist_non_matched_recojet_bb_tau_n_prong->Write();
  hist_non_matched_recojet_bb_tau_n1_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n2_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n3_subjettiness->Write();
  hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_phcc->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_ptop->Write();
  hist_non_matched_recojet_bb_ak10_ECF1->Write();
  hist_non_matched_recojet_bb_ak10_ECF2->Write();
  hist_non_matched_recojet_bb_ak10_ECF3->Write();
  hist_non_matched_recojet_bb_ak10_Split12->Write();
  hist_non_matched_recojet_bb_ak10_Split23->Write();
  hist_non_matched_recojet_bb_score_bdt_Hbb->Write();
  hist_non_matched_recojet_bb_ak10_passesOR->Write();
  
  hist_non_matched_recojet_tautau_m->Write();
  hist_non_matched_recojet_tautau_pt->Write();
  hist_non_matched_recojet_tautau_eta->Write();
  hist_non_matched_recojet_tautau_phi->Write();
  hist_non_matched_recojet_tautau_tau_n_prong->Write();
  hist_non_matched_recojet_tautau_tau_n1_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n2_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n3_subjettiness->Write();
  hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phcc->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_ptop->Write();
  hist_non_matched_recojet_tautau_ak10_ECF1->Write();
  hist_non_matched_recojet_tautau_ak10_ECF2->Write();
  hist_non_matched_recojet_tautau_ak10_ECF3->Write();
  hist_non_matched_recojet_tautau_ak10_Split12->Write();
  hist_non_matched_recojet_tautau_ak10_Split23->Write();
  hist_non_matched_recojet_tautau_score_bdt_Htautau->Write();
  hist_non_matched_recojet_tautau_ak10_passesOR->Write();
  
  hist_nevents_per_class->Write();
  hist2d_dR_per_class_bb->Write();
  hist2d_dR_per_class_tautau->Write();

  hist_taggedHbb_recojet_bb_per_event->Write();
  hist_candidates_preselected_tautau_tau_n2_over_n1_subjettiness->Write();

  //********************************************************************************************
  //non_matched_recojets_histograms for specific matches with preselected events (cpr - comparison preselected)
  //********************************************************************************************
  
  hist_non_matched_recojet_bb_m_cpr->Write();
  hist_non_matched_recojet_bb_pt_cpr->Write();
  hist_non_matched_recojet_bb_eta_cpr->Write();
  hist_non_matched_recojet_bb_phi_cpr->Write();
  hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness_cpr->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb_cpr->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd_cpr->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_phcc_cpr->Write();
  hist_non_matched_recojet_bb_ak10_GN2Xv01_ptop_cpr->Write();
  hist_non_matched_recojet_bb_ak10_ECF1_cpr->Write();
  hist_non_matched_recojet_bb_ak10_ECF2_cpr->Write();
  hist_non_matched_recojet_bb_ak10_ECF3_cpr->Write();
  hist_non_matched_recojet_bb_ak10_Split12_cpr->Write();
  hist_non_matched_recojet_bb_ak10_Split23_cpr->Write();

  
  hist_non_matched_recojet_tautau_m_cpr->Write();
  hist_non_matched_recojet_tautau_pt_cpr->Write();
  hist_non_matched_recojet_tautau_eta_cpr->Write();
  hist_non_matched_recojet_tautau_phi_cpr->Write();
  hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phcc_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_ptop_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_ECF1_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_ECF2_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_ECF3_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_Split12_cpr->Write();
  hist_non_matched_recojet_tautau_ak10_Split23_cpr->Write();


  //********************************************************************************************
  //non_matched_recojets_histograms for non info with preselected events (cpr - comparison preselected)
  //********************************************************************************************
  
  hist_non_matched_info_recojet_bb_m_cpr->Write();
  hist_non_matched_info_recojet_bb_pt_cpr->Write();
  hist_non_matched_info_recojet_bb_eta_cpr->Write();
  hist_non_matched_info_recojet_bb_phi_cpr->Write();
  hist_non_matched_info_recojet_bb_tau_n2_over_n1_subjettiness_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_GN2Xv01_phbb_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_GN2Xv01_pqcd_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_GN2Xv01_phcc_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_GN2Xv01_ptop_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_ECF1_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_ECF2_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_ECF3_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_Split12_cpr->Write();
  hist_non_matched_info_recojet_bb_ak10_Split23_cpr->Write();

  
  hist_non_matched_info_recojet_tautau_m_cpr->Write();
  hist_non_matched_info_recojet_tautau_pt_cpr->Write();
  hist_non_matched_info_recojet_tautau_eta_cpr->Write();
  hist_non_matched_info_recojet_tautau_phi_cpr->Write();
  hist_non_matched_info_recojet_tautau_tau_n2_over_n1_subjettiness_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_phbb_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_pqcd_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_phcc_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_GN2Xv01_ptop_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_ECF1_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_ECF2_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_ECF3_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_Split12_cpr->Write();
  hist_non_matched_info_recojet_tautau_ak10_Split23_cpr->Write();
  
  //***********************************************************************************
  //***********************************************************************************
  //matched_preselected_histograms
  //***********************************************************************************
  //***********************************************************************************

  //***********************************************************************************
  // matched preselected
  //***********************************************************************************
  
  hist_matched_preselected_bb_m->Write();
  hist_matched_preselected_bb_pt->Write();
  hist_matched_preselected_bb_eta->Write();
  hist_matched_preselected_bb_phi->Write();
  hist_matched_preselected_bb_tau_n2_over_n1_subjettiness->Write();
  hist_matched_preselected_bb_ak10_GN2Xv01_phbb->Write();
  hist_matched_preselected_bb_ak10_GN2Xv01_pqcd->Write();
  hist_matched_preselected_bb_ak10_GN2Xv01_phcc->Write();
  hist_matched_preselected_bb_ak10_GN2Xv01_ptop->Write();
  hist_matched_preselected_bb_ak10_ECF1->Write();
  hist_matched_preselected_bb_ak10_ECF2->Write();
  hist_matched_preselected_bb_ak10_ECF3->Write();
  hist_matched_preselected_bb_ak10_Split12->Write();
  hist_matched_preselected_bb_ak10_Split23->Write();
  hist_matched_preselected_bb_score_bdt_Hbb->Write();

  hist_matched_preselected_bb_m_only_Hbb_tagger->Write();
  hist_matched_preselected_bb_m_until_nsubjettiness->Write();
  hist_matched_preselected_bb_m_order_by_nsubjettiness->Write();
  
  hist_matched_preselected_tautau_m->Write();
  hist_matched_preselected_tautau_pt->Write();
  hist_matched_preselected_tautau_eta->Write();
  hist_matched_preselected_tautau_phi->Write();
  hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_matched_preselected_tautau_ak10_GN2Xv01_phbb->Write();
  hist_matched_preselected_tautau_ak10_GN2Xv01_pqcd->Write();
  hist_matched_preselected_tautau_ak10_GN2Xv01_phcc->Write();
  hist_matched_preselected_tautau_ak10_GN2Xv01_ptop->Write();
  hist_matched_preselected_tautau_ak10_ECF1->Write();
  hist_matched_preselected_tautau_ak10_ECF2->Write();
  hist_matched_preselected_tautau_ak10_ECF3->Write();
  hist_matched_preselected_tautau_ak10_Split12->Write();
  hist_matched_preselected_tautau_ak10_Split23->Write();
  hist_matched_preselected_tautau_score_bdt_Htautau->Write();

  hist_matched_preselected_tautau_m_only_Hbb_tagger->Write();
  hist_matched_preselected_tautau_m_until_nsubjettiness->Write();

  hist_matched_preselected_bbtautau_score_bdt_HHbbtautau->Write();
  hist_non_matched_preselected_bbtautau_score_bdt_HHbbtautau->Write();

  //***********************************************************************************
  // non matched preselected
  //***********************************************************************************
  
  hist_non_matched_preselected_bb_m->Write();
  hist_non_matched_preselected_bb_pt->Write();
  hist_non_matched_preselected_bb_eta->Write();
  hist_non_matched_preselected_bb_phi->Write();
  hist_non_matched_preselected_bb_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_preselected_bb_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_preselected_bb_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_preselected_bb_ak10_GN2Xv01_phcc->Write();
  hist_non_matched_preselected_bb_ak10_GN2Xv01_ptop->Write();
  hist_non_matched_preselected_bb_ak10_ECF1->Write();
  hist_non_matched_preselected_bb_ak10_ECF2->Write();
  hist_non_matched_preselected_bb_ak10_ECF3->Write();
  hist_non_matched_preselected_bb_ak10_Split12->Write();
  hist_non_matched_preselected_bb_ak10_Split23->Write();
  hist_non_matched_preselected_bb_score_bdt_Hbb->Write();

  hist_non_matched_preselected_tautau_m->Write();
  hist_non_matched_preselected_tautau_pt->Write();
  hist_non_matched_preselected_tautau_eta->Write();
  hist_non_matched_preselected_tautau_phi->Write();
  hist_non_matched_preselected_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_preselected_tautau_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_preselected_tautau_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_preselected_tautau_ak10_GN2Xv01_phcc->Write();
  hist_non_matched_preselected_tautau_ak10_GN2Xv01_ptop->Write();
  hist_non_matched_preselected_tautau_ak10_ECF1->Write();
  hist_non_matched_preselected_tautau_ak10_ECF2->Write();
  hist_non_matched_preselected_tautau_ak10_ECF3->Write();
  hist_non_matched_preselected_tautau_ak10_Split12->Write();
  hist_non_matched_preselected_tautau_ak10_Split23->Write();
  hist_non_matched_preselected_tautau_score_bdt_Htautau->Write();

  //***********************************************************************************
  // preselected non truth-reco info
  //***********************************************************************************
  
  hist_non_matched_info_preselected_bb_m->Write();
  hist_non_matched_info_preselected_bb_pt->Write();
  hist_non_matched_info_preselected_bb_eta->Write();
  hist_non_matched_info_preselected_bb_phi->Write();
  hist_non_matched_info_preselected_bb_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_info_preselected_bb_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_info_preselected_bb_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_info_preselected_bb_ak10_GN2Xv01_phcc->Write();
  hist_non_matched_info_preselected_bb_ak10_GN2Xv01_ptop->Write();
  hist_non_matched_info_preselected_bb_ak10_ECF1->Write();
  hist_non_matched_info_preselected_bb_ak10_ECF2->Write();
  hist_non_matched_info_preselected_bb_ak10_ECF3->Write();
  hist_non_matched_info_preselected_bb_ak10_Split12->Write();
  hist_non_matched_info_preselected_bb_ak10_Split23->Write();
  
  hist_non_matched_info_preselected_tautau_m->Write();
  hist_non_matched_info_preselected_tautau_pt->Write();
  hist_non_matched_info_preselected_tautau_eta->Write();
  hist_non_matched_info_preselected_tautau_phi->Write();
  hist_non_matched_info_preselected_tautau_tau_n2_over_n1_subjettiness->Write();
  hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_phbb->Write();
  hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_pqcd->Write();
  hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_phcc->Write();
  hist_non_matched_info_preselected_tautau_ak10_GN2Xv01_ptop->Write();
  hist_non_matched_info_preselected_tautau_ak10_ECF1->Write();
  hist_non_matched_info_preselected_tautau_ak10_ECF2->Write();
  hist_non_matched_info_preselected_tautau_ak10_ECF3->Write();
  hist_non_matched_info_preselected_tautau_ak10_Split12->Write();
  hist_non_matched_info_preselected_tautau_ak10_Split23->Write();

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

  hist_boosted_cutflow_small_jets->Write();
  
  //***********************************************************
  // Histograms for small R jets
  //***********************************************************

  hist_boosted_njets->Write();
  
  //comparison_histograms
  hist_truth_HH_pt->Write();
  hist_computed_HH_pt->Write();
  hist_truth_HH_m->Write();
  hist_computed_HH_m->Write();

  // percentages matched and preselected events
  percentages_matched_and_preselected_events_BbbBtautau->Write();
  percentages_matched_and_preselected_events_only_Bbb->Write();
  percentages_matched_and_preselected_events_only_Btautau->Write();
  percentages_statistical_parameters_for_preselected_events->Write();
  
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
