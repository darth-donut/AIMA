//
// @author: jiahong
// @date  : 26/05/18 10:20 PM
//

#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include "best_first.h"
#include "romania.h"


TEST_CASE("Greedy best-first search works on the romanian map", "[US1]") {
    SECTION("Greedy best-first search returns the greediest path from Oradea to Sibiu") {
        using namespace aima;
        RomaniaMap problem("Oradea", "Sibiu");
        std::vector<std::string> greediest_solution{"Oradea", "Sibiu"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Sibiu");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == greediest_solution);
    }

    SECTION("Greedy best-first search returns the greediest path from Arad to Craiova") {
        using namespace aima;
        RomaniaMap problem("Arad", "Craiova");
        std::vector<std::string> greediest_solution{"Arad", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Craiova");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == greediest_solution);
    }

    SECTION("Greedy best-first search returns the greediest path from Fagaras to Craiova") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Craiova");
        std::vector<std::string> greediest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Craiova");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == greediest_solution);
    }

    SECTION("Greedy best-first search returns the greediest path from Fagaras to Pitesti") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Pitesti");
        std::vector<std::string> greediest_solution{"Fagaras", "Bucharest", "Pitesti"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Pitesti");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == greediest_solution);
    }

    SECTION("Greedy best-first search returns the greediest path from Fagaras to Bucharest") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Bucharest");
        std::vector<std::string> greediest_solution{"Fagaras", "Bucharest"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Bucharest");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == greediest_solution);
    }
}

TEST_CASE("Greedy best-first search works on edge cases", "[US2]") {
    SECTION("Greedy best-first search works when start node is the goal node - Bucharest") {
        using namespace aima;
        RomaniaMap problem("Bucharest", "Bucharest");
        std::vector<std::string> solution{"Bucharest"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Bucharest");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("Greedy best-first search works when start node is the goal node - Sibiu") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Sibiu");
        std::vector<std::string> solution{"Sibiu"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Sibiu");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("Greedy best-first search works when there is no path to goal node") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Nowhere");

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.goal_estimate("Sibiu");
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  // nothing
                              });
        REQUIRE_FALSE(bool(res));
    }
}

