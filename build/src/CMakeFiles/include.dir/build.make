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

src/CMakeFiles/include.dir/global_variables.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/global_variables.c.o: ../src/global_variables.c
src/CMakeFiles/include.dir/global_variables.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/include.dir/global_variables.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/global_variables.c.o -MF CMakeFiles/include.dir/global_variables.c.o.d -o CMakeFiles/include.dir/global_variables.c.o -c /home/seb/Desktop/project_tietoevry/src/global_variables.c

src/CMakeFiles/include.dir/global_variables.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/global_variables.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/global_variables.c > CMakeFiles/include.dir/global_variables.c.i

src/CMakeFiles/include.dir/global_variables.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/global_variables.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/global_variables.c -o CMakeFiles/include.dir/global_variables.c.s

src/CMakeFiles/include.dir/analyzer.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/analyzer.c.o: ../src/analyzer.c
src/CMakeFiles/include.dir/analyzer.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/include.dir/analyzer.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/analyzer.c.o -MF CMakeFiles/include.dir/analyzer.c.o.d -o CMakeFiles/include.dir/analyzer.c.o -c /home/seb/Desktop/project_tietoevry/src/analyzer.c

src/CMakeFiles/include.dir/analyzer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/analyzer.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/analyzer.c > CMakeFiles/include.dir/analyzer.c.i

src/CMakeFiles/include.dir/analyzer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/analyzer.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/analyzer.c -o CMakeFiles/include.dir/analyzer.c.s

src/CMakeFiles/include.dir/printer.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/printer.c.o: ../src/printer.c
src/CMakeFiles/include.dir/printer.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/include.dir/printer.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/printer.c.o -MF CMakeFiles/include.dir/printer.c.o.d -o CMakeFiles/include.dir/printer.c.o -c /home/seb/Desktop/project_tietoevry/src/printer.c

src/CMakeFiles/include.dir/printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/printer.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/printer.c > CMakeFiles/include.dir/printer.c.i

src/CMakeFiles/include.dir/printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/printer.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/printer.c -o CMakeFiles/include.dir/printer.c.s

src/CMakeFiles/include.dir/watchDog.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/watchDog.c.o: ../src/watchDog.c
src/CMakeFiles/include.dir/watchDog.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/include.dir/watchDog.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/watchDog.c.o -MF CMakeFiles/include.dir/watchDog.c.o.d -o CMakeFiles/include.dir/watchDog.c.o -c /home/seb/Desktop/project_tietoevry/src/watchDog.c

src/CMakeFiles/include.dir/watchDog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/watchDog.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/watchDog.c > CMakeFiles/include.dir/watchDog.c.i

src/CMakeFiles/include.dir/watchDog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/watchDog.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/watchDog.c -o CMakeFiles/include.dir/watchDog.c.s

src/CMakeFiles/include.dir/logger.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/logger.c.o: ../src/logger.c
src/CMakeFiles/include.dir/logger.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/include.dir/logger.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/logger.c.o -MF CMakeFiles/include.dir/logger.c.o.d -o CMakeFiles/include.dir/logger.c.o -c /home/seb/Desktop/project_tietoevry/src/logger.c

src/CMakeFiles/include.dir/logger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/logger.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/logger.c > CMakeFiles/include.dir/logger.c.i

src/CMakeFiles/include.dir/logger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/logger.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/logger.c -o CMakeFiles/include.dir/logger.c.s

src/CMakeFiles/include.dir/reader.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/reader.c.o: ../src/reader.c
src/CMakeFiles/include.dir/reader.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/include.dir/reader.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/reader.c.o -MF CMakeFiles/include.dir/reader.c.o.d -o CMakeFiles/include.dir/reader.c.o -c /home/seb/Desktop/project_tietoevry/src/reader.c

src/CMakeFiles/include.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/reader.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/reader.c > CMakeFiles/include.dir/reader.c.i

src/CMakeFiles/include.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/reader.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/reader.c -o CMakeFiles/include.dir/reader.c.s

src/CMakeFiles/include.dir/buffer.c.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/buffer.c.o: ../src/buffer.c
src/CMakeFiles/include.dir/buffer.c.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/include.dir/buffer.c.o"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/include.dir/buffer.c.o -MF CMakeFiles/include.dir/buffer.c.o.d -o CMakeFiles/include.dir/buffer.c.o -c /home/seb/Desktop/project_tietoevry/src/buffer.c

src/CMakeFiles/include.dir/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/buffer.c.i"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seb/Desktop/project_tietoevry/src/buffer.c > CMakeFiles/include.dir/buffer.c.i

src/CMakeFiles/include.dir/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/buffer.c.s"
	cd /home/seb/Desktop/project_tietoevry/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seb/Desktop/project_tietoevry/src/buffer.c -o CMakeFiles/include.dir/buffer.c.s

# Object files for target include
include_OBJECTS = \
"CMakeFiles/include.dir/global_variables.c.o" \
"CMakeFiles/include.dir/analyzer.c.o" \
"CMakeFiles/include.dir/printer.c.o" \
"CMakeFiles/include.dir/watchDog.c.o" \
"CMakeFiles/include.dir/logger.c.o" \
"CMakeFiles/include.dir/reader.c.o" \
"CMakeFiles/include.dir/buffer.c.o"

# External object files for target include
include_EXTERNAL_OBJECTS =

src/libinclude.a: src/CMakeFiles/include.dir/global_variables.c.o
src/libinclude.a: src/CMakeFiles/include.dir/analyzer.c.o
src/libinclude.a: src/CMakeFiles/include.dir/printer.c.o
src/libinclude.a: src/CMakeFiles/include.dir/watchDog.c.o
src/libinclude.a: src/CMakeFiles/include.dir/logger.c.o
src/libinclude.a: src/CMakeFiles/include.dir/reader.c.o
src/libinclude.a: src/CMakeFiles/include.dir/buffer.c.o
src/libinclude.a: src/CMakeFiles/include.dir/build.make
src/libinclude.a: src/CMakeFiles/include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seb/Desktop/project_tietoevry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C static library libinclude.a"
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

