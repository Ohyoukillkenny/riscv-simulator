//
// Created by Lingkun Kong on 11/14/18.
//
#include <cstdint>
#include <vector>

#ifndef RISCV_SIMULATOR_REG_H
#define RISCV_SIMULATOR_REG_H

/**
 * reference: https://en.wikichip.org/wiki/risc-v/registers
 * x0	    zero	hardwired zero
   x1	    ra	    return address
   x2	    sp	    stack pointer
   x3	    gp	    global pointer
   x4	    tp	    thread pointer
 */


class reg {

    uint32_t regs[33];

public:
    const uint8_t ZR = 0;
    const uint8_t RA = 1;
    const uint8_t SP = 2;
    const uint8_t GP = 3;
    const uint8_t TP = 4;
    const uint8_t PC = 32;

    reg();

    uint32_t get_reg(uint8_t);
    uint16_t get_reg_high(uint8_t);
    uint16_t get_reg_low(uint8_t);

    void set_reg(uint8_t, uint32_t);
    void set_reg_high(uint8_t, uint16_t);
    void set_reg_low(uint8_t, uint16_t);
};


#endif //RISCV_SIMULATOR_REG_H
