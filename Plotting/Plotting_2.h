#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
#include <unordered_map>
//#include "declaration_of_variables.h"

struct hist_ratios {
  TH1F* hist_num_for_r1;
  TH1F* hist_den_for_r1;
  TH1F* hist_num_for_r2;
  TH1F* hist_den_for_r2;
  std::string label_r1;
  std::string title_r1;
  std::string label_r2;
  std::string title_r2;
};

struct plot_Teff {
  TEfficiency* ratio_r1;
  TEfficiency* ratio_r2;
  std::string label_r1;
  std::string label_r2;
};

//*******************************************************
// Declaration of functions
//*******************************************************

void plotEfficiencies(const std::vector<std::string>& sampleFiles, const std::string& ratio, const std::string& nameVar, const std::vector<TEfficiency*>& TEff_ratios);

void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::string& nameVar, std::vector<TEfficiency*>& TEff_ratios_r1, std::vector<TEfficiency*>& TEff_ratios_r2);

//*******************************************************
// Definition of functions declared above
//*******************************************************

void plotEfficiencies(const std::vector<std::string>& sampleFiles, const std::string& ratio, const std::string& nameVar, const std::vector<TEfficiency*>& TEff_ratios){

  SetAtlasStyle();
  
  TCanvas* canvas = new TCanvas(("can_"+nameVar+"_"+ratio).c_str());
  TLegend* leg = new TLegend(0.18, 0.75, 0.93, 0.90);

  const int colors[8] = { kRed, kBlue, kGreen, kMagenta, kCyan, kYellow, kBlack, kOrange };

  for(int ii=0; ii<8; ii++){
    TEff_ratios.at(ii)->SetMarkerStyle(20);
    TEff_ratios.at(ii)->SetMarkerColor(colors[ii]);
    leg->AddEntry(TEff_ratios.at(ii), (sampleFiles[ii]+"_"+ratio).c_str(), "lep");
    if(ii==0){
      TEff_ratios.at(ii)->Draw("AP");
    }
    else{
      TEff_ratios.at(ii)->Draw("PSAME");
    }
  }
      
  gPad->Update();
  auto graph = TEff_ratios.at(0)->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.40);
      
  gPad->Update();
  leg->SetNColumns(3);
  leg->SetFillStyle(0);
  leg->SetLineColor(0);
  
  leg->Draw();

  string name_image = "output_plots/"+nameVar+"_ratios_"+ratio+"_comparison.png";
  canvas->SaveAs(name_image.c_str());
}

// Initialize the ap_ratios_info
void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::string& nameVar, std::vector<TEfficiency*>& TEff_ratios_r1, std::vector<TEfficiency*>& TEff_ratios_r2){
  
  string path_folder="/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/analysis/Analysis/study_substructure_jets/output_analysis/";
  
  for (const auto& sample : sampleFiles){
    string path_root_file = path_folder+sample+".root";
      
    TFile* file = TFile::Open(path_root_file.c_str());
    
    if (!file || file->IsZombie()) {
      std::cerr << "Error opening file: " << sample << std::endl;
      if (file) file->Close();
      continue;
    }
    else{
      cout << "The file has been read " << sample << endl;
    }

    TH1F* hist_num = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_numerator_class3").c_str()));
    TH1F* hist_den_for_r1 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_denominator").c_str()));
    TH1F* hist_den_for_r2 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_denominator_class3").c_str()));

    TEfficiency *pEff_r1 = new TEfficiency(*hist_num, *hist_den_for_r1);
    TEfficiency *pEff_r2 = new TEfficiency(*hist_num, *hist_den_for_r2);

    TEff_ratios_r1.push_back(pEff_r1);
    TEff_ratios_r2.push_back(pEff_r2);
    
    file->Close();
  }
}
