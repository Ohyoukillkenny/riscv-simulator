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
include CMakeFiles/emulator_ricv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/emulator_ricv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/emulator_ricv.dir/flags.make

CMakeFiles/emulator_ricv.dir/main.cpp.o: CMakeFiles/emulator_ricv.dir/flags.make
CMakeFiles/emulator_ricv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/emulator_ricv.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emulator_ricv.dir/main.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/main.cpp

CMakeFiles/emulator_ricv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emulator_ricv.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/main.cpp > CMakeFiles/emulator_ricv.dir/main.cpp.i

CMakeFiles/emulator_ricv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emulator_ricv.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/main.cpp -o CMakeFiles/emulator_ricv.dir/main.cpp.s

CMakeFiles/emulator_ricv.dir/alu.cpp.o: CMakeFiles/emulator_ricv.dir/flags.make
CMakeFiles/emulator_ricv.dir/alu.cpp.o: ../alu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/emulator_ricv.dir/alu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emulator_ricv.dir/alu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/alu.cpp

CMakeFiles/emulator_ricv.dir/alu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emulator_ricv.dir/alu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/alu.cpp > CMakeFiles/emulator_ricv.dir/alu.cpp.i

CMakeFiles/emulator_ricv.dir/alu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emulator_ricv.dir/alu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/alu.cpp -o CMakeFiles/emulator_ricv.dir/alu.cpp.s

CMakeFiles/emulator_ricv.dir/reg.cpp.o: CMakeFiles/emulator_ricv.dir/flags.make
CMakeFiles/emulator_ricv.dir/reg.cpp.o: ../reg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/emulator_ricv.dir/reg.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emulator_ricv.dir/reg.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/reg.cpp

CMakeFiles/emulator_ricv.dir/reg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emulator_ricv.dir/reg.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/reg.cpp > CMakeFiles/emulator_ricv.dir/reg.cpp.i

CMakeFiles/emulator_ricv.dir/reg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emulator_ricv.dir/reg.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/reg.cpp -o CMakeFiles/emulator_ricv.dir/reg.cpp.s

CMakeFiles/emulator_ricv.dir/cpu.cpp.o: CMakeFiles/emulator_ricv.dir/flags.make
CMakeFiles/emulator_ricv.dir/cpu.cpp.o: ../cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/emulator_ricv.dir/cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emulator_ricv.dir/cpu.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/cpu.cpp

CMakeFiles/emulator_ricv.dir/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emulator_ricv.dir/cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/cpu.cpp > CMakeFiles/emulator_ricv.dir/cpu.cpp.i

CMakeFiles/emulator_ricv.dir/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emulator_ricv.dir/cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/cpu.cpp -o CMakeFiles/emulator_ricv.dir/cpu.cpp.s

CMakeFiles/emulator_ricv.dir/mem.cpp.o: CMakeFiles/emulator_ricv.dir/flags.make
CMakeFiles/emulator_ricv.dir/mem.cpp.o: ../mem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/emulator_ricv.dir/mem.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/emulator_ricv.dir/mem.cpp.o -c /Users/klk/CLionProjects/riscv-simulator/mem.cpp

CMakeFiles/emulator_ricv.dir/mem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emulator_ricv.dir/mem.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/klk/CLionProjects/riscv-simulator/mem.cpp > CMakeFiles/emulator_ricv.dir/mem.cpp.i

CMakeFiles/emulator_ricv.dir/mem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emulator_ricv.dir/mem.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/klk/CLionProjects/riscv-simulator/mem.cpp -o CMakeFiles/emulator_ricv.dir/mem.cpp.s

# Object files for target emulator_ricv
emulator_ricv_OBJECTS = \
"CMakeFiles/emulator_ricv.dir/main.cpp.o" \
"CMakeFiles/emulator_ricv.dir/alu.cpp.o" \
"CMakeFiles/emulator_ricv.dir/reg.cpp.o" \
"CMakeFiles/emulator_ricv.dir/cpu.cpp.o" \
"CMakeFiles/emulator_ricv.dir/mem.cpp.o"

# External object files for target emulator_ricv
emulator_ricv_EXTERNAL_OBJECTS =

emulator_ricv: CMakeFiles/emulator_ricv.dir/main.cpp.o
emulator_ricv: CMakeFiles/emulator_ricv.dir/alu.cpp.o
emulator_ricv: CMakeFiles/emulator_ricv.dir/reg.cpp.o
emulator_ricv: CMakeFiles/emulator_ricv.dir/cpu.cpp.o
emulator_ricv: CMakeFiles/emulator_ricv.dir/mem.cpp.o
emulator_ricv: CMakeFiles/emulator_ricv.dir/build.make
emulator_ricv: CMakeFiles/emulator_ricv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable emulator_ricv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emulator_ricv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/emulator_ricv.dir/build: emulator_ricv

.PHONY : CMakeFiles/emulator_ricv.dir/build

CMakeFiles/emulator_ricv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/emulator_ricv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/emulator_ricv.dir/clean

CMakeFiles/emulator_ricv.dir/depend:
	cd /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug /Users/klk/CLionProjects/riscv-simulator/cmake-build-debug/CMakeFiles/emulator_ricv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/emulator_ricv.dir/depend

