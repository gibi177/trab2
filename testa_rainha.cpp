#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainha.hpp"

TEST_CASE("Entrada inválida, não é 8x8", "[rainha]") {
    REQUIRE(answer("entradas/testcase1/teste1.txt") == -1);
    REQUIRE(answer("entradas/testcase1/teste2.txt") == -1);
    REQUIRE(answer("entradas/testcase1/teste3.txt") == -1);
}

TEST_CASE("Entrada inválida, caractere n binario", "[rainha]") {
    REQUIRE(answer("entradas/testcase2/teste4.txt") == -1);
    REQUIRE(answer("entradas/testcase2/teste5.txt") == -1);
    REQUIRE(answer("entradas/testcase2/teste6.txt") == -1);
}

TEST_CASE("Entrada inválida, numero de rainhas diferente de 8", "[rainha]") {
    REQUIRE(answer("entradas/testcase3/teste7.txt") == -1);
    REQUIRE(answer("entradas/testcase3/teste8.txt") == -1);
    REQUIRE(answer("entradas/testcase3/teste9.txt") == -1);
}

TEST_CASE("Testa ataque mesma linha", "[rainha]") {
    REQUIRE(answer("entradas/testcase4/teste10.txt") == 0);
    REQUIRE(answer("entradas/testcase4/teste11.txt") == 0);
    REQUIRE(answer("entradas/testcase4/teste12.txt") == 0);
}

TEST_CASE("Testa ataque mesma coluna", "[rainha]") {
    REQUIRE(answer("entradas/testcase5/teste13.txt") == 0);
    REQUIRE(answer("entradas/testcase5/teste14.txt") == 0);
    REQUIRE(answer("entradas/testcase5/teste15.txt") == 0);
}

TEST_CASE("Testa ataque diagonal", "[rainha]") {
    REQUIRE(answer("entradas/testcase6/teste16.txt") == 0);
    REQUIRE(answer("entradas/testcase6/teste17.txt") == 0);
    REQUIRE(answer("entradas/testcase6/teste18.txt") == 0);
}

TEST_CASE("Soluções validas", "[rainha]") {
    REQUIRE(answer("entradas/testcase7/teste19.txt") == 1);
    REQUIRE(answer("entradas/testcase7/teste20.txt") == 1);
}

TEST_CASE("Erro ao abrir arquivo, caminho errado", "[rainha]") {
    REQUIRE(answer("entradas/testcase5252552/teste.txt") == -2);
    REQUIRE(answer("entradas/testcase848484/teste.txt") == -2);
}
