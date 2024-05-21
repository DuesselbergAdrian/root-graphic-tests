//IMPORTS
#include "Test_JSON.hpp"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TArrow.h"
#include "TLine.h"
#include "TString.h"
#include "TApplication.h"
#include "TWebCanvas.h"
#include "TString.h"
#include <TSystem.h>

#include <string>
#include <fstream> 
#include <sstream>
#include <iostream>
#include <algorithm>

//FUNCTIONS

//Simple function to compare a created json  to a reference json
bool compare_json(const TString& created_json, const std::string& ref_filename){
   // Read the reference JSON content from file
    std::ifstream refFile(ref_filename);
    if (!refFile.is_open()) {
        std::cerr << "Failed to open reference JSON file: " << ref_filename << std::endl;
        return false;
    }
    std::stringstream refBuffer;
    refBuffer << refFile.rdbuf();
    refFile.close();

    // Compare the created JSON to the reference JSON
    return created_json.Data() == refBuffer.str();
}

bool TestMacros(const std::string& path){
    // Set paths
    std::string macroPath = "/home/adrianduesselberg/root-graphic-tests/macros/" + path + ".C";
    std::string jsonFilePath = "./json_pro/" + path + "_pro.json";

    gROOT->Reset();
    //Set batch mode.
    gROOT->SetBatch(kTRUE);

    // Initialize the ROOT application (necessary for ROOT to run macros correctly)
    //int argc = 0;
    //char* argv[] = {nullptr};
    //TApplication app("ROOT Application", &argc, argv);

    // 1. Call the macro to generate the canvas
    std::string command = ".x " + macroPath;
    gROOT->ProcessLine(command.c_str());

    // Retrieve the current canvas from gPad
    TCanvas* c1 = dynamic_cast<TCanvas*>(gPad->GetCanvas());
    if (!c1) {
        std::cerr << "Error: No canvas found in gPad" << std::endl;
        return false;
    }

    // Create JSON from the canvas
    TString jsonOutput = TWebCanvas::CreateCanvasJSON(c1, 1, kFALSE);

    // Save JSON to a file
    std::ofstream jsonFile(jsonFilePath);
    if (jsonFile.is_open()) {
        jsonFile << jsonOutput.Data();
        jsonFile.close();
    } else {
        std::cerr << "Error: Unable to open file for writing" << std::endl;
        return false;
    }

    // 2. Compare it to the reference file
    TString created_json_path = TString::Format("./json_pro/%s_pro.json", path.c_str());

    // Read the generated JSON content from file
    std::ifstream createdFile(created_json_path.Data());
    if (!createdFile.is_open()) {
        std::cerr << "Failed to open generated JSON file: " << created_json_path << std::endl;
        return false;
    }
    std::stringstream createdBuffer;
    createdBuffer << createdFile.rdbuf();
    createdFile.close();

    TString created_json = createdBuffer.str().c_str();

    // Path to the reference JSON file
    std::string ref_filename = "./json_ref/" + path + ".json";

    // Compare the created JSON to the reference JSON
    bool result = compare_json(created_json, ref_filename);

    // Close the ROOT application
    //app.Terminate(0);
    std::string command2 = ".q ";
    gROOT->ProcessLine(command2.c_str());
    return result;
}