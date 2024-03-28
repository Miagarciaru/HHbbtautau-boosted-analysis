#include "study_substructure_jets.h"

void study_substructure_jets(){
  

  // print_list_of_branches(inTree);

  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address();

  // ************************************* 
  // Fill some histograms
  // *************************************

  fill_histograms();

  // ************************************* 
  // Plot some histograms
  // *************************************

  /*
  std::vector<TString> list_of_histograms = {"truth_b1_m", "truth_b2_m", "truth_b1_plus_b2_m"};

  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii]);
  }
  */

  Int_t nentries = inTree->GetEntries();
  int nbytes = 0;

  int count_b_tau_matched_recojets = 0;
  
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    //    truth_objects_asserts(ii);
    truth_matching_reco_objects_asserts(ii, count_b_tau_matched_recojets);
  }

  cout << "The number of events in which there one of the two taus and one of the two bb jets were matched to the same recojet are " << count_b_tau_matched_recojets << " of a total nentries " << nentries << " (" << 100.0*count_b_tau_matched_recojets/nentries << "% of the total nentries)" << endl;
 
  
  inFile->Close();
  
}
