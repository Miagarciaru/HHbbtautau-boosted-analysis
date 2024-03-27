#include "study_substructure_jets.h"

void study_substructure_jets(){
  

  //print_list_of_branches(inTree);

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
  float sum = 0;

  for(int ii = 0; ii < nentries; ii++){

    nbytes = inTree->GetEntry(ii);
    if((truth_children_fromH1_pdgId->size() != 2) || (truth_children_fromH2_pdgId->size() != 2)){
      if(truth_children_fromH1_pdgId->size() != 2){
        cout << ii << "\t H1 children: "  << truth_children_fromH1_pdgId->size() << endl; 
      }
      if(truth_children_fromH2_pdgId->size() != 2){
        cout << ii << "\t H2 children: "  << truth_children_fromH2_pdgId->size() << endl; 
      }
    }
    
    int sum_objects_type_H1 = 0;
    if(truth_children_fromH1_pdgId->size() == 2){
      sum_objects_type_H1 = truth_children_fromH1_pdgId->at(0) + truth_children_fromH1_pdgId->at(1);
      if(sum_objects_type_H1 != 0){
	cout << "H1 sum type \t" << truth_children_fromH1_pdgId->at(0) << "\t" << truth_children_fromH1_pdgId->at(1) << endl;
      }
      /*
      if(truth_children_fromH1_pt->at(0) <= truth_children_fromH1_pt->at(1)){
	cout << "The jet at 0 has a lower pT than the jet at 1 for H1" << endl;
	}*/
    }
 
    int sum_objects_type_H2 = 0;
    if(truth_children_fromH2_pdgId->size() == 2){
      sum_objects_type_H2 = truth_children_fromH2_pdgId->at(0) + truth_children_fromH2_pdgId->at(1);
      if(sum_objects_type_H2 != 0){
	cout << "H2 sum type \t"<< truth_children_fromH2_pdgId->at(0) << "\t" << truth_children_fromH2_pdgId->at(1) << endl;
      }
      /*
      if(truth_children_fromH2_pt->at(0) <= truth_children_fromH2_pt->at(1)){
	cout << "The jet at 0 has a lower pT than the jet at 1 for H2" << endl;
	}*/
    }

    int sum_objects_type = 0;
    if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){
      sum_objects_type = truth_children_fromH1_pdgId->at(0) + truth_children_fromH1_pdgId->at(1) + truth_children_fromH2_pdgId->at(0) + truth_children_fromH2_pdgId->at(1);
      if(sum_objects_type != 0){
	cout << "H1 plus H2 sum type \t" << truth_children_fromH1_pdgId->at(0) << "\t" << truth_children_fromH1_pdgId->at(1) << "\t" << truth_children_fromH2_pdgId->at(0) << "\t" << truth_children_fromH2_pdgId->at(1) << endl;
      }
    }

    int sum_abs_objects_type = 0;
    if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){
      sum_abs_objects_type = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1)) + TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
      if(sum_abs_objects_type != 40){
	cout << "H1 plus H2 abs sum type \t" << truth_children_fromH1_pdgId->at(0) << "\t" << truth_children_fromH1_pdgId->at(1) << "\t" << truth_children_fromH2_pdgId->at(0) << "\t" << truth_children_fromH2_pdgId->at(1) << endl;
      }
    }
    
  }

  int abs_sum_type_children = 0;
  
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    
    if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){
      random_function(abs_sum_type_children);
    }
    if((truth_children_fromH1_pdgId->size() != 2) || (truth_children_fromH2_pdgId->size() != 2)){
      abs_sum_type_children = -99;
    }
    if(ii%5000 == 0){
      cout << ii << "\t  Abs sum of type: " << abs_sum_type_children << "\t" << truth_b1_pt << "\t" << truth_b2_pt << "\t" << truth_tau1_pt << "\t" << truth_tau2_pt << "\t" << truth_b1_m << "\t" << truth_b2_m << "\t" << truth_tau1_m << "\t" << truth_tau2_m << endl;
    }
    if(abs_sum_type_children < 0){
      cout << ii << "\t  Abs sum of type: " << abs_sum_type_children << "\t" << truth_b1_pt << "\t" << truth_b2_pt << "\t" << truth_tau1_pt << "\t" << truth_tau2_pt << "\t" << truth_b1_m << "\t" << truth_b2_m << "\t" << truth_tau1_m << "\t" << truth_tau2_m << endl;
    }
  }
  
  inFile->Close();
  
}
