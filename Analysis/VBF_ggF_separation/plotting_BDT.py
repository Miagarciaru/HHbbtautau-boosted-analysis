import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn.metrics import auc, roc_curve

def correlation_plots(df):
    correlation_matrix = df.corr()
    plt.figure(figsize=(20, 16)) # make new figure
    sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt=".2f", cbar_kws={"shrink": 0.8})
    plt.title("Variables correlation matrix")
    plt.tight_layout() 
    plt.savefig("BDT_plots/correlation_matrix.pdf")
    plt.figure()

def ranking_variables_plot(features, importances, indices):
    plt.figure(figsize=(8, 6))
    plt.title("Importance of each variable")
    plt.bar(range(len(features)), importances[indices], align="center")
    plt.xticks(range(len(features)), features[indices], rotation=90)
    plt.tight_layout()
    plt.savefig("BDT_plots/importance_ranking_BDT.pdf")
    plt.figure()
    #plt.show()

def roc_curve_plots(clf, X, y, X_test, y_test):
    # we first plot the Neural Network output
    # signal_decisions = bdt.decision_function(X[y>0.5]).ravel() # get probabilities on signal
    # background_decisions = bdt.decision_function(X[y<0.5]).ravel() # get decisions on background

    signal_decisions = clf.predict_proba(X[y>0.5])[:, 1] # get probabilities on signal
    background_decisions = clf.predict_proba(X[y<0.5])[:, 1] # get decisions on background

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
    plt.tight_layout()
    plt.savefig("BDT_plots/distributions_BDT_score.pdf")

    # we then plot the ROC
    plt.figure() # make new figure 

    decisions = clf.decision_function(X_test).ravel() # get probabilities on test set

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
    plt.tight_layout()
    plt.legend() # add legend
    plt.grid() # add grid
    #plt.show()
    plt.savefig("BDT_plots/ROC_Curve.pdf")
    plt.figure() # make new figure 

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
    plt.tight_layout()
    plt.xlabel("BDT output") # write x-axis label
    plt.ylabel("Arbitrary units") # write y-axis label
    plt.legend() # add legend
    #plt.show()
    plt.savefig("BDT_plots/overtraining_check.pdf")

### Plotting distributions per sample
def distribution_plots(samples_dict, samples_list):
    
    highest_decision = 0.95 # get maximum score
    bin_edges = [] # list to hold bin edges
    bin_edge = 0.3 # start counter for bin_edges
    while bin_edge < highest_decision: # up to highest score
    #while bin_edge < 1.0: # up to highest score
        bin_edge += 0.05 # increment
        bin_edges.append(bin_edge)

    plt.figure() # make new figure 

    for sample_name in samples_list:
        plt.hist(samples_dict[sample_name]["variable"], # background in train set
                bins=bin_edges, # lower and upper range of the bins
                density=True, # area under the histogram will sum to 1
                histtype='step', # lineplot that's filled
                color=samples_dict[sample_name]["color"], label=sample_name, # Background (train)
                alpha=1.0 ) # half transparency

    plt.xlabel("BDT output") # write x-axis label
    plt.ylabel("Arbitrary units") # write y-axis label
    plt.legend(loc = "upper left") # add legend
    plt.tight_layout()
    #plt.show()
    name_figure = "BDT_plots/comparison_samples_bdt_score.pdf"
    plt.savefig(name_figure)