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
include CMakeFiles/CF348C_SubsetSums.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CF348C_SubsetSums.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CF348C_SubsetSums.dir/flags.make

CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o: CMakeFiles/CF348C_SubsetSums.dir/flags.make
CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o: ../DataStructures/CF348C_SubsetSums.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/CF348C_SubsetSums.cpp

CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/CF348C_SubsetSums.cpp > CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.i

CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/CF348C_SubsetSums.cpp -o CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.s

CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.requires:

.PHONY : CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.requires

CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.provides: CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.requires
	$(MAKE) -f CMakeFiles/CF348C_SubsetSums.dir/build.make CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.provides.build
.PHONY : CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.provides

CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.provides.build: CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o


# Object files for target CF348C_SubsetSums
CF348C_SubsetSums_OBJECTS = \
"CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o"

# External object files for target CF348C_SubsetSums
CF348C_SubsetSums_EXTERNAL_OBJECTS =

CF348C_SubsetSums: CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o
CF348C_SubsetSums: CMakeFiles/CF348C_SubsetSums.dir/build.make
CF348C_SubsetSums: CMakeFiles/CF348C_SubsetSums.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CF348C_SubsetSums"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CF348C_SubsetSums.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CF348C_SubsetSums.dir/build: CF348C_SubsetSums

.PHONY : CMakeFiles/CF348C_SubsetSums.dir/build

CMakeFiles/CF348C_SubsetSums.dir/requires: CMakeFiles/CF348C_SubsetSums.dir/DataStructures/CF348C_SubsetSums.cpp.o.requires

.PHONY : CMakeFiles/CF348C_SubsetSums.dir/requires

CMakeFiles/CF348C_SubsetSums.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CF348C_SubsetSums.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CF348C_SubsetSums.dir/clean

CMakeFiles/CF348C_SubsetSums.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/CF348C_SubsetSums.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CF348C_SubsetSums.dir/depend

