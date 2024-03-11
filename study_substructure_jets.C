#include "study_substructure_jets.h"

void study_substructure_jets(){

  // Path of the merged samples
  
  TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_";
  TString path_boosted_sample=path+"boosted_config.root";
  TString path_resolved_sample=path+"resolved_config.root";

  // Open the input files and access to the trees

  TFile* boosted_inFile = TFile::Open(path_boosted_sample);
  TTree* boosted_inTree = (TTree*) boosted_inFile->Get("AnalysisMiniTree");
  
  TFile* resolved_inFile = TFile::Open(path_resolved_sample);
  TTree* resolved_inTree = (TTree*) resolved_inFile->Get("AnalysisMiniTree");

  // Print the names of the branches in the given tree
  
  // print_list_of_branches(boosted_inTree);
  // print_list_of_branches(resolved_inTree);
  
  // Find all the branches with the words tau and jets for the boosted config

  find_branches_names(boosted_inTree, "boosted", "bbtt_H");
  find_branches_names(resolved_inTree, "resolved", "bbtt_H");
  
  set_branch_address(boosted_inTree, resolved_inTree);
  /*
  boosted_inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &boosted_bbtt_H_vis_tautau_pt_NOSYS);
  boosted_inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &boosted_bbtt_H_vis_tautau_m);
  boosted_inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &boosted_bbtt_H_bb_pt_NOSYS);
  boosted_inTree->SetBranchAddress("bbtt_H_bb_m", &boosted_bbtt_H_bb_m);
 
  resolved_inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &resolved_bbtt_H_vis_tautau_pt_NOSYS);
  resolved_inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &resolved_bbtt_H_vis_tautau_m);
  resolved_inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &resolved_bbtt_H_bb_pt_NOSYS);
  resolved_inTree->SetBranchAddress("bbtt_H_bb_m", &resolved_bbtt_H_bb_m);
 

  boosted_inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &boosted_bbtt_H_vis_tautau_pt_NOSYS, &b_boosted_bbtt_H_vis_tautau_pt_NOSYS);
  boosted_inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &boosted_bbtt_H_vis_tautau_m, &b_boosted_bbtt_H_vis_tautau_m);
  boosted_inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &boosted_bbtt_H_bb_pt_NOSYS, &b_boosted_bbtt_H_bb_pt_NOSYS);
  boosted_inTree->SetBranchAddress("bbtt_H_bb_m", &boosted_bbtt_H_bb_m, &b_boosted_bbtt_H_bb_m);

  
  resolved_inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &resolved_bbtt_H_vis_tautau_pt_NOSYS, &b_resolved_bbtt_H_vis_tautau_pt_NOSYS) \
    ;
  resolved_inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &resolved_bbtt_H_vis_tautau_m, &b_resolved_bbtt_H_vis_tautau_m);
  resolved_inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &resolved_bbtt_H_bb_pt_NOSYS, &b_resolved_bbtt_H_bb_pt_NOSYS);
  resolved_inTree->SetBranchAddress("bbtt_H_bb_m", &resolved_bbtt_H_bb_m, &b_resolved_bbtt_H_bb_m);
  */
  
  Int_t entries = boosted_inTree->GetEntries();
  int nbytes=0;

  for(int ii = 0; ii < 50; ii++){
    nbytes = boosted_inTree->GetEntry(ii);
    cout << boosted_bbtt_H_vis_tautau_m << "\t" << resolved_bbtt_H_vis_tautau_m << endl; 
  }
  
  plot_distributions(boosted_inTree, resolved_inTree);
  
  // Close the files
  
  boosted_inFile->Close();
  resolved_inFile->Close(); 
}
