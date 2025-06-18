import numpy as np
import pandas as pd
import os
import functions
import plotting_BDT

hhard_path_folder = "HHARD_input_h5files/"

# Creating folders to save the plots
os.makedirs("ML_models", exist_ok=True)
os.makedirs("BDT_plots", exist_ok=True)

# List of all available VBF samples
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttSM_ONE_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttSM_TWO_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttEFT_ONE_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttEFT_TWO_PASS.h5"

list_VBF = ["mva_VBFHHbbttEFT_TWO_PASS.h5"]

# List of all available ggF samples
# file_ggF = "HHARD_input_h5files/mva_ggFHHbbttSM_ONE_PASS.h5"
# file_ggF = "HHARD_input_h5files/mva_ggFHHbbttSM_TWO_PASS.h5"

list_ggF = ["mva_ggFHHbbttSM_ONE_PASS.h5", "mva_ggFHHbbttSM_TWO_PASS.h5"]

df_VBF_events = functions.read_h5_input_files(list_VBF, hhard_path_folder)
df_ggF_events = functions.read_h5_input_files(list_ggF, hhard_path_folder)

# Show the number of events in the VBF samples
print(len(df_VBF_events))

# Show the number of events in the ggF samples
print(len(df_ggF_events))

##### Training

# variables to use in the training part

features_to_keep = ["two_jets_j12_m", "Hbb_j1_Pt", "NSmallRJets", "mHH", "two_jets_j12_dR", "Htt_j1_dEta", "Hbb_j2_dEta", "Hbb_j2_dR"]

features = ["two_jets_j12_m", "two_jets_eta0eta1", "two_jets_j12_deta", "two_jets_j12_dphi", "two_jets_j12_dR", 
            "Htt_j1_Pt", "Htt_j1_dR", "Htt_j1_dEta", "Htt_j1_dPhi", "Htt_j2_Pt", "Htt_j2_dR", "Htt_j2_dEta", 
            "Htt_j2_dPhi", "Hbb_j1_Pt", "Hbb_j1_dR", "Hbb_j1_dEta", "Hbb_j1_dPhi", "Hbb_j2_Pt", "Hbb_j2_dR", 
            "Hbb_j2_dEta", "Hbb_j2_dPhi", "mHH", "pTHH", "etaHH", "phiHH", "dEtaHH", "NSmallRJets", "NLargeRJets", 
            "NBJets", "NTauJets"]

# Definition of the X and y dataframes, which are used to train the bdt model. X and y dataframes contains
# the ggF and VBF events in a single dataframe and the class label, respectively.

X_VBF = df_VBF_events[features].copy()
y_VBF = df_VBF_events["class_label"].copy()

X_ggF = df_ggF_events[features].copy()
y_ggF = df_ggF_events["class_label"].copy()

X = pd.concat([X_ggF, X_VBF]).astype(np.float32)
y = pd.concat([y_ggF, y_VBF]).astype(int)

# Training the BDT
bdt, X_train, X_test, y_train, y_test = functions.train_bdt_model(X, y)

# Plotting ranking of variables and their correlation matrix
functions.ranking_relevant_variables(bdt, X)

# Plotting ROC Curve and Overtraining checking
functions.definition_validation_plots(bdt, X, y, X_train, y_train, X_test, y_test)

print(X.dtypes)
print(y.dtypes)

# Saving the model in onnx format
functions.save_bdt_model(bdt, X)
