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