#include "declaration_of_variables.h"
#include "fill_histo_functions.h"
#include "input_output_functions.h"

// *************************************
// Declaration of functions
// *************************************

void define_preselected_events();
void apply_preselection(float min_pT_cut_in_MeV);
void define_reconstructed_objects();
void define_output_branches();
void define_classes();
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void define_truth_tau_and_b_jets();
void default_values_for_truth_variables();
void default_values_for_preselected_variables();

// *************************************
// Definition of the functions declared above
// *************************************

void define_preselected_events(){

  matched_preselected_bb = false;
  matched_preselected_tautau = false;
  matched_preselection = false;

  int number_of_tagged_bb_jets = 0;
  float nsubjettiness_good_value_for_bb = 0.21;
  float nsubjettiness_good_value_for_tautau = 0.9;
  
  if( recojet_antikt10UFO_NOSYS_pt->size() >= 2 ){

    float min_tagger_Hbb_value = 0.85;
    float value_phbb = 0;
   
    float max_nsubjetiness_value_for_bb = 0.45;
    float min_nsubjetiness_value_for_bb = 0.05;

    float tau_n2_over_n1_subjettiness_bb = 0;
    
    float max_pT_bb_current = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    float max_pT_bb_previous = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());

    float nsubjettiness_bb_current = 1.0;
    float nsubjettiness_bb_previous = 1.0;
    
    //Selecting preselected boosted bb jet 
    for(Int_t ii=0; ii<recojet_antikt10UFO_GN2Xv01_phbb->size(); ii++){
      bool taggerHbb_score_cut = false;
      value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(ii);

      if(value_phbb >= min_tagger_Hbb_value){
	taggerHbb_score_cut = true;
	if(passed_preselection == true){
	  hist_matched_preselected_bb_m_only_Hbb_tagger->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
	}
      }
      
      bool nsubjettiness_cut = false;
      tau_n2_over_n1_subjettiness_bb = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
      if( (tau_n2_over_n1_subjettiness_bb <= max_nsubjetiness_value_for_bb) && (tau_n2_over_n1_subjettiness_bb >= min_nsubjetiness_value_for_bb) ){
	nsubjettiness_cut = true;
	if(passed_preselection == true){
	  hist_matched_preselected_bb_m_until_nsubjettiness->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
	}
      }
      
      if( (taggerHbb_score_cut==true) && (nsubjettiness_cut==true) ){
	max_pT_bb_current = recojet_antikt10UFO_NOSYS_pt->at(ii);
	
	if(max_pT_bb_current >= max_pT_bb_previous){
	  max_pT_bb_previous = max_pT_bb_current;
	  idx_b1_preselected = ii;
	  idx_b2_preselected = ii;
	  matched_preselected_bb = true;
	}
      }

    }
    
    float max_nsubjetiness_value_for_tautau = 0.30;
    float min_nsubjetiness_value_for_tautau = 0.05;
    
    float tau_n2_over_n1_subjettiness_tautau = 0;
    
    float nsubjettiness_tautau_current = 1.0;
    float nsubjettiness_tautau_previous = 1.0;
    
    float max_pT_tautau_current = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    float max_pT_tautau_previous = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    
    if(matched_preselected_bb == true){
      for(Int_t ii=0; ii < recojet_antikt10UFO_Tau2_wta->size(); ii++){
	if( ii != idx_b1_preselected ){
	  
	  bool taggerHbb_score_cut = false;
	  value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(ii);
	  if(value_phbb < min_tagger_Hbb_value){
	    taggerHbb_score_cut = true;
	    if(passed_preselection == true){
	      hist_matched_preselected_tautau_m_only_Hbb_tagger->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
	    }
	  }
	  
	  bool nsubjettiness_cut = false;
	  tau_n2_over_n1_subjettiness_tautau = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
	  if( (tau_n2_over_n1_subjettiness_tautau <= max_nsubjetiness_value_for_tautau) && (tau_n2_over_n1_subjettiness_tautau >= min_nsubjetiness_value_for_tautau) ){
	    nsubjettiness_cut = true;
	    if(passed_preselection == true){
	      hist_matched_preselected_tautau_m_until_nsubjettiness->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
	    }
	  }

	  if( (taggerHbb_score_cut==true) && (nsubjettiness_cut==true) ){
	    max_pT_tautau_current = recojet_antikt10UFO_NOSYS_pt->at(ii);
	    
	    if(max_pT_tautau_current >= max_pT_tautau_previous){
	      max_pT_tautau_previous = max_pT_tautau_current;
	      idx_tau1_preselected = ii;
	      idx_tau2_preselected = ii;
	      matched_preselected_tautau = true;
	    }
       
	  }          
	}
      }
    }
    
    if( (matched_preselected_bb == true) && (matched_preselected_tautau == true) ){
      matched_preselection = true;
    }
    
    // Save the values for bb, tautau and HH objects if it was posible to find the preselected bb and tautau boosted jets
    if( matched_preselection == true ){
      
      TLorentzVector bb = TLorentzVector();
      TLorentzVector tautau = TLorentzVector();
      TLorentzVector HH = TLorentzVector();
      
      preselected_bb_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected);
      preselected_bb_eta = recojet_antikt10UFO_eta->at(idx_b1_preselected);
      preselected_bb_phi = recojet_antikt10UFO_phi->at(idx_b1_preselected);
      preselected_bb_m = recojet_antikt10UFO_m->at(idx_b1_preselected);
      
      preselected_tautau_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected);
      preselected_tautau_eta = recojet_antikt10UFO_eta->at(idx_tau1_preselected);
      preselected_tautau_phi = recojet_antikt10UFO_phi->at(idx_tau1_preselected);
      preselected_tautau_m = recojet_antikt10UFO_m->at(idx_tau1_preselected);
      
      bb.SetPtEtaPhiM(preselected_bb_pt, preselected_bb_eta, preselected_bb_phi, preselected_bb_m);
      tautau.SetPtEtaPhiM(preselected_tautau_pt, preselected_tautau_eta, preselected_tautau_phi, preselected_tautau_m);
      
      HH = bb + tautau;
      
      preselected_HH_pt = HH.Pt();
      preselected_HH_eta = HH.Eta();
      preselected_HH_phi = HH.Phi();
      preselected_HH_m = HH.M();	
      
    }
    // Save the default values if it was not possible to find the bb and tautau objects
    if( matched_preselection == false ){
      default_values_for_preselected_variables();
    }
  }
  // Save the default values if it the first preselection was not passed
  if( recojet_antikt10UFO_NOSYS_pt->size() < 2 ){
    default_values_for_preselected_variables();
  }
}

void apply_preselection(float min_pT_cut_in_MeV){
  
  // default value for the preselection
  passed_preselection = false;
  
  bool min_pT_cut = false;
  
  float min_pT_recojets_MeV = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());

  if( min_pT_recojets_MeV >= min_pT_cut_in_MeV ){
    min_pT_cut = true;
  }

  bool recojets_number_condition = true;
  if( recojet_antikt10UFO_NOSYS_pt->size() < 2){
    recojets_number_condition = false;
  }
  
  if( (min_pT_recojets_MeV >= min_pT_cut_in_MeV) && (recojets_number_condition==true) ){
    passed_preselection = true;
  }
  
}

void define_reconstructed_objects(){
  
  TLorentzVector b1 = TLorentzVector();
  TLorentzVector b2 = TLorentzVector();
  TLorentzVector bb = TLorentzVector();

  TLorentzVector tau1 = TLorentzVector();
  TLorentzVector tau2 = TLorentzVector();
  TLorentzVector tautau = TLorentzVector();

  TLorentzVector HH = TLorentzVector();

  if( class_event != -1 ){
    if( class_event == 0){ // R_bb - R_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin));
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin));
      bb = b1+b2;
      tautau = tau1+tau2;
      HH = b1+b2+tau1+tau2;
    }

    if( class_event == 1){ // R_bb - B_tautau
      b1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      b2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin));
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      bb = b1+b2;
      HH = b1+b2+tautau;
    }

    if( class_event == 2){ // B_bb - R_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      tau1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      tau2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin));
      tautau = tau1+tau2;
      HH = bb+tau1+tau2;
    }

    if( class_event == 3){ // B_bb - B_tautau
      bb.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin));
      tautau.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin));
      HH = bb+tautau;
    }
    
    reco_bbtt_bb_pt_BA = bb.Pt();
    reco_bbtt_bb_eta_BA = bb.Eta();
    reco_bbtt_bb_phi_BA = bb.Phi();
    reco_bbtt_bb_m_BA = bb.M();
    
    reco_bbtt_tautau_pt_BA = tautau.Pt();
    reco_bbtt_tautau_eta_BA = tautau.Eta();
    reco_bbtt_tautau_phi_BA = tautau.Phi();
    reco_bbtt_tautau_m_BA = tautau.M();
    
    reco_bbtt_HH_pt_BA = HH.Pt();
    reco_bbtt_HH_eta_BA = HH.Eta();
    reco_bbtt_HH_phi_BA = HH.Phi();
    reco_bbtt_HH_m_BA = HH.M();
  }

  else{
    reco_bbtt_bb_pt_BA = -99;
    reco_bbtt_bb_eta_BA = -99;
    reco_bbtt_bb_phi_BA = -99;
    reco_bbtt_bb_m_BA = -99;
    
    reco_bbtt_tautau_pt_BA = -99;
    reco_bbtt_tautau_eta_BA = -99;
    reco_bbtt_tautau_phi_BA = -99;
    reco_bbtt_tautau_m_BA = -99;

    reco_bbtt_HH_pt_BA = -99;
    reco_bbtt_HH_eta_BA = -99;
    reco_bbtt_HH_phi_BA = -99;
    reco_bbtt_HH_m_BA = -99;
  }
}


// This function tell us on which class the event is given the next description:
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

*/

void define_classes(){

  class_event = -1;

  if( (idx_b1truth_recoak10_dRmin != -1) && (idx_b2truth_recoak10_dRmin != -1) && (idx_tau1truth_recoak10_dRmin != -1) && (idx_tau2truth_recoak10_dRmin != -1) ){

    if( (idx_b1truth_recoak10_dRmin!=idx_tau1truth_recoak10_dRmin) && (idx_b1truth_recoak10_dRmin!=idx_tau2truth_recoak10_dRmin) && (idx_b2truth_recoak10_dRmin!=idx_tau1truth_recoak10_dRmin) && (idx_b2truth_recoak10_dRmin!=idx_tau2truth_recoak10_dRmin)){  
      
      bool are_boosted_bb_matched = false;
      bool are_boosted_tautau_matched = false;
      
      if( idx_b1truth_recoak10_dRmin == idx_b2truth_recoak10_dRmin ){
	are_boosted_bb_matched = true;
      }
      if( idx_tau1truth_recoak10_dRmin == idx_tau2truth_recoak10_dRmin ){
	are_boosted_tautau_matched = true;
      }
      
      // ************************************
      // For the boosted and resolved jets that are correctly identified matched to fat jets
      
      // For the R_bb R_tautau class
      if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==false) ){
	class_event = 0;
      }
      
      // For the R_bb B_tautau class
      if( (are_boosted_bb_matched==false) && (are_boosted_tautau_matched==true) ){
	class_event = 1;
      }
      
      // For the B_bb R_tautau class
      if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==false) ){
	class_event = 2;
      }

      // For the B_bb B_tautau class
      if( (are_boosted_bb_matched==true) && (are_boosted_tautau_matched==true) ){
	class_event = 3;
      }
    }
  }
}

// This function give us the min deltaR between the truth_objects and the objects in the recojets_ak10UFO fat-jets
void compute_dR_min_index_fat_jets(){
  
  compute_dR_min(idx_b1truth_recoak10_dRmin, dR_min_b1truth_recoak10_fatjet, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
  compute_dR_min(idx_b2truth_recoak10_dRmin, dR_min_b2truth_recoak10_fatjet, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
  compute_dR_min(idx_tau1truth_recoak10_dRmin, dR_min_tau1truth_recoak10_fatjet, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
  compute_dR_min(idx_tau2truth_recoak10_dRmin, dR_min_tau2truth_recoak10_fatjet, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
  
}

void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m){

  dR_min = 1; // Min dR value for which a truth object can be matched to a recojet
  idx = -1;
  
  if(recojet_antikt10UFO_NOSYS_pt->size() > 0){
    for(int ii = 0; ii < recojet_antikt10UFO_NOSYS_pt->size(); ii++){
      
      TLorentzVector truth_jet  = TLorentzVector();
      TLorentzVector reco_jet  = TLorentzVector();
      
      float reco_pt = recojet_antikt10UFO_NOSYS_pt->at(ii);
      float reco_eta = recojet_antikt10UFO_eta->at(ii);
      float reco_phi = recojet_antikt10UFO_phi->at(ii);
      float reco_m = recojet_antikt10UFO_m->at(ii);
      
      truth_jet.SetPtEtaPhiM(truth_pt, truth_eta, truth_phi, truth_m);
      reco_jet.SetPtEtaPhiM(reco_pt, reco_eta, reco_phi, reco_m);
      
      float deltaR_truth_recojet = truth_jet.DeltaR(reco_jet);
      
      if( (deltaR_truth_recojet < dR_min) ){
	dR_min = deltaR_truth_recojet;
	idx = ii;
      }
    }
  }
  else{
    idx = -1;
    dR_min = -1;
  }
}

void define_truth_tau_and_b_jets(){

  if((truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2)){

    int sum_type_H1 = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1));
    int sum_type_H2 = TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
    int sum_type_HH = sum_type_H1+sum_type_H2;
    
    // Here we assume that all the jets are listed from the highest pT to the lowest pT
    int index_b1 = 0;
    int index_b2 = 1;
    int index_tau1 = 0;
    int index_tau2 = 1;

    TLorentzVector b1_jet  = TLorentzVector();
    TLorentzVector b2_jet  = TLorentzVector();
    TLorentzVector bb_jet  = TLorentzVector();

    TLorentzVector tau1_jet  = TLorentzVector();
    TLorentzVector tau2_jet  = TLorentzVector();
    TLorentzVector tautau_jet  = TLorentzVector();

    TLorentzVector HH_jet  = TLorentzVector();

    if( sum_type_HH == 40 ){
      // Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1bb_H2tautau scenario
      if( (sum_type_H1 == 10) && (sum_type_H2 == 30) ){
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

      else if( (sum_type_H1 == 30) && (sum_type_H2 == 10) ){
	
	// Here we swap the index for the b and taus if the leading jet has a lower pT than the subleading jet, in the H1tautau_H2bb scenario
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

      b1_jet.SetPtEtaPhiM(truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m);
      b2_jet.SetPtEtaPhiM(truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      bb_jet = b1_jet + b2_jet;
      
      truth_bb_pt = bb_jet.Pt();
      truth_bb_eta = bb_jet.Eta();
      truth_bb_phi = bb_jet.Phi();
      truth_bb_m = bb_jet.M();
	
      tau1_jet.SetPtEtaPhiM(truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m);
      tau2_jet.SetPtEtaPhiM(truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);
      tautau_jet = tau1_jet + tau2_jet;
      
      truth_tautau_pt = tautau_jet.Pt();
      truth_tautau_eta = tautau_jet.Eta();
      truth_tautau_phi = tautau_jet.Phi();
      truth_tautau_m = tautau_jet.M();
      
      HH_jet = bb_jet + tautau_jet;
	
      truth_HH_pt = HH_jet.Pt();
      truth_HH_eta = HH_jet.Eta();
      truth_HH_phi = HH_jet.Phi();
      truth_HH_m = HH_jet.M();	
    }
    else{
      // set -99 to truth variables
      default_values_for_truth_variables();
    }
  }
  else{
    // set -99 to truth variables
    default_values_for_truth_variables();
  }
}

// This function set the values -99 for truth variables when HH->bbtautau is not identified
void default_values_for_truth_variables(){

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
  
  truth_HH_pt = -99;
  truth_HH_eta = -99;
  truth_HH_phi = -99;
  truth_HH_m = -99;

  truth_bb_pt = -99;
  truth_bb_eta = -99;
  truth_bb_phi = -99;
  truth_bb_m = -99;

  truth_tautau_pt = -99;
  truth_tautau_eta = -99;
  truth_tautau_phi = -99;
  truth_tautau_m = -99;
}

// This function set the values -99 for preselected variables when HH->bbtautau is not identified
void default_values_for_preselected_variables(){

  preselected_HH_pt = -99;
  preselected_HH_eta = -99;
  preselected_HH_phi = -99;
  preselected_HH_m = -99;
  
  preselected_bb_pt = -99;
  preselected_bb_eta = -99;
  preselected_bb_phi = -99;
  preselected_bb_m = -99;

  preselected_tautau_pt = -99;
  preselected_tautau_eta = -99;
  preselected_tautau_phi = -99;
  preselected_tautau_m = -99;

  idx_b1_preselected = -99;
  idx_b2_preselected = -99;
  idx_tau1_preselected = -99;
  idx_tau2_preselected = -99;
  
}
