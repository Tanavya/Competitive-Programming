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
include CMakeFiles/SPOJ_QTREE1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPOJ_QTREE1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPOJ_QTREE1.dir/flags.make

CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o: CMakeFiles/SPOJ_QTREE1.dir/flags.make
CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o: ../DataStructures/SPOJ_QTREE1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/SPOJ_QTREE1.cpp

CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.i"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/SPOJ_QTREE1.cpp > CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.i

CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.s"
	/Volumes/x10ded/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DataStructures/SPOJ_QTREE1.cpp -o CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.s

CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.requires:

.PHONY : CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.requires

CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.provides: CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.requires
	$(MAKE) -f CMakeFiles/SPOJ_QTREE1.dir/build.make CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.provides.build
.PHONY : CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.provides

CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.provides.build: CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o


# Object files for target SPOJ_QTREE1
SPOJ_QTREE1_OBJECTS = \
"CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o"

# External object files for target SPOJ_QTREE1
SPOJ_QTREE1_EXTERNAL_OBJECTS =

SPOJ_QTREE1: CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o
SPOJ_QTREE1: CMakeFiles/SPOJ_QTREE1.dir/build.make
SPOJ_QTREE1: CMakeFiles/SPOJ_QTREE1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SPOJ_QTREE1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPOJ_QTREE1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPOJ_QTREE1.dir/build: SPOJ_QTREE1

.PHONY : CMakeFiles/SPOJ_QTREE1.dir/build

CMakeFiles/SPOJ_QTREE1.dir/requires: CMakeFiles/SPOJ_QTREE1.dir/DataStructures/SPOJ_QTREE1.cpp.o.requires

.PHONY : CMakeFiles/SPOJ_QTREE1.dir/requires

CMakeFiles/SPOJ_QTREE1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPOJ_QTREE1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPOJ_QTREE1.dir/clean

CMakeFiles/SPOJ_QTREE1.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/SPOJ_QTREE1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPOJ_QTREE1.dir/depend

