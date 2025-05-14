import uproot
import pandas as pd
import awkward as ak
import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.metrics import roc_auc_score
from sklearn.metrics import roc_curve, auc

# Reading ROOT file
file = uproot.open("output_analysis/input_BDT.root")
tree = file["AnalysisMiniTree"]
df = tree.arrays(library="pd")

# Training
#X = df[["two_jets_j12_m", "two_jets_j12_pt", "two_jets_j12_dR", "idx_jet1_VBF_topology", "idx_jet2_VBF_topology", "is_jet12_matched"]]  # variables to use in the training part
X = df[["two_jets_j12_m", "two_jets_j12_pt", "two_jets_j12_dR"]]  # variables to use in the training part
y = df["process_type_like"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

bdt = GradientBoostingClassifier(n_estimators=100, max_depth=3)
bdt.fit(X_train, y_train)

# Evaluation
y_pred = bdt.predict_proba(X_test)[:, 1]

print("AUC:", roc_auc_score(y_test, y_pred))

# Apply BDT to all the events
df["bdt_score"] = bdt.predict_proba(X)[:, 1]

with uproot.recreate("output_analysis/BDT_output.root") as fout:
    fout["AnalysisMiniTree"] = {**{col: ak.Array(df[col].to_numpy()) for col in X.columns},
                    "bdt_score": ak.Array(df["bdt_score"].to_numpy()),
                    "process_type_like": ak.Array(df["process_type_like"].to_numpy())}


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
plt.xticks(range(len(features)), features[indices], rotation=45)
plt.tight_layout()
plt.savefig("output_analysis/importance_ranking_BDT.png")
#plt.show()

# Calcular los puntos de la curva ROC
fpr, tpr, thresholds = roc_curve(y_test, y_pred)
roc_auc = auc(fpr, tpr)

# Dibujar la curva ROC
plt.figure(figsize=(6, 6))
plt.plot(fpr, tpr, color='darkorange', lw=2, label=f'ROC (AUC = {roc_auc:.3f})')
plt.plot([0, 1], [0, 1], color='navy', lw=1, linestyle='--')  # línea diagonal (azar)
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('False Positive Ratio (FPR)')
plt.ylabel('True Positive Ratio (TPR)')
plt.title('ROC Curve - VBF vs ggF Classification')
plt.legend(loc="lower right")
plt.grid(True)
plt.tight_layout()
plt.savefig("output_analysis/ROC_curve_BDT.png")
