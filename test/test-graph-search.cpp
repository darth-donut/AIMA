//
// @author: jiahong
// @date  : 20/05/18 9:52 PM
//


#include <string>
#include <vector>

#include "catch.hpp"
#include "graph_search.h"
#include "romania.h"


TEST_CASE("Test graph search 1", "[TGS1]") {
    SECTION("Graph search works on the Romanian map, from Arad to Pitesti (long path)") {
        using namespace aima;
        RomaniaMap problem("Arad", "Pitesti");
        std::vector<std::string> solution = {"Arad", "Timisoara", "Lugoj", "Mehadia", "Drobeta", "Craiova", "Pitesti"};
        auto res = graph_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == solution.front());
        REQUIRE(res->path().back() == solution.back());
    }

    SECTION("Graph search works on the Romanian map, from Zerind to Eforie (very long path)") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Eforie";
        RomaniaMap problem(start, end);
        auto res = graph_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }

    SECTION("Graph search works on the Romanian map, from Zerind to Neami(very long path)") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Neami";
        RomaniaMap problem(start, end);
        auto res = graph_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }

    SECTION("Graph search works on the Romanian map, on a single node, goal node") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Zerind";
        RomaniaMap problem(start, end);
        auto res = graph_search(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }
}
