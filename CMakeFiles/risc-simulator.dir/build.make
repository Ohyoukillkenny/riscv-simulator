# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/klk/CLionProjects/riscv-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/klk/CLionProjects/riscv-simulator

# Include any dependencies generated for this target.
include CMakeFiles/risc-simulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/risc-simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/risc-simulator.dir/flags.make

CMakeFiles/risc-simulator.dir/main.cpp.o: CMakeFiles/risc-simulator.dir/flags.make
CMakeFiles/risc-simulator.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/risc-simulator.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/risc-simulator.dir/main.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/main.cpp

CMakeFiles/risc-simulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/risc-simulator.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/main.cpp > CMakeFiles/risc-simulator.dir/main.cpp.i

CMakeFiles/risc-simulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/risc-simulator.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/main.cpp -o CMakeFiles/risc-simulator.dir/main.cpp.s

CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o: CMakeFiles/risc-simulator.dir/flags.make
CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o: cpu/alu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/cpu/alu.cpp

CMakeFiles/risc-simulator.dir/cpu/alu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/risc-simulator.dir/cpu/alu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/cpu/alu.cpp > CMakeFiles/risc-simulator.dir/cpu/alu.cpp.i

CMakeFiles/risc-simulator.dir/cpu/alu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/risc-simulator.dir/cpu/alu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/cpu/alu.cpp -o CMakeFiles/risc-simulator.dir/cpu/alu.cpp.s

CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o: CMakeFiles/risc-simulator.dir/flags.make
CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o: cpu/reg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/cpu/reg.cpp

CMakeFiles/risc-simulator.dir/cpu/reg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/risc-simulator.dir/cpu/reg.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/cpu/reg.cpp > CMakeFiles/risc-simulator.dir/cpu/reg.cpp.i

CMakeFiles/risc-simulator.dir/cpu/reg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/risc-simulator.dir/cpu/reg.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/cpu/reg.cpp -o CMakeFiles/risc-simulator.dir/cpu/reg.cpp.s

CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o: CMakeFiles/risc-simulator.dir/flags.make
CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o: cpu/cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/cpu/cpu.cpp

CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/cpu/cpu.cpp > CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.i

CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/cpu/cpu.cpp -o CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.s

CMakeFiles/risc-simulator.dir/mem/mem.cpp.o: CMakeFiles/risc-simulator.dir/flags.make
CMakeFiles/risc-simulator.dir/mem/mem.cpp.o: mem/mem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/risc-simulator.dir/mem/mem.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/risc-simulator.dir/mem/mem.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/mem/mem.cpp

CMakeFiles/risc-simulator.dir/mem/mem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/risc-simulator.dir/mem/mem.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/mem/mem.cpp > CMakeFiles/risc-simulator.dir/mem/mem.cpp.i

CMakeFiles/risc-simulator.dir/mem/mem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/risc-simulator.dir/mem/mem.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/mem/mem.cpp -o CMakeFiles/risc-simulator.dir/mem/mem.cpp.s

# Object files for target risc-simulator
risc__simulator_OBJECTS = \
"CMakeFiles/risc-simulator.dir/main.cpp.o" \
"CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o" \
"CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o" \
"CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o" \
"CMakeFiles/risc-simulator.dir/mem/mem.cpp.o"

# External object files for target risc-simulator
risc__simulator_EXTERNAL_OBJECTS =

risc-simulator: CMakeFiles/risc-simulator.dir/main.cpp.o
risc-simulator: CMakeFiles/risc-simulator.dir/cpu/alu.cpp.o
risc-simulator: CMakeFiles/risc-simulator.dir/cpu/reg.cpp.o
risc-simulator: CMakeFiles/risc-simulator.dir/cpu/cpu.cpp.o
risc-simulator: CMakeFiles/risc-simulator.dir/mem/mem.cpp.o
risc-simulator: CMakeFiles/risc-simulator.dir/build.make
risc-simulator: CMakeFiles/risc-simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/klk/CLionProjects/riscv-simulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable risc-simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/risc-simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/risc-simulator.dir/build: risc-simulator

.PHONY : CMakeFiles/risc-simulator.dir/build

CMakeFiles/risc-simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/risc-simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/risc-simulator.dir/clean

CMakeFiles/risc-simulator.dir/depend:
	cd /Users/klk/CLionProjects/riscv-simulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator/CMakeFiles/risc-simulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/risc-simulator.dir/depend

