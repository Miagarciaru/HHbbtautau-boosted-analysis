#include "study_substructure_jets.h"

void study_substructure_jets(){

  // Path of the merged samples
  
  TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_";
  TString name_config="boosted";
  path+=name_config;
  path+="_config.root";

  TFile* inFile = TFile::Open(path);

  // Access the input tree
  TTree *inTree = (TTree*) inFile->Get("AnalysisMiniTree");

  print_list_of_branches(inTree);

  // Find all the branches with the words tau and jets
  find_branches_names(inTree, name_config, "tau");
  find_branches_names(inTree, name_config, "jet");
  
}
