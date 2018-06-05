//
// @author: jiahong
// @date  : 5/06/18 12:27 AM
//

#include "n_queens.h"

#include "catch.hpp"

namespace {

using aima::NQueens;

TEST_CASE("NQueens correctly show the current board state on an odd sized board", "[NQBSO]") {
    NQueens nqueens{11};
    // each Q will land on string_file = file * 4 + 2
    //                     string_rank = rank * 2 + 1
    const std::string empty_board = "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+---+---+---+";

    SECTION("NQueens with size = 11 shows an empty board correctly") {
        REQUIRE(nqueens.to_string() == empty_board);
    }
}

TEST_CASE("NQueens correctly show the current board state on an even sized board", "[NQBSE]") {
    NQueens nqueens;
    // each Q will land on string_file = file * 4 + 2
    //                     string_rank = rank * 2 + 1
    const std::string empty_board = "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+\n"
                                    "|   |   |   |   |   |   |   |   |\n"
                                    "+---+---+---+---+---+---+---+---+";
    SECTION("NQueens with size = 8 shows an empty board correctly") {
        REQUIRE(nqueens.to_string() == empty_board);
    }
}

TEST_CASE("NQueens correctly validates a board when no queens are attacking each other", "[NQBVP]") {
    NQueens nqueens;

    SECTION("Partial board is also valid") {
        REQUIRE(nqueens.place(0, 0));
        REQUIRE(nqueens.is_valid());
    }

    SECTION("Partial board is also valid") {
        REQUIRE(nqueens.place(0, 0));
        REQUIRE(nqueens.place(2, 7));
        REQUIRE(nqueens.place(3, 4));
        REQUIRE(nqueens.is_valid());
    }

}

TEST_CASE("NQueens correctly validates a board when at least one queen is attacking another", "[NQBVN]") {
    NQueens nqueens;

    SECTION("Partial board is can also be invalid") {
        REQUIRE(nqueens.place(0, 0));
        REQUIRE(nqueens.place(1, 0));
        REQUIRE_FALSE(nqueens.is_valid());
    }

    SECTION("Partial board is can also be invalid") {
        REQUIRE(nqueens.place(0, 0));
        REQUIRE(nqueens.place(1, 2));
        REQUIRE(nqueens.is_valid());

        REQUIRE(nqueens.place(2, 1));
        REQUIRE_FALSE(nqueens.is_valid());
    }
}

TEST_CASE("NQueens places a piece on the board with the right semantics", "[NQBVPC]") {
    using size_type = NQueens::size_type;
    constexpr size_type N = 50;
    NQueens nqueens{N};

    SECTION("Placing on an empty square returns true") {
        for (size_type i = 0; i != N; ++i) {
            for (size_type j = 0; j != N; ++j) {
                REQUIRE(nqueens.place(i, j));
            }
        }
    }

    SECTION("Placing on an occupied square returns false") {
        for (size_type i = 0; i != N; ++i) {
            for (size_type j = 0; j != N; ++j) {
                nqueens.place(i, j);
            }
        }

        for (size_type i = 0; i != N; ++i) {
            for (size_type j = 0; j != N; ++j) {
                REQUIRE_FALSE(nqueens.place(i, j));
            }
        }
    }
}

}
