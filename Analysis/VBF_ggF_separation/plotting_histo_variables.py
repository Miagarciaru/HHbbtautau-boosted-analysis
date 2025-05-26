import uproot
import numpy as np
import matplotlib.pyplot as plt
from collections import defaultdict

# Función para leer histogramas de un archivo ROOT
def leer_histogramas(archivo_root, lista_variables):
    file = uproot.open(archivo_root)
    histogramas = {}
    
    for variable in lista_variables:
        nombre_histograma = f"hist_boosted_{variable}"
        if nombre_histograma in file:
            objeto = file[nombre_histograma]

            #if isinstance(objeto, uproot.models.TH1.Model_TH1F):
            histogramas[variable] = objeto
            """
            else:
                print(f"Advertencia: '{nombre_histograma}' no es un TH1F.")
            else:
            print(f"Histograma '{nombre_histograma}' no encontrado en {archivo_root}.")
            """
    return histogramas

# Función para construir el mapa combinado a partir de dos diccionarios de histogramas
def construir_mapa(hist1, hist2):
    mapa = defaultdict(lambda: [None, None])
    
    # Insertamos los histogramas del primer archivo
    for nombre, hist in hist1.items():
        mapa[nombre][0] = hist
    
    # Insertamos los del segundo archivo
    for nombre, hist in hist2.items():
        mapa[nombre][1] = hist

    return mapa

# Función para graficar los histogramas de una misma variable
def graficar_comparacion(nombre_variable, hist_1, hist_2, etiquetas=["VBF Processes", "ggF Processes"]):
    # Convertimos a formato usable por matplotlib
    bin_edges_1 = hist_1.axis().edges()
    valores_1 = hist_1.values()
    integral_1 = np.sum(valores_1)
    valores_1 = valores_1 / integral_1 if integral_1 > 0 else valores_1

    bin_edges_2 = hist_2.axis().edges()
    valores_2 = hist_2.values()
    integral_2 = np.sum(valores_2)
    valores_2 = valores_2 / integral_2 if integral_2 > 0 else valores_2

    plt.figure(figsize=(8, 5))
    
    plt.step(bin_edges_1[:-1], valores_1, where="post", label=etiquetas[0], color='blue')
    plt.step(bin_edges_2[:-1], valores_2, where="post", label=etiquetas[1], color='red')
    
    plt.title(f"Comparación normalizada: {nombre_variable}")
    plt.xlabel(nombre_variable)
    plt.ylabel("$m_{HH}$ Densidad normalizada")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    name_plot = "plots_comparison/"+nombre_variable+".pdf"
    #plt.show()0
    plt.savefig(name_plot)

# === Main (ejemplo de uso) ===
if __name__ == "__main__":
    sample_VBF = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/comparison_boo\
sted_resolved_easyjet/output_analysis/VBF_SM_hh_502982.root"
    sample_ggF = "/eos/user/g/garciarm/HHbbtautau-easyjet-framework-analysis/boosted-analysis/Analysis/comparison_boo\
sted_resolved_easyjet/output_analysis/ggF_SM_hh_600459.root"
    
    variables_a_graficar = ["jet12_m", "jet12_pt", "jet12_deta", "jet12_phi", "jet12_dR", "bbtautau_m", "bbtautau_pt", "bbtautau_eta", "bbtautau_phi", "bbtautau_deta" , "bbtautau_dphi", "bbtautau_dR", "bb_jet1_m", "bb_jet1_pt", "bb_jet1_eta", "bb_jet1_phi", "bb_jet1_deta", "bb_jet1_dphi", "bb_jet1_dR", "bb_jet2_m", "bb_jet2_pt", "bb_jet2_eta", "bb_jet2_phi", "bb_jet2_deta", "bb_jet2_dphi", "bb_jet2_dR", "tautau_jet1_m", "tautau_jet1_pt", "tautau_jet1_eta", "tautau_jet1_phi", "tautau_jet1_deta", "tautau_jet1_dphi", "tautau_jet1_dR", "tautau_jet2_m", "tautau_jet2_pt", "tautau_jet2_eta", "tautau_jet2_phi", "tautau_jet2_deta", "tautau_jet2_dphi", "tautau_jet2_dR", "all_jets_m", "all_jets_pt", "all_jets_eta", "all_jets_phi", "all_jets_deta", "all_jets_dphi", "all_jets_dR", "jet12_Zeppenfeld_Hbb", "jet12_Zeppenfeld_Htautau", "jet12_Zeppenfeld_jet12"]  # puedes modificar esta lista
    
    histos_VBF = leer_histogramas(sample_VBF, variables_a_graficar)
    histos_ggF = leer_histogramas(sample_ggF, variables_a_graficar)
    
    mapa_histogramas = construir_mapa(histos_VBF, histos_ggF)

    for variable, (h1, h2) in mapa_histogramas.items():
        if h1 is not None and h2 is not None:
            graficar_comparacion(variable, h1, h2)
