#include <TMath.h>
#include <TLorentzVector.h>
#include "declaration_of_functions.h"
#include "../../Plotting/Plotting.h"

void study_substructure_jets(TString sample, TString output_folder){

  auto start = chrono::steady_clock::now(); //Start the clock
  
  // *************************************
  // Open the input files and access to the trees                                                                                              // *************************************

  // Define the sample label to identify which samples is being used during the analysis and the name of the output root file
  process_label(sample);
  
  // Open the output files and get access to the output tree
  
  TFile* inFile = TFile::Open(sample);
  TTree* inTree = (TTree*) inFile->Get("AnalysisMiniTree");

  // Open the output files and get access to the output tree

  TString path_output_file = output_folder+"/"+name_output_root_file;
 
  TFile* outFile = new TFile(path_output_file, "RECREATE");
  TTree* outTree = new TTree("AnalysisMiniTree", "AnalysisMiniTree");
  
  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  cout << "Processing: " << process_name << endl;
  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  
  set_branch_address_inTree(inTree);

  Int_t nentries = inTree->GetEntries();
  int nbytes = 0;

  define_output_branches(outTree);  

  int matched_truth_events = 0;
  int bad_bjets_pt_selection = 0;
  int bad_taujets_pt_selection = 0;
  int b_tau_matched_jets = 0;
  int matched_events = 0;
  
  for(int ii=0; ii < nentries*fraction; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes();
    define_reconstructed_objects();
    fill_histograms();
    fill_acceptance_ratios();
    
    if(truth_b1_pt > 0){
      matched_truth_events++;
    }
    if( truth_b1_pt < truth_b2_pt ){
      bad_bjets_pt_selection++;
    }
    if( truth_tau1_pt < truth_tau2_pt ){
      bad_taujets_pt_selection++;
    }
    if( (class_event!=-1) && ( (idx_b1truth_recoak10_dRmin==idx_tau1truth_recoak10_dRmin) || (idx_b1truth_recoak10_dRmin==idx_tau2truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin==idx_tau1truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin==idx_tau2truth_recoak10_dRmin) ) ){
      b_tau_matched_jets++;
    }
    if( class_event!=-1 ){
      matched_events++;
    }
        
    counter_for_stat();
    // Fill the output files with the info for events passing the Boosted analysis or the resolved selection only
    if( (class_event!=-1) || (bbtt_HH_vis_m > 0) ) outTree->Fill();
 
  }

  cout << "Matched truth events number is: " << matched_truth_events << endl;
  cout << "Number of events where the order of the two b is wrong: " << bad_bjets_pt_selection << endl;
  cout << "Number of events where the order of the two tau is wrong: " << bad_taujets_pt_selection << endl;
  cout << "Number of events with a b and tau jets matched: " << b_tau_matched_jets << endl;
  cout << "Number of matched events: " << matched_events << endl;
  
  //****************************************************
  //Save Histograms in the output root file
  //****************************************************
 
  write_histograms();
  
  outFile->Write();

  print_stat(nentries);
  
  //std::vector<TString> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m", "matched_recojets_bb_pt", "matched_recojets_tautau_pt", "matched_recojets_bb_eta", "matched_recojets_tautau_eta", "non_matched_recojets_pt", "non_matched_recojets_eta", "non_matched_recojets_pt_no_class", "non_matched_recojets_eta_no_class", "events_per_class", "matched_bb_dR", "matched_tautau_dR"};
  
  std::vector<TString> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m"};
  
  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii], output_folder);
  }
  
  //std::vector<TString> list_of_2D_histograms = {"dR_per_class_bb", "dR_per_class_tautau"};
  
  /*
  for(int ii=0; ii < list_of_2D_histograms.size(); ii++){
    plot_2D_distributions(list_of_2D_histograms[ii], output_folder);
  }
  */

  //plot_distributions_comparison("HH_pt_comparison", output_folder);
  //plot_distributions_comparison("HH_m_comparison", output_folder);
  
  //std::vector<TString> list_of_ratios_acceptance = {"class0_r1_mHH", "class1_r1_mHH", "class2_r1_mHH", "class3_r1_mHH", "class0_r2_mHH", "class1_r2_mHH", "class2_r2_mHH", "class3_r2_mHH", "class0_r1_ptHH", "class1_r1_ptHH", "class2_r1_ptHH", "class3_r1_ptHH", "class0_r2_ptHH", "class1_r2_ptHH", "class2_r2_ptHH", "class3_r2_ptHH"};

  //  std::vector<TString> list_of_ratios_acceptance = {"class3_r1_mHH", "class3_r2_mHH", "class3_r1_ptHH", "class3_r2_ptHH", "class3_r1_mHbb", "class3_r2_mHbb", "class3_r1_mHtautau", "class3_r2_mHtautau", "class3_r1_ptHbb", "class3_r2_ptHbb", "class3_r1_ptHtautau", "class3_r2_ptHtautau"};

  //std::vector<TString> list_of_ratios_acceptance = {"class0_r1_mHH"};

  //std::vector<TString> list_of_ratios_acceptance = {"class3_r1_mHH", "class3_r2_mHH", "class3_r1_mHbb", "class3_r2_mHbb", "class3_r1_mHtautau", "class3_r2_mHtautau", "class3_r1_ptHH", "class3_r2_ptHH", "class3_r1_ptHbb", "class3_r2_ptHbb", "class3_r1_ptHtautau", "class3_r2_ptHtautau"};
  /*
  std::vector<TString> list_of_ratios_acceptance = {"class3_r1_mHbb", "class3_r2_mHbb", "class3_r1_mHtautau", "class3_r2_mHtautau"};
  
  for(int ii=0; ii < list_of_ratios_acceptance.size(); ii++){
    plot_ratios_acceptance(list_of_ratios_acceptance[ii], output_folder);
  }
  */
  inFile->Close();
  outFile->Close();

  auto end = chrono::steady_clock::now();
  auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();
  auto time_in_min = elapsed/60.;
  cout << "Time taken: " << time_in_min << " min" << endl;

}
