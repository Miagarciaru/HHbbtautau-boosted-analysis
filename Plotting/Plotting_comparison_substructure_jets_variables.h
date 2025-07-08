#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
#include <unordered_map>

const string path_folder="/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis/";

//*******************************************************
// Declaration of functions
//*******************************************************

void plotDistributionsComparisons(const std::vector<std::string>& sampleFiles,
				  const std::string& nameVar,
				  const std::string& min_pT,
				  const std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms);
  
void initializeHistogramsDistributionsInfo(const std::vector<std::string>& sampleFiles,
					   const std::string& nameVar,
					   const std::vector<std::string>& pT_values,
					   std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms,
					   bool matched_objects);

//*******************************************************
// Definition of functions declared above
//*******************************************************

void plotDistributionsComparisons(const std::vector<std::string>& sampleFiles,
				  const std::string& nameVar,
				  const std::string& min_pT,
				  const std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();

  string name_canvas = "can_"+nameVar+"_minpT"+min_pT;
  
  TCanvas* canvas = new TCanvas(name_canvas.c_str());
  TLegend* leg = new TLegend(0.18, 0.75, 0.93, 0.90);

  int pT_value = 0;
  int color_number = 0;

  if(min_pT.find("100")!=std::string::npos){ pT_value = 0;}
  if(min_pT.find("150")!=std::string::npos){ pT_value = 1;}
  if(min_pT.find("200")!=std::string::npos){ pT_value = 2;}
  if(min_pT.find("250")!=std::string::npos){ pT_value = 3;}
  if(min_pT.find("300")!=std::string::npos){ pT_value = 4;}
  if(min_pT.find("350")!=std::string::npos){ pT_value = 5;}
  
  TH1F hist_ggF_lambda10_hh_600460;
  TH1F hist_ggF_lambda10_lh_600462;
  TH1F hist_ggF_SM_hh_600459;
  TH1F hist_ggF_SM_lh_600461;

  float y_max_local = 0;
  float y_max_global = 0;
  
  for(const auto& process_sample : distributions_histograms) {

    const std::string& sample_name = process_sample.first;
    const auto& histograms = process_sample.second;
    
    // Make a copy of the TEfficiency object to modify it
    TH1F hist = histograms[pT_value]; // Copy the TEfficiency object

    if(sample_name.find("ggF_lambda10_hh_600460")!=std::string::npos){ hist_ggF_lambda10_hh_600460 = hist; }
    if(sample_name.find("ggF_lambda10_lh_600462")!=std::string::npos){ hist_ggF_lambda10_lh_600462 = hist; }
    if(sample_name.find("ggF_SM_hh_600459")!=std::string::npos){ hist_ggF_SM_hh_600459 = hist; }
    if(sample_name.find("ggF_SM_lh_600461")!=std::string::npos){ hist_ggF_SM_lh_600461 = hist; }

    y_max_local = hist.GetMaximum();

    if( y_max_local >= y_max_global ){
      y_max_global = y_max_local;
    }
  }

  // Set Color
  hist_ggF_lambda10_hh_600460.SetLineColor(kRed);
  hist_ggF_lambda10_lh_600462.SetLineColor(kBlue);
  hist_ggF_SM_hh_600459.SetLineColor(kGreen);
  hist_ggF_SM_lh_600461.SetLineColor(kMagenta);

  // Set line width
  hist_ggF_lambda10_hh_600460.SetLineWidth(2);
  hist_ggF_lambda10_lh_600462.SetLineWidth(2);
  hist_ggF_SM_hh_600459.SetLineWidth(2);
  hist_ggF_SM_lh_600461.SetLineWidth(2);

  // Set Maximum

  y_max_global = 1.8*y_max_global;
  
  hist_ggF_lambda10_hh_600460.SetMaximum(y_max_global);
  hist_ggF_lambda10_lh_600462.SetMaximum(y_max_global);
  hist_ggF_SM_hh_600459.SetMaximum(y_max_global);
  hist_ggF_SM_lh_600461.SetMaximum(y_max_global);

  // legends
  leg->AddEntry(&hist_ggF_lambda10_hh_600460, ("ggF_lambda10_hh_"+min_pT+"GeV").c_str(), "l");
  leg->AddEntry(&hist_ggF_lambda10_lh_600462, ("ggF_lambda10_lh_"+min_pT+"GeV").c_str(), "l");
  leg->AddEntry(&hist_ggF_SM_hh_600459, ("ggF_SM_hh_"+min_pT+"GeV").c_str(), "l");
  leg->AddEntry(&hist_ggF_SM_lh_600461, ("ggF_SM_lh_"+min_pT+"GeV").c_str(), "l");

  // Draw histograms
  hist_ggF_lambda10_hh_600460.Draw("HIST");
  hist_ggF_lambda10_lh_600462.Draw("HIST SAME");
  hist_ggF_SM_hh_600459.Draw("HIST SAME");
  hist_ggF_SM_lh_600461.Draw("HIST SAME");
  
  leg->SetNColumns(2);
  leg->SetFillStyle(0);
  leg->SetLineColor(0);
  
  leg->Draw();

  string description1 = "For min p_{T} > "+min_pT+"GeV";
  
  string name_image = "";
  
  name_image = "output_plots/"+min_pT+"GeV/grouped_distributions_plots/"+nameVar+"_min_pT"+min_pT+"GeV_comparison.pdf";
  
  double dely = 0.05;
  myText(0.2, 0.7, kBlack, description1.c_str());
  
  canvas->SaveAs(name_image.c_str());
  
}

// Initialize the histograms
void initializeHistogramsDistributionsInfo(const std::vector<std::string>& sampleFiles,
					   const std::string& nameVar,
					   const std::vector<std::string>& pT_values,
					   std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms,
					   bool matched_objects){
  
  gROOT->SetBatch(kTRUE);
  
  for(const auto& sample : sampleFiles){

    string name_hist = "";
    
    std::vector<TH1F> list_histograms(6);
    
    if(matched_objects==true){
      name_hist = "hist_matched_"+nameVar;
    }
    
    if(matched_objects==false){
      name_hist = "hist_non_matched_"+nameVar;
    }
       
    for(const auto& min_pT : pT_values){
      
      string path_root_file = path_folder+sample+"_pT"+min_pT+"GeV.root";
      //TCanvas* can = new TCanvas(("can_"+sample+"_"+nameVar+"_pT"+min_pT+"GeV").c_str());
      
      TFile* file = TFile::Open(path_root_file.c_str());
      
      int pT_location = 0;
      
      if (!file || file->IsZombie()) {
	std::cerr << "Error opening file: " << sample << std::endl;
	if (file) file->Close();
	continue;
      }
      else{
	cout << "The file has been read " << sample << endl;
      }
	  
      if(min_pT == "100"){ pT_location = 0; }
      if(min_pT == "200"){ pT_location = 1; }
      if(min_pT == "300"){ pT_location = 2; }
      
      //cout << path_root_file << endl;
      //cout << name_hist << endl;

      TH1F* hist = dynamic_cast<TH1F*>(file->Get(name_hist.c_str()));
            
      if(!hist){
	std::cout << "Warning: It was not found the histogram " << name_hist << " in " << path_root_file << std::endl;
	file->Close();
	continue;
      }
            
      list_histograms[pT_location] = *dynamic_cast<TH1F*>(hist->Clone()); // Clone the histogram before closing the file
      	    
      file->Close();
    }

    // Insert into the map: for the given process, add the list of TEfficiency
    distributions_histograms[sample] = list_histograms;
  }
  
}
