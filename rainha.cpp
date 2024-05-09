#include "rainha.hpp"
#include <fstream>      //le e escreve file
#include <string>
#include <iostream>

using std::cout; 
using std::cin;
using std::endl; 
using std::string;


int isValid (const std::string& filename) {
    std::ifstream file(filename);
    string line;
    int linecounter = 0;
    int queencounter = 0;

    if (!file) {
        std::cout << "Erro ao abrir o arquivo." << filename << std::endl;
        return -1;
    } 
    
    while (getline(file, line)) {
        if (line.size() != 8) {
            return -1;
        }
        for (int i = 0; i < 8; i++) {
            char c = line[i];
            if (c != '0' && c != '1') {
                return -1;
            }
            if (c == '1') {
                queencounter++;
            }
        }   
        linecounter ++;
    }

    file.close();
    if (linecounter != 8) {
        return -1;
    }
    if (queencounter != 8) {
        return -1;
    }

    return 1;
}

int answer(const string& filename) {
    return isValid(filename);
}