//
// @author: jiahong
// @date  : 27/05/18 5:46 PM
//

#include "romania.h"
#include "ids.h"
#include "catch.hpp"


TEST_CASE("Test iterative depth first search 1", "[TIDS1]") {
    SECTION("IDS works on the Romanian map, from Arad to Pitesti") {
        using namespace aima;
        RomaniaMap problem("Arad", "Pitesti");
        std::vector<std::string> solution = {"Arad", "Timisoara", "Lugoj", "Mehadia", "Drobeta", "Craiova", "Pitesti"};
        auto res = ids(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == solution.front());
        REQUIRE(res->path().back() == solution.back());
    }

    SECTION("IDS works on the Romanian map, from Zerind to Eforie (very long path)") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Eforie";
        RomaniaMap problem(start, end);
        auto res = ids(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }

    SECTION("IDS works on the Romanian map, from Zerind to Neamt(very long path)") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Neamt";
        RomaniaMap problem(start, end);
        auto res = ids(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }

    SECTION("IDS works on the Romanian map, on a single node, goal node") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Zerind";
        RomaniaMap problem(start, end);
        auto res = ids(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }
}
