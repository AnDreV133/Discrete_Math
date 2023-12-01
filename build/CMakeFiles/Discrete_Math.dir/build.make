# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Repositories\Discrete_Math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Repositories\Discrete_Math\build

# Include any dependencies generated for this target.
include CMakeFiles/Discrete_Math.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Discrete_Math.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Discrete_Math.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Discrete_Math.dir/flags.make

CMakeFiles/Discrete_Math.dir/main.cpp.obj: CMakeFiles/Discrete_Math.dir/flags.make
CMakeFiles/Discrete_Math.dir/main.cpp.obj: D:/Repositories/Discrete_Math/main.cpp
CMakeFiles/Discrete_Math.dir/main.cpp.obj: CMakeFiles/Discrete_Math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Repositories\Discrete_Math\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Discrete_Math.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Discrete_Math.dir/main.cpp.obj -MF CMakeFiles\Discrete_Math.dir\main.cpp.obj.d -o CMakeFiles\Discrete_Math.dir\main.cpp.obj -c D:\Repositories\Discrete_Math\main.cpp

CMakeFiles/Discrete_Math.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Discrete_Math.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Repositories\Discrete_Math\main.cpp > CMakeFiles\Discrete_Math.dir\main.cpp.i

CMakeFiles/Discrete_Math.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Discrete_Math.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Repositories\Discrete_Math\main.cpp -o CMakeFiles\Discrete_Math.dir\main.cpp.s

# Object files for target Discrete_Math
Discrete_Math_OBJECTS = \
"CMakeFiles/Discrete_Math.dir/main.cpp.obj"

# External object files for target Discrete_Math
Discrete_Math_EXTERNAL_OBJECTS =

Discrete_Math.exe: CMakeFiles/Discrete_Math.dir/main.cpp.obj
Discrete_Math.exe: CMakeFiles/Discrete_Math.dir/build.make
Discrete_Math.exe: libtest.a
Discrete_Math.exe: libalg.a
Discrete_Math.exe: libRelation.a
Discrete_Math.exe: libTransitivityClosureExperiment.a
Discrete_Math.exe: libSetFactor.a
Discrete_Math.exe: libOrderedSet.a
Discrete_Math.exe: CMakeFiles/Discrete_Math.dir/linkLibs.rsp
Discrete_Math.exe: CMakeFiles/Discrete_Math.dir/objects1.rsp
Discrete_Math.exe: CMakeFiles/Discrete_Math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Repositories\Discrete_Math\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Discrete_Math.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Discrete_Math.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Discrete_Math.dir/build: Discrete_Math.exe
.PHONY : CMakeFiles/Discrete_Math.dir/build

CMakeFiles/Discrete_Math.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Discrete_Math.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Discrete_Math.dir/clean

CMakeFiles/Discrete_Math.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Repositories\Discrete_Math D:\Repositories\Discrete_Math D:\Repositories\Discrete_Math\build D:\Repositories\Discrete_Math\build D:\Repositories\Discrete_Math\build\CMakeFiles\Discrete_Math.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Discrete_Math.dir/depend

