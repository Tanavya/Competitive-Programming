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
include CMakeFiles/SPOJ_SEGSQRSS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPOJ_SEGSQRSS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPOJ_SEGSQRSS.dir/flags.make

CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o: CMakeFiles/SPOJ_SEGSQRSS.dir/flags.make
CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o: ../DataStructures/SPOJ_SEGSQRSS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/SPOJ_SEGSQRSS.cpp

CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/SPOJ_SEGSQRSS.cpp > CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.i

CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/SPOJ_SEGSQRSS.cpp -o CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.s

CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.requires:

.PHONY : CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.requires

CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.provides: CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.requires
	$(MAKE) -f CMakeFiles/SPOJ_SEGSQRSS.dir/build.make CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.provides.build
.PHONY : CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.provides

CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.provides.build: CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o


# Object files for target SPOJ_SEGSQRSS
SPOJ_SEGSQRSS_OBJECTS = \
"CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o"

# External object files for target SPOJ_SEGSQRSS
SPOJ_SEGSQRSS_EXTERNAL_OBJECTS =

SPOJ_SEGSQRSS: CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o
SPOJ_SEGSQRSS: CMakeFiles/SPOJ_SEGSQRSS.dir/build.make
SPOJ_SEGSQRSS: CMakeFiles/SPOJ_SEGSQRSS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SPOJ_SEGSQRSS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPOJ_SEGSQRSS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPOJ_SEGSQRSS.dir/build: SPOJ_SEGSQRSS

.PHONY : CMakeFiles/SPOJ_SEGSQRSS.dir/build

CMakeFiles/SPOJ_SEGSQRSS.dir/requires: CMakeFiles/SPOJ_SEGSQRSS.dir/DataStructures/SPOJ_SEGSQRSS.cpp.o.requires

.PHONY : CMakeFiles/SPOJ_SEGSQRSS.dir/requires

CMakeFiles/SPOJ_SEGSQRSS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPOJ_SEGSQRSS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPOJ_SEGSQRSS.dir/clean

CMakeFiles/SPOJ_SEGSQRSS.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/SPOJ_SEGSQRSS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPOJ_SEGSQRSS.dir/depend
