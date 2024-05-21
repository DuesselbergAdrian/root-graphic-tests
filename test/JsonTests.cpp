#include "../Test_JSON.hpp"
#include <gtest/gtest.h>

/*List of macros to test
const std::vector<std::string> macros = {
    "analyze",
    "archi",
    "arrows",
    "compile",
    "crown"
    // Add more macros here as needed
    // "macro_name",
};

// Generate a test case for each macro
class TestJSON : public ::testing::TestWithParam<std::string> {};

TEST_P(TestJSON, RunMacro) {
    std::string macroPath = GetParam();
    std::cout << "Running macro: " << macroPath << std::endl;  // Debug print
    EXPECT_TRUE(TestMacros(macroPath)) << "Macro failed: " << macroPath;;
}

// Instantiate the test case with the list of macros
INSTANTIATE_TEST_SUITE_P(MacroTests, TestJSON, ::testing::ValuesIn(macros));*/


//Test all macros from tutorials/graphics
//Except: AtlasExample (random), canvas (crash), canvas2, diamond (no canvas), earth (not void), gaxis2 (no canvas),
// graph_edit_playback (no macro), inside (random, no canvas), madelbrot (maybe include), palettes (maybe possible),
// perceptualcolormap (no canvas), polytest1 (maybe possible), polytest2 (maybe possible), pstable (more than one canvas),
// psview, saveall, schroedinger_hydrogen (more than one canvas), 

TEST(TestGraphicJSON, analyzeFunction) {
    EXPECT_TRUE(TestMacros("analyze"));
}

TEST(TestGraphicJSON, archiFunction) {
    EXPECT_TRUE(TestMacros("archi"));
}

TEST(TestGraphicJSON, arrowsFunction) {
    EXPECT_TRUE(TestMacros("arrows"));
}

TEST(TestGraphicJSON, compileFunction) {
    EXPECT_TRUE(TestMacros("compile"));
}

TEST(TestGraphicJSON, crownFunction) {
    EXPECT_TRUE(TestMacros("crown"));
}
/*
//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

TEST(TestGraphicJSON, EllipseFunction){
    std::string macroPath = "ellipse";
    EXPECT_TRUE(TestMacros(macroPath));
}

TEST(TestGraphicJSON, Basic3dFunction){
    std::string macroPath = "basic3d";
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

TEST(TestGraphicJSON, GtimeFunction){
    std::string macroPath = "gtime";
    EXPECT_TRUE(TestMacros(macroPath));

} Not useable: Infinite loop 

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

TEST(TestGraphicJSON, PavetextFunction){
    std::string macroPath = "pavetext";
    EXPECT_TRUE(TestMacros(macroPath));
}

TEST(TestGraphicJSON, PiechartFunction){
    std::string macroPath = "piechart";
    EXPECT_TRUE(TestMacros(macroPath));
}

TEST(TestGraphicJSON, QuarksFunction){
    std::string macroPath = "quarks";
    EXPECT_TRUE(TestMacros(macroPath));
}

TEST(TestGraphicJSON, TmathtextFunction){
    std::string macroPath = "tmathtext";
    EXPECT_TRUE(TestMacros(macroPath));
}

TEST(TestGraphicJSON, Tmathtext2Function){
    std::string macroPath = "tmathtext2";
    EXPECT_TRUE(TestMacros(macroPath));
}*/