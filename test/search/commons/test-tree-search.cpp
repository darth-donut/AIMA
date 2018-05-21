//
// @author: jiahong
// @date  : 19/05/18 5:50 PM
//


#include <string>
#include <iostream>

#include "tree_search.h"
#include "../../catch.hpp"
#include "romania.h"

/* does not test for paths with no solution - romanian map has cycles that tree search does not deal well with */
TEST_CASE("Test tree search 1", "[TTS1]") {
    SECTION("Tree search works on the Romanian map, from Arad to Pitesti (long path)") {
        using namespace aima;
        RomaniaMap problem("Arad", "Pitesti");
        std::vector<std::string> solution = {"Arad", "Timisoara", "Lugoj", "Mehadia", "Drobeta", "Craiova", "Pitesti"};
        auto res = tree_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == solution.front());
        REQUIRE(res->path().back() == solution.back());
    }

    SECTION("Tree search works on the Romanian map, from Oradea to Bucharest (short path)") {
        using namespace aima;
        RomaniaMap problem("Oradea", "Bucharest");
        std::vector<std::string> solution = {"Oradea", "Sibiu", "Rimnicu Vilcea", "Pitesti", "Bucharest"};
        auto res = tree_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == solution.front());
        REQUIRE(res->path().back() == solution.back());
    }

    SECTION("Tree search works on the Romanian map, from Oradea to Oradea (single node, goal node)") {
        using namespace aima;
        RomaniaMap problem("Oradea", "Oradea");
        std::vector<std::string> solution = {"Oradea"};
        auto res = tree_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == solution.front());
        REQUIRE(res->path().back() == solution.back());
    }
}
