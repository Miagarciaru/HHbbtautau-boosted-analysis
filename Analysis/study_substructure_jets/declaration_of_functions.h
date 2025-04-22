#include "declaration_of_variables.h"
#include "fill_histo_functions.h"
#include "input_output_functions.h"

// *************************************
// Declaration of functions
// *************************************

void compute_statistical_parameters();
void counting_statistical_parameters();
void correct_match_between_truth_reco_and_preselected_objects();
void apply_preselection(float min_pT_cut_in_MeV);
void define_preselected_events();
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

void compute_statistical_parameters(){

  //***************************************************************************
  // Parameters for Boosted bb
  //***************************************************************************
  
  efficiency_Bbb = 100.0*TP_Bbb/(TP_Bbb+FN_Bbb);
  purity_Bbb = 100.0*TP_Bbb/(TP_Bbb+FP_Bbb);
  accuracy_Bbb = 100.0*(TP_Bbb+TN_Bbb)/(TP_Bbb+FP_Bbb+TN_Bbb+FN_Bbb);
  
  //***************************************************************************
  // Parameters for Boosted tautau
  //***************************************************************************
  
  efficiency_Btautau = 100.0*TP_Btautau/(TP_Btautau+FN_Btautau);
  purity_Btautau = 100.0*TP_Btautau/(TP_Btautau+FP_Btautau);
  accuracy_Btautau = 100.0*(TP_Btautau+TN_Btautau)/(TP_Btautau+FP_Btautau+TN_Btautau+FN_Btautau);

  //***************************************************************************
  // Parameters for Boosted bbtautau
  //***************************************************************************
  
  efficiency_BbbBtautau = 100.0*TP_BbbBtautau/(TP_BbbBtautau+FN_BbbBtautau);
  purity_BbbBtautau = 100.0*TP_BbbBtautau/(TP_BbbBtautau+FP_BbbBtautau);
  accuracy_BbbBtautau = 100.0*(TP_BbbBtautau+TN_BbbBtautau)/(TP_BbbBtautau+FP_BbbBtautau+TN_BbbBtautau+FN_BbbBtautau);

  // Saving the parameters in the TH2F histogram
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 1, efficiency_BbbBtautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 2, purity_BbbBtautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(1, 3, accuracy_BbbBtautau);

  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 1, efficiency_Bbb);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 2, purity_Bbb);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(2, 3, accuracy_Bbb);

  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 1, efficiency_Btautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 2, purity_Btautau);
  percentages_statistical_parameters_for_preselected_events->SetBinContent(3, 3, accuracy_Btautau);

  
  percentages_statistical_parameters_for_preselected_events->GetXaxis()->SetBinLabel(1, "B_{bb}-B_{#tau#tau} Preselected Events");
  percentages_statistical_parameters_for_preselected_events->GetXaxis()->SetBinLabel(2, "B_{bb} Preselected Events");
  percentages_statistical_parameters_for_preselected_events->GetXaxis()->SetBinLabel(3, "B_{#tau#tau} Preselected Events");

  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(1, "Efficency (%)");
  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(2, "Purity (%)");
  percentages_statistical_parameters_for_preselected_events->GetYaxis()->SetBinLabel(3, "Accuracy (%)");

  cout << "Efficiency for Bbb: " << efficiency_Bbb << endl;
  cout << "Purity for Bbb: " << purity_Bbb << endl;
  cout << "Accuracy for Bbb: " << accuracy_Bbb << endl;
  cout << "--------------------------------" << endl;
  cout << "Efficiency for Bbb: " << percentages_statistical_parameters_for_preselected_events->GetBinContent(2,1) << endl;
  cout << "Purity for Bbb: " <<percentages_statistical_parameters_for_preselected_events->GetBinContent(2,2) << endl;
  cout << "Accuracy for Bbb: " << percentages_statistical_parameters_for_preselected_events->GetBinContent(2,3) << endl;
  
  // Fill percentages Bbb
  
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 1, 100.0*matched_bb_non_preselected/matched_bb_events); // Matched events percentages wrongly preselected                                     
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 2, 100.0*overlap_matched_preselected_bb_events/matched_bb_events); // Matched events percentages being preselected                            
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(1, 3, 100.0*matched_bb_non_preselected_info/matched_bb_events); // Matched events percentages with no preselected info                           
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 1, 100.0*preselected_bb_non_matched/matched_preselected_bb_events); // Preselected events percentages wrongly matched                         
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 2, 100.0*overlap_matched_preselected_bb_events/matched_preselected_bb_events); // Preselected events percentages being matched                
  percentages_matched_and_preselected_events_only_Bbb->SetBinContent(2, 3, 100.0*preselected_bb_non_matched_truth_reco_info/matched_preselected_bb_events); // Preselected events percentages with no truth-reco info 

  percentages_matched_and_preselected_events_only_Bbb->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{bb} events");
  percentages_matched_and_preselected_events_only_Bbb->GetXaxis()->SetBinLabel(2, "Preselected B_{bb} events");

  percentages_matched_and_preselected_events_only_Bbb->GetYaxis()->SetBinLabel(1, "Wrong");
  percentages_matched_and_preselected_events_only_Bbb->GetYaxis()->SetBinLabel(2, "Correct");
  percentages_matched_and_preselected_events_only_Bbb->GetYaxis()->SetBinLabel(3, "No info match");


  // Fill percentages Btautau
  
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 1, 100.0*matched_tautau_non_preselected/matched_tautau_events); // Matched events percentages wrongly preselected                         
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 2, 100.0*overlap_matched_preselected_tautau_events/matched_tautau_events); // Matched events percentages being preselected                
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(1, 3, 100.0*matched_tautau_non_preselected_info/matched_tautau_events); // Matched events percentages with no preselected info               
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 1, 100.0*preselected_tautau_non_matched/matched_preselected_tautau_events); // Preselected events percentages not being matched           
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 2, 100.0*overlap_matched_preselected_tautau_events/matched_preselected_tautau_events); // Preselected events percentages being matched    
  percentages_matched_and_preselected_events_only_Btautau->SetBinContent(2, 3, 100.0*preselected_tautau_non_matched_truth_reco_info/matched_preselected_tautau_events); // Preselected events percentages with no tru\
th-reco info                                                                                                                                                                                                          

  percentages_matched_and_preselected_events_only_Btautau->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{#tau#tau} events");
  percentages_matched_and_preselected_events_only_Btautau->GetXaxis()->SetBinLabel(2, "Preselected B_{#tau#tau} events");

  percentages_matched_and_preselected_events_only_Btautau->GetYaxis()->SetBinLabel(1, "Wrong");
  percentages_matched_and_preselected_events_only_Btautau->GetYaxis()->SetBinLabel(2, "Correct");
  percentages_matched_and_preselected_events_only_Btautau->GetYaxis()->SetBinLabel(3, "No info match");


  // Fill percentages Bbb-Btautau
  
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 1, 100.0*matched_bbtautau_non_preselected/matched_bbtautau_events); // Matched events percentages wrongly preselected
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 2, 100.0*overlap_matched_preselected_bbtautau_events/matched_bbtautau_events); // Matched events percentages being preselected
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(1, 3, 100.0*matched_bbtautau_non_preselected_info/matched_bbtautau_events); // Matched events percentages with no preselected info
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 1, 100.0*preselected_bbtautau_non_matched/matched_preselected_bbtautau_events); // Preselected events percentages not being matched
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 2, 100.0*overlap_matched_preselected_bbtautau_events/matched_preselected_bbtautau_events); // Preselected events percentages being matched
  percentages_matched_and_preselected_events_BbbBtautau->SetBinContent(2, 3, 100.0*preselected_bbtautau_non_matched_truth_reco_info/matched_preselected_bbtautau_events); // Preselected events percentages with no truth-reco info
  
  percentages_matched_and_preselected_events_BbbBtautau->GetXaxis()->SetBinLabel(1, "Matched truth-recojet B_{bb}-B_{#tau#tau} events");
  percentages_matched_and_preselected_events_BbbBtautau->GetXaxis()->SetBinLabel(2, "Preselected B_{bb}-B_{#tau#tau} events");

  percentages_matched_and_preselected_events_BbbBtautau->GetYaxis()->SetBinLabel(1, "Wrong");
  percentages_matched_and_preselected_events_BbbBtautau->GetYaxis()->SetBinLabel(2, "Correct");
  percentages_matched_and_preselected_events_BbbBtautau->GetYaxis()->SetBinLabel(3, "No info match");  
}


void counting_statistical_parameters(){

  //******************************************************************************************
  // Counting TP, FP, TN and FN boosted bb
  //******************************************************************************************

  if( (class_event == 2 || class_event == 3) && passed_reco_truth_match_bb_pT_cut == true ){ // All truth-reco Bbb
    // Since Bbb has the same index for b1 and b2, we only compare the b1 indexes
    if( truth_reco_matched_preselected_Bbb == true ){
      // Truth Boosted bb that are preselected as boosted bb (Correct clasiffication)
      TP_Bbb++;
    }
    else{
      // Truth Boosted bb that are preselected as non boosted bb (Lost of correct boosted events)
      FN_Bbb++;
    }
  }
  else{
    if( matched_preselected_bb == true && passed_preselection_bb_pT_cut == true ){
      // False Boosted bb that are preselected as boosted bb (Wrong classification)
      FP_Bbb++;
    }
    else{
      // False boosted bb that are non preselected bb (Correctly discarded)
      TN_Bbb++;
    }
  }

  //******************************************************************************************
  // Counting TP, FP, TN and FN boosted tautau
  //******************************************************************************************

  if( (class_event == 1 || class_event == 3) && passed_reco_truth_match_tautau_pT_cut == true ){ // All truth-reco Btautau
    // Since Btautau has the same index for tau1 and tau2, we only compare the b1 indexes
    if( truth_reco_matched_preselected_Btautau == true ){ 
      // Truth Boosted tautau that are preselected as boosted tautau (Correct clasiffication)
      TP_Btautau++;
    }
    else{
      // Truth Boosted tautau that are preselected as non boosted tautau (Lost of correct boosted events)
      FN_Btautau++;
    }
  }
  else{
    if( matched_preselected_tautau == true && passed_preselection_tautau_pT_cut == true ){
      // False Boosted tautau that are preselected as boosted tautau (Wrong classification)
      FP_Btautau++;
    }
    else{
      // False boosted tautau that are non preselected tautau (Correctly discarded)
      TN_Btautau++;
    }
  }

  //******************************************************************************************
  // Counting TP, FP, TN and FN boosted bbtautau
  //******************************************************************************************

  if( class_event == 3 && passed_reco_truth_match_pT_cut == true ){ // All truth-reco Btautau
    if( truth_reco_matched_preselected_BbbBtautau == true ){ 
      // Truth Boosted BbbBtautau that are preselected as boosted BbbBtautau (Correct clasiffication)
      TP_BbbBtautau++;
    }
    else{
      // Truth Boosted BbbBtautau that are preselected as non boosted BbbBtautau (Lost of correct boosted events)
      FN_BbbBtautau++;
    }
  }
  else{
    if( matched_preselection == true && passed_preselection_pT_cut == true ){
      // False Boosted BbbBtautau that are preselected as boosted BbbBtautau (Wrong classification)
      FP_BbbBtautau++;
    }
    else{
      // False boosted BbbBtautau that are non preselected BbbBtautau (Correctly discarded)
      TN_BbbBtautau++;
    }
  }
  
}

void correct_match_between_truth_reco_and_preselected_objects(){

  //**************************************************************
  // Preselected verification
  //**************************************************************

  correct_matched_preselected_Bbb = false;
  wrong_matched_preselected_Bbb = false;
  matched_preselected_Bbb_non_matched_truth_reco_info = false;
  
  correct_matched_preselected_Btautau = false;
  wrong_matched_preselected_Btautau = false;
  matched_preselected_Btautau_non_matched_truth_reco_info = false;
  
  correct_matched_preselected_BbbBtautau = false;
  wrong_matched_preselected_BbbBtautau = false;
  matched_preselected_BbbBtautau_non_matched_truth_reco_info = false;
  
  if( matched_preselected_bb == true && passed_preselection_bb_pT_cut == true ){
    matched_preselected_bb_events++;
    if( class_event != -1 && passed_reco_truth_match_bb_pT_cut == true ){
      // Since Bbb has the same index for b1 and b2, we only compare the b1 indexes
      if( (class_event == 2 || class_event == 3) && idx_b1truth_recoak10_dRmin == idx_b1_preselected ){
	correct_matched_preselected_Bbb = true;
	preselected_bb_well_matched++;
      }
      else{
	wrong_matched_preselected_Bbb = true;
	preselected_bb_non_matched++;
      }
    }
    else{
      matched_preselected_Bbb_non_matched_truth_reco_info = true;
      preselected_bb_non_matched_truth_reco_info++;
    }
  }

  if( matched_preselected_tautau == true && passed_preselection_tautau_pT_cut == true ){
    matched_preselected_tautau_events++;
    if( class_event != -1 && passed_reco_truth_match_tautau_pT_cut == true ){
      // Since Btautau has the same index for tau1 and tau2, we only compare the tau1 indexes
      if( (class_event == 1 || class_event == 3) && idx_tau1truth_recoak10_dRmin == idx_tau1_preselected ){
	correct_matched_preselected_Btautau = true;
	preselected_tautau_well_matched++;
      }
      else{
	wrong_matched_preselected_Btautau = true;
	preselected_tautau_non_matched++;
      }
    }
    else{
      matched_preselected_Btautau_non_matched_truth_reco_info = true;
      preselected_tautau_non_matched_truth_reco_info++;
    }
  }

  
  if( matched_preselection == true && passed_preselection_pT_cut == true ){
    matched_preselected_bbtautau_events++;
    if( class_event != -1 && passed_reco_truth_match_pT_cut == true ){ // class != -1 means all truth-reco info
      if( correct_matched_preselected_Bbb == true && correct_matched_preselected_Btautau == true){ // only possible when class3
	correct_matched_preselected_BbbBtautau = true;
	preselected_bbtautau_well_matched++;
      }
      else{ // other classes different from 3, means wrong matches
	wrong_matched_preselected_BbbBtautau = true;
	preselected_bbtautau_non_matched++;
      }
    }
    else{ // No info truth-reco to determine if the preselction was done correctly or not
      matched_preselected_BbbBtautau_non_matched_truth_reco_info = true;
      preselected_bbtautau_non_matched_truth_reco_info++;
    }
  }

  //**************************************************************
  // Truth-reco verification
  //**************************************************************

  truth_reco_matched_preselected_Bbb = false;
  truth_reco_non_matched_preselected_Bbb = false;
  truth_reco_Bbb_non_matched_preselected_info = false;
  
  truth_reco_matched_preselected_Btautau = false;
  truth_reco_non_matched_preselected_Btautau = false;
  truth_reco_Btautau_non_matched_preselected_info = false;

  truth_reco_matched_preselected_BbbBtautau = false;
  truth_reco_non_matched_preselected_BbbBtautau = false;
  truth_reco_BbbBtautau_non_matched_preselected_info = false;
  
  if( (class_event == 2 || class_event == 3) && passed_reco_truth_match_bb_pT_cut == true ){ // All truth-reco Bbb
    matched_bb_events++;
    if( matched_preselected_bb == true && passed_preselection_bb_pT_cut == true ){ 
      // Since Bbb has the same index for b1 and b2, we only compare the b1 indexes
      if( idx_b1truth_recoak10_dRmin == idx_b1_preselected ){
	truth_reco_matched_preselected_Bbb = true;
	matched_bb_well_preselection++;
      }
      else{
	truth_reco_non_matched_preselected_Bbb = true;
	matched_bb_non_preselected++;
      }
    }
    else{
      truth_reco_Bbb_non_matched_preselected_info = true;
      matched_bb_non_preselected_info++;
    }
  }

  if( (class_event == 1 || class_event == 3) && passed_reco_truth_match_tautau_pT_cut == true ){ // All truth-reco Btautau
    matched_tautau_events++;
    if( matched_preselected_tautau == true && passed_preselection_tautau_pT_cut == true ){ 
      // Since Btautau has the same index for tau1 and tau2, we only compare the tau1 indexes
      if( idx_tau1truth_recoak10_dRmin == idx_tau1_preselected ){
	truth_reco_matched_preselected_Btautau = true;
	matched_tautau_well_preselection++;
      }
      else{
	truth_reco_non_matched_preselected_Btautau = true;
	matched_tautau_non_preselected++;
      }
    }
    else{
      truth_reco_Btautau_non_matched_preselected_info = true;
      matched_tautau_non_preselected_info++;
    }
  }

  if( class_event == 3 && passed_reco_truth_match_pT_cut == true ){ // All truth-reco BbbBtautau
    matched_bbtautau_events++;
    if( matched_preselection == true && passed_preselection_pT_cut == true ){
      if( truth_reco_matched_preselected_Bbb == true && truth_reco_matched_preselected_Btautau == true ){
	truth_reco_matched_preselected_BbbBtautau = true;
	matched_bbtautau_well_preselected++;
      }
      else{
	truth_reco_non_matched_preselected_BbbBtautau = true;
	matched_bbtautau_non_preselected++;
      }
    }
    else{
      truth_reco_BbbBtautau_non_matched_preselected_info = true;
      matched_bbtautau_non_preselected_info++;
    }
  }

  //**************************************************************
  // Overlaps truth-reco and preselection verification
  //**************************************************************

  if( correct_matched_preselected_Bbb == true && truth_reco_matched_preselected_Bbb == true){
    overlap_matched_preselected_bb_events++;
  }

  if( correct_matched_preselected_Btautau == true && truth_reco_matched_preselected_Btautau == true){
    overlap_matched_preselected_tautau_events++;
  }
  
  if( correct_matched_preselected_BbbBtautau == true && truth_reco_matched_preselected_BbbBtautau == true){
    overlap_matched_preselected_bbtautau_events++;
  }
  
}

void apply_preselection(float min_pT_cut_in_MeV){
  
  // default value for the preselection
  passed_preselection_pT_cut = false;
  passed_preselection_bb_pT_cut = false;
  passed_preselection_tautau_pT_cut = false;
  
  float pres_b1_pT_in_MeV = 0;
  float pres_b2_pT_in_MeV = 0;
  
  float pres_tau1_pT_in_MeV = 0;
  float pres_tau2_pT_in_MeV = 0;

  if( matched_preselected_bb == true ){

    pres_b1_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected);
    pres_b2_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_b2_preselected);
    
    if( pres_b1_pT_in_MeV >= min_pT_cut_in_MeV ){
      passed_preselection_bb_pT_cut = true;
    }

  }

  if( matched_preselected_tautau == true ){

    pres_tau1_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected);
    pres_tau2_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_tau2_preselected);
    
    if( pres_tau1_pT_in_MeV >= min_pT_cut_in_MeV ){
      passed_preselection_tautau_pT_cut = true;
    }

  }

  if( matched_preselection == true ){
    
    std::vector<float> preselected_pT_values = {pres_b1_pT_in_MeV, pres_b2_pT_in_MeV, pres_tau1_pT_in_MeV, pres_tau2_pT_in_MeV};
    
    float min_pT_for_preselected_objects_MeV = *std::min_element(preselected_pT_values.begin(), preselected_pT_values.end());
    
    if( min_pT_for_preselected_objects_MeV >= min_pT_cut_in_MeV ){
      passed_preselection_pT_cut = true;
    }
    
  }
  
  // default value for the preselection
  passed_reco_truth_match_pT_cut = false;
  passed_reco_truth_match_bb_pT_cut = false;
  passed_reco_truth_match_tautau_pT_cut = false;
  
  float reco_truth_b1_pT_in_MeV = 0;
  float reco_truth_b2_pT_in_MeV = 0;
  
  float reco_truth_tau1_pT_in_MeV = 0;
  float reco_truth_tau2_pT_in_MeV = 0;

  if( class_event != -1 ){

    reco_truth_b1_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin);
    reco_truth_b2_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin);
    reco_truth_tau1_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin);
    reco_truth_tau2_pT_in_MeV = recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin);
    
    if( reco_truth_b1_pT_in_MeV >= min_pT_cut_in_MeV && reco_truth_b2_pT_in_MeV >= min_pT_cut_in_MeV ){
      passed_reco_truth_match_bb_pT_cut = true;
    }
    
    if( reco_truth_tau1_pT_in_MeV >= min_pT_cut_in_MeV && reco_truth_tau2_pT_in_MeV >= min_pT_cut_in_MeV ){
      passed_reco_truth_match_tautau_pT_cut = true;
    }
    
    std::vector<float> reco_truth_pT_values = {reco_truth_b1_pT_in_MeV, reco_truth_b2_pT_in_MeV, reco_truth_tau1_pT_in_MeV, reco_truth_tau2_pT_in_MeV};
    
    float min_pT_for_reco_truth_objects_MeV = *std::min_element(reco_truth_pT_values.begin(), reco_truth_pT_values.end());
    
    if( min_pT_for_reco_truth_objects_MeV >= min_pT_cut_in_MeV ){
      passed_reco_truth_match_pT_cut = true;
    }
  }
}

void define_preselected_events(){

  // Assign default values for preselected bb and tautau objects
  default_values_for_preselected_variables();
    
  matched_preselected_bb = false;
  matched_preselected_tautau = false;
  matched_preselection = false;
  
  int number_of_tagged_bb_jets = 0;
  
  if( recojet_antikt10UFO_NOSYS_pt->size() >= 2 ){
    
    float min_tagger_Hbb_value = 0.85;
    float value_phbb = 0;
    
    float max_nsubjetiness_value_for_bb = 0.45;
    float min_nsubjetiness_value_for_bb = 0.05;
    
    float tau_n2_over_n1_subjettiness_bb = 0;
    
    float max_pT_bb_current = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    float max_pT_bb_previous = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    
    //Selecting preselected boosted bb jet 
    for(Int_t ii=0; ii<recojet_antikt10UFO_GN2Xv01_phbb->size(); ii++){
      
      bool taggerHbb_score_cut = false;
      value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(ii);
      
      if(value_phbb >= min_tagger_Hbb_value){
	taggerHbb_score_cut = true;
	hist_matched_preselected_bb_m_only_Hbb_tagger->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
      }
      
      bool nsubjettiness_cut = false;
      tau_n2_over_n1_subjettiness_bb = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
      
      if( (tau_n2_over_n1_subjettiness_bb <= max_nsubjetiness_value_for_bb) && (tau_n2_over_n1_subjettiness_bb >= min_nsubjetiness_value_for_bb) ){
	nsubjettiness_cut = true;
	hist_matched_preselected_bb_m_until_nsubjettiness->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
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
    
    float max_pT_tautau_current = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    float max_pT_tautau_previous = *std::min_element(recojet_antikt10UFO_NOSYS_pt->begin(), recojet_antikt10UFO_NOSYS_pt->end());
    
    //if(matched_preselected_bb == true){
    
    for(Int_t ii=0; ii < recojet_antikt10UFO_Tau2_wta->size(); ii++){
      
      if( matched_preselected_bb == true && ii == idx_b1_preselected ){
	continue;
      }
      
      bool taggerHbb_score_cut = false;
      value_phbb = recojet_antikt10UFO_GN2Xv01_phbb->at(ii);
      
      if(value_phbb < min_tagger_Hbb_value){
	taggerHbb_score_cut = true;
	hist_matched_preselected_tautau_m_only_Hbb_tagger->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
      }
      
      bool nsubjettiness_cut = false;
      tau_n2_over_n1_subjettiness_tautau = recojet_antikt10UFO_Tau2_wta->at(ii)/recojet_antikt10UFO_Tau1_wta->at(ii);
      
      if( (tau_n2_over_n1_subjettiness_tautau <= max_nsubjetiness_value_for_tautau) && (tau_n2_over_n1_subjettiness_tautau >= min_nsubjetiness_value_for_tautau) ){
	nsubjettiness_cut = true;
	hist_matched_preselected_tautau_m_until_nsubjettiness->Fill(recojet_antikt10UFO_m->at(ii)/1000.);
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
    
    //}
    
    if( matched_preselected_bb == true && matched_preselected_tautau == true ){
      matched_preselection = true;
    }
    
    // Save the values for bb, tautau and HH objects if it was posible to find the preselected bb and tautau boosted jets

    TLorentzVector bb = TLorentzVector();
    TLorentzVector tautau = TLorentzVector();
    TLorentzVector HH = TLorentzVector();
    
    if( matched_preselected_bb == true ){
      
      preselected_bb_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_b1_preselected);
      preselected_bb_eta = recojet_antikt10UFO_eta->at(idx_b1_preselected);
      preselected_bb_phi = recojet_antikt10UFO_phi->at(idx_b1_preselected);
      preselected_bb_m = recojet_antikt10UFO_m->at(idx_b1_preselected);
        
      bb.SetPtEtaPhiM(preselected_bb_pt, preselected_bb_eta, preselected_bb_phi, preselected_bb_m);
     
    }

    if( matched_preselected_tautau == true ){
      
      preselected_tautau_pt = recojet_antikt10UFO_NOSYS_pt->at(idx_tau1_preselected);
      preselected_tautau_eta = recojet_antikt10UFO_eta->at(idx_tau1_preselected);
      preselected_tautau_phi = recojet_antikt10UFO_phi->at(idx_tau1_preselected);
      preselected_tautau_m = recojet_antikt10UFO_m->at(idx_tau1_preselected);
      
      tautau.SetPtEtaPhiM(preselected_tautau_pt, preselected_tautau_eta, preselected_tautau_phi, preselected_tautau_m);
      
    }

    if( matched_preselection == true ){
      
      HH = bb + tautau;
      
      preselected_HH_pt = HH.Pt();
      preselected_HH_eta = HH.Eta();
      preselected_HH_phi = HH.Phi();
      preselected_HH_m = HH.M();	
      
    }
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
