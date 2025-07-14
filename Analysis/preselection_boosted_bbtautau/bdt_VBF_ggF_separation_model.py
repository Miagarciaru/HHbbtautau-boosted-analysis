import numpy as np
import pandas as pd
import os
import functions_VBF_ggF_separation

input_folder = "output_analysis/"
max_jets = 15

# Creating folders to save the plots
os.makedirs("ML_models", exist_ok=True)
os.makedirs("BDT_plots", exist_ok=True)

# List of all available samples

list_VBF = [
    "VBF_cvv1p5_hh_502985_pT250GeV.root", 
    "VBF_cvv1p5_lh_502996_pT250GeV.root",
    "VBF_SM_hh_502982_pT250GeV.root", 
    "VBF_SM_lh_502993_pT250GeV.root"
    ]

list_ggF = [
    "ggF_lambda10_hh_600460_pT250GeV.root", 
    "ggF_lambda10_lh_600462_pT250GeV.root",
    "ggF_SM_hh_600459_pT250GeV.root", 
    "ggF_SM_lh_600461_pT250GeV.root"
    ]

features = [
    "matched_recojet_j12_mjj_sel",
    "recojet_j12_m", 
    "recojet_j12_deta", 
    "recojet_j12_dphi", 
    "recojet_j12_dR", 
    "recojet_tautau_j1_system_pt",
    "recojet_tautau_j1_system_deta",
    "recojet_tautau_j1_system_dphi",
    "recojet_tautau_j1_system_dR",
    "recojet_tautau_j2_system_pt",
    "recojet_tautau_j2_system_deta",
    "recojet_tautau_j2_system_dphi",
    "recojet_tautau_j2_system_dR",
    "recojet_bb_j1_system_pt",
    "recojet_bb_j1_system_deta",
    "recojet_bb_j1_system_dphi",
    "recojet_bb_j1_system_dR",
    "recojet_bb_j2_system_pt",
    "recojet_bb_j2_system_deta",
    "recojet_bb_j2_system_dphi",
    "recojet_bb_j2_system_dR",
    "recojet_bbtautau_system_m",
    "recojet_bbtautau_system_pt",
    "recojet_bbtautau_system_eta",
    "recojet_bbtautau_system_phi",
    "recojet_bbtautau_system_deta",
    "recojet_bbtautau_system_dphi",
    "recojet_bbtautau_system_dR"
    # "NSmallRJets", 
    # "NLargeRJets", 
    # "NBJets", 
    # "NTauJets"
]

df_VBF = functions_VBF_ggF_separation.read_root_files(list_VBF, features, input_folder)
df_ggF = functions_VBF_ggF_separation.read_root_files(list_ggF, features, input_folder)

df_VBF = df_VBF[df_VBF["matched_recojet_j12_mjj_sel"]==True]
df_ggF = df_ggF[df_ggF["matched_recojet_j12_mjj_sel"]==True]

df_VBF["process_label"] = 1
df_ggF["process_label"] = 0

print(df_VBF)
print(df_ggF)

df_VBF.drop(columns="matched_recojet_j12_mjj_sel", inplace=True)
df_ggF.drop(columns="matched_recojet_j12_mjj_sel", inplace=True)

df_events = pd.concat([df_ggF, df_VBF])

X = df_events.drop(columns="process_label", inplace=False)
y = df_events["process_label"].copy()

X = X.astype(np.float32)
y = y.astype(int)

##### Training

# Definition of the X and y dataframes, which are used to train the bdt model. X and y dataframes contains
# the jets that are boosted in a single dataframe and the class label, respectively.

X_array = X.to_numpy()
y_array = y.to_numpy()

print(X_array)
print(y_array)

# Training the BDT for boosted bb jets
bdt_VBF_ggF_separation, X_train, X_test, y_train, y_test = functions_VBF_ggF_separation.train_bdt_model(X_array, y_array)
# import pdb; pdb.set_trace()

# Plotting ranking of variables and their correlation matrix
functions_VBF_ggF_separation.ranking_relevant_variables(bdt_VBF_ggF_separation, X, "VBF_ggF_separation")

# Plotting ROC Curve and Overtraining checking
functions_VBF_ggF_separation.definition_validation_plots(bdt_VBF_ggF_separation, X_array, y_array, X_train, y_train, X_test, y_test, "VBF_ggF_separation")
# functions_boosted_bbtautau_events.definition_validation_plots(bdt_bbtautau, X, y, X_train, y_train, X_test, y_test, "bbtautau_events")

# Saving the model in onnx format
functions_VBF_ggF_separation.save_model_with_TMVA(bdt_VBF_ggF_separation, X_array, "VBF_ggF_separation")
