import os
import subprocess

# List of root files to analyze

base_analysis_folder = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis/"

#min_pT_recojets = ["100", "200", "300"] # in GeV
min_pT_recojets = ["100", "150", "200", "250", "300", "350"] # in GeV
#min_pT_recojets = ["100"] # in GeV  

# Root folder for storing output
output_root_folder = "output_plots"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

#os.makedirs("output_analysis/temp_folder", exist_ok=True)
    
for minpT in min_pT_recojets:

    sample_paths = [
        #base_analysis_folder + "VBF_SM_hh_502982_pT"+minpT+"GeV.root", # vbf HH SM had-had channel
        #base_analysis_folder + "VBF_SM_lh_502993_pT"+minpT+"GeV.root", # vbf HH SM lep-had channel
        #base_analysis_folder + "VBF_cvv1p5_hh_502985_pT"+minpT+"GeV.root", # vbf HH Cvv=1.5 had-had channel
        #base_analysis_folder + "VBF_cvv1p5_lh_502996_pT"+minpT+"GeV.root", # vbf HH Cvv=1.5 lep-had channel
        base_analysis_folder + "ggF_SM_hh_600459_pT"+minpT+"GeV.root", # ggF SM had-had channel
        base_analysis_folder + "ggF_SM_lh_600461_pT"+minpT+"GeV.root", # ggF SM lep-had channel
        base_analysis_folder + "ggF_lambda10_hh_600460_pT"+minpT+"GeV.root", # ggF cHHH=10 had-had channel
        base_analysis_folder + "ggF_lambda10_lh_600462_pT"+minpT+"GeV.root" # ggF cHHH=10 lep-had channel
        # Add as many samples as you need
    ]

    
    output_pT_folder = minpT+"GeV_normalized"
    output_pT_folder = os.path.join(output_root_folder, output_pT_folder)
    os.makedirs(output_pT_folder, exist_ok=True)
    
    # Loop over each sample
    for sample in sample_paths:
        # Get the sample name (useful for naming the output folder)
        sample_name = os.path.basename(sample).removesuffix("_pT"+minpT+"GeV.root")
    
        # Create a specific folder for this sample's output
        output_folder = os.path.join(output_pT_folder, sample_name)
        
        os.makedirs(output_folder, exist_ok=True)

        # Define the output path in a way that can be accessed by your analysis script
        output_file_path = os.path.join(output_folder, "output_tree.root")
    
        # Define plots_substructure_jets folder
        plots_substructure_jets = os.path.join(output_folder, "plots_substructure_jets")
        os.makedirs(plots_substructure_jets, exist_ok=True)
        
        # Define plots_substructure_jets folder
        plots_substructure_jets_comparison = os.path.join(plots_substructure_jets, "comparison_plots")
        os.makedirs(plots_substructure_jets_comparison, exist_ok=True)
        
        # Define plots_comparison folder
        plots_comparison = os.path.join(output_folder, "plots_comparison")
        #os.makedirs(plots_comparison, exist_ok=True)
        
        # Define plots_ratios folder
        plots_ratios = os.path.join(output_folder, "plots_ratios")
        #os.makedirs(plots_ratios, exist_ok=True)
    
        # Construct the ROOT script command
        # The command includes a reference to your ROOT script, passing the path of the sample and output folder

        root_command = f'root -l -q \'Plotting_substructure_jets_variables.C("{sample}", "{output_folder}", "{minpT}")\''

        #print(sample)
        #print(output_folder)
        
        # Run the ROOT script
        subprocess.run(root_command, shell=True)
        

variables = ["preselected_bb_m", "preselected_bb_tau_n2_over_n1_subjettiness", "preselected_tautau_m",
             "preselected_tautau_tau_n2_over_n1_subjettiness", "preselected_bb_m_only_Hbb_tagger",
             "preselected_bb_m_until_nsubjettiness", "preselected_tautau_m_only_Hbb_tagger",
             "preselected_tautau_m_until_nsubjettiness", "recojet_tautau_m", "recojet_tautau_m_only_Hbb_tagger",
             "recojet_tautau_m_only_nsubjettiness", "recojet_tautau_m_until_nsubjettiness",
             "recojet_bb_m", "recojet_bb_m_only_Hbb_tagger",
             "recojet_bb_m_only_nsubjettiness", "recojet_bb_m_until_nsubjettiness"]

#variables = ["preselected_bb_m"]

for var in variables:
    
    print(f'Processing "{var}" histograms comparisons: ')

    root_command = f'root -l -q \'Plotting_comparison_substructure_jets_variables.C("{var}")\''

    # Run the ROOT script                                                                                                                                   
    subprocess.run(root_command, shell=True)
