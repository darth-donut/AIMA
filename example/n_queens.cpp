//
// @author: jiahong
// @date  : 4/06/18 11:12 PM
//

#include <string>

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
