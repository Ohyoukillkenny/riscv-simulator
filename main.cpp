#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <queue>
#include "alu.h"
#include "reg.h"
#include "cpu.h"

uint8_t get_func3(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000000000000000111000000000000) >> 12;
    return (uint8_t) ret;
}

uint8_t get_alu_op(uint32_t instr) {
    uint8_t func3 = get_func3(instr);
    std::bitset<8> a(func3);
    std::cout << "func3:" << a << "\n";
    uint8_t bit30 = (instr & 0x40000000) >> 30;
    std::bitset<8> y(bit30);
    std::cout << "bit30:" << y << "\n";
    if (bit30 == 1){
        return (func3 | 0b00001000);
    } else{
        return func3;
    }
}


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


//    cpu *instance = new cpu(code_region);
//    instance->run();
//    std::cout << instance -> mem_peep(19) << std::endl;
//    instance -> print();

    uint8_t a = 0b10000001;
    uint32_t b = 0xffffff84;


//    uint32_t instr = 0b01000000101010011101100100110011;
//
//    uint32_t out = instr;
//
    std::cout << (int)b << std::endl;
    std::bitset<32> y(b);
    std::cout << y;
    return 0;
}