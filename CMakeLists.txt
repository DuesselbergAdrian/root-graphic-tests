cmake_minimum_required(VERSION 3.10)
project(Root-Graphic-Tests)

# Enable testing with CTest
enable_testing()

# Include GoogleTest
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define your test executable
add_executable(root_macro_tests test.cpp)
target_link_libraries(root_macro_tests gtest gtest_main)

# Add the tests to CTest
add_test(NAME RootMacroTest COMMAND root_macro_tests)