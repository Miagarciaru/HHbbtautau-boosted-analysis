import os
import subprocess
import time

# List of root files to analyze

sample_paths = [
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_502982_vbf_hadhad_l1cvv1cv1_PHYS_merged_boosted_bypass_config.root", # vbf HH SM had-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_502993_vbf_lephad_l1cvv1cv1_PHYS_merged_boosted_bypass_config.root", # vbf HH SM lep-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_502985_vbf_hadhad_l1cvv1p5cv1_PHYS_merged_boosted_bypass_config.root", # vbf HH Cvv=1.5 had-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_502996_vbf_lephad_l1cvv1p5cv1_PHYS_merged_boosted_bypass_config.root", # vbf HH Cvv=1.5 lep-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_600459_ggf_hadhad_cHHH01d0_PHYS_merged_boosted_bypass_config.root", # ggF SM had-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_600461_ggf_lephad_cHHH01d0_PHYS_merged_boosted_bypass_config.root", # ggF SM lep-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_600460_ggf_hadhad_cHHH10d0_PHYS_merged_boosted_bypass_config.root", # ggF cHHH=10 had-had channel
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_600462_ggf_lephad_cHHH10d0_PHYS_merged_boosted_bypass_config.root" # ggF cHHH=10 lep-had channel
    # Add as many samples as you need
]


"""
sample_paths = [
    "/eos/user/g/garciarm/HHbbtautau-output-easyjet-framework/grid-outputs-easyjet/boosted_samples/mc20_13TeV_502982_vbf_hadhad_l1cvv1cv1_PHYS_merged_boosted_bypass_config.root" # vbf HH SM had-had channel
]
"""

min_pT_recojets = ["100", "150", "200", "250", "300", "350"] # in GeV

#min_pT_recojets = ["100"] # in GeV

start = time.time() # time at start of whole processing

# Root folder for storing output
output_root_folder = "output_analysis"

# Ensure the root folder exists
os.makedirs(output_root_folder, exist_ok=True)

# Loop over each sample
for min_pT in min_pT_recojets:
    
    # Construct the ROOT script command
    # The command includes a reference to your ROOT script, passing the path of the sample and output folder

    for sample in sample_paths:
    
        root_command = f'root -l -q \'study_substructure_jets.C("{sample}", "{output_root_folder}", "{min_pT}")\''
 
        # Run the ROOT script
        subprocess.run(root_command, shell=True)

elapsed = (time.time() - start)/60. # time after whole processing
print("Total time taken: "+str(round(elapsed,2))+"min") # print total time taken to process every file
