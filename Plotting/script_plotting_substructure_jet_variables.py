import os
import subprocess

# List of root files to analyze

base_analysis_folder = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/study_substructure_jets/output_analysis/"

sample_paths = [
    base_analysis_folder + "VBF_SM_hh_502982.root", # vbf HH SM had-had channel
    base_analysis_folder + "VBF_SM_lh_502993.root", # vbf HH SM lep-had channel
    base_analysis_folder + "VBF_cvv1p5_hh_502985.root", # vbf HH Cvv=1.5 had-had channel
    base_analysis_folder + "VBF_cvv1p5_lh_502996.root", # vbf HH Cvv=1.5 lep-had channel
    base_analysis_folder + "ggF_SM_hh_600459.root", # ggF SM had-had channel
    base_analysis_folder + "ggF_SM_lh_600461.root", # ggF SM lep-had channel
    base_analysis_folder + "ggF_lambda10_hh_600460.root", # ggF cHHH=10 had-had channel
    base_analysis_folder + "ggF_lambda10_lh_600462.root" # ggF cHHH=10 lep-had channel
    # Add as many samples as you need
]

# Root folder for storing output
output_root_folder = "output_plots"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

#os.makedirs("output_analysis/temp_folder", exist_ok=True)

# Loop over each sample
for sample in sample_paths:
    # Get the sample name (useful for naming the output folder)
    sample_name = os.path.basename(sample).removesuffix('.root')
   
    # Create a specific folder for this sample's output
    output_folder = os.path.join(output_root_folder, sample_name)
    os.makedirs(output_folder, exist_ok=True)

    # Define the output path in a way that can be accessed by your analysis script
    output_file_path = os.path.join(output_folder, "output_tree.root")
    
    # Define plots_substructure_jets folder
    plots_substructure_jets = os.path.join(output_folder, "plots_substructure_jets")
    os.makedirs(plots_substructure_jets, exist_ok=True)

    # Define plots_comparison folder
    plots_comparison = os.path.join(output_folder, "plots_comparison")
    os.makedirs(plots_comparison, exist_ok=True)

    # Define plots_ratios folder
    plots_ratios = os.path.join(output_folder, "plots_ratios")
    os.makedirs(plots_ratios, exist_ok=True)
    
    # Construct the ROOT script command
    # The command includes a reference to your ROOT script, passing the path of the sample and output folder

    root_command = f'root -l -q \'Plotting_substructure_jets_variables.C("{sample}", "{output_folder}")\''

    # Run the ROOT script
    subprocess.run(root_command, shell=True)
