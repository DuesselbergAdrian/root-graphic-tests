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
include CMakeFiles/Test_JSON.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test_JSON.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test_JSON.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test_JSON.dir/flags.make

CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o: CMakeFiles/Test_JSON.dir/flags.make
CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o: /home/adrianduesselberg/root-graphic-tests/Test_JSON.cpp
CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o: CMakeFiles/Test_JSON.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o -MF CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o.d -o CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o -c /home/adrianduesselberg/root-graphic-tests/Test_JSON.cpp

CMakeFiles/Test_JSON.dir/Test_JSON.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test_JSON.dir/Test_JSON.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrianduesselberg/root-graphic-tests/Test_JSON.cpp > CMakeFiles/Test_JSON.dir/Test_JSON.cpp.i

CMakeFiles/Test_JSON.dir/Test_JSON.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test_JSON.dir/Test_JSON.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrianduesselberg/root-graphic-tests/Test_JSON.cpp -o CMakeFiles/Test_JSON.dir/Test_JSON.cpp.s

# Object files for target Test_JSON
Test_JSON_OBJECTS = \
"CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o"

# External object files for target Test_JSON
Test_JSON_EXTERNAL_OBJECTS =

libTest_JSON.a: CMakeFiles/Test_JSON.dir/Test_JSON.cpp.o
libTest_JSON.a: CMakeFiles/Test_JSON.dir/build.make
libTest_JSON.a: CMakeFiles/Test_JSON.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adrianduesselberg/root-graphic-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTest_JSON.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Test_JSON.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_JSON.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test_JSON.dir/build: libTest_JSON.a
.PHONY : CMakeFiles/Test_JSON.dir/build

CMakeFiles/Test_JSON.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test_JSON.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test_JSON.dir/clean

CMakeFiles/Test_JSON.dir/depend:
	cd /home/adrianduesselberg/root-graphic-tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrianduesselberg/root-graphic-tests /home/adrianduesselberg/root-graphic-tests /home/adrianduesselberg/root-graphic-tests/build /home/adrianduesselberg/root-graphic-tests/build /home/adrianduesselberg/root-graphic-tests/build/CMakeFiles/Test_JSON.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Test_JSON.dir/depend

