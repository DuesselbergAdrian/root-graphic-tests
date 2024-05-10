# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrianduesselberg/root-graphic-tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrianduesselberg/root-graphic-tests/build

# Include any dependencies generated for this target.
include test/CMakeFiles/JsonMoreTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/JsonMoreTests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/JsonMoreTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/JsonMoreTests.dir/flags.make

test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o: test/CMakeFiles/JsonMoreTests.dir/flags.make
test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o: /home/adrianduesselberg/root-graphic-tests/test/GraphsJsonTests.cpp
test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o: test/CMakeFiles/JsonMoreTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o -MF CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o.d -o CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o -c /home/adrianduesselberg/root-graphic-tests/test/GraphsJsonTests.cpp

test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.i"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrianduesselberg/root-graphic-tests/test/GraphsJsonTests.cpp > CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.i

test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.s"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrianduesselberg/root-graphic-tests/test/GraphsJsonTests.cpp -o CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.s

# Object files for target JsonMoreTests
JsonMoreTests_OBJECTS = \
"CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o"

# External object files for target JsonMoreTests
JsonMoreTests_EXTERNAL_OBJECTS =

test/JsonMoreTests: test/CMakeFiles/JsonMoreTests.dir/GraphsJsonTests.cpp.o
test/JsonMoreTests: test/CMakeFiles/JsonMoreTests.dir/build.make
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libCore.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libImt.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libRIO.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libNet.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libHist.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libGraf.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libGraf3d.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libGpad.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libROOTDataFrame.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libTree.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libTreePlayer.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libRint.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libPostscript.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libMatrix.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libPhysics.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libMathCore.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libThread.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libMultiProc.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libROOTVecOps.so
test/JsonMoreTests: lib/libgtest_main.a
test/JsonMoreTests: libTest_JSON.a
test/JsonMoreTests: lib/libgtest.a
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libCore.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libImt.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libRIO.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libNet.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libHist.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libGraf.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libGraf3d.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libGpad.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libROOTDataFrame.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libTree.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libTreePlayer.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libRint.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libPostscript.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libMatrix.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libPhysics.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libMathCore.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libThread.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libMultiProc.so
test/JsonMoreTests: /home/adrianduesselberg/build/lib/libROOTVecOps.so
test/JsonMoreTests: test/CMakeFiles/JsonMoreTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JsonMoreTests"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JsonMoreTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/JsonMoreTests.dir/build: test/JsonMoreTests
.PHONY : test/CMakeFiles/JsonMoreTests.dir/build

test/CMakeFiles/JsonMoreTests.dir/clean:
	cd /home/adrianduesselberg/root-graphic-tests/build/test && $(CMAKE_COMMAND) -P CMakeFiles/JsonMoreTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/JsonMoreTests.dir/clean

test/CMakeFiles/JsonMoreTests.dir/depend:
	cd /home/adrianduesselberg/root-graphic-tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrianduesselberg/root-graphic-tests /home/adrianduesselberg/root-graphic-tests/test /home/adrianduesselberg/root-graphic-tests/build /home/adrianduesselberg/root-graphic-tests/build/test /home/adrianduesselberg/root-graphic-tests/build/test/CMakeFiles/JsonMoreTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/JsonMoreTests.dir/depend

