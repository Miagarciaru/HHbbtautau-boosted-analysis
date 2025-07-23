import numpy as np
import pandas as pd
import os
import functions_boosted_bbtautau_events

input_folder = "output_analysis/"
max_jets = 15

# Creating folders to save the plots
os.makedirs("ML_models", exist_ok=True)
os.makedirs("BDT_plots", exist_ok=True)

# List of all available samples

list_VBF = ["VBF_cvv1p5_hh_502985_pT250GeV.root", "VBF_cvv1p5_lh_502996_pT250GeV.root",
            "VBF_SM_hh_502982_pT250GeV.root", "VBF_SM_lh_502993_pT250GeV.root",
            "ggF_lambda10_hh_600460_pT250GeV.root", "ggF_lambda10_lh_600462_pT250GeV.root",
            "ggF_SM_hh_600459_pT250GeV.root", "ggF_SM_lh_600461_pT250GeV.root"]

# list_VBF = ["VBF_cvv1p5_hh_502985_pT250GeV.root", "VBF_cvv1p5_lh_502996_pT250GeV.root"]

features = ["class_event",
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

df_events = functions_boosted_bbtautau_events.read_root_files(list_VBF, features, input_folder)

print(df_events.head(5))

# variables to use in the training part
features_to_expand = [
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
    "recojet_antikt10UFO_GN2Xv01_ptop"
    ]

df_events["n_largeR_jets"] = df_events['recojet_antikt10UFO_NOSYS_pt'].apply(len)
df_events = df_events[df_events["n_largeR_jets"]>=2]
df_events_expanded = functions_boosted_bbtautau_events.expand_jet_features(df_events, features_to_expand, max_jets)
df_cleaned = df_events_expanded.copy()
df_cleaned["boosted_bbtautau"] = df_cleaned["class_event"].apply(
    lambda x: 1 if x==3 else 0 
)
df_cleaned.drop(columns=features, inplace=True)

# import pdb; pdb.set_trace()

##### Training

# Definition of the X and y dataframes, which are used to train the bdt model. X and y dataframes contains
# the jets that are boosted in a single dataframe and the class label, respectively.

X = df_cleaned.drop(columns="boosted_bbtautau", inplace=False).astype(np.float32)
y = df_cleaned["boosted_bbtautau"].astype(int)

X_array = X.to_numpy()
y_array = y.to_numpy()

# Training the BDT for boosted bb jets
bdt_bbtautau, X_train, X_test, y_train, y_test = functions_boosted_bbtautau_events.train_bdt_model(X_array, y_array)
# import pdb; pdb.set_trace()

# Plotting ROC Curve and Overtraining checking
# functions_boosted_bbtautau_events.definition_validation_plots(bdt_bbtautau, X_array, y_array, X_train, y_train, X_test, y_test, "bbtautau_events")
functions_boosted_bbtautau_events.definition_validation_plots(bdt_bbtautau, X, y, X_train, y_train, X_test, y_test, "bbtautau_events")

# Saving the model in onnx format
functions_boosted_bbtautau_events.save_model_with_TMVA(bdt_bbtautau, X_array, "bbtautau_events")
