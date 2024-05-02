cmake_minimum_required(VERSION 3.10)
project(Root-Graphic-Tests)

set(This Test_JSON)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Test_JSON.hpp
)
set(Sources
    Test_JSON.cpp
)

add_library(${This} STATIC ${Sources} ${Headers}) 
add_subdirectory(test)