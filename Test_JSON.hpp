#ifndef TEST_JSON_HPP
#define TEST_JSON_HPP

#include "TString.h"
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
#include <TSystem.h>

#include <string>
#include <fstream> 
#include <sstream>
#include <iostream>

bool TestMacros(const std::string& path);
bool TestMacrosG(const std::string& path); //only for testing reasons
bool compare_json(const TString& created_json, const std::string& ref_filename);

#endif /* TEST_JSON_HPP */