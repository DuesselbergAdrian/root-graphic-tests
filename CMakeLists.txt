cmake_minimum_required(VERSION 3.10)

project(Root-Graphic-Tests)

set(This Test_JSON)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)


if(NOT DEFINED ROOTSYS AND DEFINED ENV{ROOTSYS})
  file(TO_CMAKE_PATH $ENV{ROOTSYS} ROOTSYS)
  list(INSERT CMAKE_PREFIX_PATH 0 ${ROOTSYS})
endif()

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