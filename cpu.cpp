//
// Created by Lingkun Kong on 11/14/18.
//

#include "cpu.h"
cpu::cpu(uint8_t *code) {
    cpu_sram = new mem();
    cpu_alu = new alu();
    cpu_regs = new reg();
    cpu_regs -> set_reg(cpu_regs -> PC, 0);
    code_region = code;
}

cpu::cpu(uint8_t *code, uint32_t pc) {
    if ((pc & 0x00000003) != 0){
        std::cout << "CPU: last 2 bits of init PC must be 00" << std::endl;
        cpu_alu = new alu();
        cpu_regs = new reg();
        cpu_regs -> set_reg(cpu_regs -> PC, 0);
        code_region = code;
    } else{
        cpu_alu = new alu();
        cpu_regs = new reg();
        cpu_regs -> set_reg(cpu_regs -> PC, pc);
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

uint8_t get_funct7(uint32_t instr){
    uint32_t ret;
    ret = (instr & 0b11111110000000000000000000000000) >> 25;
    return (uint8_t) ret;
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

//0000000 01010   10011 000   10010 0110011
//ADD     rs2=10 rs1=19 func3 rd=18 opcode

uint8_t cpu::get_rd(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000000000000000000111110000000) >> 7;
    return (uint8_t) ret;
}

uint8_t cpu::get_func3(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000000000000000111000000000000) >> 12;
    return (uint8_t) ret;
}

uint8_t cpu::get_rs1(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000000000011111000000000000000) >> 15;
    return (uint8_t) ret;
}

uint8_t cpu::get_rs2(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000001111100000000000000000000) >> 20;
    return (uint8_t) ret;
}

uint32_t cpu::get_imm12(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b11111111111100000000000000000000) >> 20;
    if ((ret >> 11) == 1){
        // handle the case when imm is negtive
        return (ret|0b11111111111111111111000000000000);
    } else{
        return ret;
    }
}

uint32_t cpu::get_shamt(uint32_t instr) {
    uint32_t ret;
    ret = (instr & 0b00000001111100000000000000000000) >> 20;
    if ((ret >> 4) == 1){
        // handle the case when shamt is negtive
        std::cout << "CPU: shamt has negative value, which is illegal" << std::endl;
        return 0;
    } else{
        return ret;
    }
}

uint8_t cpu::combine_30_func3(uint32_t instr) {
    uint8_t func3 = get_func3(instr);
    uint8_t bit30 = (instr & 0x40000000) >> 30;
    if (bit30 == 1){
        return (func3 | 0b00001000);
    } else{
        return func3;
    }
}


void cpu::r_type_opcode_process(uint32_t instr) {
    uint8_t alu_opcode = combine_30_func3(instr);
    uint8_t rd = get_rd(instr);
    uint8_t rs1 = get_rs1(instr);
    uint8_t rs2 = get_rs2(instr);

    // read data form registers
    uint32_t in1 = cpu_regs -> get_reg(rs1);
    uint32_t in2 = cpu_regs -> get_reg(rs2);
    // calculate the value by using alu
    uint32_t out = cpu_alu -> calculate(in1, in2, alu_opcode);
    // write the data to rd register
    cpu_regs -> set_reg(rd, out);

}

void cpu::i_type_opcode_process(uint32_t instr) {
    uint8_t alu_opcode = get_func3(instr);
    uint8_t rd = get_rd(instr);
    uint8_t rs1 = get_rs1(instr);
    uint32_t in1 = cpu_regs -> get_reg(rs1);
    uint32_t in2;

    switch (alu_opcode){
        case 0b0000001:
            in2 = get_shamt(instr);
            break;
        case 0b0000101:
            in2 = get_shamt(instr);
            alu_opcode = combine_30_func3(instr);
            break;
        default:
            in2 = get_imm12(instr);
            break;
    }


    uint32_t out = cpu_alu -> calculate(in1, in2, alu_opcode);
    cpu_regs -> set_reg(rd, out);
}

void cpu::save_word(uint32_t instr, uint16_t imm, uint8_t alu_opcode){
    uint8_t src_reg = get_rs2(instr);
    uint8_t base_reg = get_rs1(instr);
    uint32_t src_val = cpu_regs -> get_reg(src_reg);
    uint32_t base_address = cpu_regs -> get_reg(base_reg);
    uint32_t mem_address = cpu_alu -> calculate(base_address, imm, alu_opcode);
    cpu_sram -> set_mem(mem_address, src_val);
}

void cpu::save_byte(uint32_t instr, uint16_t imm, uint8_t alu_opcode){
    uint8_t src_reg = get_rs2(instr);
    uint8_t base_reg = get_rs1(instr);
    uint32_t src_val = cpu_regs -> get_reg(src_reg);
    uint32_t src_byte_val = (src_val & 0b00000000000000000000000011111111);
    uint32_t base_address = cpu_regs -> get_reg(base_reg);
    uint32_t mem_address = cpu_alu -> calculate(base_address, imm, alu_opcode);
    cpu_sram -> set_mem(mem_address, src_byte_val);
}
void cpu::save_hex(uint32_t instr, uint16_t imm, uint8_t alu_opcode){
    uint8_t src_reg = get_rs2(instr);
    uint8_t base_reg = get_rs1(instr);
    uint32_t src_val = cpu_regs -> get_reg(src_reg);
    uint32_t src_hex_val =  (src_val & 0b00000000000000001111111111111111);
    uint32_t base_address = cpu_regs -> get_reg(base_reg);
    uint32_t mem_address = cpu_alu -> calculate(base_address, imm, alu_opcode);
    cpu_sram -> set_mem(mem_address, src_hex_val);
}


void cpu::s_type_opcode_process(uint32_t instr){
    uint8_t imm11to5 = get_funct7(instr); // 7 bits
    uint8_t imm4to0 = get_rd(instr);      // 5 bits
    uint16_t imm = (((uint16_t) imm11to5 )<< 5) | (uint16_t) imm4to0;
    uint8_t alu_opcode = 0; // add
    uint8_t funct3 = get_func3(instr);
    switch (funct3){
        case 0b000:
            // SB
            save_byte(instr, imm, alu_opcode);
            break;
        case 0b001:
            // SH
            save_hex(instr, imm, alu_opcode);
            break;
        case 0b010:
            save_word(instr, imm, alu_opcode);
            // SW
            break;
        default:
            std::bitset<32> y(funct3);
            std::cout << "CPU Save: Funct3 "<< y << " is not supported by this simulator" << std::endl;
            break;
    }
}

void cpu::process_instr(uint32_t instr) {
    uint8_t opcode = get_opcode(instr);
    switch (opcode){
        case L:
            break;

        case S:
            s_type_opcode_process(instr);
            break;

        case R:
            r_type_opcode_process(instr);
            break;
        case I:
            i_type_opcode_process(instr);
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

void cpu::run() {
    process_instr(0b00000000010000000000000100010011);  // ADDI imm=4, rs1=x0  rd=x2 -> x2 = 4
    process_instr(0b00000000000100000000001010010011);  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    process_instr(0b00000000001000101010100100100011);  // SW  offset1=0, src=x2, base=x5, offset2=18 -> save 4 to mem(1+18)
    process_instr(0b11111100111000000000001010010011);  // addi imm=-50 rs1=x0  rd=x5
    process_instr(0b00000000000100101000001010010011);  // ADDI imm=1   rs1=x5  rd=x5
    process_instr(0b00000000000000101000100100110011);  // ADD  rs2=0   rs1=x5  rd=18
    // x2 = 4, x5 = -49, x18 = -49, sram[19] = 4
}

void cpu::print() {
    std::cout << std::endl << "== The state of the CPU ==" << std::endl;
    // show the registers
    for(int i = 0; i < 33; ++i) {
        if (i == 32){
            std::bitset<32> bin(cpu_regs -> get_reg(i));
            std::cout << "PC  register has value : 0xb" << bin << std::endl;
        } else{
            std::cout << "x" + std::to_string(i) + " register has value : " << (int) cpu_regs -> get_reg(i) << std::endl;
        }
    }
}


void cpu::test_instrs(uint32_t *instr_set, int size) {
    for (int i = 0; i < size; ++i) {
        uint32_t instr = instr_set[i];
        process_instr(instr);
    }
}

uint32_t cpu::reg_peep(uint8_t addr) {
    return cpu_regs -> get_reg(addr);
}

uint32_t cpu::mem_peep(uint32_t addr){
    return cpu_sram -> get_mem(addr);
}