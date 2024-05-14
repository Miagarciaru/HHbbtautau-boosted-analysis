#include "Plotting.h"

// *************************************
// Declaration of functions
// *************************************

void process_label(TString name_sample);
void acceptance_mHH_variable();
void define_output_branches();
void define_classes();
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m);
void define_truth_tau_and_b_jets();
void fill_histograms();
void set_branch_address_inTree(TTree *inTree);
void define_output_branches(TTree *outTree);
void print_list_of_branches(TTree* tree);


// *************************************
// Definition of the functions declared above
// *************************************

void process_label(TString name_sample){

  // ggF processes had-had channel
  if(name_sample.Contains("600459")==true){ process_name = "ggF HH SM had-had channel"; }
  if(name_sample.Contains("600460")==true){ process_name = "ggF HH #lambda = 10 had-had channel"; }

  // ggF processes lep-had channel
  if(name_sample.Contains("600461")==true){ process_name = "ggF HH SM lep-had channel"; }
  if(name_sample.Contains("600462")==true){ process_name = "ggF HH #lambda = 10 lep-had channel"; }

  //vbf processes had-had channel
  if(name_sample.Contains("502982")==true){ process_name = "VBF HH SM had-had channel"; }
  if(name_sample.Contains("502985")==true){ process_name = "VBF HH C_{VV} = 1.5 had-had channel"; }
  if(name_sample.Contains("502989")==true){ process_name = "VBF HH #lambda = 2.0 had-had channel"; }
  if(name_sample.Contains("502990")==true){ process_name = "VBF HH #lambda = 10.0 had-had channel"; }
  if(name_sample.Contains("502991")==true){ process_name = "VBF HH C_{V} = 0.5 had-had channel"; }
  if(name_sample.Contains("508690")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 had-had channel"; }

  //vbf processes lep-had channel
  if(name_sample.Contains("502993")==true){ process_name = "VBF HH SM lep-had channel"; }
  if(name_sample.Contains("502996")==true){ process_name = "VBF HH C_{VV} = 1.5 lep-had channel"; }
  if(name_sample.Contains("503000")==true){ process_name = "VBF HH #lambda = 2.0 lep-had channel"; }
  if(name_sample.Contains("503001")==true){ process_name = "VBF HH #lambda = 10.0 lep-had channel"; }
  if(name_sample.Contains("503002")==true){ process_name = "VBF HH C_{V} = 0.5 lep-had channel"; }
  if(name_sample.Contains("508691")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 lep-had channel"; }
  
}

void plot_ratios_acceptance_group(TString name_plot, TString output_folder){

  TLegend *leg = new TLegend(0.15, 0.60, 0.30, 0.80);

  TString name_image = output_folder+"/plots_ratios/"+name_plot+".png";

  TH1F *hist_ratio_class0_r1 = (TH1F*)hist_acceptance_mHH_numerator_class0->Clone("hist_ratio_class0_r1");
  TH1F *hist_ratio_class1_r1 = (TH1F*)hist_acceptance_mHH_numerator_class1->Clone("hist_ratio_class1_r1");
  TH1F *hist_ratio_class2_r1 = (TH1F*)hist_acceptance_mHH_numerator_class2->Clone("hist_ratio_class2_r1");
  TH1F *hist_ratio_class3_r1 = (TH1F*)hist_acceptance_mHH_numerator_class3->Clone("hist_ratio_class3_r1");
    
  hist_ratio_class0_r1->SetStats(0);
  hist_ratio_class0_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class0_r1->SetLineColor(2);

  hist_ratio_class1_r1->SetStats(0);
  hist_ratio_class1_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class1_r1->SetLineColor(3);

  hist_ratio_class2_r1->SetStats(0);
  hist_ratio_class2_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class2_r1->SetLineColor(6);

  hist_ratio_class3_r1->SetStats(0);
  hist_ratio_class3_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class3_r1->SetLineColor(4);
  
  ///// Plotting                                                                                                                              
  TCanvas *can = new TCanvas("can","", 800, 600);
  /*
  hist_ratio_class0_r1->SetMaximum(1.05);
  hist_ratio_class1_r1->SetMaximum(1.05);
  hist_ratio_class2_r1->SetMaximum(1.05);
  hist_ratio_class3_r1->SetMaximum(1.05);
  */
  
  hist_ratio_class0_r1->Draw("H");
  hist_ratio_class1_r1->Draw("sameH");
  hist_ratio_class2_r1->Draw("sameH");
  hist_ratio_class3_r1->Draw("sameH");
 
  //hist_ratio_class3_r1->Draw("H");
  
  leg->AddEntry(hist_ratio_class0_r1, "R_{bb}-R_{#tau#tau}", "l");
  leg->AddEntry(hist_ratio_class1_r1, "R_{bb}-B_{#tau#tau}", "l");
  leg->AddEntry(hist_ratio_class2_r1, "B_{bb}-R_{#tau#tau}", "l");
  leg->AddEntry(hist_ratio_class3_r1, "B_{bb}-B_{#tau#tau}", "l");

  leg->SetBorderSize();
  leg->Draw();

  can->Draw();
  can->Print(name_image);
  
}

void acceptance_mHH_variable(){

  if(bbtt_HH_vis_m > 0){
    hist_acceptance_mHH_denominator->Fill(truth_HH_m/1000.);
  }

  if(class_event != -1){
    if(class_event == 0){
      hist_acceptance_mHH_denominator_class0->Fill(truth_HH_m/1000.);
    }
    if(class_event == 1){
      hist_acceptance_mHH_denominator_class1->Fill(truth_HH_m/1000.);
    }
    if(class_event == 2){
      hist_acceptance_mHH_denominator_class2->Fill(truth_HH_m/1000.);
    }
    if(class_event == 3){
      hist_acceptance_mHH_denominator_class3->Fill(truth_HH_m/1000.);
    }
  }
  
  if( (bbtt_HH_vis_m > 0) && (class_event != -1)){

    //cout << class_event << "\t \t" << bbtt_HH_m/1000. << "\t \t" << truth_HH_m/1000. << endl;
    if(class_event == 0){
      hist_acceptance_mHH_numerator_class0->Fill(truth_HH_m/1000.);
    } // RbbRtautau
    if(class_event == 1){
      hist_acceptance_mHH_numerator_class1->Fill(truth_HH_m/1000.);
    } // RbbBtautau
    if(class_event == 2){
      hist_acceptance_mHH_numerator_class2->Fill(truth_HH_m/1000.);
    } // BbbRtautau
    if(class_event == 3){
      hist_acceptance_mHH_numerator_class3->Fill(truth_HH_m/1000.);
    } // BbbBtautau
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
void fill_histograms(){

  //**********************************************
  // Filling truth objects histograms
  //**********************************************
  
  if(truth_children_fromH1_pdgId->size() == 2){
    if((TMath::Abs(truth_children_fromH1_pdgId->at(0)) == 5) && (TMath::Abs(truth_children_fromH1_pdgId->at(1)) == 5)){
      float sum = truth_children_fromH1_m->at(0) + truth_children_fromH1_m->at(1); // Wrong assumption, we need to do it by using a TLorentzV
      hist_truth_b1_plus_b2_m->Fill(sum);
      hist_truth_b1_m->Fill(truth_children_fromH1_m->at(0));
      hist_truth_b2_m->Fill(truth_children_fromH1_m->at(1));
    }
  }

  //**********************************************
  // Filling the mass, pT and eta distributions of the boosted bb and tautau objects
  //**********************************************
 
  if(class_event != -1){

    // truth Boosted bb                                                                                                                     
    if( (class_event == 2) || (class_event == 3) ){

      float dR_bb = 0;
      deltaR(dR_bb, truth_b1_pt, truth_b1_eta, truth_b1_phi, truth_b1_m, truth_b2_pt, truth_b2_eta, truth_b2_phi, truth_b2_m);
      
      hist_matched_recojet_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_bb_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_bb_eta->Fill(recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin));
      hist_matched_recojet_bb_dR->Fill(dR_bb);
      hist2d_dR_per_class_bb->Fill(class_event, dR_bb);
    }

    // truth boosted tautau jets                                                                                                            
    if( (class_event == 1) || (class_event == 3) ){

      float dR_tautau = 0;
      deltaR(dR_tautau, truth_tau1_pt, truth_tau1_eta, truth_tau1_phi, truth_tau1_m, truth_tau2_pt, truth_tau2_eta, truth_tau2_phi, truth_tau2_m);

      hist_matched_recojet_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_tautau_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000.);
      hist_matched_recojet_tautau_eta->Fill(recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin));
      hist_matched_recojet_tautau_dR->Fill(dR_tautau);
      hist2d_dR_per_class_tautau->Fill(class_event, dR_tautau);
    }

    // Fill the pt and eta distribution of those recojets that were not matched to a truth object but are in RR, RB, BR or BB classes
    if( recojet_antikt10UFO_NOSYS_pt->size() > 0 ){
      for(int jj=0; jj < recojet_antikt10UFO_NOSYS_pt->size(); jj++){
	if( (jj != idx_b1truth_recoak10_dRmin) && (jj != idx_b2truth_recoak10_dRmin) && (jj != idx_tau1truth_recoak10_dRmin) && (jj != idx_tau2truth_recoak10_dRmin) ){
	  hist_non_matched_recojet_pt->Fill(recojet_antikt10UFO_NOSYS_pt->at(jj)/1000.);
	}
      }
    }

    if( recojet_antikt10UFO_eta->size() > 0){
      for(int jj=0; jj < recojet_antikt10UFO_eta->size(); jj++){
	if( (jj != idx_b1truth_recoak10_dRmin) && (jj != idx_b2truth_recoak10_dRmin) && (jj != idx_tau1truth_recoak10_dRmin) && (jj != idx_tau2truth_recoak10_dRmin) ){
	  hist_non_matched_recojet_eta->Fill(recojet_antikt10UFO_eta->at(jj));
	}
      } 
    }
  }

  // Fill the pt and eta distribution of those recojets that were not matched to a truth object and are not in RR, RB, BR or BB classes
  if( class_event == -1){
    if( recojet_antikt10UFO_NOSYS_pt->size() > 0 ){
      for(int jj=0; jj < recojet_antikt10UFO_NOSYS_pt->size(); jj++){
	hist_non_matched_recojet_pt_no_class->Fill(recojet_antikt10UFO_NOSYS_pt->at(jj)/1000.);
      }
    }

    if( recojet_antikt10UFO_eta->size() > 0){
      for(int jj=0; jj < recojet_antikt10UFO_eta->size(); jj++){
	hist_non_matched_recojet_eta_no_class->Fill(recojet_antikt10UFO_eta->at(jj));
      }
    }
  }

  // Fill the number of events per class
  hist_nevents_per_class->Fill(class_event);

  // Fill the pT and mass distribution for truth and computed HH

  TLorentzVector b1 = TLorentzVector();
  TLorentzVector b2 = TLorentzVector();
  TLorentzVector tau1 = TLorentzVector();
  TLorentzVector tau2 = TLorentzVector();
  TLorentzVector HH = TLorentzVector();
 
  b1.SetPtEtaPhiM(truth_b1_pt/1000., truth_b1_eta, truth_b1_phi, truth_b1_m/1000.);
  b2.SetPtEtaPhiM(truth_b2_pt/1000., truth_b2_eta, truth_b2_phi, truth_b2_m/1000.);
  tau1.SetPtEtaPhiM(truth_tau1_pt/1000., truth_tau1_eta, truth_tau1_phi, truth_tau1_m/1000.);
  tau2.SetPtEtaPhiM(truth_tau2_pt/1000., truth_tau2_eta, truth_tau2_phi, truth_tau2_m/1000.);

  HH = b1 + b2 + tau1 + tau2;

  hist_truth_HH_pt->Fill(truth_HH_pt/1000.);
  hist_computed_HH_pt->Fill(HH.Pt()); // This value is already given in GeV

  hist_truth_HH_m->Fill(truth_HH_m/1000.);
  hist_computed_HH_m->Fill(HH.M()); // This value is already given in GeV
  
}

// This function saves the branches info for a given tree in the variables defined above
void set_branch_address_inTree(TTree *inTree){

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

  inTree->SetBranchAddress("truth_HH_pt", &truth_HH_pt, &b_truth_HH_pt);
  inTree->SetBranchAddress("truth_HH_eta", &truth_HH_eta, &b_truth_HH_eta);
  inTree->SetBranchAddress("truth_HH_phi", &truth_HH_phi, &b_truth_HH_phi);
  inTree->SetBranchAddress("truth_HH_m", &truth_HH_m, &b_truth_HH_m);
  
  inTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt, &b_recojet_antikt10UFO_NOSYS_pt);
  inTree->SetBranchAddress("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta, &b_recojet_antikt10UFO_eta);
  inTree->SetBranchAddress("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi, &b_recojet_antikt10UFO_phi);
  inTree->SetBranchAddress("recojet_antikt10UFO_m", &recojet_antikt10UFO_m, &b_recojet_antikt10UFO_m);
    
  inTree->SetBranchAddress("bbtt_Jet_b1_pt_NOSYS", &bbtt_Jet_b1_pt_NOSYS, &b_bbtt_Jet_b1_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Jet_b1_eta", &bbtt_Jet_b1_eta, &b_bbtt_Jet_b1_eta);
  inTree->SetBranchAddress("bbtt_Jet_b1_phi", &bbtt_Jet_b1_phi, &b_bbtt_Jet_b1_phi);
  inTree->SetBranchAddress("bbtt_Jet_b1_E", &bbtt_Jet_b1_E, &b_bbtt_Jet_b1_E);

  inTree->SetBranchAddress("bbtt_Jet_b2_pt_NOSYS", &bbtt_Jet_b2_pt_NOSYS, &b_bbtt_Jet_b2_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Jet_b2_eta", &bbtt_Jet_b2_eta, &b_bbtt_Jet_b2_eta);
  inTree->SetBranchAddress("bbtt_Jet_b2_phi", &bbtt_Jet_b2_phi, &b_bbtt_Jet_b2_phi);
  inTree->SetBranchAddress("bbtt_Jet_b2_E", &bbtt_Jet_b2_E, &b_bbtt_Jet_b2_E);

  inTree->SetBranchAddress("bbtt_Tau1_pt_NOSYS", &bbtt_Tau1_pt_NOSYS, &b_bbtt_Tau1_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Tau1_eta", &bbtt_Tau1_eta, &b_bbtt_Tau1_eta);
  inTree->SetBranchAddress("bbtt_Tau1_phi", &bbtt_Tau1_phi, &b_bbtt_Tau1_phi);
  inTree->SetBranchAddress("bbtt_Tau1_E", &bbtt_Tau1_E, &b_bbtt_Tau1_E);
  
  inTree->SetBranchAddress("bbtt_Tau2_pt_NOSYS", &bbtt_Tau2_pt_NOSYS, &b_bbtt_Tau2_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_Tau2_eta", &bbtt_Tau2_eta, &b_bbtt_Tau2_eta);
  inTree->SetBranchAddress("bbtt_Tau2_phi", &bbtt_Tau2_phi, &b_bbtt_Tau2_phi);
  inTree->SetBranchAddress("bbtt_Tau2_E", &bbtt_Tau2_E, &b_bbtt_Tau2_E);
  
  inTree->SetBranchAddress("bbtt_HH_pt_NOSYS", &bbtt_HH_pt_NOSYS, &b_bbtt_HH_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_HH_eta", &bbtt_HH_eta, &b_bbtt_HH_eta);
  inTree->SetBranchAddress("bbtt_HH_phi", &bbtt_HH_phi, &b_bbtt_HH_phi);
  inTree->SetBranchAddress("bbtt_HH_m", &bbtt_HH_m, &b_bbtt_HH_m);

  inTree->SetBranchAddress("bbtt_HH_vis_pt_NOSYS", &bbtt_HH_vis_pt_NOSYS, &b_bbtt_HH_vis_pt_NOSYS);
  inTree->SetBranchAddress("bbtt_HH_vis_m", &bbtt_HH_vis_m, &b_bbtt_HH_vis_m);
  
  inTree->SetBranchAddress("generatorWeight_NOSYS", &generatorWeight_NOSYS, &b_generatorWeight_NOSYS);
  inTree->SetBranchAddress("recojet_antikt4PFlow_NOSYS_passesOR", &recojet_antikt4PFlow_NOSYS_passesOR, &b_recojet_antikt4PFlow_NOSYS_passesOR);
  
}

void define_output_branches(TTree *outTree){

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

  outTree->Branch("truth_HH_pt", &truth_HH_pt);
  outTree->Branch("truth_HH_eta", &truth_HH_eta);
  outTree->Branch("truth_HH_phi", &truth_HH_phi);
  outTree->Branch("truth_HH_m", &truth_HH_m);

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

  outTree->Branch("bbtt_Jet_b1_pt_NOSYS_Resolved_Selection", &bbtt_Jet_b1_pt_NOSYS);
  outTree->Branch("bbtt_Jet_b1_eta_Resolved_Selection", &bbtt_Jet_b1_eta);
  outTree->Branch("bbtt_Jet_b1_phi_Resolved_Selection", &bbtt_Jet_b1_phi);
  outTree->Branch("bbtt_Jet_b1_E_Resolved_Selection", &bbtt_Jet_b1_E);

  outTree->Branch("bbtt_Jet_b2_pt_NOSYS_Resolved_Selection", &bbtt_Jet_b2_pt_NOSYS);
  outTree->Branch("bbtt_Jet_b2_eta_Resolved_Selection", &bbtt_Jet_b2_eta);
  outTree->Branch("bbtt_Jet_b2_phi_Resolved_Selection", &bbtt_Jet_b2_phi);
  outTree->Branch("bbtt_Jet_b2_E_Resolved_Selection", &bbtt_Jet_b2_E);

  outTree->Branch("bbtt_Tau1_pt_NOSYS_Resolved_Selection", &bbtt_Tau1_pt_NOSYS);
  outTree->Branch("bbtt_Tau1_eta_Resolved_Selection", &bbtt_Tau1_eta);
  outTree->Branch("bbtt_Tau1_phi_Resolved_Selection", &bbtt_Tau1_phi);
  outTree->Branch("bbtt_Tau1_E_Resolved_Selection", &bbtt_Tau1_E);
  
  outTree->Branch("bbtt_Tau2_pt_NOSYS_Resolved_Selection", &bbtt_Tau2_pt_NOSYS);
  outTree->Branch("bbtt_Tau2_eta_Resolved_Selection", &bbtt_Tau2_eta);
  outTree->Branch("bbtt_Tau2_phi_Resolved_Selection", &bbtt_Tau2_phi);
  outTree->Branch("bbtt_Tau2_E_Resolved_Selection", &bbtt_Tau2_E);
  
  outTree->Branch("bbtt_HH_pt_NOSYS_Resolved_Selection", &bbtt_HH_pt_NOSYS);
  outTree->Branch("bbtt_HH_eta_Resolved_Selection", &bbtt_HH_eta);
  outTree->Branch("bbtt_HH_phi_Resolved_Selection", &bbtt_HH_phi);
  outTree->Branch("bbtt_HH_m_Resolved_Selection", &bbtt_HH_m);

  outTree->Branch("bbtt_HH_vis_pt_NOSYS", &bbtt_HH_vis_pt_NOSYS);
  outTree->Branch("bbtt_HH_vis_m", &bbtt_HH_vis_m);
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
