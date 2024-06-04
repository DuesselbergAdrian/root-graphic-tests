//IMPORTS
#include "Test_Root.hpp"

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
#include "TLatex.h"
#include <TSystem.h>

#include <string>
#include <fstream> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <regex>
#include <filesystem>

//FUNCTIONS

//---------------------JSON----------------------------------------------------------------
bool compare_json(const TString& jsonOutput, const std::string& ref_filename, const std::string& macroName){
   
   // Read the reference JSON content from file
    std::ifstream refFile(ref_filename);
    if (!refFile.is_open()) {
        std::string jsonFilePath = "./json_ref/" + macroName + ".json";
        std::cerr << "Failed to open reference JSON file and created new reference JSON: " << ref_filename << std::endl;
        std::ofstream jsonFile(jsonFilePath);
        if (jsonFile.is_open()) {
            jsonFile << jsonOutput.Data();
            jsonFile.close();
        } else {
            std::cerr << "Error: Unable to open file for writing" << std::endl;
            return false;
        }
        return false;
    }
    std::stringstream refBuffer;
    refBuffer << refFile.rdbuf();
    refFile.close();

    // Compare the created JSON to the reference JSON
    std::cerr << "Length of produced JSON: " << jsonOutput.Length() << std::endl;
    std::cerr << "Length of reference JSON: " << refBuffer.str().length() << std::endl;
    return jsonOutput.Data() == refBuffer.str();
}
void test_json(TCanvas* c1, const std::string& macroName){

    TString jsonOutput = TWebCanvas::CreateCanvasJSON(c1, 1, kFALSE);

    // Path to the reference JSON file
    std::string ref_filename = "./json_ref/" + macroName + ".json";

    // Compare the created JSON to the reference JSON
    if (compare_json(jsonOutput, ref_filename, macroName)) {
        std::cout << "JSON test passed for " << macroName << std::endl;
    } else {
        std::cerr << "JSON test failed for " << macroName << std::endl;
        exit(EXIT_FAILURE);
    }
}

//---------------------SVG-----------------------------------------------------------------
// Function to read file content into a string
std::string readFileToString(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


// Function to remove or normalize specific parts of the SVG content
std::string preprocessSVGContent(const std::string& svgContent) {
    std::string result = svgContent;

    // Remove <title>...</title> sections
    std::regex titleRegex(R"(<title>(.|\n)*?<\/title>)");
    result = std::regex_replace(result, titleRegex, "");

    // Remove <desc>...</desc> sections
    std::regex descRegex(R"(<desc>(.|\n)*?<\/desc>)");
    result = std::regex_replace(result, descRegex, "");

    return result;
}

// Function to compare two SVG files (old graphics)
bool compareSVGFiles(const std::string& filePath1, const std::string& filePath2) {
    try {
        std::string content1 = readFileToString(filePath1);
        std::string content2 = readFileToString(filePath2);

        content1 = preprocessSVGContent(content1);
        content2 = preprocessSVGContent(content2);

        return content1 == content2;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

void test_svg(TCanvas* c1, const std::string& macroName){
    std::string file1 = "./old_svg_ref/" + macroName + ".svg";
    std::string file2 = "./old_svg_pro/" + macroName + "_pro.svg";
    if(!std::filesystem::exists(file1)){
        std::cout << "Save generated file" << macroName << "as reference" << std::endl;
        c1->SaveAs(("./old_svg_ref/" + macroName + ".svg").c_str());
        exit(EXIT_FAILURE);
    } else {
        c1->SaveAs(("./old_svg_pro/" + macroName + "_pro.svg").c_str());
    }
    if (compareSVGFiles(file1, file2)) {
        std::cout << "SVG test passed for "<< macroName << std::endl;
    } else {
        std::cout << "SVG test failed for "<< macroName << std::endl;
        exit(EXIT_FAILURE);
    }
}


// TEST ROOT MACRO -------------------------------------------------------------------------------
void Test_Root(const std::string& macroName, const std::string& test_type, const std::string& macro_folder){
    // Set paths
    std::string macroPath = macro_folder + "/" + macroName + ".C";
    gROOT->SetMacroPath("./macros");

    // Call the macro to generate the canvas
    std::string command = ".x " + macroPath;
    gROOT->ProcessLine(command.c_str());

    // Retrieve the current canvas from gPad
    TCanvas* c1 = dynamic_cast<TCanvas*>(gPad->GetCanvas());
    if (!c1) {
        std::cerr << "Error: No canvas found in gPad" << std::endl;
        return;
    }

    // Different tests for root graphics
    // a == invokes both tests
    // j === test the JSON creation
    // o === test the SVG creation in ROOT (old graphics with --web=off)

    if(test_type == "j"){
        test_json(c1,macroName);
    }
    if(test_type == "o"){
        test_svg(c1,macroName);
    }
    return;
}


int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <macro_name> <test_type> <macro_folder>" << std::endl;
        return 1;
    }

    std::string macroName = argv[1];
    std::string test_type = argv[2];
    std::string macro_folder = argv[3];
    Test_Root(macroName,test_type, macro_folder);
    return EXIT_SUCCESS;
}