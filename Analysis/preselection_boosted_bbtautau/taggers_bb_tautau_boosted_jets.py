import numpy as np
import pandas as pd
import os
import functions_taggers_jets

input_folder = "output_analysis/"

# Creating folders to save the plots
os.makedirs("ML_models", exist_ok=True)
os.makedirs("BDT_plots", exist_ok=True)

# List of all available samples

list_VBF = ["VBF_cvv1p5_hh_502985_pT250GeV.root", "VBF_cvv1p5_lh_502996_pT250GeV.root",
            "VBF_SM_hh_502982_pT250GeV.root", "VBF_SM_lh_502993_pT250GeV.root",
            "ggF_lambda10_hh_600460_pT250GeV.root", "ggF_lambda10_lh_600462_pT250GeV.root",
            "ggF_SM_hh_600459_pT250GeV.root", "ggF_SM_lh_600461_pT250GeV.root"]

features = ["truth_reco_match_for_boosted_bb",
            "truth_reco_match_for_boosted_tautau",
            "idx_b1truth_recoak10_dRmin", 
            "idx_tau1truth_recoak10_dRmin", 
            "recojet_antikt10UFO_NOSYS_pt", 
            "recojet_antikt10UFO_eta", 
            "recojet_antikt10UFO_phi", 
            "recojet_antikt10UFO_m", 
            "recojet_antikt10UFO_Tau1_wta", 
            "recojet_antikt10UFO_Tau2_wta", 
            "recojet_antikt10UFO_Tau3_wta",
            "recojet_antikt10UFO_ECF1", 
            "recojet_antikt10UFO_ECF2", 
            "recojet_antikt10UFO_ECF3",
            "recojet_antikt10UFO_Split12", 
            "recojet_antikt10UFO_Split23", 
            "recojet_antikt10UFO_GN2Xv01_phbb", 
            "recojet_antikt10UFO_GN2Xv01_pqcd", 
            "recojet_antikt10UFO_GN2Xv01_phcc",
            "recojet_antikt10UFO_GN2Xv01_ptop"]

df_events = functions_taggers_jets.read_root_files(list_VBF, features, input_folder)

print(df_events.head(5))

# variables to use in the training part
features_to_keep = ["recojet_antikt10UFO_NOSYS_pt", 
                    "recojet_antikt10UFO_eta", 
                    "recojet_antikt10UFO_phi", 
                    "recojet_antikt10UFO_m", 
                    "recojet_antikt10UFO_Tau1_wta", 
                    "recojet_antikt10UFO_Tau2_wta", 
                    "recojet_antikt10UFO_Tau3_wta",
                    "recojet_antikt10UFO_ECF1", 
                    "recojet_antikt10UFO_ECF2", 
                    "recojet_antikt10UFO_ECF3",
                    "recojet_antikt10UFO_Split12", 
                    "recojet_antikt10UFO_Split23", 
                    "recojet_antikt10UFO_GN2Xv01_phbb", 
                    "recojet_antikt10UFO_GN2Xv01_pqcd", 
                    "recojet_antikt10UFO_GN2Xv01_phcc",
                    "recojet_antikt10UFO_GN2Xv01_ptop"]

df_bb_jets = functions_taggers_jets.get_df_with_info_jets(df_events, features_to_keep, "idx_b1truth_recoak10_dRmin")
df_tautau_jets = functions_taggers_jets.get_df_with_info_jets(df_events, features_to_keep, "idx_tau1truth_recoak10_dRmin")

##### Training

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
bdt_bb_jets, X_train_bb_jets, X_test_bb_jets, y_train_bb_jets, y_test_bb_jets = functions_taggers_jets.train_bdt_model(X_bb_jets_array, y_bb_jets_array)

# Plotting ranking of variables and their correlation matrix
functions_taggers_jets.ranking_relevant_variables(bdt_bb_jets, X_bb_jets, "bb_jets")

# Plotting ROC Curve and Overtraining checking
functions_taggers_jets.definition_validation_plots(bdt_bb_jets, X_bb_jets, y_bb_jets, X_train_bb_jets, y_train_bb_jets, X_test_bb_jets, y_test_bb_jets, "bb_jets")

# # Saving the model in onnx format
# functions_taggers_jets.save_bdt_model(bdt_bb_jets, X_bb_jets, "bb_jets")
functions_taggers_jets.save_model_with_TMVA(bdt_bb_jets, X_bb_jets_array, "bb_jets")

# Definition of the X and y dataframes, which are used to train the bdt model. X and y dataframes contains
# the jets that are boosted in a single dataframe and the class label, respectively.

X_tautau_jets = df_tautau_jets[features_to_keep].astype(np.float32)
y_tautau_jets = df_tautau_jets["is_boosted_tautau_jet"].astype(int)

print(X_tautau_jets.columns)
print(y_tautau_jets)

X_tautau_jets_array = X_tautau_jets.to_numpy()
y_tautau_jets_array = y_tautau_jets.to_numpy()

# Training the BDT for boosted bb jets
bdt_tautau_jets, X_train_tautau_jets, X_test_tautau_jets, y_train_tautau_jets, y_test_tautau_jets = functions_taggers_jets.train_bdt_model(X_tautau_jets_array, y_tautau_jets_array)

# Plotting ranking of variables and their correlation matrix
functions_taggers_jets.ranking_relevant_variables(bdt_tautau_jets, X_tautau_jets, "tautau_jets")

# Plotting ROC Curve and Overtraining checking
functions_taggers_jets.definition_validation_plots(bdt_tautau_jets, X_tautau_jets, y_tautau_jets, X_train_tautau_jets, y_train_tautau_jets, X_test_tautau_jets, y_test_tautau_jets, "tautau_jets")

# # Saving the model in onnx format
# functions_taggers_jets.save_bdt_model(bdt_tautau_jets, X_tautau_jets, "tautau_jets")
functions_taggers_jets.save_model_with_TMVA(bdt_tautau_jets, X_tautau_jets, "tautau_jets")