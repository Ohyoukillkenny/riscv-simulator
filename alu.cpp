//
// Created by Lingkun Kong on 11/13/18.
// Reference: https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
//
#include <cstdint>
#include "alu.h"

const uint8_t ALU_OP_ADD  = 0b00000000; // 0
const uint8_t ALU_OP_SLL  = 0b00000001; // 1
const uint8_t ALU_OP_XOR  = 0b00000100; // 4
const uint8_t ALU_OP_OR   = 0b00000110; // 6
const uint8_t ALU_OP_AND  = 0b00000111; // 7
const uint8_t ALU_OP_SRL  = 0b00000101; // 5
const uint8_t ALU_OP_SUB  = 0b00001000; // 8
const uint8_t ALU_OP_SRA  = 0b00001101; // 13
const uint8_t ALU_OP_SLT  = 0b00000010; // 2
const uint8_t ALU_OP_SLTU = 0b00000011; // 3

uint32_t alu::calculate(uint32_t in1, uint32_t in2, uint8_t op) {

    uint32_t out;
    switch (op){
        case ALU_OP_ADD: out = in1 + in2;
            break;
        case ALU_OP_SLL : out = in1 << in2;
            break;
        case ALU_OP_XOR : out = in1 ^ in2;
            break;
        case ALU_OP_OR : out = in1 | in2;
            break;
        case ALU_OP_AND : out = in1 & in2;
            break;
        case ALU_OP_SRL : out = in1 >> in2; // Shift Right Logical
            break;
        case ALU_OP_SUB : out = in1 - in2;
            break;
        case ALU_OP_SRA : out = ((int32_t) in1) >> in2; // Shift Right Arithmetic
            break;
        case ALU_OP_SLT : out = (uint32_t) 0 | (((int32_t) in1) < ((int32_t) in2)); // Set If Less Than (Signed)
            break;
        case ALU_OP_SLTU : out = (uint32_t) 0 | (in1 < in2); // Set If Less Than (Unsigned)
            break;
        default:
            out = (uint32_t) 0;
            std::cout << "ALU cannot recognize the operating instruction" << std::endl;
            break;
    }
    return out;
}