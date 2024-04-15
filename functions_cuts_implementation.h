#include "variables_cuts_implementation.h"

// *************************************
// Declaration of functions
// *************************************

//void plot_distributions(TString name_plot);

void plot_graphs_for_cuts_on_variables(TString name_plot);
void reset_values();
void applying_HH_cuts();
void mHH_cut(float mHH_cut);
void ptHH_cut(float ptHH_cut);
void compute_ratios_and_fill_graphs(float mHH_cut, float ptHH_cut);
void set_branch_address_outTree();
void print_list_of_branches(TTree* tree);


// *************************************
// Definition of the functions declared above
// *************************************

// Plot the graphs for the cuts on the variables such as mHH, etc

void plot_graphs_for_cuts_on_variables(TString name_plot){

  TCanvas *can = new TCanvas("can","can", 800, 600);
  TGraph *graph0 = new TGraph();
  TGraph *graph1 = new TGraph();
  TGraph *graph2 = new TGraph();
  TGraph *graph3 = new TGraph();

  TString name_image = "output/plots_ratios/";
  name_image+=name_plot+".png";

  TString title_plot = "";
  
  if(name_plot=="massHH_cut_r1"){
    graph0 = graph_mHH_cut_r1_class0;
    graph1 = graph_mHH_cut_r1_class1;
    graph2 = graph_mHH_cut_r1_class2;
    graph3 = graph_mHH_cut_r1_class3;

    title_plot = "Ratios for mass mHH cuts; m(HH) [GeV];ratio value";
    
    graph0->SetTitle(title_plot);
    graph1->SetTitle(title_plot);
    graph2->SetTitle(title_plot);
    graph3->SetTitle(title_plot);
  }

  if(name_plot=="ptHH_cut_r1"){
    graph0 = graph_ptHH_cut_r1_class0;
    graph1 = graph_ptHH_cut_r1_class1;
    graph2 = graph_ptHH_cut_r1_class2;
    graph3 = graph_ptHH_cut_r1_class3;
    
    title_plot = "Ratios for pTHH cuts; p_{T}(HH) [GeV];ratio value";
    
    graph0->SetTitle(title_plot);
    graph1->SetTitle(title_plot);
    graph2->SetTitle(title_plot);
    graph3->SetTitle(title_plot);
  }
    
  //graph0->SetLineWidth(2);
  //graph1->SetLineWidth(2);
  //graph2->SetLineWidth(2);
  graph3->SetLineWidth(2);

  //graph0->SetFillStyle(3001);
  //graph0->SetFillColorAlpha(kBlue, 0.45);

  //graph0->SetLineColor(2);
  //graph1->SetLineColor(3);
  //graph2->SetLineColor(6);
  graph3->SetLineColor(4);


  ///// Plotting                                                                                                                            

  graph3->Draw("apl");
  //graph1->Draw("pl same");
  //graph2->Draw("pl same");
  //graph3->Draw("pl same");
  //graph3->Draw("apl");

  can->Draw();
  can->Print(name_image);

}

void reset_values(){

  // For mass mHH
  evnt_RbbRtautau_passing_mHH_cut_and_RES = 0;
  evnt_RbbBtautau_passing_mHH_cut_and_RES = 0;
  evnt_BbbRtautau_passing_mHH_cut_and_RES = 0;
  evnt_BbbBtautau_passing_mHH_cut_and_RES = 0;
  evnt_passing_RES_and_mHH_cut = 0;
  evnt_RbbRtautau_passing_mHH_cut = 0;
  evnt_RbbBtautau_passing_mHH_cut = 0;
  evnt_BbbRtautau_passing_mHH_cut = 0;
  evnt_BbbBtautau_passing_mHH_cut = 0;
  
  r1_class0_mHH_cut = 0;
  r1_class1_mHH_cut = 0;
  r1_class2_mHH_cut = 0;
  r1_class3_mHH_cut = 0;

  r2_class0_mHH_cut = 0;
  r2_class1_mHH_cut = 0;
  r2_class2_mHH_cut = 0;
  r2_class3_mHH_cut = 0;

  // For mass ptHH
  evnt_RbbRtautau_passing_ptHH_cut_and_RES = 0;
  evnt_RbbBtautau_passing_ptHH_cut_and_RES = 0;
  evnt_BbbRtautau_passing_ptHH_cut_and_RES = 0;
  evnt_BbbBtautau_passing_ptHH_cut_and_RES = 0;
  evnt_passing_RES_and_ptHH_cut = 0;
  evnt_RbbRtautau_passing_ptHH_cut = 0;
  evnt_RbbBtautau_passing_ptHH_cut = 0;
  evnt_BbbRtautau_passing_ptHH_cut = 0;
  evnt_BbbBtautau_passing_ptHH_cut = 0;
  
  r1_class0_ptHH_cut = 0;
  r1_class1_ptHH_cut = 0;
  r1_class2_ptHH_cut = 0;
  r1_class3_ptHH_cut = 0;

  r2_class0_ptHH_cut = 0;
  r2_class1_ptHH_cut = 0;
  r2_class2_ptHH_cut = 0;
  r2_class3_ptHH_cut = 0;

}

void compute_ratios_and_fill_graphs(float mHH_cut, float ptHH_cut){

  // For mass mHH
  r1_class0_mHH_cut = 1.0*evnt_RbbRtautau_passing_mHH_cut_and_RES/evnt_passing_RES_and_mHH_cut;
  r1_class1_mHH_cut = 1.0*evnt_RbbBtautau_passing_mHH_cut_and_RES/evnt_passing_RES_and_mHH_cut;
  r1_class2_mHH_cut = 1.0*evnt_BbbRtautau_passing_mHH_cut_and_RES/evnt_passing_RES_and_mHH_cut;
  r1_class3_mHH_cut = 1.0*evnt_BbbBtautau_passing_mHH_cut_and_RES/evnt_passing_RES_and_mHH_cut;
  
  r2_class0_mHH_cut = 1.0*evnt_RbbRtautau_passing_mHH_cut_and_RES/evnt_RbbRtautau_passing_mHH_cut;
  r2_class1_mHH_cut = 1.0*evnt_RbbBtautau_passing_mHH_cut_and_RES/evnt_RbbBtautau_passing_mHH_cut;
  r2_class2_mHH_cut = 1.0*evnt_BbbRtautau_passing_mHH_cut_and_RES/evnt_BbbRtautau_passing_mHH_cut;
  r2_class3_mHH_cut = 1.0*evnt_BbbBtautau_passing_mHH_cut_and_RES/evnt_BbbBtautau_passing_mHH_cut;

  graph_mHH_cut_r1_class0->AddPoint(mHH_cut, r1_class0_mHH_cut);
  graph_mHH_cut_r1_class1->AddPoint(mHH_cut, r1_class1_mHH_cut);
  graph_mHH_cut_r1_class2->AddPoint(mHH_cut, r1_class2_mHH_cut);
  graph_mHH_cut_r1_class3->AddPoint(mHH_cut, r1_class3_mHH_cut);
  
  graph_mHH_cut_r2_class0->AddPoint(mHH_cut, r2_class0_mHH_cut);
  graph_mHH_cut_r2_class1->AddPoint(mHH_cut, r2_class1_mHH_cut);
  graph_mHH_cut_r2_class2->AddPoint(mHH_cut, r2_class2_mHH_cut);
  graph_mHH_cut_r2_class3->AddPoint(mHH_cut, r2_class3_mHH_cut);

  // For pT ptHH
  r1_class0_ptHH_cut = 1.0*evnt_RbbRtautau_passing_ptHH_cut_and_RES/evnt_passing_RES_and_ptHH_cut;
  r1_class1_ptHH_cut = 1.0*evnt_RbbBtautau_passing_ptHH_cut_and_RES/evnt_passing_RES_and_ptHH_cut;
  r1_class2_ptHH_cut = 1.0*evnt_BbbRtautau_passing_ptHH_cut_and_RES/evnt_passing_RES_and_ptHH_cut;
  r1_class3_ptHH_cut = 1.0*evnt_BbbBtautau_passing_ptHH_cut_and_RES/evnt_passing_RES_and_ptHH_cut;
  
  r2_class0_ptHH_cut = 1.0*evnt_RbbRtautau_passing_ptHH_cut_and_RES/evnt_RbbRtautau_passing_ptHH_cut;
  r2_class1_ptHH_cut = 1.0*evnt_RbbBtautau_passing_ptHH_cut_and_RES/evnt_RbbBtautau_passing_ptHH_cut;
  r2_class2_ptHH_cut = 1.0*evnt_BbbRtautau_passing_ptHH_cut_and_RES/evnt_BbbRtautau_passing_ptHH_cut;
  r2_class3_ptHH_cut = 1.0*evnt_BbbBtautau_passing_ptHH_cut_and_RES/evnt_BbbBtautau_passing_ptHH_cut;

  graph_ptHH_cut_r1_class0->AddPoint(ptHH_cut, r1_class0_ptHH_cut);
  graph_ptHH_cut_r1_class1->AddPoint(ptHH_cut, r1_class1_ptHH_cut);
  graph_ptHH_cut_r1_class2->AddPoint(ptHH_cut, r1_class2_ptHH_cut);
  graph_ptHH_cut_r1_class3->AddPoint(ptHH_cut, r1_class3_ptHH_cut);
  
  graph_ptHH_cut_r2_class0->AddPoint(ptHH_cut, r2_class0_ptHH_cut);
  graph_ptHH_cut_r2_class1->AddPoint(ptHH_cut, r2_class1_ptHH_cut);
  graph_ptHH_cut_r2_class2->AddPoint(ptHH_cut, r2_class2_ptHH_cut);
  graph_ptHH_cut_r2_class3->AddPoint(ptHH_cut, r2_class3_ptHH_cut);

}

void applying_HH_cuts(){

  float steps = 400;
  float max_mHH = 2000;
  float max_ptHH = 1000;
  float dmass = max_mHH/steps;
  float dpt = max_ptHH/steps;
  
  float mHH_cut_value = 0;
  float ptHH_cut_value = 0;
  
  int out_nentries = outTree->GetEntries();
  int out_nbytes = 0;

  //cout << "mHH_cut"  << "\t \t" << "evnt_BbbBtautau_passing_mHH_cut" << "\t \t" << "evnt_passing_RES_and_mHH_cut" << "\t \t" << "ratio r1_class3" << endl;
  cout << "ptHH_cut"  << "\t \t" << "evnt_BbbBtautau_passing_ptHH_cut" << "\t \t" << "evnt_passing_RES_and_ptHH_cut" << "\t \t" << "ratio r1_class3" << endl;
  
  for(int ii=0; ii < steps; ii++){  

    reset_values();
    mHH_cut_value = ii*dmass;
    ptHH_cut_value = ii*dpt;
    
    for(int jj=0; jj<out_nentries; jj++){
      out_nbytes = outTree->GetEntry(jj);
      mHH_cut(mHH_cut_value);
      ptHH_cut(ptHH_cut_value);
    }
    
    compute_ratios_and_fill_graphs(mHH_cut_value, ptHH_cut_value);
    
    if(ii%20==0){
      //cout << mHH_cut_value << "\t \t" << evnt_BbbBtautau_passing_mHH_cut_and_RES << "\t \t" << evnt_passing_RES_and_mHH_cut << "\t \t" << r1_class3_mHH_cut << endl;
      cout << ptHH_cut_value << "\t \t" << evnt_BbbBtautau_passing_ptHH_cut_and_RES << "\t \t" << evnt_passing_RES_and_ptHH_cut << "\t \t" << r1_class3_ptHH_cut << endl;
    }
  }
}

void mHH_cut(float mHH_cut){

  if( (class_event != -1) && (truth_HH_m/1000. > mHH_cut) ){
    if(class_event == 0){ evnt_RbbRtautau_passing_mHH_cut+=1; }
    if(class_event == 1){ evnt_RbbBtautau_passing_mHH_cut+=1; }
    if(class_event == 2){ evnt_BbbRtautau_passing_mHH_cut+=1; }
    if(class_event == 3){ evnt_BbbBtautau_passing_mHH_cut+=1; }
  }

  if( bbtt_HH_m/1000. > 0 ){
    
    if(bbtt_HH_m/1000. > mHH_cut){ evnt_passing_RES_and_mHH_cut+=1; }
    
    if( (class_event != -1) && (truth_HH_m/1000. > mHH_cut) ){ 	
      if(class_event == 0){ evnt_RbbRtautau_passing_mHH_cut_and_RES+=1; }
      if(class_event == 1){ evnt_RbbBtautau_passing_mHH_cut_and_RES+=1; }
      if(class_event == 2){ evnt_BbbRtautau_passing_mHH_cut_and_RES+=1; }
      if(class_event == 3){ evnt_BbbBtautau_passing_mHH_cut_and_RES+=1; }
    }
  }
}


void ptHH_cut(float ptHH_cut){

  if( (class_event != -1) && (truth_HH_pt/1000. > ptHH_cut) ){
    if(class_event == 0){ evnt_RbbRtautau_passing_ptHH_cut+=1; }
    if(class_event == 1){ evnt_RbbBtautau_passing_ptHH_cut+=1; }
    if(class_event == 2){ evnt_BbbRtautau_passing_ptHH_cut+=1; }
    if(class_event == 3){ evnt_BbbBtautau_passing_ptHH_cut+=1; }
  }

  if( bbtt_HH_pt_NOSYS/1000. > 0 ){ 
    if(bbtt_HH_pt_NOSYS/1000. > ptHH_cut){ evnt_passing_RES_and_ptHH_cut+=1; }
    
    if( (class_event != -1) && (truth_HH_pt/1000. > ptHH_cut) ){ 	
      if(class_event == 0){ evnt_RbbRtautau_passing_ptHH_cut_and_RES+=1; }
      if(class_event == 1){ evnt_RbbBtautau_passing_ptHH_cut_and_RES+=1; }
      if(class_event == 2){ evnt_BbbRtautau_passing_ptHH_cut_and_RES+=1; }
      if(class_event == 3){ evnt_BbbBtautau_passing_ptHH_cut_and_RES+=1; }
    }
  }
}

void set_branch_address_outTree(){

  outTree->SetBranchAddress("truth_children_fromH1_pdgId", &truth_children_fromH1_pdgId, &b_truth_children_fromH1_pdgId);
  outTree->SetBranchAddress("truth_children_fromH1_pt", &truth_children_fromH1_pt, &b_truth_children_fromH1_pt);
  outTree->SetBranchAddress("truth_children_fromH1_eta", &truth_children_fromH1_eta, &b_truth_children_fromH1_eta);
  outTree->SetBranchAddress("truth_children_fromH1_phi", &truth_children_fromH1_phi, &b_truth_children_fromH1_phi);
  outTree->SetBranchAddress("truth_children_fromH1_m", &truth_children_fromH1_m, &b_truth_children_fromH1_m);

  outTree->SetBranchAddress("truth_children_fromH2_pdgId", &truth_children_fromH2_pdgId, &b_truth_children_fromH2_pdgId);
  outTree->SetBranchAddress("truth_children_fromH2_pt", &truth_children_fromH2_pt, &b_truth_children_fromH2_pt);
  outTree->SetBranchAddress("truth_children_fromH2_eta", &truth_children_fromH2_eta, &b_truth_children_fromH2_eta);
  outTree->SetBranchAddress("truth_children_fromH2_phi", &truth_children_fromH2_phi, &b_truth_children_fromH2_phi);
  outTree->SetBranchAddress("truth_children_fromH2_m", &truth_children_fromH2_m, &b_truth_children_fromH2_m);

  outTree->SetBranchAddress("truth_HH_pt", &truth_HH_pt, &b_truth_HH_pt);
  outTree->SetBranchAddress("truth_HH_eta", &truth_HH_eta, &b_truth_HH_eta);
  outTree->SetBranchAddress("truth_HH_phi", &truth_HH_phi, &b_truth_HH_phi);
  outTree->SetBranchAddress("truth_HH_m", &truth_HH_m, &b_truth_HH_m);

  outTree->SetBranchAddress("truth_b1_pt", &truth_b1_pt, &b_truth_b1_pt);
  outTree->SetBranchAddress("truth_b1_eta", &truth_b1_eta, &b_truth_b1_eta);
  outTree->SetBranchAddress("truth_b1_phi", &truth_b1_phi, &b_truth_b1_phi);
  outTree->SetBranchAddress("truth_b1_m", &truth_b1_m, &b_truth_b1_m);

  outTree->SetBranchAddress("truth_b2_pt", &truth_b2_pt, &b_truth_b2_pt);
  outTree->SetBranchAddress("truth_b2_eta", &truth_b2_eta, &b_truth_b2_eta);
  outTree->SetBranchAddress("truth_b2_phi", &truth_b2_phi, &b_truth_b2_phi);
  outTree->SetBranchAddress("truth_b2_m", &truth_b2_m, &b_truth_b2_m);

  outTree->SetBranchAddress("truth_tau1_pt", &truth_tau1_pt, &b_truth_tau1_pt);
  outTree->SetBranchAddress("truth_tau1_eta", &truth_tau1_eta, &b_truth_tau1_eta);
  outTree->SetBranchAddress("truth_tau1_phi", &truth_tau1_phi, &b_truth_tau1_phi);
  outTree->SetBranchAddress("truth_tau1_m", &truth_tau1_m, &b_truth_tau1_m);
  
  outTree->SetBranchAddress("truth_tau2_pt", &truth_tau2_pt, &b_truth_tau2_pt);
  outTree->SetBranchAddress("truth_tau2_eta", &truth_tau2_eta, &b_truth_tau2_eta);
  outTree->SetBranchAddress("truth_tau2_phi", &truth_tau2_phi, &b_truth_tau2_phi);
  outTree->SetBranchAddress("truth_tau2_m", &truth_tau2_m, &b_truth_tau2_m);

  outTree->SetBranchAddress("recojet_antikt10UFO_NOSYS_pt", &recojet_antikt10UFO_NOSYS_pt, &b_recojet_antikt10UFO_NOSYS_pt);
  outTree->SetBranchAddress("recojet_antikt10UFO_eta", &recojet_antikt10UFO_eta, &b_recojet_antikt10UFO_eta);
  outTree->SetBranchAddress("recojet_antikt10UFO_phi", &recojet_antikt10UFO_phi, &b_recojet_antikt10UFO_phi);
  outTree->SetBranchAddress("recojet_antikt10UFO_m", &recojet_antikt10UFO_m, &b_recojet_antikt10UFO_m);
  
  outTree->SetBranchAddress("idx_b1truth_recoak10_dRmin", &idx_b1truth_recoak10_dRmin, &b_idx_b1truth_recoak10_dRmin);
  outTree->SetBranchAddress("idx_b2truth_recoak10_dRmin", &idx_b2truth_recoak10_dRmin, &b_idx_b2truth_recoak10_dRmin);
  outTree->SetBranchAddress("idx_tau1truth_recoak10_dRmin", &idx_tau1truth_recoak10_dRmin, &b_idx_tau1truth_recoak10_dRmin);
  outTree->SetBranchAddress("idx_tau2truth_recoak10_dRmin", &idx_tau2truth_recoak10_dRmin, &b_idx_tau2truth_recoak10_dRmin);

  outTree->SetBranchAddress("dR_min_b1truth_recoak10_fatjet", &dR_min_b1truth_recoak10_fatjet, &b_dR_min_b1truth_recoak10_fatjet);
  outTree->SetBranchAddress("dR_min_b2truth_recoak10_fatjet", &dR_min_b2truth_recoak10_fatjet, &b_dR_min_b2truth_recoak10_fatjet);
  outTree->SetBranchAddress("dR_min_tau1truth_recoak10_fatjet", &dR_min_tau1truth_recoak10_fatjet, &b_dR_min_tau1truth_recoak10_fatjet);
  outTree->SetBranchAddress("dR_min_tau2truth_recoak10_fatjet", &dR_min_tau2truth_recoak10_fatjet, &b_dR_min_tau2truth_recoak10_fatjet);

  outTree->SetBranchAddress("class_event", &class_event, &b_class_event);

  outTree->SetBranchAddress("bbtt_Jet_b1_pt_NOSYS_Resolved_Selection", &bbtt_Jet_b1_pt_NOSYS, &b_bbtt_Jet_b1_pt_NOSYS);
  outTree->SetBranchAddress("bbtt_Jet_b1_eta_Resolved_Selection", &bbtt_Jet_b1_eta, &b_bbtt_Jet_b1_eta);
  outTree->SetBranchAddress("bbtt_Jet_b1_phi_Resolved_Selection", &bbtt_Jet_b1_phi, &b_bbtt_Jet_b1_phi);
  outTree->SetBranchAddress("bbtt_Jet_b1_E_Resolved_Selection", &bbtt_Jet_b1_E, &b_bbtt_Jet_b1_E);

  outTree->SetBranchAddress("bbtt_Jet_b2_pt_NOSYS_Resolved_Selection", &bbtt_Jet_b2_pt_NOSYS, &b_bbtt_Jet_b2_pt_NOSYS);
  outTree->SetBranchAddress("bbtt_Jet_b2_eta_Resolved_Selection", &bbtt_Jet_b2_eta, &b_bbtt_Jet_b2_eta);
  outTree->SetBranchAddress("bbtt_Jet_b2_phi_Resolved_Selection", &bbtt_Jet_b2_phi, &b_bbtt_Jet_b2_phi);
  outTree->SetBranchAddress("bbtt_Jet_b2_E_Resolved_Selection", &bbtt_Jet_b2_E, &b_bbtt_Jet_b2_E);

  outTree->SetBranchAddress("bbtt_Tau1_pt_NOSYS_Resolved_Selection", &bbtt_Tau1_pt_NOSYS, &b_bbtt_Tau1_pt_NOSYS);
  outTree->SetBranchAddress("bbtt_Tau1_eta_Resolved_Selection", &bbtt_Tau1_eta, &b_bbtt_Tau1_eta);
  outTree->SetBranchAddress("bbtt_Tau1_phi_Resolved_Selection", &bbtt_Tau1_phi, &b_bbtt_Tau1_phi);
  outTree->SetBranchAddress("bbtt_Tau1_E_Resolved_Selection", &bbtt_Tau1_E, &b_bbtt_Tau1_E);

  outTree->SetBranchAddress("bbtt_Tau2_pt_NOSYS_Resolved_Selection", &bbtt_Tau2_pt_NOSYS, &b_bbtt_Tau2_pt_NOSYS);
  outTree->SetBranchAddress("bbtt_Tau2_eta_Resolved_Selection", &bbtt_Tau2_eta, &b_bbtt_Tau2_eta);
  outTree->SetBranchAddress("bbtt_Tau2_phi_Resolved_Selection", &bbtt_Tau2_phi, &b_bbtt_Tau2_phi);
  outTree->SetBranchAddress("bbtt_Tau2_E_Resolved_Selection", &bbtt_Tau2_E, &b_bbtt_Tau2_E);
  
  outTree->SetBranchAddress("bbtt_HH_pt_NOSYS_Resolved_Selection", &bbtt_HH_pt_NOSYS, &b_bbtt_HH_pt_NOSYS);
  outTree->SetBranchAddress("bbtt_HH_eta_Resolved_Selection", &bbtt_HH_eta, &b_bbtt_HH_eta);
  outTree->SetBranchAddress("bbtt_HH_phi_Resolved_Selection", &bbtt_HH_phi, &b_bbtt_HH_phi);
  outTree->SetBranchAddress("bbtt_HH_m_Resolved_Selection", &bbtt_HH_m, &b_bbtt_HH_m);

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
