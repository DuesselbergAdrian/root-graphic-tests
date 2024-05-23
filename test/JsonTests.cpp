#include "../Test_JSON.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <filesystem>


//Test all macros from tutorials/graphics
//Except: AtlasExample (random), canvas (crash), canvas2, diamond (no canvas), earth (not void), gaxis2 (no canvas),
// graph_edit_playback (no macro), inside (random, no canvas), mandelbrot (maybe include), palettes (maybe possible),
// perceptualcolormap (no canvas), polytest1 (maybe possible), polytest2 (maybe possible), pstable (more than one canvas),
// psview, saveall, schroedinger_hydrogen (more than one canvas), 

TEST(TestJSON, analyzeFunction) {
    EXPECT_TRUE(TestMacros("analyze"));
}

TEST(TestJSON, archiFunction) {
    EXPECT_TRUE(TestMacros("archi"));
}

TEST(TestJSON, arrowsFunction) {
    EXPECT_TRUE(TestMacros("arrows"));
}

TEST(TestJSON, compileFunction) {
    EXPECT_TRUE(TestMacros("compile"));
}

TEST(TestJSON, crownFunction) {
    EXPECT_TRUE(TestMacros("crown"));
}
TEST(TestJSON, basic3dFunction) {
    EXPECT_TRUE(TestMacros("basic3d"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    // Print the current working directory
    //std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    
    return RUN_ALL_TESTS();
}