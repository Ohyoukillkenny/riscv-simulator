# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/klk/CLionProjects/riscv-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/klk/CLionProjects/riscv-simulator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.12.4/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/Cellar/cmake/3.12.4/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/klk/CLionProjects/riscv-simulator/CMakeFiles /Users/klk/CLionProjects/riscv-simulator/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/klk/CLionProjects/riscv-simulator/CMakeFiles 0
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
# Target rules for targets named TestAll

# Build rule for target.
TestAll: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TestAll
.PHONY : TestAll

# fast build rule for target.
TestAll/fast:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/build
.PHONY : TestAll/fast

#=============================================================================
# Target rules for targets named risc-simulator

# Build rule for target.
risc-simulator: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 risc-simulator
.PHONY : risc-simulator

# fast build rule for target.
risc-simulator/fast:
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/build
.PHONY : risc-simulator/fast

cpu/alu.o: cpu/alu.cpp.o

.PHONY : cpu/alu.o

# target to build an object file
cpu/alu.cpp.o:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/alu.cpp.o
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o
.PHONY : cpu/alu.cpp.o

cpu/alu.i: cpu/alu.cpp.i

.PHONY : cpu/alu.i

# target to preprocess a source file
cpu/alu.cpp.i:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/alu.cpp.i
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/alu.cpp.i
.PHONY : cpu/alu.cpp.i

cpu/alu.s: cpu/alu.cpp.s

.PHONY : cpu/alu.s

# target to generate assembly for a file
cpu/alu.cpp.s:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/alu.cpp.s
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/alu.cpp.s
.PHONY : cpu/alu.cpp.s

cpu/cpu.o: cpu/cpu.cpp.o

.PHONY : cpu/cpu.o

# target to build an object file
cpu/cpu.cpp.o:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/cpu.cpp.o
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o
.PHONY : cpu/cpu.cpp.o

cpu/cpu.i: cpu/cpu.cpp.i

.PHONY : cpu/cpu.i

# target to preprocess a source file
cpu/cpu.cpp.i:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/cpu.cpp.i
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.i
.PHONY : cpu/cpu.cpp.i

cpu/cpu.s: cpu/cpu.cpp.s

.PHONY : cpu/cpu.s

# target to generate assembly for a file
cpu/cpu.cpp.s:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/cpu.cpp.s
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.s
.PHONY : cpu/cpu.cpp.s

cpu/reg.o: cpu/reg.cpp.o

.PHONY : cpu/reg.o

# target to build an object file
cpu/reg.cpp.o:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/reg.cpp.o
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o
.PHONY : cpu/reg.cpp.o

cpu/reg.i: cpu/reg.cpp.i

.PHONY : cpu/reg.i

# target to preprocess a source file
cpu/reg.cpp.i:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/reg.cpp.i
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/reg.cpp.i
.PHONY : cpu/reg.cpp.i

cpu/reg.s: cpu/reg.cpp.s

.PHONY : cpu/reg.s

# target to generate assembly for a file
cpu/reg.cpp.s:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/cpu/reg.cpp.s
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/cpu/reg.cpp.s
.PHONY : cpu/reg.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/main.cpp.s
.PHONY : main.cpp.s

mem/mem.o: mem/mem.cpp.o

.PHONY : mem/mem.o

# target to build an object file
mem/mem.cpp.o:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/mem/mem.cpp.o
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/mem/mem.cpp.o
.PHONY : mem/mem.cpp.o

mem/mem.i: mem/mem.cpp.i

.PHONY : mem/mem.i

# target to preprocess a source file
mem/mem.cpp.i:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/mem/mem.cpp.i
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/mem/mem.cpp.i
.PHONY : mem/mem.cpp.i

mem/mem.s: mem/mem.cpp.s

.PHONY : mem/mem.s

# target to generate assembly for a file
mem/mem.cpp.s:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/mem/mem.cpp.s
	$(MAKE) -f CMakeFiles/risc-simulator.dir/build.make CMakeFiles/risc-simulator.dir/mem/mem.cpp.s
.PHONY : mem/mem.cpp.s

test/test-alu.o: test/test-alu.cpp.o

.PHONY : test/test-alu.o

# target to build an object file
test/test-alu.cpp.o:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/test/test-alu.cpp.o
.PHONY : test/test-alu.cpp.o

test/test-alu.i: test/test-alu.cpp.i

.PHONY : test/test-alu.i

# target to preprocess a source file
test/test-alu.cpp.i:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/test/test-alu.cpp.i
.PHONY : test/test-alu.cpp.i

test/test-alu.s: test/test-alu.cpp.s

.PHONY : test/test-alu.s

# target to generate assembly for a file
test/test-alu.cpp.s:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/test/test-alu.cpp.s
.PHONY : test/test-alu.cpp.s

test/test-cpu.o: test/test-cpu.cpp.o

.PHONY : test/test-cpu.o

# target to build an object file
test/test-cpu.cpp.o:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/test/test-cpu.cpp.o
.PHONY : test/test-cpu.cpp.o

test/test-cpu.i: test/test-cpu.cpp.i

.PHONY : test/test-cpu.i

# target to preprocess a source file
test/test-cpu.cpp.i:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/test/test-cpu.cpp.i
.PHONY : test/test-cpu.cpp.i

test/test-cpu.s: test/test-cpu.cpp.s

.PHONY : test/test-cpu.s

# target to generate assembly for a file
test/test-cpu.cpp.s:
	$(MAKE) -f CMakeFiles/TestAll.dir/build.make CMakeFiles/TestAll.dir/test/test-cpu.cpp.s
.PHONY : test/test-cpu.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... TestAll"
	@echo "... risc-simulator"
	@echo "... cpu/alu.o"
	@echo "... cpu/alu.i"
	@echo "... cpu/alu.s"
	@echo "... cpu/cpu.o"
	@echo "... cpu/cpu.i"
	@echo "... cpu/cpu.s"
	@echo "... cpu/reg.o"
	@echo "... cpu/reg.i"
	@echo "... cpu/reg.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mem/mem.o"
	@echo "... mem/mem.i"
	@echo "... mem/mem.s"
	@echo "... test/test-alu.o"
	@echo "... test/test-alu.i"
	@echo "... test/test-alu.s"
	@echo "... test/test-cpu.o"
	@echo "... test/test-cpu.i"
	@echo "... test/test-cpu.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

