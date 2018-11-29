#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "cpu/cpu.h"

int main(int argc, char *argv[]) {
    // by default we are not printing the cpu status after processing every instruction
    bool print_after_each_inst = false;

    // are the parameters provided if not print help
    if (argc != 2 && argc != 3) {
        std::cout << "Usage: riscv-simulator [-p] CODE_FILE" << std::endl;
        std::cout << std::endl;
        std::cout << "[-p]      - print CPU status after processing each instruction" << std::endl;
        std::cout << "CODE_FILE - path of the instruction file" << std::endl;
        return 0;
    }

    if(argc == 2 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        std::cout << "Usage:      riscv-simulator [-p] CODE_FILE" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "[-p]      - print CPU status after each instruction" << std::endl;
        std::cout << "CODE_FILE - path of the instruction file" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        return 0;
    }

    if(argc == 3 && std::string(argv[1]) == "-p") {
        std::cout << "Running in the print all status mode" << std::endl;
        print_after_each_inst = true;
    }


    int code_size = 1024;

    // allocate the code region
    auto *code_region = new uint8_t[code_size];

    std::string inst_file_name;
    // read the code from inst_file
    if (argc == 2)
        inst_file_name = std::string(argv[1]);
    else
        inst_file_name = std::string(argv[2]);

    std::ifstream code_file(inst_file_name);
    // check if we could open the file
    if(!code_file.is_open()) {
        std::cout << "Could not open the " << inst_file_name << " file." << std::endl;
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
    if (print_after_each_inst) {
        instance->run_debug();
    }
    else{
        instance -> run();
        instance -> print();
    }
    return 0;
}