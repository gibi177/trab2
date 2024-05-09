#include "rainha.hpp"
#include <fstream>      //le e escreve file
#include <string>
#include <iostream>

using std::cout; 
using std::cin;
using std::endl; 
using std::string;


int isBinary8x8 (const std::string& filename) {
    std::ifstream file(filename);
    string line;
    int linecounter = 0;

    if (!file) {
        std::cout << "Erro ao abrir o arquivo." << filename << std::endl;
        return -1;
    } 
    
    while (getline(file, line)) {
        if (line.size() != 8) {
            return -1;
        }
        for (char c : line) {
            if (c != '0' && c != '1') {
                return -1;
            }
        }   
        linecounter ++;
    }

    file.close();
    if (linecounter != 8) {
        return -1;
    }

    return 1;
}

int answer(const string& filename) {
    return isBinary8x8(filename);
}