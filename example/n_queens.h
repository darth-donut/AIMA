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

#define NQUEEN_COORD_UNIT std::size_t
#define NQUEEN_COORD std::pair<NQUEEN_COORD_UNIT, NQUEEN_COORD_UNIT>
#define NQUEENS_MAX_HASH_ITERS 10


namespace std {

template<>
struct hash<NQUEEN_COORD> {
    using result_type = size_t;
    using argument_type = NQUEEN_COORD;

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
    friend class std::hash<NQueens>;
public:
    using size_type = NQUEEN_COORD_UNIT;
    using NQueenCoord = NQUEEN_COORD;

    /// a NQueen problem on a board of size n by n
    /// \param n size of square board
    explicit NQueens(size_type n = 8) : size_{n} {}

    /// Is the current board configuration valid? Validity is defined as a configuration where
    /// all queens are safe from each other's attacking range.
    /// \return true if the current board configuration is valid.
    bool is_valid() const;


    /// Is the current board-(file,rank) square occupied?
    /// \param file_rank a pair of size-type values, starting with file, then rank
    /// \return true if the space is occupied
    bool operator[](const NQueenCoord &file_rank) const {
        return occupied_.find({file_rank.first, file_rank.second}) != occupied_.cend();
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

    /// overloads place to take a pair of (file, rank) object instead of 2 arguments
    /// \param coord aima::NQueens::NQueenCoord of (file, rank)
    /// \return
    bool place(const NQueenCoord &coord) { return place(coord.first, coord.second); }

    /// a board is equal to another iff the size is the same, and each occupied (and implicitly, unoccupied) spots
    /// are identical
    /// \param other other NQueens state to compare
    /// \return true if they are identical
    bool operator==(const NQueens &other) const {
        if (size_ == other.size_) {
            for (const auto &coord : occupied_) {
                if (!other[coord]) return false;
            }
        } else {
            return false;
        }
        return true;
    }


private:
    std::size_t size_;
    std::unordered_set<NQueenCoord> occupied_;

    bool is_empty(size_type file, size_type rank) const {
        return !this->operator[]({file, rank});
    }

};

std::ostream
&operator<<(std::ostream &os, const NQueens &nqueens);

class NQueensProblem : public aima::Problem<NQueens, NQueens::NQueenCoord> {
public:
    using size_type = NQueens::size_type;
    NQueensProblem(const size_type n = 8) : size_{n} {}

    std::vector<aima::NQueens::NQueenCoord> actions(const NQueens &state) const override;

    NQueens successor(const NQueens &state, const aima::NQueens::NQueenCoord &action) const override {
        NQueens copy_state{state};
        copy_state.place(action);
        return copy_state;
    }

    bool goal(const NQueens &state) const override { return state.queens() == state.size() && state.is_valid(); }

    NQueens initial_state() const override { return NQueens{size_}; }

private:
    size_type size_;
};

}       // end of aima namespace

namespace std {

// for saving states in a hash map - required for graph search algorithms
template<>
struct hash<aima::NQueens> {
    using argument_type = aima::NQueens;
    using result_type = size_t;

    size_t operator()(const aima::NQueens &state) const {
        size_t it = 0;
        size_t res = 17 *  + 31 * state.size_;
        for (const auto &coord : state.occupied_) {
            if (it++ < NQUEENS_MAX_HASH_ITERS) {
                res += 31 * std::hash<aima::NQueens::NQueenCoord>{}(coord);
            } else {
                break;
            }
        }
        return res;
    }
};

}   // end std namespace


#endif //AIMA_N_QUEENS_H
