// *************************************
// Declaration of leaf variables
// *************************************

// Declaration of leaf types for boosted tree
Float_t boosted_bbtt_H_vis_tautau_pt_NOSYS;
Float_t boosted_bbtt_H_vis_tautau_m;
Float_t boosted_bbtt_H_bb_pt_NOSYS;
Float_t boosted_bbtt_H_bb_m;

// Declaration of leaf types for resolved tree
Float_t resolved_bbtt_H_vis_tautau_pt_NOSYS;
Float_t resolved_bbtt_H_vis_tautau_m;
Float_t resolved_bbtt_H_bb_pt_NOSYS;
Float_t resolved_bbtt_H_bb_m;

// *************************************
// Declaration of branches
// *************************************

// Declaration of branches for boosted tree
TBranch *b_boosted_bbtt_H_vis_tautau_pt_NOSYS;
TBranch *b_boosted_bbtt_H_vis_tautau_m;
TBranch *b_boosted_bbtt_H_bb_pt_NOSYS;
TBranch *b_boosted_bbtt_H_bb_m;

// Declaration of branches for resolved tree
TBranch *b_resolved_bbtt_H_vis_tautau_pt_NOSYS;
TBranch *b_resolved_bbtt_H_vis_tautau_m;
TBranch *b_resolved_bbtt_H_bb_pt_NOSYS;
TBranch *b_resolved_bbtt_H_bb_m;


// Declaration of histograms for boosted variables
TH1F *hist_mH_tautau_boosted = new TH1F("hist_mH_tautau_boosted", "; m_{#tau #tau} [GeV];Events / bin", 100, 0, 500);
TH1F *hist_mH_bb_boosted = new TH1F("hist_mH_bb_boosted", "$m_{bb}$ [GeV];Events / bin", 100, 0, 500);

// Declaration of histograms for resolved variables
TH1F *hist_mH_tautau_resolved = new TH1F("hist_mH_tautau_resolved", " ; m_{#tau #tau} [GeV];Events / bin", 100, 0, 500);

// *************************************
// Declaration of some functions
// *************************************

void plot_distributions(TTree* boosted_tree, TTree* resolved_tree);
void set_branch_address(TTree* boosted_tree, TTree* resolved_tree);
void print_list_of_branches(TTree* tree);
void find_branches_names(TTree* tree, TString name_config, TString word);


// This functions plots some distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void plot_distributions(TTree* boosted_tree, TTree* resolved_tree){

  Int_t b_entries = boosted_tree->GetEntries();
  Int_t r_entries = resolved_tree->GetEntries();
  int nbytes = 0;
  
  for(int ii=0; ii < b_entries; ii++){

    nbytes = boosted_tree->GetEntry(ii);
    hist_mH_tautau_boosted->Fill(boosted_bbtt_H_vis_tautau_m/1000.);
  }

  for(int ii=0; ii < r_entries; ii++){
    
    nbytes = resolved_tree->GetEntry(ii);
    hist_mH_tautau_resolved->Fill(resolved_bbtt_H_vis_tautau_m/1000.);
  }

  TLegend *leg = new TLegend(0.55, 0.70, 0.90, 0.82);

  //hist_mH_tautau_boosted->SetMarkerStyle(20);
  //hist_mH_tautau_boosted->SetMarkerColor(kBlack);
  hist_mH_tautau_boosted->SetStats(0);
  hist_mH_tautau_boosted->SetFillStyle(3001);
  hist_mH_tautau_boosted->SetFillColorAlpha(kBlue, 0.45);
  hist_mH_tautau_boosted->SetLineColor(4);
  hist_mH_tautau_boosted->SetTitle("Mass m_{#tau #tau} comparison between boosted and resolved processes");
  
  //hist_mH_tautau_resolved->SetMarkerStyle(20);
  //hist_mH_tautau_resolved->SetMarkerColor(kBlack);
  hist_mH_tautau_resolved->SetStats(0);
  hist_mH_tautau_resolved->SetFillStyle(3003);
  hist_mH_tautau_resolved->SetFillColorAlpha(kRed, 0.45);
  hist_mH_tautau_resolved->SetLineColor(2);
  hist_mH_tautau_resolved->SetTitle("Mass m_{#tau #tau} comparison between boosted and resolved processes");

  ///// Plotting
  TCanvas *can = new TCanvas("can","", 600, 800);

  hist_mH_tautau_boosted->Draw("H");
  hist_mH_tautau_resolved->Draw("sameH");
  
  leg->AddEntry(hist_mH_tautau_boosted, "m_{HH} for the boosted process", "l");
  leg->AddEntry(hist_mH_tautau_resolved,"m_{HH} for the resolved process","l");
  leg->SetBorderSize();
  leg->Draw();
  
  can->Draw();
}


// This function saves the branches info for a given tree in the variables defined above
void set_branch_address(TTree* boosted_tree, TTree* resolved_tree){

  boosted_tree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &boosted_bbtt_H_vis_tautau_pt_NOSYS, &b_boosted_bbtt_H_vis_tautau_pt_NOSYS);
  boosted_tree->SetBranchAddress("bbtt_H_vis_tautau_m", &boosted_bbtt_H_vis_tautau_m, &b_boosted_bbtt_H_vis_tautau_m);
  boosted_tree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &boosted_bbtt_H_bb_pt_NOSYS, &b_boosted_bbtt_H_bb_pt_NOSYS);
  boosted_tree->SetBranchAddress("bbtt_H_bb_m", &boosted_bbtt_H_bb_m, &b_boosted_bbtt_H_bb_m);
  

  resolved_tree->SetBranchAddress("bbtt_H_vis_tautau_pt_NOSYS", &resolved_bbtt_H_vis_tautau_pt_NOSYS, &b_resolved_bbtt_H_vis_tautau_pt_NOSYS);
  resolved_tree->SetBranchAddress("bbtt_H_vis_tautau_m", &resolved_bbtt_H_vis_tautau_m, &b_resolved_bbtt_H_vis_tautau_m);
  resolved_tree->SetBranchAddress("bbtt_H_bb_pt_NOSYS", &resolved_bbtt_H_bb_pt_NOSYS, &b_resolved_bbtt_H_bb_pt_NOSYS);
  resolved_tree->SetBranchAddress("bbtt_H_bb_m", &resolved_bbtt_H_bb_m, &b_resolved_bbtt_H_bb_m);
}


// This function prints the list of branches of a given tree
void print_list_of_branches(TTree* tree){

  cout << "The number of entries is: " << tree->GetEntries() << endl;
  cout << "The list of branches is shown below:"  << endl;

  for(int ii = 0; ii < tree->GetListOfBranches()->GetEntries(); ii++){
    cout << ii << "\t" << tree->GetListOfBranches()->At(ii)->GetName() << endl;  
  }
  
}

// This function prints the branches of a tree that contain an specific word, and it would be useful to find the branches
// that contain some info related with some objects
void find_branches_names(TTree* tree, TString name_config, TString word){

  cout << "The list of branches that contain the word " << word << " for the " << name_config << " configuration are:"  << endl;
  
  for(int ii = 0; ii < tree->GetListOfBranches()->GetEntries(); ii++){
    
    bool find_word = false;
    TString name_branch = tree->GetListOfBranches()->At(ii)->GetName();
    
    if(name_branch.Contains(word)==true){
      find_word=true;
    }
    
    if(find_word==true){
      cout << ii << "\t" << tree->GetListOfBranches()->At(ii)->GetName() << '\n';  
    }
  }

}
