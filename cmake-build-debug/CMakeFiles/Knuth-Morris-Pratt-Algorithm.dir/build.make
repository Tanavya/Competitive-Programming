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
CMAKE_COMMAND = /Volumes/x10ded/Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Volumes/x10ded/Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tanavya.dimri/Desktop/Competitive-Programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/flags.make

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/flags.make
CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o: ../OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.i"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp > CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.i

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.s"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp -o CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.s

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.requires:

.PHONY : CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.requires

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.provides: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.requires
	$(MAKE) -f CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/build.make CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.provides.build
.PHONY : CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.provides

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.provides.build: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o


# Object files for target Knuth-Morris-Pratt-Algorithm
Knuth__Morris__Pratt__Algorithm_OBJECTS = \
"CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o"

# External object files for target Knuth-Morris-Pratt-Algorithm
Knuth__Morris__Pratt__Algorithm_EXTERNAL_OBJECTS =

Knuth-Morris-Pratt-Algorithm: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o
Knuth-Morris-Pratt-Algorithm: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/build.make
Knuth-Morris-Pratt-Algorithm: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Knuth-Morris-Pratt-Algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/build: Knuth-Morris-Pratt-Algorithm

.PHONY : CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/build

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/requires: CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp.o.requires

.PHONY : CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/requires

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/clean

CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Knuth-Morris-Pratt-Algorithm.dir/depend

