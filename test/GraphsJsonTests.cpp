#include "../Test_JSON.hpp"

#include <gtest/gtest.h>

//One first example
TEST(TestGraphsJSON, GraphFunction){
    std::string macroPath = "graph";
    EXPECT_TRUE(TestMacrosG(macroPath));
}