// Declaration of some functions

void print_list_of_branches(TTree* tree);
void find_branches_names(TTree* tree, TString name_config, TString word);


/*
// This functions plots the pT, eta, phi, and other distributions for the H_bb and H_tautau and compare the distributions
// for the two configurations, boosted and resolved
void plot_distributions(TTree* boosted_tree, TTree* resolved_tree){


}
*/

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

  cout << "The list of branches that contains the word " << word << " for the " << name_config << " configuration are:"  << endl;
  
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
