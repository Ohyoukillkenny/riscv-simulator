#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "cpu/cpu.h"
#include "translator/translator.h"

int main(int argc, char *argv[]) {
    // assembly mode
    bool assembly_mode = false;
    // by default we are not printing the cpu status after processing every instruction
    bool print_after_each_inst = false;

    // are the parameters provided if not print help
    if (argc != 2 && argc != 3 && argc != 4) {
        std::cout << "risc-simulator: cannot recognize the command" << std::endl;
        std::cout << std::endl;
        std::cout << "Usage:     risc-simulator [-a] [-p]   CODE_FILE" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "[-h|--help] - show usage of risc-simulator" << std::endl;
        std::cout << "[-a]        - process the assembly code" << std::endl;
        std::cout << "[-p]        - print CPU status after each instruction" << std::endl;
        std::cout << "CODE_FILE   - path of the assembly|binary code file" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        return 0;
    }

    if(argc == 2 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        std::cout << "Usage:     risc-simulator [-a] [-p]   CODE_FILE" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "[-h|--help] - show usage of risc-simulator" << std::endl;
        std::cout << "[-a]        - process the assembly code" << std::endl;
        std::cout << "[-p]        - print CPU status after each instruction" << std::endl;
        std::cout << "CODE_FILE   - path of the assembly|binary code file" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        return 0;
    }
    if (argc == 2){
        ;
    } else if(argc == 3 && std::string(argv[1]) == "-p") {
        std::cout << "Running in the print all status mode" << std::endl;
        print_after_each_inst = true;
    } else if(argc == 3 && std::string(argv[1]) == "-a") {
        std::cout << "Running in the assembly processing mode" << std::endl;
        assembly_mode = true;
    } else if(argc == 3 && (std::string(argv[1]) == "-ap" || std::string(argv[1]) == "-pa")) {
        std::cout << "Running in the print all status mode" << std::endl;    
        std::cout << "Running in the assembly processing mode" << std::endl;
        print_after_each_inst = true;
        assembly_mode = true;
    } else if(argc == 4 && (std::string(argv[1]) == "-a" && std::string(argv[2]) == "-p")) {
        std::cout << "Running in the print all status mode" << std::endl;
        std::cout << "Running in the assembly processing mode" << std::endl;
        print_after_each_inst = true;
        assembly_mode = true;
    } else if(argc == 4 && (std::string(argv[1]) == "-p" && std::string(argv[2]) == "-a")) {
        std::cout << "Running in the print all status mode" << std::endl;
        std::cout << "Running in the assembly processing mode" << std::endl;
        print_after_each_inst = true;
        assembly_mode = true;
    } else {
        std::cout << "risc-simulator: cannot recognize the command" << std::endl;
        std::cout << std::endl;
        std::cout << "Usage:     risc-simulator [-a] [-p]   CODE_FILE" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "[-h|--help] - show usage of risc-simulator" << std::endl;
        std::cout << "[-a]        - process the assembly code" << std::endl;
        std::cout << "[-p]        - print CPU status after each instruction" << std::endl;
        std::cout << "CODE_FILE   - path of the assembly|binary code file" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        return 0;
    }

    int code_size = 1024;

    // allocate the code region
    auto *code_region = new uint8_t[code_size];

    std::string code_file_name;
    // read the code from inst_file
    if (argc == 2)
        code_file_name = std::string(argv[1]);
    else if (argc == 3)
        code_file_name = std::string(argv[2]);
    else
        code_file_name = std::string(argv[3]);

    // assembly mode, translate the assembly to binary
    if (assembly_mode){
        string inst_file_name = "risc_bin_temp.txt";
        translator *instance = new translator();
        instance -> instructionToBin(code_file_name, inst_file_name);
        code_file_name = inst_file_name;
    }

    std::ifstream code_file(code_file_name);
    // check if we could open the file
    if(!code_file.is_open()) {
        std::cout << "Could not open the " << code_file_name << " file." << std::endl;
        return -1;
    }

    // copy the code region
    int num = 0;
    std::string temp;
    uint8_t code;
    while (std::getline(code_file, temp)) {
        if (temp == "\0"){
            continue;
        }
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