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


namespace aima {

class NQueens {
friend std::ostream& operator<<(std::ostream &os, const NQueens &nqueens);
public:
    using size_type = std::size_t;
    explicit NQueens(size_type n = 8) : size_{n} {}

    /// Is the current board configuration valid? Valid implies all queens are
    /// safe from each other's attacking range. A board can still be valid even if
    /// it is not complete (and vice-versa)
    /// \return true if the current board configuration is valid.
    bool is_valid() const;

    /// Is the current board completely filled with queens on all ranks and files?
    /// Note that a board can be complete without being valid and vice versa.
    /// \return true if all files and rank has exactly one queen (regardless of validity)
    bool is_complete() const;

    /// Is the current board-(file,rank) square empty?
    /// \param file_rank a pair of size-type values, starting with file, then rank
    /// \return true if the space is unoccupied
    /// \return
    bool operator[](const std::pair<size_type, size_type> &file_rank) const {
        size_type file = file_rank.first;
        size_type rank = file_rank.second;
        return occupied_.find(std::to_string(file) + ':' + std::to_string(rank)) == occupied_.cend();
    }



    std::string to_string() const;


private:
    std::size_t size_;
    std::unordered_set<std::string> occupied_;
    bool is_empty(size_type file, size_type rank) const {
        return this->operator[]({file, rank});
    }
};


class NQueensProblem : public aima::Problem<NQueens, bool> {

};


std::ostream
&operator<<(std::ostream &os, const NQueens &nqueens);


}       // end of aima namespace

#endif //AIMA_N_QUEENS_H
