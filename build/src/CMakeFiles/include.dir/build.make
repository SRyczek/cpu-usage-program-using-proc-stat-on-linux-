# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seb/Desktop/project_tietoevry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seb/Desktop/project_tietoevry/build

# Include any dependencies generated for this target.
include src/CMakeFiles/include.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/include.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/include.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/include.dir/flags.make

src/CMakeFiles/include.dir/reader.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/reader.c.o: ../src/reader.c
src/CMakeFiles/include.dir/reader.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/include.dir/reader.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/reader.c.o -MF CMakeFiles/include.dir/reader.c.o.d -o CMakeFiles/include.dir/reader.c.o -c /home/seb/Desktop/project_tietoevry/src/reader.c

src/CMakeFiles/include.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/reader.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/reader.c > CMakeFiles/include.dir/reader.c.i

src/CMakeFiles/include.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/reader.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/reader.c -o CMakeFiles/include.dir/reader.c.s

# Object files for target include
include_OBJECTS = \
"CMakeFiles/include.dir/reader.c.o"

# External object files for target include
include_EXTERNAL_OBJECTS =

src/libinclude.a: src/CMakeFiles/include.dir/reader.c.o
src/libinclude.a: src/CMakeFiles/include.dir/build.make
src/libinclude.a: src/CMakeFiles/include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libinclude.a"
	cd /home/seb/Desktop/project_tietoevry/build/src && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean_target.cmake
	cd /home/seb/Desktop/project_tietoevry/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/include.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/include.dir/build: src/libinclude.a
.PHONY : src/CMakeFiles/include.dir/build

src/CMakeFiles/include.dir/clean:
	cd /home/seb/Desktop/project_tietoevry/build/src && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/include.dir/clean

src/CMakeFiles/include.dir/depend:
	cd /home/seb/Desktop/project_tietoevry/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seb/Desktop/project_tietoevry /home/seb/Desktop/project_tietoevry/src /home/seb/Desktop/project_tietoevry/build /home/seb/Desktop/project_tietoevry/build/src /home/seb/Desktop/project_tietoevry/build/src/CMakeFiles/include.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/include.dir/depend
