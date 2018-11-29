#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "cpu/cpu.h"

int main() {
    int code_size = 1024;

    // allocate the code region
    auto *code_region = new uint8_t[code_size];
    auto *inst_file_name = "/Users/klk/CLionProjects/riscv-simulator/exe.txt";
    // read the code from inst_file
    std::ifstream code_file(inst_file_name);

    // check if we have opened the file
    if(!code_file.is_open()) {
        std::cout << "Could not open the " <<  inst_file_name << " file." << std::endl;
        return -1;
    }

    // copy the code region
    int num = 0;
    std::string temp;
    uint8_t code;
    while (std::getline(code_file, temp)) {
        std::string code_string = temp.substr(0,32);
        for (int i = 0; i < 4; ++i) {
            code = 0b00000000;
            for (int j = 0; j < 8; ++j){
                if (code_string[8*i+j] - '0' == 0){
                    continue;
                } else {
                    code = code | (uint8_t) (1 << (7-j));
                }
            }
            code_region[num] = code;
            num ++;
        }
    }
    // close the file
    code_file.close();

    // create a cpu, run it and view its final status
    cpu *instance = new cpu(code_region, num);
    instance -> run();
//    instance -> run_debug(); // see status of the cpu after processing each instruction
    instance -> print();

    return 0;
}