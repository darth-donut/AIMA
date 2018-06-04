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

}
