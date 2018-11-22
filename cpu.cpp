//
// Created by Lingkun Kong on 11/14/18.
//

#include "cpu.h"
cpu::cpu() {
    cpu_sram = new mem();
    cpu_alu = new alu();
    cpu_regs = new reg();
    cpu_regs -> set_reg(cpu_regs -> PC, 0);
}


cpu::cpu(uint8_t *code, int n) {
    if (n <= 0){
        std::cout << "CPU: initialization failed." << std::endl <<
                  "In parameter setting, the number of instructions should > 0" << std::endl;
        std::runtime_error("CPU: initialization failed due to wrong parameter setting");
        return;
    }
    cpu_sram = new mem();
    cpu_alu = new alu();
    cpu_regs = new reg();
    cpu_regs -> set_reg(cpu_regs -> PC, 0);
    code_region = code;
    code_num = n;
}

cpu::cpu(uint8_t *code, int n, uint32_t pc) {
    if (n <= 0){
        std::cout << "CPU: initialization failed, as the number of instructions <= 0" << std::endl;
        std::runtime_error("CPU: initialization failed due to wrong parameter setting");
        return;
    }
    cpu_alu = new alu();
    cpu_regs = new reg();
    code_num = n;
    if ((pc & 0x00000003) != 0){
        std::cout << "CPU: last 2 bits of init PC must be 00, now we start with PC = 0" << std::endl;
        cpu_regs -> set_reg(cpu_regs -> PC, 0);
        code_region = code;
    } else{
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

uint8_t cpu::get_funct7(uint32_t instr){
    uint32_t ret;
    ret = (instr & 0b11111110000000000000000000000000) >> 25;
    return (uint8_t) ret;
}

uint8_t cpu::get_opcode(uint32_t instr) {
    uint8_t ret = 0;
    ret = (uint8_t) instr & 0x0000007f;
    return ret;
}


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

uint32_t cpu::get_branch_imm(uint32_t instr) {
    uint32_t imm = 0;
    uint8_t imm4to1_11 = get_rd(instr);
    uint8_t imm12_10to5 = get_funct7(instr);
    uint32_t imm_0 = 0;
    uint32_t imm_11 = (imm4to1_11 & 0b00000001) << 11;
    uint32_t imm_12 = (imm12_10to5 & 0b01000000) << 6;
    uint32_t imm_10to5 = (imm12_10to5 & 0b00111111) << 5;
    uint32_t imm4to1 = (imm4to1_11 & 0b00011110);
    imm = imm_12 | imm_11 | imm_10to5 | imm4to1 | imm_0;
    if ((imm_12 >> 12) != 0){
        imm = imm | 0xffffe000;  // add sign extension
    }
    return imm;
}

uint32_t cpu::get_jal_offset(uint32_t instr) {
    uint32_t offset = 0;
    uint32_t offset0 = 0;
    uint32_t offset20 = (instr & 0x80000000) >> 11;
    uint32_t offset10to1 = (instr & 0b01111111111000000000000000000000) >> 20;
    uint32_t offset11 =    (instr & 0b00000000000100000000000000000000) >> 9;
    uint32_t offset19to12= (instr & 0b00000000000011111111000000000000);
    offset = offset20 | offset19to12 | offset11 | offset10to1 | offset0;
    if ((offset20 >> 20) != 0){
        offset = offset | 0xfff00000; // add sign extension
    }
    return offset;
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

void cpu::l_type_opcode_process(uint32_t instr){
    uint32_t  imm = get_imm12(instr);
    uint8_t rd = get_rd(instr);
    uint8_t base_reg = get_rs1(instr);
    uint8_t alu_opcode = 0; // add
    uint32_t base_address = cpu_regs -> get_reg(base_reg);
    uint32_t mem_address = cpu_alu -> calculate(base_address, imm, alu_opcode);
    uint8_t funct3 = get_func3(instr);
    uint32_t mem_val;
    uint16_t mem_hex_val;
    uint8_t mem_byte_val;
    switch (funct3){
        case 0b000:
            // LB
            mem_byte_val = cpu_sram -> get_mem_byte(mem_address);
            if (((mem_byte_val & 0b10000000) >> 7 ) == 1){
                mem_val = 0xffffff00 | mem_byte_val;
            } else{
                mem_val = (uint32_t) mem_byte_val;
            }
            cpu_regs -> set_reg(rd, mem_val);
            break;
        case 0b001:
            // LH
            mem_hex_val = cpu_sram -> get_mem_byte(mem_address);
            if (((mem_hex_val & 0b1000000000000000) >> 15 ) == 1){
                mem_val = 0xffff0000 | mem_hex_val;
            } else{
                mem_val = (uint32_t) mem_hex_val;
            }
            cpu_regs -> set_reg(rd, mem_val);
            break;
        case 0b010:
            mem_val = cpu_sram -> get_mem(mem_address);
            cpu_regs -> set_reg(rd, mem_val);
            // LW
            break;
        case 0b100:
            // LBU
            mem_byte_val = cpu_sram -> get_mem_byte(mem_address);
            mem_val = (uint32_t) mem_byte_val;
            cpu_regs -> set_reg(rd, mem_val);
            break;
        case 0b101:
            // LHU
            mem_hex_val = cpu_sram -> get_mem_byte(mem_address);
            mem_val = (uint32_t) mem_hex_val;
            cpu_regs -> set_reg(rd, mem_val);
            break;
        default:
            std::bitset<32> y(funct3);
            std::cout << "CPU Load: Funct3 "<< y << " is not supported by this simulator" << std::endl;
            break;
    }

}

void cpu::b_type_opcode_process(uint32_t instr){
    uint8_t funct3 = get_func3(instr);
    uint32_t offset = get_branch_imm(instr);
    uint8_t rs1 = get_rs1(instr);
    uint8_t rs2 = get_rs2(instr);
    uint32_t rs1_val = cpu_regs -> get_reg(rs1);
    uint32_t rs2_val = cpu_regs -> get_reg(rs2);
    uint32_t pc_val = get_pc_val();
    switch (funct3){
        case 0b000:
            // beq
            if (rs1_val == rs2_val) {
                set_pc_val(pc_val + (int32_t) offset);
            } else{
                pc_plus_4();
            }
            break;
        case 0b001:
            // bne
            if (rs1_val != rs2_val){
                set_pc_val(pc_val + (int32_t) offset);
            } else{
                pc_plus_4();
            }
            break;
        case 0b100:
            // blt
            if ((int32_t) rs1_val < (int32_t) rs2_val){
                set_pc_val(pc_val + (int32_t) offset);
            } else{
                pc_plus_4();
            }
            break;
        case 0b101:
            // bge
            if ((int32_t) rs1_val >= (int32_t) rs2_val){
                set_pc_val(pc_val + (int32_t) offset);
            } else{
                pc_plus_4();
            }
            break;
        case 0b110:
            // bltu
            if (rs1_val < rs2_val){
                set_pc_val(pc_val + (int32_t) offset);
            } else{
                pc_plus_4();
            }
            break;
        case 0b111:
            // bgeu
            if (rs1_val >= rs2_val){
                set_pc_val(pc_val + (int32_t) offset);
            } else{
                pc_plus_4();
            }
            break;
        default:
            std::bitset<32> y(funct3);
            std::cout << "CPU Branch: Funct3 "<< y << " is not supported by this simulator" << std::endl;
            std::runtime_error("CPU Branch Processing: Instruction cannot be recognized. ");
            break;
    }

}

void cpu::jal_opcode_process(uint32_t instr) {
    uint8_t rd = get_rd(instr);
    uint32_t pc_val = get_pc_val();
    cpu_regs -> set_reg(rd, pc_val + 4);
    uint32_t offset = get_jal_offset(instr);
    set_pc_val(pc_val + (int32_t) offset);
}

void cpu::jalr_opcode_process(uint32_t instr) {
    uint32_t imm = get_imm12(instr);
    imm = imm & 0xfffffffe; // set the least-significant bit of the result to zero
    if ((imm >> 12) != 0){
        imm = imm | 0xfffff000; // add sign extension
    }
    uint8_t rs1 = get_rs1(instr);
    uint32_t rs1_val = cpu_regs -> get_reg(rs1);
    int32_t offset = ((int32_t)rs1_val) + ((int32_t)imm);
    uint8_t rd = get_rd(instr);
    uint32_t pc_val = get_pc_val();
    cpu_regs -> set_reg(rd, pc_val + 4);
    set_pc_val(pc_val + offset);
}

uint32_t cpu::get_pc_val(){
    uint32_t pc_val  = cpu_regs->get_reg(cpu_regs->PC);
    if ((pc_val & 0x00000003) != 0){
        std::cout << "CPU: last 2 bits of init PC must be 00" << std::endl;
        std::runtime_error("CPU: Processing Error with PC value");
    }
    return pc_val;
}

void cpu::set_pc_val(uint32_t new_pc_val){
    if ((new_pc_val & 0x00000003) != 0){
        std::cout << "CPU: last 2 bits of init PC must be 00" << std::endl;
        std::runtime_error("CPU: Processing Error with PC value");
    }
    cpu_regs ->set_reg(cpu_regs->PC, new_pc_val);
}

void cpu::pc_plus_4(){
    uint32_t pc_val = get_pc_val();
    pc_val += 4;
    set_pc_val(pc_val);
}

void cpu::check_whether_end(){
    uint32_t pc_val = get_pc_val();
//    std::cout << "PC val: " << pc_val << std::endl;
    if (pc_val >= code_num) {
        cpu_is_running = false;
    }
}


void cpu::process_instr(uint32_t instr) {
    uint8_t opcode = get_opcode(instr);
    switch (opcode){
        case L:
            l_type_opcode_process(instr);
            pc_plus_4();
            break;
        case S:
            s_type_opcode_process(instr);
            pc_plus_4();
            break;
        case R:
            r_type_opcode_process(instr);
            pc_plus_4();
            break;
        case I:
            i_type_opcode_process(instr);
            pc_plus_4();
            break;
        case B:
            b_type_opcode_process(instr);
            break;

        case JAL:
            jal_opcode_process(instr);
            break;

        case JALR:
            jalr_opcode_process(instr);
            break;

        default:
            std::bitset<32> y(opcode);
            std::cout << "CPU: opcode "<< y << " is not supported by this simulator" << std::endl;
            std::runtime_error("CPU process_instr: Instruction cannot be recognized.");
            break;
    }
}

void cpu::run_debug() {
    while (cpu_is_running) {
        uint32_t instr;
        uint32_t pc_val = get_pc_val();
        if ((pc_val & 0x00000003) != 0) {
            std::runtime_error("CPU Running: last 2 bits of init PC must be 00");
        }
        instr = combine_instr(code_region + pc_val);

        std::bitset<32> y(instr);
        std::cout << "instr: " << y << std::endl;
        process_instr(instr);
        print();
        check_whether_end();
    }
    // x2 = 4, x5 = -49, x18 = -49, sram[19] = 4
}

void cpu::run() {
    while (cpu_is_running) {
        uint32_t instr;
        uint32_t pc_val = get_pc_val();
        if ((pc_val & 0x00000003) != 0) {
            std::runtime_error("CPU Running: last 2 bits of init PC must be 00");
        }
        instr = combine_instr(code_region + pc_val);
        process_instr(instr);
        check_whether_end();
    }
    // x2 = 4, x5 = -49, x18 = -49, sram[19] = 4
}

void cpu::print() {
    std::cout << std::endl << "== The state of the CPU ==" << std::endl;
    // show the registers
    for(int i = 0; i < 33; ++i) {
        if (i == 32){
            std::bitset<32> bin(cpu_regs -> get_reg(i));
            std::cout << "PC has value : 0xb" << bin << std::endl;
        } else{
            std::cout << "x" + std::to_string(i) + " : " << (int) cpu_regs -> get_reg(i) << std::endl;
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