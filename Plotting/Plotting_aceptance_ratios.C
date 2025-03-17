#include "Plotting_aceptance_ratios.h"

void Plotting_aceptance_ratios(string nameVar, string min_pT){

  // Sample files
  /*
  std::vector<string> sample_files = {"ggF_lambda10_hh_600460", "ggF_lambda10_lh_600462", "ggF_SM_hh_600459", "ggF_SM_lh_600461", "VBF_cvv1p5_hh_502985", "VBF_cvv1p5_lh_502996", "VBF_SM_hh_502982", "VBF_SM_lh_502993"};
  */
  std::vector<string> sample_files = {"ggF_lambda10_hh_600460", "ggF_lambda10_lh_600462", "ggF_SM_hh_600459", "ggF_SM_lh_600461"};

  // Define the unordered map
  std::unordered_map<std::string, std::vector<TEfficiency>> efficiency_map_proper_ratios;
  std::unordered_map<std::string, std::vector<TEfficiency>> efficiency_map_only_boosted_ratios;

  bool proper = true;

  // Proper ratios
  initializeMapRatiosInfo(sample_files, nameVar, min_pT, efficiency_map_proper_ratios, proper);

  plotEfficiencies(sample_files, "r1" , nameVar, min_pT, efficiency_map_proper_ratios, proper);
  plotEfficiencies(sample_files, "r2" , nameVar, min_pT, efficiency_map_proper_ratios, proper);
  plotEfficiencies(sample_files, "r3" , nameVar, min_pT, efficiency_map_proper_ratios, proper);
  plotEfficiencies(sample_files, "r4" , nameVar, min_pT, efficiency_map_proper_ratios, proper);
  
  // Only boosted ratios
  /*
  proper = false;
  
  initializeMapRatiosInfo(sample_files, nameVar, min_pT, efficiency_map_only_boosted_ratios, proper);

  plotEfficiencies(sample_files, "r1" , nameVar, min_pT, efficiency_map_only_boosted_ratios, proper);
  plotEfficiencies(sample_files, "r2" , nameVar, min_pT, efficiency_map_only_boosted_ratios, proper);
  plotEfficiencies(sample_files, "r3" , nameVar, min_pT, efficiency_map_only_boosted_ratios, proper);
  plotEfficiencies(sample_files, "r4" , nameVar, min_pT, efficiency_map_only_boosted_ratios, proper);
  */
}
