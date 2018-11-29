# RISC-V Simulator

## Introduction

This is an implementation of the RISC-V simulator, finished as a term project for COMP 554 at Rice University. The RISC-V Instruction Manual is located at:  https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf

In general, the idea of this project is to simulate a CPU under RISC-V architecture and then help people to understand how a CPU processes the instructions from RISC-V Instruction set. Also, this project is a good practice for us to get familiar with the RISC-V instruction set and learn more about how CPU works in modern computers.

## How Does it Work

In our project, **first of all, we put some 01 instructions in a txt file**, exp., *exe.txt* as below:

```
00000000100000000000001100010011 // ADDI imm=8, rs1=x0  rd=x6
00000000000100000000001010010011 // ADDI imm=1, rs1=x0  rd=x5
00000000000100101000001010010011 // ADDI imm=1, rs1=x5  rd=x5
00000000011000101000010001100011 // BEQ  offset=8, rs2=x6, rs1=x5
11111111000100110000000011100111 // JALR imm=-16, rs1=x6, rd=x1
00000000000100101000001010010011 // ADDI imm=1, rs1=x5  rd=x5
```

Then, **we used a program, *main.cpp* in this project, to read the binary-like instructions into instruction memory**. To be noticed, the comments of the 01 string will not be loaded, and the details about instruction loading could be found in *main.cpp*.

After that, in  *main.cpp*, **we call the simulated CPU to run in response to these instructions**. Our simulated CPU will use a PC register to fetch the instructions and process the instruction under the RISC-V architecture. Basically, the simulated CPU will modify values of its registers and might change values in the memory.

We provided a method in CPU class called **print()** which could print the current status of our simulated CPU, here is the sample about the printed status of the simulated CPU after processing the instruction examples in *exe.txt*:

```
== The state of the CPU ==
x0  : 0
x1  : 20
x2  : 0
x3  : 0
x4  : 0
x5  : 9
x6  : 8
x7  : 0
x8  : 0

...

x31 : 0
PC has value : 0xb00000000000000000000000000011000
```

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

## Usage

### Environment Configuration:

We wrote this project in C++, and the compiling is handled by CMake. The required version of CMake is 3.10+, because it used the Google Test feature to specify the tests. The only dependency of the project is google test framework. You can find details about Google Test in <https://github.com/google/googletest>.

However, if you are not familiar with C++, here is the tutorial about how to configure the environment of this project from scratch.

1. Install the CMake. link: https://cmake.org/download/
2. Install the GTest.
   1. link for windows: https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Windows
   2. link for Linux: https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Windows
   3. link for mac:  https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Mac
3. Also, we highly recommend you to use the IDE for C++ called Clion, which can be found in https://www.jetbrains.com/clion. You can register by your student email to get free trials.

### Directory Structure

Here, the directories in this project were printed in a tree structure.

```
├── CMakeLists.txt
├── README.md
├── cpu
│   ├── alu.cpp
│   ├── alu.h
│   ├── cpu.cpp
│   ├── cpu.h
│   ├── reg.cpp
│   └── reg.h
├── exe.txt
├── main.cpp
├── mem
│   ├── mem.cpp
│   └── mem.h
└── test
    ├── test-alu.cpp
    └── test-cpu.cpp
```

The **CMakeLists.txt** contains instructions for CMake compiler.

The **cpu** directory contains the code of the CPU. 

The **mem** directory contains the code of the Memory.

The **test** directory contains the tests we wrote for our simulator, and you get some insight about how the whole simulator works by checking the code in *test-cpu.cpp*.

The **main.cpp** file contains code for starting the simulation.

The **exe.txt** file contains the instructions we want to run on our simulated CPU. We wrote a simple example in this file.

### Compiling

1. By command line:

   ```
   cd riscv-simulator
   cmake .
   make
   ```

   After that, you shall find two executable files named as **TestAll** and **risc-simulator**. The former one is used to test whether the CPU is correctly functioning, and the latter one is used to process the instructions in the *exe.txt* file.


2. By Clion:

   Start Clion, import this project. That's it!

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

Then, let us run risc-simulator.

1. By command line:

   The usage of *risc-simulator* can be viewed as below:

   ```
   Usage:        risc-simulator [-p] CODE_FILE
   -----------------------------------------------------
   [-h|--help] - show usage of risc-simulator
   [-p]        - print CPU status after each instruction
   CODE_FILE   - path of the instruction file
   -----------------------------------------------------
   ```
   Here is an example we run instructions in *exe.txt* in PrintAll mode:

   ```
   ./risc-simulator -p /Users/klk/CLionProjects/riscv-simulator/exe.txt
   ```

   You can also find the usage by putting `./risc-simulator -h` into your command line terminals.

2. By Clion:

   Select the target to be risc-simulator, edit the configuration of risc-simulator to add program arguments  like `-h`, `CODE_FILE`, `-p CODE_FILE` or etc., and then click the green run button.

Then, you shall get a similar final CPU status like the printed status in the session of **How Does it Work** if you use our sample *exe.txt*.

## Enjoy Yourself

If everything goes smoothly, it is the time to test your own instruction codes!

By the way, if you want to see the memory status, you can use the method from cpu class called `mem_peep()`. It takes the address of the memory as the argument. Here is a detailed example for that:

```c++
// create a new cpu
cpu *instance = new cpu(code_region, num);
// let cpu process the instructions
instance -> run();
// peep the value in memory at address 0x00000001
instance -> mem_peep(0x00000001);
```

Have fun with this toy simulator!

