#include <TMath.h>
#include <TLorentzVector.h>
#include "declaration_of_functions.h"


void study_substructure_jets(){

  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address();


  Int_t nentries = inTree->GetEntries();
  int nbytes = 0;

  int count_b_tau_matched_recojets = 0;

  int count_non_matched_events = 0;
  int count_truth_Rbb_Rtautau = 0;
  int count_truth_Rbb_Btautau = 0;
  int count_truth_Bbb_Rtautau = 0;
  int count_truth_Bbb_Btautau = 0;

  define_output_branches();
  
  
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes();
    fill_histograms();
    
    if(class_event == -1){ count_non_matched_events+=1; }
    if(class_event == 0){ count_truth_Rbb_Rtautau+=1; } 
    if(class_event == 1){ count_truth_Rbb_Btautau+=1; }
    if(class_event == 2){ count_truth_Bbb_Rtautau+=1; }
    if(class_event == 3){ count_truth_Bbb_Btautau+=1; }

    outTree->Fill();
  }

  outFile->Write();
  
  
  int sum_all_events = count_non_matched_events + count_truth_Rbb_Rtautau + count_truth_Rbb_Btautau + count_truth_Bbb_Rtautau + count_truth_Bbb_Btautau;

  int sum_truth_matching_events = count_truth_Rbb_Rtautau + count_truth_Rbb_Btautau + count_truth_Bbb_Rtautau + count_truth_Bbb_Btautau;

  cout << "There are " << count_truth_Rbb_Rtautau << " in the truth R_bb-R_tautau (" << 100.0*count_truth_Rbb_Rtautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_truth_Rbb_Btautau << " in the truth R_bb-B_tautau (" << 100.0*count_truth_Rbb_Btautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_truth_Bbb_Rtautau << " in the truth B_bb-R_tautau (" << 100.0*count_truth_Bbb_Rtautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_truth_Bbb_Btautau << " in the truth B_bb-B_tautau (" << 100.0*count_truth_Bbb_Btautau/nentries << "% of the total entries)" << endl;
  /*
  cout << "The number of events in which there are one of the two taus and one of the two bb jets matched to the same recojet is " << count_b_tau_matched_recojets << " of a total nentries " << nentries << " (" << 100.0*count_b_tau_matched_recojets/nentries << "% of the total nentries)" << endl;
  */
  cout << "The sum of all the events into one of the given classes plus the number of events which have at least one truth object without a match with a fat jet is: " << sum_all_events << " (" << 100.0*sum_all_events/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_non_matched_events << " events which have at least one truth object without a match with a fat jet (" << 100.0*count_non_matched_events/nentries << "% of the total entries)" << endl;

  cout << "The sum of all the events which were correctly classified with resolved and boosted bb and tautau jets: " << sum_truth_matching_events << " (" << 100.0*sum_truth_matching_events/nentries << "% of the total entries)" << endl;

  cout << "Total entries: " << nentries << endl;


  std::vector<TString> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m", "matched_recojets_bb_pt", "matched_recojets_tautau_pt", "matched_recojets_bb_eta", "matched_recojets_tautau_eta", "non_matched_recojets_pt", "non_matched_recojets_eta", "non_matched_recojets_pt_no_class", "non_matched_recojets_eta_no_class", "events_per_class", "matched_bb_dR", "matched_tautau_dR"};

  std::vector<TString> list_of_2D_histograms = {"dR_per_class_bb", "dR_per_class_tautau"};
  
  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii]);
  }
  
  for(int ii=0; ii < list_of_2D_histograms.size(); ii++){
    plot_2D_distributions(list_of_2D_histograms[ii]);
  }
  
  inFile->Close();
  outFile->Close();
}
