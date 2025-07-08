#include "AtlasStyle/AtlasStyle.C"
#include "AtlasStyle/AtlasUtils.C"
#include "AtlasStyle/AtlasLabels.C"
#include <unordered_map>
#include <fstream>

const string path_folder="/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis/";

const string base_output_folder = "output_plots/acceptance_ratios_plots/";

//*******************************************************
// Declaration of functions
//*******************************************************

void plotEfficiencies(const std::vector<std::string>& sampleFiles, const std::string& ratio, const std::string& nameVar,
		      const std::string& min_pT, const std::unordered_map<std::string,
		      std::vector<TEfficiency>>& TEff_ratios, bool proper);
  
void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::string& nameVar,
			     const std::string& min_pT, std::unordered_map<std::string,
			     std::vector<TEfficiency>>& efficiency_map, bool proper);
  
//*******************************************************
// Definition of functions declared above
//*******************************************************

void plotEfficiencies(const std::vector<std::string>& sampleFiles, const std::string& ratio, const std::string& nameVar,
		      const std::string& min_pT, const std::unordered_map<std::string,
		      std::vector<TEfficiency>>& TEff_ratios, bool proper){

  gROOT->SetBatch(kTRUE);
  SetAtlasStyle();

  string name_canvas = "can_"+nameVar+"_minpT"+min_pT+ratio;
  if(proper==true) name_canvas+="_proper";
  
  TCanvas* canvas = new TCanvas(name_canvas.c_str());
  TLegend* leg = new TLegend(0.18, 0.75, 0.93, 0.90);

  int r_plot = 0;
  int color_number = 0;

  if(ratio.find("r1")!=std::string::npos){ r_plot = 0;}
  if(ratio.find("r2")!=std::string::npos){ r_plot = 1;}
  if(ratio.find("r3")!=std::string::npos){ r_plot = 2;}
  if(ratio.find("r4")!=std::string::npos){ r_plot = 3;}
  
  TEfficiency hist_ggF_lambda10_hh_600460;
  TEfficiency hist_ggF_lambda10_lh_600462;
  TEfficiency hist_ggF_SM_hh_600459;
  TEfficiency hist_ggF_SM_lh_600461;

  TEfficiency hist_VBF_cvv1p5_hh_502985;
  TEfficiency hist_VBF_cvv1p5_lh_502996;
  TEfficiency hist_VBF_SM_hh_502982;
  TEfficiency hist_VBF_SM_lh_502993;

  for(const auto& process_sample : TEff_ratios) {

    const std::string& sample_name = process_sample.first;
    const auto& ratios = process_sample.second;
    
    // Make a copy of the TEfficiency object to modify it
    TEfficiency ratio_hist = ratios[r_plot]; // Copy the TEfficiency object

    //cout << "plot for: "+sample_name << endl;

    ratio_hist.SetMarkerStyle(20);
    //ratio_hist.SetMarkerColor(colors[color_number]);
    
    //ratio_hist.Draw();
    //string name_image = "output_combined_ratios_plots/"+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"_ratio_r1_"+sample_name+".pdf";
    //canvas->SaveAs(name_image.c_str());

    if(sample_name.find("ggF_lambda10_hh_600460")!=std::string::npos){ hist_ggF_lambda10_hh_600460 = ratio_hist; }
    if(sample_name.find("ggF_lambda10_lh_600462")!=std::string::npos){ hist_ggF_lambda10_lh_600462 = ratio_hist; }
    if(sample_name.find("ggF_SM_hh_600459")!=std::string::npos){ hist_ggF_SM_hh_600459 = ratio_hist; }
    if(sample_name.find("ggF_SM_lh_600461")!=std::string::npos){ hist_ggF_SM_lh_600461 = ratio_hist; }


    if(sample_name.find("VBF_cvv1p5_hh_502985")!=std::string::npos){ hist_VBF_cvv1p5_hh_502985 = ratio_hist; }
    if(sample_name.find("VBF_cvv1p5_lh_502996")!=std::string::npos){ hist_VBF_cvv1p5_lh_502996 = ratio_hist; }
    if(sample_name.find("VBF_SM_hh_502982")!=std::string::npos){ hist_VBF_SM_hh_502982 = ratio_hist; }
    if(sample_name.find("VBF_SM_lh_502993")!=std::string::npos){ hist_VBF_SM_lh_502993 = ratio_hist; }
  
  }

  hist_ggF_lambda10_hh_600460.SetMarkerColor(kRed);
  hist_ggF_lambda10_lh_600462.SetMarkerColor(kBlue);
  hist_ggF_SM_hh_600459.SetMarkerColor(kGreen);
  hist_ggF_SM_lh_600461.SetMarkerColor(kMagenta);

  
  hist_VBF_cvv1p5_hh_502985.SetMarkerColor(kCyan);
  hist_VBF_cvv1p5_lh_502996.SetMarkerColor(kYellow);
  hist_VBF_SM_hh_502982.SetMarkerColor(kBlack);
  hist_VBF_SM_lh_502993.SetMarkerColor(kOrange);


  leg->AddEntry(&hist_ggF_lambda10_hh_600460, ("ggF_lambda10_hh_600460_"+ratio).c_str(), "lep");
  leg->AddEntry(&hist_ggF_lambda10_lh_600462, ("ggF_lambda10_lh_600462_"+ratio).c_str(), "lep");
  leg->AddEntry(&hist_ggF_SM_hh_600459, ("ggF_SM_hh_600459_"+ratio).c_str(), "lep");
  leg->AddEntry(&hist_ggF_SM_lh_600461, ("ggF_SM_lh_600461_"+ratio).c_str(), "lep");

  leg->AddEntry(&hist_VBF_cvv1p5_hh_502985, ("VBF_cvv1p5_hh_502985_"+ratio).c_str(), "lep");
  leg->AddEntry(&hist_VBF_cvv1p5_lh_502996, ("VBF_cvv1p5_lh_502996_"+ratio).c_str(), "lep");
  leg->AddEntry(&hist_VBF_SM_hh_502982, ("VBF_SM_hh_502982_"+ratio).c_str(), "lep");
  leg->AddEntry(&hist_VBF_SM_lh_502993, ("VBF_SM_lh_502993_"+ratio).c_str(), "lep");
 

  hist_ggF_lambda10_hh_600460.Draw("AP");
  hist_ggF_lambda10_lh_600462.Draw("PSAME");
  hist_ggF_SM_hh_600459.Draw("PSAME");
  hist_ggF_SM_lh_600461.Draw("PSAME");

  hist_VBF_cvv1p5_hh_502985.Draw("PSAME");
  hist_VBF_cvv1p5_lh_502996.Draw("PSAME");
  hist_VBF_SM_hh_502982.Draw("PSAME");
  hist_VBF_SM_lh_502993.Draw("PSAME");


  gPad->Update();
  auto graph = hist_ggF_lambda10_hh_600460.GetPaintedGraph();
  graph->SetMinimum(0);
  graph->SetMaximum(1.7);
  
  gPad->Update();
  
  leg->SetNColumns(3);
  leg->SetFillStyle(0);
  leg->SetLineColor(0);
  
  leg->Draw();

  string description1 = "";
  string description2 = "For min p_{T} > "+min_pT+"GeV";
  string description3 = "For cut phbb > 0.85";
  //string description4 = "For cut n2/n1 subjetiness < 0.30";
  
  string name_image = "";
  
  if(proper==true){
    description1 = "Proper B_{bb}-B_{#tau#tau} class";
    name_image = base_output_folder+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"GeV_proper_ratios_"+ratio+"_comparison.pdf";
  }
  if(proper==false){
    if(nameVar.find("HH")!=std::string::npos){
      description1 = "Proper B_{bb}-B_{#tau#tau} class";
    }
    if(nameVar.find("bb")!=std::string::npos){
      description1 = "bb-only";
    }
    if(nameVar.find("tautau")!=std::string::npos){
      description1 = "#tau#tau-only";
    }
    name_image = base_output_folder+min_pT+"GeV/"+nameVar+"_min_pT"+min_pT+"GeV_ratios_"+ratio+"_comparison.pdf";
  }
  
  double dely = 0.05;
  myText(0.2, 0.7, kBlack, description1.c_str());
  myText(0.2, 0.7-dely, kBlack, description2.c_str());
  myText(0.2, 0.7-2*dely, kBlack, description3.c_str());
  //myText(0.2, 0.7-3*dely, kBlack, description4.c_str());
  
  canvas->SaveAs(name_image.c_str());
  
}

// Initialize the ap_ratios_info
void initializeMapRatiosInfo(const std::vector<std::string>& sampleFiles, const std::string& nameVar, const std::string& min_pT, std::unordered_map<std::string, std::vector<TEfficiency>>& efficiency_map, bool proper){

  gROOT->SetBatch(kTRUE);
  
  std::ofstream outFile((base_output_folder+"percentages_ratios.txt").c_str(), std::ios::app); // Open in append mode
 
  for (const auto& sample : sampleFiles){
    string path_root_file = path_folder+sample+"_pT"+min_pT+"GeV.root";
    //TCanvas* can = new TCanvas(("can_"+sample+"_"+nameVar+"_pT"+min_pT+"GeV").c_str());
    
    TFile* file = TFile::Open(path_root_file.c_str());
    
    string name_hist_num_r1_r2 = ""; string name_hist_den_for_r1 = ""; string name_hist_den_for_r2 = "";
    string name_hist_num_for_r3 = ""; string name_hist_num_for_r4 = ""; string name_hist_den_for_r3_r4 = ""; 

    if(proper==false){
      if(nameVar.find("HH")!=std::string::npos){
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
    }

    if(proper==true){
      name_hist_num_r1_r2 = "hist_acceptance_"+nameVar+"_numerator_class3_r1_r2";
      name_hist_den_for_r1 = "hist_acceptance_"+nameVar+"_denominator_r1";
      name_hist_den_for_r2 = "hist_acceptance_"+nameVar+"_denominator_class3_r2";
      name_hist_num_for_r3 = "hist_acceptance_"+nameVar+"_numerator_r3";
      name_hist_num_for_r4 = "hist_acceptance_"+nameVar+"_numerator_class3_r4";
      name_hist_den_for_r3_r4 = "hist_acceptance_"+nameVar+"_denominator_r3_r4";
    }

    TH1F* hist_num_r1_r2 = dynamic_cast<TH1F*>(file->Get(name_hist_num_r1_r2.c_str()));
    TH1F* hist_den_for_r1 = dynamic_cast<TH1F*>(file->Get(name_hist_den_for_r1.c_str()));
    TH1F* hist_den_for_r2 = dynamic_cast<TH1F*>(file->Get(name_hist_den_for_r2.c_str()));

    TH1F* hist_num_for_r3 = dynamic_cast<TH1F*>(file->Get(name_hist_num_for_r3.c_str()));
    TH1F* hist_num_for_r4 = dynamic_cast<TH1F*>(file->Get(name_hist_num_for_r4.c_str()));
    TH1F* hist_den_for_r3_r4 = dynamic_cast<TH1F*>(file->Get(name_hist_den_for_r3_r4.c_str()));

    cout << "/----------------------------------------------------------------------" << endl;
    cout << "For: "+nameVar << endl;
    cout << "\t For: "+min_pT << endl;
    cout << "\t \t name process: "+sample << "\t r1_acceptance (%): " << (hist_num_r1_r2->Integral()/hist_den_for_r1->Integral())*100.0 << endl;
    cout << "\t \t name process: "+sample << "\t r2_acceptance (%): " << (hist_num_r1_r2->Integral()/hist_den_for_r2->Integral())*100.0 << endl;
    cout << "\t \t name process: "+sample << "\t r3_acceptance (%): " << (hist_num_for_r3->Integral()/hist_den_for_r3_r4->Integral())*100.0 << endl;
    cout << "\t \t name process: "+sample << "\t r4_acceptance (%): " << (hist_num_for_r4->Integral()/hist_den_for_r3_r4->Integral())*100.0 << endl;
    cout << "/----------------------------------------------------------------------" << endl;

    // Save this information in a txt file
    outFile << "/----------------------------------------------------------------------" << endl;
    outFile << "For: "+nameVar << endl;
    outFile << "\t For: "+min_pT << endl;
    outFile << "\t \t name process: "+sample << "\t r1_acceptance (%): " << (hist_num_r1_r2->Integral()/hist_den_for_r1->Integral())*100.0 << endl;
    outFile << "\t \t name process: "+sample << "\t r2_acceptance (%): " << (hist_num_r1_r2->Integral()/hist_den_for_r2->Integral())*100.0 << endl;
    outFile << "\t \t name process: "+sample << "\t r3_acceptance (%): " << (hist_num_for_r3->Integral()/hist_den_for_r3_r4->Integral())*100.0 << endl;
    outFile << "\t \t name process: "+sample << "\t r4_acceptance (%): " << (hist_num_for_r4->Integral()/hist_den_for_r3_r4->Integral())*100.0 << endl;
    outFile << "/----------------------------------------------------------------------" << endl;

    TEfficiency *pEff_r1 = new TEfficiency(*hist_num_r1_r2, *hist_den_for_r1);
    TEfficiency *pEff_r2 = new TEfficiency(*hist_num_r1_r2, *hist_den_for_r2);
    TEfficiency *pEff_r3 = new TEfficiency(*hist_num_for_r3, *hist_den_for_r3_r4);
    TEfficiency *pEff_r4 = new TEfficiency(*hist_num_for_r4, *hist_den_for_r3_r4);

    // Store the ratios in a vector
    std::vector<TEfficiency> list_TEff_ratios = {*pEff_r1, *pEff_r2, *pEff_r3, *pEff_r4};

    // Insert into the map: for the given process, add the list of TEfficiency
    efficiency_map[sample] = list_TEff_ratios;
   
    file->Close();
  }
  
  outFile.close();
  
}
