#include "Plotting_comparison_substructure_jets_variables.h"

void Plotting_comparison_substructure_jets_variables(string nameVar){

  // Sample files
  /*
  std::vector<string> sample_files = {"ggF_lambda10_hh_600460", "ggF_lambda10_lh_600462", "ggF_SM_hh_600459", "ggF_SM_lh_600461", "VBF_cvv1p5_hh_502985", "VBF_cvv1p5_lh_502996", "VBF_SM_hh_502982", "VBF_SM_lh_502993"};
  */
  std::vector<string> sample_files = {"ggF_lambda10_hh_600460", "ggF_lambda10_lh_600462", "ggF_SM_hh_600459", "ggF_SM_lh_600461"};

  std::vector<string> min_pT_values = {"100", "200", "300"};

  // Define the unordered map
  std::unordered_map<std::string, std::vector<TH1F>> distribution_histograms;
 
  bool matched_objects = true;

  // Histograms distributions
  initializeHistogramsDistributionsInfo(sample_files, nameVar, min_pT_values, distribution_histograms, matched_objects);

  for(const auto& min_pT : min_pT_values){
    plotDistributionsComparisons(sample_files, nameVar, min_pT, distribution_histograms);
  }
  
}
