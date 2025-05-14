#include "Plotting_VBF_ggF_distributions.h"

void Plotting_VBF_ggF_distributions(){
  
  string sample_BDT_output_path = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/comparison_boosted_resolved_easyjet/output_analysis/BDT_output.root";

  TFile* file_sample_BDT_output = TFile::Open(sample_BDT_output_path.c_str());
  TTree* BDT_output_root = (TTree*) file_sample_BDT_output->Get("AnalysisMiniTree");

  double bdt_score;
  int process_type_like;
  
  TBranch *b_bdt_score;
  TBranch *b_process_type_like;
    
  BDT_output_root->SetBranchAddress("bdt_score", &bdt_score, &b_bdt_score);
  BDT_output_root->SetBranchAddress("process_type_like", &process_type_like, &b_process_type_like);
  
  Int_t nentries = BDT_output_root->GetEntries();
  int nbytes = 0;

  for(int ii=0; ii<nentries; ii++){
    nbytes = BDT_output_root->GetEntry(ii);
    if(process_type_like == 0){
      hist_boosted_bdt_score_separation_ggF->Fill(bdt_score);
    }
    else{
      hist_boosted_bdt_score_separation_VBF->Fill(bdt_score);
    }
  }
  
  std::vector<string> comparison_list = {"jet12_m", "jet12_pt", "jet12_deta", "jet12_phi", "jet12_dR", "jet12_Zeppenfeld_Hbb",
    "jet12_Zeppenfeld_Htautau", "jet12_Zeppenfeld_jet12", "BDT_score"};

  // Define the unordered map

  std::unordered_map<std::string, std::vector<TH1F>> distributions_histograms;
  
  //process_label(sample);

  reading_distributions_histograms(comparison_list, distributions_histograms);

  plot_distributions_comparisons(distributions_histograms);
  
}
