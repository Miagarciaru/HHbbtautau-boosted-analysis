import os
import subprocess

# List of root files to analyze

#variables = ["mHH", "mHbb", "mHtautau", "ptHH", "ptHbb", "ptHtautau", "truth_mHH", "truth_mHbb", "truth_mHtautau", "truth_ptHH", "truth_ptHbb", "truth_ptHtautau"]

variables = ["mHH", "ptHbb", "ptHtautau", "truth_mHH", "truth_ptHbb", "truth_ptHtautau"]

# Root folder for storing output
output_root_folder = "output_combined_ratios_plots"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

# Loop over each sample
for var in variables:
    
    # Construct the ROOT script command
    # The command includes a reference to your ROOT script, passing the path of the sample and output folder

    print(f'Processing "{var}" ratios')
    
    root_command = f'root -l -q \'Plotting_aceptance_ratios.C("{var}")\''
 
    # Run the ROOT script
    subprocess.run(root_command, shell=True)
