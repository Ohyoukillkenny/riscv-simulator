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
CMAKE_BINARY_DIR = /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestALU.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestALU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestALU.dir/flags.make

CMakeFiles/TestALU.dir/test/test-alu.cpp.o: CMakeFiles/TestALU.dir/flags.make
CMakeFiles/TestALU.dir/test/test-alu.cpp.o: ../test/test-alu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestALU.dir/test/test-alu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestALU.dir/test/test-alu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/test/test-alu.cpp

CMakeFiles/TestALU.dir/test/test-alu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestALU.dir/test/test-alu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/test/test-alu.cpp > CMakeFiles/TestALU.dir/test/test-alu.cpp.i

CMakeFiles/TestALU.dir/test/test-alu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestALU.dir/test/test-alu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/test/test-alu.cpp -o CMakeFiles/TestALU.dir/test/test-alu.cpp.s

CMakeFiles/TestALU.dir/alu.cpp.o: CMakeFiles/TestALU.dir/flags.make
CMakeFiles/TestALU.dir/alu.cpp.o: ../alu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestALU.dir/alu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestALU.dir/alu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/alu.cpp

CMakeFiles/TestALU.dir/alu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestALU.dir/alu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/alu.cpp > CMakeFiles/TestALU.dir/alu.cpp.i

CMakeFiles/TestALU.dir/alu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestALU.dir/alu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/alu.cpp -o CMakeFiles/TestALU.dir/alu.cpp.s

CMakeFiles/TestALU.dir/reg.cpp.o: CMakeFiles/TestALU.dir/flags.make
CMakeFiles/TestALU.dir/reg.cpp.o: ../reg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TestALU.dir/reg.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestALU.dir/reg.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/reg.cpp

CMakeFiles/TestALU.dir/reg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestALU.dir/reg.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/reg.cpp > CMakeFiles/TestALU.dir/reg.cpp.i

CMakeFiles/TestALU.dir/reg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestALU.dir/reg.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/reg.cpp -o CMakeFiles/TestALU.dir/reg.cpp.s

CMakeFiles/TestALU.dir/cpu.cpp.o: CMakeFiles/TestALU.dir/flags.make
CMakeFiles/TestALU.dir/cpu.cpp.o: ../cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TestALU.dir/cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestALU.dir/cpu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/cpu.cpp

CMakeFiles/TestALU.dir/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestALU.dir/cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/cpu.cpp > CMakeFiles/TestALU.dir/cpu.cpp.i

CMakeFiles/TestALU.dir/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestALU.dir/cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/cpu.cpp -o CMakeFiles/TestALU.dir/cpu.cpp.s

CMakeFiles/TestALU.dir/test/test-cpu.cpp.o: CMakeFiles/TestALU.dir/flags.make
CMakeFiles/TestALU.dir/test/test-cpu.cpp.o: ../test/test-cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TestALU.dir/test/test-cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestALU.dir/test/test-cpu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/test/test-cpu.cpp

CMakeFiles/TestALU.dir/test/test-cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestALU.dir/test/test-cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/test/test-cpu.cpp > CMakeFiles/TestALU.dir/test/test-cpu.cpp.i

CMakeFiles/TestALU.dir/test/test-cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestALU.dir/test/test-cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/test/test-cpu.cpp -o CMakeFiles/TestALU.dir/test/test-cpu.cpp.s

# Object files for target TestALU
TestALU_OBJECTS = \
"CMakeFiles/TestALU.dir/test/test-alu.cpp.o" \
"CMakeFiles/TestALU.dir/alu.cpp.o" \
"CMakeFiles/TestALU.dir/reg.cpp.o" \
"CMakeFiles/TestALU.dir/cpu.cpp.o" \
"CMakeFiles/TestALU.dir/test/test-cpu.cpp.o"

# External object files for target TestALU
TestALU_EXTERNAL_OBJECTS =

TestALU: CMakeFiles/TestALU.dir/test/test-alu.cpp.o
TestALU: CMakeFiles/TestALU.dir/alu.cpp.o
TestALU: CMakeFiles/TestALU.dir/reg.cpp.o
TestALU: CMakeFiles/TestALU.dir/cpu.cpp.o
TestALU: CMakeFiles/TestALU.dir/test/test-cpu.cpp.o
TestALU: CMakeFiles/TestALU.dir/build.make
TestALU: CMakeFiles/TestALU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable TestALU"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestALU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestALU.dir/build: TestALU

.PHONY : CMakeFiles/TestALU.dir/build

CMakeFiles/TestALU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestALU.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestALU.dir/clean

CMakeFiles/TestALU.dir/depend:
	cd /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles/TestALU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestALU.dir/depend

