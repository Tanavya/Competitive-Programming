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
include CMakeFiles/1D1DOptimisation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1D1DOptimisation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1D1DOptimisation.dir/flags.make

CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o: CMakeFiles/1D1DOptimisation.dir/flags.make
CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o: ../DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp

CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp > CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.i

CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp -o CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.s

CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.requires:

.PHONY : CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.requires

CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.provides: CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.requires
	$(MAKE) -f CMakeFiles/1D1DOptimisation.dir/build.make CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.provides.build
.PHONY : CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.provides

CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.provides.build: CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o


# Object files for target 1D1DOptimisation
1D1DOptimisation_OBJECTS = \
"CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o"

# External object files for target 1D1DOptimisation
1D1DOptimisation_EXTERNAL_OBJECTS =

1D1DOptimisation: CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o
1D1DOptimisation: CMakeFiles/1D1DOptimisation.dir/build.make
1D1DOptimisation: CMakeFiles/1D1DOptimisation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1D1DOptimisation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1D1DOptimisation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1D1DOptimisation.dir/build: 1D1DOptimisation

.PHONY : CMakeFiles/1D1DOptimisation.dir/build

CMakeFiles/1D1DOptimisation.dir/requires: CMakeFiles/1D1DOptimisation.dir/DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp.o.requires

.PHONY : CMakeFiles/1D1DOptimisation.dir/requires

CMakeFiles/1D1DOptimisation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1D1DOptimisation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1D1DOptimisation.dir/clean

CMakeFiles/1D1DOptimisation.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/1D1DOptimisation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1D1DOptimisation.dir/depend

