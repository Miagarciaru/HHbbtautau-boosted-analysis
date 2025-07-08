import time  # to measure time to analyse
import numpy as np
import pandas as pd
from onnx import TensorProto, helper
from skl2onnx import convert_sklearn
from skl2onnx.common.data_types import FloatTensorType
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import classification_report, roc_auc_score
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
import uproot3
import plotting_BDT
import ROOT
import xgboost as xgb
from xgboost import XGBClassifier
# from onnxmltools.convert import convert_xgboost
# from onnxmltools.convert.common.data_types import FloatTensorType

# def expand_jet_features(df, features, max_jets=15):
#     df_base = df.copy()

#     # List to acumulate df with expanded columns
#     expanded_cols = []

#     for feature in features:
#         expanded = pd.DataFrame(
#             df[feature].apply(
#                 lambda x: list(x) + [0.0] * (max_jets - len(x))  # padding
#             ).to_list(),
#             columns=[f"{feature}{i}" for i in range(max_jets)]
#         )
#         expanded_cols.append(expanded)

#     # Concatenate all in a single final df
#     df_final = pd.concat([df_base] + expanded_cols, axis=1)

#     return df_final

def expand_jet_features(df, features, max_jets):
    df_expanded = df.copy()
    for feature in features:
        for i in range(max_jets):
            df_expanded[f"{feature}_{i}"] = df[feature].apply(
                lambda x: x[i] if i < len(x) else 0.0
            )
    return df_expanded

def get_df_with_info_jets(df_events: pd.DataFrame, explode_branches: list, boosted_idx_name: str) -> pd.DataFrame:

    df_jets = df_events.explode(explode_branches)

    # Create a column with the jet index
    df_jets["jet_index"] = df_jets.groupby("entry").cumcount()
    df_jets.reset_index(drop=True, inplace=True)

    name_column = ""
    is_boosted_label = ""
    if(boosted_idx_name == "idx_b1truth_recoak10_dRmin"):
        name_column = "is_boosted_bb_jet"
        is_boosted_label = "truth_reco_match_for_boosted_bb"

    if(boosted_idx_name == "idx_tau1truth_recoak10_dRmin"):
         name_column = "is_boosted_tautau_jet"
         is_boosted_label = "truth_reco_match_for_boosted_tautau"

    df_jets[name_column] = np.vectorize(is_boosted_jet)(df_jets[is_boosted_label], df_jets["jet_index"], df_jets[boosted_idx_name], boosted_idx_name)
    
    # Result
    print(len(df_jets[df_jets[name_column]==1])/len(df_jets)*100)
    print(df_jets.columns)

    return df_jets

def is_boosted_jet(is_boosted_label, jet_idx, boosted_jet_idx, name_boosted_jet):
    
    if(name_boosted_jet == "idx_b1truth_recoak10_dRmin"):
        if(is_boosted_label==True and jet_idx == boosted_jet_idx):
            return 1
        else:
            return 0

    if(name_boosted_jet == "idx_tau1truth_recoak10_dRmin"):
        if(is_boosted_label==True and jet_idx == boosted_jet_idx):
            return 1
        else:
            return 0

def read_root_files(list_of_samples: list, features: list, base_folder: str) -> pd.DataFrame:
    
    frames = []
    for sample_name in list_of_samples:
        file_path = base_folder+sample_name
        tree = uproot3.open(file_path)["AnalysisMiniTree"] # open the tree called mini
        numevents = uproot3.numentries(file_path, "AnalysisMiniTree") # number of events
        print(numevents)
        for data in tree.iterate(features,
                                    outputtype=pd.DataFrame): # choose output type as pandas DataFrame
                                #  entrystop=numevents*fraction):
            frames.append(data)
    df_events = pd.concat(frames) 
    return df_events


def train_bdt_model(X_df, y_df):
    """
        This functions trained the bdt model and returns the classifier with the splitted dataframes 
        samples.
    """
    
    start = time.time() # time at start of BDT fit
    X_train, X_test, y_train, y_test = train_test_split(X_df, y_df, test_size=0.3, random_state=42)
    
    scale_pos_weight = np.sum(y_train == 0) / np.sum(y_train == 1)

    bdt = XGBClassifier(n_estimators=100, 
                        max_depth=3, 
                        learning_rate=0.1,
                        seed = 42, 
                        scale_pos_weight=scale_pos_weight,
                        eval_metric='logloss'
                        )

    bdt.fit(X_train, y_train)
    elapsed = time.time() - start # time after fitting BDT
    print("Time taken to fit BDT: "+str(round(elapsed,1))+"s") # print total time taken to fit BDT
    print(bdt)

    return bdt, X_train, X_test, y_train, y_test

def ranking_relevant_variables(clf: AdaBoostClassifier, X_df: pd.DataFrame, name_boosted_jet: str) -> None:
    """
        This functions computes the relevance of each variable used to train the bdt model, and ranking them
        from more relevant to less relevant variables. This also produces plots for the Correlation matrix
        and ranking of the used variables.
    """

    # Name of the variables
    features = X_df.columns

    # computed importance of each variable used in the training part                                                                                               
    importances = clf.feature_importances_

    # Ordered by most important to less important                                                                                                                  
    indices = np.argsort(importances)[::-1]

    # Ranking                                                                                                                                                      
    print("Ranking of the most important variables for "+name_boosted_jet+":")
    for i in range(len(features)):
        print(f"{i+1}. {features[indices[i]]} ({importances[indices[i]]:.3f})")

    plotting_BDT.correlation_plots(X_df, name_boosted_jet) # plotting correlation between variables
    plotting_BDT.ranking_variables_plot(features, importances, indices, name_boosted_jet) # plotting ranking of variables
    return

def definition_validation_plots(clf: AdaBoostClassifier, X_df: pd.DataFrame, y_df: pd.DataFrame, X_train: pd.DataFrame, y_train: pd.DataFrame, X_test: pd.DataFrame, y_test: pd.DataFrame, name_boosted_jet: str) -> None:
    """
        This function computes the needed values to plot the ROC Curve and the overtraining check.
    """
    y_predicted = clf.predict(X_test)
    # y_predicted = pd.Series(probas, index=y_test.index)

    print (classification_report(y_test, y_predicted,
                                target_names=["background", "signal"]))

    print ("Area under ROC curve for test data: %.4f"%(roc_auc_score(y_test,
                                                        clf.predict_proba(X_test)[:, 1])) )

    plotting_BDT.roc_curve_plots(clf, X_df, y_df, X_test, y_test, name_boosted_jet) # plotting roc curve for the bdt

    plotting_BDT.compare_train_test(clf, X_train, y_train, X_test, y_test, name_boosted_jet) # plotting overtraining check
    return

def save_model_with_TMVA(clf, X_df, name_boosted_jet):
   
    output_path = f"ML_models/tmva101_{name_boosted_jet}.root"
    name_bdt = "myBDT_"+name_boosted_jet
    # import pdb; pdb.set_trace()
    ROOT.TMVA.Experimental.SaveXGBoost(clf, name_bdt, output_path, X_df.shape[1])

    # # Accessing the Booster
    # booster = clf.get_booster()

    # # Define el tipo de entrada (asegúrate que sea float32)
    # initial_type = [('jet_features', FloatTensorType([1, X_df.shape[1]]))]

    # Conversión
    # onnx_model = convert_xgboost(booster, initial_types=initial_type, target_opset=12)

    # # Guarda el modelo ONNX
    # with open(f"ML_models/bdt_model_{name_boosted_jet}.onnx", "wb") as f:
    #     f.write(onnx_model.SerializeToString())

    return

def save_bdt_model(clf: AdaBoostClassifier, X_df: pd.DataFrame, name_boosted_jet: str) -> None:
    """
        Convert the model into a ONNX file with the correct format required by HHARD
    """

    if(name_boosted_jet=="bb_jets"):
        bkg_label = "non boosted bb jets"
        sgl_label = "boosted bb jets"

    if(name_boosted_jet=="tautau_jets"):
        bkg_label = "non boosted tautau jets"
        sgl_label = "boosted tautau jets"

    input_name = "jet_features"  # input name

    # initial_type = [(input_name, FloatTensorType([None, X_df.shape[1]]))]
    initial_type = [(input_name, FloatTensorType([1, X_df.shape[1]]))]

    # Forcing to save the onnx as predict proba 2d array
    options = {id(clf): {"zipmap": False}}  # Avoid dict returns
    # options = {id(clf): {'dtype': 'float32'}}
    onnx_model = convert_sklearn(clf, initial_types=initial_type, options=options, target_opset=13 )

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
    starts_0 = helper.make_tensor("starts_0", TensorProto.FLOAT, [1], [0])
    ends_0 = helper.make_tensor("ends_0", TensorProto.FLOAT, [1], [1]) 
    starts_1 = helper.make_tensor("starts_1", TensorProto.FLOAT, [1], [1])
    ends_1 = helper.make_tensor("ends_1", TensorProto.FLOAT, [1], [2])
    axes = helper.make_tensor("axes", TensorProto.FLOAT, [1], [1])
    steps = helper.make_tensor("steps", TensorProto.FLOAT, [1], [1])
    squeeze_axes = helper.make_tensor("squeeze_axes", TensorProto.FLOAT, [0], [])

    for tensor in [starts_0, ends_0, starts_1, ends_1, axes, steps, squeeze_axes]:
        if not any(init.name == tensor.name for init in graph.initializer):
            graph.initializer.append(tensor)

    # Slice node for bdt_pggF
    slice_bdt_prob_non_boosted_jet = helper.make_node(
        "Slice",
        inputs=[original_output_name, "starts_0", "ends_0", "axes", "steps"],
        outputs=["bdt_prob_non_boosted_jet_raw"],
        name="slice_bdt_prob_non_boosted_jet"
    )

    # Slice node for bdt_pVBF
    slice_bdt_prob_boosted_jet = helper.make_node(
        "Slice",
        inputs=[original_output_name, "starts_1", "ends_1", "axes", "steps"],
        outputs=["bdt_prob_boosted_jet_raw"],
        name="slice_bdt_prob_boosted_jet"
    )

    graph.node.extend([slice_bdt_prob_non_boosted_jet, slice_bdt_prob_boosted_jet])

    squeeze_bdt_prob_non_boosted_jet = helper.make_node(
        "Squeeze",
        inputs=["bdt_prob_non_boosted_jet_raw", "squeeze_axes"],
        outputs=["bdt_prob_non_boosted_jet"],
        name="squeeze_bdt_prob_non_boosted_jet"
    )

    squeeze_bdt_prob_boosted_jet = helper.make_node(
        "Squeeze",
        inputs=["bdt_prob_boosted_jet_raw", "squeeze_axes"],
        outputs=["bdt_prob_boosted_jet"],
        name="squeeze_bdt_prob_boosted_jet"
    )
    graph.node.extend([squeeze_bdt_prob_non_boosted_jet, squeeze_bdt_prob_boosted_jet])

    # Add news outputs 
    graph.output.extend([
        helper.make_tensor_value_info('bdt_prob_non_boosted_jet', TensorProto.FLOAT, shape=[]),
        helper.make_tensor_value_info('bdt_prob_boosted_jet', TensorProto.FLOAT, shape=[]),
    ])

    for output_name in ["label", "probabilities"]:
        for output in graph.output:
            if output.name == output_name:
                graph.output.remove(output)
                break

    for output in onnx_model.graph.output:
        print("Output name:", output.name)

    # Save the file .onnx
    with open("ML_models/bdt_model_"+name_boosted_jet+".onnx", "wb") as f:
        f.write(onnx_model.SerializeToString())

    print("Saved model in ONNX format in 'ML_models/bdt_model_"+name_boosted_jet+".onnx'")
    
    return