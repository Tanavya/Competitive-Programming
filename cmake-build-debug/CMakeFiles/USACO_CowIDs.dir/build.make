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
include CMakeFiles/USACO_CowIDs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/USACO_CowIDs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/USACO_CowIDs.dir/flags.make

CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o: CMakeFiles/USACO_CowIDs.dir/flags.make
CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o: ../Miscellaneous/USACO_CowIDs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/Miscellaneous/USACO_CowIDs.cpp

CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/Miscellaneous/USACO_CowIDs.cpp > CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.i

CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/Miscellaneous/USACO_CowIDs.cpp -o CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.s

CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.requires:

.PHONY : CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.requires

CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.provides: CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.requires
	$(MAKE) -f CMakeFiles/USACO_CowIDs.dir/build.make CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.provides.build
.PHONY : CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.provides

CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.provides.build: CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o


# Object files for target USACO_CowIDs
USACO_CowIDs_OBJECTS = \
"CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o"

# External object files for target USACO_CowIDs
USACO_CowIDs_EXTERNAL_OBJECTS =

USACO_CowIDs: CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o
USACO_CowIDs: CMakeFiles/USACO_CowIDs.dir/build.make
USACO_CowIDs: CMakeFiles/USACO_CowIDs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable USACO_CowIDs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/USACO_CowIDs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/USACO_CowIDs.dir/build: USACO_CowIDs

.PHONY : CMakeFiles/USACO_CowIDs.dir/build

CMakeFiles/USACO_CowIDs.dir/requires: CMakeFiles/USACO_CowIDs.dir/Miscellaneous/USACO_CowIDs.cpp.o.requires

.PHONY : CMakeFiles/USACO_CowIDs.dir/requires

CMakeFiles/USACO_CowIDs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/USACO_CowIDs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/USACO_CowIDs.dir/clean

CMakeFiles/USACO_CowIDs.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/USACO_CowIDs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/USACO_CowIDs.dir/depend

