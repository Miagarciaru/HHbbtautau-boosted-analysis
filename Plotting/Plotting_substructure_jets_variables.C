#include "Plotting_substructure_jets_variables.h"

void Plotting_substructure_jets_variables(string sample, string output_folder, string minpT){

  std::vector<string> list_of_histograms = {"recojet_bb_m", "recojet_bb_pt", "recojet_bb_eta", "recojet_bb_phi", "recojet_bb_tau_n_prong", "recojet_bb_tau_n1_subjettiness", "recojet_bb_tau_n2_subjettiness", "recojet_bb_tau_n3_subjettiness", "recojet_bb_tau_n2_over_n1_subjettiness", "recojet_bb_ak10_GN2Xv01_phbb", "recojet_bb_ak10_GN2Xv01_pqcd", "recojet_bb_ak10_GN2Xv01_phcc", "recojet_bb_ak10_GN2Xv01_ptop", "recojet_bb_ak10_ECF1", "recojet_bb_ak10_ECF2", "recojet_bb_ak10_ECF3", "recojet_bb_ak10_Split12", "recojet_bb_ak10_Split23", "recojet_bb_ak10_passesOR",
    "recojet_tautau_m", "recojet_tautau_pt", "recojet_tautau_eta", "recojet_tautau_phi", "recojet_tautau_tau_n_prong", "recojet_tautau_tau_n1_subjettiness", "recojet_tautau_tau_n2_subjettiness", "recojet_tautau_tau_n3_subjettiness", "recojet_tautau_tau_n2_over_n1_subjettiness", "recojet_tautau_ak10_GN2Xv01_phbb", "recojet_tautau_ak10_GN2Xv01_pqcd", "recojet_tautau_ak10_GN2Xv01_phcc", "recojet_tautau_ak10_GN2Xv01_ptop", "recojet_tautau_ak10_ECF1", "recojet_tautau_ak10_ECF2", "recojet_tautau_ak10_ECF3", "recojet_tautau_ak10_Split12", "recojet_tautau_ak10_Split23", "recojet_tautau_ak10_passesOR",
    "preselected_bb_m", "preselected_bb_pt", "preselected_bb_eta", "preselected_bb_phi", "preselected_bb_tau_n2_over_n1_subjettiness", "preselected_bb_ak10_GN2Xv01_phbb",
    "preselected_tautau_m", "preselected_tautau_pt", "preselected_tautau_eta", "preselected_tautau_phi", "preselected_tautau_tau_n2_over_n1_subjettiness", "preselected_tautau_ak10_GN2Xv01_phbb"
  };

  std::vector<string> comparison_list = {"recojet_bb_m", "recojet_bb_pt", "recojet_bb_eta", "recojet_bb_phi", 
    "recojet_bb_tau_n_prong", "recojet_bb_tau_n1_subjettiness", "recojet_bb_tau_n2_subjettiness", 
    "recojet_bb_tau_n3_subjettiness", "recojet_bb_tau_n2_over_n1_subjettiness", "recojet_bb_ak10_GN2Xv01_phbb",
    "recojet_bb_ak10_GN2Xv01_pqcd", "recojet_bb_ak10_GN2Xv01_phcc", "recojet_bb_ak10_GN2Xv01_ptop", 
    "recojet_bb_ak10_ECF1", "recojet_bb_ak10_ECF2", "recojet_bb_ak10_ECF3", "recojet_bb_ak10_Split12", 
    "recojet_bb_ak10_Split23", "recojet_bb_ak10_passesOR", "recojet_tautau_m", "recojet_tautau_pt", 
    "recojet_tautau_eta", "recojet_tautau_phi", "recojet_tautau_tau_n_prong", 
    "recojet_tautau_tau_n1_subjettiness", "recojet_tautau_tau_n2_subjettiness", 
    "recojet_tautau_tau_n3_subjettiness", "recojet_tautau_tau_n2_over_n1_subjettiness", 
    "recojet_tautau_ak10_GN2Xv01_phbb", "recojet_tautau_ak10_GN2Xv01_pqcd", "recojet_tautau_ak10_GN2Xv01_phcc",
    "recojet_tautau_ak10_GN2Xv01_ptop", "recojet_tautau_ak10_ECF1", "recojet_tautau_ak10_ECF2", 
    "recojet_tautau_ak10_ECF3", "recojet_tautau_ak10_Split12", "recojet_tautau_ak10_Split23", 
    "recojet_tautau_ak10_passesOR", "recojet_bb_score_bdt_Hbb", "recojet_tautau_score_bdt_Htautau",
    "preselected_bb_m", "preselected_tautau_m", "preselected_bb_score_bdt_Hbb", 
    "preselected_tautau_score_bdt_Htautau"};

  std::vector<string> comparison_list_cpr = {"recojet_bb_m_cpr", "recojet_bb_pt_cpr", "recojet_bb_eta_cpr", "recojet_bb_phi_cpr", "recojet_bb_tau_n2_over_n1_subjettiness_cpr", "recojet_bb_ak10_GN2Xv01_phbb_cpr", "recojet_bb_ak10_GN2Xv01_pqcd_cpr", "recojet_bb_ak10_GN2Xv01_phcc_cpr", "recojet_bb_ak10_GN2Xv01_ptop_cpr", "recojet_bb_ak10_ECF1_cpr", "recojet_bb_ak10_ECF2_cpr", "recojet_bb_ak10_ECF3_cpr", "recojet_bb_ak10_Split12_cpr", "recojet_bb_ak10_Split23_cpr",
    "recojet_tautau_m_cpr", "recojet_tautau_pt_cpr", "recojet_tautau_eta_cpr", "recojet_tautau_phi_cpr", "recojet_tautau_tau_n2_over_n1_subjettiness_cpr", "recojet_tautau_ak10_GN2Xv01_phbb_cpr", "recojet_tautau_ak10_GN2Xv01_pqcd_cpr", "recojet_tautau_ak10_GN2Xv01_phcc_cpr", "recojet_tautau_ak10_GN2Xv01_ptop_cpr", "recojet_tautau_ak10_ECF1_cpr", "recojet_tautau_ak10_ECF2_cpr", "recojet_tautau_ak10_ECF3_cpr", "recojet_tautau_ak10_Split12_cpr", "recojet_tautau_ak10_Split23_cpr", 
    "preselected_bb_m", "preselected_bb_pt", "preselected_bb_eta", "preselected_bb_phi", "preselected_bb_tau_n2_over_n1_subjettiness", "preselected_bb_ak10_GN2Xv01_phbb", "preselected_bb_ak10_GN2Xv01_pqcd", "preselected_bb_ak10_GN2Xv01_phcc", "preselected_bb_ak10_GN2Xv01_ptop", "preselected_bb_ak10_ECF1", "preselected_bb_ak10_ECF2", "preselected_bb_ak10_ECF3", "preselected_bb_ak10_Split12", "preselected_bb_ak10_Split23", 
    "preselected_tautau_m", "preselected_tautau_pt", "preselected_tautau_eta", "preselected_tautau_phi", "preselected_tautau_tau_n2_over_n1_subjettiness", "preselected_tautau_ak10_GN2Xv01_phbb", "preselected_tautau_ak10_GN2Xv01_pqcd", "preselected_tautau_ak10_GN2Xv01_phcc", "preselected_tautau_ak10_GN2Xv01_ptop", "preselected_tautau_ak10_ECF1", "preselected_tautau_ak10_ECF2", "preselected_tautau_ak10_ECF3", "preselected_tautau_ak10_Split12", "preselected_tautau_ak10_Split23"};
  

  // Define the unordered map

  std::unordered_map<std::string, std::vector<TH1F>> comparison_distributions_histograms;
  std::unordered_map<std::string, std::vector<TH1F>> distributions_histograms_cpr;
  std::unordered_map<std::string, TH1F> distributions_histograms;
  
  process_label(sample);

  cout << "------------------------------------" << endl;
  cout << "process name: " << process_name << endl;
  cout << "name output root file: " << name_output_root_file << endl;
  cout << "------------------------------------" << endl;

  reading_distributions_histograms(sample, list_of_histograms, comparison_list, comparison_list_cpr, output_folder, distributions_histograms, comparison_distributions_histograms, distributions_histograms_cpr, minpT);
  
  plot_distributions_comparisons(comparison_distributions_histograms, output_folder, minpT);
  //plot_distributions_comparisons_cpr(distributions_histograms_cpr, output_folder, minpT);

  //plot_distributions(distributions_histograms, output_folder, minpT);

}
