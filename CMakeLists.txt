cmake_minimum_required(VERSION 3.10)

project(Root-Graphic-Tests)

set(This Test_JSON)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)



#############################################################################################
# If no explicit ROOTSYS is set, use ${ROOTSYS} environment variable to search
# for ROOT. This may be set by sourcing thisroot.sh from an installation.
if(NOT DEFINED ROOTSYS AND DEFINED ENV{ROOTSYS})
  file(TO_CMAKE_PATH $ENV{ROOTSYS} ROOTSYS)
  list(INSERT CMAKE_PREFIX_PATH 0 ${ROOTSYS})
endif()

# Use ${ROOTSYS} CMake variable to search for ROOT. This is set when roottest is
# built as part of ROOT, i.e., when ROOT is configured with -Droottest=ON. It
# may also be set by passing -DROOTSYS=<PATH> to CMake when configuring a
# standalone roottest against an installation of ROOT. If this is set, it takes
# precedence over the environment to ensure that when roottest is being built in
# a ROOT build configured with -Droottest=ON, it will find the ROOT being built,
# and not a ROOT installation sourced with thisroot.sh or found in $PATH.
if(DEFINED ROOTSYS)
  list(INSERT CMAKE_PREFIX_PATH 0 ${ROOTSYS})
endif()

find_package(ROOT REQUIRED CONFIG)

include_directories(${ROOT_INCLUDE_DIRS})

enable_testing()

add_subdirectory(googletest)

set(Headers
    Test_JSON.hpp
)
set(Sources
    Test_JSON.cpp
)

# Link against ROOT libraries
link_libraries(${ROOT_LIBRARIES})

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)