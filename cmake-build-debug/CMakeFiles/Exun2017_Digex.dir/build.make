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
include CMakeFiles/Exun2017_Digex.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exun2017_Digex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exun2017_Digex.dir/flags.make

CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o: CMakeFiles/Exun2017_Digex.dir/flags.make
CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o: ../DynamicProgramming/Exun2017_Digex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/Exun2017_Digex.cpp

CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/Exun2017_Digex.cpp > CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.i

CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/Exun2017_Digex.cpp -o CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.s

CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.requires:

.PHONY : CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.requires

CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.provides: CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.requires
	$(MAKE) -f CMakeFiles/Exun2017_Digex.dir/build.make CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.provides.build
.PHONY : CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.provides

CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.provides.build: CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o


# Object files for target Exun2017_Digex
Exun2017_Digex_OBJECTS = \
"CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o"

# External object files for target Exun2017_Digex
Exun2017_Digex_EXTERNAL_OBJECTS =

Exun2017_Digex: CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o
Exun2017_Digex: CMakeFiles/Exun2017_Digex.dir/build.make
Exun2017_Digex: CMakeFiles/Exun2017_Digex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Exun2017_Digex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exun2017_Digex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exun2017_Digex.dir/build: Exun2017_Digex

.PHONY : CMakeFiles/Exun2017_Digex.dir/build

CMakeFiles/Exun2017_Digex.dir/requires: CMakeFiles/Exun2017_Digex.dir/DynamicProgramming/Exun2017_Digex.cpp.o.requires

.PHONY : CMakeFiles/Exun2017_Digex.dir/requires

CMakeFiles/Exun2017_Digex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exun2017_Digex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exun2017_Digex.dir/clean

CMakeFiles/Exun2017_Digex.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/Exun2017_Digex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exun2017_Digex.dir/depend

