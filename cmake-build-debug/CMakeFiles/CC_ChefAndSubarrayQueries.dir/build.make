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
include CMakeFiles/CC_ChefAndSubarrayQueries.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CC_ChefAndSubarrayQueries.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CC_ChefAndSubarrayQueries.dir/flags.make

CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o: CMakeFiles/CC_ChefAndSubarrayQueries.dir/flags.make
CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o: ../DataStructures/CC_ChefAndSubarrayQueries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/CC_ChefAndSubarrayQueries.cpp

CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.i"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/CC_ChefAndSubarrayQueries.cpp > CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.i

CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.s"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/CC_ChefAndSubarrayQueries.cpp -o CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.s

CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.requires:

.PHONY : CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.requires

CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.provides: CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.requires
	$(MAKE) -f CMakeFiles/CC_ChefAndSubarrayQueries.dir/build.make CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.provides.build
.PHONY : CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.provides

CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.provides.build: CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o


# Object files for target CC_ChefAndSubarrayQueries
CC_ChefAndSubarrayQueries_OBJECTS = \
"CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o"

# External object files for target CC_ChefAndSubarrayQueries
CC_ChefAndSubarrayQueries_EXTERNAL_OBJECTS =

CC_ChefAndSubarrayQueries: CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o
CC_ChefAndSubarrayQueries: CMakeFiles/CC_ChefAndSubarrayQueries.dir/build.make
CC_ChefAndSubarrayQueries: CMakeFiles/CC_ChefAndSubarrayQueries.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CC_ChefAndSubarrayQueries"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CC_ChefAndSubarrayQueries.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CC_ChefAndSubarrayQueries.dir/build: CC_ChefAndSubarrayQueries

.PHONY : CMakeFiles/CC_ChefAndSubarrayQueries.dir/build

CMakeFiles/CC_ChefAndSubarrayQueries.dir/requires: CMakeFiles/CC_ChefAndSubarrayQueries.dir/DataStructures/CC_ChefAndSubarrayQueries.cpp.o.requires

.PHONY : CMakeFiles/CC_ChefAndSubarrayQueries.dir/requires

CMakeFiles/CC_ChefAndSubarrayQueries.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CC_ChefAndSubarrayQueries.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CC_ChefAndSubarrayQueries.dir/clean

CMakeFiles/CC_ChefAndSubarrayQueries.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/CC_ChefAndSubarrayQueries.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CC_ChefAndSubarrayQueries.dir/depend

