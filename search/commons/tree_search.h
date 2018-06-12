//
// @author: jiahong
// @date  : 19/05/18 4:22 PM
//

#ifndef AIMA_TREE_SEARCH_H
#define AIMA_TREE_SEARCH_H

#include <stack>

#include <optional>
#include "problem.h"

namespace aima {

template<typename State, typename Action>
std::optional<State>
tree_search(const Problem<State, Action> &problem);

}   // end namespace aima



template<typename State, typename Action>
std::optional<State>
aima::tree_search(const Problem<State, Action> &problem) {
    // initial state inserted into frontier immediately
    std::stack<State> frontier;
    frontier.push(problem.initial_state());

    while (!frontier.empty()) {
        auto state = frontier.top();
        frontier.pop();
        if (problem.goal(state)) {
            return state;
        }
        for (auto action : problem.actions(state)) {
            frontier.push(problem.successor(state, action));
        }
    }
    // return no solution
    return {};
}


#endif //AIMA_TREE_SEARCH_H
