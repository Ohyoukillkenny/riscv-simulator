//
// Created by Lingkun Kong on 11/14/18.
//

#include <gtest/gtest.h>
#include "../cpu.h"

class test_cpu: public testing::Test {
public:

    // the instance of the mmu
    cpu *instance;

    test_cpu( ) {
        instance = new cpu();
    }

    void SetUp() override {
    }

    void TearDown() override {}

    ~test_cpu() override {
        // do the cleanup
        delete instance;
    }
};

TEST_F(test_cpu, test_cpu_addi)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b11111100111000000000001010010011; // addi imm=-50 rs1=x0  rd=x5
    instr_set[1] = 0b00000000000100101000001010010011; // ADDI imm=1   rs1=x5  rd=x5
    instr_set[2] = 0b00000000000000101000100100110011; // ADD  rs2=0   rs1=x5  rd=18
    this -> instance -> test_instrs(instr_set, 3);
    EXPECT_EQ((int) this -> instance -> reg_peep(18), -49);
}

TEST_F(test_cpu, test_cpu_sw)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00010000010000000000000100010011;  // ADDI imm=260, rs1=x0  rd=x2 -> x2 = 260
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101010100100100011;  // SW  offset1=0, src=x2, base=x5, offset2=18 -> save 260 to mem(1+18)
    instr_set[3] = 0b11111100111000000000001010010011;  // addi imm=-50 rs1=x0  rd=x5
    instr_set[4] = 0b00000000000100101000001010010011;  // ADDI imm=1   rs1=x5  rd=x5
    instr_set[5] = 0b00000000000000101000100100110011;  // ADD  rs2=0   rs1=x5  rd=18
    // x2 = 260, x5 = -49, x18 = -49, sram[19] = 4
    instance -> test_instrs(instr_set, 6);
    EXPECT_EQ((int) instance -> reg_peep(18), -49);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 260);
}

TEST_F(test_cpu, test_cpu_sb)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00010000010000000000000100010011;  // ADDI imm=260, rs1=x0  rd=x2 -> x2 = 0b000100000100 = 256+4 = 260
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101000100100100011;  // SB  offset1=0, src=x2's byte, base=x5, offset2=18 -> save 4 to mem(1+18)
    // x2 = 260, sram[19] = 4
    instance -> test_instrs(instr_set, 3);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 4);
}

TEST_F(test_cpu, test_cpu_lw)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00010000010000000000000100010011;  // ADDI imm=260, rs1=x0  rd=x2 -> x2 = 0b000100000100 = 256+4 = 260
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101000100100100011;  // SB  offset1=0, src=x2's byte, base=x5, offset2=18 -> save 4 to mem(1+18)
    instr_set[3] = 0b00000001001100000010001010000011;  // lw imm=19, rs1=x0  rd=x5 -> mem_addr = 0 + 19, load sram(19) to x5
    // x2 = 260, x5 = 4, sram[19] = 4
    instance -> test_instrs(instr_set, 4);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 4);
    EXPECT_EQ((int) instance -> reg_peep(5), 4);
}

TEST_F(test_cpu, test_cpu_lb)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00010000010000000000000100010011;  // ADDI imm=260, rs1=x0  rd=x2 -> x2 = 0b000100000100 = 256+4 = 260
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101010100100100011;  // SW  offset1=0, src=x2, base=x5, offset2=18 -> save 260 to mem(1+18)
    instr_set[3] = 0b00000001001100000000001010000011;  // lb imm=19, rs1=x0  rd=x5 -> mem_addr = 0 + 19, load sram(19)'s byte to x5
    // x2 = 260, x5 = 4, sram[19] = 4
    instance -> test_instrs(instr_set, 4);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 260);
    EXPECT_EQ((int) instance -> reg_peep(5), 4);
}

TEST_F(test_cpu, test_cpu_lb2)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00011000010000000000000100010011;  // ADDI imm=388, rs1=x0  rd=x2 -> x2 = 0b000110000100 = 256+128+4 = 388
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101010100100100011;  // SW  offset1=0, src=x2, base=x5, offset2=18 -> save 388 to mem(1+18)
    instr_set[3] = 0b00000001001100000000001010000011;  // lb imm=19, rs1=x0  rd=x5 -> mem_addr = 0 + 19, load sram(19)'s byte to x5
                                                        //      with sign-extension, x5 = 0xffffff84 = -124
    // x2 = 388, x5 = -124, sram[19] = 388
    instance -> test_instrs(instr_set, 4);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 388);
    EXPECT_EQ((int) instance -> reg_peep(5), -124);
}

TEST_F(test_cpu, test_cpu_lbu)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00011000010000000000000100010011;  // ADDI imm=388, rs1=x0  rd=x2 -> x2 = 0b000110000100 = 256+128+4 = 388
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101010100100100011;  // SW  offset1=0, src=x2, base=x5, offset2=18 -> save 388 to mem(1+18)
    instr_set[3] = 0b00000001001100000100001010000011;  // lb imm=19, rs1=x0  rd=x5 -> mem_addr = 0 + 19, load sram(19)'s byte to x5
                                                        //      without sign-extension, x5 = 0x00000084 = 128+4 = 132
    // x2 = 388, x5 = 132, sram[19] = 388
    instance -> test_instrs(instr_set, 4);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 388);
    EXPECT_EQ((int) instance -> reg_peep(5), 132);
}

TEST_F(test_cpu, test_cpu_beq_not_jump)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[1] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1 -> x5=2
    instr_set[2] = 0b00000000000000101000010001100011;  // BEQ offset=8, rs2=x0, rs1=x5
    instr_set[3] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1 -> x5=3
    instr_set[4] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1 -> x5=4
    int num_instr = 5;
    uint8_t  *code_region = new uint8_t[1024];
    for (int i = 0; i < num_instr; ++i) {
        code_region[4*i] = (uint8_t) ((instr_set[i] >> 24) & 0x000000ff);
        code_region[4*i+1] = (uint8_t) ((instr_set[i] >> 16) & 0x000000ff);
        code_region[4*i+2] = (uint8_t) ((instr_set[i] >> 8) & 0x000000ff);
        code_region[4*i+3] = (uint8_t) ((instr_set[i]) & 0x000000ff);
    }
    cpu *new_instance = new cpu(code_region, num_instr*4);
    new_instance -> run();
    EXPECT_EQ((int) new_instance -> reg_peep(5), 4);
}

TEST_F(test_cpu, test_cpu_bne_jump)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[1] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1 -> x5=2
    instr_set[2] = 0b00000000000000101001010001100011;  // BNE offset=8, rs2=x0, rs1=x5
    instr_set[3] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1 be skipped by branch)
    instr_set[4] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1 -> x5=3
    int num_instr = 5;
    uint8_t  *code_region = new uint8_t[1024];
    for (int i = 0; i < num_instr; ++i) {
        code_region[4*i] = (uint8_t) ((instr_set[i] >> 24) & 0x000000ff);
        code_region[4*i+1] = (uint8_t) ((instr_set[i] >> 16) & 0x000000ff);
        code_region[4*i+2] = (uint8_t) ((instr_set[i] >> 8) & 0x000000ff);
        code_region[4*i+3] = (uint8_t) ((instr_set[i]) & 0x000000ff);
    }
    cpu *new_instance = new cpu(code_region, num_instr*4);
    new_instance -> run();
    EXPECT_EQ((int) new_instance -> reg_peep(5), 3);
}

TEST_F(test_cpu, test_cpu_bge_loop){
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00000000100000000000001100010011;  // ADDI imm=8, rs1=x0  rd=x6 -> x6 = 8
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1
    instr_set[3] = 0b11111110010100110101111011100011;  // BGE offset=-4, rs2=x5, rs1=x6
    instr_set[4] = 0b00000000000100101000001010010011;  // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1

/*
 * Explanation:
 *      1: x6 = 8
        2: x5 = 1
        3: x5 = x5 + 1
        4: if (x6 >= x5), branch back to instr 3, else go to next instr (x5 = 9)
        5: x5 = x5 + 1 -> x5 = 10
 */
    int num_instr = 5;
    uint8_t  *code_region = new uint8_t[1024];
    for (int i = 0; i < num_instr; ++i) {
        code_region[4*i] = (uint8_t) ((instr_set[i] >> 24) & 0x000000ff);
        code_region[4*i+1] = (uint8_t) ((instr_set[i] >> 16) & 0x000000ff);
        code_region[4*i+2] = (uint8_t) ((instr_set[i] >> 8) & 0x000000ff);
        code_region[4*i+3] = (uint8_t) ((instr_set[i]) & 0x000000ff);
    }
    cpu *new_instance = new cpu(code_region, num_instr*4);
    new_instance -> run();
    EXPECT_EQ((int) new_instance -> reg_peep(6), 8);
    EXPECT_EQ((int) new_instance -> reg_peep(5), 10);
}

TEST_F(test_cpu, test_cpu_jal_loop){
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00000000100000000000001100010011;    // ADDI imm=8, rs1=x0  rd=x6 -> x6 = 8,           pc = 0
    instr_set[1] = 0b00000000000100000000001010010011;    // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1,           pc = 4
    instr_set[2] = 0b00000000000100101000001010010011;    // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1,      pc = 8
    instr_set[3] = 0b00000000011000101000010001100011;    // BEQ  offset= 8, rs2=x6, rs1=x5                 pc = 12,  next_pc = 16 or 20
    instr_set[4] = 0b11111111100111111111000011101111;    // JAL  offset=-8, rd=x1 -> x1 = pc+4 = 20,       pc = 16,  next_pc = pc-8
    instr_set[5] = 0b00000000000100101000001010010011;    // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1,      pc = 20
    int num_instr = 6;
    uint8_t  *code_region = new uint8_t[1024];
    for (int i = 0; i < num_instr; ++i) {
        code_region[4*i] = (uint8_t) ((instr_set[i] >> 24) & 0x000000ff);
        code_region[4*i+1] = (uint8_t) ((instr_set[i] >> 16) & 0x000000ff);
        code_region[4*i+2] = (uint8_t) ((instr_set[i] >> 8) & 0x000000ff);
        code_region[4*i+3] = (uint8_t) ((instr_set[i]) & 0x000000ff);
    }
    cpu *new_instance = new cpu(code_region, num_instr*4);
    new_instance -> run();
    EXPECT_EQ((int) new_instance -> reg_peep(6), 8);
    EXPECT_EQ((int) new_instance -> reg_peep(1), 20);
    EXPECT_EQ((int) new_instance -> reg_peep(5), 9);

//    1: x6 = 8
//    2: x5 = 1
//    3: x5 = x5 + 1
//    4: if (x5 == x6), branch to instr 6, else go to instr 5
//    5: jump back to instr 3
//    6: x5 = x5 + 1
//
//    get x6 = 8, x5 = 9, x1 = 20
}

TEST_F(test_cpu, test_cpu_jalr_loop) {
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00000000100000000000001100010011;    // ADDI imm=8, rs1=x0  rd=x6 -> x6 = 8,           pc = 0
    instr_set[1] = 0b00000000000100000000001010010011;    // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1,           pc = 4
    instr_set[2] = 0b00000000000100101000001010010011;    // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1,      pc = 8
    instr_set[3] = 0b00000000011000101000010001100011;    // BEQ  offset= 8, rs2=x6, rs1=x5                 pc = 12,  next_pc = 16 or 20
    instr_set[4] = 0b11111111000100110000000011100111;    // JALR imm=-16, rs1=x6, rd=x1 -> x1 = pc+4 = 20, pc = 16,  next_pc = pc -16+8 = pc-8
    instr_set[5] = 0b00000000000100101000001010010011;    // ADDI imm=1, rs1=x5  rd=x5 -> x5 = x5 + 1,      pc = 20
    int num_instr = 6;
    uint8_t  *code_region = new uint8_t[1024];
    for (int i = 0; i < num_instr; ++i) {
        code_region[4*i] = (uint8_t) ((instr_set[i] >> 24) & 0x000000ff);
        code_region[4*i+1] = (uint8_t) ((instr_set[i] >> 16) & 0x000000ff);
        code_region[4*i+2] = (uint8_t) ((instr_set[i] >> 8) & 0x000000ff);
        code_region[4*i+3] = (uint8_t) ((instr_set[i]) & 0x000000ff);
    }
    cpu *new_instance = new cpu(code_region, num_instr*4);
    new_instance -> run();
    EXPECT_EQ((int) new_instance -> reg_peep(6), 8);
    EXPECT_EQ((int) new_instance -> reg_peep(1), 20);
    EXPECT_EQ((int) new_instance -> reg_peep(5), 9);

//    1: x6 = 8
//    2: x5 = 1
//    3: x5 = x5 + 1
//    4: if (x5 == x6), branch to instr 6, else go to instr 5
//    5: jump back to instr 3
//    6: x5 = x5 + 1
//
//    get x6 = 8, x5 = 9, x1 = 20
}