#include <TMath.h>
#include <TLorentzVector.h>
#include "declaration_of_functions.h"
#include <iostream>
#include <string>
#include <cstdlib>

void study_substructure_jets(TString sample, TString output_folder, string min_pT){

  auto start = chrono::steady_clock::now(); //Start the clock
  
  // *************************************
  // Open the input files and access to the trees
  // *************************************

  // Define the sample label to identify which samples is being used during the analysis and the name of the output root file
  process_label(sample, min_pT);
  
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
  int diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt = 0;
  
  // Convert char* to float using std::atof()
  float min_pT_recojet_cut_MeV = 1000*std::stoi(min_pT); // min pT in MeV
  
  for(int ii=0; ii < nentries*fraction; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes();
    define_reconstructed_objects();

    fill_acceptance_ratios(min_pT_recojet_cut_MeV);

    // min_pT_cut_in_MeV

    if(class_event!=-1){
      float b1_pT = recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin);
      float b2_pT = recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin);
      float tau1_pT = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin);
      float tau2_pT = recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin);
      
      std::vector<float> *min_pT_objects_list = new std::vector<float> {b1_pT, b2_pT, tau1_pT, tau2_pT};
      
      float min_pT_matched_objects_recojets_MeV = *std::min_element(min_pT_objects_list->begin(), min_pT_objects_list->end());

      float min_tagger_Hbb_value = 0.85;
      bool cut_tagger_Hbb = false;
      float value_phbb = 0;
  
      for(int ii=0; ii<recojet_antikt10UFO_GN2Xv01_phbb->size(); ii++){
	value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(ii);
	if(value_phbb >= min_tagger_Hbb_value){
	  cut_tagger_Hbb = true;
	  break;
	}
      }

      float max_nsubjetiness_value = 0.60;
      bool cut_nsubjetiness = true;
      float tau_n2_over_n1_subjettiness = 0;
      
      for(int ii=0; ii < recojet_antikt10UFO_Tau2_wta->size(); ii++){
	tau_n2_over_n1_subjettiness = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
	if(tau_n2_over_n1_subjettiness <= max_nsubjetiness_value){
	  cut_nsubjetiness = false;
	  break;
	}
      }
      
      //if( (min_pT_matched_objects_recojets_MeV >= min_pT_recojet_cut_MeV) && (cut_tagger_Hbb == true) ){
      if( (min_pT_matched_objects_recojets_MeV >= min_pT_recojet_cut_MeV) && (cut_tagger_Hbb == true) && (cut_nsubjetiness == true) ){
	fill_histograms();
      }
    }
    
    int size_Tau1_wta = recojet_antikt10UFO_Tau2_wta->size();
    //int size_Tau1_wta = tau_nProng->size();
    int size_NOSYS_pt = recojet_antikt10UFO_NOSYS_pt->size();
    
    if(size_Tau1_wta != size_NOSYS_pt){
      diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt++;
    }
    
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
  cout << "Number of events with different sizes on pt and tau1 n subjettiness: " << diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt << endl;
  
    
  //****************************************************
  //Save Histograms in the output root file
  //****************************************************
 
  write_histograms();
  
  outFile->Write();

  print_stat(nentries);
  
  inFile->Close();
  outFile->Close();

  auto end = chrono::steady_clock::now();
  auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();
  auto time_in_min = elapsed/60.;
  cout << "Time taken: " << time_in_min << " min" << endl;

}
