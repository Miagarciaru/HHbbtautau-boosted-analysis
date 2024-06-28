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

void getTEfficiency(const std::vector<std::string>& sampleFiles, const std::vector<std::string>& variables,
                    std::unordered_map<TString, hist_ratios>& map_ratios_info,
                    std::unordered_map<TString, std::unordered_map<TString, plot_Teff>>& map_Teff_ratios);

void plotEfficiencies(const std::string& ratio, const std::vector<string>& nameTEff, const std::vector<TEfficiency*>& TEff_ratios);

//void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, 
//                           std::unordered_map<std::string, std::unordered_map<string, hist_ratios>>& map_ratios_info);


void plotEfficiencies(const std::string& ratio, const std::vector<string>& nameTEff, const std::vector<TEfficiency*>& TEff_ratios){

  SetAtlasStyle();
  
  TCanvas* canvas = new TCanvas();
  TLegend* leg = new TLegend(0.18, 0.75, 0.93, 0.90);

  //int color = 1;

  std::vector<TEfficiency*> TEff_list;
  const int colors[8] = { kRed, kBlue, kGreen, kMagenta, kCyan, kYellow, kBlack, kOrange };
  
  for(int ii=0; ii<8; ii++){
    TEff_list.push_back(TEff_ratios.at(ii));
    //TEff_list->SetFillColor(colors[ii]);
    //TEff_list->SetLineColor(colors[ii]);
    TEff_list.at(ii)->SetMarkerStyle(20);
    TEff_list.at(ii)->SetMarkerColor(colors[ii]);
    leg->AddEntry(TEff_list.at(ii), (nameTEff.at(ii)+"_"+ratio).c_str(), "lep");
    if(ii==0){
      TEff_list.at(ii)->Draw("AP");
    }
    else{
      TEff_list.at(ii)->Draw("PSAME");
    }
  }
  /*
  TEfficiency *pEff_r1 = TEff_ratios.at(0);
  TEfficiency *pEff_r2 = TEff_ratios.at(1);
  TEfficiency *pEff_r3 = TEff_ratios.at(2);
  TEfficiency *pEff_r4 = TEff_ratios.at(3);
  TEfficiency *pEff_r5 = TEff_ratios.at(4);
  TEfficiency *pEff_r6 = TEff_ratios.at(5);
  TEfficiency *pEff_r7 = TEff_ratios.at(6);
  TEfficiency *pEff_r8 = TEff_ratios.at(7);
  */
  
  gPad->Update();
  auto graph = TEff_list.at(0)->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.40);
      
  gPad->Update();
  leg->SetNColumns(3);
  leg->SetFillStyle(0);
  leg->SetLineColor(0);
  
  leg->Draw();
  canvas->SaveAs("output_plots/mHH_ratios_r1_comparison.png");
}

// Initialize the map_ratios_info
void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::vector<string>& nameVar, std::vector<string>& nameTEff, std::vector<TEfficiency*>& TEff_ratios_r1, std::vector<TEfficiency*>& TEff_ratios_r2){
  string path_folder="/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/analysis/Analysis/study_substructure_jets/output_analysis/";
  
  for (const auto& sample : sampleFiles){
    string path_root_file = path_folder+sample+".root";
      
    TFile* file = TFile::Open(path_root_file.c_str());
    //TCanvas* canvas = new TCanvas();
    
    if (!file || file->IsZombie()) {
      std::cerr << "Error opening file: " << sample << std::endl;
      if (file) file->Close();
      continue;
    }
    else{
      cout << "The file has been read " << sample << endl;
    }

    for(const auto& variable : nameVar){
      //std::unordered_map<std::string, hist_ratios*> sample_ratios;

      //string name_Teff = sample+"_TEff_"+variable;
      string name_Teff = sample;
      
      TH1F* hist_num = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_numerator_class3"));
      TH1F* hist_den_for_r1 = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_denominator"));
      TH1F* hist_den_for_r2 = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_denominator_class3"));

      TEfficiency *pEff_r1 = new TEfficiency(*hist_num, *hist_den_for_r1);
      TEfficiency *pEff_r2 = new TEfficiency(*hist_num, *hist_den_for_r2);

      TEff_ratios_r1.push_back(pEff_r1);
      TEff_ratios_r2.push_back(pEff_r2);
      nameTEff.push_back(name_Teff);
    }
    
    file->Close();
  }
}
