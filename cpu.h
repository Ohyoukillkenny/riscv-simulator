//
// Created by Lingkun Kong on 11/14/18.
//

#include <cstdint>
#include <vector>
#include "reg.h"
#include "alu.h"
#include "ctr.h"
#ifndef RISCV_SIMULATOR_CPU_H
#define RISCV_SIMULATOR_CPU_H

// the eighth bit is from bit 12 -- BNE, BEQ

const uint8_t R = 0b00110011; // reg data processing, exp. add  rd, rs1, rs2
const uint8_t S = 0b00100011; // save data,           exp. sw   rs1, rs2, imm
const uint8_t L = 0b00000011; // load data,           exp. lw   rd,  rs1, imm
const uint8_t I = 0b00010011; // imm data processing, exp. addi rd, rs1, imm
const uint8_t BNE = 0b11100011; // bne                exp. bne  rs1, rs2, imm
const uint8_t BEQ = 0b01100011; // beq                exp. beq  rs1, rs2, imm
const uint8_t J = 0b01101111; // jump, only JAL       exp. jal  rd, imm

class cpu {
    reg cpu_regs;
    alu cpu_alu;
    uint8_t *code_region;

    uint8_t alu_op;
    bool jump, beq, bne, mem_read, mem_write, alu_src, reg_dst, mem_to_reg, reg_write;

    uint32_t combine_instr(uint8_t *start);
    uint8_t get_opcode(uint32_t instr);
    // process the 32 bits instruction
    void process_instr(uint32_t instr);
    // process the instruction after know it belongs to R-type
    void r_type_opcode_process(uint32_t instr);



public:
    cpu(uint8_t *code);
    cpu(uint8_t *code, uint32_t pc);
    void run();
    /**
     * Prints cpu status
     */
    void print();
};


#endif //RISCV_SIMULATOR_CPU_H
