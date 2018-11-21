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
    return (uint16_t) sram[addr] >> 16;
}
uint16_t mem::get_mem_low(uint32_t addr){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return 0;
    }
    return (uint16_t) (sram[addr] & 0x0000ffff);
}

uint8_t mem::get_mem_byte(uint32_t addr){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return 0;
    }
    return (uint8_t) (sram[addr] & 0x000000ff);
}

void mem::set_mem(uint32_t addr, uint32_t val){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return;
    }
    sram[addr] = val;
}
void mem::set_mem_high(uint32_t addr, uint16_t val){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return;
    }
    uint32_t mask = val << 16;
    sram[addr] = (sram[addr] & 0x0000ffff) | mask;

}
void mem::set_mem_low(uint32_t addr, uint16_t val){
    if (addr >= mem_size){
        std::cout << "Mem: invalid memory address" << std::endl;
        return;
    }
    sram[addr] = (sram[addr] & 0xffff0000) + val;
}











