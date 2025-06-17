import pandas as pd
import os
import numpy as np
import time # to measure time to analyse
import h5py
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import classification_report, roc_auc_score
from skl2onnx import convert_sklearn
from skl2onnx.common.data_types import FloatTensorType
from onnx import helper, TensorProto
import plotting_BDT

# Reading VBF File
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttSM_ONE_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttSM_TWO_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttEFT_ONE_PASS.h5"
# file_VBF = "HHARD_input_h5files/mva_VBFHHbbttEFT_TWO_PASS.h5"

hhard_path_folder = "HHARD_input_h5files/"

list_VBF = ["mva_VBFHHbbttEFT_TWO_PASS.h5"]

frames_VBF = []

for file_name in list_VBF:
    file_VBF_name = hhard_path_folder+file_name
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

#### TODO: this code block has the same stucture as the one above, move it to a function?? 

list_ggF = ["mva_ggFHHbbttSM_ONE_PASS.h5", "mva_ggFHHbbttSM_TWO_PASS.h5"]

frames_ggF = []

for file_name in list_ggF:
    file_ggF_name = hhard_path_folder+file_name
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

features_to_keep = ["two_jets_j12_m", "Hbb_j1_Pt", "NSmallRJets", "mHH", "two_jets_j12_dR", "Htt_j1_dEta", "Hbb_j2_dEta", "Hbb_j2_dR"]

features = ["two_jets_j12_m", "two_jets_eta0eta1", "two_jets_j12_deta", "two_jets_j12_dphi", "two_jets_j12_dR", 
            "Htt_j1_Pt", "Htt_j1_dR", "Htt_j1_dEta", "Htt_j1_dPhi", "Htt_j2_Pt", "Htt_j2_dR", "Htt_j2_dEta", 
            "Htt_j2_dPhi", "Hbb_j1_Pt", "Hbb_j1_dR", "Hbb_j1_dEta", "Hbb_j1_dPhi", "Hbb_j2_Pt", "Hbb_j2_dR", 
            "Hbb_j2_dEta", "Hbb_j2_dPhi", "mHH", "pTHH", "etaHH", "phiHH", "dEtaHH", "NSmallRJets", "NLargeRJets", 
            "NBJets", "NTauJets"]

X_VBF = df_VBF_events[features].copy()
y_VBF = df_VBF_events["class_label"].copy()

X_ggF = df_ggF_events[features].copy()
y_ggF = df_ggF_events["class_label"].copy()

# keep only the 8 most relevant variables
# X_VBF[[f for f in df_VBF_events.columns if f not in features_to_keep]] = 0
# X_ggF[[f for f in df_VBF_events.columns if f not in features_to_keep]] = 0
# X_VBF = X_VBF[features_to_keep]
# X_ggF = X_ggF[features_to_keep]

X = pd.concat([X_ggF, X_VBF]).astype(np.float32)
y = pd.concat([y_ggF, y_VBF]).astype(int)

plotting_BDT.correlation_plots(X) # plotting correlation between variables

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=492)

dt = DecisionTreeClassifier(max_depth=5) # maximum depth of the tree
bdt = AdaBoostClassifier(
    dt,
    algorithm='SAMME', # SAMME discrete boosting algorithm
    n_estimators=12, # max number of estimators at which boosting is terminated
    learning_rate=0.3 # shrinks the contribution of each classifier by learning_rate
)
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
track_input = helper.make_tensor_value_info("track_features", TensorProto.FLOAT, ["n_tracks", 4])
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

# TODO: is there a vway to make a simpler reshape?? 

# squeeze_bdt_pggF, slice_bdt_pggF = create_sqeeze_reshape_layer("vbf")
# squeeze_bdt_pVBF, slice_bdt_pVBF = create_sqeeze_reshape_layer("ggf")
# graph.node.extend([slice_bdt_pggF, slice_bdt_pVBF])
# graph.node.extend([squeeze_bdt_pggF, squeeze_bdt_pVBF])


# Add constants for Slice node inputs
starts_0 = helper.make_tensor("starts_0", TensorProto.INT64, [1], [0])
ends_0 = helper.make_tensor("ends_0", TensorProto.INT64, [1], [1]) 
starts_1 = helper.make_tensor("starts_1", TensorProto.INT64, [1], [1])
ends_1 = helper.make_tensor("ends_1", TensorProto.INT64, [1], [2])
axes = helper.make_tensor("axes", TensorProto.INT64, [1], [1])
steps = helper.make_tensor("steps", TensorProto.INT64, [1], [1])
squeeze_axes = helper.make_tensor("squeeze_axes", TensorProto.INT64, [0], [])

for tensor in [starts_0, ends_0, starts_1, ends_1, axes, steps, squeeze_axes]:
    if not any(init.name == tensor.name for init in graph.initializer):
        graph.initializer.append(tensor)

# Slice node for bdt_pggF
slice_bdt_pggF = helper.make_node(
    "Slice",
    inputs=[original_output_name, "starts_0", "ends_0", "axes", "steps"],
    outputs=["bdt_pggF_raw"],
    name="slice_bdt_pggF"
)

# Slice node for bdt_pVBF
slice_bdt_pVBF = helper.make_node(
    "Slice",
    inputs=[original_output_name, "starts_1", "ends_1", "axes", "steps"],
    outputs=["bdt_pVBF_raw"],
    name="slice_bdt_pVBF"
)

graph.node.extend([slice_bdt_pggF, slice_bdt_pVBF])

squeeze_bdt_pggF = helper.make_node(
    "Squeeze",
    inputs=["bdt_pggF_raw", "squeeze_axes"],
    outputs=["bdt_pggF"],
    name="squeeze_bdt_pggF"
)

squeeze_bdt_pVBF = helper.make_node(
    "Squeeze",
    inputs=["bdt_pVBF_raw", "squeeze_axes"],
    outputs=["bdt_pVBF"],
    name="squeeze_bdt_pVBF"
)
graph.node.extend([squeeze_bdt_pggF, squeeze_bdt_pVBF])

# Add news outputs 
graph.output.extend([
    helper.make_tensor_value_info('bdt_pggF', TensorProto.FLOAT, shape=[]),
    helper.make_tensor_value_info('bdt_pVBF', TensorProto.FLOAT, shape=[]),
])

for output_name in ["label", "probabilities"]:
    for output in graph.output:
        if output.name == output_name:
            graph.output.remove(output)
            break

for output in onnx_model.graph.output:
    print("Output name:", output.name)

# Save the file .onnx
os.makedirs("ML_models", exist_ok=True)
with open("ML_models/bdt_model.onnx", "wb") as f:
    f.write(onnx_model.SerializeToString())

print("Saved model in ONNX format in 'ML_models/bdt_model.onnx'")