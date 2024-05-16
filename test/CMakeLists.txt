cmake_minimum_required(VERSION 3.10)
project(JSONTest)

# List of macros to test
set(macros
    analyze
    archi
    basic3d
    compile
    crown
    # Add more macros here as needed
)

# Add test executable
add_executable(JsonTests JsonTests.cpp)
target_link_libraries(JsonTests PUBLIC
    Test_JSON
    gtest_main
    ${ROOT_LIBRARIES}
)

# Add each macro as a separate test
foreach(macro ${macros})
    add_test(NAME ${macro} COMMAND JsonTests MacroTests.RunMacro/${macro})
endforeach()

# Add SVG Test: here iI need to find a waty to run each test seperate from a list
add_test(
    NAME SVGTest
    COMMAND node Test_SVG.js
)