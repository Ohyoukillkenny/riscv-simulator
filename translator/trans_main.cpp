#include "translator.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    if(argc == 2 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        std::cout << "Usage:  risc-translator   INPUT_FILE    OUTPUT_FILE" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "[-h|--help] - show usage of risc-translator" << std::endl;
        std::cout << "INPUT_FILE  - path of the assembly code file" << std::endl;
        std::cout << "OUTPUT_FILE - path of the instruction code file" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        return 0;
    }

    if (argc != 3) {
        std::cout << "Usage:  risc-translator   INPUT_FILE    OUTPUT_FILE" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << "[-h|--help] - show usage of risc-translator" << std::endl;
        std::cout << "INPUT_FILE  - path of the assembly code file" << std::endl;
        std::cout << "OUTPUT_FILE - path of the instruction code file" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        return 0;
    }

    string assem_file_name = std::string(argv[1]);
    string inst_file_name = std::string(argv[2]);

    translator *instance = new translator();
    instance -> instructionToBin(assem_file_name, inst_file_name);
    return 0;
}