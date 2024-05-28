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
#include <cstdlib>

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
    std::cerr << "Length of produced JSON: " << created_json.Length() << std::endl;
    std::cerr << "Length of reference JSON: " << refBuffer.str().length() << std::endl;
    return created_json.Data() == refBuffer.str();
}

void Test_JSON(const std::string& macroName, const std::string& flags){
    // Set paths
    std::string macroPath = macroName + ".C";
    std::string jsonFilePath = "./json_pro/" + macroName + "_pro.json";
    gROOT->SetMacroPath("./macros");

    // 1. Call the macro to generate the canvas
    std::string command = ".x " + macroPath;
    gROOT->ProcessLine(command.c_str());

    // 2. Retrieve the current canvas from gPad
    TCanvas* c1 = dynamic_cast<TCanvas*>(gPad->GetCanvas());
    if (!c1) {
        std::cerr << "Error: No canvas found in gPad" << std::endl;
        return;
    }

    if(flags == "j"){
        // 3. Create JSON from the canvas
        TString jsonOutput = TWebCanvas::CreateCanvasJSON(c1, 1, kFALSE);

        // 4. Save JSON to a file
        std::ofstream jsonFile(jsonFilePath);
        if (jsonFile.is_open()) {
            jsonFile << jsonOutput.Data();
            jsonFile.close();
        } else {
            std::cerr << "Error: Unable to open file for writing" << std::endl;
            return;
        }

        // 5. Compare it to the reference file
        TString created_json_path = TString::Format("./json_pro/%s_pro.json", macroName.c_str());

        // 6. Read the generated JSON content from file
        std::ifstream createdFile(created_json_path.Data());
        if (!createdFile.is_open()) {
            std::cerr << "Failed to open generated JSON file: " << created_json_path << std::endl;
            return;
        }
        std::stringstream createdBuffer;
        createdBuffer << createdFile.rdbuf();
        createdFile.close();

        TString created_json = createdBuffer.str().c_str();

        // Path to the reference JSON file
        std::string ref_filename = "./json_ref/" + macroName + ".json";

        // Compare the created JSON to the reference JSON
        bool result = compare_json(created_json, ref_filename);
        if (result) {
            std::cout << "Test passed for " << macroName << std::endl;
        } else {
            std::cerr << "Test failed for " << macroName << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if(flags== "s"){
        std::cerr << "Test failed for " << macroName << std::endl;
        // how can I skip a test?
        exit(EXIT_FAILURE);
    }   
    return;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <macro_name> <flags>" << std::endl;
        return 1;
    }

    std::string macroName = argv[1];
    std::string flags = argv[2];
    Test_JSON(macroName,flags);
    return EXIT_SUCCESS;
}