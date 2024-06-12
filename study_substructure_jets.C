#include <TMath.h>
#include <TLorentzVector.h>
#include "declaration_of_functions.h"


void study_substructure_jets(TString sample, TString output_folder){

  // *************************************
  // Open the input files and access to the trees                                                                                              // *************************************
  
  auto start = chrono::steady_clock::now(); //Start the clock
  
  TFile* inFile = TFile::Open(sample);
  TTree* inTree = (TTree*) inFile->Get("AnalysisMiniTree");
    
  process_label(sample);

  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  cout << "Processing: " << process_name << endl;
  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  
  set_branch_address_inTree(inTree);

  Int_t nentries = inTree->GetEntries();
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

  int count_pos_resolved_HH_vis_pt_config = 0;
  int count_pos_resolved_HH_vis_m_config = 0;


  int count_all_objects_resolved_config = 0;

  int count_truth_HH_pt_pos_values = 0;
  int count_truth_HH_m_pos_values = 0;

  //  define_output_branches(outTree);  
  
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes();

    //if( class_event != 3) continue;
    
    define_reconstructed_objects();
    fill_histograms();
    fill_acceptance_ratios();
    
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

    if(bbtt_HH_vis_pt_NOSYS > 0){ count_pos_resolved_HH_vis_pt_config+=1;}
    if(bbtt_HH_vis_m > 0){ count_pos_resolved_HH_vis_m_config+=1;}
   
    if( (bbtt_Jet_b1_pt_NOSYS > 0) && (bbtt_Jet_b2_pt_NOSYS > 0) && (bbtt_Tau1_pt_NOSYS > 0) && (bbtt_Tau2_pt_NOSYS > 0) ){
      count_all_objects_resolved_config+=1;
    }

    if(truth_HH_pt > 0){ count_truth_HH_pt_pos_values+=1;}
    if(truth_HH_m > 0){ count_truth_HH_m_pos_values+=1;}
    
    //    outTree->Fill();
  }

  //  outFile->Write();
  
  
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
  
  cout << "Number of events that passed the resolved selection (counting bbtt_HH_pt positive values): " << count_pos_resolved_HH_pt_config << endl;
  cout << "Number of events that passed the resolved selection (counting bbtt_HH_m positive values): " << count_pos_resolved_HH_m_config << endl;

  cout << "Number of events that passed the resolved selection (counting bbtt_HH_vis_pt positive values): " << count_pos_resolved_HH_vis_pt_config << endl;
  cout << "Number of events that passed the resolved selection (counting bbtt_HH_vis_m positive values): " << count_pos_resolved_HH_vis_m_config << endl;
  
  cout << "Number of events that passed the resolved selection (counting all possible objects values): " << count_all_objects_resolved_config << endl;

  cout << "The number of positive values for truth_HH_pt is: " << count_truth_HH_pt_pos_values << endl;

  cout << "The number of positive values for truth_HH_m is: " << count_truth_HH_m_pos_values << endl;

  //std::vector<TString> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m", "matched_recojets_bb_pt", "matched_recojets_tautau_pt", "matched_recojets_bb_eta", "matched_recojets_tautau_eta", "non_matched_recojets_pt", "non_matched_recojets_eta", "non_matched_recojets_pt_no_class", "non_matched_recojets_eta_no_class", "events_per_class", "matched_bb_dR", "matched_tautau_dR"};
  
  //std::vector<TString> list_of_2D_histograms = {"dR_per_class_bb", "dR_per_class_tautau"};
  /*
  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii], output_folder);
  }
  
  for(int ii=0; ii < list_of_2D_histograms.size(); ii++){
    plot_2D_distributions(list_of_2D_histograms[ii], output_folder);
  }
  */

  plot_distributions_comparison("HH_pt_comparison", output_folder);
  plot_distributions_comparison("HH_m_comparison", output_folder);
  
  //std::vector<TString> list_of_ratios_acceptance = {"class0_r1_mHH", "class1_r1_mHH", "class2_r1_mHH", "class3_r1_mHH", "class0_r2_mHH", "class1_r2_mHH", "class2_r2_mHH", "class3_r2_mHH", "class0_r1_ptHH", "class1_r1_ptHH", "class2_r1_ptHH", "class3_r1_ptHH", "class0_r2_ptHH", "class1_r2_ptHH", "class2_r2_ptHH", "class3_r2_ptHH"};

  //  std::vector<TString> list_of_ratios_acceptance = {"class3_r1_mHH", "class3_r2_mHH", "class3_r1_ptHH", "class3_r2_ptHH", "class3_r1_mHbb", "class3_r2_mHbb", "class3_r1_mHtautau", "class3_r2_mHtautau", "class3_r1_ptHbb", "class3_r2_ptHbb", "class3_r1_ptHtautau", "class3_r2_ptHtautau"};

  //std::vector<TString> list_of_ratios_acceptance = {"class0_r1_mHH"};

  std::vector<TString> list_of_ratios_acceptance = {"class3_r1_mHH", "class3_r2_mHH", "class3_r1_mHbb", "class3_r2_mHbb", "class3_r1_mHtautau", "class3_r2_mHtautau", "class3_r1_ptHH", "class3_r2_ptHH", "class3_r1_ptHbb", "class3_r2_ptHbb", "class3_r1_ptHtautau", "class3_r2_ptHtautau"};
  
  for(int ii=0; ii < list_of_ratios_acceptance.size(); ii++){
    plot_ratios_acceptance(list_of_ratios_acceptance[ii], output_folder);
  }
  
  //plot_ratios_acceptance_group("acceptance_mHH_r1");
  
  inFile->Close();
  //  outFile->Close();

  auto end = chrono::steady_clock::now();
  auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();
  auto time_in_min = elapsed/60.;
  cout << "Time taken: " << time_in_min << " min" << endl;

}
