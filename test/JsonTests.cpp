#include "../Test_JSON.hpp"

#include <gtest/gtest.h>

//Get all the different macros at test them

TEST(TestGraphicJSON, AnalyzeFunction){
    std::string macroPath = "analyze";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, ArchiFunction){
    std::string macroPath = "archi";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, ArrowsFunction){
    std::string macroPath = "arrows";
    EXPECT_TRUE(TestMacros(macroPath));

}