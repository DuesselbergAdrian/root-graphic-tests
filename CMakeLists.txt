cmake_minimum_required(VERSION 3.10)
project(Root-Graphic-Tests)
set(CMAKE_CXX_STANDARD 17)

#ROOT setup
if(NOT DEFINED ROOTSYS AND DEFINED ENV{ROOTSYS})
  file(TO_CMAKE_PATH $ENV{ROOTSYS} ROOTSYS)
  list(INSERT CMAKE_PREFIX_PATH 0 ${ROOTSYS})
endif()
if(DEFINED ROOTSYS)
  list(INSERT CMAKE_PREFIX_PATH 0 ${ROOTSYS})
endif()

find_package(ROOT REQUIRED COMPONENTS RIO Net Hist Graf Gpad Tree Matrix Physics MathCore Graf3d WebGui6)
include(${ROOT_USE_FILE})

enable_testing()

# Sources and headers
set(Headers
    Test_Root.hpp
)
set(Sources
    Test_Root.cpp
)

# Add executable
add_executable(Test_Root ${Sources})
target_link_libraries(Test_Root PUBLIC ${ROOT_LIBRARIES})

# Run Python script to generate the CMake list
execute_process(
    COMMAND ${CMAKE_COMMAND} -E env python3 ${CMAKE_SOURCE_DIR}/generate_macros_cmake.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Include the generated macros list
include(${CMAKE_SOURCE_DIR}/macros.cmake)

#Tests for each macro: (j == JSON),(o == old SVG), (s == new SVG), (a == all)
foreach(macro_content ${macros})

    string(REGEX MATCH "([^ ]+) ([^ ]+) ([^ ]+)" _ ${macro_content})
    set(macro ${CMAKE_MATCH_1})
    set(test_type ${CMAKE_MATCH_2})
    set(macro_folder ${CMAKE_MATCH_3})
    message(STATUS "Macro: ${macro}, Test_type: ${test_type}, Macro_folder: ${macro_folder}")

    if(${test_type} STREQUAL "j")
        add_test(
            NAME ${macro}_RootTest_${test_type}
            COMMAND root -l -b -q "Test_Root.cpp(\"${macro}\", \"${test_type}\", \"${macro_folder}\")"
            )
        set_tests_properties(${macro}_RootTest_${test_type} PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    elseif(${test_type} STREQUAL "o")
        add_test(
            NAME ${macro}_RootTest_${test_type}
            COMMAND root -l -b -q --web=off "Test_Root.cpp(\"${macro}\", \"${test_type}\", \"${macro_folder}\")"
        )
        set_tests_properties(${macro}_RootTest_${test_type} PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    elseif(${test_type} STREQUAL "s")
        add_test(
            NAME ${macro}_JsRootTest_${test_type}
            COMMAND node Test_JsRoot.js ${macro}
            )
        set_tests_properties(${macro}_JsRootTest_${test_type} PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    elseif(${test_type} STREQUAL "a")
        add_test(NAME ${macro}_ALL_step1
            COMMAND root -l -b -q "Test_Root.cpp(\"${macro}\", \"j\", \"${macro_folder}\")"
        )
        add_test(NAME ${macro}_ALL_step2
            COMMAND root -l -b -q --web=off "Test_Root.cpp(\"${macro}\", \"o\", \"${macro_folder}\")"
        )
        add_test(NAME ${macro}_ALL_step3
            COMMAND node Test_JsRoot.js ${macro}
        )
        set_tests_properties(${macro}_ALL_step1 PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        set_tests_properties(${macro}_ALL_step2 PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
        set_tests_properties(${macro}_ALL_step3 PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

        add_custom_target(${macro}_All
            DEPENDS ${macro}_ALL_step1 ${macro}_ALL_step2 ${macro}_ALL_step3
        )

    endif()
    
endforeach()
