//
// Created by Jacob Yan on 12/2/18.
//
#include <string>
using namespace std;
#ifndef PROJECT_TRANSLATOR_H
#define PROJECT_TRANSLATOR_H

class translator {

private:
    string loadAndStore(string instruction);
    string branch(string instruction);
    string AluI(string instruction);
    string Alu(string instruction);
    string jumpAndLink(string instruction);

    string decToBin(int num, int length);
    string preprocess(string instruction);

public:
    void instructionToBin(string in_filename, string out_filename);
};

#endif //PROJECT_TRANSLATOR_H
