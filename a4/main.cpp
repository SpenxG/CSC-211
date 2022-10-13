
#include "catch/catch.hpp"
#include "bigint/bigint.h"
#include <sstream>
#include <fstream>

using std::string;

typedef std::vector<vec_bin> vec;

TEST_CASE("Constructors", "[constructors]") {
    SECTION("Default") {
        bigint x = 0;
        REQUIRE(x.getNumber() == vec{0});
    }
}

TEST_CASE("Displaying Bigints", "[display]") {
    const bigint x = 1234;
    SECTION("to_string()") {
        REQUIRE(x.to_string() == std::string("1234"));
    }
}

TEST_CASE("Comparators", "[compare]") {

}

TEST_CASE("Arithmetic", "[math]") {
    SECTION("Addition") {
        bigint x = 10;
        bigint y = 10;
        bigint z = x + y;
        REQUIRE(z.getNumber() == vec{0, 2});
    }

}

TEST_CASE("Operators", "[operators]") {

}
