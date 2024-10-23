#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
#include <unordered_map>

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

void plotEfficiencies(const std::vector<std::string>& sampleFiles, const std::string& ratio, const std::string& nameVar, const std::string& min_pT, const std::vector<TEfficiency*>& TEff_ratios);

void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::string& nameVar, const std::string& min_pT, std::vector<TEfficiency*>& TEff_ratios_r1, std::vector<TEfficiency*>& TEff_ratios_r2, std::vector<TEfficiency*>& TEff_ratios_r3, std::vector<TEfficiency*>& TEff_ratios_r4);

//*******************************************************
// Definition of functions declared above
//*******************************************************

void plotEfficiencies(const std::vector<std::string>& sampleFiles, const std::string& ratio, const std::string& nameVar, const std::string& min_pT, const std::vector<TEfficiency*>& TEff_ratios){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  TCanvas* canvas = new TCanvas(("can_"+nameVar+"_minpT"+min_pT+ratio).c_str());
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

  string name_image = "output_combined_ratios_plots/"+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"_ratios_"+ratio+"_comparison.png";
  canvas->SaveAs(name_image.c_str());
}

// Initialize the ap_ratios_info
void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::string& nameVar, const std::string& min_pT, std::vector<TEfficiency*>& TEff_ratios_r1, std::vector<TEfficiency*>& TEff_ratios_r2, std::vector<TEfficiency*>& TEff_ratios_r3, std::vector<TEfficiency*>& TEff_ratios_r4){
  
  string path_folder="/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis/";
   
  for (const auto& sample : sampleFiles){
    string path_root_file = path_folder+sample+"_pT"+min_pT+"GeV.root";
    TCanvas* can = new TCanvas(("can_"+sample+"_"+nameVar+"_pT"+min_pT+"GeV").c_str());
    
    TFile* file = TFile::Open(path_root_file.c_str());
    
    if (!file || file->IsZombie()) {
      std::cerr << "Error opening file: " << sample << std::endl;
      if (file) file->Close();
      continue;
    }
    else{
      cout << "The file has been read " << sample << endl;
    }
    /*
    TH1F* hist_num_r1_r2 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_numerator_class3_r1_r2").c_str()));
    TH1F* hist_den_for_r1 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_denominator_r1").c_str()));
    TH1F* hist_den_for_r2 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_denominator_class3_r2").c_str()));

    TH1F* hist_num_for_r3 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_numerator_r3").c_str()));
    TH1F* hist_num_for_r4 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_numerator_class3_r4").c_str()));
    TH1F* hist_den_for_r3_r4 = dynamic_cast<TH1F*>(file->Get(("hist_acceptance_"+nameVar+"_denominator_r3_r4").c_str()));
    */

    string name_hist_num_r1_r2 = ""; string name_hist_den_for_r1 = ""; string name_hist_den_for_r2 = "";
    string name_hist_num_for_r3 = ""; string name_hist_num_for_r4 = ""; string name_hist_den_for_r3_r4 = ""; 

    if(nameVar.find("mHH")!=std::string::npos){
      name_hist_num_r1_r2 = "hist_acceptance_"+nameVar+"_numerator_class3_r1_r2";
      name_hist_den_for_r1 = "hist_acceptance_"+nameVar+"_denominator_r1";
      name_hist_den_for_r2 = "hist_acceptance_"+nameVar+"_denominator_class3_r2";
      name_hist_num_for_r3 = "hist_acceptance_"+nameVar+"_numerator_r3";
      name_hist_num_for_r4 = "hist_acceptance_"+nameVar+"_numerator_class3_r4";
      name_hist_den_for_r3_r4 = "hist_acceptance_"+nameVar+"_denominator_r3_r4";
    }
    
    if(nameVar.find("tautau")!=std::string::npos){
      name_hist_num_r1_r2 = "hist_acceptance_all_Btautau_"+nameVar+"_numerator_r1_r2";
      name_hist_den_for_r1 = "hist_acceptance_"+nameVar+"_denominator_r1";
      name_hist_den_for_r2 = "hist_acceptance_all_Btautau_"+nameVar+"_denominator_r2_numerator_r4";
      name_hist_num_for_r3 = "hist_acceptance_"+nameVar+"_numerator_r3";
      name_hist_num_for_r4 = "hist_acceptance_all_Btautau_"+nameVar+"_denominator_r2_numerator_r4";
      name_hist_den_for_r3_r4 = "hist_acceptance_"+nameVar+"_denominator_r3_r4";
    }
    if(nameVar.find("bb")!=std::string::npos){
      name_hist_num_r1_r2 = "hist_acceptance_all_Bbb_"+nameVar+"_numerator_r1_r2";
      name_hist_den_for_r1 = "hist_acceptance_"+nameVar+"_denominator_r1";
      name_hist_den_for_r2 = "hist_acceptance_all_Bbb_"+nameVar+"_denominator_r2_numerator_r4";
      name_hist_num_for_r3 = "hist_acceptance_"+nameVar+"_numerator_r3";
      name_hist_num_for_r4 = "hist_acceptance_all_Bbb_"+nameVar+"_denominator_r2_numerator_r4";
      name_hist_den_for_r3_r4 = "hist_acceptance_"+nameVar+"_denominator_r3_r4";
    }
   
    
    TH1F* hist_num_r1_r2 = dynamic_cast<TH1F*>(file->Get(name_hist_num_r1_r2.c_str()));
    TH1F* hist_den_for_r1 = dynamic_cast<TH1F*>(file->Get(name_hist_den_for_r1.c_str()));
    TH1F* hist_den_for_r2 = dynamic_cast<TH1F*>(file->Get(name_hist_den_for_r2.c_str()));

    TH1F* hist_num_for_r3 = dynamic_cast<TH1F*>(file->Get(name_hist_num_for_r3.c_str()));
    TH1F* hist_num_for_r4 = dynamic_cast<TH1F*>(file->Get(name_hist_num_for_r4.c_str()));
    TH1F* hist_den_for_r3_r4 = dynamic_cast<TH1F*>(file->Get(name_hist_den_for_r3_r4.c_str()));

    
    //********************************************************************
    //Plotting numerator histograms r1_r2
    //********************************************************************

    gROOT->SetBatch(kTRUE);
    hist_num_r1_r2->Draw("H");
    string name_image = "output_combined_ratios_plots/"+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"_num_ratios_r1_r2_"+sample+".png";
    can->SaveAs(name_image.c_str());

    //********************************************************************
    //Plotting numerator histograms r3
    //********************************************************************
    
    hist_num_for_r3->Draw("H");
    name_image = "output_combined_ratios_plots/"+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"_num_ratios_r3_"+sample+".png";
    can->SaveAs(name_image.c_str());

    //********************************************************************
    //Plotting numerator histograms r4
    //********************************************************************
    
    hist_num_for_r4->Draw("H");
    name_image = "output_combined_ratios_plots/"+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"_num_ratios_r4_"+sample+".png";
    can->SaveAs(name_image.c_str());
   
    TEfficiency *pEff_r1 = new TEfficiency(*hist_num_r1_r2, *hist_den_for_r1);
    TEfficiency *pEff_r2 = new TEfficiency(*hist_num_r1_r2, *hist_den_for_r2);
    TEfficiency *pEff_r3 = new TEfficiency(*hist_num_for_r3, *hist_den_for_r3_r4);
    TEfficiency *pEff_r4 = new TEfficiency(*hist_num_for_r4, *hist_den_for_r3_r4);

    TEff_ratios_r1.push_back(pEff_r1);
    TEff_ratios_r2.push_back(pEff_r2);
    TEff_ratios_r3.push_back(pEff_r3);
    TEff_ratios_r4.push_back(pEff_r4);
    
    file->Close();
  }
}
