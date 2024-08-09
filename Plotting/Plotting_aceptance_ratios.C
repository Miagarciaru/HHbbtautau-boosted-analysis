#include "Plotting_aceptance_ratios.h"

void Plotting_aceptance_ratios(string nameVar){

  // Sample files
  std::vector<string> sample_files = {"ggF_lambda10_hh_600460", "ggF_lambda10_lh_600462", "ggF_SM_hh_600459", "ggF_SM_lh_600461",
    "VBF_cvv1p5_hh_502985", "VBF_cvv1p5_lh_502996", "VBF_SM_hh_502982", "VBF_SM_lh_502993"};

  std::vector<TEfficiency*> TEff_ratios_r1;
  std::vector<TEfficiency*> TEff_ratios_r2;
  std::vector<TEfficiency*> TEff_ratios_r3;
  std::vector<TEfficiency*> TEff_ratios_r4;

  initializeMapRatiosInfo(sample_files, nameVar, TEff_ratios_r1, TEff_ratios_r2, TEff_ratios_r3, TEff_ratios_r4);

  plotEfficiencies(sample_files, "r1", nameVar, TEff_ratios_r1);
  plotEfficiencies(sample_files, "r2", nameVar, TEff_ratios_r2);
  plotEfficiencies(sample_files, "r3", nameVar, TEff_ratios_r3);
  plotEfficiencies(sample_files, "r4", nameVar, TEff_ratios_r4);

}
