//
// @author: jiahong
// @date  : 4/06/18 11:12 PM
//

#ifndef AIMA_N_QUEENS_H
#define AIMA_N_QUEENS_H

#include <unordered_set>
#include <string>
#include <iostream>

#include "problem.h"


namespace std {

template<>
struct hash<pair<size_t, size_t>> {
    using result_type = size_t;
    using argument_type = pair<size_t, size_t>;

    size_t operator()(const pair<size_t, size_t> &coord) const noexcept {
        size_t res = 17;
        res += 31 * hash<size_t>{}(coord.first);
        res += 31 * hash<size_t>{}(coord.second);
        return res;
    }
};

} // end of std namespace

namespace aima {

/// An instance of NQueens state. The board's cartesian coordinates are on the
/// fourth quadrant with positive y values. For example, here's an example of a 8x8 board:
///
/// ```
///       0   1   2   3   4   5   6   7
///     +---+---+---+---+---+---+---+---+
///  0  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  1  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  2  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  3  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  4  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  5  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  6  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
///  7  |   |   |   |   |   |   |   |   |
///     +---+---+---+---+---+---+---+---+
/// ```
///
class NQueens {
    friend std::ostream &operator<<(std::ostream &os, const NQueens &nqueens);

public:
    using size_type = std::size_t;
    using NQueenCoord = std::pair<size_type, size_type>;

    /// a NQueen problem on a board of size n by n
    /// \param n size of square board
    explicit NQueens(size_type n = 8) : size_{n} {}

    /// Is the current board configuration valid? Validity is defined as a configuration where
    /// all queens are safe from each other's attacking range.
    /// \return true if the current board configuration is valid.
    bool is_valid() const;


    /// Is the current board-(file,rank) square empty?
    /// \param file_rank a pair of size-type values, starting with file, then rank
    /// \return true if the space is unoccupied
    bool operator[](const NQueenCoord &file_rank) const {
        return occupied_.find({file_rank.first, file_rank.second}) == occupied_.cend();
    }

    /// returns the number of queens present on the current board
    /// \return number of queens present on the board
    size_type queens() const { return occupied_.size(); }

    /// returns the board size
    /// \return n, where the board size is n by n
    size_type size() const { return size_; }

    /// returns true if the current board is empty
    /// \return true if the current board is empty, i.e. this->size() == 0
    bool empty() const { return occupied_.empty(); }

    /// an ascii string representation of the current board state
    /// \return std::string representation of the current board
    std::string to_string() const;

    /// adds a queen piece at the specified file and rank
    /// \param file column
    /// \param rank row
    /// \return true if the spot was unoccupied before placing a piece down (a successful place operation). False
    /// indicates that the board hasn't changed because it was already occupied by a queen piece
    bool place(size_type file, size_type rank) {
        if (is_empty(file, rank)) {
            occupied_.insert({file, rank});
            return true;
        }
        return false;
    }


private:
    std::size_t size_;
    std::unordered_set<NQueenCoord> occupied_;

    bool is_empty(size_type file, size_type rank) const {
        return this->operator[]({file, rank});
    }

};

std::ostream
&operator<<(std::ostream &os, const NQueens &nqueens);

class NQueensProblem : public aima::Problem<NQueens, bool> {

};

}       // end of aima namespace


#endif //AIMA_N_QUEENS_H
