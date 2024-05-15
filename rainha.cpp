#include "rainha.hpp"
#include <fstream>      //le e escreve file
#include <string>
#include <iostream>
#include <vector>
#include <utility>     //para usar std::pair
#include <cstddef>     //para usar std::size_t
#include <cmath>       //para usar std::abs
#include <set>

using namespace std;   // Pra n precisar botar ::std 

// Vetor global que armazena as coordenadas das rainhas
vector <pair <int, int>> positions;


// Checa se o input é matriz 8x8, se tem 8 rainhas, se a matriz é binaria e cria vetor com as coordenadas das rainhas
int isValid(const string& filename) {
    ifstream file(filename);
    string line;
    int linecounter = 0;
    int queencounter = 0;
    positions.clear();   // Cada vez q a funcao for chamada o vetor é limpado para ficar vazio

    if (!file) {   // Arquivo não abriu
        return -2;
    }
   
    while (getline(file, line)) {
        if (line.size() != 8) {
            return -1;
        }
        for (int i = 0; i < 8; i++) {
            char c = line[i];
            if (c != '0' && c != '1') {   // Entrada da matriz nao e binaria
                return -1;
            }
            if (c == '1') {
                queencounter++;
                positions.push_back({linecounter, i});
            }
        } 
        linecounter++;
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

// Checa se as rainhas se atacam na horizontal, vertical e diagonal
bool isAttacked(const vector<pair<int, int>>& positions) {
    static int counter = 1;   // Variavel estatica local, usada no nome do arquivo a ser criado
    bool isunderattack = false;

    // Cria arquivo com as rainhas que se atacam nesse teste
    // Note que se a matriz for solucao, cria um arquivo que ficara vazio (sem ataques)
    string ataquesfile = "ataques/atck" + to_string(counter);
    ofstream createdfile(ataquesfile);

    for (size_t i = 0; i < positions.size(); i++) {
        for (size_t j = i + 1; j < positions.size(); j++) {

            // Todos os casos que as rainhas se atacam
            if (positions[i].first == positions[j].first || positions[i].second == positions[j].second ||
                abs(positions[i].first - positions[j].first) == abs(positions[i].second - positions[j].second)) {
                
                // Escreve no arquivo as rainhas que se atacam, um par por linha
                if (createdfile.is_open()) {
                    createdfile << positions[i].first << "," << positions[i].second << " "
                                << positions[j].first << "," << positions[j].second << endl; 
                } else {
                    cout << "falha ao criar arquivo" << endl;
                }
                isunderattack = true;
            }
        }
    }
    counter++;
    createdfile.close();   // Fecha arquivo
    return isunderattack;
}

// Usa as funcoes de cima para retornar a resposta final
int answer(const string& filename) {
    
    int valid = isValid(filename);
    if (valid != 1) {
        return valid;
    }

    bool isunderattack = isAttacked(positions);
    if (isunderattack) {
        return 0;
    }
    return 1;
}
