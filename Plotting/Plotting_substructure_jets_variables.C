#include "Plotting_substructure_jets_variables.h"

void Plotting_substructure_jets_variables(string sample, string output_folder, string minpT){

  std::vector<string> list_of_histograms = {"recojet_bb_m", "recojet_bb_pt", "recojet_bb_eta", "recojet_bb_phi", "recojet_bb_tau_n_prong", "recojet_bb_tau_n1_subjettiness", "recojet_bb_tau_n2_subjettiness", "recojet_bb_tau_n3_subjettiness", "recojet_bb_tau_n2_over_n1_subjettiness", "recojet_bb_ak10_GN2Xv01_phbb", "recojet_bb_ak10_GN2Xv01_pqcd", "recojet_bb_ak10_GN2Xv01_phcc", "recojet_bb_ak10_GN2Xv01_ptop", "recojet_bb_ak10_ECF1", "recojet_bb_ak10_ECF2", "recojet_bb_ak10_ECF3", "recojet_bb_ak10_Split12", "recojet_bb_ak10_Split23", "recojet_bb_ak10_passesOR",
    "recojet_tautau_m", "recojet_tautau_pt", "recojet_tautau_eta", "recojet_tautau_phi", "recojet_tautau_tau_n_prong", "recojet_tautau_tau_n1_subjettiness", "recojet_tautau_tau_n2_subjettiness", "recojet_tautau_tau_n3_subjettiness", "recojet_tautau_tau_n2_over_n1_subjettiness", "recojet_tautau_ak10_GN2Xv01_phbb", "recojet_tautau_ak10_GN2Xv01_pqcd", "recojet_tautau_ak10_GN2Xv01_phcc", "recojet_tautau_ak10_GN2Xv01_ptop", "recojet_tautau_ak10_ECF1", "recojet_tautau_ak10_ECF2", "recojet_tautau_ak10_ECF3", "recojet_tautau_ak10_Split12", "recojet_tautau_ak10_Split23", "recojet_tautau_ak10_passesOR",
    "preselected_bb_m", "preselected_bb_pt", "preselected_bb_eta", "preselected_bb_phi", "preselected_bb_tau_n2_over_n1_subjettiness", "preselected_bb_ak10_GN2Xv01_phbb",
    "preselected_tautau_m", "preselected_tautau_pt", "preselected_tautau_eta", "preselected_tautau_phi", "preselected_tautau_tau_n2_over_n1_subjettiness", "preselected_tautau_ak10_GN2Xv01_phbb"
  };

  std::vector<string> comparison_list = {"recojet_bb_m", "recojet_bb_pt", "recojet_bb_eta", "recojet_bb_phi", "recojet_bb_tau_n_prong", "recojet_bb_tau_n1_subjettiness", "recojet_bb_tau_n2_subjettiness", "recojet_bb_tau_n3_subjettiness", "recojet_bb_tau_n2_over_n1_subjettiness", "recojet_bb_ak10_GN2Xv01_phbb", "recojet_bb_ak10_GN2Xv01_pqcd", "recojet_bb_ak10_GN2Xv01_phcc", "recojet_bb_ak10_GN2Xv01_ptop", "recojet_bb_ak10_ECF1", "recojet_bb_ak10_ECF2", "recojet_bb_ak10_ECF3", "recojet_bb_ak10_Split12", "recojet_bb_ak10_Split23", "recojet_bb_ak10_passesOR",
    "recojet_tautau_m", "recojet_tautau_pt", "recojet_tautau_eta", "recojet_tautau_phi", "recojet_tautau_tau_n_prong", "recojet_tautau_tau_n1_subjettiness", "recojet_tautau_tau_n2_subjettiness", "recojet_tautau_tau_n3_subjettiness", "recojet_tautau_tau_n2_over_n1_subjettiness", "recojet_tautau_ak10_GN2Xv01_phbb", "recojet_tautau_ak10_GN2Xv01_pqcd", "recojet_tautau_ak10_GN2Xv01_phcc", "recojet_tautau_ak10_GN2Xv01_ptop", "recojet_tautau_ak10_ECF1", "recojet_tautau_ak10_ECF2", "recojet_tautau_ak10_ECF3", "recojet_tautau_ak10_Split12", "recojet_tautau_ak10_Split23", "recojet_tautau_ak10_passesOR"};
  

  // Define the unordered map

  std::unordered_map<std::string, std::vector<TH1F>> comparison_distributions_histograms;
  std::unordered_map<std::string, TH1F> distributions_histograms;
  
  process_label(sample);

  cout << "------------------------------------" << endl;
  cout << "process name: " << process_name << endl;
  cout << "name output root file: " << name_output_root_file << endl;
  cout << "------------------------------------" << endl;

  reading_distributions_histograms(sample, list_of_histograms, comparison_list, output_folder, distributions_histograms, comparison_distributions_histograms, minpT);

  plot_distributions_comparisons(comparison_distributions_histograms, output_folder, minpT);

  plot_distributions(distributions_histograms, output_folder, minpT);

}
