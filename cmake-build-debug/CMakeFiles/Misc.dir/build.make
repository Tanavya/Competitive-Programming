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
include CMakeFiles/Misc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Misc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Misc.dir/flags.make

CMakeFiles/Misc.dir/Misc.cpp.o: CMakeFiles/Misc.dir/flags.make
CMakeFiles/Misc.dir/Misc.cpp.o: ../Misc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Misc.dir/Misc.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Misc.dir/Misc.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/Misc.cpp

CMakeFiles/Misc.dir/Misc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Misc.dir/Misc.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/Misc.cpp > CMakeFiles/Misc.dir/Misc.cpp.i

CMakeFiles/Misc.dir/Misc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Misc.dir/Misc.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/Misc.cpp -o CMakeFiles/Misc.dir/Misc.cpp.s

CMakeFiles/Misc.dir/Misc.cpp.o.requires:

.PHONY : CMakeFiles/Misc.dir/Misc.cpp.o.requires

CMakeFiles/Misc.dir/Misc.cpp.o.provides: CMakeFiles/Misc.dir/Misc.cpp.o.requires
	$(MAKE) -f CMakeFiles/Misc.dir/build.make CMakeFiles/Misc.dir/Misc.cpp.o.provides.build
.PHONY : CMakeFiles/Misc.dir/Misc.cpp.o.provides

CMakeFiles/Misc.dir/Misc.cpp.o.provides.build: CMakeFiles/Misc.dir/Misc.cpp.o


# Object files for target Misc
Misc_OBJECTS = \
"CMakeFiles/Misc.dir/Misc.cpp.o"

# External object files for target Misc
Misc_EXTERNAL_OBJECTS =

Misc: CMakeFiles/Misc.dir/Misc.cpp.o
Misc: CMakeFiles/Misc.dir/build.make
Misc: CMakeFiles/Misc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Misc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Misc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Misc.dir/build: Misc

.PHONY : CMakeFiles/Misc.dir/build

CMakeFiles/Misc.dir/requires: CMakeFiles/Misc.dir/Misc.cpp.o.requires

.PHONY : CMakeFiles/Misc.dir/requires

CMakeFiles/Misc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Misc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Misc.dir/clean

CMakeFiles/Misc.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/Misc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Misc.dir/depend
