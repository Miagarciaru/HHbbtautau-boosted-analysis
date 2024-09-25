import os
import subprocess

# List of root files to analyze

#variables = ["mHH", "mHbb", "mHtautau", "ptHH", "ptHbb", "ptHtautau", "truth_mHH", "truth_mHbb", "truth_mHtautau", "truth_ptHH", "truth_ptHbb", "truth_ptHtautau"]

variables = ["mHH", "ptHbb", "ptHtautau", "truth_mHH", "truth_ptHbb", "truth_ptHtautau"]

#min_pT_recojets = [100000, 200000, 250000, 300000, 350000] # in MeV
min_pT_recojets = ["100000"] # in MeV  

# Root folder for storing output
output_root_folder = "output_combined_ratios_plots"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

# Loop over each sample
for var in variables:
    
    # Construct the ROOT script command
    # The command includes a reference to your ROOT script, passing the path of the sample and output folder
    for min_pT in min_pT_recojets:

        output_folder = os.path.join(output_root_folder, min_pT)
        
        os.makedirs(output_folder, exist_ok=True)

        print(f'Processing "{var}" ratios for min pT of recojets "{min_pT}" MeV')
        
        root_command = f'root -l -q \'Plotting_aceptance_ratios.C("{var}", "{min_pT}")\''
 
        # Run the ROOT script
        subprocess.run(root_command, shell=True)
