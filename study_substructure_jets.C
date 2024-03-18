#include "study_substructure_jets.h"

void study_substructure_jets(){

  // Path of the merged samples
  
  TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/outputfiles-easyjet-march7-2024/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_";
  TString path_boosted_sample=path+"boosted_config.root";
  TString path_resolved_sample=path+"resolved_config.root";

  // Open the input files and access to the trees

  TFile* boosted_inFile = TFile::Open(path_boosted_sample);
  TTree* boosted_inTree = (TTree*) boosted_inFile->Get("AnalysisMiniTree");

  TFile* resolved_inFile = TFile::Open("/afs/cern.ch/user/g/garciarm/HHbbtautau-easyjet-framework/run/output_mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_r13144_resolved_bypass_config.root");
  // TFile* resolved_inFile = TFile::Open(path_resolved_sample);
  TTree* resolved_inTree = (TTree*) resolved_inFile->Get("AnalysisMiniTree");

  // Print the names of the branches in the given tree
  
  // print_list_of_branches(boosted_inTree);
  // print_list_of_branches(resolved_inTree);
  
  // Find all the branches with the words tau and jets for the boosted config

  // find_branches_names(boosted_inTree, "boosted", "bbtt_H");

  find_branches_names(resolved_inTree, "resolved", "bbtt_H");
  //find_branches_names(resolved_inTree, "resolved", "passesOR");

  find_branches_names(resolved_inTree, "resolved", "Weight");
  find_branches_names(resolved_inTree, "resolved", "weight");
  
  // set_branch_address(boosted_inTree, resolved_inTree);
  
  Int_t entries = boosted_inTree->GetEntries();
  int b_nbytes=0;
  int r_nbytes=0;

  /*
  for(int ii = 0; ii < 50; ii++){
    b_nbytes = boosted_inTree->GetEntry(ii);
    r_nbytes = resolved_inTree->GetEntry(ii);
    cout << boosted_bbtt_H_vis_tautau_m << "\t" << resolved_bbtt_H_vis_tautau_m << endl; 
  }
  */

  //fill_histograms(boosted_inTree, resolved_inTree);
  /*
  plot_distributions(boosted_inTree, resolved_inTree, "tautau_m");
  plot_distributions(boosted_inTree, resolved_inTree, "bb_m");
  plot_distributions(boosted_inTree, resolved_inTree, "tautau_pT");
  plot_distributions(boosted_inTree, resolved_inTree, "bb_pT");
  */

  int b_entries = boosted_inTree->GetEntries();
  int r_entries = resolved_inTree->GetEntries();
  int boosted_mbb_neg_values = 0;
  int resolved_mbb_neg_values = 0;
  int boosted_bbpT_neg_values = 0;
  int resolved_bbpT_neg_values = 0;
  
  for(int ii=0; ii < b_entries; ii++){
    b_nbytes = boosted_inTree->GetEntry(ii);
    if(boosted_bbtt_H_bb_m < 0){
      boosted_mbb_neg_values += 1;
    }
    if(boosted_bbtt_H_bb_pt_NOSYS < 0){
      boosted_bbpT_neg_values += 1;
    }
  }

  for(int ii=0; ii < r_entries; ii++){
    r_nbytes = resolved_inTree->GetEntry(ii);
    if(resolved_bbtt_H_bb_m < 0){
      resolved_mbb_neg_values += 1;
    }
    if(resolved_bbtt_H_bb_pt_NOSYS < 0){
      resolved_bbpT_neg_values += 1;
    }
  }
  

  int tau_passesOR_count = 0;
  int recojet_antikt4_passesOR_count = 0;
  int counter = 0;
  int counter_2 = 0;

  /*
  for(int ii=0; ii < b_entries; ii++){
    b_nbytes = boosted_inTree->GetEntry(ii);
    if(boosted_tau_NOSYS_passesOR->size() > 0){
      cout << "tau_passesOR for boosted for " << ii << endl;
      for(int jj=0; jj < boosted_tau_NOSYS_passesOR->size(); jj++){
	cout << boosted_tau_NOSYS_passesOR->at(jj) << " - "; 
      }
      counter+=1;
      if(counter == 1000){
	break;
      }
    }
  }
  for(int ii=0; ii < b_entries; ii++){
    b_nbytes = boosted_inTree->GetEntry(ii);
    if(boosted_recojet_antikt4PFlow_NOSYS_passesOR->size() > 0){
      cout << "recojet_antikt4_passesOR boosted for " << ii << endl;
      for(int kk=0; kk < boosted_recojet_antikt4PFlow_NOSYS_passesOR->size(); kk++){
	cout << boosted_recojet_antikt4PFlow_NOSYS_passesOR->at(kk) << " - "; 
      }
      counter_2+=1;
      if(counter_2 == 1000){
	break;
      }
    }
  }
  */
  /*
  for(int ii=0; ii < 5; ii++){
    b_nbytes = boosted_inTree->GetEntry(ii);
    if(boosted_tau_NOSYS_passesOR->size() > 0){
      for(int jj=0; jj < boosted_tau_NOSYS_passesOR->size(); jj++){
	if((boosted_tau_NOSYS_passesOR->at(jj)==0) or (boosted_tau_NOSYS_passesOR->at(jj)==1)){
	  cout << "Entry: " << ii << endl;
	  cout << jj << "\t" << boosted_tau_NOSYS_passesOR->at(jj) << endl;
	}
      }
    }
  }
  */
  
  cout << "The number of entries for mbb that are negative for boosted and resolved cases are respectively:"  << endl;

  cout << boosted_mbb_neg_values << "\t" << resolved_mbb_neg_values << endl;
  
  cout << "The number of entries for bbpT that are negative for boosted and resolved cases are respectively:"  << endl;

  cout << boosted_bbpT_neg_values << "\t" << resolved_bbpT_neg_values << endl;

  //find_branches_names(boosted_inTree, "boosted", "OR");
  //find_branches_names(boosted_inTree, "boosted", "passesOR");
  
  find_branches_names(resolved_inTree, "resolved", "OR");
  find_branches_names(resolved_inTree, "resolved", "passesOR");

  // plot_distributions(boosted_inTree, resolved_inTree, "tau_passesOR");
  // plot_distributions(boosted_inTree, resolved_inTree, "recojet_antikt4_passesOR");
  
  // Close the files
  
  boosted_inFile->Close();
  resolved_inFile->Close(); 
}
