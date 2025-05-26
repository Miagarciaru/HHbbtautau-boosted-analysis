import uproot
import pandas as pd
import awkward as ak
import matplotlib.pyplot as plt
import numpy as np
import time # to measure time to analyse
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import classification_report, roc_auc_score
from sklearn.metrics import roc_curve, auc

# Reading ROOT file
file = uproot.open("output_analysis/input_BDT.root")
tree = file["AnalysisMiniTree"]
df = tree.arrays(library="pd")

# Training

# variables\to use in the training part
#X = df[["two_jets_j12_m", "two_jets_j12_pt", "two_jets_j12_eta", "two_jets_j12_phi", "two_jets_j12_deta", "two_jets_j12_dphi", "two_jets_j12_dR", "boosted_bb_tautau_system_m", "boosted_bb_tautau_system_pt", "boosted_bb_tautau_system_eta", "boosted_bb_tautau_system_phi", "boosted_bb_tautau_system_deta" , "boosted_bb_tautau_system_dphi", "boosted_bb_tautau_system_dR", "boosted_bb_j1_system_m", "boosted_bb_j1_system_pt", "boosted_bb_j1_system_eta", "boosted_bb_j1_system_phi", "boosted_bb_j1_system_deta", "boosted_bb_j1_system_dphi", "boosted_bb_j1_system_dR",  "boosted_bb_j2_system_m", "boosted_bb_j2_system_pt", "boosted_bb_j2_system_eta", "boosted_bb_j2_system_phi", "boosted_bb_j2_system_deta", "boosted_bb_j2_system_dphi", "boosted_bb_j2_system_dR", "boosted_tautau_j1_system_m", "boosted_tautau_j1_system_pt", "boosted_tautau_j1_system_eta", "boosted_tautau_j1_system_phi", "boosted_tautau_j1_system_deta", "boosted_tautau_j1_system_dphi", "boosted_tautau_j1_system_dR",  "boosted_tautau_j2_system_m", "boosted_tautau_j2_system_pt", "boosted_tautau_j2_system_eta", "boosted_tautau_j2_system_phi", "boosted_tautau_j2_system_deta", "boosted_tautau_j2_system_dphi", "boosted_tautau_j2_system_dR", "boosted_all_jets_system_m", "boosted_all_jets_system_pt", "boosted_all_jets_system_eta", "boosted_all_jets_system_phi", "boosted_all_jets_system_deta", "boosted_all_jets_system_dphi", "boosted_all_jets_system_dR", "smallR_jets_n", "largeR_jets_n"]]  

#X = df[["boosted_all_jets_system_m", "boosted_bb_tautau_system_deta", "two_jets_j12_m", "boosted_tautau_j1_system_m", "two_jets_j12_pt", "boosted_bb_j1_system_eta", "boosted_bb_j2_system_pt", "boosted_tautau_j2_system_eta", "boosted_tautau_j1_system_eta", "boosted_bb_j1_system_pt", "smallR_jets_n", "largeR_jets_n"]]  # variables to use in the training part

X = df[["boosted_all_jets_system_m", "two_jets_j12_m", "boosted_bb_j1_system_pt", "smallR_jets_n", "boosted_bb_tautau_system_m", "two_jets_j12_dR", "boosted_tautau_j1_system_deta", "boosted_bb_j2_system_deta", "boosted_bb_j2_system_dR"]]

y = df["process_type_like"]

correlation_matrix = X.corr()
plt.figure(figsize=(20, 16)) # make new figure
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt=".2f", cbar_kws={"shrink": 0.8})
plt.title("Variables correlation matrix")
plt.tight_layout() 
plt.savefig("BDT_plots/correlation_matrix.pdf")

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=492)

dt = DecisionTreeClassifier(max_depth=2) # maximum depth of the tree
bdt = AdaBoostClassifier(dt,
                        algorithm='SAMME', # SAMME discrete boosting algorithm
                        n_estimators=12, # max number of estimators at which boosting is terminated
                        learning_rate=0.5) # shrinks the contribution of each classifier by learning_rate

start = time.time() # time at start of BDT fit
#bdt = GradientBoostingClassifier(n_estimators=100, max_depth=3)
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

# Plotting                                                                                                                                                     
plt.figure(figsize=(8, 6))
plt.title("Importance of each variable")
plt.bar(range(len(features)), importances[indices], align="center")
plt.xticks(range(len(features)), features[indices], rotation=90)
plt.tight_layout()
plt.savefig("BDT_plots/importance_ranking_BDT.pdf")
plt.figure()
#plt.show()

y_predicted = bdt.predict(X_test) # get predicted y for test set
print (classification_report(y_test, y_predicted,
                            target_names=["background", "signal"]))
print ("Area under ROC curve for test data: %.4f"%(roc_auc_score(y_test,
                                                    bdt.decision_function(X_test))) )

# we first plot the Neural Network output
#signal_decisions = bdt.decision_function(X[y>0.5]).ravel() # get probabilities on signal
#background_decisions = bdt.decision_function(X[y<0.5]).ravel() # get decisions on background

signal_decisions = bdt.predict_proba(X[y>0.5])[:, 1] # get probabilities on signal
background_decisions = bdt.predict_proba(X[y<0.5])[:, 1] # get decisions on background

plt.hist(background_decisions, color='red', label='ggF processes', 
         histtype='step', # lineplot that's unfilled
         density=True ) # normalize to form a probability density
plt.hist(signal_decisions, color='blue', label='VBF processes', 
         histtype='step', # lineplot that's unfilled
         density=True, # normalize to form a probability density
         linestyle='--' ) # dashed line
plt.xlabel('BDT output') # add x-axis label
plt.ylabel('Arbitrary units') # add y-axis label
plt.legend() # add legend
#plt.show()
plt.savefig("BDT_plots/distributions_BDT_score.pdf")

# we then plot the ROC
plt.figure() # make new figure 

decisions = bdt.decision_function(X_test).ravel() # get probabilities on test set

# Compute ROC curve and area under the curve
fpr, tpr, _ = roc_curve(y_test, # actual
                        decisions ) # predicted

# Compute area under the curve for training set
roc_auc = auc(fpr, # false positive rate 
              tpr) # true positive rate

plt.plot(fpr, tpr, label='ROC (area = %0.2f)'%(roc_auc)) # plot test ROC curve
plt.plot([0, 1], # x from 0 to 1
         [0, 1], # y from 0 to 1
         '--', # dashed line
         color='grey', label='Luck')

plt.xlabel('False Positive Rate') # x-axis label
plt.ylabel('True Positive Rate') # y-axis label
plt.title('Receiver operating characteristic (ROC) curve') # title
plt.legend() # add legend
plt.grid() # add grid
#plt.show()
plt.savefig("BDT_plots/ROC_Curve.pdf")

### BDT Overtraining check

def compare_train_test(clf, X_train, y_train, X_test, y_test):
    decisions = [] # list to hold decisions of classifier
    for X,y in ((X_train, y_train), (X_test, y_test)): # train and test
        #d1 = clf.decision_function(X[y<0.5]).ravel() # background
        #d2 = clf.decision_function(X[y>0.5]).ravel() # signal
        d1 = clf.predict_proba(X[y<0.5])[:, 1] # background
        d2 = clf.predict_proba(X[y>0.5])[:, 1] # signal
        decisions += [d1, d2] # add to list of classifier decision
    
    highest_decision = max(np.max(d) for d in decisions) # get maximum score
    bin_edges = [] # list to hold bin edges
    bin_edge = -0.1 # start counter for bin_edges
    while bin_edge < highest_decision: # up to highest score
    #while bin_edge < 1.0: # up to highest score
        bin_edge += 0.1 # increment
        bin_edges.append(bin_edge)

    plt.figure() # make new figure 
    plt.hist(decisions[0], # background in train set
             bins=bin_edges, # lower and upper range of the bins
             density=True, # area under the histogram will sum to 1
             histtype='stepfilled', # lineplot that's filled
             color='red', label='ggF (train)', # Background (train)
             alpha=0.5 ) # half transparency
    plt.hist(decisions[1], # background in train set
             bins=bin_edges, # lower and upper range of the bins
             density=True, # area under the histogram will sum to 1
             histtype='stepfilled', # lineplot that's filled
             color='blue', label='VBF (train)', # Signal (train)
             alpha=0.5 ) # half transparency

    hist_background, bin_edges = np.histogram(decisions[2], # background test
                                              bins=bin_edges, # number of bins in function definition
                                              density=True ) # area under the histogram will sum to 1
    
    scale = len(decisions[2]) / sum(hist_background) # between raw and normalised
    err_background = np.sqrt(hist_background * scale) / scale # error on test background

    width = 0.1 # histogram bin width
    center = (bin_edges[:-1] + bin_edges[1:]) / 2 # bin centres
    
    plt.errorbar(x=center, y=hist_background, yerr=err_background, fmt='o', # circles
                 c='red', label='ggF (test)' ) # Background (test)
    
    hist_signal, bin_edges = np.histogram(decisions[3], # siganl test
                                          bins=bin_edges, # number of bins in function definition
                                          density=True ) # area under the histogram will sum to 1
    scale = len(decisions[3]) / sum(hist_signal) # between raw and normalised
    err_signal = np.sqrt(hist_signal * scale) / scale # error on test background
    
    plt.errorbar(x=center, y=hist_signal, yerr=err_signal, fmt='o', # circles
                 c='blue', label='VBF (test)' ) # Signal (test)
    
    plt.xlabel("BDT output") # write x-axis label
    plt.ylabel("Arbitrary units") # write y-axis label
    plt.legend() # add legend
    #plt.show()
    plt.savefig("BDT_plots/overtraining_check.pdf")
    
compare_train_test(bdt, X_train, y_train, X_test, y_test) # call compare_train_test

# Apply BDT to all the events
df["bdt_score"] = bdt.predict_proba(X)[:, 1]

with uproot.recreate("output_analysis/BDT_output.root") as fout:
    fout["AnalysisMiniTree"] = {**{col: ak.Array(df[col].to_numpy()) for col in X.columns},
                                "bdt_score": ak.Array(df["bdt_score"].to_numpy()),
                                "process_type_like": ak.Array(df["process_type_like"].to_numpy())}
