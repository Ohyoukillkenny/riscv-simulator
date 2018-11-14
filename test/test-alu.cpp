//
// Created by Lingkun Kong on 11/13/18.
//

#include <gtest/gtest.h>
#include "../alu.h"

class test_alu: public testing::Test {
public:

    // the instance of the mmu
    alu *instance;

    test_alu( ) {
        // create the instance
        instance = new alu;
    }

    void SetUp() override {

    }

    void TearDown() override {}

    ~test_alu() override {
        // do the cleanup
        delete instance;
    }
};

TEST_F(test_alu, test_alu_add)
{
    // add: 1 + 2 = 3
    uint32_t in1 = 0b00000000000000000000000000000001;
    uint32_t in2 = 0b00000000000000000000000000000010;
    uint8_t op = 0b00000000;
    uint32_t out = this->instance->calculate(in1, in2, op);
    EXPECT_EQ(out, 3);
}

TEST_F(test_alu, test_alu_sub)
{
    // add: 5 - 2 = 3
    uint32_t in1 = 0b00000000000000000000000000000101;
    uint32_t in2 = 0b00000000000000000000000000000010;
    uint8_t op = 0b00001000;
    uint32_t out = this->instance->calculate(in1, in2, op);
    EXPECT_EQ(out, 3);
}

TEST_F(test_alu, test_alu_sra)
{
    // sra
    uint32_t in1 = 0b10000000000000000000000000000101;
    uint32_t in2 = 0b00000000000000000000000000000110;
    uint8_t op = 13;
    uint32_t out = this->instance->calculate(in1, in2, op);
    uint32_t ref = 0b11111110000000000000000000000000;
    EXPECT_EQ(out, ref);
}

TEST_F(test_alu, test_alu_slt)
{
    uint32_t in1 = 0b10000000000000000000000000000101;
    uint32_t in2 = 0b00000000000000000000000000000110;
    uint8_t op = 2;
    uint32_t out = this->instance->calculate(in1, in2, op);
    uint32_t ref = 1;
    EXPECT_EQ(out, ref);
}

TEST_F(test_alu, test_alu_slt2)
{
    uint32_t in1 = 0b00000000000000000000000000000111;
    uint32_t in2 = 0b00000000000000000000000000000110;
    uint8_t op = 2;
    uint32_t out = this->instance->calculate(in1, in2, op);
    uint32_t ref = 0;
    EXPECT_EQ(out, ref);
}

TEST_F(test_alu, test_alu_sltu)
{
    uint32_t in1 = 0b10000000000000000000000000000101;
    uint32_t in2 = 0b00000000000000000000000000000110;
    uint8_t op = 3;
    uint32_t out = this->instance->calculate(in1, in2, op);
    uint32_t ref = 0;
    EXPECT_EQ(out, ref);
}