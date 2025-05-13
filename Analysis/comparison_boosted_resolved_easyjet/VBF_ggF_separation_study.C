#include "functions_VBF_ggF_study.h"

void VBF_ggF_separation_study(TString sample, TString output_folder){
  
  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  
  set_branch_address();
  
  // ************************************* 
  // Fill some histograms
  // *************************************

  Int_t VBF_entries = VBF_inTree->GetEntries();
  Int_t ggF_entries = ggF_inTree->GetEntries();
  int nbytes = 0;

  int count_VBF = 0;
  int count_ggF = 0;
  
  for(int ii = 0; ii < VBF_entries; ii++){
    
    nbytes = VBF_inTree->GetEntry(ii);

    boosted_candidates_VBF();
    pairs_small_jets_VBF();
    compute_variables_for_topological_processes_VBF();
    
    if(is_boosted_bbtautau_VBF == true && is_jet12_matched_VBF == true){
      fill_histograms_VBF();
      count_VBF++;
    }

    hist_boosted_njets_VBF->Fill(VBF_recojet_antikt4PFlow_pt___NOSYS->size());
    hist_boosted_bb_candidates_VBF->Fill(count_bb_candidates_VBF);
    hist_boosted_tautau_candidates_VBF->Fill(count_tautau_candidates_VBF);
  }
  
  for(int ii=0; ii < ggF_entries; ii++){
    
    nbytes = ggF_inTree->GetEntry(ii);
    
    boosted_candidates_ggF();
    pairs_small_jets_ggF();
    compute_variables_for_topological_processes_ggF();
    
    if(is_boosted_bbtautau_ggF == true && is_jet12_matched_ggF == true ){
      fill_histograms_ggF();
      count_ggF++;
    }

    hist_boosted_njets_ggF->Fill(ggF_recojet_antikt4PFlow_pt___NOSYS->size());
    hist_boosted_bb_candidates_ggF->Fill(count_bb_candidates_ggF);
    hist_boosted_tautau_candidates_ggF->Fill(count_tautau_candidates_ggF);
  }

  fix_underflow_overflow(hist_boosted_jet12_m_VBF);
  fix_underflow_overflow(hist_boosted_jet12_m_ggF);

  fix_underflow_overflow(hist_boosted_jet12_pt_VBF);
  fix_underflow_overflow(hist_boosted_jet12_pt_ggF);

  fix_underflow_overflow(hist_boosted_jet12_deta_VBF);
  fix_underflow_overflow(hist_boosted_jet12_deta_ggF);

  fix_underflow_overflow(hist_boosted_jet12_dphi_VBF);
  fix_underflow_overflow(hist_boosted_jet12_dphi_ggF);

  fix_underflow_overflow(hist_boosted_jet12_dR_VBF);
  fix_underflow_overflow(hist_boosted_jet12_dR_ggF);
  
  cout << "Number of VBF boosted events (entries in the VBF sample): " << VBF_entries << endl;
  cout << "Number of VBF boosted events (by the selection cuts): " << count_VBF++ << endl;

  cout << "Number of ggF boosted events (entries in the ggF sample): " << ggF_entries << endl;
  cout << "Number of ggF boosted events (by the selection cuts): " << count_ggF++ << endl;
  
  // ************************************* 
  // Ploting distributions for boosted and resolved configs
  // *************************************
  /*
  vector<string> list_of_plots = {"tautau_m", "tautau_pT", "tautau_ECF1", "tautau_ECF2", "tautau_ECF3" , "tautau_Split12", "tautau_Split23", "tautau_n1_nsubjettiness", "tautau_n2_nsubjettiness", "tautau_n3_nsubjettiness", "bb_m", "bb_pT", "bb_ECF1", "bb_ECF2", "bb_ECF3", "bb_Split12", "bb_Split23", "bb_n1_nsubjettiness", "bb_n2_nsubjettiness", "bb_n3_nsubjettiness", "njets", "bb_jets_n", "tautau_jets_n", "neither_bb_nor_tautau_jets_m", "neither_bb_nor_tautau_jets_pT", "neither_bb_nor_tautau_jets_ECF1", "neither_bb_nor_tautau_jets_ECF2", "neither_bb_nor_tautau_jets_ECF3"};
  */
  
  vector<string> list_of_plots = {"tautau_m", "tautau_pT", "bb_m", "bb_pT", "njets", "bb_jets_n", "tautau_jets_n", "jet12_m", "jet12_pt", "jet12_deta", "jet12_dphi", "jet12_dR", "jet12_Zeppenfeld_Hbb", "jet12_Zeppenfeld_Htautau", "Zeppenfeld_jet12"};
  
  for(int ii=0; ii < list_of_plots.size(); ii++){
    plot_distributions(list_of_plots[ii]);
  }

  // ************************************* 
  // Close the files
  // *************************************
  
  VBF_inFile->Close();
  ggF_inFile->Close(); 
}
