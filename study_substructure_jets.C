void study_substructure_jets(){

  // Path of the merged samples
  
  TString path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_";
  TString name_config="boosted";
  path+=name_config;
  path+="_config.root";

  TFile* inFile = TFile::Open(path);

  // Access the input tree
  TTree *inTree = (TTree*) inFile->Get("AnalysisMiniTree");

  int nentries = inTree->GetEntries();
  cout << "nentries: " << nentries << endl;


  for(int ii = 0; ii < inTree->GetListOfBranches()->GetEntries(); ii++){
    cout << ii << "\t" << inTree->GetListOfBranches()->At(ii)->GetName() << '\n';  
  }

  cout << "The list of branches that contains the flag passesOR for the " << name_config << " configuration are:"  << endl;
  
  for(int ii = 0; ii < inTree->GetListOfBranches()->GetEntries(); ii++){

    bool find_passOR_flag = false;
    TString name_branch = inTree->GetListOfBranches()->At(ii)->GetName();

    if(name_branch.Contains("passesOR")==true){
      find_passOR_flag=true;
    }

    if(find_passOR_flag==true){
      cout << ii << "\t" << inTree->GetListOfBranches()->At(ii)->GetName() << '\n';  
    }
  }

  cout << "The list of branches that contains the word tau for the " << name_config << " configuration are:"  << endl;
  
  for(int ii = 0; ii < inTree->GetListOfBranches()->GetEntries(); ii++){

    bool find_word = false;
    TString name_branch = inTree->GetListOfBranches()->At(ii)->GetName();

    if(name_branch.Contains("tau")==true){
      find_word=true;
    }

    if(find_word==true){
      cout << ii << "\t" << inTree->GetListOfBranches()->At(ii)->GetName() << '\n';  
    }
  }

 
  cout << "The list of branches that contains the word jet for the " << name_config << " configuration are:"  << endl;
  
  for(int ii = 0; ii < inTree->GetListOfBranches()->GetEntries(); ii++){

    bool find_word = false;
    TString name_branch = inTree->GetListOfBranches()->At(ii)->GetName();

    if(name_branch.Contains("jet")==true){
      find_word=true;
    }

    if(find_word==true){
      cout << ii << "\t" << inTree->GetListOfBranches()->At(ii)->GetName() << '\n';  
    }
  }
}
