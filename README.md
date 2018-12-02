# RISC-V Simulator

## Introduction

This is an implementation of the RISC-V simulator, finished as a term project for COMP 554 at Rice University. The RISC-V Instruction Manual is located at:  https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf

RISC-V is a new instruction set architecture (ISA) that was originally designed to support computer architecture research and education, but which also has the potential to become a standard free and open architecture for industry implementations. 
As the RISC-V had become more and more popular, in this project, we simulated a CPU under RISC-V architecture which could process the binary instructions from RISC-V Instruction set. Also, we implemented a translator to translate RISC-V assembly codes to binary instructions. Thus, in simulation, people could also directly feed our simulator with RISC-V assembly codes whose writing mannual could be viewed in the **Details about Implemented Instructions**.

The tutorial of this project is presented in the **Tutorial**, including the installation and the usage of RISC-V Simulator.

## How Does it Work

### Instruction Feeding

This project provides a simple RISC-V assembly translator which compiles assembly code to binary codes, then, the simulated CPU can process the binary instructions according to RISC-V ISA. Here, we presented an example to illustrate how to feed our CPU with instructions. First of all, we gave the pseudo-code of the program that will be fed to CPU:

```
a = 0;
b = 20; 
a = a + 1;
if a < b, branching back to a = a + 1;
store a to memory[0x00000000];
load memory[0x00000000] to c;
```

Basically, what we wrote was a loop in which we increased the value of variable `a` until it was greater or equal than the value of `b`. After the loop, we simply saved the value of `a` to the memory at address of `0x00000000` and loaded this value to another variable named as `c`.

According to the pseudo-code, we gave the RISC-V assembly code in **assem.txt** as below:

```
addi x5, x0, 0
addi x6, x6, 20
addi x5, x5, 1
blt  x5, x6, -4
sw   x5, 0(x0)
lw   x7, 0(x0)
```

Then, by typing `./risc-translate assem.txt exe.txt` on command line terminal, the RISC-V assembly code will be translated to binary strings in the **exe.txt**.

We also gave the codes in **exe.txt** as below:

```
00000000000000000000001010010011
00000001010000110000001100010011
00000000000100101000001010010011
11111110011000101100111011100011
00000000010100000010000000100011
00000000000000000010001110000011
```

Then, we used a program, **main.cpp** in this project, to read the binary-like instructions into instruction memory. 

To be noticed, this project provided `./risc-simulator -a assem.txt` to feed the CPU directly with RISC-V assembly codes, and our project also supported feeding the CPU with binary strings with `./risc-simulator exe.txt`, and the details about instruction feeding could be found in **main.cpp**.

### Instruction Processing

After the 0-1 strings from the text file was loaded into the program as binary instructions, our simulated CPU would start to process these instructions.

First of all, our CPU would use its PC register to fetch instructions from the instruction memory, and we used method called `get_pc_val()`in `cpu` class to implement this function of our CPU.

Then, we decoded the fetched instructions according to RISC-V specification. For instance, the CPU would parse the bits from 0 to 7 as opcode to figure out the type of the instruction. Once the type of the operation was determined, the CPU could further decode other components in the instruction, such as immediate number, destination register, and etc.

As the instruction had been decoded, the CPU will start to calculate, i.e., execute the instruction. To be noticed, in our implementation of CPU, we also simulated the ALU by `alu` class. Therefore, you could see that when our CPU executed instructions, it would transmit binary sequences to ALU to finish the calculation, i.e., in our code, `cpu` instance would call methods from `alu` class to do the calculation.

After that, for L-Type and S-Type instructions, CPU will visit the memory to load or save data. In our code, we used the `mem` class to simulate the memory in a computer, and the CPU could call the get and save methods in `mem` class to load or save data. Moreover, for J-Type and B-Type instructions, the value in the PC register would be modified by the executing results, thereby the jumping and branching instructions could be realized. For instructions of other types, after finishing processing an instruction, the value of PC register would automatically plus 4.

### Status Monitoring

We provided `print()` method for CPU to print out the status of each register in the CPU. Here is an example for the printed register status after our simulated CPU processed the instructions from the **assem.txt**.

```
== The state of the CPU ==
x0  : 0
x1  : 0
x2  : 0
x3  : 0
x4  : 0
x5  : 20
x6  : 20
x7  : 20
x8  : 0

...

x31 : 0
PC has value : 0xb00000000000000000000000000011000
```

For memory status monitoring, we provided the `mem_peep()` method in `cpu` class. It would consume the memory address as input and return the value at that address as output.

## Details about Implemented Instructions

In this project, we mainly focused on **RV32I Base Integer Instruction Set**, and we used a table to specify the features in RV32I instruction set with their implementing status as below:

| Symbol  | Format                | Description                        | STATUS      |
| ------- | --------------------- | ---------------------------------- | ----------- |
| LUI     | `LUI rd,imm`          | Load Upper Immediate               | Miss        |
| AUIPC   | `AUIPC rd,offset`     | Add Upper Immediate to PC          | Miss        |
| JAL     | `JAL rd,offset`       | Jump and Link                      | Implemented |
| JALR    | `JALR rd,rs1,offset`  | Jump and Link Register             | Implemented |
| BEQ     | `BEQ rs1,rs2,offset`  | Branch Equal                       | Implemented |
| BNE     | `BNE rs1,rs2,offset`  | Branch Not Equal                   | Implemented |
| BLT     | `BLT rs1,rs2,offset`  | Branch Less Than                   | Implemented |
| BGE     | `BGE rs1,rs2,offset`  | Branch Greater than Equal          | Implemented |
| BLTU    | `BLTU rs1,rs2,offset` | Branch Less Than Unsigned          | Implemented |
| BGEU    | `BGEU rs1,rs2,offset` | Branch Greater than Equal Unsigned | Implemented |
| LB      | `LB rd,offset(rs1)`   | Load Byte                          | Implemented |
| LH      | `LH rd,offset(rs1)`   | Load Half                          | Implemented |
| LW      | `LW rd,offset(rs1)`   | Load Word                          | Implemented |
| LBU     | `LBU rd,offset(rs1)`  | Load Byte Unsigned                 | Implemented |
| LHU     | `LHU rd,offset(rs1)`  | Load Half Unsigned                 | Implemented |
| SB      | `SB rs2,offset(rs1)`  | Store Byte                         | Implemented |
| SH      | `SH rs2,offset(rs1)`  | Store Half                         | Implemented |
| SW      | `SW rs2,offset(rs1)`  | Store Word                         | Implemented |
| ADDI    | `ADDI rd,rs1,imm`     | Add Immediate                      | Implemented |
| SLTI    | `SLTI rd,rs1,imm`     | Set Less Than Immediate            | Implemented |
| SLTIU   | `SLTIU rd,rs1,imm`    | Set Less Than Immediate Unsigned   | Implemented |
| XORI    | `XORI rd,rs1,imm`     | Xor Immediate                      | Implemented |
| ORI     | `ORI rd,rs1,imm`      | Or Immediate                       | Implemented |
| ANDI    | `ANDI rd,rs1,imm`     | And Immediate                      | Implemented |
| SLLI    | `SLLI rd,rs1,imm`     | Shift Left Logical Immediate       | Implemented |
| SRLI    | `SRLI rd,rs1,imm`     | Shift Right Logical Immediate      | Implemented |
| SRAI    | `SRAI rd,rs1,imm`     | Shift Right Arithmetic Immediate   | Implemented |
| ADD     | `ADD rd,rs1,rs2`      | Add                                | Implemented |
| SUB     | `SUB rd,rs1,rs2`      | Subtract                           | Implemented |
| SLL     | `SLL rd,rs1,rs2`      | Shift Left Logical                 | Implemented |
| SLT     | `SLT rd,rs1,rs2`      | Set Less Than                      | Implemented |
| SLTU    | `SLTU rd,rs1,rs2`     | Set Less Than Unsigned             | Implemented |
| XOR     | `XOR rd,rs1,rs2`      | Xor                                | Implemented |
| SRL     | `SRL rd,rs1,rs2`      | Shift Right Logical                | Implemented |
| SRA     | `SRA rd,rs1,rs2`      | Shift Right Arithmetic             | Implemented |
| OR      | `OR rd,rs1,rs2`       | Or                                 | Implemented |
| AND     | `AND rd,rs1,rs2`      | And                                | Implemented |
| FENCE   | `FENCE pred,succ`     | Fence                              | Miss        |
| FENCE.I | `FENCE.I`             | Fence Instruction                  | Miss        |

## Tutorial

### Environment Configuration:

We wrote this project in C++, and the compiling is handled by CMake. The required version of CMake is 3.10+, because it used the Google Test feature to specify the tests. The only dependency of the project is google test framework. You can find details about Google Test in https://github.com/google/googletest.

However, if you are not familiar with C++, here is the tutorial about how to configure the environment of this project from scratch.

1. Install the CMake. 

   ​	https://cmake.org/download/

2. Install the GTest.

   ​	Windows: 

   ​	 https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Windows

   ​	Linux:         

   ​	https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Windows

   ​	Mac:          

   ​	https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Mac

3. Also, we highly recommend you to use the IDE for C++ called Clion, which can be found in https://www.jetbrains.com/clion. It provides free trials for educational usage.

### Directory Structure

Here, the directories in this project were printed in a tree structure.

```
├── CMakeLists.txt
├── README.md
├── assem.txt
├── main.cpp
├── translator
│   ├── translator.cpp
│   ├── translator.h
│   └── trans_main.h
├── cpu
│   ├── alu.cpp
│   ├── alu.h
│   ├── cpu.cpp
│   ├── cpu.h
│   ├── reg.cpp
│   └── reg.h
├── mem
│   ├── mem.cpp
│   └── mem.h
└── test
    ├── test-alu.cpp
    └── test-cpu.cpp
```

The **CMakeLists.txt** contains instructions for CMake compiler.

The **assem.txt** file contains the RISC-V assembly code we want to run on our simulated CPU. We wrote a simple example in this file.

The **main.cpp** file contains code for starting the simulation.

The **translator** directory contains the code of the assembly translator.

The **cpu** directory contains the code of the CPU. 

The **mem** directory contains the code of the Memory.

The **test** directory contains the tests we wrote for our simulator, and you get some insight about how the whole simulator works by checking the code in *test-cpu.cpp*.

### Compiling

1. By command line:

   ```
   git clone https://github.com/Ohyoukillkenny/riscv-simulator.git
   cd riscv-simulator
   cmake .
   make
   ```

   After that, you shall find three executable files named as **TestAll**, **risc-translator** and **risc-simulator**. **TestAll** is used to test whether the CPU is correctly functioning. **risc-translator** is leveraged to translate assembly codes to binary instructions. **risc-simulator** is used to process the instructions and simulate the CPU.


2. By Clion:

   Download our project from Github. Start Clion, import this project. That's it!

### Run the Code

First of all, let us do the testing. 

1. By command line:

   ```
   ./TestAll
   ```

2. By Clion:

   Select the target to be TestAll and then click the green run button.

You shall see something like:

```
[----------] Global test environment tear-down
[==========] 18 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 18 tests.
```

Then, let us run **risc-simulator**.

1. By command line:

   The usage can be viewed as below:

   ```
   Usage:     risc-simulator [-a] [-p]   CODE_FILE
   -----------------------------------------------------
   [-h|--help] - show usage of risc-simulator
   [-a]        - process the assembly code
   [-p]        - print CPU status after each instruction
   CODE_FILE   - path of the assembly|binary code file
   -----------------------------------------------------
   ```
   Here is an example we run assembly codes in **assem.txt** in PrintAll mode:

   ```
   ./risc-simulator -ap assem.txt
   ```

   You can also find the usage by putting `./risc-simulator -h` into your command line terminals.

2. By Clion:

   Select the target to be risc-simulator, edit the configuration of risc-simulator to add program arguments  like `-h`, `CODE_FILE`, `-p CODE_FILE` or etc., and then click the green run button.

Then, you shall get a similar final CPU status like the printed status in the session of **How Does it Work** if you use our **assem.txt**.

## Enjoy Yourself

If everything goes smoothly, it is the time to test your own instruction codes!

By the way, if you want to see the memory status, you can use the method from `cpu` class called `mem_peep()`. It takes the address of the memory as the argument. Here is an example:

```c++
// create a new cpu
cpu *instance = new cpu(code_region, num);
// let cpu process the instructions
instance -> run();
// peep the value in memory at address 0x00000001
instance -> mem_peep(0x00000001);
```

Have fun with this toy simulator!

