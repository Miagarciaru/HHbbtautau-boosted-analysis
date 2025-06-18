import time  # to measure time to analyse
import h5py
import numpy as np
import pandas as pd
from onnx import TensorProto, helper
from skl2onnx import convert_sklearn
from skl2onnx.common.data_types import FloatTensorType
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import classification_report, roc_auc_score
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
import plotting_BDT

def read_h5_input_files(list_of_files: list, base_folder: str) -> pd.DataFrame:
    """
        This functions reads the names of the samples stored in the h5 list files, and extract the events and
        objects features to a df. Finally, it returns a concatenated df if there were more than two samples 
        in the list. 
    """
    
    frames = []
    for file_name in list_of_files:
        file_sample_name = base_folder+file_name
        # Open file HDF5
        with h5py.File(file_sample_name, "r") as f:
            # Convert the 'events' branch in a df
            temp_events = pd.DataFrame(f["events"][:])
            # Convert the dataset 'objects' in a structure per event (optional)
            temp_objects = f["objects"][:]
            frames.append(temp_events)

    df_events = pd.concat(frames) 
    return df_events

def train_bdt_model(X_df: pd.DataFrame, y_df: pd.DataFrame):
    """
        This functions trained the bdt model and returns the classifier with the splitted dataframes 
        samples.
    """
    start = time.time() # time at start of BDT fit
    X_train, X_test, y_train, y_test = train_test_split(X_df, y_df, test_size=0.3, random_state=492)
    dt = DecisionTreeClassifier(max_depth=5) # maximum depth of the tree
    bdt = AdaBoostClassifier(
        dt,
        algorithm='SAMME', # SAMME discrete boosting algorithm
        n_estimators=12, # max number of estimators at which boosting is terminated
        learning_rate=0.3 # shrinks the contribution of each classifier by learning_rate
    )
    bdt.fit(X_train, y_train)
    elapsed = time.time() - start # time after fitting BDT
    print("Time taken to fit BDT: "+str(round(elapsed,1))+"s") # print total time taken to fit BDT
    print(bdt)

    return bdt, X_train, X_test, y_train, y_test

def ranking_relevant_variables(clf: AdaBoostClassifier, X_df: pd.DataFrame) -> None:
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
    print("Ranking of the most important variables:")
    for i in range(len(features)):
        print(f"{i+1}. {features[indices[i]]} ({importances[indices[i]]:.3f})")

    plotting_BDT.correlation_plots(X_df) # plotting correlation between variables
    plotting_BDT.ranking_variables_plot(features, importances, indices) # plotting ranking of variables
    return

def definition_validation_plots(clf: AdaBoostClassifier, X_df: pd.DataFrame, y_df: pd.DataFrame, X_train: pd.DataFrame, y_train: pd.DataFrame, X_test: pd.DataFrame, y_test: pd.DataFrame) -> None:
    """
        This function computes the needed values to plot the ROC Curve and the overtraining check.
    """
    y_predicted = clf.predict(X_test) # get predicted y for test set
    print (classification_report(y_test, y_predicted,
                                target_names=["background", "signal"]))
    print ("Area under ROC curve for test data: %.4f"%(roc_auc_score(y_test,
                                                        clf.decision_function(X_test))) )

    plotting_BDT.roc_curve_plots(clf, X_df, y_df, X_test, y_test) # plotting roc curve for the bdt

    plotting_BDT.compare_train_test(clf, X_train, y_train, X_test, y_test) # plotting overtraining check
    return

def save_bdt_model(clf: AdaBoostClassifier, X_df: pd.DataFrame) -> None:
    """
        Convert the model into a ONNX file with the correct format required by HHARD
    """

    input_name = "jet_features"  # input name

    initial_type = [(input_name, FloatTensorType([None, X_df.shape[1]]))]

    # Forcing to save the onnx as predict proba 2d array
    options = {id(clf): {"zipmap": False}}  # Avoid dict returns
    onnx_model = convert_sklearn(clf, initial_types=initial_type, options=options)

    # track_input = helper.make_tensor_value_info("track_features", TensorProto.FLOAT, [None, X["NSmallRJets"].astype(int), 4])
    track_input = helper.make_tensor_value_info("track_features", TensorProto.FLOAT, [None, "n_tracks", 4])
    # track_input = helper.make_tensor_value_info("track_features", TensorProto.FLOAT, [None, 2, 4])
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
    with open("ML_models/bdt_model.onnx", "wb") as f:
        f.write(onnx_model.SerializeToString())

    print("Saved model in ONNX format in 'ML_models/bdt_model.onnx'")
    return