#include <TMath.h>
#include <TLorentzVector.h>
#include "functions_VBF_ggF_study.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

void VBF_ggF_separation_study(TString sample, TString output_folder){

  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  cout << "Processing: " << sample << endl;
  cout << "----------------------------------------------------------------------------------------------------------------" << endl;

  // Define the sample label to identify which samples is being used during the analysis and the name of the output root file
  process_label(sample);
  
  // Open the output files and get access to the output tree
  
  TFile* inFile_root = TFile::Open(sample);
  TTree* inTree_root = (TTree*) inFile_root->Get("AnalysisMiniTree");

  // Open the output files and get access to the output tree

  TString path_output_file = output_folder+"/"+name_output_root_file;

  cout << "******************* \t " << path_output_file << " \t ************************" << endl;

  TFile* outFile_root = new TFile(path_output_file, "RECREATE");
  TTree* outTree_root = new TTree("AnalysisMiniTree", "AnalysisMiniTree");
    
  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address_inTree(inTree_root);
  define_output_branches(outTree_root);

  // ************************************* 
  // Fill some histograms
  // *************************************

  Int_t n_entries = inTree_root->GetEntries();
  int nbytes = 0;

  int count_matched_events = 0;
  
  for(int ii = 0; ii < n_entries; ii++){
    
    nbytes = inTree_root->GetEntry(ii);

    boosted_candidates();
    pairs_small_jets();
    compute_variables_for_topological_processes();
    cutflow_small_R_jets();
    
    smallR_jets_n = recojet_antikt4PFlow_pt___NOSYS->size();
    largeR_jets_n = recojet_antikt10UFO_pt___NOSYS->size();
    
    if(is_boosted_bbtautau == true && is_jet12_matched_mjj_sel == true){
      fill_histograms();
      hist_boosted_njets->Fill(recojet_antikt4PFlow_pt___NOSYS->size());
      count_matched_events++;
    }
   
    hist_boosted_bb_candidates->Fill(count_bb_candidates);
    hist_boosted_tautau_candidates->Fill(count_tautau_candidates);

    if(is_boosted_bbtautau == true && is_jet12_matched_mjj_sel == true) outTree_root->Fill();
  }
  
  fix_underflow_overflow(hist_boosted_jet12_m);
  fix_underflow_overflow(hist_boosted_jet12_pt);
  fix_underflow_overflow(hist_boosted_jet12_deta);
  fix_underflow_overflow(hist_boosted_jet12_dphi);
  fix_underflow_overflow(hist_boosted_jet12_dR);

  hist_boosted_cutflow_small_jets->SetBinContent(1, 100.0*count_matched_events/count_matched_events);
  hist_boosted_cutflow_small_jets->SetBinContent(2, 100.0*overlap_jj_selection_methods/count_matched_events);
  hist_boosted_cutflow_small_jets->SetBinContent(3, 100.0*eta_smalljets_cutflow/count_matched_events);
  hist_boosted_cutflow_small_jets->SetBinContent(4, 100.0*minpt_smalljets_cutflow/count_matched_events);
  hist_boosted_cutflow_small_jets->SetBinContent(5, 100.0*min_mjj_smalljets_cutflow/count_matched_events);
  hist_boosted_cutflow_small_jets->SetBinContent(6, 100.0*min_dR_smalljets_cutflow/count_matched_events);
  hist_boosted_cutflow_small_jets->SetBinContent(7, 100.0*all_cuts_applied_cutflow/count_matched_events);

  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(1, "Total Events");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(2, "pT same sel");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(3, "eta op. sign");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(4, "min pT > 30 GeV");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(5, "min mjj > 500 GeV");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(6, "dR > 3");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(7, "all cuts ap.");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(8, "BDT cut > 0.8");
  
  //****************************************************
  //Save Histograms in the output root file
  //****************************************************
  
  write_histograms();
  
  outFile_root->Write();
  
  cout << "Number of VBF boosted events like (number of entries in the sample): " << n_entries << endl;
  cout << "Number of VBF boosted events like (by the selected cuts): " << count_matched_events << endl;
  cout << "Number of events overlapped between the two jj selection methods: " << overlap_jj_selection_methods << " (" << 100.0*overlap_jj_selection_methods/count_matched_events << " %)" << endl;
  cout << "Number of jets unordered: " << number_of_desordered_small_jets_pT_candidates << endl;
  
  // ************************************* 
  // Ploting distributions for boosted and resolved configs
  // *************************************
  /*
  vector<string> list_of_plots = {"tautau_m", "tautau_pT", "tautau_ECF1", "tautau_ECF2", "tautau_ECF3" , "tautau_Split12", "tautau_Split23", "tautau_n1_nsubjettiness", "tautau_n2_nsubjettiness", "tautau_n3_nsubjettiness", "bb_m", "bb_pT", "bb_ECF1", "bb_ECF2", "bb_ECF3", "bb_Split12", "bb_Split23", "bb_n1_nsubjettiness", "bb_n2_nsubjettiness", "bb_n3_nsubjettiness", "njets", "bb_jets_n", "tautau_jets_n", "neither_bb_nor_tautau_jets_m", "neither_bb_nor_tautau_jets_pT", "neither_bb_nor_tautau_jets_ECF1", "neither_bb_nor_tautau_jets_ECF2", "neither_bb_nor_tautau_jets_ECF3"};
  
  vector<string> list_of_plots = {"tautau_m", "tautau_pT", "bb_m", "bb_pT", "njets", "bb_jets_n", "tautau_jets_n", "jet12_m", "jet12_pt", "jet12_deta", "jet12_dphi", "jet12_dR", "jet12_Zeppenfeld_Hbb", "jet12_Zeppenfeld_Htautau", "Zeppenfeld_jet12"};
  
  for(int ii=0; ii < list_of_plots.size(); ii++){
    plot_distributions(list_of_plots[ii]);
  }
  */
  
  // ************************************* 
  // Close the files
  // *************************************
  
  inFile_root->Close();
  outFile_root->Close();
  
}
