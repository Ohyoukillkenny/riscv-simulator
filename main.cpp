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
    uint8_t *code_region = new uint8_t[code_size];

    unsigned long i = 0;

    // addi x5, x0, -50

    // 111111001110 00000 000 00101 0010011

    code_region[0] = 0b11111100;  // PC 0b000
    code_region[1] = 0b11100000;  // PC 0b001
    code_region[2] = 0b00000010;  // PC 0b010
    code_region[3] = 0b10010011;  // PC 0b011

    code_region[4] = 0b00000000;

    uint8_t *ptr = code_region + 1;


    uint32_t out =  0;
    out = out | ptr[3];
    out = out | ptr[2] << 8;
    out = out | ptr[1] << 16;
    out = out | ptr[0] << 24;

    std::cout << (int)out << std::endl;
    std::bitset<32> y(out);
    std::cout << y;
    return 0;
}