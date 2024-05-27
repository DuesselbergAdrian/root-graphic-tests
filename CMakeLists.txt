cmake_minimum_required(VERSION 3.10)
project(Root-Graphic-Tests)
set(CMAKE_CXX_STANDARD 17)

#ROOT
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

set(Headers
    Test_JSON.hpp
)
set(Sources
    Test_JSON.cpp
)

#Libraries
add_executable(Test_JSON ${Sources})
target_link_libraries(Test_JSON PUBLIC ${ROOT_LIBRARIES})

# List of macros to test
#set(macros
#    analyze
#    archi
#    arrows
#    compile
#    crown
#    basic3d
#    # Add more macros here as needed
#)
# Run Python script to generate the CMake list
execute_process(
    COMMAND ${CMAKE_COMMAND} -E env python3 ${CMAKE_SOURCE_DIR}/generate_macros_cmake.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Include the generated macros list
include(${CMAKE_SOURCE_DIR}/macros.cmake)

#JSON tests for each macro
foreach(macro ${macros})
    add_test(
        NAME ${macro}_JSONTest
        COMMAND root -l -b -q "Test_JSON.cpp(\"${macro}\")"
        )
    set_tests_properties(${macro}_JSONTest PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

#SVG tests for each macro
foreach(macro ${macros})
    add_test(
        NAME ${macro}_SVGTest
        #COMMAND xvfb-run --auto-servernum --server-args='-screen 0 1024x768x24' node Test_SVG.js ${macro}
        COMMAND node Test_SVG.js ${macro}
    )
    set_tests_properties(${macro}_SVGTest PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()
