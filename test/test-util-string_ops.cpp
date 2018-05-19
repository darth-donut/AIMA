//
// @author: jiahong
// @date  : 20/05/18 2:25 AM
//

#include <vector>
#include <string>

#include "string_ops.h"
#include "catch.hpp"

using namespace aima;

TEST_CASE("String ops test", "SOT1") {
    SECTION("String split on a sentence works as expected") {
        const std::string str = "hello world ! ? a word";
        REQUIRE(split(str) == std::vector<std::string>({"hello", "world", "!", "?", "a", "word"}));
    }

    SECTION("String split on one word returns a singleton vector") {
        const std::string str = "world";
        REQUIRE(split(str) == std::vector<std::string>({"world"}));
    }

    SECTION("String split on empty string returns an empty vector") {
        const std::string str = "";
        REQUIRE(split(str) == std::vector<std::string>({""}));
    }
}
