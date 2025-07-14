#include <TMath.h>
#include <TLorentzVector.h>
#include "declaration_of_functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "TMVA/RTensor.hxx"
using namespace TMVA::Experimental;
 
// #include <TMVA::RModelParser_ONNX.hxx>
// #include "TMVA/Experimental/ONNX/ONNXRuntime.hxx"

void study_substructure_jets(TString sample, TString output_folder, string min_pT){

  auto start = chrono::steady_clock::now(); //Start the clock

  // set precision for double and float variables
  std::cout << std::fixed << std::setprecision(2);
  
  // *************************************
  // Open the input files and access to the trees
  // *************************************

  // Define the sample label to identify which samples is being used during the analysis and the name of the output root file
  process_label(sample, min_pT);
  
  // Open the output files and get access to the output tree
  
  TFile* inFile_root = TFile::Open(sample);
  TTree* inTree_root = (TTree*) inFile_root->Get("AnalysisMiniTree");

  // Open the output files and get access to the output tree

  TString path_output_file = output_folder+"/"+name_output_root_file;
 
  TFile* outFile_root = new TFile(path_output_file, "RECREATE");
  TTree* outTree_root = new TTree("AnalysisMiniTree", "AnalysisMiniTree");

  // Load the models
  string path_base_models = "../preselection_boosted_bbtautau/ML_models/";
  string path_model_1 = path_base_models+"tmva101_bb_jets.root";
  string path_model_2 = path_base_models+"tmva101_tautau_jets.root";
  string path_model_3 = path_base_models+"tmva101_bbtautau_events.root";

  TMVA::Experimental::RBDT model_bb_jets("myBDT_bb_jets", path_model_1);
  TMVA::Experimental::RBDT model_tautau_jets("myBDT_tautau_jets", path_model_2);
  TMVA::Experimental::RBDT model_bbtautau_events("myBDT_bbtautau_events", path_model_3);
  
  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  cout << "Processing: " << process_name << endl;
  cout << "----------------------------------------------------------------------------------------------------------------" << endl;
  
  set_branch_address_inTree(inTree_root);

  Int_t nentries = inTree_root->GetEntries();
  int nbytes = 0;

  define_output_branches(outTree_root);  

  int matched_truth_events = 0;
  int bad_bjets_pt_selection = 0;
  int bad_taujets_pt_selection = 0;
  int b_tau_matched_jets = 0;
  int diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt = 0;
  int overlap_resolved_and_preselected = 0;
  
  // Convert char* to float using std::atof()
  float min_pT_recojet_cut_MeV = 1000*std::stoi(min_pT); // min pT in MeV
  
  for(int ii=0; ii < nentries*fraction; ii++){
    
    nbytes = inTree_root->GetEntry(ii);  

    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    define_classes(min_pT_recojet_cut_MeV);
    define_reconstructed_objects();
    // define_reco_truth_boosted_jets_hh();
    define_preselected_events(min_pT_recojet_cut_MeV, model_bb_jets, model_tautau_jets, model_bbtautau_events);
    
    pairs_small_jets();
    compute_variables_for_topological_processes();
    cutflow_small_R_jets();
    correct_match_between_truth_reco_and_preselected_objects();
    counting_statistical_parameters();
    process_like();

    fill_acceptance_ratios();
    fill_histograms_matched_truth_recojets(min_pT_recojet_cut_MeV);
    fill_histograms_preselected_jets();
    
    hist_nevents_per_class->Fill(class_event);
    
    if( (matched_preselection == true) && (bbtt_HH_vis_m > 0) ){
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
    // if( (truth_reco_match_for_boosted_bb==true || truth_reco_match_for_boosted_tautau==true) || (matched_preselection == true) || (bbtt_HH_vis_m > 0) ) outTree_root->Fill();
    if( (truth_reco_match_for_boosted_bb==true || truth_reco_match_for_boosted_tautau==true) || bbtt_HH_vis_m > 0 ) outTree_root->Fill();
    // outTree_root->Fill();
  
  }
  
  //****************************************************************************
  // Compute statistical parameters for preselected events
  //****************************************************************************
  compute_statistical_parameters();

  
  cout << "Entries: " << nentries << endl;
  cout << "Matched truth events number is: " << matched_truth_events << endl;
  cout << "Number of events where the order of the two b is wrong: " << bad_bjets_pt_selection << endl;
  cout << "Number of events where the order of the two tau is wrong: " << bad_taujets_pt_selection << endl;
  cout << "Number of events with a b and tau jets matched: " << b_tau_matched_jets << endl;
  cout << "Number of events with different sizes on pt and tau1 n subjettiness: " << diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt << endl;
  cout << "Number of matched events: " << matched_bbtautau_events << endl;
  cout << "Number of matched preselected events: " << matched_preselected_bbtautau_events << endl;
  cout << "Overlap of matched and preselected events: " << overlap_matched_preselected_bbtautau_events << endl;
  cout << "Number of matched non preselected events: " << matched_bbtautau_non_preselected << endl;
  cout << "Number of preselected non matched events: " << preselected_bbtautau_non_matched << endl;
  cout << "Relative difference between preselected and all events: " << TMath::Abs(matched_preselected_bbtautau_events-nentries)/nentries << endl;
  cout << "Overlap between resolved selection and the preselection events: " << overlap_resolved_and_preselected << endl;
  cout << "Number of preselected bb jets ordered by pT - nsubjettiness: " << count_preselected_bb_jets_ordered_by_pT << "\t" << count_preselected_bb_jets_ordered_by_nsubjettiness << endl;

  cout << "---------------------------" << endl;

  cout << "Preselected truth-reco percentages Bbb-Btautau:" << endl;
  cout << "Number of matched truth-reco Bbb-Btautau events: " << matched_bbtautau_events << endl;
  cout << "Number of matched preselected Bbb-Btautau events: " << matched_preselected_bbtautau_events << endl;
  cout << "Overlap of truth-reco and preselected Bbb-Btautau events: " << overlap_matched_preselected_bbtautau_events << endl;
  cout << "Number of matched truth-reco non preselected Bbb-Btautau events: " << matched_bbtautau_non_preselected << endl;
  cout << "Number of preselected non matched truth reco Bbb-Btautau events: " << preselected_bbtautau_non_matched << endl;
  
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
  // Saving relevant info in a txt file
  //****************************************************
  
  std::ofstream outFile("output_analysis/info_analysis_part.txt", std::ios::app); // Open in append mode

  outFile << "----------------------------------------------------------------------------------------------------------------" << endl;
  outFile << "Processing: " << process_name << endl;
  outFile << "----------------------------------------------------------------------------------------------------------------" << endl;
  
  outFile << "Total entries: " << nentries << endl;
  outFile << "Matched truth events number is: " << matched_truth_events << "(" << 100.0*matched_truth_events/nentries << "%)" << endl;
  if(bad_bjets_pt_selection!=0 || bad_taujets_pt_selection!= 0 || b_tau_matched_jets!=0 || diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt!=0){
    outFile << "An issue occurred, revise the following info: " << bad_bjets_pt_selection << endl;
    outFile << "\t Number of events where the order of the two b is wrong: " << bad_bjets_pt_selection << endl;
    outFile << "\t Number of events where the order of the two tau is wrong: " << bad_taujets_pt_selection << endl;
    outFile << "\t Number of events with a b and tau jets matched: " << b_tau_matched_jets << endl;
    outFile << "\t Number of events with different sizes on pt and tau1 n subjettiness: " << diff_size_recojet_antikt10UFO_Tau1_wta_NOSYS_pt << endl;
  }

  outFile << "---------------------------" << endl;

  outFile << "Preselected and truth-reco percentages Bbb-Btautau:" << endl;
  outFile << "Number of matched truth-reco Bbb-Btautau events: " << matched_bbtautau_events << "(" << 100.0*matched_bbtautau_events/nentries << "%)" << endl;
  outFile << "Number of matched preselected Bbb-Btautau events: " << matched_preselected_bbtautau_events << "(" << 100.0*matched_preselected_bbtautau_events/nentries << "%)" << endl;
  outFile << "Overlap of truth-reco and preselected Bbb-Btautau events: " << overlap_matched_preselected_bbtautau_events << endl;
  outFile << "Number of matched truth-reco non preselected Bbb-Btautau events: " << matched_bbtautau_non_preselected << endl;
  outFile << "Number of matched truth-reco non preselected Bbb-Btautau info events: " << matched_bbtautau_non_preselected_info << endl;
  outFile << "Number of preselected non matched truth reco Bbb-Btautau events: " << preselected_bbtautau_non_matched << endl;
  outFile << "Number of preselected non matched truth reco Bbb-Btautau info events: " << preselected_bbtautau_non_matched_truth_reco_info << endl;

  int sum_BB_preselected = overlap_matched_preselected_bbtautau_events+preselected_bbtautau_non_matched+preselected_bbtautau_non_matched_truth_reco_info;
  int sum_BB_truth_reco = overlap_matched_preselected_bbtautau_events+matched_bbtautau_non_preselected+matched_bbtautau_non_preselected_info;
  if(sum_BB_truth_reco!=matched_bbtautau_events || sum_BB_preselected!=matched_preselected_bbtautau_events){
    outFile << "The sum of matched events or preselected events is not the same" << endl;
  }
  if( TP_Bbb+FN_Bbb != matched_bb_events ){
    outFile << "The sum of TP and FN for boosted bb is not the same result for matched bb" << endl;
    outFile << "\t TP = " << TP_Bbb << endl;
    outFile << "\t FN = " << FN_Bbb << endl;
    outFile << "\t FP = " << FP_Bbb << endl; 
    outFile << "\t TN = " << TN_Bbb << endl;
    outFile << "\t matched bb events = " << matched_bb_events << endl;
  }
  if( TP_Btautau+FN_Btautau != matched_tautau_events ){
    outFile << "The sum of TP and FN for boosted tautau is not the same result for matched tautau" << endl;
    outFile << "\t TP = " << TP_Btautau << endl;
    outFile << "\t FN = " << FN_Btautau << endl;
    outFile << "\t FP = " << FP_Btautau << endl; 
    outFile << "\t TN = " << TN_Btautau << endl;
    outFile << "\t matched tautau events = " << matched_tautau_events << endl;
  }
  if( TP_BbbBtautau+FN_BbbBtautau != matched_bbtautau_events ){
    outFile << "The sum of TP and FN for boosted BbbBtautau is not the same result for matched BbbBtautau" << endl;
    outFile << "\t TP = " << TP_BbbBtautau << endl;
    outFile << "\t FN = " << FN_BbbBtautau << endl;
    outFile << "\t FP = " << FP_BbbBtautau << endl; 
    outFile << "\t TN = " << TN_BbbBtautau << endl;
    outFile << "\t matched bbtautau events = " << matched_bbtautau_events << endl;
  }
  if( TP_Bbb+FP_Bbb != matched_preselected_bb_events-wrong_matched_preselected_Bbb){
    outFile << "The sum of TP and FP for boosted bb is not the same result for preselected bb events" << endl;
    outFile << "\t TP = " << TP_Bbb << endl;
    outFile << "\t FP = " << FP_Bbb << endl;
    outFile << "\t TN = " << TN_Bbb << endl;
    outFile << "\t FN = " << FN_Bbb << endl;
    outFile << "\t correct matched preselected bb events = " << matched_preselected_bb_events-wrong_matched_preselected_Bbb << endl;
  }
  if( TP_Btautau+FP_Btautau != matched_preselected_tautau_events-wrong_matched_preselected_Btautau){
    outFile << "The sum of TP and FP for boosted tautau is not the same result for preselected tautau events" << endl;
    outFile << "\t TP = " << TP_Btautau << endl;
    outFile << "\t FP = " << FP_Btautau << endl;
    outFile << "\t TN = " << TN_Btautau << endl;
    outFile << "\t FN = " << FN_Btautau << endl;
    outFile << "\t correct matched preselected tautau events = " << matched_preselected_tautau_events-wrong_matched_preselected_Btautau << endl;
  }
  if( TP_BbbBtautau+FP_BbbBtautau != matched_preselected_bbtautau_events-wrong_matched_preselected_BbbBtautau){
    outFile << "The sum of TP and FP for boosted BbbBtautau is not the same result for preselected bbtautau events" << endl;
    outFile << "\t TP = " << TP_BbbBtautau << endl;
    outFile << "\t FP = " << FP_BbbBtautau << endl;
    outFile << "\t TN = " << TN_BbbBtautau << endl;
    outFile << "\t FN = " << FN_BbbBtautau << endl;
    outFile << "\t correct matched preselected bbtautau events = " << matched_preselected_bbtautau_events-wrong_matched_preselected_BbbBtautau << endl;
  }
  
  outFile << "---------------------------" << endl;

  outFile << "Preselected truth-reco percentages Bbb:" << endl;
  outFile << "Number of matched truth-reco Bbb events: " << matched_bb_events << "(" << 100.0*matched_bb_events/nentries << "%)" << endl;
  outFile << "Number of matched preselected Bbb events: " << matched_preselected_bb_events << "(" << 100.0*matched_preselected_bb_events/nentries << "%)" << endl;
  outFile << "Overlap of truth-reco and preselected Bbb events: " << overlap_matched_preselected_bb_events << endl;
  outFile << "Number of matched truth-reco non preselected Bbb events: " << matched_bb_non_preselected << endl;
  outFile << "Number of matched truth-reco non preselected Bbb info events: " << matched_bb_non_preselected_info << endl;
  outFile << "Number of preselected non matched truth reco Bbb events: " << preselected_bb_non_matched << endl;
  outFile << "Number of preselected non matched truth reco Bbb info events: " << preselected_bb_non_matched_truth_reco_info << endl;

  int sum_Bbb_preselected = overlap_matched_preselected_bb_events+preselected_bb_non_matched+preselected_bb_non_matched_truth_reco_info;
  int sum_Bbb_truth_reco = overlap_matched_preselected_bb_events+matched_bb_non_preselected+matched_bb_non_preselected_info;
  if(sum_Bbb_truth_reco!=matched_bb_events || sum_Bbb_preselected!=matched_preselected_bb_events){
    outFile << "The sum of matched bb events or preselected bb events is not the same" << endl;
  }
  
  outFile << "---------------------------" << endl;

  outFile << "Preselected truth-reco percentages Btautau:" << endl;
  outFile << "Number of matched truth-reco Btautau events: " << matched_tautau_events << "(" << 100.0*matched_tautau_events/nentries << "%)" << endl;
  outFile << "Number of matched preselected Btautau events: " << matched_preselected_tautau_events << "(" << 100.0*matched_preselected_tautau_events/nentries << "%)" << endl;
  outFile << "Overlap of truth-reco and preselected Btautau events: " << overlap_matched_preselected_tautau_events << endl;
  outFile << "Number of matched truth-reco non preselected Btautau events: " << matched_tautau_non_preselected << endl;
  outFile << "Number of matched truth-reco non preselected Btautau info events: " << matched_tautau_non_preselected_info << endl;
  outFile << "Number of preselected non matched truth reco Btautau events: " << preselected_tautau_non_matched << endl;
  outFile << "Number of preselected non matched truth reco Btautau info events: " << preselected_tautau_non_matched_truth_reco_info << endl;

  int sum_Btautau_preselected = overlap_matched_preselected_tautau_events+preselected_tautau_non_matched+preselected_tautau_non_matched_truth_reco_info;
  int sum_Btautau_truth_reco = overlap_matched_preselected_tautau_events+matched_tautau_non_preselected+matched_tautau_non_preselected_info;
  if(sum_Btautau_truth_reco!=matched_tautau_events || sum_Btautau_preselected!=matched_preselected_tautau_events){
    outFile << "The sum of matched tautau events or preselected tautau events is not the same" << endl;
  }
  
  outFile << "---------------------------" << endl;
  
  outFile.close();
  
  //****************************************************
  //Apply underflow and overflow to specific histograms distributions
  //****************************************************
  
  fix_underflow_overflow(hist_matched_recojet_bb_ak10_ECF1);
  fix_underflow_overflow(hist_non_matched_recojet_bb_ak10_ECF1);
  
  fix_underflow_overflow(hist_matched_recojet_bb_ak10_ECF2);
  fix_underflow_overflow(hist_non_matched_recojet_bb_ak10_ECF2);
  
  fix_underflow_overflow(hist_matched_recojet_bb_ak10_ECF3);
  fix_underflow_overflow(hist_non_matched_recojet_bb_ak10_ECF3);
  
  fix_underflow_overflow(hist_matched_recojet_bb_ak10_Split12);
  fix_underflow_overflow(hist_non_matched_recojet_bb_ak10_Split12);
  
  fix_underflow_overflow(hist_matched_recojet_bb_ak10_Split23);
  fix_underflow_overflow(hist_non_matched_recojet_bb_ak10_Split23);

  fix_underflow_overflow(hist_boosted_preselected_j12_m);
  fix_underflow_overflow(hist_boosted_preselected_j12_pt);
  fix_underflow_overflow(hist_boosted_preselected_j12_deta);
  fix_underflow_overflow(hist_boosted_preselected_j12_dphi);
  fix_underflow_overflow(hist_boosted_preselected_j12_dR);

  hist_boosted_cutflow_small_jets->SetBinContent(1, 100.0*matched_preselected_bbtautau_events/matched_preselected_bbtautau_events);
  hist_boosted_cutflow_small_jets->SetBinContent(2, 100.0*overlap_jj_selection_methods/matched_preselected_bbtautau_events);
  hist_boosted_cutflow_small_jets->SetBinContent(3, 100.0*eta_smalljets_cutflow/matched_preselected_bbtautau_events);
  hist_boosted_cutflow_small_jets->SetBinContent(4, 100.0*minpt_smalljets_cutflow/matched_preselected_bbtautau_events);
  hist_boosted_cutflow_small_jets->SetBinContent(5, 100.0*min_mjj_smalljets_cutflow/matched_preselected_bbtautau_events);
  hist_boosted_cutflow_small_jets->SetBinContent(6, 100.0*min_dR_smalljets_cutflow/matched_preselected_bbtautau_events);
  hist_boosted_cutflow_small_jets->SetBinContent(7, 100.0*all_cuts_applied_cutflow/matched_preselected_bbtautau_events);

  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(1, "Total Events");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(2, "pT same sel");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(3, "eta op. sign");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(4, "min pT > 30 GeV");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(5, "min mjj > 500 GeV");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(6, "dR > 5");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(7, "all cuts ap.");
  hist_boosted_cutflow_small_jets->GetXaxis()->SetBinLabel(8, "BDT cut > 0.8");

  //****************************************************
  //Save Histograms in the output root file
  //****************************************************
  
  outFile_root->cd();
  
  write_histograms();
  
  outFile_root->Write();
  
  //print_stat(nentries);
  
  inFile_root->Close();
  outFile_root->Close();
  
  auto end = chrono::steady_clock::now();
  auto elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();
  auto time_in_min = elapsed/60.;
  cout << "Time taken: " << time_in_min << " min" << endl;
  
}
