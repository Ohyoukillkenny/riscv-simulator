//
// Created by Lingkun Kong on 11/14/18.
//

#include "cpu.h"
cpu::cpu(uint8_t *code) {
    cpu_alu = alu();
    cpu_regs = reg();
    cpu_regs . set_reg(cpu_regs.PC, 0);
    code_region = code;
}

cpu::cpu(uint8_t *code, uint32_t pc) {
    if ((pc & 0x00000003) != 0){
        std::cout << "CPU: last 2 bits of init PC must be 00" << std::endl;
        cpu_alu = alu();
        cpu_regs = reg();
        cpu_regs.set_reg(cpu_regs.PC, 0);
        code_region = code;
    } else{
        cpu_alu = alu();
        cpu_regs = reg();
        cpu_regs.set_reg(cpu_regs.PC, pc);
        code_region = code + pc;
    }
}

uint32_t cpu::combine_instr(uint8_t *start) {
    uint32_t ret = 0;
    ret = ret | start[3];
    ret = ret | start[2] << 8;
    ret = ret | start[1] << 16;
    ret = ret | start[0] << 24;
    return  ret;
}

uint8_t cpu::get_opcode(uint32_t instr) {
    uint8_t ret = 0;
    ret = instr & 0x0000007f;
    if (ret == 0b01100011){
        // Branch
        if ((instr & 0x00001000)>>12 == 1){
            // 12 th bit is 1 --> bne
            ret = 0b11100011;
        }
    }
    return ret;
}

void cpu::process_instr(uint32_t instr) {
    uint8_t opcode = get_opcode(instr);
    switch (opcode){
        case L:
            break;

        case S:
            break;

        case R:

            break;
        case I:

            break;
        case BEQ:

            break;

        case BNE:

            break;

        case J:
            break;

        default:
            std::bitset<32> y(opcode);
            std::cout << "CPU: opcode "<< y << " is not supported by this simulator" << std::endl;
            break;
    }

}