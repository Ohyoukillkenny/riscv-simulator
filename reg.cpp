//
// Created by Lingkun Kong on 11/14/18.
//

#include <iostream>
#include "reg.h"

reg::reg() {
    regs[0] = 0;
    regs[PC] = 0;
}

reg::reg(uint32_t pc) {
    regs[0] = 0;
    if (pc & (uint32_t) 3){
        regs[PC] = pc;
    }
    else{
        std::cout << "Reg: the last two bits of init pc are not 00" << std::endl;
        regs[PC] = 0;
    }
}

uint32_t reg::get_reg(uint8_t addr){
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return 0;
    }
    if (regs[addr] == NULL){
        std::cout << "Reg: reg[addr] is empty" << std::endl;
        return 0;
    }
    return regs[addr];
}

uint16_t reg::get_reg_high(uint8_t addr) {
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return 0;
    }
    if (regs[addr] == NULL){
        std::cout << "Reg: reg[addr] is empty" << std::endl;
        return 0;
    }
    uint16_t res = regs[addr] >> 16;
    return res;
}

uint16_t reg::get_reg_low(uint8_t addr) {
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return 0;
    }
    if (regs[addr] == NULL){
        std::cout << "Reg: reg[addr] is empty" << std::endl;
        return 0;
    }
    uint32_t res = regs[addr] & 0x0000ffff;
    return (uint16_t) res;
}

void reg::set_reg(uint8_t addr, uint32_t val) {
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return;
    }
    if (addr == 0){
        std::cout << "Reg: cannot set x0" << std::endl;
        return;
    }
    regs[addr] = val;
}

void reg::set_reg_high(uint8_t addr, uint16_t val) {
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return;
    }
    if (addr == 0){
        std::cout << "Reg: cannot set x0" << std::endl;
        return;
    }
    uint32_t mask = val << 16;
    regs[addr] = (regs[addr] & 0x0000ffff) | mask;
}

void reg::set_reg_low(uint8_t addr, uint16_t val) {
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return;
    }
    if (addr == 0){
        std::cout << "Reg: cannot set x0" << std::endl;
        return;
    }
    regs[addr] = (regs[addr] & 0xffff0000) + val;
}


















