#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"

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

// preselected events for m, pT and eta
TH1F* hist_matched_preselected_bb_m;
TH1F* hist_matched_preselected_tautau_m;
TH1F* hist_matched_preselected_bb_pt;
TH1F* hist_matched_preselected_tautau_pt;
TH1F* hist_matched_preselected_bb_eta;
TH1F* hist_matched_preselected_tautau_eta;

//tau_nProng histograms
TH1F* hist_matched_recojet_bb_tau_n_prong;
TH1F* hist_matched_recojet_tautau_tau_n_prong;
TH1F* hist_non_matched_recojet_bb_tau_n_prong;
TH1F* hist_non_matched_recojet_tautau_tau_n_prong;

//GN2X phbb
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_phbb;
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_phbb;
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb;
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb;

TH1F *hist_matched_preselected_bb_ak10_GN2Xv01_phbb;
TH1F *hist_matched_preselected_tautau_ak10_GN2Xv01_phbb;

//GN2X pqcd
TH1F *hist_matched_recojet_bb_ak10_GN2Xv01_pqcd;
TH1F *hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd;
TH1F *hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd;
TH1F *hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd;

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

TH1F* hist_matched_preselected_bb_tau_n2_over_n1_subjettiness;
TH1F* hist_matched_preselected_recojet_tautau_tau_n2_over_n1_subjettiness;

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

void reading_distributions_histograms(const std::string& sample, const std::vector<std::string>& list_of_histograms, const std::vector<std::string>& comparison_list, const std::string& output_folder, const std::string& minpT);
void plot_distributions_comparisons(const std::string& name_plot, const std::string& output_folder, const std::string& minpT);
void plot_distributions(const std::string& name_plot, const std::string& output_folder);
void process_label(string name_sample);

string output_analysis_folder = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis_oct24/";

//**********************************************************************************
// Definition of the functions above
//**********************************************************************************

void reading_distributions_histograms(const std::string& sample, const std::vector<std::string>& list_of_histograms, const std::vector<std::string>& comparison_list, const std::string& output_folder, const std::string& minpT){

  //string path_root_file = output_analysis_folder+"/"+sample+".root";

  TFile* file = TFile::Open(sample.c_str());

  cout << "------------------------------------------------------" << endl;
  cout << sample << endl;
  cout << "------------------------------------------------------" << endl;
  
  if(!file || file->IsZombie()){
    std::cerr << "Error opening file: " << sample << std::endl;
    if (file) file->Close();
  }
  else{
    cout << "The file has been read " << sample << endl;
  }

  hist_matched_recojet_bb_m = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_m")));
  hist_matched_recojet_tautau_m = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_m")));
  hist_matched_recojet_bb_pt = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_pt")));
  hist_matched_recojet_tautau_pt = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_pt")));
  hist_matched_recojet_bb_eta = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_eta")));
  hist_matched_recojet_tautau_eta = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_eta")));
  hist_matched_recojet_bb_dR = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_dR")));
  hist_matched_recojet_tautau_dR = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_dR")));

  hist_matched_preselected_bb_m = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_bb_m")));
  hist_matched_preselected_tautau_m = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_tautau_m")));
  hist_matched_preselected_bb_pt = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_bb_pt")));
  hist_matched_preselected_tautau_pt = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_tautau_pt")));
  hist_matched_preselected_bb_eta = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_bb_eta")));
  hist_matched_preselected_tautau_eta = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_tautau_eta")));
  
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

  //GN2X phbb
  hist_matched_recojet_bb_ak10_GN2Xv01_phbb = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_ak10_GN2Xv01_phbb")));
  hist_matched_recojet_tautau_ak10_GN2Xv01_phbb = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_ak10_GN2Xv01_phbb")));
  hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb")));
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb")));

  hist_matched_preselected_bb_ak10_GN2Xv01_phbb = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_bb_ak10_GN2Xv01_phbb")));
  hist_matched_preselected_tautau_ak10_GN2Xv01_phbb = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_tautau_ak10_GN2Xv01_phbb")));
  
  //GN2X pqcd
  hist_matched_recojet_bb_ak10_GN2Xv01_pqcd = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_bb_ak10_GN2Xv01_pqcd")));
  hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd = dynamic_cast<TH1F*>(file->Get(("hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd")));
  hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd")));
  hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd = dynamic_cast<TH1F*>(file->Get(("hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd")));
  
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

  //hist_matched_preselected_bb_tau_n2_over_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_bb_tau_n2_over_n1_subjettiness")));
  //hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness = dynamic_cast<TH1F*>(file->Get(("hist_matched_preselected_tautau_tau_n2_over_n1_subjettiness")));
  
  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii], output_folder);
  }

  for(int ii=0; ii < comparison_list.size(); ii++){
    plot_distributions_comparisons(comparison_list[ii], output_folder, minpT);
  }

  file->Close();
}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                          
// for the two configurations, boosted and resolved                                                                                         

void plot_distributions_comparisons(const std::string& name_plot, const std::string& output_folder, const std::string& minpT){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  string name_image = output_folder+"/plots_substructure_jets/comparison_plots/"+name_plot+".png";
  //string name_image = "plots_ratios/"+name_plot+".png";
  
  ///// Plotting
  TCanvas *can = new TCanvas("can","", 800, 600);
  TLegend *leg = new TLegend(0.7, 0.75, 0.9, 0.9);
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

  if(name_plot=="bb_GN2X_phbb"){
    hist_boosted = hist_matched_recojet_bb_ak10_GN2Xv01_phbb;
    hist_resolved = hist_non_matched_recojet_bb_ak10_GN2Xv01_phbb;
  }

  if(name_plot=="tautau_GN2X_phbb"){
    hist_boosted = hist_matched_recojet_tautau_ak10_GN2Xv01_phbb;
    hist_resolved = hist_non_matched_recojet_tautau_ak10_GN2Xv01_phbb;
  }

  if(name_plot=="bb_GN2X_pqcd"){
    hist_boosted = hist_matched_recojet_bb_ak10_GN2Xv01_pqcd;
    hist_resolved = hist_non_matched_recojet_bb_ak10_GN2Xv01_pqcd;
  }

  if(name_plot=="tautau_GN2X_pqcd"){
    hist_boosted = hist_matched_recojet_tautau_ak10_GN2Xv01_pqcd;
    hist_resolved = hist_non_matched_recojet_tautau_ak10_GN2Xv01_pqcd;
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

  string label_boosted = "";
  string label_resolved = "";
  
  if(name_plot.find("bb")!=std::string::npos){
    label_boosted = "boosted bb jet";
    label_resolved = "single b jet";
  }
  if(name_plot.find("tautau")!=std::string::npos){
    label_boosted = "boosted #tau#tau jet";
    label_resolved = "single #tau jet";
  }
  
  hist_boosted->SetStats(0);
  hist_boosted->SetFillStyle(3001);
  hist_boosted->SetFillColorAlpha(kBlue, 0.45);
  hist_boosted->SetLineColor(4);
  
  hist_resolved->SetStats(0);
  hist_resolved->SetFillStyle(3003);
  hist_resolved->SetFillColorAlpha(kRed, 0.45);
  hist_resolved->SetLineColor(2);

  // Step 1: Normalize the histograms manually (or use DrawNormalized to visualize them directly).
  //hist_boosted->Scale(1.0 / hist_boosted->Integral());
  //hist_resolved->Scale(1.0 / hist_resolved->Integral());

  // Step 2: Get the maximum value of each histogram after normalization.
  double max_boosted = hist_boosted->GetMaximum();
  double max_resolved = hist_resolved->GetMaximum();

  // Step 3: Set the y-axis maximum to the maximum of the two histograms.
  double y_max = std::max(max_boosted, max_resolved);

  // Optionally, you can set the y-axis maximum slightly higher than the actual maximum value for better visualization.
  y_max = y_max*1.5;  // Increase by 10% for padding
  
  // Step 4: Draw the histograms and set the maximum.
  hist_boosted->SetMaximum(y_max);
  hist_resolved->SetMaximum(y_max);
  
  // Step 5: Draw the histograms on the same canvas for comparison.
  hist_boosted->Draw("H");   // Draw the first histogram
  hist_resolved->Draw("sameH");  // Draw the second histogram on the same canvas
  
  leg->AddEntry(hist_boosted, label_boosted.c_str(), "l");
  leg->AddEntry(hist_resolved, label_resolved.c_str(),"l");
  leg->SetBorderSize();
  leg->Draw();
  
  double dely = 0.05;
  myText(0.2, 0.9, kBlack, process_name.c_str());
  myText(0.2, 0.9-dely, kBlack, name_plot.c_str());
  myText(0.2, 0.9-2*dely, kBlack, ("for a min p_{T}: "+minpT+" GeV").c_str());
  
  can->Draw();
  can->SaveAs(name_image.c_str());

}

// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                          
// for the two configurations, boosted and resolved                                                                                         

void plot_distributions(const std::string& name_plot, const std::string& output_folder){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();
  
  string name_image = output_folder+"/plots_substructure_jets/"+name_plot+".png";
  
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

  if(name_plot == "matched_preselected_bb_m"){ hist = hist_matched_preselected_bb_m;}
  if(name_plot == "matched_preselected_tautau_m"){ hist = hist_matched_preselected_tautau_m;}
  
  if(name_plot == "matched_preselected_bb_pt"){ hist = hist_matched_preselected_bb_pt;}
  if(name_plot == "matched_preselected_tautau_pt"){ hist = hist_matched_preselected_tautau_pt;}
  
  if(name_plot == "matched_preselected_bb_eta"){ hist = hist_matched_preselected_bb_eta;}
  if(name_plot == "matched_preselected_tautau_eta"){ hist = hist_matched_preselected_tautau_eta;}

  double y_max = 1.25*hist->GetMaximum();
  
  // Step 4: Draw the histograms and set the maximum.

  hist->SetMaximum(y_max);
  
  hist->Draw();

  double dely = 0.04;
  myText(0.2, 0.90, kBlack, process_name.c_str());
  myText(0.2, 0.90-dely, kBlack, name_plot.c_str());

  can->Draw();
  can->SaveAs(name_image.c_str());

}

void process_label(string name_sample){

  // ggF processes had-had channel
  if(name_sample.find("600459") != string::npos){ process_name = "ggF HH SM had-had channel"; name_output_root_file = "ggF_SM_hh_600459.root";}
  if(name_sample.find("600460") != string::npos){ process_name = "ggF HH #lambda = 10 had-had channel"; name_output_root_file = "ggF_lambda10_hh_600460.root";}

  // ggF processes lep-had channel
  if(name_sample.find("600461") != string::npos){ process_name = "ggF HH SM lep-had channel"; name_output_root_file = "ggF_SM_lh_600461.root";}
  if(name_sample.find("600462") != string::npos){ process_name = "ggF HH #lambda = 10 lep-had channel"; name_output_root_file = "ggF_lambda10_lh_600462.root";}

  //vbf processes had-had channel
  if(name_sample.find("502982") != string::npos){ process_name = "VBF HH SM had-had channel"; name_output_root_file = "VBF_SM_hh_502982.root";}
  if(name_sample.find("502985") != string::npos){ process_name = "VBF HH C_{VV} = 1.5 had-had channel"; name_output_root_file = "VBF_cvv1p5_hh_502985.root";}
  if(name_sample.find("502989") != string::npos){ process_name = "VBF HH #lambda = 2.0 had-had channel"; name_output_root_file = "VBF_l2_hh_502989.root";}
  if(name_sample.find("502990") != string::npos){ process_name = "VBF HH #lambda = 10.0 had-had channel"; name_output_root_file = "VBF_l10_hh_502990.root";}
  if(name_sample.find("502991") != string::npos){ process_name = "VBF HH C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_cv0p5_hh_502991.root";}
  if(name_sample.find("508690") != string::npos){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 had-had channel"; name_output_root_file = "VBF_l5cv0p5_hh_508690.root";}

  //vbf processes lep-had channel
  if(name_sample.find("502993") != string::npos){ process_name = "VBF HH SM lep-had channel"; name_output_root_file = "VBF_SM_lh_502993.root";}
  if(name_sample.find("502996") != string::npos){ process_name = "VBF HH C_{VV} = 1.5 lep-had channel"; name_output_root_file = "VBF_cvv1p5_lh_502996.root";}
  if(name_sample.find("503000") != string::npos){ process_name = "VBF HH #lambda = 2.0 lep-had channel"; name_output_root_file = "VBF_l2_lh_503000.root";}
  if(name_sample.find("503001") != string::npos){ process_name = "VBF HH #lambda = 10.0 lep-had channel"; name_output_root_file = "VBF_l10_lh_503001.root";}
  if(name_sample.find("503002") != string::npos){ process_name = "VBF HH C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_cv0p5_lh_503002.root";}
  if(name_sample.find("508691") != string::npos){ process_name = "VBF HH #lambda = 5.0, C_{V} = 0.5 lep-had channel"; name_output_root_file = "VBF_l5cv0p5_lh_508691.root";}

  //vbf SM processes both channels channel
  if(name_sample.find("vbf_SM_both_channels") != string::npos){ process_name = "VBF HH SM"; }

  //vbf SM processes both channels channel
  if(name_sample.find("ggf_SM_both_channels") != string::npos){ process_name = "ggF HH SM"; }

  //vbf Cvv=1.5 processes both channels channel
  if(name_sample.find("vbf_l1cvv1p5cv1_both_channels") != string::npos){ process_name = "VBF HH C_{VV} = 1.5"; }

  //ggf cHHH = 10 processes both channels channel
  if(name_sample.find("ggf_cHHH10d0_both_channels") != string::npos){ process_name = "ggF HH #lambda = 10"; }
}
