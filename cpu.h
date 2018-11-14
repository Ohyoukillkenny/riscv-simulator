//
// Created by Lingkun Kong on 11/14/18.
//

#include <cstdint>
#include <vector>
#ifndef RISCV_SIMULATOR_CPU_H
#define RISCV_SIMULATOR_CPU_H

/**
 * The register type
 */
union ricv_register_t {

    /**
     * Used to get the bytes (assuming big endian)
     */
    struct
    {
        uint8_t B0;
        uint8_t B1;
        uint8_t B2;
        uint8_t B3;

    } to_bytes;

    /**
     * Used to get the 16 words (assuming bit endian)
     */
    struct
    {
        uint16_t W0;
        uint16_t W1;

    } to_half_words;

    /**
     * Used to get the unsigned 32-bit word
     */
    uint32_t to_uint;
};


class cpu {


public:
    /**
     * Prints cpu status
     */
    void print();
};


#endif //RISCV_SIMULATOR_CPU_H
