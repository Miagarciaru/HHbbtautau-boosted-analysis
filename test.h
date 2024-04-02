#include "declaration_of_functions.h"

// *************************************
// Declaration of the functions declared below (test)
// *************************************

void verification_no_b_tau_in_same_recojet(bool &b_tau_recojet, int &count_events);
void verification_idx_truth_matched_objects(bool &no_idx_for_non_matched_objects, int &count_events);
void correct_match_truth_leading_subleading_jets(bool &correct_match_pt, int &count_events);
void no_match_for_no_correct_truth_children_size(bool &no_match_for_no_correct_size, int &count_events);
void truth_children_size(bool &truth_childrenH1_size, bool &truth_childrenH2_size, int &count_events);
void truth_childrenH1_sum_types(bool &sum_type_truth_objectsH1, int &count_events);
void truth_childrenH2_sum_types(bool &sum_type_truth_objectsH2, int &count_events);


// void truth_matching_reco_objects_asserts(int ii, int &count_b_tau_matched);


// *************************************
// Definition of the functions declared above
// *************************************

void verification_no_b_tau_in_same_recojet(bool &b_tau_recojet, int &count_events){

  if( (truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2) && (recojet_antikt10UFO_NOSYS_pt->size() > 0) ){
    if( (idx_b1truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) ){
      if(class_event != -1){
	b_tau_recojet = false;
	count_events += 1;
      }
    }
  }
}

void verification_idx_truth_matched_objects(bool &no_idx_for_non_matched_objects, int &count_events){

  if( (truth_children_fromH1_pdgId->size() < 2) || (truth_children_fromH2_pdgId->size() < 2) ){
    if( (idx_b1truth_recoak10_dRmin != -1) || (idx_b2truth_recoak10_dRmin != -1) || (idx_tau1truth_recoak10_dRmin != -1) || (idx_tau2truth_recoak10_dRmin != -1) ){
      no_idx_for_non_matched_objects = false;
      count_events += 1;
      cout << "Zero truth children with matched objects: sizeH1c- sizeH2c- idxb1 - idxb2 - idxtau1 - idxtau2: " << endl;
      cout << truth_children_fromH1_pdgId->size() << "\t" << truth_children_fromH2_pdgId->size() << "\t" << idx_b1truth_recoak10_dRmin << "\t" << idx_b2truth_recoak10_dRmin << "\t" << idx_tau1truth_recoak10_dRmin << "\t" << idx_tau2truth_recoak10_dRmin << endl;
    }
  }
}

void correct_match_truth_leading_subleading_jets(bool &correct_match_pt, int &count_events){

  if( (truth_children_fromH1_pdgId->size() >= 2) || (truth_children_fromH2_pdgId->size() >= 2) ){
    if( (truth_b1_pt < truth_b2_pt) || (truth_tau1_pt < truth_tau2_pt) ){
      correct_match_pt = false;
      count_events += 1;
    }
  }
}

void no_match_for_no_correct_truth_children_size(bool &no_match_for_no_correct_size, int &count_events){

  bool truthb1_match = true;
  bool truthb2_match = true;
  bool truthtau1_match = true;
  bool truthtau2_match = true;
  
  if((truth_children_fromH1_pdgId->size() < 2) || (truth_children_fromH2_pdgId->size() < 2)){
    if( (truth_b1_pt != -99) || (truth_b1_eta != -99) || (truth_b1_phi != -99) || (truth_b1_m != -99) ){
      truthb1_match = false;
    }
  }
  
  if((truth_children_fromH1_pdgId->size() < 2) || (truth_children_fromH2_pdgId->size() < 2)){
    if( (truth_b2_pt != -99) || (truth_b2_eta != -99) || (truth_b2_phi != -99) || (truth_b2_m != -99) ){
      truthb2_match = false;
    }
  }

  if((truth_children_fromH1_pdgId->size() < 2) || (truth_children_fromH2_pdgId->size() < 2)){
    if( (truth_tau1_pt != -99) || (truth_tau1_eta != -99) || (truth_tau1_phi != -99) || (truth_tau1_m != -99) ){
      truthtau1_match = false;
    }
  }

  if((truth_children_fromH1_pdgId->size() < 2) || (truth_children_fromH2_pdgId->size() < 2)){
    if( (truth_tau2_pt != -99) || (truth_tau2_eta != -99) || (truth_tau2_phi != -99) || (truth_tau2_m != -99) ){
      truthtau2_match = false;
    }
  }

  if( (truthb1_match == false) || (truthb2_match == false) || (truthtau1_match == false) || (truthtau2_match == false) ){
    no_match_for_no_correct_size = false;
    count_events += 1;
  }
}

void truth_children_size(bool &truth_childrenH1_size, bool &truth_childrenH2_size, int &count_events){

  // Print those vectors from the truth_childrenH1/H2_pdgID that has a different size of two elements
  if((truth_children_fromH1_pdgId->size() != 2)){
    truth_childrenH1_size = false;
    count_events+=1;
  }
  if((truth_children_fromH2_pdgId->size() != 2)){
    truth_childrenH2_size = false;
    count_events+=1;
  }
}

void truth_childrenH1_sum_types(bool &sum_type_truth_objectsH1, int &count_events){

  // Verify if the two objects in the truth_children_H1/H2 are a particle and its antiparticle (sum of the types should be equal to zero)

  int sum_abs_objects_type = 0;
  if( (truth_children_fromH1_pdgId->size() == 2) ){
    sum_abs_objects_type = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1));
  }

  if( (sum_abs_objects_type != 10) &&  (sum_abs_objects_type != 30) ){
    sum_type_truth_objectsH1 = false;
    count_events += 1;
  }
}

void truth_childrenH2_sum_types(bool &sum_type_truth_objectsH2, int &count_events){

  // Verify if the two objects in the truth_children_H1/H2 are a particle and its antiparticle (sum of the types should be equal to zero)

  int sum_abs_objects_type = 0;
  if( (truth_children_fromH2_pdgId->size() == 2) ){
    sum_abs_objects_type = TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
  }

  if( (sum_abs_objects_type != 10) &&  (sum_abs_objects_type != 30) ){
    sum_type_truth_objectsH2 = false;
    count_events +=1 ;
  }
}


/*
void truth_matching_reco_objects_asserts(int ii, int &count_b_tau_matched){
  
  if ( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){
    
    if( (idx_b1truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) ){
      cout << "A b jet and a tau jet were matched to the same reconstructed jet" << endl;
      cout << ii << "\t idx for b1, b2, tau1 and tau2: " << "\t" << idx_b1truth_recoak10_dRmin << "\t" << idx_b2truth_recoak10_dRmin << "\t" << idx_tau1truth_recoak10_dRmin << "\t" << idx_tau2truth_recoak10_dRmin << endl;
      cout << ii << "\t dRmin for b1, b2, tau1 and tau2: " << "\t" << dR_min_b1truth_recoak10_fatjet << "\t" << dR_min_b2truth_recoak10_fatjet << "\t" << dR_min_tau1truth_recoak10_fatjet << "\t" << dR_min_tau2truth_recoak10_fatjet << endl;

      count_b_tau_matched += 1;
    }
  }
  

  if ( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) && (count_b_tau_matched < 15) ){

    if( (idx_b1truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) ){
      count_b_tau_matched += 1;
      cout << "A b jet and a tau jet were matched to the same fat jet j(b, tau): " << endl;
      cout << ii << "\t idx for b1, b2, tau1 and tau2: " << "\t" << idx_b1truth_recoak10_dRmin << "\t" << idx_b2truth_recoak10_dRmin << "\t" << idx_tau1truth_recoak10_dRmin << "\t" << idx_tau2truth_recoak10_dRmin << endl;
      cout << ii << "\t truth_boosted_bb - truth_resolved_bb - truth_boosted_tautau - truth_resolved_tautau - class event: " << endl;
      cout << ii << ": \t" << truth_boosted_bb << "\t" << truth_resolved_bb << "\t" << truth_boosted_tautau << "\t" << truth_resolved_tautau << "\t" << class_event << endl;
    }
  }

  if(ii%5000 == 0){
    cout << "Clases for the event " << ii << endl;
    cout << ii << "\t idx for b1, b2, tau1 and tau2: " << "\t" << idx_b1truth_recoak10_dRmin << "\t" << idx_b2truth_recoak10_dRmin << "\t" << idx_tau1truth_recoak10_dRmin << "\t" << idx_tau2truth_recoak10_dRmin << endl;
    cout << ii << "\t truth_boosted_bb - truth_resolved_bb - truth_boosted_tautau - truth_resolved_tautau - class event: " << endl;
    cout << ii << ": \t" << truth_boosted_bb << "\t" << truth_resolved_bb << "\t" << truth_boosted_tautau << "\t" << truth_resolved_tautau << "\t" << class_event << endl;
  }
}
*/
