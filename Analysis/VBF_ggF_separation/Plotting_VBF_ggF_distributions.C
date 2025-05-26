#include "Plotting_VBF_ggF_distributions.h"

void Plotting_VBF_ggF_distributions(){
  
  string sample_BDT_output_path = "output_analysis/BDT_output.root";

  cout << sample_BDT_output_path << endl;
  
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

  int n_ggF_events_BDT_cut = 0;
  int n_VBF_events_BDT_cut = 0;

  int n_ggF_events_entries = 0;
  int n_VBF_events_entries = 0;
  
  for(int ii=0; ii<nentries; ii++){
    nbytes = BDT_output_root->GetEntry(ii);
    if(process_type_like == 0){
      n_ggF_events_entries++;
      hist_boosted_bdt_score_separation_ggF->Fill(bdt_score);
      if( bdt_score > 0.8 ){
	n_ggF_events_BDT_cut++;
      }
    }
    else{
      n_VBF_events_entries++;
      hist_boosted_bdt_score_separation_VBF->Fill(bdt_score);
      if( bdt_score > 0.8 ){
	n_VBF_events_BDT_cut++;
      }
    }
  }

  perc_accepted_ggF_BDT_cut = 100*n_ggF_events_BDT_cut/n_ggF_events_entries;
  perc_accepted_VBF_BDT_cut = 100*n_VBF_events_BDT_cut/n_VBF_events_entries;
  
  //std::vector<string> comparison_list = {"jet12_m", "jet12_pt", "jet12_deta", "jet12_phi", "jet12_dR", "bbtautau_m", "bbtautau_pt", "bbtautau_eta", "bbtautau_phi", "bbtautau_deta" , "bbtautau_dphi", "bbtautau_dR", "bb_jet1_m", "bb_jet1_pt", "bb_jet1_eta", "bb_jet1_phi", "bb_jet1_deta", "bb_jet1_dphi", "bb_jet1_dR", "bb_jet2_m", "bb_jet2_pt", "bb_jet2_eta", "bb_jet2_phi", "bb_jet2_deta", "bb_jet2_dphi", "bb_jet2_dR", "tautau_jet1_m", "tautau_jet1_pt", "tautau_jet1_eta", "tautau_jet1_phi", "tautau_jet1_deta", "tautau_jet1_dphi", "tautau_jet1_dR", "tautau_jet2_m", "tautau_jet2_pt", "tautau_jet2_eta", "tautau_jet2_phi", "tautau_jet2_deta", "tautau_jet2_dphi", "tautau_jet2_dR", "all_jets_m", "all_jets_pt", "all_jets_eta", "all_jets_phi", "all_jets_deta", "all_jets_dphi", "all_jets_dR", "jet12_Zeppenfeld_Hbb", "jet12_Zeppenfeld_Htautau", "jet12_Zeppenfeld_jet12", "BDT_score"};

  std::vector<string> comparison_list = {"all_jets_m", "jet12_m", "bb_jet1_pt", "bbtautau_m", "jet12_dR", "tautau_jet1_deta", "bb_jet2_deta", "bb_jet2_dR", "BDT_score", "njets", "bb_m", "tautau_m", "cutflow_small_jets"}; //"njets"

  // Define the unordered map

  std::unordered_map<std::string, std::vector<TH1F>> distributions_histograms;
  
  //process_label(sample);

  reading_distributions_histograms(comparison_list, distributions_histograms);

  plot_distributions_comparisons(distributions_histograms);
  
}
