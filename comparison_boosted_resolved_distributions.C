#include "comparison_boosted_resolved_distributions.h"

void comparison_boosted_resolved_distributions(){

  // ************************************* 
  // Print the names of the branches in the given tree
  // *************************************
  
  print_list_of_branches(boosted_inTree);
  // print_list_of_branches(resolved_inTree);

  // ************************************* 
  // Find all the branches with the words tau and jets for the boosted config
  // *************************************

  vector <string> list_names_of_branches = {"bbtt_H", "passesOR", "truth"};

  for(int ii = 0; ii < list_names_of_branches.size(); ii++){
    find_branches_names(list_names_of_branches[ii]);
  }
  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address();
  
  Int_t entries = boosted_inTree->GetEntries();
  int b_nbytes=0;
  int r_nbytes=0;

  // ************************************* 
  // Fill some histograms
  // *************************************
  
  fill_histograms();

  // ************************************* 
  // Ploting distributions for boosted and resolved configs
  // *************************************
  
  vector<string> list_of_plots = {"tautau_m", "tautau_pT", "bb_m", "bb_pT", "recojet_antikt4_passesOR", "bbtt_Jet_b1_pt", "bbtt_Jet_b2_pt"};
  /*
  for(int ii=0; ii < list_of_plots.size(); ii++){
    plot_distributions(list_of_plots[ii]);
  }
  */
  // plot_distributions("tau_passesOR");
  // plot_distributions("recojet_antikt4_passesOR");
 

  // ************************************* 
  // Print some values for some branches, etc
  // *************************************

  print_some_values();
  
  // ************************************* 
  // Close the files
  // *************************************
  
  boosted_inFile->Close();
  resolved_inFile->Close(); 
}
