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
  int diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt = 0;
  int overlap_resolved_and_preselected = 0;
  
  // Convert char* to float using std::atof()
  float min_pT_recojet_cut_MeV = 1000*std::stoi(min_pT); // min pT in MeV
  
  for(int ii=0; ii < nentries*fraction; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes();
    define_reconstructed_objects();
    define_preselected_events();
    apply_preselection(min_pT_recojet_cut_MeV);
    
    fill_acceptance_ratios();

    if(passed_reco_truth_match_pT_cut == true){
      fill_histograms_matched_truth_recojets();
    }

    if(passed_preselection_pT_cut == true){
      fill_histograms_preselected_jets();
    }

    // Counting preselected bb jets after each cut on pT min
    if( matched_preselected_bb == true && passed_preselection_bb_pT_cut == true){
      matched_preselected_bb_events++;
      if( ( class_event==2 || class_event==3 ) && passed_reco_truth_match_bb_pT_cut == true ){
        overlap_matched_preselected_bb_events++;
      }
      else{
	preselected_bb_non_matched++;
      }
    }

    // Counting preselected tautau jets after each cut on pT min
    if( matched_preselected_tautau == true && passed_preselection_tautau_pT_cut == true){
      matched_preselected_tautau_events++;
      if( ( class_event==1 || class_event==3 ) && passed_reco_truth_match_tautau_pT_cut == true ){
	overlap_matched_preselected_tautau_events++;
      }
      else{
	preselected_tautau_non_matched++;
      }
    }

    // Counting preselected Bbb Btautau jets after each cut on pT min
    if( matched_preselection == true && passed_preselection_pT_cut == true){
      matched_preselected_events++;
      if( class_event==3 && passed_reco_truth_match_pT_cut == true ){
	overlap_matched_preselected_events++;
      }
      else{
	preselected_non_matched++;
      }
    }
    
    // Counting truth-reco bb jets after each cut on pT min
    if( passed_reco_truth_match_bb_pT_cut == true ){
      if( class_event==2 || class_event==3 ){
	matched_bb_events++;
	if( matched_preselected_bb == false || passed_preselection_bb_pT_cut == false ){
	  matched_bb_non_preselected++;
	}
      }
    }

    // Counting truth-reco tautau jets after each cut on pT min
    if( passed_reco_truth_match_tautau_pT_cut == true ){
      if( class_event==1 || class_event==3 ){
	matched_tautau_events++;
	if( matched_preselected_tautau == false || passed_preselection_tautau_pT_cut == false ){
	  matched_tautau_non_preselected++;
	}
      }
    }

    // Counting truth-reco Bbb-Btautau jets after each cut on pT min
    if( passed_reco_truth_match_pT_cut == true ){
      if( class_event==3 ){
	matched_events++;
	if( matched_preselection == false || passed_preselection_pT_cut == false ){
	  matched_non_preselected++;
	}
      }
    }
    
    if( (matched_preselection == true) && (bbtt_HH_vis_m > 0) && (passed_preselection_pT_cut == true) ){
      overlap_resolved_and_preselected++;
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
        
    counter_for_stat();
    // Fill the output files with the info for events passing the Boosted analysis or the resolved selection only
    if( (class_event!=-1) || (matched_preselection == true) || (bbtt_HH_vis_m > 0) ) outTree->Fill();
    
  }

  // Fill percentages Bbb
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 1, 100.0*matched_bb_non_preselected/matched_bb_events); // Matched events percentages not being preselected
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 2, 100.0*overlap_matched_preselected_bb_events/matched_bb_events); // Matched events percentages being preselected
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 1, 100.0*preselected_bb_non_matched/matched_preselected_bb_events); // Preselected events percentages not being matched
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 2, 100.0*overlap_matched_preselected_bb_events/matched_preselected_bb_events); // Preselected events percentages being matched

  percentages_matched_and_preselected_events_only_Bbb->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{bb} events");
  percentages_matched_and_preselected_events_only_Bbb->GetXaxis()->SetBinLabel(2, "Preselected B_{bb} events");


  // Fill percentages Btautau
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 1, 100.0*matched_tautau_non_preselected/matched_tautau_events); // Matched events percentages not being preselected
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 2, 100.0*overlap_matched_preselected_tautau_events/matched_tautau_events); // Matched events percentages being preselected
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 1, 100.0*preselected_tautau_non_matched/matched_preselected_tautau_events); // Preselected events percentages not being matched
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 2, 100.0*overlap_matched_preselected_tautau_events/matched_preselected_tautau_events); // Preselected events percentages being matched

  percentages_matched_and_preselected_events_only_Btautau->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{#tau#tau} events");
  percentages_matched_and_preselected_events_only_Btautau->GetXaxis()->SetBinLabel(2, "Preselected B_{#tau#tau} events");
  
  
  // Fill percentages Bbb-Btautau
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 1, 100.0*matched_non_preselected/matched_events); // Matched events percentages not being preselected
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 2, 100.0*overlap_matched_preselected_events/matched_events); // Matched events percentages being preselected
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 1, 100.0*preselected_non_matched/matched_preselected_events); // Preselected events percentages not being matched
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 2, 100.0*overlap_matched_preselected_events/matched_preselected_events); // Preselected events percentages being matched

  percentages_matched_and_preselected_events_BbbBtautau->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{bb}-B{#tau#tau} events");
  percentages_matched_and_preselected_events_BbbBtautau->GetXaxis()->SetBinLabel(2, "Preselected B_{bb}-B{#tau#tau} events");

  
  cout << "Entries: " << nentries << endl;
  cout << "Matched truth events number is: " << matched_truth_events << endl;
  cout << "Number of events where the order of the two b is wrong: " << bad_bjets_pt_selection << endl;
  cout << "Number of events where the order of the two tau is wrong: " << bad_taujets_pt_selection << endl;
  cout << "Number of events with a b and tau jets matched: " << b_tau_matched_jets << endl;
  cout << "Number of events with different sizes on pt and tau1 n subjettiness: " << diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt << endl;
  cout << "Number of matched events: " << matched_events << endl;
  cout << "Number of matched preselected events: " << matched_preselected_events << endl;
  cout << "Overlap of matched and preselected events: " << overlap_matched_preselected_events << endl;
  cout << "Number of matched non preselected events: " << matched_non_preselected << endl;
  cout << "Number of preselected non matched events: " << preselected_non_matched << endl;
  cout << "Relative difference between preselected and all events: " << TMath::Abs(matched_preselected_events-nentries)/nentries << endl;
  cout << "Overlap between resolved selection and the preselection events: " << overlap_resolved_and_preselected << endl;
  cout << "Number of preselected bb jets ordered by pT - nsubjettiness: " << count_preselected_bb_jets_ordered_by_pT << "\t" << count_preselected_bb_jets_ordered_by_nsubjettiness << endl;

  cout << "---------------------------" << endl;

  cout << "Preselected truth-reco percentages Bbb-Btautau:" << endl;
  cout << "Number of matched truth-reco Bbb-Btautau events: " << matched_events << endl;
  cout << "Number of matched preselected Bbb-Btautau events: " << matched_preselected_events << endl;
  cout << "Overlap of truth-reco and preselected Bbb-Btautau events: " << overlap_matched_preselected_events << endl;
  cout << "Number of matched truth-reco non preselected Bbb-Btautau events: " << matched_non_preselected << endl;
  cout << "Number of preselected non matched truth reco Bbb-Btautau events: " << preselected_non_matched << endl;
  
  cout << "---------------------------" << endl;

  cout << "Preselected truth-reco percentages Bbb:" << endl;
  cout << "Number of matched truth-reco Bbb events: " << matched_bb_events << endl;
  cout << "Number of matched preselected Bbb events: " << matched_preselected_bb_events << endl;
  cout << "Overlap of truth-reco and preselected Bbb events: " << overlap_matched_preselected_bb_events << endl;
  cout << "Number of matched truth-reco non preselected Bbb events: " << matched_bb_non_preselected << endl;
  cout << "Number of preselected non matched truth reco Bbb events: " << preselected_bb_non_matched << endl;

  cout << "---------------------------" << endl;

  cout << "Preselected truth-reco percentages Btautau:" << endl;
  cout << "Number of matched truth-reco Btautau events: " << matched_tautau_events << endl;
  cout << "Number of matched preselected Btautau events: " << matched_preselected_tautau_events << endl;
  cout << "Overlap of truth-reco and preselected Btautau events: " << overlap_matched_preselected_tautau_events << endl;
  cout << "Number of matched truth-reco non preselected Btautau events: " << matched_tautau_non_preselected << endl;
  cout << "Number of preselected non matched truth reco Btautau events: " << preselected_tautau_non_matched << endl;

  cout << "---------------------------" << endl;
  
  //****************************************************
  //Save Histograms in the output root file
  //****************************************************
 
  write_histograms();
  
  outFile->Write();

  //print_stat(nentries);
  
  inFile->Close();
  outFile->Close();

  auto end = chrono::steady_clock::now();
  auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();
  auto time_in_min = elapsed/60.;
  cout << "Time taken: " << time_in_min << " min" << endl;

}
