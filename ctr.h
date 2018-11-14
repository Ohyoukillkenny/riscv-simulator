//
// Created by Lingkun Kong on 11/14/18.
//
#include <iostream>
#ifndef RISCV_SIMULATOR_CTR_H
#define RISCV_SIMULATOR_CTR_H


class ctr {

public:
    uint8_t alu_op;
    bool jump, beq, bne, mem_read, mem_write, alu_src, reg_dst, mem_to_reg, reg_write;
    void unit_ctrol(uint8_t);

};


#endif //RISCV_SIMULATOR_CTR_H
