# Problema das 8 rainhas

## Descrição

Consiste em receber um arquivo de texto com um tabuleiro de xadrez na forma de uma matriz 8x8. O número 0 indica que há um espaço vazio e o 1 indica que há uma rainha naquela posição.

Uma entrada é solução se há é uma matriz 8x8, tem exatamente 8 rainhas no tabuleiro, as entradas da matriz são 0 ou 1 e se nenhuma da 8 rainhas do tabuleiro se ataca.

Na saída, 1 indica que a entrada é solução do problema, 0 indica que não é solução e -1 indica que a entrada é inválida.

As entradas estão em arquivos .txt na pasta "entrada". Caso a entrada seja válida, será criado um arquivo na pasta "ataques" mostrando qual par de rainhas se ataca. Se a entrada for solução o arquivo gerado ficará vazio.

Está escrito em C++ e inclui testes abrangentes usando a framework de testes Catch2.

## Requisitos

Um compilador C++, aqui foi usado o g++; Framework de testes Catch2.
Opcional: Doxygen para a documentação; Verificador de leaks de memória Valgrind; Cpplint para padrão de código; Verificador de cobertura gcov; debugger gdb; Verificador estático cppcheck.

## Instruções

 Crie um arquivo para o makefile e copie-o para o seu projeto. Com todos os programas instalados, digite "make" no terminal para compilar e rodar os testes.
