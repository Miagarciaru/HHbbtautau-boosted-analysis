#include "TMVA/RBDT.hxx"
#include "TMVA/RTensor.hxx"
#include <vector>
#include <iostream>

using namespace TMVA::Experimental;

void test_TMVA(){

    // Load model
    // auto model = RBDT::LoadFromFile("ML_models/tmva101_bb_jets.root");
    TMVA::Experimental::RBDT model("myBDT_bb_jets", "ML_models/tmva101_bb_jets.root");

//     "recojet_antikt10UFO_NOSYS_pt", "recojet_antikt10UFO_m", "recojet_antikt10UFO_Tau1_wta",
// "recojet_antikt10UFO_Tau2_wta", "recojet_antikt10UFO_ECF1", "recojet_antikt10UFO_ECF2", "recojet_antikt10UFO_ECF3",
// "recojet_antikt10UFO_Split12", "recojet_antikt10UFO_Split23", "recojet_antikt10UFO_GN2Xv01_phbb"

    std::vector<float> input = {251620.0, 120232.0, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.85 };  // tus 10 variables
    // Shape del tensor: [1, 10]
    // std::vector<size_t> shape = {1, 10};

    // Crear el RTensor
    // RTensor<float> input_tensor(shape, input);
    
    // std::cout << "Model expects " << model.GetNInputs() << " inputs." << std::endl;

    // RTensor<float> score = model.Compute(input_tensor);
    std::vector<float> score = model.Compute(input);

    for(int ii=0; ii<score.size(); ii++){
       std::cout << "size: " << score.size() << std::endl;  
       std::cout << "BDT score: " << score[ii] << std::endl; 
    }
    // std::cout << "BDT score: " << score << std::endl;
}
