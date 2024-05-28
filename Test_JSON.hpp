#ifndef TEST_JSON_HPP
#define TEST_JSON_HPP

#include "TString.h"
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
#include <TSystem.h>

#include <string>
#include <fstream> 
#include <sstream>
#include <iostream>

/// @brief 
/// @param macroName 
/// @param prop 
void Test_JSON(const std::string& macroName, const std::string& flags);
bool compare_json(const TString& created_json, const std::string& ref_filename);

bool compareSVGFiles(const std::string& filePath1, const std::string& filePath2);
std::string readFileToString(const std::string& filePath);

#endif /* TEST_JSON_HPP */