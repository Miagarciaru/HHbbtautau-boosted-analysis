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

  SetAtlasStyle();
  
  TLegend *leg = new TLegend(0.25, 0.70, 0.40, 0.80);
  
  TString name_image = output_folder+"/plots_ratios/"+name_plot+".png";

  TH1F *hist_ratio = new TH1F();
  TH1F *hist_ratio_den = new TH1F();
  
  TString label_leg = "";
  TString title_plot = "";
  TString process_name = "VBF HH C_{2V}=1.5 had-had channel";
  
  TEfficiency *pEff = 0;
  
  if(name_plot == "class0_r1_mHH"){
    TH1F *hist_ratio = (TH1F*)hist_acceptance_mHH_numerator_class0->Clone();
    TH1F *hist_ratio_den = (TH1F*)hist_acceptance_mHH_denominator->Clone();
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class0, *hist_acceptance_mHH_denominator)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class0, *hist_acceptance_mHH_denominator);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "R_{bb}-R_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  
  if(name_plot == "class1_r1_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class1;
    hist_ratio_den = hist_acceptance_mHH_denominator;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class1, *hist_acceptance_mHH_denominator)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class1, *hist_acceptance_mHH_denominator);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "R_{bb}-B_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  if(name_plot == "class2_r1_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class2;
    hist_ratio_den = hist_acceptance_mHH_denominator;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class2, *hist_acceptance_mHH_denominator)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class2, *hist_acceptance_mHH_denominator);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "B_{bb}-R_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  if(name_plot == "class3_r1_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class3;
    hist_ratio_den = hist_acceptance_mHH_denominator;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class3, *hist_acceptance_mHH_denominator)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class3, *hist_acceptance_mHH_denominator);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "B_{bb}-B_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{1}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  
  if(name_plot == "class0_r2_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class0;
    hist_ratio_den = hist_acceptance_mHH_denominator_class0;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class0, *hist_acceptance_mHH_denominator_class0)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class0, *hist_acceptance_mHH_denominator_class0);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "R_{bb}-R_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  if(name_plot == "class1_r2_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class1;
    hist_ratio_den = hist_acceptance_mHH_denominator_class1;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class1, *hist_acceptance_mHH_denominator_class1)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class1, *hist_acceptance_mHH_denominator_class1);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "R_{bb}-B_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  if(name_plot == "class2_r2_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class2;
    hist_ratio_den = hist_acceptance_mHH_denominator_class2;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class2, *hist_acceptance_mHH_denominator_class2)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class2, *hist_acceptance_mHH_denominator_class2);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "B_{bb}-R_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  if(name_plot == "class3_r2_mHH"){
    hist_ratio = hist_acceptance_mHH_numerator_class3;
    hist_ratio_den = hist_acceptance_mHH_denominator_class3;
    if(TEfficiency::CheckConsistency(*hist_acceptance_mHH_numerator_class3, *hist_acceptance_mHH_denominator_class3)){
      pEff = new TEfficiency(*hist_acceptance_mHH_numerator_class3, *hist_acceptance_mHH_denominator_class3);
      cout << "Both histograms were consistent" << endl;
    }
    label_leg = "B_{bb}-B_{#tau#tau}";
    title_plot = "Acceptance plot using the mass mHH variable (r_{2}); m(HH) [GeV];Ratio";
    cout << "The copy of the histograms was succesful" << endl;
  }
  hist_ratio->SetStats(0);
  hist_ratio->Divide(hist_ratio_den);
  hist_ratio->SetTitle(title_plot);
  hist_ratio->SetLineColor(1);
  
  ///// Plotting                                                                                                                                            
  TCanvas *can = new TCanvas("can","", 800, 600);
  
  //hist_ratio_class0_r1->SetMaximum(1.05);                                                                                                   
  
  //hist_ratio->Draw("H");                                                                                                                    
  
  pEff->SetTitle(title_plot);
  pEff->Draw("AP");

  TLatex l;
  l.SetNDC();
  l.SetTextFont(42);
  l.SetTextColor(kBlack);
  l.SetTextSize(0.035);
  l.DrawLatex(0.15,0.8,Form(process_name));
  
  TLatex o;
  o.SetNDC();
  o.SetTextFont(42);
  o.SetTextColor(kBlack);
  o.SetTextSize(0.03);
  double dely = 0.04;
  o.DrawLatex(0.15,0.8-dely, Form("for class:"));
  o.DrawLatex(0.15,0.76-dely, Form(label_leg));
  /*                                                                                                                                          
																	      leg->AddEntry(hist_ratio, label_leg, "l");                                                                                                  
																	      leg->SetBorderSize();                                                                                                                       
																	      leg->Draw();                                                                                                                                
  */
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
  
  hist->SetStats(0);
  //hist->Draw("SURF");
  hist->GetXaxis()->SetBinLabel(1, "R_{bb}-R_{#tau#tau}");
  hist->GetXaxis()->SetBinLabel(2, "R_{bb}-B_{#tau#tau}");
  hist->GetXaxis()->SetBinLabel(3, "B_{bb}-R_{#tau#tau}");
  hist->GetXaxis()->SetBinLabel(4, "B_{bb}-B_{#tau#tau}");
  
  //  hist->Draw("SCAT");                                                                                                                     
  //  hist->Draw("colz");                                                                                                                     
  hist->Draw();
  
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
  
  if(name_plot=="truth_HH_pt_comparison"){
    hist1 = hist_truth_HH_pt;
    hist2 = hist_computed_HH_pt;
  }
  
  if(name_plot=="truth_HH_m_comparison"){
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
  
  can->Draw();
  can->Print(name_image);
}
