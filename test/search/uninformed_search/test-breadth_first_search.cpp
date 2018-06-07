//
// @author: jiahong
// @date  : 22/05/18 1:38 AM
//


#include "romania.h"
#include "bfs.h"
#include "n_queens.h"

#include "catch.hpp"


TEST_CASE("Test breadth first search 1", "[TBFS1]") {
    SECTION("BFS works on the Romanian map, from Arad to Pitesti") {
        using namespace aima;
        RomaniaMap problem("Arad", "Pitesti");
        std::vector<std::string> solution = {"Arad", "Timisoara", "Lugoj", "Mehadia", "Drobeta", "Craiova", "Pitesti"};
        auto res = bfs(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == solution.front());
        REQUIRE(res->path().back() == solution.back());
    }

    SECTION("BFS search works on the Romanian map, from Zerind to Eforie (very long path)") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Eforie";
        RomaniaMap problem(start, end);
        auto res = bfs(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }

    SECTION("BFS search works on the Romanian map, from Zerind to Neamt(very long path)") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Neamt";
        RomaniaMap problem(start, end);
        auto res = bfs(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }

    SECTION("BFS search works on the Romanian map, on a single node, goal node") {
        using namespace aima;
        std::string start = "Zerind";
        std::string end = "Zerind";
        RomaniaMap problem(start, end);
        auto res = bfs(problem);
        REQUIRE(bool(res));
        REQUIRE(res->path().front() == start);
        REQUIRE(res->path().back() == end);
    }
}

TEST_CASE("Test breadth first search 2", "[TBFS2]") {
    SECTION("BFS works on the 4-Queens problem") {
        using namespace aima;
        NQueensProblem nqueens{4};
        auto res = bfs(nqueens);
        REQUIRE(bool(res));
        REQUIRE(res->is_valid());
    }
}

