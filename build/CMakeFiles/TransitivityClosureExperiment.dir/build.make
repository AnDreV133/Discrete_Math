# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files (x86)/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "T:/c github pc/Discrete_Math"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "T:/c github pc/Discrete_Math/build"

# Include any dependencies generated for this target.
include CMakeFiles/TransitivityClosureExperiment.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TransitivityClosureExperiment.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TransitivityClosureExperiment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TransitivityClosureExperiment.dir/flags.make

CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj: CMakeFiles/TransitivityClosureExperiment.dir/flags.make
CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj: T:/c\ github\ pc/Discrete_Math/lab3.2/TransitivityClosureExperiment.cpp
CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj: CMakeFiles/TransitivityClosureExperiment.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="T:/c github pc/Discrete_Math/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj"
	C:/Users/dmitr/gcc/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj -MF CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj.d -o CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj -c "T:/c github pc/Discrete_Math/lab3.2/TransitivityClosureExperiment.cpp"

CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.i"
	C:/Users/dmitr/gcc/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "T:/c github pc/Discrete_Math/lab3.2/TransitivityClosureExperiment.cpp" > CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.i

CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.s"
	C:/Users/dmitr/gcc/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "T:/c github pc/Discrete_Math/lab3.2/TransitivityClosureExperiment.cpp" -o CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.s

# Object files for target TransitivityClosureExperiment
TransitivityClosureExperiment_OBJECTS = \
"CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj"

# External object files for target TransitivityClosureExperiment
TransitivityClosureExperiment_EXTERNAL_OBJECTS =

libTransitivityClosureExperiment.a: CMakeFiles/TransitivityClosureExperiment.dir/lab3.2/TransitivityClosureExperiment.cpp.obj
libTransitivityClosureExperiment.a: CMakeFiles/TransitivityClosureExperiment.dir/build.make
libTransitivityClosureExperiment.a: CMakeFiles/TransitivityClosureExperiment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="T:/c github pc/Discrete_Math/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTransitivityClosureExperiment.a"
	$(CMAKE_COMMAND) -P CMakeFiles/TransitivityClosureExperiment.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TransitivityClosureExperiment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TransitivityClosureExperiment.dir/build: libTransitivityClosureExperiment.a
.PHONY : CMakeFiles/TransitivityClosureExperiment.dir/build

CMakeFiles/TransitivityClosureExperiment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TransitivityClosureExperiment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TransitivityClosureExperiment.dir/clean

CMakeFiles/TransitivityClosureExperiment.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "T:/c github pc/Discrete_Math" "T:/c github pc/Discrete_Math" "T:/c github pc/Discrete_Math/build" "T:/c github pc/Discrete_Math/build" "T:/c github pc/Discrete_Math/build/CMakeFiles/TransitivityClosureExperiment.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/TransitivityClosureExperiment.dir/depend

