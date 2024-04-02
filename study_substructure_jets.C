#include <TMath.h>
#include <TLorentzVector.h>
#include "declaration_of_functions.h"


void study_substructure_jets(){
  

  // print_list_of_branches(inTree);

  // *************************************
  // Set Branch Address for the leafs on each tree
  // ************************************* 

  set_branch_address();

  // ************************************* 
  // Fill some histograms
  // *************************************

  fill_histograms();

  // ************************************* 
  // Plot some histograms
  // *************************************

  /*
  std::vector<TString> list_of_histograms = {"truth_b1_m", "truth_b2_m", "truth_b1_plus_b2_m"};

  for(int ii=0; ii < list_of_histograms.size(); ii++){
    plot_distributions(list_of_histograms[ii]);
  }
  */

  Int_t nentries = inTree->GetEntries();
  int nbytes = 0;

  int count_b_tau_matched_recojets = 0;

  int count_non_matched_events = 0;
  int count_truth_Rbb_Rtautau = 0;
  int count_truth_Rbb_Btautau = 0;
  int count_truth_Bbb_Rtautau = 0;
  int count_truth_Bbb_Btautau = 0;
  int count_fake_Rbb_Rtautau = 0;
  int count_fake_Rbb_Btautau = 0;
  int count_fake_Bbb_Rtautau = 0;
  int count_fake_Bbb_Btautau = 0;

  
  for(int ii=0; ii < nentries; ii++){
    
    nbytes = inTree->GetEntry(ii);  
    define_truth_tau_and_b_jets();
    compute_dR_min_index_fat_jets();
    //    truth_objects_asserts(ii);
    define_classes();
    // truth_matching_reco_objects_asserts(ii, count_b_tau_matched_recojets);

    if(class_event != -1){
      
      TLorentzVector jet1  = TLorentzVector();
      TLorentzVector jet2  = TLorentzVector();
      
      // truth Boosted bb

      if( (class_event == 2) || (class_event == 3) ){
	hist_recojet_bb_m->Fill(recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin/1000.));
      }
      
      // truth resolved bb
      if( (class_event == 0) || (class_event == 1) ){

	jet1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b1truth_recoak10_dRmin)/1000.);
	
	jet2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_b2truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_b2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_b2truth_recoak10_dRmin)/1000.);

	TLorentzVector sum_jet = jet1 + jet2;
	
	hist_recojet_bb_m->Fill(sum_jet.Mag());
      }

      // truth boosted tautau jets

      if( (class_event == 1) || (class_event == 3) ){
	hist_recojet_tautau_m->Fill(recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin/1000.));
      }
      
      // truth resolved tautau jets
      if( (class_event == 0) || (class_event == 2) ){

	jet1.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau1truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau1truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau1truth_recoak10_dRmin)/1000.);
	
	jet2.SetPtEtaPhiM(recojet_antikt10UFO_NOSYS_pt->at(idx_tau2truth_recoak10_dRmin)/1000., recojet_antikt10UFO_eta->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_phi->at(idx_tau2truth_recoak10_dRmin), recojet_antikt10UFO_m->at(idx_tau2truth_recoak10_dRmin)/1000.);

	TLorentzVector sum_jet = jet1 + jet2;
	
	hist_recojet_tautau_m->Fill(sum_jet.Mag());
      }
      
      
    }
    
    if(class_event == -1){ count_non_matched_events+=1; }
    if(class_event == 0){ count_truth_Rbb_Rtautau+=1; } 
    if(class_event == 1){ count_truth_Rbb_Btautau+=1; }
    if(class_event == 2){ count_truth_Bbb_Rtautau+=1; }
    if(class_event == 3){ count_truth_Bbb_Btautau+=1; }
    if(class_event == 4){ count_fake_Rbb_Rtautau+=1; }
    if(class_event == 5){ count_fake_Rbb_Btautau+=1; }
    if(class_event == 6){ count_fake_Bbb_Rtautau+=1; }
    if(class_event == 7){ count_fake_Bbb_Btautau+=1; }
  }

  /*
  cout << "The number of events in which there one of the two taus and one of the two bb jets were matched to the same recojet are " << count_b_tau_matched_recojets << " of a total nentries " << nentries << " (" << 100.0*count_b_tau_matched_recojets/nentries << "% of the total nentries)" << endl;
  */

  cout << "There are " << count_truth_Rbb_Rtautau << " in the truth R_bb-Rtautau (" << 100.0*count_truth_Rbb_Rtautau/nentries << "% of the total entries)" << endl;
  cout << "There are " << count_truth_Rbb_Btautau << " in the truth R_bb-Btautau (" << 100.0*count_truth_Rbb_Btautau/nentries << "% of the total entries)" << endl;
  cout << "There are " << count_truth_Bbb_Rtautau << " in the truth B_bb-Rtautau (" << 100.0*count_truth_Bbb_Rtautau/nentries << "% of the total entries)" << endl;
  cout << "There are " << count_truth_Bbb_Btautau << " in the truth B_bb-Btautau (" << 100.0*count_truth_Bbb_Btautau/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_fake_Rbb_Rtautau << " in the fake R_bb-Rtautau (" << 100.0*count_fake_Rbb_Rtautau/nentries << "% of the total entries)" << endl;
  cout << "There are " << count_fake_Rbb_Btautau << " in the fake R_bb-Btautau (" << 100.0*count_fake_Rbb_Btautau/nentries << "% of the total entries)" << endl;
  cout << "There are " << count_fake_Bbb_Rtautau << " in the fake B_bb-Rtautau (" << 100.0*count_fake_Bbb_Rtautau/nentries << "% of the total entries)" << endl;
  cout << "There are " << count_fake_Bbb_Btautau << " in the fake B_bb-Btautau (" << 100.0*count_fake_Bbb_Btautau/nentries << "% of the total entries)" << endl;

  
  int sum_all_events = count_non_matched_events + count_truth_Rbb_Rtautau + count_truth_Rbb_Btautau + count_truth_Bbb_Rtautau + count_truth_Bbb_Btautau + count_fake_Rbb_Rtautau + count_fake_Rbb_Btautau + count_fake_Bbb_Rtautau + count_fake_Bbb_Btautau;

  int sum_truth_matching_events = count_truth_Rbb_Rtautau + count_truth_Rbb_Btautau + count_truth_Bbb_Rtautau + count_truth_Bbb_Btautau;

  int sum_fake_matching_events = count_fake_Rbb_Rtautau + count_fake_Rbb_Btautau + count_fake_Bbb_Rtautau + count_fake_Bbb_Btautau;
  
  cout << "The sum of all the events into one of the given classes plus the number of events which have at least one truth object without a match with a fat jet is: " << sum_all_events << " (" << 100.0*sum_all_events/nentries << "% of the total entries)" << endl;

  cout << "There are " << count_non_matched_events << " events which have at least one truth object without a match with a fat jet (" << 100.0*count_non_matched_events/nentries << "% of the total entries)" << endl;

  cout << "The sum of all the events which were correctly classified with resolved and boosted bb and tautau jets: " << sum_truth_matching_events << " (" << 100.0*sum_truth_matching_events/nentries << "% of the total entries)" << endl;

  cout << "The sum of all the events which were wrongly classified with resolved and boosted bb and tautau jets: " << sum_fake_matching_events << " (" << 100.0*sum_fake_matching_events/nentries << "% of the total entries)" << endl;

  cout << "Total entries: " << nentries << endl;


  plot_distributions("recojet_bb_m");
  plot_distributions("recojet_tautau_m");

  inFile->Close();
  
}
