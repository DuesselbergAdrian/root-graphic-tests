#include "../Test_JSON.hpp"

#include <gtest/gtest.h>

//Test all macros from tutorials/graphics
//Except: AtlasExample (random), canvas (crash), canvas2, diamond (no canvas), earth (not void), gaxis2 (no canvas)
// graph_edit_playback (no macro), inside (random, no canvas), madelbrot.C (maybe include), 

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

TEST(TestGraphicJSON, EvalFunction){
    std::string macroPath = "eval";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, EventFunction){
    std::string macroPath = "event";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, FeynmanFunction){
    std::string macroPath = "feynman";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, FirstFunction){
    std::string macroPath = "first";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Formula1Function){
    std::string macroPath = "formula1";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, FrameworkFunction){
    std::string macroPath = "framework";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, GaxisFunction){
    std::string macroPath = "gaxis";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Gaxis3Function){
    std::string macroPath = "gaxis3";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, GreyscaleFunction){
    std::string macroPath = "greyscale";
    EXPECT_TRUE(TestMacros(macroPath));

}

/*TEST(TestGraphicJSON, GtimeFunction){
    std::string macroPath = "gtime";
    EXPECT_TRUE(TestMacros(macroPath));

} Not useable: Infinite loop */

TEST(TestGraphicJSON, LatexFunction){
    std::string macroPath = "latex";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Latex2Function){
    std::string macroPath = "latex2";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Latex3Function){
    std::string macroPath = "latex3";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Latex4Function){
    std::string macroPath = "latex4";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Latex5Function){
    std::string macroPath = "latex5";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, MarkerwarningFunction){
    std::string macroPath = "markerwarning";
    EXPECT_TRUE(TestMacros(macroPath));

}

TEST(TestGraphicJSON, Mass_SpectrumFunction){
    std::string macroPath = "mass_spectrum";
    EXPECT_TRUE(TestMacros(macroPath));

}