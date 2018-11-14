#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <queue>
#include "alu.h"
#include "reg.h"

int main() {
    int code_size = 1024;

    // allocate the code region
    auto *code_region = new uint8_t[code_size];

    unsigned long i = 0;

    // addi x5, x0, -50

    // 111111001110 00000 000 00101 0010011

//    code_region[i++] = 0b11111100;  // PC 0b000
//    code_region[i++] = 0b11100000;  // PC 0b001
//    code_region[i++] = 0b00000010;  // PC 0b010
//    code_region[i++] = 0b10010011;  // PC 0b011
//
//    uint32_t PC = 0b0;

    reg registers = reg();

    registers.set_reg(1, 13);

    uint32_t out =  registers.get_reg(1);

    std::cout << (int)out << std::endl;
    std::bitset<32> y(out);
    std::cout << y;
    return 0;
}