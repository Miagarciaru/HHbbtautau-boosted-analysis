import numpy as np
import pandas as pd
import os
import functions

input_folder = "output_analysis_2/"

# Creating folders to save the plots
os.makedirs("ML_models", exist_ok=True)
os.makedirs("BDT_plots", exist_ok=True)

# List of all available VBF samples

list_VBF = ["VBF_cvv1p5_hh_502985_pT250GeV.root", "VBF_cvv1p5_lh_502996_pT250GeV.root"]
# list_VBF = ["VBF_cvv1p5_hh_502985_pT250GeV.root"]

features = ["class_event", "idx_b1truth_recoak10_dRmin", "idx_tau1truth_recoak10_dRmin", "recojet_antikt10UFO_NOSYS_pt", 
"recojet_antikt10UFO_eta", "recojet_antikt10UFO_phi", "recojet_antikt10UFO_m", "recojet_antikt10UFO_Tau1_wta",
"recojet_antikt10UFO_Tau2_wta", "recojet_antikt10UFO_ECF1", "recojet_antikt10UFO_ECF2", "recojet_antikt10UFO_ECF3",
"recojet_antikt10UFO_Split12", "recojet_antikt10UFO_Split23", "recojet_antikt10UFO_GN2Xv01_phbb"]

df_events = functions.read_root_files(list_VBF, features, input_folder)

print(df_events.head(5))

explode_branches = ["recojet_antikt10UFO_NOSYS_pt", "recojet_antikt10UFO_eta", "recojet_antikt10UFO_phi",
                    "recojet_antikt10UFO_m", "recojet_antikt10UFO_Tau1_wta", "recojet_antikt10UFO_Tau2_wta", 
                    "recojet_antikt10UFO_ECF1", "recojet_antikt10UFO_ECF2", "recojet_antikt10UFO_ECF3",
                    "recojet_antikt10UFO_Split12", "recojet_antikt10UFO_Split23", "recojet_antikt10UFO_GN2Xv01_phbb"]

df_bb_jets = functions.get_df_with_info_jets(df_events, explode_branches, "idx_b1truth_recoak10_dRmin")
df_tautau_jets = functions.get_df_with_info_jets(df_events, explode_branches, "idx_tau1truth_recoak10_dRmin")

##### Training

# variables to use in the training part

features_to_keep = ["recojet_antikt10UFO_NOSYS_pt", "recojet_antikt10UFO_m", "recojet_antikt10UFO_Tau1_wta",
"recojet_antikt10UFO_Tau2_wta", "recojet_antikt10UFO_ECF1", "recojet_antikt10UFO_ECF2", "recojet_antikt10UFO_ECF3",
"recojet_antikt10UFO_Split12", "recojet_antikt10UFO_Split23", "recojet_antikt10UFO_GN2Xv01_phbb"]

# Definition of the X and y dataframes, which are used to train the bdt model. X and y dataframes contains
# the jets that are boosted in a single dataframe and the class label, respectively.

X_bb_jets = df_bb_jets[features_to_keep].astype(np.float32)
y_bb_jets = df_bb_jets["is_boosted_bb_jet"].astype(int)

print(X_bb_jets.columns)
print(y_bb_jets)

X_bb_jets_array = X_bb_jets.to_numpy()
y_bb_jets_array = y_bb_jets.to_numpy()

# import pdb; pdb.set_trace()

# Training the BDT for boosted bb jets
bdt_bb_jets, X_train_bb_jets, X_test_bb_jets, y_train_bb_jets, y_test_bb_jets = functions.train_bdt_model(X_bb_jets_array, y_bb_jets_array)

# Plotting ranking of variables and their correlation matrix
functions.ranking_relevant_variables(bdt_bb_jets, X_bb_jets, "bb_jets")

# Plotting ROC Curve and Overtraining checking
functions.definition_validation_plots(bdt_bb_jets, X_bb_jets, y_bb_jets, X_train_bb_jets, y_train_bb_jets, X_test_bb_jets, y_test_bb_jets, "bb_jets")

# # Saving the model in onnx format
# functions.save_bdt_model(bdt_bb_jets, X_bb_jets, "bb_jets")
functions.save_model_with_TMVA(bdt_bb_jets, X_bb_jets_array, "bb_jets")

# Definition of the X and y dataframes, which are used to train the bdt model. X and y dataframes contains
# the jets that are boosted in a single dataframe and the class label, respectively.

X_tautau_jets = df_tautau_jets[features_to_keep].astype(np.float32)
y_tautau_jets = df_tautau_jets["is_boosted_tautau_jet"].astype(int)

X_tautau_jets_array = X_tautau_jets.to_numpy()
y_tautau_jets_array = y_tautau_jets.to_numpy()

# Training the BDT for boosted bb jets
bdt_tautau_jets, X_train_tautau_jets, X_test_tautau_jets, y_train_tautau_jets, y_test_tautau_jets = functions.train_bdt_model(X_tautau_jets_array, y_tautau_jets_array)

# Plotting ranking of variables and their correlation matrix
functions.ranking_relevant_variables(bdt_tautau_jets, X_tautau_jets, "tautau_jets")

# Plotting ROC Curve and Overtraining checking
functions.definition_validation_plots(bdt_tautau_jets, X_tautau_jets, y_tautau_jets, X_train_tautau_jets, y_train_tautau_jets, X_test_tautau_jets, y_test_tautau_jets, "tautau_jets")

# # Saving the model in onnx format
# functions.save_bdt_model(bdt_tautau_jets, X_tautau_jets, "tautau_jets")
functions.save_model_with_TMVA(bdt_tautau_jets, X_tautau_jets, "tautau_jets")