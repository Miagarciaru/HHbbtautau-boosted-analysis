import os
import awkward as ak
import h5py
import numpy as np
import onnxruntime as rt
import pandas as pd
import uproot
import plotting_BDT

# Load the model
sess = rt.InferenceSession("ML_models/bdt_model.onnx")
input_name = sess.get_inputs()[0].name
output_name = sess.get_outputs()[0].name

# Variables used for the bdt model

features = ["preselected_j12_m", "two_jets_eta0eta1", "preselected_j12_deta", "preselected_j12_dphi", "preselected_j12_dR", 
            "Htt_j1_Pt", "Htt_j1_dR", "Htt_j1_dEta", "Htt_j1_dPhi", "Htt_j2_Pt", "Htt_j2_dR", "Htt_j2_dEta", 
            "Htt_j2_dPhi", "Hbb_j1_Pt", "Hbb_j1_dR", "Hbb_j1_dEta", "Hbb_j1_dPhi", "Hbb_j2_Pt", "Hbb_j2_dR", 
            "Hbb_j2_dEta", "Hbb_j2_dPhi", "mHH", "pTHH", "etaHH", "phiHH", "dEtaHH", "NSmallRJets", "NLargeRJets", 
            "NBJets", "NTauJets"]

# List of files
files_h5 = [f for f in os.listdir("HHARD_input_h5files") if f.endswith(".h5")]
print(files_h5)

dict_list = {}
color_list = ["gray", "black", "blue", "green", "red", "orange"]
color = 0

for file in files_h5:
    file_name = "HHARD_input_h5files/"+file
    with h5py.File(file_name, "r") as f:
        original_df = pd.DataFrame(f["events"][:])
        n_tracks_df = pd.DataFrame(f["objects"]["valid"])
        n_tracks_df["n_tracks"] = n_tracks_df.sum(axis=1)    
        n_tracks = n_tracks_df["n_tracks"].to_numpy()
        max_tracks = max(n_tracks)

        X = original_df[features].copy()
        # print(X)
        X = X.astype(np.float32).to_numpy()
        # sec_tracks_input = np.zeros((1, 2, 4), dtype=np.float32)   # 2 objects with zeros entries values
        # tracks_input = np.zeros((1, 2, 4), dtype=np.float32)   # 2 objects with zeros entries values
        # tracks_input = [np.zeros((n, 4), dtype=np.float32) for n in n_tracks]
        # tracks_input = np.zeros((len(n_tracks), max_tracks, 4), dtype=np.float32)
        tracks_input = np.zeros((1, max_tracks, 4), dtype=np.float32)
       
        outputs = sess.run(None, {
            "jet_features": X,
            "track_features": tracks_input
        })

        bdt_scores = outputs[1]
        original_df["bdt_score"] = bdt_scores

        print(original_df[["class_label", "bdt_score"]])

        dict_list[file] = {
            'variable': original_df["bdt_score"],
            'color': color_list[color] 
        }

        color = color+1


plotting_BDT.distribution_plots(dict_list, files_h5)

print(dict_list)