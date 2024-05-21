cmake_minimum_required(VERSION 3.10)

# List of macros to test
set(macros
    analyze
    archi
    arrows
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


# Ensure the working directory is set to the correct directory
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

#JSON tests for each macro
foreach(macro ${macros})
    add_test(
        NAME ${macro}_JSONTest
        COMMAND JsonTests --gtest_filter=TestJSON.${macro}Function
    )
    set_tests_properties(${macro}_JSONTest PROPERTIES WORKING_DIRECTORY ${PARENT_DIR})    
endforeach()

#SVG tests for each macro
foreach(macro ${macros})
    add_test(
        NAME ${macro}_SVGTest
        COMMAND node Test_SVG.js ${macro}
    )
    set_tests_properties(${macro}_SVGTest PROPERTIES WORKING_DIRECTORY ${PARENT_DIR})
endforeach()