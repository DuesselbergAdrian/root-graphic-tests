#include "Test_JSON.hpp"

#include "TROOT.h"
#include "TCanvas.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TArrow.h"
#include "TLine.h"
#include "TWebCanvas.h"
#include "TString.h"
#include "TApplication.h"
#include "TString.h"

#include <string>
#include <fstream> 
#include <sstream>
#include <iostream>

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

bool TestMacros(){
    // Initialize ROOT application
    TApplication app("app", 0, nullptr);

    // 1. Call the macro
    gROOT->ProcessLine(".x /home/adrianduesselberg/root-graphic-tests/graphics/analyze.C");

    // 2. Compare it to the reference file
    TString created_json_path = "./json_pro/analyze_pro.json";
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
    std::string ref_filename = "./json_ref/analyze.json";

    // Compare the created JSON to the reference JSON
    bool result = compare_json(created_json, ref_filename);

    return result;
}