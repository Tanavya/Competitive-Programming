# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tanavya.dimri/Desktop/Competitive-Programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CF868E_PolicemanAndTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CF868E_PolicemanAndTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CF868E_PolicemanAndTree.dir/flags.make

CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o: CMakeFiles/CF868E_PolicemanAndTree.dir/flags.make
CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o: ../DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp

CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp > CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.i

CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp -o CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.s

CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.requires:

.PHONY : CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.requires

CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.provides: CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/CF868E_PolicemanAndTree.dir/build.make CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.provides.build
.PHONY : CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.provides

CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.provides.build: CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o


# Object files for target CF868E_PolicemanAndTree
CF868E_PolicemanAndTree_OBJECTS = \
"CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o"

# External object files for target CF868E_PolicemanAndTree
CF868E_PolicemanAndTree_EXTERNAL_OBJECTS =

CF868E_PolicemanAndTree: CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o
CF868E_PolicemanAndTree: CMakeFiles/CF868E_PolicemanAndTree.dir/build.make
CF868E_PolicemanAndTree: CMakeFiles/CF868E_PolicemanAndTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CF868E_PolicemanAndTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CF868E_PolicemanAndTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CF868E_PolicemanAndTree.dir/build: CF868E_PolicemanAndTree

.PHONY : CMakeFiles/CF868E_PolicemanAndTree.dir/build

CMakeFiles/CF868E_PolicemanAndTree.dir/requires: CMakeFiles/CF868E_PolicemanAndTree.dir/DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp.o.requires

.PHONY : CMakeFiles/CF868E_PolicemanAndTree.dir/requires

CMakeFiles/CF868E_PolicemanAndTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CF868E_PolicemanAndTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CF868E_PolicemanAndTree.dir/clean

CMakeFiles/CF868E_PolicemanAndTree.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/CF868E_PolicemanAndTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CF868E_PolicemanAndTree.dir/depend

