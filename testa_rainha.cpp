#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainha.hpp"

TEST_CASE("Entrada inválida, não é 8x8", "[rainha]") {
    REQUIRE(answer("entradas/testcase1/teste1.txt") == -1);
    REQUIRE(answer("entradas/testcase1/teste2.txt") == -1);
    REQUIRE(answer("entradas/testcase1/teste3.txt") == -1);
}