#ifndef Test_Root_HPP
#define Test_Root_HPP

#include "TString.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TArrow.h"
#include "TLine.h"
#include "TString.h"
#include "TApplication.h"
#include "TString.h"
#include "TWebCanvas.h"
#include "TLatex.h"
#include <TSystem.h>

#include <string>
#include <fstream> 
#include <sstream>
#include <iostream>

/// @brief 
/// @param macroName 
/// @param prop
// ROOT
void Test_Root(const std::string& macroName, const std::string& test_type, const std::string& macro_folder, const std::string& builddir);
std::string readFileToString(const std::string& filePath);
// JSON
void test_json(TCanvas* c1, const std::string& macroName, const std::string& builddir);
bool compare_json(const TString& created_json, const std::string& ref_filename, const std::string& macroName);
std::string preprocessJSONContent(const std::string& jsonString);
// old SVG
void test_svg(TCanvas* c1, const std::string& macroName, const std::string& builddir);
bool compareSVGFiles(const std::string& filePath1, const std::string& filePath2);
std::string preprocessSVGContent(const std::string& svgContent);
// old PDF
void test_pdf(TCanvas* c1, const std::string& macroName, const std::string& builddir);
bool comparePDFFiles(const std::string& filePath1, const std::string& filePath2);
std::string preprocessPDFContent(const std::string& pdfContent);


#endif /* Test_Root_HPP */