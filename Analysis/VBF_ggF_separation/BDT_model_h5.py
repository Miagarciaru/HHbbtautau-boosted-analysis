import uproot
import pandas as pd
import awkward as ak
import matplotlib.pyplot as plt
import numpy as np
import time # to measure time to analyse
import seaborn as sns
import joblib
import h5py
from sklearn.model_selection import train_test_split
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import classification_report, roc_auc_score
from sklearn.metrics import roc_curve, auc
from skl2onnx import convert_sklearn
from skl2onnx.common.data_types import FloatTensorType
import onnx
from onnx import helper, numpy_helper, TensorProto
import plotting_BDT

# Reading VBF File
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttSM_ONE_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttSM_TWO_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttEFT_ONE_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttEFT_TWO_PASS.h5"

list_VBF = ["mva_VBFHHbbttEFT_ONE_PASS.h5", "mva_VBFHHbbttEFT_TWO_PASS.h5"]

frames_VBF = []

for file_name in list_VBF:
    file_VBF_name = "HHARD_input_h5files/"+file_name
    # Open file HDF5
    with h5py.File(file_VBF_name, "r") as f:
        # Convert the 'events' branch in a df
        temp_events = pd.DataFrame(f["events"][:])
        # Convert the dataset 'objects' in a structure per event (optional)
        temp_array = f["objects"][:]
        frames_VBF.append(temp_events)

df_VBF_events = pd.concat(frames_VBF) 

# Show the first events
print(len(df_VBF_events))

# Reading ggF File
# file_ggF = "HHARD_input_h5files/mva_ggFHHbbttSM_ONE_PASS.h5"
# file_ggF = "HHARD_input_h5files/mva_ggFHHbbttSM_TWO_PASS.h5"

list_ggF = ["mva_ggFHHbbttSM_ONE_PASS.h5", "mva_ggFHHbbttSM_TWO_PASS.h5"]

frames_ggF = []

for file_name in list_ggF:
    file_ggF_name = "HHARD_input_h5files/"+file_name
    # Open file HDF5
    with h5py.File(file_ggF_name, "r") as f:
        # Convert the 'events' branch in a df
        temp_events = pd.DataFrame(f["events"][:])
        # Convert the dataset 'objects' in a structure per event (optional)
        temp_array = f["objects"][:]
        frames_ggF.append(temp_events)

df_ggF_events = pd.concat(frames_ggF) 

# Show the first events
print(len(df_ggF_events))

##### Training

# variables to use in the training part

# features = ["two_jets_j12_m", "Hbb_j1_Pt", "NSmallRJets", "mHH", "two_jets_j12_dR", "Htt_j1_dEta", "Hbb_j2_dEta", "Hbb_j2_dR"]

features = ["two_jets_j12_m", "two_jets_eta0eta1", "two_jets_j12_deta", "two_jets_j12_dphi", "two_jets_j12_dR", 
            "Htt_j1_Pt", "Htt_j1_dR", "Htt_j1_dEta", "Htt_j1_dPhi", "Htt_j2_Pt", "Htt_j2_dR", "Htt_j2_dEta", 
            "Htt_j2_dPhi", "Hbb_j1_Pt", "Hbb_j1_dR", "Hbb_j1_dEta", "Hbb_j1_dPhi", "Hbb_j2_Pt", "Hbb_j2_dR", 
            "Hbb_j2_dEta", "Hbb_j2_dPhi", "mHH", "pTHH", "etaHH", "phiHH", "dEtaHH", "NSmallRJets", "NLargeRJets", 
            "NBJets", "NTauJets"]

X_VBF = df_VBF_events[features].copy()
y_VBF = df_VBF_events["class_label"].copy()

X_ggF = df_ggF_events[features].copy()
y_ggF = df_ggF_events["class_label"].copy()

X = pd.concat([X_ggF, X_VBF]).astype(np.float32)
y = pd.concat([y_ggF, y_VBF]).astype(int)

plotting_BDT.correlation_plots(X) # plotting correlation between variables

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=492)

dt = DecisionTreeClassifier(max_depth=2) # maximum depth of the tree
bdt = AdaBoostClassifier(dt,
                        algorithm='SAMME', # SAMME discrete boosting algorithm
                        n_estimators=12, # max number of estimators at which boosting is terminated
                        learning_rate=0.5) # shrinks the contribution of each classifier by learning_rate

start = time.time() # time at start of BDT fit
bdt.fit(X_train, y_train)
elapsed = time.time() - start # time after fitting BDT
print("Time taken to fit BDT: "+str(round(elapsed,1))+"s") # print total time taken to fit BDT
print(bdt)

# Name of the variables
features = X.columns

# computed importance of each variable used in the training part                                                                                               
importances = bdt.feature_importances_

# Ordered by most important to less important                                                                                                                  
indices = np.argsort(importances)[::-1]

# Ranking                                                                                                                                                      
print("Ranking of the most important variables:")
for i in range(len(features)):
    print(f"{i+1}. {features[indices[i]]} ({importances[indices[i]]:.3f})")

plotting_BDT.ranking_variables_plot(features, importances, indices) # plotting ranking of variables

y_predicted = bdt.predict(X_test) # get predicted y for test set
print (classification_report(y_test, y_predicted,
                            target_names=["background", "signal"]))
print ("Area under ROC curve for test data: %.4f"%(roc_auc_score(y_test,
                                                    bdt.decision_function(X_test))) )

plotting_BDT.roc_curve_plots(bdt, X, y, X_test, y_test) # plotting roc curve for the bdt

plotting_BDT.compare_train_test(bdt, X_train, y_train, X_test, y_test) # plotting overtraining check

# # Apply BDT to all the events
# df["bdt_score"] = bdt.predict_proba(X)[:, 1]

print(X.dtypes)
print(y.dtypes)

# Convert the model into a ONNX file

input_name = "jet_features"  # input name

# initial_type = [("input", FloatTensorType([None, X.shape[1]]))]
initial_type = [(input_name, FloatTensorType([None, X.shape[1]]))]

# initial_type = [
#     ("jet_features", FloatTensorType([None, X.shape[1]])),
#     ("track_features", FloatTensorType([None, 2, 4])) # 2 objetos, 4 variables
# ]

# Force to save the onnx as predict proba 2d array
options = {id(bdt): {"zipmap": False}}  # Avoid dict returns
onnx_model = convert_sklearn(bdt, initial_types=initial_type, options=options)

# track_input = helper.make_tensor_value_info("track_features", TensorProto.FLOAT, [None, X["NSmallRJets"].astype(int), 4])
track_input = helper.make_tensor_value_info("track_features", TensorProto.FLOAT, [None, 2, 4])
onnx_model.graph.input.append(track_input)

# Now we separate the output called "probabilities" in two separated outputs
graph = onnx_model.graph

# Original output name 
original_output_name = graph.output[1].name  # "probabilities"

# print(graph.output[0].name)
# import pdb; pdb.set_trace()
# print("*****************************************************")
# for output in onnx_model.graph.output:
#     print(output.name, output.type)
#     # import pdb; pdb.set_trace()
# print("*****************************************************")

split_initializer = helper.make_tensor(
    name="split_sizes",
    data_type=TensorProto.INT64,
    dims=[2],
    vals=[1, 1]
)

split_node = helper.make_node(
    'Split',
    inputs=[original_output_name, "split_sizes"],  # split_sizes is the new entry
    outputs=['bdt_pggF', 'bdt_pVBF'],
    axis=1,
    name='SplitProbabilities'
)

graph.initializer.append(split_initializer)
graph.node.append(split_node)

# Add news outputs 
graph.output.extend([
    helper.make_tensor_value_info('bdt_pggF', TensorProto.FLOAT, [None, 1]),
    helper.make_tensor_value_info('bdt_pVBF', TensorProto.FLOAT, [None, 1]),
])

for output_name in ["label", "probabilities"]:
    for output in graph.output:
        if output.name == output_name:
            graph.output.remove(output)
            break

for output in onnx_model.graph.output:
    print("Output name:", output.name)

# Save the file .onnx
with open("ML_models/bdt_model.onnx", "wb") as f:
    f.write(onnx_model.SerializeToString())

print("Saved model in ONNX format in 'ML_models/bdt_model.onnx'")