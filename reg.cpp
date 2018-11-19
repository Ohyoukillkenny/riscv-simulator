//
// Created by Lingkun Kong on 11/14/18.
//

#include <iostream>
#include "reg.h"

reg::reg() {
    for (int i = 0; i< 33; i++){
        regs[i] = 0;
    }
}

uint32_t reg::get_reg(uint8_t addr){
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
        return 0;
    }
    return regs[addr];
}

uint16_t reg::get_reg_high(uint8_t addr) {
    if (addr > 32){
        std::cout << "Reg: invalid register address" << std::endl;
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


















