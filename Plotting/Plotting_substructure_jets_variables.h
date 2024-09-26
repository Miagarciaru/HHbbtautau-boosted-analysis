#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
//#include "../Analysis/study_substructure_jets/declaration_of_variables.h"

string process_name;
string name_output_root_file;

TH1F* hist_truth_b1_m;
TH1F* hist_truth_b2_m;
TH1F* hist_truth_b1_plus_b2_m;
TH1F* hist_matched_recojet_bb_m;
TH1F* hist_matched_recojet_tautau_m;
TH1F* hist_matched_recojet_bb_pt;
TH1F* hist_matched_recojet_tautau_pt;
TH1F* hist_matched_recojet_bb_eta;
TH1F* hist_matched_recojet_tautau_eta;
TH1F* hist_matched_recojet_bb_dR;
TH1F* hist_matched_recojet_tautau_dR;
TH1F* hist_non_matched_recojet_pt;
TH1F* hist_non_matched_recojet_eta;
TH1F* hist_non_matched_recojet_pt_no_class;
TH1F* hist_non_matched_recojet_eta_no_class;
TH1F* hist_nevents_per_class;

//tau_nProng histograms
TH1F* hist_matched_recojet_bb_tau_n_prong;
TH1F* hist_matched_recojet_tautau_tau_n_prong;
TH1F* hist_non_matched_recojet_bb_tau_n_prong;
TH1F* hist_non_matched_recojet_tautau_tau_n_prong;

//n1 subjettiness
TH1F* hist_matched_recojet_bb_tau_n1_subjettiness;
TH1F* hist_matched_recojet_tautau_tau_n1_subjettiness;
TH1F* hist_non_matched_recojet_bb_tau_n1_subjettiness;
TH1F* hist_non_matched_recojet_tautau_tau_n1_subjettiness;

//n2 subjettiness
TH1F* hist_matched_recojet_bb_tau_n2_subjettiness;
TH1F* hist_matched_recojet_tautau_tau_n2_subjettiness;
TH1F* hist_non_matched_recojet_bb_tau_n2_subjettiness;
TH1F* hist_non_matched_recojet_tautau_tau_n2_subjettiness;

//n2 over n1 subjettiness
TH1F* hist_matched_recojet_bb_tau_n2_over_n1_subjettiness;
TH1F* hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness;
TH1F* hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness;
TH1F* hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness;

struct hist_ratios {
    TH1F* hist_num_for_r1;
    TH1F* hist_den_for_r1;
    TH1F* hist_num_for_r2;
    TH1F* hist_den_for_r2;
    TString label_r1;
    TString title_r1;
    TString label_r2;
    TString title_r2;
};

struct plot_Teff {
    TEfficiency* ratio_r1;
    TEfficiency* ratio_r2;
    TString label_r1;
    TString label_r2;
};

void reading_distributions_histograms(const std::string& sample, const std::vector<std::string>& list_of_histograms, const std::vector<std::string>& comparison_list, const std::string& output_folder);
//void plot_ratios_acceptance(TString name_plot, TString output_folder);
//void plot_ratios_acceptance_group(TString name_plot, TString output_folder);
//void plot_distributions_comparison(TString name_plot, TString output_folder);
//void plot_2D_distributions(TString name_plot, TString output_folder);
void plot_distributions_comparisons(const std::string& name_plot, const std::string& output_folder);
void plot_distributions(const std::string& name_plot, const std::string& output_folder);
void process_label(string name_sample);

string output_analysis_folder = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis/";

//**********************************************************************************
// Definition of the functions above
//**********************************************************************************

void reading_distributions_histograms(const std::string& sample, const std::vector<std::string>& list_of_histograms, const std::vector<std::string>& comparison_list, const std::string& output_folder){

  //string path_root_file = output_analysis_folder+"/"+sample+".root";

  //TFile* file = TFile::Open(path_root_file.c_str());
  TFile* file = TFile::Open(sample.c_str());

  if(!file || file->IsZombie()){
    std::cerr << "Error opening file: " << sample << std::endl;
    if (file) file->Close();
  }
  else{
    cout << "The file has been read " << sample << endl;
  }

  hist_truth_b1_m = dynamic_cast<TH1F*>(file->Get(("hist_truth_b1_m")));
  hist_truth_b2_m = dynamic_cast<TH1F*>(file->Get(("hist_truth_b2_m")));
  hist_truth_b1_plus_b2_m = dynamic_cast<TH1F*>(file->Get(("hist_truth_b1_plus_b2_m")));
  hist_matched_recojet_bb_m = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_m")));
  hist_matched_recojet_tautau_m = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_m")));
  hist_matched_recojet_bb_pt = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_pt")));
  hist_matched_recojet_tautau_pt = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_pt")));
  hist_matched_recojet_bb_eta = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_eta")));
  hist_matched_recojet_tautau_eta = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_eta")));
  hist_matched_recojet_bb_dR = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_dR")));
  hist_matched_recojet_tautau_dR = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_dR")));
  hist_non_matched_recojet_pt = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_pt")));
  hist_non_matched_recojet_eta = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_eta")));
  hist_non_matched_recojet_pt_no_class = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_pt_no_class")));
  hist_non_matched_recojet_eta_no_class = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_eta_no_class")));
  hist_nevents_per_class = dynamic_cast<TH1F*>(file->Get(("hist_nevents_per_class")));

  //tau_nProng histograms
  hist_matched_recojet_bb_tau_n_prong = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_tau_n_prong")));
  hist_matched_recojet_tautau_tau_n_prong = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_tau_n_prong")));
  hist_non_matched_recojet_bb_tau_n_prong = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_bb_tau_n_prong")));
  hist_non_matched_recojet_tautau_tau_n_prong = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_tautau_tau_n_prong")));
  
  //n1 subjettiness
  hist_matched_recojet_bb_tau_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_tau_n1_subjettiness")));
  hist_matched_recojet_tautau_tau_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_tau_n1_subjettiness")));
  hist_non_matched_recojet_bb_tau_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_bb_tau_n1_subjettiness")));
  hist_non_matched_recojet_tautau_tau_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_tautau_tau_n1_subjettiness")));
  
  //n2 subjettiness
  hist_matched_recojet_bb_tau_n2_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_tau_n2_subjettiness")));
  hist_matched_recojet_tautau_tau_n2_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_tau_n2_subjettiness")));
  hist_non_matched_recojet_bb_tau_n2_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_bb_tau_n2_subjettiness")));
  hist_non_matched_recojet_tautau_tau_n2_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_tautau_tau_n2_subjettiness")));
  
  //n2 over n1 subjettiness
  hist_matched_recojet_bb_tau_n2_over_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_tau_n2_over_n1_subjettiness")));
  hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness")));
  hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness")));
  hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness")));
  
  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii], output_folder);
  }

  for(int ii=0; ii < comparison_list.size(); ii++){
    plot_distributions_comparisons(comparison_list[ii], output_folder);
  }

  file->Close();
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                          
// for the two configurations, boosted and resolved                                                                                         

void plot_distributions_comparisons(const std::string& name_plot, const std::string& output_folder){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  string name_image = output_folder+"/plots_substructure_jets/comparison_plots/"+name_plot+".png";
  //string name_image = "plots_ratios/"+name_plot+".png";
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);
  TLegend *leg = new TLegend(0.7, 0.75, 0.85, 0.85);
  TH1F *hist_boosted = new TH1F();
  TH1F *hist_resolved = new TH1F();

  if(name_plot=="bb_tau_nProng"){
    hist_boosted = hist_matched_recojet_bb_tau_n_prong;
    hist_resolved = hist_non_matched_recojet_bb_tau_n_prong;
  }

  if(name_plot=="tautau_tau_nProng"){
    hist_boosted = hist_matched_recojet_tautau_tau_n_prong;
    hist_resolved = hist_non_matched_recojet_tautau_tau_n_prong;
  }

  if(name_plot=="bb_n1_subjettiness"){
    hist_boosted = hist_matched_recojet_bb_tau_n1_subjettiness;
    hist_resolved = hist_non_matched_recojet_bb_tau_n1_subjettiness;
  }

  if(name_plot=="tautau_n1_subjettiness"){
    hist_boosted = hist_matched_recojet_tautau_tau_n1_subjettiness;
    hist_resolved = hist_non_matched_recojet_tautau_tau_n1_subjettiness;
  }
    
  if(name_plot=="bb_n2_subjettiness"){
    hist_boosted = hist_matched_recojet_bb_tau_n2_subjettiness;
    hist_resolved = hist_non_matched_recojet_bb_tau_n2_subjettiness;
  }

  if(name_plot=="tautau_n2_subjettiness"){
    hist_boosted = hist_matched_recojet_tautau_tau_n2_subjettiness;
    hist_resolved = hist_non_matched_recojet_tautau_tau_n2_subjettiness;
  }

  if(name_plot=="bb_n2_over_n1_subjettiness"){
    hist_boosted = hist_matched_recojet_bb_tau_n2_over_n1_subjettiness;
    hist_resolved = hist_non_matched_recojet_bb_tau_n2_over_n1_subjettiness;
  }

  if(name_plot=="tautau_n2_over_n1_subjettiness"){
    hist_boosted = hist_matched_recojet_tautau_tau_n2_over_n1_subjettiness;
    hist_resolved = hist_non_matched_recojet_tautau_tau_n2_over_n1_subjettiness;
  }
  
  hist_boosted->SetStats(0);
  hist_boosted->SetFillStyle(3001);
  hist_boosted->SetFillColorAlpha(kBlue, 0.45);
  hist_boosted->SetLineColor(4);
  
  hist_resolved->SetStats(0);
  hist_resolved->SetFillStyle(3003);
  hist_resolved->SetFillColorAlpha(kRed, 0.45);
  hist_resolved->SetLineColor(2);

  hist_boosted->DrawNormalized("H");
  hist_resolved->DrawNormalized("sameH");
  
  leg->AddEntry(hist_boosted, "boosted jets", "l");
  leg->AddEntry(hist_resolved,"resolved jets","l");
  leg->SetBorderSize();
  leg->Draw();
  
  double dely = 0.04;
  myText(0.2, 0.8, kBlack, process_name.c_str());
  //  myText(0.2, 0.8-dely, kBlack, "for class: "+label_leg);
  myText(0.2, 0.8-dely, kBlack, name_plot.c_str());

  can->Draw();
  can->SaveAs(name_image.c_str());

}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                          
// for the two configurations, boosted and resolved                                                                                         

void plot_distributions(const std::string& name_plot, const std::string& output_folder){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  string name_image = output_folder+"/plots_substructure_jets/"+name_plot+".png";
  //string name_image = "plots_ratios/"+name_plot+".png";
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);
  TH1F *hist = new TH1F();
  
  if(name_plot == "truth_b1_m"){ hist = hist_truth_b1_m;}
  if(name_plot == "truth_b2_m"){ hist = hist_truth_b2_m;}
  if(name_plot == "truth_b1_plus_b2_m"){ hist = hist_truth_b1_plus_b2_m;}

  if(name_plot == "matched_recojet_bb_m"){ hist = hist_matched_recojet_bb_m;}
  if(name_plot == "matched_recojet_tautau_m"){ hist = hist_matched_recojet_tautau_m;}
  
  if(name_plot == "matched_recojets_bb_pt"){ hist = hist_matched_recojet_bb_pt;}
  if(name_plot == "matched_recojets_tautau_pt"){ hist = hist_matched_recojet_tautau_pt;}
  
  if(name_plot == "matched_recojets_bb_eta"){ hist = hist_matched_recojet_bb_eta;}
  if(name_plot == "matched_recojets_tautau_eta"){ hist = hist_matched_recojet_tautau_eta;}

  if(name_plot == "matched_bb_dR"){ hist = hist_matched_recojet_bb_dR;}
  if(name_plot == "matched_tautau_dR"){ hist = hist_matched_recojet_tautau_dR;}

  if(name_plot == "non_matched_recojets_pt"){ hist = hist_non_matched_recojet_pt;}
  if(name_plot == "non_matched_recojets_eta"){ hist = hist_non_matched_recojet_eta;}

  if(name_plot == "non_matched_recojets_pt_no_class"){ hist = hist_non_matched_recojet_pt_no_class;}
  if(name_plot == "non_matched_recojets_eta_no_class"){ hist = hist_non_matched_recojet_eta_no_class;}

  if(name_plot == "events_per_class"){ hist = hist_nevents_per_class;}
  
  hist->Draw();

  double dely = 0.04;
  myText(0.2, 0.8, kBlack, process_name.c_str());
  //  myText(0.2, 0.8-dely, kBlack, "for class: "+label_leg);
  myText(0.2, 0.8-dely, kBlack, name_plot.c_str());

  can->Draw();
  can->SaveAs(name_image.c_str());

}

// Plot 2d histograms

/*
void plot_2D_distributions(TString name_plot, TString output_folder){

  gROOT->SetBatch(kTRUE);
  TString name_image = output_folder+"/plots_substructure_jets/"+name_plot+".png";
  
  ///// Plotting
  
  SetAtlasStyle();

  TCanvas *can = new TCanvas("can","", 800, 600);
  TH2F *hist = new TH2F();
  
  if(name_plot == "dR_per_class_bb"){ hist = hist2d_dR_per_class_bb;}
  if(name_plot == "dR_per_class_tautau"){ hist = hist2d_dR_per_class_tautau;}
  
  //gStyle->SetPalette(52);                                                                                                                   
  //TColor::InvertPalette();                                                                                                                  
  
  //hist->SetStats(0);
  //hist->Draw("SURF");
  hist->GetXaxis()->SetBinLabel(1, "R_{bb}-R_{#tau#tau}");
  hist->GetXaxis()->SetBinLabel(2, "R_{bb}-B_{#tau#tau}");
  hist->GetXaxis()->SetBinLabel(3, "B_{bb}-R_{#tau#tau}");
  hist->GetXaxis()->SetBinLabel(4, "B_{bb}-B_{#tau#tau}");
  
  //  hist->Draw("SCAT");                                                                                                                     
  //  hist->Draw("colz");                                                                                                                     
  hist->Draw();

  double dely = 0.04;
  myText(0.2, 0.8, kBlack, process_name);
  //myText(0.2, 0.8-dely, kBlack, "for class: "+label_leg);
  myText(0.2, 0.8-2*dely, kBlack, name_plot);
  
  can->Draw();
  can->Print(name_image);
}


// Plot distribution comparisons                                                                                                              

void plot_distributions_comparison(TString name_plot, TString output_folder){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  TLegend *leg = new TLegend(0.7, 0.75, 0.85, 0.85);
  TH1F *hist1 = new TH1F();
  TH1F *hist2 = new TH1F();
  TString name_image = output_folder+"/plots_comparison/"+name_plot+".png";
  
  if(name_plot=="HH_pt_comparison"){
    hist1 = hist_truth_HH_pt;
    hist2 = hist_computed_HH_pt;
  }
  
  if(name_plot=="HH_m_comparison"){
    hist1 = hist_truth_HH_m;
    hist2 = hist_computed_HH_m;
  }
  
  hist1->SetStats(0);
  hist1->SetFillStyle(3001);
  hist1->SetFillColorAlpha(kBlue, 0.45);
  hist1->SetLineColor(4);
  
  hist2->SetStats(0);
  hist2->SetFillStyle(3003);
  hist2->SetFillColorAlpha(kRed, 0.45);
  hist2->SetLineColor(2);
  
  ///// Plotting
  
  TCanvas *can = new TCanvas("can","", 800, 600);
  
  hist1->Draw("H");
  hist2->Draw("sameH");

  leg->AddEntry(hist1, "truth", "l");
  leg->AddEntry(hist2, "computed","l");
  leg->SetBorderSize();
  leg->Draw();

  double dely = 0.04;
  myText(0.2, 0.8, kBlack, process_name);
  //myText(0.2, 0.8-dely, kBlack, "for class: "+label_leg);
  myText(0.2, 0.8-dely, kBlack, name_plot);
  
  can->Draw();
  can->SaveAs(name_image);
  
  //TString process_label = process_name.ReplaceAll(" ", "_");
  //process_label = process_label.replace(" ", "_");
  //can->SaveAs("output_analysis/temp_folder/"+name_plot+"_"+process_label+".png");
}
*/

void process_label(string name_sample){

  // ggF processes had-had channel
  if(name_sample.find("600459")==true){ process_name = "ggF HH SM had-had channel"; name_output_root_file = "ggF_SM_hh_600459.root";}
  if(name_sample.find("600460")==true){ process_name = "ggF HH #lambda = 10 had-had channel"; name_output_root_file = "ggF_lambda10_hh_600460.root";}

  // ggF processes lep-had channel
  if(name_sample.find("600461")==true){ process_name = "ggF HH SM lep-had channel"; name_output_root_file = "ggF_SM_lh_600461.root";}
  if(name_sample.find("600462")==true){ process_name = "ggF HH #lambda = 10 lep-had channel"; name_output_root_file = "ggF_lambda10_lh_600462.root";}

  //vbf processes had-had channel
  if(name_sample.find("502982")==true){ process_name = "VBF HH SM had-had channel"; name_output_root_file = "VBF_SM_hh_502982.root";}
  if(name_sample.find("502985")==true){ process_name = "VBF HH C_{VV} = 1.5 had-had channel"; name_output_root_file = "VBF_cvv1p5_hh_502985.root";}
  if(name_sample.find("502989")==true){ process_name = "VBF HH #lambda = 2.0 had-had channel"; name_output_root_file = "VBF_l2_hh_502989.root";}
  if(name_sample.find("502990")==true){ process_name = "VBF HH #lambda = 10.0 had-had channel"; name_output_root_file = "VBF_l10_hh_502990.root";}
  if(name_sample.find("502991")==true){ process_name = "VBF HH C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_cv0p5_hh_502991.root";}
  if(name_sample.find("508690")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_l5cv0p5_hh_508690.root";}

  //vbf processes lep-had channel
  if(name_sample.find("502993")==true){ process_name = "VBF HH SM lep-had channel"; name_output_root_file = "VBF_SM_lh_502993.root";}
  if(name_sample.find("502996")==true){ process_name = "VBF HH C_{VV} = 1.5 lep-had channel"; name_output_root_file = "VBF_cvv1p5_lh_502996.root";}
  if(name_sample.find("503000")==true){ process_name = "VBF HH #lambda = 2.0 lep-had channel"; name_output_root_file = "VBF_l2_lh_503000.root";}
  if(name_sample.find("503001")==true){ process_name = "VBF HH #lambda = 10.0 lep-had channel"; name_output_root_file = "VBF_l10_lh_503001.root";}
  if(name_sample.find("503002")==true){ process_name = "VBF HH C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_cv0p5_lh_503002.root";}
  if(name_sample.find("508691")==true){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_l5cv0p5_lh_508691.root";}

  //vbf SM processes both channels channel
  if(name_sample.find("vbf_SM_both_channels")==true){ process_name = "VBF HH SM"; }

  //vbf SM processes both channels channel
  if(name_sample.find("ggf_SM_both_channels")==true){ process_name = "ggF HH SM"; }

  //vbf Cvv=1.5 processes both channels channel
  if(name_sample.find("vbf_l1cvv1p5cv1_both_channels")==true){ process_name = "VBF HH C_{VV} = 1.5"; }

  //ggf cHHH = 10 processes both channels channel
  if(name_sample.find("ggf_cHHH10d0_both_channels")==true){ process_name = "ggF HH #lambda = 10"; }
}


/*
void plot_ratios_acceptance(TString name_plot, TString output_folder){

  gROOT->SetBatch(kTRUE);
  auto it = plotMap.find(name_plot.Data()); // Data() is used to convert TString to string
  if (it != plotMap.end()) { // If the plot name was found
    
    SetAtlasStyle();
    PlotInfo plotInfo = it->second; // Access the PlotInfo struct
    //TString name_image = output_folder+"/plots_ratios/"+name_plot+".png";
    TString name_image = "plots_ratios/"+name_plot+".png";
    TH1F *hist_num = plotInfo.hist_num;
    TH1F *hist_den = plotInfo.hist_den;
    TString label_leg = plotInfo.label;
    TString title_plot = plotInfo.title;

    TEfficiency *pEff = new TEfficiency(*hist_num, *hist_den);
    pEff->SetTitle(title_plot);
    pEff->SetName(name_plot);

    //pEff->SetMaximum(1.25);
    
    ///// Plotting                                                                                                                           

    TCanvas *can = new TCanvas("can","can", 800, 600);
    //TLegend *leg = new TLegend(0.25, 0.70, 0.40, 0.80);
    
    pEff->Draw("AP");
    gPad->Update(); 
    auto graph = pEff->GetPaintedGraph(); 
    graph->SetMinimum(0);
    graph->SetMaximum(1.25); 
    gPad->Update(); 

    double dely = 0.05;
    myText(0.2, 0.9, kBlack, process_name);
    myText(0.2, 0.9-dely, kBlack, "for class: "+label_leg);
    myText(0.2, 0.9-2*dely, kBlack, name_plot);

    //can->Draw();
    can->SaveAs(name_image);
    //TString process_label = process_name;
    //process_label = process_label.ReplaceAll(" ", "_");
    //process_label = process_label.replace(" ", "_");
    //can->SaveAs("output_analysis/temp_folder/"+name_plot+"_"+process_label+".png");

    // ***********************************************
    // hist numerator
    // ***********************************************

    //    TCanvas *can = new TCanvas("can","can", 800, 600);
    hist_num->Draw("H");
    //name_image = output_folder+"/plots_ratios/"+name_plot+"_hist_num.png";
    name_image = "plots_ratios/"+name_plot+"_hist_num.png";
    myText(0.2, 0.9, kBlack, process_name);
    myText(0.2, 0.9-dely, kBlack, "for class: "+label_leg);
    myText(0.2, 0.9-2*dely, kBlack, name_plot+"_hist_num.png");
    can->SaveAs(name_image);

    // ***********************************************
    // hist denominator
    // ***********************************************

    //    TCanvas *can = new TCanvas("can","can", 800, 600);
    hist_den->Draw("H");
    //name_image = output_folder+"/plots_ratios/"+name_plot+"_hist_den.png";
    name_image = "plots_ratios/"+name_plot+"_hist_den.png";
    myText(0.2, 0.9, kBlack, process_name);
    myText(0.2, 0.9-dely, kBlack, "for class: "+label_leg);
    myText(0.2, 0.9-2*dely, kBlack, name_plot+"_hist_den.png");
    can->SaveAs(name_image);
  }
  else {
    // Handle the case where the plot name is not found
    std::cout << "Plot name " << name_plot << " not found!" << endl;
  }    
}
*/
