//
// @author: jiahong
// @date  : 27/05/18 3:30 AM
//

#ifndef AIMA_DFS_H
#define AIMA_DFS_H

#include <limits>
#include <utility>

#include "problem.h"
#include <optional>

namespace aima {


template<typename State, typename Action>
std::optional<State> depth_limited_search(const Problem<State, Action> &problem, double depth);

template<typename State, typename Action>
std::optional<State> dfs(const Problem<State, Action> &problem);

}   // end namespace aima


namespace {

template<typename State, typename Action>
std::optional<State>
recursive_depth_first_search(const aima::Problem<State, Action> &problem, const State &root, double current_depth,
                             double max_depth) {

    if (problem.goal(root)) {
        return root;
    }

    if (current_depth >= max_depth) {
        // no solution
        return {};
    }

    for (const auto &a : problem.actions(root)) {
        auto res = recursive_depth_first_search(problem, problem.successor(root, a), current_depth + 1, max_depth);
        // if we've found the "first" goal node, return it immediately
        if (res) {
            return res;
        }
    }
    return {};

};

}   // end nameless namespace



template<typename State, typename Action>
std::optional<State>
aima::depth_limited_search(const Problem<State, Action> &problem, double depth) {
    return recursive_depth_first_search(problem, problem.initial_state(), 0, depth);
};

template<typename State, typename Action>
std::optional<State>
aima::dfs(const aima::Problem<State, Action> &problem) {
    return depth_limited_search(problem, std::numeric_limits<double>::infinity());
};

#endif //AIMA_DFS_H
