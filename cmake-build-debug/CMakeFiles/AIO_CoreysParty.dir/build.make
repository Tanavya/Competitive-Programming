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
include CMakeFiles/AIO_CoreysParty.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AIO_CoreysParty.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AIO_CoreysParty.dir/flags.make

CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o: CMakeFiles/AIO_CoreysParty.dir/flags.make
CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o: ../Miscellaneous/AIO_CoreysParty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o -c /Users/tanavya.dimri/Desktop/Competitive-Programming/Miscellaneous/AIO_CoreysParty.cpp

CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanavya.dimri/Desktop/Competitive-Programming/Miscellaneous/AIO_CoreysParty.cpp > CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.i

CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanavya.dimri/Desktop/Competitive-Programming/Miscellaneous/AIO_CoreysParty.cpp -o CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.s

CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.requires:

.PHONY : CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.requires

CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.provides: CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.requires
	$(MAKE) -f CMakeFiles/AIO_CoreysParty.dir/build.make CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.provides.build
.PHONY : CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.provides

CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.provides.build: CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o


# Object files for target AIO_CoreysParty
AIO_CoreysParty_OBJECTS = \
"CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o"

# External object files for target AIO_CoreysParty
AIO_CoreysParty_EXTERNAL_OBJECTS =

AIO_CoreysParty: CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o
AIO_CoreysParty: CMakeFiles/AIO_CoreysParty.dir/build.make
AIO_CoreysParty: CMakeFiles/AIO_CoreysParty.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AIO_CoreysParty"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AIO_CoreysParty.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AIO_CoreysParty.dir/build: AIO_CoreysParty

.PHONY : CMakeFiles/AIO_CoreysParty.dir/build

CMakeFiles/AIO_CoreysParty.dir/requires: CMakeFiles/AIO_CoreysParty.dir/Miscellaneous/AIO_CoreysParty.cpp.o.requires

.PHONY : CMakeFiles/AIO_CoreysParty.dir/requires

CMakeFiles/AIO_CoreysParty.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AIO_CoreysParty.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AIO_CoreysParty.dir/clean

CMakeFiles/AIO_CoreysParty.dir/depend:
	cd /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug /Users/tanavya.dimri/Desktop/Competitive-Programming/cmake-build-debug/CMakeFiles/AIO_CoreysParty.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AIO_CoreysParty.dir/depend

