import os
import subprocess

# List of root files to analyze

sample_paths = [
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/boosted_samples/mc20_13TeV_502982_vbf_hadhad_l1cvv1cv1/boosted_samples/mc20_13TeV_502982_vbf_hadhad_l1cvv1cv1_PHYS_merged_boosted_bypass_config.root",
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/boosted_samples/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1/boosted_samples/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_boosted_bypass_config.root",
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/boosted_samples/mc20_13TeV_502996_vbf_lephad_l1cvv1p5cv1/boosted_samples/mc20_13TeV_502996_vbf_lephad_l1cvv1p5cv1_PHYS_merged_boosted_bypass_config.root"
    # Add as many samples as you need
]

# Root folder for storing output
output_root_folder = "output_analysis"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

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

    root_command = f'root -l -q \'study_substructure_jets.C("{sample}", "{output_folder}")\''

    #root_command = f'root -l -q analysis.C("{sample}", "{output_folder}")'

    # Run the ROOT script
    subprocess.run(root_command, shell=True)
