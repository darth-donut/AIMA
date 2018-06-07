//
// @author: jiahong
// @date  : 4/06/18 11:12 PM
//

#include <string>
#include <vector>

#include "n_queens.h"

std::ostream
&aima::operator<<(std::ostream &os, const NQueens &nqueens) {
    return os << nqueens.to_string();
}

std::string
aima::NQueens::to_string() const {
    // initiate with symbol on the left upper corner
    std::string buffer{"+"};
    //            each rank's size   each file's size
    buffer.reserve((4 * size_ + 2) * (2 * size_ + 1));

    std::string queen{" Q "};

    for (size_type i = 0; i < size_; ++i) {
        buffer += "---+";
    }
    buffer += '\n';

    const std::string rank_sep = buffer;

    for (NQueens::size_type rank = 0; rank != size_; ++rank) {
        buffer += '|';
        for (NQueens::size_type file = 0; file != size_; ++file) {
            if (is_empty(file, rank)) {
                buffer += "   |";
            } else {
                buffer += (queen + "|");
            }
        }
        buffer += ("\n" + rank_sep);
    }

    // remove trailing newline
    buffer.pop_back();
    return buffer;
}

bool
aima::NQueens::is_valid() const {
    if (queens() > size_) {
        // there's no such valid configuration where
        // there's more queens then #file or #rank
        return false;
    }
    for (const auto &coord: occupied_) {
        for (size_type i= 1; i != size_; ++i) {
            // rank check
            if (coord.second + i < size_) {
                if (occupied_.find({coord.first, coord.second + i}) != occupied_.cend()) return false;
            }
            if (coord.second >= i) {
                if (occupied_.find({coord.first, coord.second - i}) != occupied_.cend()) return false;
            }

            // file check
            if (coord.first + i < size_) {
                if (occupied_.find({coord.first + i, coord.second}) != occupied_.cend()) return false;
            }
            if (coord.first >= i) {
                if (occupied_.find({coord.first - i, coord.second}) != occupied_.cend()) return false;
            }

            // south west
            if (coord.second + i < size_ && coord.first >= i) {
                if (occupied_.find({coord.first - i, coord.second + i}) != occupied_.cend()) return false;
            }

            // north east
            if (coord.second >= i && coord.first + i < size_) {
                if (occupied_.find({coord.first + i, coord.second - i}) != occupied_.cend()) return false;
            }

            // north west
            if (coord.second >= i && coord.first >= i) {
                if (occupied_.find({coord.first - i, coord.second - i}) != occupied_.cend()) return false;
            }

            // south east
            if (coord.second + i < size_ && coord.first + i < size_) {
                if (occupied_.find({coord.first + i, coord.second + i}) != occupied_.cend()) return false;
            }
        }
    }

    return true;
}

std::vector<aima::NQueens::NQueenCoord>
aima::NQueensProblem::actions(const aima::NQueens &state) const {
    std::vector<NQueens::NQueenCoord> possible_actions;
    std::unordered_set<aima::NQueens::size_type> skip_ranks;

    for (size_type file = 0; file != size_; ++file) {
        for (size_type rank = 0; rank != size_; ++rank) {
            if (skip_ranks.find(rank) != skip_ranks.cend()) continue;
            if (!state[{file, rank}]) {
                possible_actions.emplace_back(file, rank);
            } else {
                // the next time we iterate into another file, just skip this
                // rank entirely because we already know that it's filled
                skip_ranks.insert(rank);
            }
        }
    }
    return possible_actions;
}

