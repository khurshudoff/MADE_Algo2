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
CMAKE_SOURCE_DIR = /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/flags.make

CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.o: CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/flags.make
CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.o -c /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/main.cpp

CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/main.cpp > CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.i

CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/main.cpp -o CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.s

# Object files for target HW6_5_samoe_deshevoe_rebro
HW6_5_samoe_deshevoe_rebro_OBJECTS = \
"CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.o"

# External object files for target HW6_5_samoe_deshevoe_rebro
HW6_5_samoe_deshevoe_rebro_EXTERNAL_OBJECTS =

HW6_5_samoe_deshevoe_rebro: CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/main.cpp.o
HW6_5_samoe_deshevoe_rebro: CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/build.make
HW6_5_samoe_deshevoe_rebro: CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW6_5_samoe_deshevoe_rebro"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/build: HW6_5_samoe_deshevoe_rebro

.PHONY : CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/build

CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/clean

CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/depend:
	cd /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug /Users/khurshudov/Desktop/MADE/Algo2/HW/HW6/HW6_5_samoe_deshevoe_rebro/cmake-build-debug/CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW6_5_samoe_deshevoe_rebro.dir/depend
