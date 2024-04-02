#include "declaration_of_variables.h"

// *************************************
// Declaration of functions
// *************************************

//void plot_distributions(TString name_plot);

void define_output_branches();
void define_classes();
void truth_and_fake_boosted_and_resolved_jets();
void truth_matching_reco_objects_asserts(int ii, int &count_b_tau_matched);
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m);
void plot_distributions(TString name_plot);
void truth_objects_asserts(int ii);
void random_function(int &sum_type_per_event);
void define_truth_tau_and_b_jets();
void fill_histograms();
void set_branch_address();
void print_list_of_branches(TTree* tree);

// *************************************
// Definition of the functions declared above
// *************************************

void define_output_branches(){

  outTree->Branch("truth_children_fromH1_pdgId", &truth_children_fromH1_pdgId);
  outTree->Branch("truth_children_fromH1_pt", &truth_children_fromH1_pt);
  outTree->Branch("truth_children_fromH1_eta", &truth_children_fromH1_eta);
  outTree->Branch("truth_children_fromH1_phi", &truth_children_fromH1_phi);
  outTree->Branch("truth_children_fromH1_m", &truth_children_fromH1_m);

  outTree->Branch("truth_children_fromH2_pdgId", &truth_children_fromH2_pdgId);
  outTree->Branch("truth_children_fromH2_pt", &truth_children_fromH2_pt);
  outTree->Branch("truth_children_fromH2_eta", &truth_children_fromH2_eta);
  outTree->Branch("truth_children_fromH2_phi", &truth_children_fromH2_phi);
  outTree->Branch("truth_children_fromH2_m", &truth_children_fromH2_m);

  outTree->Branch("truth_b1_pt", &truth_b1_pt);
  outTree->Branch("truth_b1_eta", &truth_b1_eta);
  outTree->Branch("truth_b1_phi", &truth_b1_phi);
  outTree->Branch("truth_b1_m", &truth_b1_m);

  outTree->Branch("truth_b2_pt", &truth_b2_pt);
  outTree->Branch("truth_b2_eta", &truth_b2_eta);
  outTree->Branch("truth_b2_phi", &truth_b2_phi);
  outTree->Branch("truth_b2_m", &truth_b2_m);

  outTree->Branch("truth_tau1_pt", &truth_tau1_pt);
  outTree->Branch("truth_tau1_eta", &truth_tau1_eta);
  outTree->Branch("truth_tau1_phi", &truth_tau1_phi);
  outTree->Branch("truth_tau1_m", &truth_tau1_m);
  
  outTree->Branch("truth_tau2_pt", &truth_tau2_pt);
  outTree->Branch("truth_tau2_eta", &truth_tau2_eta);
  outTree->Branch("truth_tau2_phi", &truth_tau2_phi);
  outTree->Branch("truth_tau2_m", &truth_tau2_m);

  outTree->Branch("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt);
  outTree->Branch("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta);
  outTree->Branch("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi);
  outTree->Branch("recojet_antikt10UFO_m", &recojet_antikt10UFO_m);
  
  outTree->Branch("idx_b1truth_recoak10_dRmin", &idx_b1truth_recoak10_dRmin);
  outTree->Branch("idx_b2truth_recoak10_dRmin", &idx_b2truth_recoak10_dRmin);
  outTree->Branch("idx_tau1truth_recoak10_dRmin", &idx_tau1truth_recoak10_dRmin);
  outTree->Branch("idx_tau2truth_recoak10_dRmin", &idx_tau2truth_recoak10_dRmin);

  outTree->Branch("dR_min_b1truth_recoak10_fatjet", &dR_min_b1truth_recoak10_fatjet);
  outTree->Branch("dR_min_b2truth_recoak10_fatjet", &dR_min_b2truth_recoak10_fatjet);
  outTree->Branch("dR_min_tau1truth_recoak10_fatjet", &dR_min_tau1truth_recoak10_fatjet);
  outTree->Branch("dR_min_tau2truth_recoak10_fatjet", &dR_min_tau2truth_recoak10_fatjet);

  outTree->Branch("class_event", &class_event);

  outTree->Branch("bbtt_H_vis_tautau_pt_NOSYS", &bbtt_H_vis_tautau_pt_NOSYS);
  outTree->Branch("bbtt_H_vis_tautau_m", &bbtt_H_vis_tautau_m);
  outTree->Branch("bbtt_H_bb_pt_NOSYS", &bbtt_H_bb_pt_NOSYS);
  outTree->Branch("bbtt_Jet_b1_pt_NOSYS", &bbtt_Jet_b1_pt_NOSYS);
  outTree->Branch("bbtt_Jet_b2_pt_NOSYS", &bbtt_Jet_b2_pt_NOSYS);
  outTree->Branch("bbtt_H_bb_m", &bbtt_H_bb_m);
  //outTree->Branch("generatorWeight_NOSYS", &generatorWeight_NOSYS);
  //inTree->Branch("tau_NOSYS_passesOR", &tau_NOSYS_passesOR);
  //outTree->Branch("recojet_antikt4PFlow_NOSYS_passesOR", &recojet_antikt4PFlow_NOSYS_passesOR);
  
}

void define_classes(){

  // class_event
  /*
  // Condition 1: To classify the events in the 4 classes, all the truth objects must have been matched to one recojet, i.e, all the truth
  // idx must be different to -1. If not, the class_event will be set to -1 (no belong to any of the 4 casses)

  // Condition 2: Those events where at least one b and one tau jets were matched to the same fat jet will be discarded because we
  // already know that this wouldn't be possible, so the class_event will be set to -1 (no belong to any of the 4 casses)
  
  // Condition 3: For boosted events, we need to ensure at leats two conditions: 1- The two truth objects (bb or tautau) must be matched to
  // the same fat jet and 2- the deltaR between these two truth objects must be less than 1. Thus, when we are considering the bb or tautau
  // truth jets, these criteria is going to tell us when the two jets are boosted.

  // Condition 4: For resolved events, we need to ensure that 1- the two truth objects (bb or tautau) have been matched to a different fat
  // jet and 2- the deltaR between these two truth objects are higher than 1.

  // Condition 4: Definition of the 4 classes:
  For R_bb R_tautau we setup 0
  For R_bb B_tautau we setup 1
  For B_bb R_tautau we setup 2
  For B_bb B_tautau we setup 3

  // Condition 5: Definition of the fake classes
  For fake R_bb R_tautau: Both of the two pairs (bb or tautau) must have a deltaR < 1, while being matched two different fat jets, i.e, 
  the two truth taus were matched to different fatjets, but they have a deltaR(tautau) < 1. The same for the two bb.
  For fake R_bb B_tautau: The R_bb must be correct, but the B_tautau don't. So here, the two taus must have been matched to the same fatjet
  while having a deltaR(tautau) > 1.
  For fake B_bb R_tautau: The R_tautau must be correct, but the B_bb don't. So here, the two bb must have been matched to the same fatjet
  while having a deltaR(bb) > 1.
  For fake B_bb B_tautau: Both of the two pairs (bb or tautau) must have a deltaR > 1, while being matched two the same fatjets, i.e, 
  the two truth taus were matched to the same fatjet, but they have a deltaR(tautau) > 1. The same for the two bb.
  For fakeR_bb R_tautau we setup 4
  For fakeR_bb B_tautau we setup 5
  For fakeB_bb R_tautau we setup 6
  For fakeB_bb B_tautau we setup 7
  */

  class_event = -1;

  truth_and_fake_boosted_and_resolved_jets();
  
  if( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){

    bool are_boosted_bb_matched = false;
    bool are_boosted_tautau_matched = false;

    if( idx_b1truth_recoak10_dRmin == idx_b2truth_recoak10_dRmin ){
      are_boosted_bb_matched = true;
    }
    if( idx_tau1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin ){
      are_boosted_tautau_matched = true;
    }

    // ************************************
    // For the boosted and resolved jets that are correctly identified
 
    // For the truth R_bb R_tautau class
    if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==false) && (truth_resolved_bb == 1) && (truth_resolved_tautau == 1) ){
      class_event = 0;
    }

    // For the truth R_bb B_tautau class
    if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==true) && (truth_resolved_bb == 1) && (truth_boosted_tautau == 1) ){
      class_event = 1;
    }

    // For the truth B_bb R_tautau class
    if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==false) && (truth_boosted_bb == 1) && (truth_resolved_tautau == 1) ){
      class_event = 2;
    }

    // For the truth B_bb B_tautau class
    if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==true) && (truth_boosted_bb == 1) && (truth_boosted_tautau == 1) ){
      class_event = 3;
    }

    // ************************************
    // For the boosted and resolved jets that are wronly identified
    
    // For the fake R_bb R_tautau class
    if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==false) && (truth_resolved_bb == 0) && (truth_resolved_tautau == 0) ){
      class_event = 4;
    }

    // For the fake R_bb B_tautau class: the R_bb must be correct, but the B_tautau don't
    if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==true) && (truth_resolved_bb == 1) && (truth_boosted_tautau == 0) ){
      class_event = 5;
    }

    // For the fake B_bb R_tautau class: the B_bb must be wrong and the R_tautau must be correct
    if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==false) && (truth_boosted_bb == 0) && (truth_resolved_tautau == 1) ){
      class_event = 6;
    }

    // For the fake B_bb B_tautau class: Both B_bb and B_tautau must be wrong
    if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==true) && (truth_boosted_bb == 0) && (truth_boosted_tautau == 0) ){
      class_event = 7;
    }
  }
}


void truth_and_fake_boosted_and_resolved_jets(){

  /*
    For a fake boosted jet, we need to ensure that the all the truth objects were matched to one fat jet, 2- the two objects were matched 
    to the same fatjet and have a deltaR > 1 
    
    For a fake resolved jet, we need to ensure that the all the truth objects were matched to one fat jet, 2- the two objects were matched 
    to different fatjets and have a deltaR < 1 
    
    The value -1 is for those events where any of the truth objects was not able to be matched. The 0 value is for a fake boosted or 
    resolved match, and 1 is for a correct boosted or truth match.
  */
  
  truth_boosted_bb = -1;
  truth_boosted_tautau = -1;
  truth_resolved_bb = -1;
  truth_resolved_tautau = -1;

  if( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){
    
    if( (idx_b1truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) ){
      return;
    }

    // After verifying that all the truth objects were matched, we set 0 as the default value for the classes, because we now know that
    // these events will be in one of the 8 possible classes (4 truth classes or 4 fake classes). So these values should be -1, which is
    // the default value to say these events are not classified into a class.
    
    truth_boosted_bb = 0;
    truth_boosted_tautau = 0;
    truth_resolved_bb = 0;
    truth_resolved_tautau = 0;
  
    // Checking if the events has boosted or resolved jets for the two b
    float dR_bb = 0;
    deltaR(dR_bb, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
    // Checking if the bb are boosted 
    if( idx_b1truth_recoak10_dRmin == idx_b2truth_recoak10_dRmin ){
      if(dR_bb < 1){
	truth_boosted_bb = 1;
      }
      if(dR_bb > 1){
	truth_boosted_bb = 0;
      }
    }
    // Checking if the bb are resolved
    if( idx_b1truth_recoak10_dRmin != idx_b2truth_recoak10_dRmin ){
      if(dR_bb > 1){
	truth_resolved_bb = 1;
      }
      if(dR_bb < 1){
	truth_resolved_bb = 0;
      }
    }
    // Checking if the events has boosted or resolved jets for the two taus
    float dR_tautau = 0;
    deltaR(dR_tautau, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
    // Checking if the tautau are boosted 
    if( idx_tau1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin ){
      if(dR_tautau < 1){
	truth_boosted_tautau = 1;
      }
      if(dR_tautau > 1){
	truth_boosted_tautau = 0;
      }
    }
    // Checking if the tautau are resolved
    if( idx_tau1truth_recoak10_dRmin != idx_tau2truth_recoak10_dRmin ){
      if(dR_tautau > 1){
	truth_resolved_tautau = 1;
      }
      if(dR_tautau < 1){
	truth_resolved_tautau = 0;
      }
    }
  }
}

void truth_matching_reco_objects_asserts(int ii, int &count_b_tau_matched){
  /*
  if ( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){
    
    if( (idx_b1truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau1truth_recoak10_dRmin) || (idx_b2truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin) ){
      cout << "A b jet and a tau jet were matched to the same reconstructed jet" << endl;
      cout << ii << "\t idx for b1, b2, tau1 and tau2: " << "\t" << idx_b1truth_recoak10_dRmin << "\t" << idx_b2truth_recoak10_dRmin << "\t" << idx_tau1truth_recoak10_dRmin << "\t" << idx_tau2truth_recoak10_dRmin << endl;
      cout << ii << "\t dRmin for b1, b2, tau1 and tau2: " << "\t" << dR_min_b1truth_recoak10_fatjet << "\t" << dR_min_b2truth_recoak10_fatjet << "\t" << dR_min_tau1truth_recoak10_fatjet << "\t" << dR_min_tau2truth_recoak10_fatjet << endl;

      count_b_tau_matched += 1;
    }
  }
  */

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


// This function give us the min deltaR between the truth_objects and the objects in the recojets_ak10UFO fat-jets
void compute_dR_min_index_fat_jets(){
  
  if(recojet_antikt10UFO_NOSYS_pt->size() > 0){
    compute_dR_min(idx_b1truth_recoak10_dRmin, dR_min_b1truth_recoak10_fatjet, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
    compute_dR_min(idx_b2truth_recoak10_dRmin, dR_min_b2truth_recoak10_fatjet, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
    compute_dR_min(idx_tau1truth_recoak10_dRmin, dR_min_tau1truth_recoak10_fatjet, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
    compute_dR_min(idx_tau2truth_recoak10_dRmin, dR_min_tau2truth_recoak10_fatjet, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
  }
  else{
    idx_b1truth_recoak10_dRmin = -1;
    dR_min_b1truth_recoak10_fatjet = -1;
    idx_b2truth_recoak10_dRmin = -1;
    dR_min_b2truth_recoak10_fatjet = -1;
    idx_tau1truth_recoak10_dRmin = -1;
    dR_min_tau1truth_recoak10_fatjet = -1;
    idx_tau2truth_recoak10_dRmin = -1;
    dR_min_tau2truth_recoak10_fatjet = -1;
  }
  
}

void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m){

  TLorentzVector jet1  = TLorentzVector();
  TLorentzVector jet2  = TLorentzVector();
      
  jet1.SetPtEtaPhiM(jet1_pt/1000., jet1_eta, jet1_phi, jet1_m/1000.);
  jet2.SetPtEtaPhiM(jet2_pt/1000., jet2_eta, jet2_phi, jet2_m/1000.);

  dR = jet1.DeltaR(jet2);
}


void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m){

  idx = -1;
  dR_min = 1;
  
  for(int ii = 0; ii < recojet_antikt10UFO_NOSYS_pt->size(); ii++){
    
    TLorentzVector truth_jet  = TLorentzVector();
    TLorentzVector reco_jet  = TLorentzVector();
    
    float reco_pt = recojet_antikt10UFO_NOSYS_pt->at(ii);
    float reco_eta = recojet_antikt10UFO_eta->at(ii);
    float reco_phi = recojet_antikt10UFO_phi->at(ii);
    float reco_m = recojet_antikt10UFO_m->at(ii);
    
    truth_jet.SetPtEtaPhiM(truth_pt/1000., truth_eta, truth_phi, truth_m/1000.);
    reco_jet.SetPtEtaPhiM(reco_pt/1000., reco_eta, reco_phi, reco_m/1000.);
    
    float deltaR_truth_recojet = truth_jet.DeltaR(reco_jet);
      
    if( (deltaR_truth_recojet < dR_min) && (deltaR_truth_recojet < 1) ){
      dR_min = deltaR_truth_recojet;
      idx = ii;
    }
  }
}


void truth_objects_asserts(int ii){

  // Print those vectors from the truth_childrenH1/H2_pdgID that has a different size of two elements
  if((truth_children_fromH1_pdgId->size() != 2) || (truth_children_fromH2_pdgId->size() != 2)){
    if(truth_children_fromH1_pdgId->size() != 2){
      cout << ii << "\t H1 children: "  << truth_children_fromH1_pdgId->size() << endl;
    }
    if(truth_children_fromH2_pdgId->size() != 2){
      cout << ii << "\t H2 children: "  << truth_children_fromH2_pdgId->size() << endl;
    }
  }

  // Verify if the two objects in the truth_children_H1/H2 are a particle and its antiparticle (sum of the types should be equal to zero)
  int sum_objects_type_H1 = 0;
  if(truth_children_fromH1_pdgId->size() == 2){
    sum_objects_type_H1 = truth_children_fromH1_pdgId->at(0) + truth_children_fromH1_pdgId->at(1);
    if(sum_objects_type_H1 != 0){
      cout << ii << "\t H1 sum type \t" << truth_children_fromH1_pdgId->at(0) << "\t" << truth_children_fromH1_pdgId->at(1) << endl;
    }
  }

  int sum_objects_type_H2 = 0;
  if(truth_children_fromH2_pdgId->size() == 2){
    sum_objects_type_H2 = truth_children_fromH2_pdgId->at(0) + truth_children_fromH2_pdgId->at(1);
    if(sum_objects_type_H2 != 0){
      cout << ii << "\t H2 sum type \t"<< truth_children_fromH2_pdgId->at(0) << "\t" << truth_children_fromH2_pdgId->at(1) << endl;
    }
  }
  
  // Verify that the abs sum of the four objects coming from the truth_children H1/H2 is 40 for possible combinations (b=5, ~b=-5, tau=15, ~tau=-15), so it is useful to detrmine that we really have two bs and two taus as the decays product
  int sum_abs_objects_type = 0;
  if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){
    sum_abs_objects_type = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1)) + TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
    if(sum_abs_objects_type != 40){
      cout << ii << "\t H1 plus H2 abs sum type \t" << truth_children_fromH1_pdgId->at(0) << "\t" << truth_children_fromH1_pdgId->at(1) << "\t" << truth_children_fromH2_pdgId->at(0) << "\t" << truth_children_fromH2_pdgId->at(1) << endl;
    }
  } 

  // Print the abs sum of the types for the four objects, as well as their pTs and masses
  int abs_sum_type_children = 0;

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


void random_function(int &sum_type_per_event){

  sum_type_per_event = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1)) + TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
  
}

void define_truth_tau_and_b_jets(){

  if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){

    int sum_type_H1 = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1));
    int sum_type_H2 = TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));

    bool is_H1_bb = false;
    bool is_H2_bb = false;

    if(sum_type_H1 == 10){ is_H1_bb = true;} 
    if(sum_type_H1 == 30){ is_H2_bb = true;}

    // Here we assume that all the jets are listed from the highest pT to the lowest pT
    int index_b1 = 0;
    int index_b2 = 1;
    int index_tau1 = 0;
    int index_tau2 = 1;
      
    // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1_bb scenario
    if(is_H1_bb){
      if(truth_children_fromH1_pt->at(0) < truth_children_fromH1_pt->at(1)){
	index_b1 = 1;
	index_b2 = 0;
      } 
      if(truth_children_fromH2_pt->at(0) < truth_children_fromH2_pt->at(1)){
	index_tau1 = 1;
	index_tau2 = 0;
      }
      
      truth_b1_pt = truth_children_fromH1_pt->at(index_b1);
      truth_b1_eta = truth_children_fromH1_eta->at(index_b1);
      truth_b1_phi = truth_children_fromH1_phi->at(index_b1);
      truth_b1_m = truth_children_fromH1_m->at(index_b1);

      truth_b2_pt = truth_children_fromH1_pt->at(index_b2);
      truth_b2_eta = truth_children_fromH1_eta->at(index_b2);
      truth_b2_phi = truth_children_fromH1_phi->at(index_b2);
      truth_b2_m = truth_children_fromH1_m->at(index_b2);

      truth_tau1_pt = truth_children_fromH2_pt->at(index_tau1);
      truth_tau1_eta = truth_children_fromH2_eta->at(index_tau1);
      truth_tau1_phi = truth_children_fromH2_phi->at(index_tau1);
      truth_tau1_m = truth_children_fromH2_m->at(index_tau1);	
      
      truth_tau2_pt = truth_children_fromH2_pt->at(index_tau2);
      truth_tau2_eta = truth_children_fromH2_eta->at(index_tau2);
      truth_tau2_phi = truth_children_fromH2_phi->at(index_tau2);
      truth_tau2_m = truth_children_fromH2_m->at(index_tau2);	
      
    }

    // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H2_bb scenario
    if(is_H2_bb){
      if(truth_children_fromH2_pt->at(0) < truth_children_fromH2_pt->at(1)){
	index_b1 = 1;
	index_b2 = 0;
      } 
      if(truth_children_fromH1_pt->at(0) < truth_children_fromH1_pt->at(1)){
	index_tau1 = 1;
	index_tau2 = 0;
      }
	
      truth_b1_pt = truth_children_fromH2_pt->at(index_b1);
      truth_b1_eta = truth_children_fromH2_eta->at(index_b1);
      truth_b1_phi = truth_children_fromH2_phi->at(index_b1);
      truth_b1_m = truth_children_fromH2_m->at(index_b1);
      
      truth_b2_pt = truth_children_fromH2_pt->at(index_b2);
      truth_b2_eta = truth_children_fromH2_eta->at(index_b2);
      truth_b2_phi = truth_children_fromH2_phi->at(index_b2);
      truth_b2_m = truth_children_fromH2_m->at(index_b2);
      
      truth_tau1_pt = truth_children_fromH1_pt->at(index_tau1);
      truth_tau1_eta = truth_children_fromH1_eta->at(index_tau1);
      truth_tau1_phi = truth_children_fromH1_phi->at(index_tau1);
      truth_tau1_m = truth_children_fromH1_m->at(index_tau1);	
      
      truth_tau2_pt = truth_children_fromH1_pt->at(index_tau2);
      truth_tau2_eta = truth_children_fromH1_eta->at(index_tau2);
      truth_tau2_phi = truth_children_fromH1_phi->at(index_tau2);
      truth_tau2_m = truth_children_fromH1_m->at(index_tau2);	
    }	
  }
  else{
    truth_b1_pt = -99;
    truth_b1_eta = -99;
    truth_b1_phi = -99;
    truth_b1_m = -99;
    
    truth_b2_pt = -99;
    truth_b2_eta = -99;
    truth_b2_phi = -99;
    truth_b2_m = -99;

    truth_tau1_pt = -99;
    truth_tau1_eta = -99;
    truth_tau1_phi = -99;
    truth_tau1_m = -99;
    
    truth_tau2_pt = -99;
    truth_tau2_eta = -99;
    truth_tau2_phi = -99;
    truth_tau2_m = -99;
  }
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved

void plot_distributions(TString name_plot){
  /*
  TLegend *leg = new TLegend(0.7, 0.75, 0.85, 0.85);
  TH1F *hist_boosted = new TH1F();
  TH1F *hist_resolved = new TH1F();
  TString name_image = "plots/";
  name_image+=name_plot+".png";
  
  if(name_plot=="tautau_m"){
    hist_boosted = hist_mH_tautau_boosted;
    hist_resolved = hist_mH_tautau_resolved;
  }

  hist_boosted->SetStats(0);
  hist_boosted->SetFillStyle(3001);
  hist_boosted->SetFillColorAlpha(kBlue, 0.45);
  hist_boosted->SetLineColor(4);

  */

  TString name_image="plots/"+name_plot+".png";
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);
  TH1F *hist = new TH1F();

  if(name_plot == "truth_b1_m"){
    hist = hist_truth_b1_m;
  }
  if(name_plot == "truth_b2_m"){
    hist = hist_truth_b2_m;
  }
  if(name_plot == "truth_b1_plus_b2_m"){
    hist = hist_truth_b1_plus_b2_m;
  }
  if(name_plot == "recojet_bb_m"){
    hist = hist_recojet_bb_m;
  }
  if(name_plot == "recojet_tautau_m"){
    hist = hist_recojet_tautau_m;
  }
  if(name_plot == "match_recojets_pt"){
    hist = hist_matched_recojet_pt;
  }
  if(name_plot == "match_recojets_eta"){
    hist = hist_matched_recojet_eta;
  }
  if(name_plot == "non_match_recojets_pt"){
    hist = hist_non_matched_recojet_pt;
  }
  if(name_plot == "non_match_recojets_eta"){
    hist = hist_non_matched_recojet_eta;
  }

  
  hist->Draw();
  
  /*
  leg->AddEntry(hist_boosted, "boosted", "l");
  leg->AddEntry(hist_resolved,"resolved","l");
  leg->SetBorderSize();
  leg->Draw();
  */
  
  can->Draw();
  can->Print(name_image);
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void fill_histograms(){

  Int_t nentries = inTree->GetEntries();
  int nbytes = 0;

  float sum = 0;
    
  for(int ii = 0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);
    if(truth_children_fromH1_pdgId->size() == 2){
      if((TMath::Abs(truth_children_fromH1_pdgId->at(0)) == 5) && (TMath::Abs(truth_children_fromH1_pdgId->at(1)) == 5)){
	sum = truth_children_fromH1_m->at(0) + truth_children_fromH1_m->at(1);
	hist_truth_b1_plus_b2_m->Fill(sum);
	hist_truth_b1_m->Fill(truth_children_fromH1_m->at(0));
	hist_truth_b2_m->Fill(truth_children_fromH1_m->at(1));
	/*
	if(ii%100 == 0){
	  cout << sum << endl;
	  }*/
      }
    }
  }
}


// This function saves the branches info for a given tree in the variables defined above
void set_branch_address(){

  inTree->SetBranchAddress("truth_children_fromH1_pdgId", &truth_children_fromH1_pdgId, &b_truth_children_fromH1_pdgId);
  inTree->SetBranchAddress("truth_children_fromH1_pt", &truth_children_fromH1_pt, &b_truth_children_fromH1_pt);
  inTree->SetBranchAddress("truth_children_fromH1_eta", &truth_children_fromH1_eta, &b_truth_children_fromH1_eta);
  inTree->SetBranchAddress("truth_children_fromH1_phi", &truth_children_fromH1_phi, &b_truth_children_fromH1_phi);
  inTree->SetBranchAddress("truth_children_fromH1_m", &truth_children_fromH1_m, &b_truth_children_fromH1_m);

  inTree->SetBranchAddress("truth_children_fromH2_pdgId", &truth_children_fromH2_pdgId, &b_truth_children_fromH2_pdgId);
  inTree->SetBranchAddress("truth_children_fromH2_pt", &truth_children_fromH2_pt, &b_truth_children_fromH2_pt);
  inTree->SetBranchAddress("truth_children_fromH2_eta", &truth_children_fromH2_eta, &b_truth_children_fromH2_eta);
  inTree->SetBranchAddress("truth_children_fromH2_phi", &truth_children_fromH2_phi, &b_truth_children_fromH2_phi);
  inTree->SetBranchAddress("truth_children_fromH2_m", &truth_children_fromH2_m, &b_truth_children_fromH2_m);

  /*
  inTree->SetBranchAddress("truth_b1_pt", &truth_b1_pt, b_truth_b1_pt);
  inTree->SetBranchAddress("truth_b1_eta", &truth_b1_eta, b_truth_b1_eta);
  inTree->SetBranchAddress("truth_b1_phi", &truth_b1_phi, b_truth_b1_phi);
  inTree->SetBranchAddress("truth_b1_m", &truth_b1_m, b_truth_b1_m);

  inTree->SetBranchAddress("truth_b2_pt", &truth_b2_pt, b_truth_b2_pt);
  inTree->SetBranchAddress("truth_b2_eta", &truth_b2_eta, b_truth_b2_eta);
  inTree->SetBranchAddress("truth_b2_phi", &truth_b2_phi, b_truth_b2_phi);
  inTree->SetBranchAddress("truth_b2_m", &truth_b2_m, b_truth_b2_m);

  inTree->SetBranchAddress("truth_tau1_pt", &truth_tau1_pt, b_truth_tau1_pt);
  inTree->SetBranchAddress("truth_tau1_eta", &truth_tau1_eta, b_truth_tau1_eta);
  inTree->SetBranchAddress("truth_tau1_phi", &truth_tau1_phi, b_truth_tau1_phi);
  inTree->SetBranchAddress("truth_tau1_m", &truth_tau1_m, b_truth_tau1_m);
  
  inTree->SetBranchAddress("truth_tau2_pt", &truth_tau2_pt, b_truth_tau2_pt);
  inTree->SetBranchAddress("truth_tau2_eta", &truth_tau2_eta, b_truth_tau2_eta);
  inTree->SetBranchAddress("truth_tau2_phi", &truth_tau2_phi, b_truth_tau2_phi);
  inTree->SetBranchAddress("truth_tau2_m", &truth_tau2_m, b_truth_tau2_m);
  */

  inTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt, &b_recojet_antikt10UFO_NOSYS_pt);
  inTree->SetBranchAddress("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta, &b_recojet_antikt10UFO_eta);
  inTree->SetBranchAddress("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi, &b_recojet_antikt10UFO_phi);
  inTree->SetBranchAddress("recojet_antikt10UFO_m", &recojet_antikt10UFO_m, &b_recojet_antikt10UFO_m);
  
  
  inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &bbtt_H_vis_tautau_pt_NOSYS, &b_bbtt_H_vis_tautau_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &bbtt_H_vis_tautau_m, &b_bbtt_H_vis_tautau_m);
  inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &bbtt_H_bb_pt_NOSYS, &b_bbtt_H_bb_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Jet_b1_pt_NOSYS", &bbtt_Jet_b1_pt_NOSYS, &b_bbtt_Jet_b1_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Jet_b2_pt_NOSYS", &bbtt_Jet_b2_pt_NOSYS, &b_bbtt_Jet_b2_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_H_bb_m", &bbtt_H_bb_m, &b_bbtt_H_bb_m);
  inTree->SetBranchAddress("generatorWeight_NOSYS", &generatorWeight_NOSYS, &b_generatorWeight_NOSYS);
  //inTree->SetBranchAddress("tau_NOSYS_passesOR", &tau_NOSYS_passesOR, &b_tau_NOSYS_passesOR);
  inTree->SetBranchAddress("recojet_antikt4PFlow_NOSYS_passesOR", &recojet_antikt4PFlow_NOSYS_passesOR, &b_recojet_antikt4PFlow_NOSYS_passesOR);
  
}


// This function prints the list of branches of a given tree
void print_list_of_branches(TTree* tree){

  cout << "The number of entries is: " << tree->GetEntries() << endl;

  // Get the list of branches
  TObjArray *branchList = tree->GetListOfBranches();
  
  // Loop over branches and print their names and types
  for (int ii = 0; ii < branchList->GetEntries(); ++ii) {
    TBranch *branch = dynamic_cast<TBranch*>(branchList->At(ii));
    if (!branch) continue;
    
    const char* branchName = branch->GetName();
    const char* typeName = branch->GetClassName(); // Get the class name of the branch type

    std::cout << "Branch: " << branchName << "\t Type: " << (typeName ? typeName : "Unknown") << std::endl;
  }
}
