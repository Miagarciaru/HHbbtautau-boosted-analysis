import os
import subprocess
import time

# List of root files to analyze

base_path="/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples_May_2025/";

sample_paths = [
    #base_path+"user.gmagni.44636303._000001.output-tree_Boosted_vbf_SM.root",
    base_path+"user.gmagni.44636306._000001.output-tree_Boosted_vbf_cv1p5.root",
    base_path+"user.gmagni.44636309._000001.output-tree_Boosted_ggF_SM.root" # ggf HH SM had-had channel
    # Add as many samples as you need
]

start = time.time() # time at start of whole processing

# Root folder for storing output
output_root_folder = "output_analysis"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

# Loop over each sample
# The command includes a reference to your ROOT script, passing the path of the sample and output folder

for sample in sample_paths:
    
    root_command = f'root -l -q \'VBF_ggF_separation_study.C("{sample}", "{output_root_folder}")\''
    
    # Run the ROOT script
    subprocess.run(root_command, shell=True)

input_file_BDT_file = "input_BDT.root"
hadd_command = f'hadd -f2 {input_file_BDT_file} ggF_SM_hh_600459.root VBF_SM_hh_502982.root'
print(hadd_command)
#subprocess.run(hadd_command, shell=True)

elapsed = (time.time() - start)/60. # time after whole processing
print("Total time taken: "+str(round(elapsed,2))+"min") # print total time taken to process every file
