#include <TMath.h>
// *************************************
// Reading the input files
// *************************************

// Path of the merged samples                                                                                                               

//TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/outputfiles-easyjet-march21-2024/mc20_13TeV_502985_vbf_hadhad_l1cvv1 \
p5cv1_PHYS_merged_";

TString path="../run/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_";
TString path_sample=path+"boosted_bypass_config.root";

// Open the input files and access to the trees                                                                                             

TFile* inFile = TFile::Open(path_sample);
TTree* inTree = (TTree*) inFile->Get("AnalysisMiniTree");

// *************************************
// Declaration of leaf variables
// *************************************


// Declaration of leaf types for truth_children branches for boosted tree variables

// truth childre from Higgs
vector<int> *truth_children_fromH1_pdgId;
vector<int> *truth_children_fromH2_pdgId;
vector<float> *truth_children_fromH1_pt;
vector<float> *truth_children_fromH1_eta;
vector<float> *truth_children_fromH1_phi;
vector<float> *truth_children_fromH1_m;
vector<float> *truth_children_fromH2_pt;
vector<float> *truth_children_fromH2_eta;
vector<float> *truth_children_fromH2_phi;
vector<float> *truth_children_fromH2_m;

// Matching of truth b and tau jets from truth children
Float_t truth_b1_pt;
Float_t truth_b1_eta;
Float_t truth_b1_phi;
Float_t truth_b1_m;

Float_t truth_b2_pt;
Float_t truth_b2_eta;
Float_t truth_b2_phi;
Float_t truth_b2_m;

Float_t truth_tau1_pt;
Float_t truth_tau1_eta;
Float_t truth_tau1_phi;
Float_t truth_tau1_m;

Float_t truth_tau2_pt;
Float_t truth_tau2_eta;
Float_t truth_tau2_phi;
Float_t truth_tau2_m;


// Declaration of leaf types for bbtt_H boosted tree variables
Float_t bbtt_H_vis_tautau_pt_NOSYS;
Float_t bbtt_H_vis_tautau_m;
Float_t bbtt_H_bb_pt_NOSYS;
Float_t bbtt_H_bb_m;
Float_t bbtt_Jet_b1_pt_NOSYS;
Float_t bbtt_Jet_b2_pt_NOSYS;
Float_t generatorWeight_NOSYS;
//vector<char> *tau_NOSYS_passesOR;
vector<char> *recojet_antikt4PFlow_NOSYS_passesOR;

// *************************************
// Declaration of branches
// *************************************


// truth childre from Higgs
TBranch *b_truth_children_fromH1_pdgId;
TBranch *b_truth_children_fromH2_pdgId;
TBranch *b_truth_children_fromH1_pt;
TBranch *b_truth_children_fromH1_eta;
TBranch *b_truth_children_fromH1_phi;
TBranch *b_truth_children_fromH1_m;
TBranch *b_truth_children_fromH2_pt;
TBranch *b_truth_children_fromH2_eta;
TBranch *b_truth_children_fromH2_phi;
TBranch *b_truth_children_fromH2_m;

// Matching of truth b and tau jets from truth children
TBranch *b_truth_b1_pt;
TBranch *b_truth_b1_eta;
TBranch *b_truth_b1_phi;
TBranch *b_truth_b1_m;

TBranch *b_truth_b2_pt;
TBranch *b_truth_b2_eta;
TBranch *b_truth_b2_phi;
TBranch *b_truth_b2_m;

TBranch *b_truth_tau1_pt;
TBranch *b_truth_tau1_eta;
TBranch *b_truth_tau1_phi;
TBranch *b_truth_tau1_m;

TBranch *b_truth_tau2_pt;
TBranch *b_truth_tau2_eta;
TBranch *b_truth_tau2_phi;
TBranch *b_truth_tau2_m;


// Declaration of branches for boosted tree
TBranch *b_bbtt_H_vis_tautau_pt_NOSYS;
TBranch *b_bbtt_H_vis_tautau_m;
TBranch *b_bbtt_H_bb_pt_NOSYS;
TBranch *b_bbtt_H_bb_m;
TBranch *b_bbtt_Jet_b1_pt_NOSYS;
TBranch *b_bbtt_Jet_b2_pt_NOSYS;
TBranch *b_generatorWeight_NOSYS;
//TBranch *b_tau_NOSYS_passesOR;
TBranch *b_recojet_antikt4PFlow_NOSYS_passesOR;


// *************************************
// Declaration of histograms
// *************************************

// Declaration of histograms for truth b-jets variables

TH1F *hist_truth_b1_m = new TH1F("hist_truth_b1_m", "Mass of the truth b1; m(b_1) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b2_m = new TH1F("hist_truth_b2_m", "Mass of the truth b2; m(b_2) [GeV];Events / 5 bins", 100, 0, 5000);
TH1F *hist_truth_b1_plus_b2_m = new TH1F("hist_truth_b1_plus_b2_m", "Mass of the two truth b; m(b_1+b_2) [GeV];Events / 5 bins", 100, 0, 5000);


// *************************************
// Declaration of some functions
// *************************************

//void plot_distributions(TString name_plot);

void random_function(int &sum_type_per_event);
void define_truth_tau_and_b_jets();
void fill_histograms();
void set_branch_address();
void print_list_of_branches(TTree* tree);


void random_function(int &sum_type_per_event){

  sum_type_per_event = TMath::Abs(truth_children_fromH1_pdgId->at(0)) + TMath::Abs(truth_children_fromH1_pdgId->at(1)) + TMath::Abs(truth_children_fromH2_pdgId->at(0)) + TMath::Abs(truth_children_fromH2_pdgId->at(1));
  
}

void define_truth_tau_and_b_jets(){

  int nentries = inTree->GetEntries();
  int nbytes = 0;

  /*
  // Bool to use only those events that have two elements for the truth children decays of the Higgs boson
  bool cond_1 = (truth_children_fromH1_pdgId->size() == 2) && (truth_children_fromH2_pdgId->size() == 2);
  // Bool to see if the H1 and H2 truth decays are combination of bbtautau or tautaubb, only the Higgs can decay in a pair of bb or tautau
  bool cond_2 = true;
  */
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

  TString name_image=name_plot+".png";
  
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
