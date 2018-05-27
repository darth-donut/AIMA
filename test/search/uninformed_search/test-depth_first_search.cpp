//
// @author: jiahong
// @date  : 27/05/18 5:21 PM
//


#include "catch.hpp"

#include "romania.h"
#include "dfs.h"


// NOTE: test cases have to be carefully chosen from the map (dfs is a tree implementation here,
// therefore, there might be some paths that continue on forever)

TEST_CASE("Depth first search works on the romanian map", "[TDFS1]") {
    SECTION("Depth first search returns a solution from Oradea to Zerind") {
        using namespace aima;
        const std::string start = "Oradea";
        const std::string goal = "Zerind";
        RomaniaMap problem(start, goal);

        auto res = dfs(problem);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }

    SECTION("Depth first search returns a solution from Arad to Zerind") {
        using namespace aima;
        const std::string start = "Arad";
        const std::string goal = "Zerind";
        RomaniaMap problem(start, goal);

        auto res = dfs(problem);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }

    SECTION("Depth first search returns a solution from Fagaras to Sibiu") {
        using namespace aima;
        const std::string start = "Fagaras";
        const std::string goal = "Sibiu";
        RomaniaMap problem(start, goal);

        auto res = dfs(problem);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }

    SECTION("Depth first search returns a solution from Neamt to Bucharest") {
        using namespace aima;
        const std::string start = "Neamt";
        const std::string goal = "Bucharest";
        RomaniaMap problem(start, goal);

        auto res = dfs(problem);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }
}

