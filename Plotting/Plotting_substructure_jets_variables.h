#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
#include <fstream>

string process_name;
string name_output_root_file;

//Percentages matched truth-recojets and preselected recojets
TH2F *percentages_matched_and_preselected_events_BbbBtautau;
TH2F *percentages_matched_and_preselected_events_only_Bbb;
TH2F *percentages_matched_and_preselected_events_only_Btautau;

void reading_distributions_histograms(const std::string& sample,
				      const std::vector<std::string>& list_of_histograms,
				      const std::vector<std::string>& comparison_list,
				      const std::string& output_folder,
				      std::unordered_map<std::string, TH1F>& distributions_histograms,
				      std::unordered_map<std::string, std::vector<TH1F>>& comparison_distributions_histograms,
				      const std::string& minpT);
void plot_distributions_comparisons(const std::unordered_map<std::string, std::vector<TH1F>>& comparison_distributions_histograms, const std::string& output_folder, const std::string& minpT);
void plot_distributions(const std::unordered_map<std::string, TH1F>& distributions_histograms, const std::string& output_folder, const std::string& minpT);
void plot_2D_distributions(const std::string& sample, const std::string& name_plot, const std::string& output_folder, const std::string& minpT);
void process_label(string name_sample);

//**********************************************************************************
// Definition of the functions above
//**********************************************************************************

void reading_distributions_histograms(const std::string& sample,
				      const std::vector<std::string>& list_of_histograms,
				      const std::vector<std::string>& comparison_list,
				      const std::string& output_folder,
				      std::unordered_map<std::string, TH1F>& distributions_histograms,
				      std::unordered_map<std::string, std::vector<TH1F>>& comparison_distributions_histograms,
				      const std::string& minpT){

  string percentages_folder = "output_plots/percentages/";
  
  TFile* file = TFile::Open(sample.c_str());

  //cout << sample << endl;
  for(const auto& nameVar : comparison_list){

    string name_matched_hist = "hist_matched_"+nameVar;
    string name_non_matched_hist = "hist_non_matched_"+nameVar;
    
    std::vector<TH1F> list_histograms(2);

    //cout << "name matched hist: " << name_matched_hist << endl;
    
    TH1F* matched_hist = dynamic_cast<TH1F*>(file->Get(name_matched_hist.c_str()));
    TH1F* non_matched_hist = dynamic_cast<TH1F*>(file->Get(name_non_matched_hist.c_str()));
            
    list_histograms[0] = *dynamic_cast<TH1F*>(matched_hist->Clone()); // Clone the histogram for matched jets
    list_histograms[1] = *dynamic_cast<TH1F*>(non_matched_hist->Clone()); // Clone the histogram for non matched jets

    // Insert into the map: for the given process, add the list of TEfficiency
    comparison_distributions_histograms[nameVar] = list_histograms;

  }

  for(const auto& nameVar : list_of_histograms){

    string name_hist = "";

    if(nameVar.find("non_matched")!=std::string::npos){
      name_hist = "hist_non_matched_"+nameVar;
    }
    else{
      name_hist = "hist_matched_"+nameVar;
    }
    
    TH1F* temp_histo = dynamic_cast<TH1F*>(file->Get(name_hist.c_str()));
            
    TH1F histogram_distribution = *dynamic_cast<TH1F*>(temp_histo->Clone()); // Clone the histogram for matched jets
    
    // Insert into the map: for the given process, add the list of TEfficiency
    distributions_histograms[nameVar] = histogram_distribution;

  }
  
  //**********************************************************************************************
  // Percentages Plotting part
  //**********************************************************************************************

  // Percentages of truth-recojets and preselected jets
  percentages_matched_and_preselected_events_BbbBtautau = dynamic_cast<TH2F*>(file->Get(("percentages_matched_and_preselected_events_BbbBtautau")));
  percentages_matched_and_preselected_events_only_Bbb = dynamic_cast<TH2F*>(file->Get(("percentages_matched_and_preselected_events_only_Bbb")));
  percentages_matched_and_preselected_events_only_Btautau = dynamic_cast<TH2F*>(file->Get(("percentages_matched_and_preselected_events_only_Btautau")));
  
  plot_2D_distributions(sample, "percentages_matched_and_preselected_events_BbbBtautau", output_folder, minpT);
  plot_2D_distributions(sample, "percentages_matched_and_preselected_events_only_Bbb", output_folder, minpT);
  plot_2D_distributions(sample, "percentages_matched_and_preselected_events_only_Btautau", output_folder, minpT);
  
  // Save the percentages in a txt file
  
  std::ofstream outFile((percentages_folder+"percentages_truth_reco_and_preselected.txt").c_str(), std::ios::app); // Open in append mode

  outFile << "/----------------------------------------------------------------------" << endl;
  outFile << "For "+minpT+"GeV: " << endl;
  outFile << "\t Percentages of correct preselected BbbBtautau for "+name_output_root_file+" process: " << endl;
  outFile << "Correct/Wrong preselected Bbb-Btautau: " << percentages_matched_and_preselected_events_BbbBtautau->GetBinContent(2, 2) << "% / " << percentages_matched_and_preselected_events_BbbBtautau->GetBinContent(2, 1) << "%" << endl;
  outFile << "Correct/Wrong preselected Bbb: " << percentages_matched_and_preselected_events_only_Bbb->GetBinContent(2, 2) << "% / " << percentages_matched_and_preselected_events_only_Bbb->GetBinContent(2, 1) << "%" <<  endl;
  outFile << "Correct/Wrong preselected Btautau: " << percentages_matched_and_preselected_events_only_Btautau->GetBinContent(2, 2) << "% / " << percentages_matched_and_preselected_events_only_Btautau->GetBinContent(2, 1) << "%" <<  endl;
  outFile << "/--------" << endl;
  outFile << "Correct/Wrong matched truth-reco Bbb-Btautau: " << percentages_matched_and_preselected_events_BbbBtautau->GetBinContent(1, 2) << "% / " << percentages_matched_and_preselected_events_BbbBtautau->GetBinContent(1, 1) << "%" << endl;
  outFile << "Correct/Wrong matched truth-reco Bbb: " << percentages_matched_and_preselected_events_only_Bbb->GetBinContent(1, 2) << "% / " << percentages_matched_and_preselected_events_only_Bbb->GetBinContent(1, 1) << "%" <<  endl;
  outFile << "Correct/Wrong matched truth-reco Btautau: " << percentages_matched_and_preselected_events_only_Btautau->GetBinContent(1, 2) << "% / " << percentages_matched_and_preselected_events_only_Btautau->GetBinContent(1, 1) << "%" <<  endl;
  outFile << "/----------------------------------------------------------------------" << endl;

  outFile.close();
  
  file->Close();
  
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                          
// for the two configurations, boosted and resolved                                                                                         

void plot_distributions_comparisons(const std::unordered_map<std::string, std::vector<TH1F>>& comparison_distributions_histograms, const std::string& output_folder, const std::string& minpT){

  string substructure_jets_folder = output_folder+"/substructure_jets_plots/";
 
  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  for(const auto& name_distribution : comparison_distributions_histograms) {

    const std::string& nameVar = name_distribution.first;
    const auto& histograms = name_distribution.second;

    string name_image = substructure_jets_folder+nameVar+".png";
    
    ///// Plotting
    TCanvas* can = new TCanvas(("can_"+nameVar).c_str(),"", 800, 600);
    TLegend* leg = new TLegend(0.7, 0.75, 0.9, 0.9);

    TH1F hist_boosted;
    TH1F hist_resolved;
    
    hist_boosted = histograms[0];
    hist_resolved = histograms[1];

    string label_boosted = "";
    string label_resolved = "";
  
    if(nameVar.find("bb")!=std::string::npos){
      label_boosted = "boosted bb jet";
      label_resolved = "single b jet";
    }
    if(nameVar.find("tautau")!=std::string::npos){
      label_boosted = "boosted #tau#tau jet";
      label_resolved = "single #tau jet";
    }
  
    hist_boosted.SetStats(0);
    hist_boosted.SetFillStyle(3001);
    hist_boosted.SetFillColorAlpha(kBlue, 0.45);
    hist_boosted.SetLineColor(4);
  
    hist_resolved.SetStats(0);
    hist_resolved.SetFillStyle(3003);
    hist_resolved.SetFillColorAlpha(kRed, 0.45);
    hist_resolved.SetLineColor(2);

    // Step 1: Normalize the histograms manually (or use DrawNormalized to visualize them directly).
    hist_boosted.Scale(1.0 / hist_boosted.Integral());
    hist_resolved.Scale(1.0 / hist_resolved.Integral());
    
    // Step 2: Get the maximum value of each histogram after normalization.
    double max_boosted = hist_boosted.GetMaximum();
    double max_resolved = hist_resolved.GetMaximum();
    
    // Step 3: Set the y-axis maximum to the maximum of the two histograms.
    double y_max = std::max(max_boosted, max_resolved);
    
    // Optionally, you can set the y-axis maximum slightly higher than the actual maximum value for better visualization.
    y_max = y_max*1.5;  // Increase by 10% for padding
    
    // Step 4: Draw the histograms and set the maximum.
    hist_boosted.SetMaximum(y_max);
    hist_resolved.SetMaximum(y_max);
  
    // Step 5: Draw the histograms on the same canvas for comparison.
    hist_boosted.Draw("H");   // Draw the first histogram
    hist_resolved.Draw("sameH");  // Draw the second histogram on the same canvas
  
    leg->AddEntry(&hist_boosted, label_boosted.c_str(), "l");
    leg->AddEntry(&hist_resolved, label_resolved.c_str(),"l");
    leg->SetBorderSize();
    leg->Draw();
    
    double dely = 0.05;
    myText(0.2, 0.9, kBlack, process_name.c_str());
    myText(0.2, 0.9-dely, kBlack, nameVar.c_str());
    myText(0.2, 0.9-2*dely, kBlack, ("for a min p_{T}: "+minpT+" GeV").c_str());
    
    can->Draw();
    can->SaveAs(name_image.c_str());
  }
  
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                          
// for the two configurations, boosted and resolved                                                                                         

void plot_distributions(const std::unordered_map<std::string, TH1F>& distributions_histograms, const std::string& output_folder, const std::string& minpT){

  string distributions_comparison_folder = output_folder+"/distributions_comparison/";
  
  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();

  for(const auto& name_distribution : distributions_histograms) {

    const std::string& nameVar = name_distribution.first;
    const auto& histo = name_distribution.second;
    
    string name_image = distributions_comparison_folder+nameVar+".png";
  
    ///// Plotting
    TCanvas *can = new TCanvas(("can_"+nameVar).c_str(),"", 800, 600);
    TH1F hist;

    hist = histo;
    
    double y_max = 1.25*hist.GetMaximum();
  
    // Step 4: Draw the histograms and set the maximum.

    hist.SetMaximum(y_max);

    hist.Draw();
    
    double dely = 0.04;
    myText(0.2, 0.90, kBlack, process_name.c_str());
    myText(0.2, 0.90-dely, kBlack, nameVar.c_str());
    myText(0.2, 0.9-2*dely, kBlack, ("for a min p_{T}: "+minpT+" GeV").c_str());
    
    can->Draw();
    can->SaveAs(name_image.c_str());
  }
}

void plot_2D_distributions(const std::string& sample, const std::string& name_plot, const std::string& output_folder, const std::string& minpT){

  string percentages_folder = "output_plots/percentages/";
  
  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);
  TH2F *hist = new TH2F();
  string variable = "";
  
  if(name_plot == "percentages_matched_and_preselected_events_BbbBtautau"){
    hist = percentages_matched_and_preselected_events_BbbBtautau;
    variable = "BbbBtautau";
  }
  if(name_plot == "percentages_matched_and_preselected_events_only_Bbb"){
    hist = percentages_matched_and_preselected_events_only_Bbb;
    variable = "BbbB";
  }
  if(name_plot == "percentages_matched_and_preselected_events_only_Btautau"){
    hist = percentages_matched_and_preselected_events_only_Btautau;
    variable = "Btautau";
  }

  string name_image = percentages_folder+name_output_root_file+"_"+variable+"_"+minpT+"GeV.png";
  
  double y_max = 1.25*hist->GetMaximum();
  
  //hist->SetMaximum(y_max);
 
  gStyle->SetTextFont(42);     // Set global font (42 = Helvetica, nice default)
  gStyle->SetTextSize(0.035);  // Set global text size
  
  hist->SetStats(0);
  hist->SetMarkerSize(2.0);
 
  //hist->SetMarkerFont(42);

  gPad->SetTopMargin(0.2);
  
  hist->Draw("TEXT");
  
  double dely = 0.04;
  myText(0.2, 0.90, kBlack, process_name.c_str());
  myText(0.2, 0.90-dely, kBlack, name_plot.c_str());
  myText(0.2, 0.9-2*dely, kBlack, ("for a min p_{T}: "+minpT+" GeV").c_str());
  
  can->Draw();
  can->SaveAs(name_image.c_str());

}

void process_label(string name_sample){

  // ggF processes had-had channel
  if(name_sample.find("600459") != string::npos){ process_name = "ggF HH SM had-had channel"; name_output_root_file = "ggF_SM_hh_600459";}
  if(name_sample.find("600460") != string::npos){ process_name = "ggF HH #lambda = 10 had-had channel"; name_output_root_file = "ggF_lambda10_hh_600460";}

  // ggF processes lep-had channel
  if(name_sample.find("600461") != string::npos){ process_name = "ggF HH SM lep-had channel"; name_output_root_file = "ggF_SM_lh_600461";}
  if(name_sample.find("600462") != string::npos){ process_name = "ggF HH #lambda = 10 lep-had channel"; name_output_root_file = "ggF_lambda10_lh_600462";}

  //vbf processes had-had channel
  if(name_sample.find("502982") != string::npos){ process_name = "VBF HH SM had-had channel"; name_output_root_file = "VBF_SM_hh_502982";}
  if(name_sample.find("502985") != string::npos){ process_name = "VBF HH C_{VV} = 1.5 had-had channel"; name_output_root_file = "VBF_cvv1p5_hh_502985";}
  if(name_sample.find("502989") != string::npos){ process_name = "VBF HH #lambda = 2.0 had-had channel"; name_output_root_file = "VBF_l2_hh_502989";}
  if(name_sample.find("502990") != string::npos){ process_name = "VBF HH #lambda = 10.0 had-had channel"; name_output_root_file = "VBF_l10_hh_502990";}
  if(name_sample.find("502991") != string::npos){ process_name = "VBF HH C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_cv0p5_hh_502991";}
  if(name_sample.find("508690") != string::npos){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_l5cv0p5_hh_508690";}

  //vbf processes lep-had channel
  if(name_sample.find("502993") != string::npos){ process_name = "VBF HH SM lep-had channel"; name_output_root_file = "VBF_SM_lh_502993";}
  if(name_sample.find("502996") != string::npos){ process_name = "VBF HH C_{VV} = 1.5 lep-had channel"; name_output_root_file = "VBF_cvv1p5_lh_502996";}
  if(name_sample.find("503000") != string::npos){ process_name = "VBF HH #lambda = 2.0 lep-had channel"; name_output_root_file = "VBF_l2_lh_503000";}
  if(name_sample.find("503001") != string::npos){ process_name = "VBF HH #lambda = 10.0 lep-had channel"; name_output_root_file = "VBF_l10_lh_503001";}
  if(name_sample.find("503002") != string::npos){ process_name = "VBF HH C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_cv0p5_lh_503002";}
  if(name_sample.find("508691") != string::npos){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_l5cv0p5_lh_508691";}

  //vbf SM processes both channels channel
  if(name_sample.find("vbf_SM_both_channels") != string::npos){ process_name = "VBF HH SM"; }

  //vbf SM processes both channels channel
  if(name_sample.find("ggf_SM_both_channels") != string::npos){ process_name = "ggF HH SM"; }

  //vbf Cvv=1.5 processes both channels channel
  if(name_sample.find("vbf_l1cvv1p5cv1_both_channels") != string::npos){ process_name = "VBF HH C_{VV} = 1.5"; }

  //ggf cHHH = 10 processes both channels channel
  if(name_sample.find("ggf_cHHH10d0_both_channels") != string::npos){ process_name = "ggF HH #lambda = 10"; }
}
