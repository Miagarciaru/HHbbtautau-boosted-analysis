// *************************************
// Reading the input files
// *************************************

// Path of the merged samples                                                                                                               

TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/";
TString path_boosted_sample=path+"boosted_samples/mc20_13TeV_503002_vbf_lephad_l1cvv1cv0p5_PHYS_merged_boosted_bypass_config.root";
TString path_resolved_sample=path+"resolved_samples/mc20_13TeV_503002_vbf_lephad_l1cvv1cv0p5_PHYS_merged_resolved_bypass_config.root";

// Open the input files and access to the trees                                                                                             

TFile* boosted_inFile = TFile::Open(path_boosted_sample);
TTree* boosted_inTree = (TTree*) boosted_inFile->Get("AnalysisMiniTree");

TFile* resolved_inFile = TFile::Open(path_resolved_sample);
TTree* resolved_inTree = (TTree*) resolved_inFile->Get("AnalysisMiniTree");


// *************************************
// Declaration of leaf variables
// *************************************


// Declaration of leaf types for truth_children branches for boosted tree variables

// Declaration of leaf types for bbtt_H boosted tree variables
Float_t boosted_bbtt_H_vis_tautau_pt_NOSYS;
Float_t boosted_bbtt_H_vis_tautau_m;
Float_t boosted_bbtt_H_bb_pt_NOSYS;
Float_t boosted_bbtt_H_bb_m;
Float_t boosted_bbtt_Jet_b1_pt_NOSYS;
Float_t boosted_bbtt_Jet_b2_pt_NOSYS;
Float_t boosted_generatorWeight_NOSYS;
//vector<char> *boosted_tau_NOSYS_passesOR;
vector<char> *boosted_recojet_antikt4PFlow_NOSYS_passesOR;

// Declaration of leaf types for bbtt_H boosted tree variables
Float_t resolved_bbtt_H_vis_tautau_pt_NOSYS;
Float_t resolved_bbtt_H_vis_tautau_m;
Float_t resolved_bbtt_H_bb_pt_NOSYS;
Float_t resolved_bbtt_H_bb_m;
Float_t resolved_bbtt_Jet_b1_pt_NOSYS;
Float_t resolved_bbtt_Jet_b2_pt_NOSYS;
Float_t resolved_generatorWeight_NOSYS;
//vector<char> *resolved_tau_NOSYS_passesOR;
vector<char> *resolved_recojet_antikt4PFlow_NOSYS_passesOR;


// *************************************
// Declaration of branches
// *************************************

// Declaration of branches for boosted tree
TBranch *b_boosted_bbtt_H_vis_tautau_pt_NOSYS;
TBranch *b_boosted_bbtt_H_vis_tautau_m;
TBranch *b_boosted_bbtt_H_bb_pt_NOSYS;
TBranch *b_boosted_bbtt_H_bb_m;
TBranch *b_boosted_bbtt_Jet_b1_pt_NOSYS;
TBranch *b_boosted_bbtt_Jet_b2_pt_NOSYS;
TBranch *b_boosted_generatorWeight_NOSYS;
//TBranch *b_boosted_tau_NOSYS_passesOR;
TBranch *b_boosted_recojet_antikt4PFlow_NOSYS_passesOR;

// Declaration of branches for resolved tree
TBranch *b_resolved_bbtt_H_vis_tautau_pt_NOSYS;
TBranch *b_resolved_bbtt_H_vis_tautau_m;
TBranch *b_resolved_bbtt_H_bb_pt_NOSYS;
TBranch *b_resolved_bbtt_H_bb_m;
TBranch *b_resolved_bbtt_Jet_b1_pt_NOSYS;
TBranch *b_resolved_bbtt_Jet_b2_pt_NOSYS;
TBranch *b_resolved_generatorWeight_NOSYS;
//TBranch *b_resolved_tau_NOSYS_passesOR;
TBranch *b_resolved_recojet_antikt4PFlow_NOSYS_passesOR;

// *************************************
// Declaration of histograms
// *************************************

// Declaration of histograms for boosted variables
TH1F *hist_tautau_pt_NOSYS_boosted = new TH1F("hist_tautau_pt_NOSYS_boosted", "P_{T}(#tau #tau) comparison between boosted and resolved configurations; p_T(#tau #tau) [GeV];Events / 5 bins", 100, 0, 500);
TH1F *hist_mH_tautau_boosted = new TH1F("hist_mH_tautau_boosted", "Mass m_{#tau #tau} comparison between boosted and resolved configurations; m_{#tau #tau} [GeV];Events / 5 bins", 100, 0, 500);
TH1F *hist_bb_pt_boosted = new TH1F("hist_bb_pt_boosted", "P_{T}(bb) comparison between boosted and resolved configurations; p_T(bb) [GeV];Events / 5 bins", 100, 0, 500);

TH1F *hist_bbtt_Jet_b1_pt_boosted = new TH1F("hist_bbtt_Jet_b1_pt_boosted", "P_{T}(b1) comparison between boosted and resolved configurations; p_T(b1) [GeV];Events / 5 bins", 100, 0, 500);
TH1F *hist_bbtt_Jet_b2_pt_boosted = new TH1F("hist_bbtt_Jet_b2_pt_boosted", "P_{T}(b2) comparison between boosted and resolved configurations; p_T(b2) [GeV];Events / 5 bins", 100, 0, 500);

TH1F *hist_mH_bb_boosted = new TH1F("hist_mH_bb_boosted", "Mass m_{bb} comparison between boosted and resolved configurations; m_{bb} [GeV];Events / 5 bins", 100, 0, 500);
//TH1F *hist_tau_passesOR_boosted = new TH1F("hist_tau_passesOR_boosted", "Comparison of the number of tau objects passing the OR flag", 3, 0, 2);
TH1F *hist_recojet_antikt4_passesOR_boosted = new TH1F("hist_recojet_antikt4_passesOR_boosted", "Comparison of the number of recojet antikt4 objects passing the OR flag", 3, 0, 2);


// Declaration of histograms for resolved variables
TH1F *hist_tautau_pt_NOSYS_resolved = new TH1F("hist_tautau_pt_NOSYS_resolved", "P_{T}(#tau #tau) comparison between boosted and resolved configurations; p_T(#tau #tau) [GeV];Events / 5 bins", 100, 0, 500);
TH1F *hist_mH_tautau_resolved = new TH1F("hist_mH_tautau_resolved", "Mass m_{#tau #tau} comparison between boosted and resolved configurations; m_{#tau #tau} [GeV];Events / 5 bins", 100, 0, 500);
TH1F *hist_bb_pt_resolved = new TH1F("hist_bb_pt_resolved", "P_{T}(bb) comparison between boosted and resolved configurations; m_{bb} [GeV];Events / 5 bins", 100, 0, 500);

TH1F *hist_bbtt_Jet_b1_pt_resolved = new TH1F("hist_bbtt_Jet_b1_pt_resolved", "P_{T}(b1) comparison between boosted and resolved configurations; p_T(b1) [GeV];Events / 5 bins", 100, 0, 500);
TH1F *hist_bbtt_Jet_b2_pt_resolved = new TH1F("hist_bbtt_Jet_b2_pt_resolved", "P_{T}(b2) comparison between boosted and resolved configurations; p_T(b2) [GeV];Events / 5 bins", 100, 0, 500);

TH1F *hist_mH_bb_resolved = new TH1F("hist_mH_bb_resolved", "Mass m_{bb} comparison between boosted and resolved configurations; hist_mH_bb_resolved; $m_{bb}$ [GeV]; Events / 5 bins", 100, 0, 500);
//TH1F *hist_tau_passesOR_resolved = new TH1F("hist_tau_passesOR_resolved", "Comparison of the number of tau objects passing the OR flag", 3, 0, 2);
TH1F *hist_recojet_antikt4_passesOR_resolved = new TH1F("hist_recojet_antikt4_passesOR_resolved", "Comparison of the number of recojet antikt4 objects passing the OR flag", 3, 0, 2);


// *************************************
// Declaration of some functions
// *************************************

void plot_distributions(TString name_plot);
void fill_histograms();
void set_branch_address();
void print_list_of_branches(TTree* tree);
void print_names_and_types_branches_containing_a_word(TString word);
void find_branches_names(TString word);
void print_some_values();

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void plot_distributions(TString name_plot){

  TLegend *leg = new TLegend(0.7, 0.75, 0.85, 0.85);
  TH1F *hist_boosted = new TH1F();
  TH1F *hist_resolved = new TH1F();
  TString name_image = "plots_comparison/";
  name_image+=name_plot+".png";
  
  if(name_plot=="tautau_m"){
    hist_boosted = hist_mH_tautau_boosted;
    hist_resolved = hist_mH_tautau_resolved;
  }

  if(name_plot=="bb_m"){
    hist_boosted = hist_mH_bb_boosted;
    hist_resolved = hist_mH_bb_resolved;
  }
  if(name_plot=="tautau_pT"){
    hist_boosted = hist_tautau_pt_NOSYS_boosted;
    hist_resolved = hist_tautau_pt_NOSYS_resolved;
  }
  if(name_plot=="bb_pT"){
    hist_boosted = hist_bb_pt_boosted;
    hist_resolved = hist_bb_pt_resolved;
  }
  /*
  if(name_plot=="tau_passesOR"){
    hist_boosted = hist_tau_passesOR_boosted;
    hist_resolved = hist_tau_passesOR_resolved;
  }
  */
  if(name_plot=="recojet_antikt4_passesOR"){
    hist_boosted = hist_recojet_antikt4_passesOR_boosted;
    hist_resolved = hist_recojet_antikt4_passesOR_resolved;
  }
  if(name_plot=="bbtt_Jet_b1_pt"){
    hist_boosted = hist_bbtt_Jet_b1_pt_boosted;
    hist_resolved = hist_bbtt_Jet_b1_pt_resolved;
  }
  if(name_plot=="bbtt_Jet_b2_pt"){
    hist_boosted = hist_bbtt_Jet_b2_pt_boosted;
    hist_resolved = hist_bbtt_Jet_b2_pt_resolved;
  }
  hist_boosted->SetStats(0);
  hist_boosted->SetFillStyle(3001);
  hist_boosted->SetFillColorAlpha(kBlue, 0.45);
  hist_boosted->SetLineColor(4);
  
  hist_resolved->SetStats(0);
  hist_resolved->SetFillStyle(3003);
  hist_resolved->SetFillColorAlpha(kRed, 0.45);
  hist_resolved->SetLineColor(2);
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);

  hist_boosted->Draw("H");
  hist_resolved->Draw("sameH");
  
  leg->AddEntry(hist_boosted, "boosted", "l");
  leg->AddEntry(hist_resolved,"resolved","l");
  leg->SetBorderSize();
  leg->Draw();
  
  can->Draw();
  can->SaveAs(name_image);
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void fill_histograms(){

  Int_t b_entries = boosted_inTree->GetEntries();
  Int_t r_entries = resolved_inTree->GetEntries();
  int nbytes = 0;
  
  for(int ii = 0; ii < b_entries; ii++){
    
    nbytes = boosted_inTree->GetEntry(ii);

    if(boosted_bbtt_H_vis_tautau_pt_NOSYS > 0){
      hist_tautau_pt_NOSYS_boosted->Fill(boosted_bbtt_H_vis_tautau_pt_NOSYS/1000.);
      // hist_tautau_pt_NOSYS_boosted->Fill(boosted_bbtt_H_vis_tautau_pt_NOSYS/1000., boosted_generatorWeight_NOSYS);
    }
    if(boosted_bbtt_H_vis_tautau_m > 0){
      hist_mH_tautau_boosted->Fill(boosted_bbtt_H_vis_tautau_m/1000.);
    }
    hist_bb_pt_boosted->Fill(boosted_bbtt_H_bb_pt_NOSYS/1000.);
    //hist_bb_pt_boosted->Fill(boosted_bbtt_H_bb_pt_NOSYS/1000., boosted_generatorWeight_NOSYS);
    hist_bbtt_Jet_b1_pt_boosted->Fill(boosted_bbtt_Jet_b1_pt_NOSYS/1000.);
    hist_bbtt_Jet_b2_pt_boosted->Fill(boosted_bbtt_Jet_b2_pt_NOSYS/1000.);
 
    hist_mH_bb_boosted->Fill(boosted_bbtt_H_bb_m/1000.);
    
    /*
    if(boosted_tau_NOSYS_passesOR->size() > 0){
      for(int jj=0; jj < boosted_tau_NOSYS_passesOR->size(); jj++){
	hist_tau_passesOR_boosted->Fill(boosted_tau_NOSYS_passesOR->at(jj));	  
      }
    }
    */
    if(boosted_recojet_antikt4PFlow_NOSYS_passesOR->size() > 0){
      for(int jj=0; jj < boosted_recojet_antikt4PFlow_NOSYS_passesOR->size(); jj++){
        hist_recojet_antikt4_passesOR_boosted->Fill(boosted_recojet_antikt4PFlow_NOSYS_passesOR->at(jj));	  
      }
    }
    
  }
  
  for(int ii=0; ii < r_entries; ii++){
    nbytes = resolved_inTree->GetEntry(ii);

    if(resolved_bbtt_H_vis_tautau_pt_NOSYS > 0){
      hist_tautau_pt_NOSYS_resolved->Fill(resolved_bbtt_H_vis_tautau_pt_NOSYS/1000.);
      // hist_tautau_pt_NOSYS_resolved->Fill(resolved_bbtt_H_vis_tautau_pt_NOSYS/1000., resolved_generatorWeight_NOSYS);
    }
    if(resolved_bbtt_H_vis_tautau_m > 0){
      hist_mH_tautau_resolved->Fill(resolved_bbtt_H_vis_tautau_m/1000.);
    }
    hist_bb_pt_resolved->Fill(resolved_bbtt_H_bb_pt_NOSYS/1000.);
    // hist_bb_pt_resolved->Fill(resolved_bbtt_H_bb_pt_NOSYS/1000., resolved_generatorWeight_NOSYS);

    hist_bbtt_Jet_b1_pt_resolved->Fill(resolved_bbtt_Jet_b1_pt_NOSYS/1000.);
    hist_bbtt_Jet_b2_pt_resolved->Fill(resolved_bbtt_Jet_b2_pt_NOSYS/1000.);

    hist_mH_bb_resolved->Fill(resolved_bbtt_H_bb_m/1000.);
    /*
    if(resolved_tau_NOSYS_passesOR->size() > 0){
      for(int jj=0; jj < resolved_tau_NOSYS_passesOR->size(); jj++){
	hist_tau_passesOR_resolved->Fill(resolved_tau_NOSYS_passesOR->at(jj));	  
      }
    }
    */
    if(resolved_recojet_antikt4PFlow_NOSYS_passesOR->size() > 0){
      for(int jj=0; jj < resolved_recojet_antikt4PFlow_NOSYS_passesOR->size(); jj++){
        hist_recojet_antikt4_passesOR_resolved->Fill(resolved_recojet_antikt4PFlow_NOSYS_passesOR->at(jj));	  
      }
    }
  }
}


// This function saves the branches info for a given tree in the variables defined above
void set_branch_address(){

  boosted_inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &boosted_bbtt_H_vis_tautau_pt_NOSYS, &b_boosted_bbtt_H_vis_tautau_pt_NOSYS);
  boosted_inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &boosted_bbtt_H_vis_tautau_m, &b_boosted_bbtt_H_vis_tautau_m);
  boosted_inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &boosted_bbtt_H_bb_pt_NOSYS, &b_boosted_bbtt_H_bb_pt_NOSYS);
  
  boosted_inTree->SetBranchAddress("bbtt_Jet_b1_pt_NOSYS", &boosted_bbtt_Jet_b1_pt_NOSYS, &b_boosted_bbtt_Jet_b1_pt_NOSYS);
  boosted_inTree->SetBranchAddress("bbtt_Jet_b2_pt_NOSYS", &boosted_bbtt_Jet_b2_pt_NOSYS, &b_boosted_bbtt_Jet_b2_pt_NOSYS);
  
  boosted_inTree->SetBranchAddress("bbtt_H_bb_m", &boosted_bbtt_H_bb_m, &b_boosted_bbtt_H_bb_m);
  boosted_inTree->SetBranchAddress("generatorWeight_NOSYS", &boosted_generatorWeight_NOSYS, &b_boosted_generatorWeight_NOSYS);
  //boosted_inTree->SetBranchAddress("tau_NOSYS_passesOR", &boosted_tau_NOSYS_passesOR, &b_boosted_tau_NOSYS_passesOR);
  boosted_inTree->SetBranchAddress("recojet_antikt4PFlow_NOSYS_passesOR", &boosted_recojet_antikt4PFlow_NOSYS_passesOR, &b_boosted_recojet_antikt4PFlow_NOSYS_passesOR);

  
  resolved_inTree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &resolved_bbtt_H_vis_tautau_pt_NOSYS, &b_resolved_bbtt_H_vis_tautau_pt_NOSYS);
  resolved_inTree->SetBranchAddress("bbtt_H_vis_tautau_m", &resolved_bbtt_H_vis_tautau_m, &b_resolved_bbtt_H_vis_tautau_m);
  resolved_inTree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &resolved_bbtt_H_bb_pt_NOSYS, &b_resolved_bbtt_H_bb_pt_NOSYS);

  resolved_inTree->SetBranchAddress("bbtt_Jet_b1_pt_NOSYS", &resolved_bbtt_Jet_b1_pt_NOSYS, &b_resolved_bbtt_Jet_b1_pt_NOSYS);
  resolved_inTree->SetBranchAddress("bbtt_Jet_b2_pt_NOSYS", &resolved_bbtt_Jet_b2_pt_NOSYS, &b_resolved_bbtt_Jet_b2_pt_NOSYS);
  
  resolved_inTree->SetBranchAddress("bbtt_H_bb_m", &resolved_bbtt_H_bb_m, &b_resolved_bbtt_H_bb_m);
  resolved_inTree->SetBranchAddress("generatorWeight_NOSYS", &resolved_generatorWeight_NOSYS, &b_resolved_generatorWeight_NOSYS);
  //resolved_inTree->SetBranchAddress("tau_NOSYS_passesOR", &resolved_tau_NOSYS_passesOR, &b_resolved_tau_NOSYS_passesOR);
  resolved_inTree->SetBranchAddress("recojet_antikt4PFlow_NOSYS_passesOR", &resolved_recojet_antikt4PFlow_NOSYS_passesOR, &b_resolved_recojet_antikt4PFlow_NOSYS_passesOR);
  
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



// This function prints the list of branches of a tree and their types that contain a specific word, and it would be useful to find
// the branches that contain some info related with some objects
void print_names_and_types_branches_containing_a_word(TString word){

  // Get the list of branches
  TObjArray *b_branchList = boosted_inTree->GetListOfBranches();
  cout << "The list of branches that contain the word " << word << " for the boosted configuration are:"  << endl;
  for(int ii = 0; ii < b_branchList->GetEntries(); ii++){
    TBranch *branch = dynamic_cast<TBranch*>(b_branchList->At(ii));
    TString name_branch = branch->GetName();
    if(name_branch.Contains(word)==true){
      cout << ii << "\t Branch: " << branch->GetName() << "\t Type: " << branch->GetClassName() << endl;  
    }
  } 
}

// This function prints the branches of a tree that contain an specific word, and it would be useful to find the branches
// that contain some info related with some objects
void find_branches_names(TString word){

  cout << "The list of branches that contain the word " << word << " for the boosted configuration are:"  << endl;
  for(int ii = 0; ii < boosted_inTree->GetListOfBranches()->GetEntries(); ii++){
    TString name_branch = boosted_inTree->GetListOfBranches()->At(ii)->GetName();
    if(name_branch.Contains(word)==true){
      cout << ii << "\t" << boosted_inTree->GetListOfBranches()->At(ii)->GetName() << endl;  
    }
  }
  
  cout << "The list of branches that contain the word " << word << " for the resolved configuration are:"  << endl;
  for(int ii = 0; ii < resolved_inTree->GetListOfBranches()->GetEntries(); ii++){
    TString name_branch = resolved_inTree->GetListOfBranches()->At(ii)->GetName();
    if(name_branch.Contains(word)==true){
      cout << ii << "\t" << resolved_inTree->GetListOfBranches()->At(ii)->GetName() << endl;  
    }
  }
}

// This function prints some values for some needed info, i.e, number of negative values, 0, etc for each tree to compare if those
// trees for boosted and resolved configs keep the same number of entries for some branches
void print_some_values(){

  Int_t b_entries = boosted_inTree->GetEntries();
  Int_t r_entries = resolved_inTree->GetEntries();
  int b_nbytes = 0;
  int r_nbytes = 0;
  int boosted_mbb_neg_values = 0;
  int resolved_mbb_neg_values = 0;
  int boosted_bbpT_neg_values = 0;
  int resolved_bbpT_neg_values = 0;
  int boosted_mtautau_zero_values = 0;
  int resolved_mtautau_zero_values = 0;
  int boosted_mtautau_neg_values = 0;
  int resolved_mtautau_neg_values = 0;

  
  for(int ii=0; ii < b_entries; ii++){
    b_nbytes = boosted_inTree->GetEntry(ii);
    if(boosted_bbtt_H_bb_m < 0){
      boosted_mbb_neg_values += 1;
    }
    if(boosted_bbtt_H_bb_pt_NOSYS < 0){
      boosted_bbpT_neg_values += 1;
    }
    if(boosted_bbtt_H_vis_tautau_m == 0){
      boosted_mtautau_zero_values += 1;
    }
    if(boosted_bbtt_H_vis_tautau_m < 0){
      boosted_mtautau_neg_values += 1;
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
    if(resolved_bbtt_H_vis_tautau_m == 0){
      resolved_mtautau_zero_values += 1;
    }
    if(resolved_bbtt_H_vis_tautau_m < 0){
      resolved_mtautau_neg_values += 1;
    }
  }
  cout << "The number of entries for mbb that are negative for boosted and resolved cases are respectively:"  << endl;
  cout << boosted_mbb_neg_values << "\t" << resolved_mbb_neg_values << endl;
  cout << "The number of entries for bbpT that are negative for boosted and resolved cases are respectively:"  << endl;
  cout << boosted_bbpT_neg_values << "\t" << resolved_bbpT_neg_values << endl;
  cout << "The number of entries for m_tautau that are equal to zero for boosted and resolved cases are respectively:"  << endl;
  cout << boosted_mtautau_zero_values << "\t" << resolved_mtautau_zero_values << endl;
  cout << "The number of entries for m_tautau that are negative for boosted and resolved cases are respectively:"  << endl;
  cout << boosted_mtautau_neg_values << "\t" << resolved_mtautau_neg_values << endl;
}
