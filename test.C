#include <TMath.h>
#include <TLorentzVector.h>
#include "test.h"

void test(){
  

  // print_list_of_branches(inTree);

  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address();

  Int_t nentries = inTree->GetEntries();
  int nbytes = 0;

  bool sum_type_truth_objectsH1 = true;
  int count_events_sum_type_truth_objectsH1 = 0;

  bool sum_type_truth_objectsH2 = true;
  int count_events_sum_type_truth_objectsH2 = 0;

  bool truth_childrenH1_size = true;
  bool truth_childrenH2_size = true;
  int count_events_truth_children_size = 0;

  bool no_match_for_no_correct_size = true;
  int count_events_no_match_for_no_correct_size = 0;

  bool correct_match_pt = true;
  int count_events_correct_match_pt = 0;

  bool no_idx_for_non_matched_objects = true;
  int count_events_no_idx_for_non_matched_objects = 0;

  bool b_tau_recojet = true;
  int count_events_b_tau_recojet = 0;
  
  int count_zero_recojets_size = 0;
 
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes();

    // Warnings
    truth_childrenH1_sum_types(sum_type_truth_objectsH1, count_events_sum_type_truth_objectsH1);
    truth_childrenH2_sum_types(sum_type_truth_objectsH2, count_events_sum_type_truth_objectsH2);
    truth_children_size(truth_childrenH1_size, truth_childrenH2_size, count_events_truth_children_size);
    // Tests
    no_match_for_no_correct_truth_children_size(no_match_for_no_correct_size, count_events_no_match_for_no_correct_size);
    correct_match_truth_leading_subleading_jets(correct_match_pt, count_events_correct_match_pt);
    verification_idx_truth_matched_objects(no_idx_for_non_matched_objects, count_events_no_idx_for_non_matched_objects);
    verification_no_b_tau_in_same_recojet(b_tau_recojet, count_events_b_tau_recojet);
    
    if(recojet_antikt10UFO_NOSYS_pt->size()==0){
      count_zero_recojets_size += 1;
      // cout << ii << endl;
    }
    
  }

   
  // Print tests

  cout << "Testing Process..." << endl;
  
  if( no_match_for_no_correct_size != true ){
    cout << "There are some events that are getting truth objects from zero truth childrens: " << count_events_no_match_for_no_correct_size << endl;
  }

  if( correct_match_pt!= true){
    cout << "There are some events that the bb or tautau truth objects are ordered wronly using the pT value" << count_events_correct_match_pt << endl;
  }

  if( no_idx_for_non_matched_objects != true ){
    cout << "There are some events with zero size for the truth children objects that has idx different for -1. Events: " << count_events_no_idx_for_non_matched_objects << endl;
  }  

  if( b_tau_recojet != true ){
    cout << "There are some b and tau objects that are being matched to the same recojet. Events: " << count_events_b_tau_recojet << endl;
  }

  cout << "There are " << count_zero_recojets_size << " events with zero size for recojets." << endl;
  
  if( (no_match_for_no_correct_size == true) && (correct_match_pt == true)&&(no_idx_for_non_matched_objects==true)&&(b_tau_recojet==true)){
    cout << "All tests passed" << endl;
  }
 

  // Printing some warnings
  
  cout << "Warnings:" << endl;
  if( (truth_childrenH1_size != true) || (truth_childrenH2_size != true) ){
    cout << "The number of events that the truth children objects has a size different of 2 is: " << count_events_truth_children_size << endl;
  }
  
  if( sum_type_truth_objectsH1 != true ){
    cout << "The sum of the two truth children of H1 is different from a bb or tautau pair for " << count_events_sum_type_truth_objectsH1 << " events" << endl;
  }

  if( sum_type_truth_objectsH2 != true ){
    cout << "The sum of the two truth children of H2 is different from a bb or tautau pair for " << count_events_sum_type_truth_objectsH2 << " events" << endl;
  }

  
  inFile->Close();
  
}
