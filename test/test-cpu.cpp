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
    instance -> test_instrs(instr_set, 3);
    EXPECT_EQ((int) instance -> reg_peep(18), -49);
}