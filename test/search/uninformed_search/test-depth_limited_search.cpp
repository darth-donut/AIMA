//
// @author: jiahong
// @date  : 27/05/18 5:08 PM
//

#include "dfs.h"
#include "romania.h"

#include "catch.hpp"

TEST_CASE("Depth limited search works on the romanian map - testing for depth >= solution depth", "[TDLS1]") {
    SECTION("Depth limited search returns a solution from Oradea to Sibiu") {
        using namespace aima;
        const std::string start = "Oradea";
        const std::string goal = "Sibiu";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 2);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }

    SECTION("Depth limited search returns a solution from Arad to Craiova") {
        using namespace aima;
        const std::string start = "Arad";
        const std::string goal = "Craiova";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 4);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }

    SECTION("Depth limited search returns a solution from Fagaras to Pitesti") {
        using namespace aima;
        const std::string start = "Fagaras";
        const std::string goal = "Pitesti";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 3);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }

    SECTION("Depth limited search returns a solution from Fagaras to Bucharest") {
        using namespace aima;
        const std::string start = "Fagaras";
        const std::string goal = "Bucharest";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 2);

        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == goal);
    }
}

TEST_CASE("Depth limited search works on the romanian map - testing for depth < solution depth", "[TDLS2]") {
    SECTION("Depth limited search returns a solution from Fagaras to Bucharest") {
        using namespace aima;
        const std::string start = "Fagaras";
        const std::string goal = "Bucharest";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 0);

        REQUIRE_FALSE(bool(res));
    }

    SECTION("Depth limited search returns a solution from Oradea to Sibiu") {
        using namespace aima;
        const std::string start = "Oradea";
        const std::string goal = "Sibiu";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 0);

        REQUIRE_FALSE(bool(res));
    }

    SECTION("Depth limited search returns a solution from Arad to Craiova") {
        using namespace aima;
        const std::string start = "Arad";
        const std::string goal = "Craiova";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 2);

        REQUIRE_FALSE(bool(res));
    }

    SECTION("Depth limited search returns a solution from Fagaras to Pitesti") {
        using namespace aima;
        const std::string start = "Fagaras";
        const std::string goal = "Pitesti";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 1);

        REQUIRE_FALSE(bool(res));
    }

    SECTION("Depth limited search returns a solution from Fagaras to Craiova") {
        using namespace aima;
        const std::string start = "Fagaras";
        const std::string goal = "Craiova";
        RomaniaMap problem(start, goal);

        auto res = depth_limited_search(problem, 2);

        REQUIRE_FALSE(bool(res));
    }
}
