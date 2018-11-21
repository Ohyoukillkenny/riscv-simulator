#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <queue>
#include "alu.h"
#include "reg.h"
#include "cpu.h"


uint8_t get_rd(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000000000000000000111110000000) >> 7;
    return (uint8_t) ret;
}

uint8_t get_funct7(uint32_t instr){
    uint32_t ret;
    ret = (instr & 0b11111110000000000000000000000000) >> 25;
    return (uint8_t) ret;
}

uint32_t get_branch_imm(uint32_t instr) {
    uint32_t imm = 0;
    uint8_t imm4to1_11 = get_rd(instr);
    uint8_t imm12_10to5 = get_funct7(instr);
    uint32_t imm_0 = 0;
    uint32_t imm_11 = (imm4to1_11 & 0b00000001) << 11;
    uint32_t imm_12 = (imm12_10to5 & 0b01000000) << 6;
    std::bitset<32> y(imm_12);
    std::cout << "imm_12: "<< y << std::endl;
    uint32_t imm_10to5 = (imm12_10to5 & 0b00111111) << 5;
    uint32_t imm4to1 = (imm4to1_11 & 0b00011110);
    imm = imm_12 | imm_11 | imm_10to5 | imm4to1 | imm_0;
    if ((imm_12 >> 12) != 0){
        imm = imm | 0xffffe000;  // add sign extension
    }
    return imm;
}


int main() {
//    int code_size = 1024;
//
//    // allocate the code region
//    auto *code_region = new uint8_t[code_size];
//
//    // read the code region
//    std::ifstream code_file("/Users/klk/CLionProjects/riscv-simulator/exe.txt");
//
//    // check if we have opened the file
//    if(!code_file.is_open()) {
//        std::cout << "Could not open the " <<  "~/CLionProjects/riscv-simulator/exe.txt" << " file." << std::endl;
//        return -1;
//    }
//
//    // copy the code region
//    int num = 0;
//    std::string temp;
//    uint8_t code;
//    while (std::getline(code_file, temp)) {
//        for (int i = 0; i < 4; ++i) {
//            code = 0b00000000;
//            for (int j = 0; j < 8; ++j){
//                if (temp[8*i+j] - '0' == 0){
//                    continue;
//                } else {
//                    code = code | (uint8_t) (1 << (7-j));
//                }
//            }
//            code_region[num] = code;
//            num ++;
//        }
//    }
//    // close the file
//    code_file.close();
//
//    cpu *instance = new cpu(code_region, num);
//    instance -> run();
//    instance -> print();
//    std::cout << instance -> mem_peep(19) << std::endl;
    uint32_t instr = 0b10000000101010011000100011100011;
    uint32_t code = get_branch_imm(instr);
    std::cout << (int) code << std::endl;
    std::bitset<32> y(code);
    std::cout << y << std::endl;

//    uint8_t a = 0b10000001;
//    uint32_t b = 0xffffff84;
//    std::cout << (int)b << std::endl;
//    std::bitset<32> y(b);
//    std::cout << y;

    return 0;
}