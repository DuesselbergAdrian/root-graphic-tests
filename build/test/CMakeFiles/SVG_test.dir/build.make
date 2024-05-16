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
include test/CMakeFiles/SVG_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/SVG_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/SVG_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/SVG_test.dir/flags.make

test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o: test/CMakeFiles/SVG_test.dir/flags.make
test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o: /home/adrianduesselberg/root-graphic-tests/test/GraphicSVGTests.cpp
test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o: test/CMakeFiles/SVG_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o -MF CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o.d -o CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o -c /home/adrianduesselberg/root-graphic-tests/test/GraphicSVGTests.cpp

test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.i"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrianduesselberg/root-graphic-tests/test/GraphicSVGTests.cpp > CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.i

test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.s"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrianduesselberg/root-graphic-tests/test/GraphicSVGTests.cpp -o CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.s

# Object files for target SVG_test
SVG_test_OBJECTS = \
"CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o"

# External object files for target SVG_test
SVG_test_EXTERNAL_OBJECTS =

test/SVG_test: test/CMakeFiles/SVG_test.dir/GraphicSVGTests.cpp.o
test/SVG_test: test/CMakeFiles/SVG_test.dir/build.make
test/SVG_test: /home/adrianduesselberg/build/lib/libCore.so
test/SVG_test: /home/adrianduesselberg/build/lib/libImt.so
test/SVG_test: /home/adrianduesselberg/build/lib/libRIO.so
test/SVG_test: /home/adrianduesselberg/build/lib/libNet.so
test/SVG_test: /home/adrianduesselberg/build/lib/libHist.so
test/SVG_test: /home/adrianduesselberg/build/lib/libGraf.so
test/SVG_test: /home/adrianduesselberg/build/lib/libGraf3d.so
test/SVG_test: /home/adrianduesselberg/build/lib/libGpad.so
test/SVG_test: /home/adrianduesselberg/build/lib/libROOTDataFrame.so
test/SVG_test: /home/adrianduesselberg/build/lib/libTree.so
test/SVG_test: /home/adrianduesselberg/build/lib/libTreePlayer.so
test/SVG_test: /home/adrianduesselberg/build/lib/libRint.so
test/SVG_test: /home/adrianduesselberg/build/lib/libPostscript.so
test/SVG_test: /home/adrianduesselberg/build/lib/libMatrix.so
test/SVG_test: /home/adrianduesselberg/build/lib/libPhysics.so
test/SVG_test: /home/adrianduesselberg/build/lib/libMathCore.so
test/SVG_test: /home/adrianduesselberg/build/lib/libThread.so
test/SVG_test: /home/adrianduesselberg/build/lib/libMultiProc.so
test/SVG_test: /home/adrianduesselberg/build/lib/libROOTVecOps.so
test/SVG_test: lib/libgtest_main.a
test/SVG_test: lib/libgtest.a
test/SVG_test: test/CMakeFiles/SVG_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SVG_test"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SVG_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/SVG_test.dir/build: test/SVG_test
.PHONY : test/CMakeFiles/SVG_test.dir/build

test/CMakeFiles/SVG_test.dir/clean:
	cd /home/adrianduesselberg/root-graphic-tests/build/test && $(CMAKE_COMMAND) -P CMakeFiles/SVG_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/SVG_test.dir/clean

test/CMakeFiles/SVG_test.dir/depend:
	cd /home/adrianduesselberg/root-graphic-tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrianduesselberg/root-graphic-tests /home/adrianduesselberg/root-graphic-tests/test /home/adrianduesselberg/root-graphic-tests/build /home/adrianduesselberg/root-graphic-tests/build/test /home/adrianduesselberg/root-graphic-tests/build/test/CMakeFiles/SVG_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/SVG_test.dir/depend

