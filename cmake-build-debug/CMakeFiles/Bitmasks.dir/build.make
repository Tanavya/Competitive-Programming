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
include CMakeFiles/Bitmasks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bitmasks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bitmasks.dir/flags.make

CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o: CMakeFiles/Bitmasks.dir/flags.make
CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o: ../OtherAlgorithms/Bitmasks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/OtherAlgorithms/Bitmasks.cpp

CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/OtherAlgorithms/Bitmasks.cpp > CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.i

CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/OtherAlgorithms/Bitmasks.cpp -o CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.s

CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.requires:

.PHONY : CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.requires

CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.provides: CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bitmasks.dir/build.make CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.provides.build
.PHONY : CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.provides

CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.provides.build: CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o


# Object files for target Bitmasks
Bitmasks_OBJECTS = \
"CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o"

# External object files for target Bitmasks
Bitmasks_EXTERNAL_OBJECTS =

Bitmasks: CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o
Bitmasks: CMakeFiles/Bitmasks.dir/build.make
Bitmasks: CMakeFiles/Bitmasks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Bitmasks"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bitmasks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bitmasks.dir/build: Bitmasks

.PHONY : CMakeFiles/Bitmasks.dir/build

CMakeFiles/Bitmasks.dir/requires: CMakeFiles/Bitmasks.dir/OtherAlgorithms/Bitmasks.cpp.o.requires

.PHONY : CMakeFiles/Bitmasks.dir/requires

CMakeFiles/Bitmasks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bitmasks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bitmasks.dir/clean

CMakeFiles/Bitmasks.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/Bitmasks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bitmasks.dir/depend

