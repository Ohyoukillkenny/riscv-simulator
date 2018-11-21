//
// Created by Lingkun Kong on 11/14/18.
//

#include <cstdint>
#include <vector>

#ifndef RISCV_SIMULATOR_MEM_H
#define RISCV_SIMULATOR_MEM_H


class mem {
    const int mem_size = 2048;
    // default size of sram is 2048
    uint32_t sram[2048];
public:
    mem();

    uint32_t get_mem(uint32_t addr);
    uint16_t get_mem_high(uint32_t addr);
    uint16_t get_mem_low(uint32_t addr);
    uint8_t get_mem_byte(uint32_t addr);

    void set_mem(uint32_t addr, uint32_t val);
    void set_mem_high(uint32_t addr, uint16_t val);
    void set_mem_low(uint32_t addr, uint16_t val);

};


#endif //RISCV_SIMULATOR_MEM_H
