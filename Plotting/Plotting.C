#include "Plotting_2.h"

void Plotting(){
  
  // Sample files
  std::vector<string> sample_files = {"ggF_lambda10_hh_600460", "ggF_lambda10_lh_600462", "ggF_SM_hh_600459", "ggF_SM_lh_600461",
    "VBF_cvv1p5_hh_502985", "VBF_cvv1p5_lh_502996", "VBF_SM_hh_502982", "VBF_SM_lh_502993"};

  // Variables
  //std::vector<std::string> variables = {"mHH", "ptHH", "mHbb", "ptHbb", "mHtautau", "ptHtautau"};
  std::vector<string> variables = {"mHH"};

  std::vector<string> nameTEff;

  std::vector<TEfficiency*> TEff_ratios_r1;
  std::vector<TEfficiency*> TEff_ratios_r2;

  initializeMapRatiosInfo(sample_files, variables, nameTEff, TEff_ratios_r1, TEff_ratios_r2);

  int size = nameTEff.size();

  if( (TEff_ratios_r1.size() != size) || (TEff_ratios_r2.size() != size) ) cout << "sizes are different" << endl;

  for(int ii=0; ii < nameTEff.size(); ii++){  
    cout << nameTEff[ii] << endl;
  }

  plotEfficiencies("r1", nameTEff, TEff_ratios_r1);
  

}
