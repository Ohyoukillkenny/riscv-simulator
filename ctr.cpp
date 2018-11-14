//
// Created by Lingkun Kong on 11/14/18.
//

#include "ctr.h"
#include <cstdint>

// the eighth bit is from bit 12 -- BNE, BEQ

const uint8_t R = 0b00110011; // reg data processing, exp. add  rd, rs1, rs2
const uint8_t S = 0b00100011; // save data,           exp. sw   rs1, rs2, imm
const uint8_t L = 0b00000011; // load data,           exp. lw   rd,  rs1, imm
const uint8_t I = 0b00010011; // imm data processing, exp. addi rd, rs1, imm
const uint8_t BNE = 0b11100011; // bne                exp. bne  rs1, rs2, imm
const uint8_t BEQ = 0b01100011; // beq                exp. beq  rs1, rs2, imm
const uint8_t J = 0b01101111; // jump, only JAL       exp. jal  rd, imm


void ctr::unit_ctrol(uint8_t opcode) {
    switch (opcode){

        case L:
            reg_dst = false;
            alu_src = true;
            mem_to_reg = true;
            reg_write = true;
            mem_read = true;
            mem_write = false;
            beq = false;
            bne = false;
            jump = false;
            alu_op = 0b00000010;
            break;

        case S:
            reg_dst = false;
            alu_src = true;
            mem_to_reg = false;
            reg_write = false;
            mem_read = false;
            mem_write = true;
            beq = false;
            bne = false;
            jump = false;
            alu_op = 0b00000010;
            break;

        case R:
            reg_dst = true;
            alu_src = false;
            mem_to_reg = false;
            reg_write = true;
            mem_read = false;
            mem_write = false;
            beq = false;
            bne = false;
            jump = false;
            alu_op = 0b00000000;
            break;
        case I:
            reg_dst = true;
            alu_src = false;
            mem_to_reg = false;
            reg_write = true;
            mem_read = false;
            mem_write = false;
            beq = false;
            bne = false;
            jump = false;
            alu_op = 0b00000001;
            break;
        case BEQ:
            reg_dst = false;
            alu_src = false;
            mem_to_reg = false;
            reg_write = true;
            mem_read = false;
            mem_write = false;
            beq = true;
            bne = false;
            jump = false;
            alu_op = 0b00000001;
            break;

        case BNE:
            reg_dst = false;
            alu_src = false;
            mem_to_reg = false;
            reg_write = true;
            mem_read = false;
            mem_write = false;
            beq = false;
            bne = true;
            jump = false;
            alu_op = 0b00000001;
            break;

        case J:
            reg_dst = false;
            alu_src = false;
            mem_to_reg = false;
            reg_write = false;
            mem_read = false;
            mem_write = false;
            beq = false;
            bne = false;
            jump = true;
            alu_op = 0b00000000;
            break;

        default:
            reg_dst = true;
            alu_src = false;
            mem_to_reg = false;
            reg_write = true;
            mem_read = false;
            mem_write = false;
            beq = false;
            bne = false;
            jump = false;
            alu_op = 0b00000000;
            break;

    }

}
