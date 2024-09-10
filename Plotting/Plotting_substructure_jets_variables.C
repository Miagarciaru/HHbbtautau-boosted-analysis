#include "Plotting_substructure_jets_variables.h"

void Plotting_substructure_jets_variables(string sample, string output_folder){

  std::vector<string> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m", "matched_recojets_bb_pt", "matched_recojets_tautau_pt", "matched_recojets_bb_eta", "matched_recojets_tautau_eta", "non_matched_recojets_pt", "non_matched_recojets_eta", "non_matched_recojets_pt_no_class", "non_matched_recojets_eta_no_class", "events_per_class", "matched_bb_dR", "matched_tautau_dR"};                        

  process_label(sample);
  
  //std::vector<string> list_of_histograms = {"matched_recojet_bb_m", "matched_recojet_tautau_m"};

  
  reading_distributions_histograms(sample, list_of_histograms, output_folder);

}
