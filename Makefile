# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/oleg/Public/Oleg/course_2/ded/my_compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oleg/Public/Oleg/course_2/ded/my_compiler

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/oleg/Public/Oleg/course_2/ded/my_compiler/CMakeFiles /home/oleg/Public/Oleg/course_2/ded/my_compiler/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/oleg/Public/Oleg/course_2/ded/my_compiler/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named my_executor

# Build rule for target.
my_executor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 my_executor
.PHONY : my_executor

# fast build rule for target.
my_executor/fast:
	$(MAKE) -f CMakeFiles/my_executor.dir/build.make CMakeFiles/my_executor.dir/build
.PHONY : my_executor/fast

#=============================================================================
# Target rules for targets named my_compiler

# Build rule for target.
my_compiler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 my_compiler
.PHONY : my_compiler

# fast build rule for target.
my_compiler/fast:
	$(MAKE) -f CMakeFiles/my_compiler.dir/build.make CMakeFiles/my_compiler.dir/build
.PHONY : my_compiler/fast

#=============================================================================
# Target rules for targets named my_disassembler

# Build rule for target.
my_disassembler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 my_disassembler
.PHONY : my_disassembler

# fast build rule for target.
my_disassembler/fast:
	$(MAKE) -f CMakeFiles/my_disassembler.dir/build.make CMakeFiles/my_disassembler.dir/build
.PHONY : my_disassembler/fast

my_compiler.o: my_compiler.cpp.o

.PHONY : my_compiler.o

# target to build an object file
my_compiler.cpp.o:
	$(MAKE) -f CMakeFiles/my_compiler.dir/build.make CMakeFiles/my_compiler.dir/my_compiler.cpp.o
.PHONY : my_compiler.cpp.o

my_compiler.i: my_compiler.cpp.i

.PHONY : my_compiler.i

# target to preprocess a source file
my_compiler.cpp.i:
	$(MAKE) -f CMakeFiles/my_compiler.dir/build.make CMakeFiles/my_compiler.dir/my_compiler.cpp.i
.PHONY : my_compiler.cpp.i

my_compiler.s: my_compiler.cpp.s

.PHONY : my_compiler.s

# target to generate assembly for a file
my_compiler.cpp.s:
	$(MAKE) -f CMakeFiles/my_compiler.dir/build.make CMakeFiles/my_compiler.dir/my_compiler.cpp.s
.PHONY : my_compiler.cpp.s

my_disassembler.o: my_disassembler.cpp.o

.PHONY : my_disassembler.o

# target to build an object file
my_disassembler.cpp.o:
	$(MAKE) -f CMakeFiles/my_disassembler.dir/build.make CMakeFiles/my_disassembler.dir/my_disassembler.cpp.o
.PHONY : my_disassembler.cpp.o

my_disassembler.i: my_disassembler.cpp.i

.PHONY : my_disassembler.i

# target to preprocess a source file
my_disassembler.cpp.i:
	$(MAKE) -f CMakeFiles/my_disassembler.dir/build.make CMakeFiles/my_disassembler.dir/my_disassembler.cpp.i
.PHONY : my_disassembler.cpp.i

my_disassembler.s: my_disassembler.cpp.s

.PHONY : my_disassembler.s

# target to generate assembly for a file
my_disassembler.cpp.s:
	$(MAKE) -f CMakeFiles/my_disassembler.dir/build.make CMakeFiles/my_disassembler.dir/my_disassembler.cpp.s
.PHONY : my_disassembler.cpp.s

my_executor.o: my_executor.cpp.o

.PHONY : my_executor.o

# target to build an object file
my_executor.cpp.o:
	$(MAKE) -f CMakeFiles/my_executor.dir/build.make CMakeFiles/my_executor.dir/my_executor.cpp.o
.PHONY : my_executor.cpp.o

my_executor.i: my_executor.cpp.i

.PHONY : my_executor.i

# target to preprocess a source file
my_executor.cpp.i:
	$(MAKE) -f CMakeFiles/my_executor.dir/build.make CMakeFiles/my_executor.dir/my_executor.cpp.i
.PHONY : my_executor.cpp.i

my_executor.s: my_executor.cpp.s

.PHONY : my_executor.s

# target to generate assembly for a file
my_executor.cpp.s:
	$(MAKE) -f CMakeFiles/my_executor.dir/build.make CMakeFiles/my_executor.dir/my_executor.cpp.s
.PHONY : my_executor.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... my_executor"
	@echo "... my_compiler"
	@echo "... my_disassembler"
	@echo "... my_compiler.o"
	@echo "... my_compiler.i"
	@echo "... my_compiler.s"
	@echo "... my_disassembler.o"
	@echo "... my_disassembler.i"
	@echo "... my_disassembler.s"
	@echo "... my_executor.o"
	@echo "... my_executor.i"
	@echo "... my_executor.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
