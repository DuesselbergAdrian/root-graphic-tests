#include "../Test_JSON.hpp"

#include <gtest/gtest.h>

//Test all macros from tutorials/graphics
//Except: AtlasExample (random), canvas (crash), canvas2, diamond (no canvas), earth (not void), 

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

TEST(TestGraphicJSON, Basic3dFunction){
    std::string macroPath = "basic3d";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, CompileFunction){
    std::string macroPath = "compile";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, CrownFunction){
    std::string macroPath = "crown";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, EllipseFunction){
    std::string macroPath = "ellipse";
    EXPECT_TRUE(TestMacros(macroPath));

}
