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

    return