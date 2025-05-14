#include "../../Plotting/AtlasStyle/AtlasStyle.C"
#include "../../Plotting/AtlasStyle/AtlasUtils.C"
#include "../../Plotting/AtlasStyle/AtlasLabels.C"

TH1F* hist_boosted_bdt_score_separation_VBF = new TH1F("hist_boosted_bdt_score_separation_VBF", "BDT score to separate ggF and VBF processes; BDT score;Events", 30, 0, 1);
TH1F* hist_boosted_bdt_score_separation_ggF = new TH1F("hist_boosted_bdt_score_separation_ggF", "BDT score to separate ggF and VBF processes; BDT score;Events", 30, 0, 1);


// *************************************
// Declaration of some functions
// *************************************

void reading_distributions_histograms(const std::vector<std::string>& list_of_histograms,
				      std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms);
void plot_distributions_comparisons(const std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms);


// *************************************
// Implementation of the functions defined above
// *************************************

void reading_distributions_histograms(const std::vector<std::string>& list_of_histograms,
				      std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms){

  string sample_VBF_path = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/comparison_boosted_resolved_easyjet/output_analysis/VBF_SM_hh_502982.root";
  
  string sample_ggF_path = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/comparison_boosted_resolved_easyjet/output_analysis/ggF_SM_hh_600459.root";
  
  TFile* file_sample_VBF = TFile::Open(sample_VBF_path.c_str());
  TFile* file_sample_ggF = TFile::Open(sample_ggF_path.c_str());

  //cout << sample << endl;
  for(const auto& nameVar : list_of_histograms){

    string name_VBF_hist = "hist_boosted_"+nameVar;
    string name_ggF_hist = "hist_boosted_"+nameVar;
    
    std::vector<TH1F> list_histograms(2);

    //cout << "name matched hist: " << name_matched_hist << endl;

    TH1F* VBF_hist = new TH1F();
    TH1F* ggF_hist = new TH1F();
      
    if(nameVar.find("BDT_score")!=std::string::npos){
      VBF_hist = hist_boosted_bdt_score_separation_VBF;
      ggF_hist = hist_boosted_bdt_score_separation_ggF;
    }
    else{
      VBF_hist = dynamic_cast<TH1F*>(file_sample_VBF->Get(name_VBF_hist.c_str()));
      ggF_hist = dynamic_cast<TH1F*>(file_sample_ggF->Get(name_ggF_hist.c_str()));
    }
    
    list_histograms[0] = *dynamic_cast<TH1F*>(VBF_hist->Clone()); // Clone the histogram for matched jets
    list_histograms[1] = *dynamic_cast<TH1F*>(ggF_hist->Clone()); // Clone the histogram for non matched jets

    // Insert into the map: for the given process, add the list of TEfficiency
    distributions_histograms[nameVar] = list_histograms;

  }

  file_sample_VBF->Close();
  file_sample_ggF->Close();

}

void plot_distributions_comparisons(const std::unordered_map<std::string, std::vector<TH1F>>& distributions_histograms){

  string distributions_comparison_folder = "plots_comparison/";
 
  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  for(const auto& name_distribution : distributions_histograms) {

    const std::string& nameVar = name_distribution.first;
    const auto& histograms = name_distribution.second;

    string name_image = distributions_comparison_folder+nameVar+".png";
    
    ///// Plotting
    TCanvas* can = new TCanvas(("can_"+nameVar).c_str(),"", 800, 600);
    TLegend* leg = new TLegend(0.7, 0.75, 0.9, 0.9);

    TH1F hist_VBF;
    TH1F hist_ggF;
    
    hist_VBF = histograms[0];
    hist_ggF = histograms[1];

    string label_VBF = "VBF processes";
    string label_ggF = "ggF processes";
  
    hist_VBF.SetStats(0);
    hist_VBF.SetFillStyle(3001);
    hist_VBF.SetFillColorAlpha(kBlue, 0.45);
    hist_VBF.SetLineColor(4);
  
    hist_ggF.SetStats(0);
    hist_ggF.SetFillStyle(3003);
    hist_ggF.SetFillColorAlpha(kRed, 0.45);
    hist_ggF.SetLineColor(2);

    // Step 1: Normalize the histograms manually (or use DrawNormalized to visualize them directly).
    hist_VBF.Scale(1.0 / hist_VBF.Integral());
    hist_ggF.Scale(1.0 / hist_ggF.Integral());
    
    // Step 2: Get the maximum value of each histogram after normalization.
    double max_VBF = hist_VBF.GetMaximum();
    double max_ggF = hist_ggF.GetMaximum();
    
    // Step 3: Set the y-axis maximum to the maximum of the two histograms.
    double y_max = std::max(max_VBF, max_ggF);
    
    // Optionally, you can set the y-axis maximum slightly higher than the actual maximum value for better visualization.
    y_max = y_max*1.5;  // Increase by 10% for padding
    
    // Step 4: Draw the histograms and set the maximum.
    hist_VBF.SetMaximum(y_max);
    hist_ggF.SetMaximum(y_max);
  
    // Step 5: Draw the histograms on the same canvas for comparison.
    hist_VBF.Draw("H");   // Draw the first histogram
    hist_ggF.Draw("sameH");  // Draw the second histogram on the same canvas
  
    leg->AddEntry(&hist_VBF, label_VBF.c_str(), "l");
    leg->AddEntry(&hist_ggF, label_ggF.c_str(),"l");
    leg->SetBorderSize();
    leg->Draw();
    
    double dely = 0.05;
    myText(0.2, 0.8, kBlack, nameVar.c_str());
    
    can->Draw();
    can->SaveAs(name_image.c_str());
  }
  
}
