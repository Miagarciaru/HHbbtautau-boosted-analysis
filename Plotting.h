#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
#include "declaration_of_variables.h"

void plot_ratios_acceptance(TString name_plot, TString output_folder);
void plot_ratios_acceptance_group(TString name_plot, TString output_folder);
void plot_distributions_comparison(TString name_plot, TString output_folder);
void plot_2D_distributions(TString name_plot, TString output_folder);
void plot_distributions(TString name_plot, TString output_folder);


void plot_ratios_acceptance(TString name_plot, TString output_folder){

  auto it = plotMap.find(name_plot.Data()); // Data() is used to convert TString to string
  if (it != plotMap.end()) { // If the plot name was found
    
    SetAtlasStyle();
    PlotInfo plotInfo = it->second; // Access the PlotInfo struct
    TString name_image = output_folder+"/plots_ratios/"+name_plot+".png";
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
    name_image = output_folder+"/plots_ratios/"+name_plot+"_hist_num.png";
    myText(0.2, 0.9, kBlack, process_name);
    myText(0.2, 0.9-dely, kBlack, "for class: "+label_leg);
    myText(0.2, 0.9-2*dely, kBlack, name_plot+"_hist_num.png");
    can->SaveAs(name_image);

    // ***********************************************
    // hist denominator
    // ***********************************************

    //    TCanvas *can = new TCanvas("can","can", 800, 600);
    hist_den->Draw("H");
    name_image = output_folder+"/plots_ratios/"+name_plot+"_hist_den.png";
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


void plot_ratios_acceptance_group(TString name_plot, TString output_folder){

  TLegend *leg = new TLegend(0.15, 0.60, 0.30, 0.80);

  TString name_image = output_folder+"/plots_ratios/"+name_plot+".png";

  TH1F *hist_ratio_class0_r1 = (TH1F*)hist_acceptance_mHH_numerator_class0->Clone("hist_ratio_class0_r1");
  TH1F *hist_ratio_class1_r1 = (TH1F*)hist_acceptance_mHH_numerator_class1->Clone("hist_ratio_class1_r1");
  TH1F *hist_ratio_class2_r1 = (TH1F*)hist_acceptance_mHH_numerator_class2->Clone("hist_ratio_class2_r1");
  TH1F *hist_ratio_class3_r1 = (TH1F*)hist_acceptance_mHH_numerator_class3->Clone("hist_ratio_class3_r1");

  hist_ratio_class0_r1->SetStats(0);
  hist_ratio_class0_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class0_r1->SetLineColor(2);

  hist_ratio_class1_r1->SetStats(0);
  hist_ratio_class1_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class1_r1->SetLineColor(3);

  hist_ratio_class2_r1->SetStats(0);
  hist_ratio_class2_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class2_r1->SetLineColor(6);

  hist_ratio_class3_r1->SetStats(0);
  hist_ratio_class3_r1->Divide(hist_acceptance_mHH_denominator);
  hist_ratio_class3_r1->SetLineColor(4);

  ///// Plotting
  
  TCanvas *can = new TCanvas("can","", 800, 600);

  hist_ratio_class0_r1->Draw("H");
  hist_ratio_class1_r1->Draw("sameH");
  hist_ratio_class2_r1->Draw("sameH");
  hist_ratio_class3_r1->Draw("sameH");

  leg->AddEntry(hist_ratio_class0_r1, "R_{bb}-R_{#tau#tau}", "l");
  leg->AddEntry(hist_ratio_class1_r1, "R_{bb}-B_{#tau#tau}", "l");
  leg->AddEntry(hist_ratio_class2_r1, "B_{bb}-R_{#tau#tau}", "l");
  leg->AddEntry(hist_ratio_class3_r1, "B_{bb}-B_{#tau#tau}", "l");

  leg->SetBorderSize();
  leg->Draw();

  can->Draw();
  can->Print(name_image);

}


// This functions plots some distributions for the H_bb and H_tautau and compare the distributions                                            
// for the two configurations, boosted and resolved                                                                                           
void plot_distributions(TString name_plot, TString output_folder){
  
  TString name_image = output_folder+"/plots_substructure_jets/"+name_plot+".png";
  
  ///// Plotting

  SetAtlasStyle();

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
  myText(0.2, 0.8, kBlack, process_name);
  //  myText(0.2, 0.8-dely, kBlack, "for class: "+label_leg);
  myText(0.2, 0.8-dely, kBlack, name_plot);
  can->Draw();
  can->Print(name_image);
}

// Plot 2d histograms                                                                                                                         
void plot_2D_distributions(TString name_plot, TString output_folder){
  
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
