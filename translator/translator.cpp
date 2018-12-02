//
// Created by Jacob Yan on 12/2/18.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include "translator.h"

string translator::decToBin(int num, int length) {
    bool flag = (num < 0);
    if (flag) num *= -1;

    string s;
    while (num) {
        s = to_string(num % 2) + s;
        num /= 2;
    }

    string prefix(length - s.size(), '0');

    if (!flag) return prefix + s;

    string str = prefix + s;
    for (int i = 0; i < str.size(); i++)
        str[i] = str[i] == '0' ? '1' : '0';

    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '1') str[i] = '0';
        else {str[i] = '1'; break;}
    }
    return str;
}

string translator::preprocess(string instruction) {
    int index = instruction.find(" "), idx = 0;
    string s1 = instruction.substr(0, index), s2 = instruction.substr(index+1);
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    while((idx = s2.find(' ',idx)) != string::npos) s2.erase(idx,1);
    return s1 + " " + s2;
}

string translator::loadAndStore(string instruction) {
    map<string, string> load, store;
    load = {{"LB", "000"}, {"LH", "001"}, {"LW", "010"}, {"LBU", "100"}, {"LHU", "101"}};
    store = {{"SB", "000"},{"SH", "001"},{"SW", "010"}};

    int index1 = instruction.find(" ");
    int index2 = instruction.find(",");
    int index3 = instruction.find("(");
    int index4 = instruction.rfind("x");

    string op = instruction.substr(0, index1);
    if (load.find(op) == load.end() && store.find(op) == store.end()) return "";
    string offset = decToBin(atoi(instruction.substr(index2 + 1, index3 - index2 - 1).c_str()), 12);
    string rs = decToBin(atoi(instruction.substr(index4 + 1, instruction.size() - index4 - 2).c_str()), 5);
    string rd = decToBin(atoi(instruction.substr(index1 + 2, index2 - index1 - 2).c_str()), 5);


    if (load.find(op) != load.end())
        return offset + rs + load[op] + rd + "0000011";

    if (store.find(op) != store.end()) {
        return offset.substr(5) + rd + rs + store[op] + offset.substr(0,5) + "0100011";
    }
    std::cout << "Translator: loadAndStore cannot translate the instruction." << std::endl;
    return NULL;
}

string translator::branch(string instruction) {
    map<string, string> branch;
    branch = {{"BEQ", "000"}, {"BNE", "001"}, {"BLT", "100"}, {"BGE", "101"}, {"BLTU", "110"}, {"BGEU", "111"}};

    int index1 = instruction.find(" ");
    int index2 = instruction.find(",");
    int index3 = instruction.rfind(",");

    string op = instruction.substr(0, index1);
    if (branch.find(op) == branch.end()) return "";

    string offset = decToBin(atoi(instruction.substr(index3+1).c_str())/2, 12);
    string rs1 = decToBin(atoi(instruction.substr(index1+2, index2-index1-2).c_str()), 5);
    string rs2 = decToBin(atoi(instruction.substr(index2+2, index3-index2-2).c_str()), 5);

    return offset.substr(0,1) +  offset.substr(2,6) +  rs2 +  rs1 +  branch[op] + offset.substr(8) + offset.substr(1,1) + "1100011";
}

string translator::AluI(string instruction) {
    map<string, string> immediate;
    map<string, string> shift;

    immediate = {{"ADDI", "000"}, {"SLTI", "010"}, {"SLTIU", "011"},
                 {"XORI", "100"}, {"ORI", "110"}, {"ANDI", "111"}};
    shift = {{"SLLI", "001"}, {"SRLI", "101"}, {"SRAI", "101"}};

    int index1 = instruction.find(" ");
    int index2 = instruction.find(",");
    int index3 = instruction.rfind(",");

    string op = instruction.substr(0, index1);

    string imm = decToBin(atoi(instruction.substr(index3+1).c_str()), 12);
    string rs1 = decToBin(atoi(instruction.substr(index2+2, index3-index2-2).c_str()), 5);
    string rd = decToBin(atoi(instruction.substr(index1+2, index2-index1-2).c_str()), 5);

    if (immediate.find(op) != immediate.end()) {
        return imm + rs1 + immediate[op] + rd + "0010011";
    }

    if (shift.find(op) != shift.end()) {
        if(op == "SRAI") imm = imm.replace(1,1,"1");
        return imm + rs1 + shift[op] + rd + "0010011";
    }

    return "";
}

string translator::Alu(string instruction) {
    map<string, string> alu;
    string s = "0000000";
    alu = {{"ADD", "000"}, {"SUB", "000"}, {"SLL", "001"},
           {"SLT", "010"}, {"SLTU", "011"}, {"XOR", "100"},
           {"SRL", "101"}, {"SRA", "101"}, {"OR", "110"}, {"AND", "111"}};

    int index = instruction.find(" ");
    string op = instruction.substr(0, index);

    if (alu.find(op) == alu.end()) return "";

    vector<int> tmp;
    for (int i = index + 1; i < instruction.size(); ++i)
        if (instruction[i] == ',') tmp.push_back(i);

    string rd = decToBin(atoi(instruction.substr(index + 2, tmp[0] - index - 2).c_str()), 5);
    string rs1 = decToBin(atoi(instruction.substr(tmp[0] + 2, tmp[1] - tmp[0] - 2).c_str()), 5);
    string rs2 = decToBin(atoi(instruction.substr(tmp[1] + 2, instruction.size() - tmp[1] - 2).c_str()), 5);

    s = s + rs2 + rs1 + alu[op] + rd + "0110011";
    if (op == "SUB" or op == "SRA") s[1] = '1';
    return s;
}

string translator::jumpAndLink(string instruction) {
    map<string, string> jump;
    int index1 = instruction.find(" ");
    string op = instruction.substr(0, index1);
    if(op == "JAL"){
        int index2 = instruction.find(",");
        string rd = decToBin(atoi(instruction.substr(index1+2, index2-index1-2).c_str()), 5);
        string offset = decToBin(atoi(instruction.substr(index2+1).c_str())/2, 20);
        return offset.substr(0,1) + offset.substr(10,10) + offset.substr(9,1) + offset.substr(1,8) + rd + "1101111";
    }

    if(op == "JALR"){
        int index2 = instruction.find(",");
        int index3 = instruction.rfind(",");
        string rd = decToBin(atoi(instruction.substr(index1+2, index2-index1-2).c_str()), 5);
        string rs1 = decToBin(atoi(instruction.substr(index2+2, index3-index2-2).c_str()), 5);
        string offset = decToBin(atoi(instruction.substr(index3+1).c_str()), 12);

        return offset + rs1 + "000" + rd + "1100111";
    }

    return "";
}

void translator::instructionToBin(string in_filename, string out_filename) {
    ifstream in(in_filename);
    ofstream out(out_filename);
    if(!in.is_open()) {
        std::cout << "Could not open the " << in_filename << " file." << std::endl;
        return;
    }
    string line, s;
    while (getline(in, line)) {
        line = preprocess(line);
        if ((s = loadAndStore(line)) != "") out <<  s << endl;
        else if ((s = branch(line)) != "") out <<  s << endl;
        else if ((s = AluI(line)) != "") out <<  s << endl;
        else if ((s = Alu(line)) != "") out <<  s << endl;
        else if ((s = jumpAndLink(line)) != "") out << s << endl;
    }
    in.close();
    out.close();
}

