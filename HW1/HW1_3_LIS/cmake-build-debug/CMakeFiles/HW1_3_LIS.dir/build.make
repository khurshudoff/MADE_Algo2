# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW1_3_LIS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW1_3_LIS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW1_3_LIS.dir/flags.make

CMakeFiles/HW1_3_LIS.dir/main.cpp.o: CMakeFiles/HW1_3_LIS.dir/flags.make
CMakeFiles/HW1_3_LIS.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW1_3_LIS.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW1_3_LIS.dir/main.cpp.o -c /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/main.cpp

CMakeFiles/HW1_3_LIS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW1_3_LIS.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/main.cpp > CMakeFiles/HW1_3_LIS.dir/main.cpp.i

CMakeFiles/HW1_3_LIS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW1_3_LIS.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/main.cpp -o CMakeFiles/HW1_3_LIS.dir/main.cpp.s

# Object files for target HW1_3_LIS
HW1_3_LIS_OBJECTS = \
"CMakeFiles/HW1_3_LIS.dir/main.cpp.o"

# External object files for target HW1_3_LIS
HW1_3_LIS_EXTERNAL_OBJECTS =

HW1_3_LIS: CMakeFiles/HW1_3_LIS.dir/main.cpp.o
HW1_3_LIS: CMakeFiles/HW1_3_LIS.dir/build.make
HW1_3_LIS: CMakeFiles/HW1_3_LIS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW1_3_LIS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW1_3_LIS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW1_3_LIS.dir/build: HW1_3_LIS

.PHONY : CMakeFiles/HW1_3_LIS.dir/build

CMakeFiles/HW1_3_LIS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW1_3_LIS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW1_3_LIS.dir/clean

CMakeFiles/HW1_3_LIS.dir/depend:
	cd /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug /Users/khurshudov/Desktop/MADE/Algo2/HW/HW1/HW1_3_LIS/cmake-build-debug/CMakeFiles/HW1_3_LIS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW1_3_LIS.dir/depend

