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
#include "TLatex.h"
#include <TSystem.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <stdexcept>
#include <filesystem>

// FUNCTION DECLARATIONS

// JSON Preprocessing
std::string preprocessJSONContent(const std::string& jsonString);

// JSON Comparison
bool compare_json(const TString& jsonOutput, const std::string& ref_filename, const std::string& macroName);

// JSON Test
void test_json(TCanvas* c1, const std::string& macroName);

// File Content Reading
std::string readFileToString(const std::string& filePath);

// SVG Preprocessing
std::string preprocessSVGContent(const std::string& svgContent);

// SVG Comparison
bool compareSVGFiles(const std::string& filePath1, const std::string& filePath2);

// SVG Test
void test_svg(TCanvas* c1, const std::string& macroName);

// PDF Preprocessing
std::string preprocessPDFContent(const std::string& pdfString);

// PDF Comparison
bool comparePDFFiles(const std::string& filePath1, const std::string& filePath2);

// PDF Test
void test_pdf(TCanvas* c1, const std::string& macroName);

// Root Test
void Test_Root(const std::string& macroName, const std::string& test_type, const std::string& macro_folder);

// MAIN FUNCTION
int main(int argc, char** argv);

// FUNCTION DEFINITIONS
//---------------------HELPER--------------------------------------------------------------
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

//---------------------JSON----------------------------------------------------------------
std::string preprocessJSONContent(const std::string& jsonString) {
    std::string result = jsonString;
    // Remove fTsumwx key
    std::regex fTsumwxRegex(R"("fTsumwx" : \d+\.\d+,)");
    result = std::regex_replace(result, fTsumwxRegex, "");

    // Remove fTsumwx2 key
    std::regex fTsumwx2Regex(R"("fTsumwx2" : \d+\.\d+,)");
    result = std::regex_replace(result, fTsumwx2Regex, "");
    return result;
}

bool compare_json(const TString& jsonOutput, const std::string& ref_filename, const std::string& macroName) {
    // Read the reference JSON content from file
    std::ifstream refFile(ref_filename);
    if (!refFile.is_open()) {
        std::string jsonFilePath = "./json_ref/" + macroName + ".json";
        std::cerr << "Failed to open reference JSON file: " << ref_filename << "\nCreating new reference JSON: " << jsonFilePath << std::endl;

        std::ofstream jsonFile(jsonFilePath);
        if (!jsonFile.is_open()) {
            std::cerr << "Error: Unable to open file for writing: " << jsonFilePath << std::endl;
            return false;
        }
        jsonFile << jsonOutput.Data();
        return false;
    }

    std::stringstream refBuffer;
    refBuffer << refFile.rdbuf();

    // Remove specific lines from both JSON strings
    std::string produced_json = preprocessJSONContent(jsonOutput.Data());
    std::string reference_json = preprocessJSONContent(refBuffer.str());

    // Compare the created JSON to the reference JSON
    std::cerr << "Length of produced JSON: " << jsonOutput.Length() << std::endl;
    std::cerr << "Length of reference JSON: " << refBuffer.str().length() << std::endl;

    return produced_json == reference_json;
}

void test_json(TCanvas* c1, const std::string& macroName) {
    // Create JSON output from canvas
    TString jsonOutput = TWebCanvas::CreateCanvasJSON(c1, 1, kFALSE);

    // Path to the reference and produced JSON file
    std::string ref_filename = "./json_ref/" + macroName + ".json";
    std::string jsonFilePath = "./build/json_pro/" + macroName + "_pro.json"; // Not good

    // Save Json file if generated one is different
    std::ofstream jsonFile(jsonFilePath);
    if (jsonFile.is_open()) {
        jsonFile << jsonOutput.Data();
        jsonFile.close();
    } else {
        std::cerr << "Error: Unable to open file for writing" << std::endl;
        return;
    }

    // Compare the created JSON to the reference JSON
    if (compare_json(jsonOutput, ref_filename, macroName)) {
        std::cout << "JSON test passed for " << macroName << std::endl;
    } else {
        std::cerr << "JSON test failed for " << macroName << std::endl;
        exit(EXIT_FAILURE);
    }
}

//---------------------SVG-----------------------------------------------------------------
// Function to remove or normalize specific parts of the SVG content
std::string preprocessSVGContent(const std::string& svgContent) {
    std::string result = svgContent;

    // Remove <title>...</title> sections
    std::regex titleRegex(R"(<title>(.|\n)*?<\/title>)");
    result = std::regex_replace(result, titleRegex, "");

    // Remove <desc>...</desc> sections
    std::regex descRegex(R"(<desc>(.|\n)*?<\/desc>)");
    result = std::regex_replace(result, descRegex, "");

    // Print the lengths of the contents
    std::cout << "Length of result: " << result.length() << std::endl;

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

void test_svg(TCanvas* c1, const std::string& macroName) {
    // Paths to the reference and generated SVG files
    std::string refFilePath = "./old_svg_ref/" + macroName + ".svg";
    std::string genFilePath = "./build/old_svg_pro/" + macroName + "_pro.svg";

    // Check if the reference file exists
    if (!std::filesystem::exists(refFilePath)) {
        std::cout << "Reference file not found. Saving generated file as reference: " << macroName << std::endl;
        c1->SaveAs(refFilePath.c_str());
        exit(EXIT_FAILURE);
    } else {
        // Save the generated SVG file
        c1->SaveAs(genFilePath.c_str());
    }

    // Compare the generated SVG file with the reference SVG file
    if (compareSVGFiles(refFilePath, genFilePath)) {
        std::cout << "SVG test passed for " << macroName << std::endl;
    } else {
        std::cout << "SVG test failed for " << macroName << std::endl;
        exit(EXIT_FAILURE);
    }
}

//---------------------PDF-----------------------------------------------------------------
std::string preprocessPDFContent(const std::string& pdfString) {    
    std::string result = pdfString;
    // Regular expressions to match the metadata patterns
    std::regex creationDatePattern(R"(/CreationDate \(D:\d{14}.*?\))");
    std::regex modDatePattern(R"(/ModDate \(D:\d{14}[-+Z].*?\))");
    std::regex titlePattern(R"(/Title \(.*?\))");

    // Regular expressions to match the cross-reference table and trailer section
    std::regex xrefPattern(R"(xref[\s\S]*?EOF)");

    // Remove the matched patterns from the content
    result = std::regex_replace(result, creationDatePattern, "");
    result = std::regex_replace(result, modDatePattern, "");
    result = std::regex_replace(result, titlePattern, "");
    result = std::regex_replace(result, xrefPattern, "");
    return result;
}

// Function to compare two PDF files (old graphics)
bool comparePDFFiles(const std::string& filePath1, const std::string& filePath2) {
    try {
        std::string content1 = readFileToString(filePath1);
        std::string content2 = readFileToString(filePath2);
        //std::cout << content1 << std::endl;

        content1 = preprocessPDFContent(content1);
        content2 = preprocessPDFContent(content2);

        return content1 == content2;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

void test_pdf(TCanvas* c1, const std::string& macroName) {
    // Paths to the reference and generated SVG files
    std::string refFilePath = "./pdf_ref/" + macroName + ".pdf";
    std::string genFilePath = "./build/pdf_pro/" + macroName + "_pro.pdf";

    // Check if the reference file exists
    if (!std::filesystem::exists(refFilePath)) {
        std::cout << "Reference file not found. Saving generated file as reference: " << macroName << std::endl;
        c1->SaveAs(refFilePath.c_str());
        exit(EXIT_FAILURE);
    } else {
        // Save the generated PDF file
        c1->SaveAs(genFilePath.c_str());
    }

    // Compare the generated PDF file with the reference PDF file
    if (comparePDFFiles(refFilePath, genFilePath)) {
        std::cout << "PDF test passed for " << macroName << std::endl;
    } else {
        std::cout << "PDF test failed for " << macroName << std::endl;
        exit(EXIT_FAILURE);
    }
}

// TEST ROOT MACRO -------------------------------------------------------------------------------
void Test_Root(const std::string& macroName, const std::string& test_type, const std::string& macro_folder) {
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
    // a == invokes all tests
    // j === test the JSON creation
    // o === test the SVG creation in ROOT (old graphics with --web=off)
    // p == test the PDF creation in ROOT (old graphics with --web=off)

    if (test_type == "j") {
        test_json(c1, macroName);
    }
    if (test_type == "o") {
        test_svg(c1, macroName);
    }
    if (test_type == "p") {
        test_pdf(c1, macroName);
    }
    return;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <macro_name> <test_type> <macro_folder>" << std::endl;
        return 1;
    }

    std::string macroName = argv[1];
    std::string test_type = argv[2];
    std::string macro_folder = argv[3];
    Test_Root(macroName, test_type, macro_folder);
    return EXIT_SUCCESS;
}
