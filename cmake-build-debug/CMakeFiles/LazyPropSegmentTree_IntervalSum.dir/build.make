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
include CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/flags.make

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/flags.make
CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o: ../DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp > CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.i

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp -o CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.s

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.requires:

.PHONY : CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.requires

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.provides: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.requires
	$(MAKE) -f CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/build.make CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.provides.build
.PHONY : CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.provides

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.provides.build: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o


# Object files for target LazyPropSegmentTree_IntervalSum
LazyPropSegmentTree_IntervalSum_OBJECTS = \
"CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o"

# External object files for target LazyPropSegmentTree_IntervalSum
LazyPropSegmentTree_IntervalSum_EXTERNAL_OBJECTS =

LazyPropSegmentTree_IntervalSum: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o
LazyPropSegmentTree_IntervalSum: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/build.make
LazyPropSegmentTree_IntervalSum: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LazyPropSegmentTree_IntervalSum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/build: LazyPropSegmentTree_IntervalSum

.PHONY : CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/build

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/requires: CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp.o.requires

.PHONY : CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/requires

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/clean

CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LazyPropSegmentTree_IntervalSum.dir/depend
