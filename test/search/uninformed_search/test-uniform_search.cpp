//
// @author: jiahong
// @date  : 26/05/18 5:01 PM
//

#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include "best_first.h"
#include "romania.h"


TEST_CASE("Uniform search works on the romanian map", "[US1]") {
    SECTION("Uniform search returns the shortest path from Oradea to Sibiu") {
        using namespace aima;
        RomaniaMap problem("Oradea", "Sibiu");
        std::vector<std::string> shortest_solution{"Oradea", "Sibiu"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("Uniform search returns the shortest path from Arad to Craiova") {
        using namespace aima;
        RomaniaMap problem("Arad", "Craiova");
        std::vector<std::string> shortest_solution{"Arad", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("Uniform search returns the shortest path from Fagaras to Craiova") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Craiova");
        std::vector<std::string> shortest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("Uniform search returns the shortest path from Fagaras to Pitesti") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Pitesti");
        std::vector<std::string> shortest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Pitesti"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("Uniform search returns the shortest path from Fagaras to Bucharest") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Bucharest");
        std::vector<std::string> shortest_solution{"Fagaras", "Bucharest"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }
}

TEST_CASE("Uniform search works on edge cases", "[US2]") {
    SECTION("Uniform search works when start node is the goal node - Bucharest") {
        using namespace aima;
        RomaniaMap problem("Bucharest", "Bucharest");
        std::vector<std::string> solution{"Bucharest"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("Uniform search works when start node is the goal node - Sibiu") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Sibiu");
        std::vector<std::string> solution{"Sibiu"};

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("Uniform search works when there is no path to goal node") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Nowhere");

        auto res = best_first(problem,
                              [](const Romania &s) {
                                  return s.ccost();
                              },
                              [](Romania &node, const Romania &cost_copy) {
                                  node.set_ccost(cost_copy.ccost());
                              });
        REQUIRE_FALSE(bool(res));
    }
}


