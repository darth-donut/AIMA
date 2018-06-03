//
// @author: jiahong
// @date  : 2/06/18 5:09 PM
//

#include <vector>
#include <string>

#include "rbfs.h"
#include "romania.h"

#include "catch.hpp"


namespace {

TEST_CASE("recursive best first search works on romanian map", "[RBFS1]") {
    using aima::rbfs;
    using aima::Romania;
    using aima::RomaniaMap;

    SECTION("RBFS search returns the shortest path from Oradea to Sibiu") {
        RomaniaMap problem("Oradea", "Sibiu");
        std::vector<std::string> shortest_solution{"Oradea", "Sibiu"};

        auto res = rbfs(problem, [](const Romania &s) { return s.ccost() + s.goal_estimate("Sibiu"); },
                        [](Romania &state, double new_cost) { state.set_ccost(new_cost); });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }
    SECTION("RBFS search returns the shortest path from Arad to Craiova") {
        using namespace aima;
        RomaniaMap problem("Arad", "Craiova");
        std::vector<std::string> shortest_solution{"Arad", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = rbfs(problem,
                        [](const Romania &s) {
                            return s.ccost() + s.goal_estimate("Craiova");
                        },
                        [](Romania &state, double new_cost) {
                            state.set_ccost(new_cost);

                        });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("RBFS search returns the shortest path from Fagaras to Craiova") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Craiova");
        std::vector<std::string> shortest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Craiova"};

        auto res = rbfs(problem,
                        [](const Romania &s) {
                            return s.ccost() + s.goal_estimate("Craiova");
                        },
                        [](Romania &state, double new_cost) {
                            state.set_ccost(new_cost);
                        });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("RBFS search returns the shortest path from Fagaras to Pitesti") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Pitesti");
        std::vector<std::string> shortest_solution{"Fagaras", "Sibiu", "Rimnicu Vilcea", "Pitesti"};

        auto res = rbfs(problem,
                        [](const Romania &s) {
                            return s.ccost() + s.goal_estimate("Pitesti");
                        },
                        [](Romania &state, double new_cost) {
                            state.set_ccost(new_cost);
                        });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }

    SECTION("RBFS search returns the shortest path from Fagaras to Bucharest") {
        using namespace aima;
        RomaniaMap problem("Fagaras", "Bucharest");
        std::vector<std::string> shortest_solution{"Fagaras", "Bucharest"};

        auto res = rbfs(problem,
                        [](const Romania &s) {
                            return s.ccost() + s.goal_estimate("Bucharest");
                        },
                        [](Romania &state, double new_cost) {
                            state.set_ccost(new_cost);
                        });
        REQUIRE(bool(res));
        REQUIRE(res->path() == shortest_solution);
    }
}

TEST_CASE("recursive best first search works on edge cases", "[RBFS2]") {
    SECTION("RBFS search works when start node is the goal node - Bucharest") {
        using namespace aima;
        RomaniaMap problem("Bucharest", "Bucharest");
        std::vector<std::string> solution{"Bucharest"};

        auto res = rbfs(problem,
                        [](const Romania &s) {
                            return s.ccost() + s.goal_estimate("Bucharest");
                        },
                        [](Romania &state, double new_cost) {
                            state.set_ccost(new_cost);
                        });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }
    SECTION("RBFS search works when start node is the goal node - Sibiu") {
        using namespace aima;
        RomaniaMap problem("Sibiu", "Sibiu");
        std::vector<std::string> solution{"Sibiu"};

        auto res = rbfs(problem,
                        [](const Romania &s) {
                            return s.ccost() + s.goal_estimate("Sibiu");
                        },
                        [](Romania &state, double new_cost) {
                            state.set_ccost(new_cost);
                        });
        REQUIRE(bool(res));
        REQUIRE(res->path() == solution);
    }

    // will not work because there's no "visited" node
//    SECTION("RBFS search works when there is no path to goal node") {
//        using namespace aima;
//        RomaniaMap problem("Sibiu", "Nowhere");
//
//        auto res = rbfs(problem,
//                        [](const Romania &s) {
//                            return s.ccost();
//                        },
//                        [](Romania &state, double new_cost) {
//                            state.set_ccost(new_cost);
//                        });
//        REQUIRE_FALSE(bool(res));
//    }
}

}   // end nameless namespace

