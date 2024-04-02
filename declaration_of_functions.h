#include "declaration_of_variables.h"

// *************************************
// Declaration of functions
// *************************************

//void plot_distributions(TString name_plot);

void define_output_branches();
void define_classes();
void compute_dR_min_index_fat_jets();
void compute_dR_min(int &idx, float &dR_min, float truth_pt, float truth_eta, float truth_phi, float truth_m);
void deltaR(float &dR, float jet1_pt, float jet1_eta, float jet1_phi, float jet1_m, float jet2_pt, float jet2_eta, float jet2_phi, float jet2_m);
void plot_distributions(TString name_plot);
void define_truth_tau_and_b_jets();
void fill_histograms();
void set_branch_address();
void print_list_of_branches(TTree* tree);

// *************************************
// Definition of the functions declared above
// *************************************


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

  */

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
