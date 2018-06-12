//
// @author: jiahong
// @date  : 2/06/18 4:58 PM
//

#ifndef AIMA_RBFS_H
#define AIMA_RBFS_H


#include <limits>
#include <queue>
#include <functional>
#include <optional>

#include "problem.h"

namespace aima {

/// O(d*b) space (for each layer, expand all immediate children only)
/// \tparam State
/// \tparam Action
/// \tparam CostFunc
/// \tparam UpdateFunc
/// \param problem
/// \param cost_func
/// \param update_func
/// \return
template<typename State, typename Action, typename CostFunc, typename UpdateFunc>
std::optional<State> rbfs(const Problem<State, Action> &problem, CostFunc cost_func, UpdateFunc update_func);

}        // end namespace aima


namespace {

template<typename State, typename Action, typename CostFunc, typename UpdateFunc>
std::pair<std::optional<State>, double>
recursive_best_first(const aima::Problem<State, Action> &problem, const State &state,
                     double f_limit, CostFunc cost_func, UpdateFunc update_function) {

    auto comparator = [&cost_func](const State &s1, const State &s2) { return cost_func(s1) > cost_func(s2); };

    if (problem.goal(state)) {
        return std::make_pair(std::optional<State>(state), 0);
    }

    std::priority_queue<State, std::vector<State>, decltype(comparator)> successors(comparator);

    for (const auto &action : problem.actions(state)) {
        successors.push(problem.successor(state, action));
    }

    while (!successors.empty()) {
        auto best_node = successors.top();
        successors.pop();
        // if this node's shortest distance to its child is still greater that the 'saved' checkpoint, stop.
        if (cost_func(best_node) > f_limit) {
            return std::make_pair(std::nullopt, cost_func(best_node));
        }
        auto next_best_score = cost_func(successors.top());

        // recurse and update f_limit to the next smallest value we find. It will change if
        // the newly expanded nodes in 'successors' have smaller f(x) values
        auto pair = recursive_best_first(problem, best_node, std::min(next_best_score, f_limit), cost_func,
                                         update_function);

        auto [return_state, override_score] = pair;

        if (return_state) {
            return pair;
        } else {
            update_function(best_node, override_score);
            successors.push(best_node);
        }
    }

    return std::make_pair(std::nullopt, std::numeric_limits<double>::infinity());
}

}   // end nameless namespace


template<typename State, typename Action, typename CostFunc, typename UpdateFunc>
std::optional<State> aima::rbfs(const Problem<State, Action> &problem, CostFunc cost_func, UpdateFunc update_func) {
    return std::get<0>(recursive_best_first(problem, problem.initial_state(), std::numeric_limits<double>::infinity(),
                                            cost_func, update_func));
}

#endif //AIMA_RBFS_H
