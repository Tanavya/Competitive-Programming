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
include CMakeFiles/IOITC2014_Granularity.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IOITC2014_Granularity.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IOITC2014_Granularity.dir/flags.make

CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o: CMakeFiles/IOITC2014_Granularity.dir/flags.make
CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o: ../DataStructures/IOITC2014_Granularity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/IOITC2014_Granularity.cpp

CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/IOITC2014_Granularity.cpp > CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.i

CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/IOITC2014_Granularity.cpp -o CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.s

CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.requires:

.PHONY : CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.requires

CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.provides: CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.requires
	$(MAKE) -f CMakeFiles/IOITC2014_Granularity.dir/build.make CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.provides.build
.PHONY : CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.provides

CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.provides.build: CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o


# Object files for target IOITC2014_Granularity
IOITC2014_Granularity_OBJECTS = \
"CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o"

# External object files for target IOITC2014_Granularity
IOITC2014_Granularity_EXTERNAL_OBJECTS =

IOITC2014_Granularity: CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o
IOITC2014_Granularity: CMakeFiles/IOITC2014_Granularity.dir/build.make
IOITC2014_Granularity: CMakeFiles/IOITC2014_Granularity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IOITC2014_Granularity"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IOITC2014_Granularity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IOITC2014_Granularity.dir/build: IOITC2014_Granularity

.PHONY : CMakeFiles/IOITC2014_Granularity.dir/build

CMakeFiles/IOITC2014_Granularity.dir/requires: CMakeFiles/IOITC2014_Granularity.dir/DataStructures/IOITC2014_Granularity.cpp.o.requires

.PHONY : CMakeFiles/IOITC2014_Granularity.dir/requires

CMakeFiles/IOITC2014_Granularity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IOITC2014_Granularity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IOITC2014_Granularity.dir/clean

CMakeFiles/IOITC2014_Granularity.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/IOITC2014_Granularity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IOITC2014_Granularity.dir/depend

