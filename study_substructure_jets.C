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

  // Print the 
  print_list_of_branches(boosted_inTree);
  print_list_of_branches(resolved_inTree);
  
  // Find all the branches with the words tau and jets for the boosted config
  find_branches_names(boosted_inTree, "boosted", "tau");
  find_branches_names(boosted_inTree, "boosted", "jet");


  // Close the files
  boosted_inFile->Close();
  resolved_inFile->Close(); 
}
