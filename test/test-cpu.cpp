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
    instr_set[0] = 0b00010000010000000000000100010011;  // ADDI imm=4, rs1=x0  rd=x2 -> x2 = 260
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101010100100100011;  // SW  offset1=0, src=x2, base=x5, offset2=18 -> save 4 to mem(1+18)
    instr_set[3] = 0b11111100111000000000001010010011;  // addi imm=-50 rs1=x0  rd=x5
    instr_set[4] = 0b00000000000100101000001010010011;  // ADDI imm=1   rs1=x5  rd=x5
    instr_set[5] = 0b00000000000000101000100100110011;  // ADD  rs2=0   rs1=x5  rd=18
    // x2 = 4, x5 = -49, x18 = -49, sram[19] = 4
    instance -> test_instrs(instr_set, 6);
    EXPECT_EQ((int) instance -> reg_peep(18), -49);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 260);
}

TEST_F(test_cpu, test_cpu_sb)
{
    uint32_t *instr_set = new uint32_t[10];
    instr_set[0] = 0b00010000010000000000000100010011;  // ADDI imm=4, rs1=x0  rd=x2 -> x2 = 0b000100000100 = 256+4 = 260
    instr_set[1] = 0b00000000000100000000001010010011;  // ADDI imm=1, rs1=x0  rd=x5 -> x5 = 1
    instr_set[2] = 0b00000000001000101010100100100011;  // SW  offset1=0, src=x2's byte, base=x5, offset2=18 -> save 4 to mem(1+18)
    instr_set[3] = 0b11111100111000000000001010010011;  // addi imm=-50 rs1=x0  rd=x5
    instr_set[4] = 0b00000000000100101000001010010011;  // ADDI imm=1   rs1=x5  rd=x5
    instr_set[5] = 0b00000000000000101000100100110011;  // ADD  rs2=0   rs1=x5  rd=18
    // x2 = 4, x5 = -49, x18 = -49, sram[19] = 4
    instance -> test_instrs(instr_set, 6);
    EXPECT_EQ((int) instance -> reg_peep(18), -49);
    EXPECT_EQ((int) instance -> mem_peep((uint32_t)19), 4);
}