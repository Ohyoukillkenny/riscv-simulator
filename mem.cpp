//
// Created by Lingkun Kong on 11/14/18.
//

#include <iostream>
#include "mem.h"


mem::mem() {
    for (int i = 0; i< mem_size; i++){
        sram[i] = 0;
    }
}

uint32_t mem::get_mem(uint32_t addr){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return 0;
    }
    return sram[addr];
}
uint16_t mem::get_mem_high(uint32_t addr){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return 0;
    }
    uint16_t res = sram[addr] >> 16;
    return res;
}
uint16_t mem::get_mem_low(uint32_t addr);

void mem::set_mem(uint32_t addr, uint32_t val);
void mem::set_mem_high(uint32_t addr, uint16_t val);
void mem::set_mem_low(uint32_t addr, uint16_t val);