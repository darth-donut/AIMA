//
// @author: jiahong
// @date  : 22/05/18 1:09 AM
//

#ifndef AIMA_BFS_H
#define AIMA_BFS_H

#include <queue>
#include <unordered_set>

#include "problem.h"
#include "optional.h"

namespace aima {

/// A Graph-search implementation of breadth-first-search. Since tree search will take as much
/// space as a graph (frontier), there's no real benefit of using it.
///
/// Time complexity  : O(b^d)
/// Space complexity : O(b^d)
/// Completeness     : Yes, if b is finite
/// Optimality       : Yes, if path cost is a non-decreasing function of the depth of the node

/// \tparam State state type
/// \tparam Action action type
/// \param problem problem definition
/// \return goal state if present, otherwise an empty optional object
template<typename State, typename Action> optional<State> bfs(const Problem<State, Action> &problem);


}   // end namespace aima

template<typename State, typename Action>
aima::optional<State> aima::bfs(const Problem<State, Action> &problem) {
    std::queue<State> frontier;
    std::unordered_set<State> explored;

    frontier.push(problem.initial_state());

    while (!frontier.empty()) {
        auto node = frontier.front();
        frontier.pop();
        for (const auto& a : problem.actions(node)) {
            auto candidate = problem.successor(node, a);
            // as soon as we see it, we can return since we get a better
            // time (and space) complexity of O(b^d) instead of O(b^(d+1))
            // (the +1 depth is redundant!)
            if (problem.goal(candidate)) {
                return candidate;
            }
            if (explored.find(candidate) == explored.cend()) {
                // anything that's about to go into the frontier should also be classified as "visited"
                explored.insert(candidate);
                frontier.push(std::move(candidate));
            }
        }
    }

    return {};
}

#endif //AIMA_BFS_H

