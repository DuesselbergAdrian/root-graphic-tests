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
include test/CMakeFiles/GraphicsTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/GraphicsTest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/GraphicsTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/GraphicsTest.dir/flags.make

test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o: test/CMakeFiles/GraphicsTest.dir/flags.make
test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o: /home/adrianduesselberg/root-graphic-tests/test/GraphicsJsonTests.cpp
test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o: test/CMakeFiles/GraphicsTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o -MF CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o.d -o CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o -c /home/adrianduesselberg/root-graphic-tests/test/GraphicsJsonTests.cpp

test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.i"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrianduesselberg/root-graphic-tests/test/GraphicsJsonTests.cpp > CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.i

test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.s"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrianduesselberg/root-graphic-tests/test/GraphicsJsonTests.cpp -o CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.s

# Object files for target GraphicsTest
GraphicsTest_OBJECTS = \
"CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o"

# External object files for target GraphicsTest
GraphicsTest_EXTERNAL_OBJECTS =

test/GraphicsTest: test/CMakeFiles/GraphicsTest.dir/GraphicsJsonTests.cpp.o
test/GraphicsTest: test/CMakeFiles/GraphicsTest.dir/build.make
test/GraphicsTest: /home/adrianduesselberg/build/lib/libCore.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libImt.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libRIO.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libNet.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libHist.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libGraf.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libGraf3d.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libGpad.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libROOTDataFrame.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libTree.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libTreePlayer.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libRint.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libPostscript.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libMatrix.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libPhysics.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libMathCore.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libThread.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libMultiProc.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libROOTVecOps.so
test/GraphicsTest: lib/libgtest_main.a
test/GraphicsTest: libTest_JSON.a
test/GraphicsTest: lib/libgtest.a
test/GraphicsTest: /home/adrianduesselberg/build/lib/libCore.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libImt.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libRIO.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libNet.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libHist.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libGraf.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libGraf3d.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libGpad.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libROOTDataFrame.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libTree.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libTreePlayer.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libRint.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libPostscript.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libMatrix.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libPhysics.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libMathCore.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libThread.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libMultiProc.so
test/GraphicsTest: /home/adrianduesselberg/build/lib/libROOTVecOps.so
test/GraphicsTest: test/CMakeFiles/GraphicsTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GraphicsTest"
	cd /home/adrianduesselberg/root-graphic-tests/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphicsTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/GraphicsTest.dir/build: test/GraphicsTest
.PHONY : test/CMakeFiles/GraphicsTest.dir/build

test/CMakeFiles/GraphicsTest.dir/clean:
	cd /home/adrianduesselberg/root-graphic-tests/build/test && $(CMAKE_COMMAND) -P CMakeFiles/GraphicsTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/GraphicsTest.dir/clean

test/CMakeFiles/GraphicsTest.dir/depend:
	cd /home/adrianduesselberg/root-graphic-tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrianduesselberg/root-graphic-tests /home/adrianduesselberg/root-graphic-tests/test /home/adrianduesselberg/root-graphic-tests/build /home/adrianduesselberg/root-graphic-tests/build/test /home/adrianduesselberg/root-graphic-tests/build/test/CMakeFiles/GraphicsTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/GraphicsTest.dir/depend

