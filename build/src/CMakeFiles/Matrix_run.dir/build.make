# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ashish/Desktop/CPPMatrixLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ashish/Desktop/CPPMatrixLib/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Matrix_run.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Matrix_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Matrix_run.dir/flags.make

src/CMakeFiles/Matrix_run.dir/main.cpp.o: src/CMakeFiles/Matrix_run.dir/flags.make
src/CMakeFiles/Matrix_run.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/Desktop/CPPMatrixLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Matrix_run.dir/main.cpp.o"
	cd /home/ashish/Desktop/CPPMatrixLib/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Matrix_run.dir/main.cpp.o -c /home/ashish/Desktop/CPPMatrixLib/src/main.cpp

src/CMakeFiles/Matrix_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix_run.dir/main.cpp.i"
	cd /home/ashish/Desktop/CPPMatrixLib/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/Desktop/CPPMatrixLib/src/main.cpp > CMakeFiles/Matrix_run.dir/main.cpp.i

src/CMakeFiles/Matrix_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix_run.dir/main.cpp.s"
	cd /home/ashish/Desktop/CPPMatrixLib/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/Desktop/CPPMatrixLib/src/main.cpp -o CMakeFiles/Matrix_run.dir/main.cpp.s

src/CMakeFiles/Matrix_run.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/Matrix_run.dir/main.cpp.o.requires

src/CMakeFiles/Matrix_run.dir/main.cpp.o.provides: src/CMakeFiles/Matrix_run.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Matrix_run.dir/build.make src/CMakeFiles/Matrix_run.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/Matrix_run.dir/main.cpp.o.provides

src/CMakeFiles/Matrix_run.dir/main.cpp.o.provides.build: src/CMakeFiles/Matrix_run.dir/main.cpp.o


# Object files for target Matrix_run
Matrix_run_OBJECTS = \
"CMakeFiles/Matrix_run.dir/main.cpp.o"

# External object files for target Matrix_run
Matrix_run_EXTERNAL_OBJECTS =

src/Matrix_run: src/CMakeFiles/Matrix_run.dir/main.cpp.o
src/Matrix_run: src/CMakeFiles/Matrix_run.dir/build.make
src/Matrix_run: src/CMakeFiles/Matrix_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ashish/Desktop/CPPMatrixLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Matrix_run"
	cd /home/ashish/Desktop/CPPMatrixLib/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Matrix_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Matrix_run.dir/build: src/Matrix_run

.PHONY : src/CMakeFiles/Matrix_run.dir/build

src/CMakeFiles/Matrix_run.dir/requires: src/CMakeFiles/Matrix_run.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/Matrix_run.dir/requires

src/CMakeFiles/Matrix_run.dir/clean:
	cd /home/ashish/Desktop/CPPMatrixLib/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Matrix_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Matrix_run.dir/clean

src/CMakeFiles/Matrix_run.dir/depend:
	cd /home/ashish/Desktop/CPPMatrixLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ashish/Desktop/CPPMatrixLib /home/ashish/Desktop/CPPMatrixLib/src /home/ashish/Desktop/CPPMatrixLib/build /home/ashish/Desktop/CPPMatrixLib/build/src /home/ashish/Desktop/CPPMatrixLib/build/src/CMakeFiles/Matrix_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Matrix_run.dir/depend

