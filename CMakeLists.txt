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
add_library(Test_JSON STATIC ${Sources} ${Headers})
target_link_libraries(Test_JSON PUBLIC ${ROOT_LIBRARIES})

#Subdirectories
add_subdirectory(test)
add_subdirectory(googletest)