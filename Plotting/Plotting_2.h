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
  TLegend* leg = new TLegend(0.35, 0.70, 0.90, 0.90);

  int color = 1;

  TEfficiency *pEff_r1 = TEff_ratios.at(0);
  TEfficiency *pEff_r2 = TEff_ratios.at(1);
  TEfficiency *pEff_r3 = TEff_ratios.at(2);
  TEfficiency *pEff_r4 = TEff_ratios.at(3);
  TEfficiency *pEff_r5 = TEff_ratios.at(4);
  TEfficiency *pEff_r6 = TEff_ratios.at(5);
  TEfficiency *pEff_r7 = TEff_ratios.at(6);
  TEfficiency *pEff_r8 = TEff_ratios.at(7);

  pEff_r1->SetFillColor(1);
  pEff_r2->SetFillColor(2);
  pEff_r3->SetFillColor(3);
  pEff_r4->SetFillColor(4);
  pEff_r5->SetFillColor(5);
  pEff_r6->SetFillColor(6);
  pEff_r7->SetFillColor(7);
  pEff_r8->SetFillColor(8);

  pEff_r1->SetLineColor(1);
  pEff_r2->SetLineColor(2);
  pEff_r3->SetLineColor(3);
  pEff_r4->SetLineColor(4);
  pEff_r5->SetLineColor(5);
  pEff_r6->SetLineColor(6);
  pEff_r7->SetLineColor(7);
  pEff_r8->SetLineColor(8);

  pEff_r1->SetMarkerStyle(20);
  pEff_r1->SetMarkerColor(1);
  pEff_r2->SetMarkerStyle(20);
  pEff_r2->SetMarkerColor(2);
  pEff_r3->SetMarkerStyle(20);
  pEff_r3->SetMarkerColor(3);
  pEff_r4->SetMarkerStyle(20);
  pEff_r4->SetMarkerColor(4);
  pEff_r5->SetMarkerStyle(20);
  pEff_r5->SetMarkerColor(5);
  pEff_r6->SetMarkerStyle(20);
  pEff_r6->SetMarkerColor(6);
  pEff_r7->SetMarkerStyle(20);
  pEff_r7->SetMarkerColor(7);
  pEff_r8->SetMarkerStyle(20);
  pEff_r8->SetMarkerColor(8);

  leg->SetNColumns(2);
  leg->AddEntry(pEff_r1, (nameTEff.at(0)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r2, (nameTEff.at(1)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r3, (nameTEff.at(2)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r4, (nameTEff.at(3)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r5, (nameTEff.at(4)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r6, (nameTEff.at(5)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r7, (nameTEff.at(6)+"_"+ratio).c_str(), "lep");
  leg->AddEntry(pEff_r8, (nameTEff.at(7)+"_"+ratio).c_str(), "lep");

  leg->SetFillStyle(0);
  leg->SetLineColor(0);
  
  //leg->Draw();
  pEff_r1->Draw("AP");
  pEff_r2->Draw("PSAME");
  pEff_r3->Draw("PSAME");
  pEff_r4->Draw("PSAME");
  pEff_r5->Draw("PSAME");
  pEff_r6->Draw("PSAME");
  pEff_r7->Draw("PSAME");
  pEff_r8->Draw("PSAME");
   
  gPad->Update();
  auto graph = pEff_r1->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.60);
      
  gPad->Update();
    
  /*
  for(int ii=0; ii<TEff_ratios.size(); ii++){
    TEff_ratios.at(ii)->SetFillColor(color);
    TEff_ratios.at(ii)->Draw("APSAME");
    color++;
    string legend = nameTEff.at(ii)+"_"+ratio;
    leg->AddEntry(TEff_ratios.at(ii), legend.c_str(), "l");
    gPad->Update();
    auto graph = TEff_ratios.at(ii)->GetPaintedGraph();
    graph->SetMinimum(0);
    graph->SetMaximum(1.25);
    gPad->Update();
  }
  
  gPad->Update();
  auto graph = pEff->GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.25);
  gPad->Update();
  */
  // canvas->Draw();
  leg->Draw();
  canvas->SaveAs("ratios_r1_comparison.png");
}

// Initialize the map_ratios_info
void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::vector<string>& nameVar, std::vector<string>& nameTEff, std::vector<TEfficiency*>& TEff_ratios_r1, std::vector<TEfficiency*>& TEff_ratios_r2){
  string path_folder="/afs/cern.ch/user/g/garciarm/HHbbtautau-easyjet-framework/analysis/Analysis/study_substructure_jets/output_analysis/";
  
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
  
  /*
  void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, std::vector<string>& nameVar, std::vector<TEfficiency*>& TEff_ratios){
  string path_folder="/afs/cern.ch/user/g/garciarm/HHbbtautau-easyjet-framework/analysis/Analysis/study_substructure_jets/output_analysis/";
  
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

    //std::unordered_map<std::string, hist_ratios*> sample_ratios;

    hist_ratios mHH_ratios;
    
    mHH_ratios.hist_num_for_r1 = (TH1F*)file->Get("hist_acceptance_mHH_numerator_class3");
    mHH_ratios.hist_den_for_r1 = (TH1F*)file->Get("hist_acceptance_mHH_denominator");
    mHH_ratios.hist_num_for_r2 = (TH1F*)file->Get("hist_acceptance_mHH_numerator_class3");
    mHH_ratios.hist_den_for_r2 = (TH1F*)file->Get("hist_acceptance_mHH_denominator_class3");
  
    mHH_ratios.hist_num_for_r1 = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_numerator_class3"));
    mHH_ratios.hist_den_for_r1 = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_denominator"));
    mHH_ratios.hist_num_for_r2 = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_numerator_class3"));
    mHH_ratios.hist_den_for_r2 = dynamic_cast<TH1F*>(file->Get("hist_acceptance_mHH_denominator_class3"));

    if (!mHH_ratios.hist_num_for_r1 || !mHH_ratios.hist_den_for_r1 ||
	!mHH_ratios.hist_num_for_r2 || !mHH_ratios.hist_den_for_r2) {
      std::cout << "Missing histograms in file: " << sample << std::endl;
      if (!mHH_ratios.hist_num_for_r1) std::cout << "hist_num_mHH_r1 not found." << std::endl;
      if (!mHH_ratios.hist_den_for_r1) std::cout << "hist_den_mHH_r1 not found." << std::endl;
      if (!mHH_ratios.hist_num_for_r2) std::cout << "hist_num_mHH_r2 not found." << std::endl;
      if (!mHH_ratios.hist_den_for_r2) std::cout << "hist_den_mHH_r2 not found." << std::endl;
      file->Close();
      continue;
    }

    //mHH_ratios.hist_num_for_r1->Draw();
    
    mHH_ratios.label_r1 = "Efficiency r1 for mHH";
    mHH_ratios.title_r1 = "Efficiency Ratio r1 for mHH";
    mHH_ratios.label_r2 = "Efficiency r2 for mHH";
    mHH_ratios.title_r2 = "Efficiency Ratio r2 for mHH";

    //sample_ratios["mHH"] = mHH_ratios;
    
    //sample_ratios.insert({"mHH", mHH_ratios});

    //map_ratios_info[sample] = sample_ratios;
    map_ratios_info[sample] = make_pair("mHH", mHH_ratios);
    //map_ratios_info.insert({sample, sample_ratios});

    //map_ratios_info[sample]["mHH"].hist_num_for_r1->Draw();
    //canvas->SaveAs((sample + "_hist_num_mHH_r1.png").c_str());
    file->Close();
  }
}

// Function to print the details of histograms in map_ratios_info with null checks
void printMapRatiosInfo(const std::unordered_map<std::string, std::unordered_map<std::string, hist_ratios>>& map_ratios_info) {
  for (const auto& sample_entry : map_ratios_info) {
    const std::string& sample_name = sample_entry.first;
    const auto& variable_map = sample_entry.second;
        
    std::cout << "Sample: " << sample_name << std::endl;
        
    for (const auto& variable_entry : variable_map) {
      const std::string& variable_name = variable_entry.first;
      //auto& ratios = variable_entry.second;
      //const hist_ratios& ratios = variable_entry.second;
      hist_ratios ratios = variable_entry.second;
            
      std::cout << "  Variable: " << variable_name << std::endl;
      std::cout << "     Label_r1: " << ratios.label_r1 << std::endl;

      TH1F* hist = ratios.hist_num_for_r1;
      
      if (ratios.hist_num_for_r1) {
	std::cout << "    Histogram num_r1: " << "ratios.hist_num_for_r1->GetName()" << std::endl;
	//	std::cout << "    Histogram num_r1: " << hist->GetEntries() << std::endl;
      } else {
	std::cout << "    Histogram num_r1: null" << std::endl;
      }
      
      if (ratios.hist_num_for_r1) {
	std::cout << "    Histogram num_r1: " << ratios.hist_num_for_r1->GetName() << std::endl;
      } else {
	std::cout << "    Histogram num_r1: null" << std::endl;
      }
      
      if (ratios.hist_den_for_r1) {
	std::cout << "    Histogram den_r1: " << ratios.hist_den_for_r1->GetName() << std::endl;
      } else {
	std::cout << "    Histogram den_r1: null" << std::endl;
      }
      
      if (ratios.hist_num_for_r2) {
	std::cout << "    Histogram num_r2: " << ratios.hist_num_for_r2->GetName() << std::endl;
      } else {
	std::cout << "    Histogram num_r2: null" << std::endl;
      }
      
      if (ratios.hist_den_for_r2) {
	std::cout << "    Histogram den_r2: " << ratios.hist_den_for_r2->GetName() << std::endl;
      } else {
	std::cout << "    Histogram den_r2: null" << std::endl;
      }
    
    }
  }
}


// Function to plot hist_num_r1 for the variable mHH with additional checks
void plotHistNumR1(const std::unordered_map<std::string, std::unordered_map<std::string, hist_ratios>>& map_ratios_info) {
  for (const auto& sample_entry : map_ratios_info) {
    const std::string& sample_name = sample_entry.first;
    const auto& variable_map = sample_entry.second;
    if (variable_map.find("mHH") != variable_map.end()) {
      TH1F* hist = variable_map.at("mHH").hist_num_for_r1;
      if (hist) {
	TCanvas* canvas = new TCanvas((sample_name + "_mHH_num_r1").c_str(), (sample_name + " hist_num_mHH_r1").c_str(), 800, 600);
	if (canvas) {
	  hist->Draw();
	  canvas->Update();
	  canvas->SaveAs((sample_name + "_hist_num_mHH_r1.png").c_str());
	  delete canvas;
	} else {
	  std::cerr << "Failed to create canvas for sample: " << sample_name << std::endl;
	}
      } else {
	std::cerr << "hist_num_for_r1 for mHH is null in sample: " << sample_name << std::endl;
      }
    }
  }
}


void getTEfficiency(const std::vector<std::string>& sampleFiles, const std::vector<std::string>& variables,
                    std::unordered_map<std::string, std::unordered_map<std::string, hist_ratios>>& map_ratios_info,
                    std::unordered_map<std::string, std::unordered_map<std::string, plot_Teff>>& map_Teff_ratios) {
    for (const auto& sample : sampleFiles) {
        if (map_ratios_info.find(sample) == map_ratios_info.end()) continue;

        for (const auto& variable : variables) {
            if (map_ratios_info[sample].find(variable) != map_ratios_info[sample].end()) {
                hist_ratios hist_info = map_ratios_info[sample][variable];

                TEfficiency* ratio_r1 = new TEfficiency(*hist_info.hist_num_for_r1, *hist_info.hist_den_for_r1);
                TEfficiency* ratio_r2 = new TEfficiency(*hist_info.hist_num_for_r2, *hist_info.hist_den_for_r2);

                map_Teff_ratios[sample][variable] = {ratio_r1, ratio_r2, hist_info.label_r1, hist_info.label_r2};
            }
        }
    }
}

*/
/*
void plotEfficiencies(const std::unordered_map<TString, std::unordered_map<TString, plot_Teff>>& map_Teff_ratios,
                      const std::vector<std::string>& variables) {
  TCanvas* canvas = new TCanvas("canvas", "Efficiency Comparison", 800, 600);
  
  for (const auto& variable : variables) {
    TMultiGraph* mg_r1 = new TMultiGraph();
    TMultiGraph* mg_r2 = new TMultiGraph();
    TLegend* legend_r1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    TLegend* legend_r2 = new TLegend(0.7, 0.8, 0.9, 0.9);
    bool first_r1 = true;
    bool first_r2 = true;

    for (const auto& entry : map_Teff_ratios) {
      const TString& sample = entry.first;
      if (entry.second.find(variable.c_str()) != entry.second.end()) {
	const plot_Teff& eff_info = entry.second.at(variable.c_str());

	TGraphAsymmErrors* graph_r1 = eff_info.ratio_r1->CreateGraph();
	TGraphAsymmErrors* graph_r2 = eff_info.ratio_r2->CreateGraph();

	graph_r1->SetMarkerColor(kRed);
	graph_r1->SetMarkerStyle(20);
	graph_r2->SetMarkerColor(kBlue);
	graph_r2->SetMarkerStyle(21);
	
	mg_r1->Add(graph_r1, "P");
	mg_r2->Add(graph_r2, "P");

	if (first_r1) {
	  legend_r1->AddEntry(graph_r1, eff_info.label_r1, "P");
	  first_r1 = false;
	}
	if (first_r2) {
	  legend_r2->AddEntry(graph_r2, eff_info.label_r2, "P");
	  first_r2 = false;
	}
      }
    }

    canvas->cd();
    mg_r1->Draw("A PMC PLC");
    mg_r1->SetTitle(("Efficiency Comparison for " + variable + " (Ratio r1); X Axis Title; Efficiency").c_str());
    mg_r1->GetXaxis()->SetTitle("X Axis Title");
    mg_r1->GetYaxis()->SetTitle("Efficiency");
    legend_r1->Draw();
    canvas->Update();
    canvas->SaveAs((variable + "_efficiency_comparison_r1.png").c_str());
    
    mg_r2->Draw("A PMC PLC");
    mg_r2->SetTitle(("Efficiency Comparison for " + variable + " (Ratio r2); X Axis Title; Efficiency").c_str());
    mg_r2->GetXaxis()->SetTitle("X Axis Title");
    mg_r2->GetYaxis()->SetTitle("Efficiency");
    legend_r2->Draw();
    canvas->Update();
    canvas->SaveAs((variable + "_efficiency_comparison_r2.png").c_str());

    delete mg_r1;
    delete mg_r2;
    delete legend_r1;
    delete legend_r2;
  }

  delete canvas;
}
*/
