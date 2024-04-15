#include <TMath.h>
#include <TLorentzVector.h>
#include "functions_cuts_implementation.h"


void cuts_implementation(){

  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address_outTree();


  Int_t nentries = outTree->GetEntries();
  int nbytes = 0;

  int count_b_tau_matched_recojets = 0;

  int count_non_matched_events = 0;
  int count_truth_Rbb_Rtautau = 0;
  int count_truth_Rbb_Btautau = 0;
  int count_truth_Bbb_Rtautau = 0;
  int count_truth_Bbb_Btautau = 0;

  int count_pos_resolved_b1_config = 0;
  int count_pos_resolved_b2_config = 0;
  int count_pos_resolved_tau1_config = 0;
  int count_pos_resolved_tau2_config = 0;  

  int count_pos_resolved_HH_pt_config = 0;
  int count_pos_resolved_HH_phi_config = 0;
  int count_pos_resolved_HH_eta_config = 0;
  int count_pos_resolved_HH_m_config = 0;


  int count_all_objects_resolved_config = 0;

  int count_truth_HH_pt_pos_values = 0;
  int count_truth_HH_m_pos_values = 0; 
  
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = outTree->GetEntry(ii);  
    
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
    
    if( (bbtt_Jet_b1_pt_NOSYS > 0) && (bbtt_Jet_b2_pt_NOSYS > 0) && (bbtt_Tau1_pt_NOSYS > 0) && (bbtt_Tau2_pt_NOSYS > 0) ){
      count_all_objects_resolved_config+=1;
    }

    if(truth_HH_pt > 0){ count_truth_HH_pt_pos_values+=1;}
    if(truth_HH_m > 0){ count_truth_HH_m_pos_values+=1;}
  }

  
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

  cout << "Number of events that passed the resolved selection (counting b1_pt positive values): " << count_pos_resolved_b1_config << endl;
  cout << "Number of events that passed the resolved selection (counting b2_pt positive values): " << count_pos_resolved_b2_config << endl;
  cout << "Number of events that passed the resolved selection (counting tau1_pt positive values): " << count_pos_resolved_tau1_config << endl;
  cout << "Number of events that passed the resolved selection (counting tau2_pt positive values): " << count_pos_resolved_tau2_config << endl;
  
  cout << "Number of events that passed the resolved selection (counting HH_pt positive values): " << count_pos_resolved_HH_pt_config << endl;
  cout << "Number of events that passed the resolved selection (counting HH_m positive values): " << count_pos_resolved_HH_m_config << endl;
  
  cout << "Number of events that passed the resolved selection (counting all possible objects values): " << count_all_objects_resolved_config << endl;

  cout << "The number of positive values for truth_HH_pt is: " << count_truth_HH_pt_pos_values << endl;

  cout << "The number of positive values for truth_HH_m is: " << count_truth_HH_m_pos_values << endl;
 
  applying_HH_cuts(); // Fill the graphs of the r1 ratio after applying the massHH cut

  plot_graphs_for_cuts_on_variables("massHH_cut_r1");
  
  plot_graphs_for_cuts_on_variables("ptHH_cut_r1");

  outFile->Close();
}
