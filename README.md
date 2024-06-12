# Boosted $HH \rightarrow bb \tau \tau$ Analysis

This analysis is aimed to study of the overlap region between the resolved selection done by the [easyjet framework](https://gitlab.cern.ch/easyjet/easyjet) for the process boosted $bb \tau \tau$ and the analysis implemented in this repository where a classification of the events is done through 4 vmain classes ($R_{bb}-R_{\tau \tau}$, $R_{bb}-B_{\tau \tau}$, $B_{bb}-R_{\tau \tau}$ and $B_{bb}-B_{\tau \tau}$).

## Objective

The goal is to find a good definition of boosted bb and tautau jet based on substructure variables and define a baseline to understand the number of (semi)boosted events and the overlap with the resolved selections.

# Installation

First, create a wordk directory where you would like to copy the code. Go into that directory and make:
```
setupATLAS
lsetup git
# Copy-paste this repo's URL, choosing your preferred authentication scheme, e.g. for lxplus or institute cluster
git clone https://github.com/Miagarciaru/HHbbtautau-boosted-analysis.git
```
# Running the analysis

To run the analysis, you need to run the following command:

```
python3 script_analysis.py
```

# Description of the analysis
