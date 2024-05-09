#include "rainha.hpp"
#include <fstream>      //le e escreve file
#include <string>
#include <iostream>
#include <vector>
#include <utility>     //para usar std::pair
#include <cstddef>     //para usar std::size_t

using std::cout; 
using std::cin;
using std::endl; 
using std::string;
using std::vector;
using std::pair;


//vetor global que armazena as coordenadas das rainhas
vector <pair <int, int>> positions;

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
                positions.push_back({linecounter, i});
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

int isAttacked (const vector<pair<int, int>>& positions) {
    for (std::size_t i = 0; i < positions.size(); i++) {
        for (std::size_t j = 0; j < positions.size(); j++) {
            if (positions[i].first == positions[j].first) {
                return 0;
            }
        }
    }
    return 1;
}

int answer(const string& filename) {
    if (isValid(filename) == -1) {
        return -1;
    } else if (isValid(filename) == 1 && isAttacked (positions) == 0) {
        return 0;
    } else {
        return 1;
    }
}