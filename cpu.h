//
// Created by Lingkun Kong on 11/14/18.
//

#include <cstdint>
#include <vector>
#include "reg.h"
#include "alu.h"
#include "ctr.h"
#include "mem.h"
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
    reg *cpu_regs;
    alu *cpu_alu;
    mem *cpu_sram;
    uint8_t *code_region;


    /* methods for instruction processing:
     * combine_instr:   combine 4 bytes to a 32 bits instruction
     * get_funct:       get funct7, bit position from 31 to 25
     * get_opcode:      parse the opcode from the instruction
     * get_rd:          get rd register from the instruction, for save instruction, it is imm
     * get_func3:       get func3 from the instruction
     * get_rs1:         get rs1 register from the instruction
     * get_rs2:         get rs2 register from the instruction
     * combine_30_func3:      bit30 + [func3] -> 4 bits alu_op
     * */
    uint32_t combine_instr(uint8_t *start);

    uint8_t get_funct7(uint32_t instr);

    uint8_t get_opcode(uint32_t instr);

    uint8_t get_rd(uint32_t instr);

    uint8_t get_func3(uint32_t instr);

    uint8_t get_rs1(uint32_t instr);

    uint8_t get_rs2(uint32_t instr);

    uint8_t combine_30_func3(uint32_t instr);

    uint32_t get_imm12(uint32_t instr);

    uint32_t get_shamt(uint32_t instr);

    // function for S-type instructions
    void save_word(uint32_t instr, uint16_t imm, uint8_t alu_opcode);
    void save_byte(uint32_t instr, uint16_t imm, uint8_t alu_opcode);
    void save_hex(uint32_t instr, uint16_t imm, uint8_t alu_opcode);

    // function for L-type instructions


    // process the 32 bits instruction
    void process_instr(uint32_t instr);
    // R-type
    void r_type_opcode_process(uint32_t instr);
    // I-type
    void i_type_opcode_process(uint32_t instr);
    // S-type
    void s_type_opcode_process(uint32_t instr);
    // L-type
    void l_type_opcode_process(uint32_t instr);



public:
    cpu();
    cpu(uint8_t *code);
    cpu(uint8_t *code, uint32_t pc);
    void run();
    /**
     * Prints cpu status
     */
    void print();

    // methods prepared for the cpu-test in test file
    void test_instrs(uint32_t *instr_set, int size);
    uint32_t reg_peep(uint8_t addr);
    uint32_t mem_peep(uint32_t addr);
};


#endif //RISCV_SIMULATOR_CPU_H
