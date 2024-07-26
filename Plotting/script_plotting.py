import os
import subprocess

# List of root files to analyze

variables = ["mHH", "mHbb", "mHtautau", "ptHH", "ptHbb", "ptHtautau"]

# Root folder for storing output
output_root_folder = "output_plots"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

# Loop over each sample
for var in variables:
    
    # Construct the ROOT script command
    # The command includes a reference to your ROOT script, passing the path of the sample and output folder

    print("Processing {var} ratios")
    
    root_command = f'root -l -q \'Plotting.C("{var}")\''
 
    # Run the ROOT script
    subprocess.run(root_command, shell=True)
