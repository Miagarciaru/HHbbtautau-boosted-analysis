#include "Plotting_substructure_jets_variables.h"

void Plotting_substructure_jets_variables(string sample, string output_folder, string minpT){
  /*
  std::vector<string> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m", "matched_recojets_bb_pt", "matched_recojets_tautau_pt", "matched_recojets_bb_eta", "matched_recojets_tautau_eta", "non_matched_recojets_pt", "non_matched_recojets_eta", "non_matched_recojets_pt_no_class", "non_matched_recojets_eta_no_class", "events_per_class", "matched_bb_dR", "matched_tautau_dR"};
  */

  std::vector<string> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m", "matched_recojets_bb_pt", "matched_recojets_tautau_pt", "matched_recojets_bb_eta", "matched_recojets_tautau_eta", "matched_preselected_bb_m", "matched_preselected_tautau_m", "matched_preselected_bb_pt", "matched_preselected_tautau_pt", "matched_preselected_bb_eta", "matched_preselected_tautau_eta"};

  std::vector<string> list_comparisons = {"bb_tau_nProng", "tautau_tau_nProng", "bb_n1_subjettiness", "tautau_n1_subjettiness", "bb_n2_subjettiness", "tautau_n2_subjettiness", "bb_n2_over_n1_subjettiness", "tautau_n2_over_n1_subjettiness", "bb_GN2X_phbb", "tautau_GN2X_phbb", "bb_GN2X_pqcd", "tautau_GN2X_pqcd"};

  process_label(sample);

  cout << "------------------------------------" << endl;
  cout << "process name: " << process_name << endl;
  cout << "name output root file: " << name_output_root_file << endl;
  cout << "------------------------------------" << endl;

  //std::vector<string> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m"};
  
  reading_distributions_histograms(sample, list_of_histograms, list_comparisons, output_folder, minpT);

}
