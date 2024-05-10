#include "rainha.hpp"
#include <fstream>      //le e escreve file
#include <string>
#include <iostream>
#include <vector>
#include <utility>     //para usar std::pair
#include <cstddef>     //para usar std::size_t
#include <cmath>       //para usar std::abs

using std::cout; 
using std::cin;
using std::endl; 
using std::string;
using std::vector;
using std::pair;
using std::abs;


//vetor global que armazena as coordenadas das rainhas
vector <pair <int, int>> positions;


//Checa se o input é matriz 8x8, se tem 8 rainhas, se a matriz é binaria e cria vetor com as coordenadas das rainhas
int isValid (const std::string& filename) {
    std::ifstream file(filename);
    string line;
    int linecounter = 0;
    int queencounter = 0;
    positions.clear();   //cada vez q a funcao for chamada o vetor é limpado para ficar vazio

    if (!file) {
        std::cout << "Erro ao abrir o arquivo." << filename << std::endl;
        return -2;
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

//Checa se as rainhas se atacam na horizontal, vertical e diagonal
int isAttacked (const vector<pair<int, int>>& positions) {
    for (std::size_t i = 0; i < positions.size(); i++) {
        for (std::size_t j = i + 1; j < positions.size(); j++) {
            if (positions[i].first == positions[j].first || positions[i].second == positions[j].second ||
                abs(positions[i].first - positions[j].first) == abs(positions[i].second - positions[j].second)) {
                return 1;
            }
        }
    }
    return 0;
}

//Usa as funcoes de cima para retornar a resposta final
int answer(const string& filename) {
    int valid = isValid(filename);

    if (valid == -1) {
        return -1;
    } else if (isAttacked(positions) == 1) {
        return 0;
    } else {
        return 1;
    }
}