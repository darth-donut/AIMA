//
// @author: jiahong
// @date  : 27/05/18 12:04 AM
//

#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include "best_first.h"
#include "romania.h"


// TODO: test non-admissible heuristics, they should fail

TEST_CASE("A* search works on the romanian map", "[US1]") {
    SECTION("A* search returns the shortest path from Oradea to Sibiu") {
        using namespace aima;
        RomaniaMap problem("Oradea", "Sibiu");
        std::vector<std::string> shortest_solution{"Oradea", "Sibiu"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Sibiu");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("A* search returns the shortest path from Arad to Craiova") {
        using namespace aima;
        RomaniaMap problem("Arad", "Craiova");
        std::vector<std::string> shortest_solution{"Arad", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Craiova");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("A* search returns the shortest path from Fagaras to Craiova") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Craiova");
        std::vector<std::string> shortest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Craiova");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("A* search returns the shortest path from Fagaras to Pitesti") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Pitesti");
        std::vector<std::string> shortest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Pitesti"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Pitesti");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("A* search returns the shortest path from Fagaras to Bucharest") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Bucharest");
        std::vector<std::string> shortest_solution{"Fagaras", "Bucharest"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Bucharest");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }
}

TEST_CASE("A* search works on edge cases", "[US2]") {
    SECTION("A* search works when start node is the goal node - Bucharest") {
        using namespace aima;
        RomaniaMap problem("Bucharest", "Bucharest");
        std::vector<std::string> solution{"Bucharest"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Bucharest");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("A* search works when start node is the goal node - Sibiu") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Sibiu");
        std::vector<std::string> solution{"Sibiu"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost() + s.goal_estimate("Sibiu");
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("A* search works when there is no path to goal node") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Nowhere");

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              });
        REQUIRE_FALSE(bool(res));
    }
}

