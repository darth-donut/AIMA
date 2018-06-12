//
// @author: jiahong
// @date  : 20/05/18 9:34 PM
//

#ifndef AIMA_GRAPH_SEARCH_H
#define AIMA_GRAPH_SEARCH_H

#include <stack>
#include <unordered_set>

#include "problem.h"
#include <optional>

namespace aima {


template<typename State, typename Action>
std::optional<State> graph_search(const Problem<State, Action> &problem);


}   // end namespace aima




template<typename State, typename Action>
std::optional<State>
aima::graph_search(const Problem<State, Action> &problem) {
    std::unordered_set<State> frontier;
    std::unordered_set<State> explored;

    frontier.insert(problem.initial_state());

    while (!frontier.empty()) {
        auto node = *frontier.begin();
        frontier.erase(node);
        if (problem.goal(node)) {
            return node;
        }
        explored.insert(node);
        for (auto action : problem.actions(node)) {
            auto candidate = problem.successor(node, action);
            if (explored.find(candidate) == explored.end() && frontier.find(candidate) == frontier.end()) {
                frontier.insert(std::move(candidate));
            }
        }
    }

    return {};

}

#endif //AIMA_GRAPH_SEARCH_H
