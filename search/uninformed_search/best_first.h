//
// @author: jiahong
// @date  : 22/05/18 1:49 AM
//

#ifndef AIMA_UNIFORM_SEARCH_H
#define AIMA_UNIFORM_SEARCH_H



#include "optional.h"
#include "problem.h"
#include "priority_queue.h"


namespace aima {

template<typename State, typename Action, typename CostUpdate, typename CostFunc>
optional<State> best_first(const Problem<State, Action> &problem, CostUpdate cost_func, CostFunc cost_update);

}       // end namespace aima

template<typename State, typename Action, typename CostUpdate, typename CostFunc>
aima::optional<State> aima::best_first(const Problem<State, Action> &problem,
                                       CostUpdate cost_func, CostFunc cost_update) {
    // LEGACY:
//     state, cost from start node - g(n)
//    using SPair = std::pair<State, double>;
//    auto comparator = [](auto pair) { return pair.second; };


    auto comparator = [&cost_func](const State &lhs, const State &rhs) {
        return cost_func(lhs) > cost_func(rhs);
    };

    PriorityQueue<State, decltype(comparator)> frontier(comparator);
    std::unordered_set<State> explored;

    frontier.push(problem.initial_state());

    while (!frontier.empty()) {
        auto node = frontier.top();
        frontier.pop();
        if (problem.goal(node)) {
            return node;
        }

        for (const auto& a : problem.actions(node)) {
            auto child = problem.successor(node, a);
            // push to frontier only if it's not in our explored set AND it's not in our frontier already
            if (frontier.find(child) == frontier.cend() && explored.find(child) == explored.cend()) {
                frontier.push(child);
                explored.insert(child);
            } else if (frontier.find(child) != frontier.cend()) {
                // if it is in our frontier, make sure we update its value if it's greater than what we have just seen

                auto old_node = frontier.find(child);

                if (cost_func(*old_node) > cost_func(child)) {
                    frontier.remove(*old_node);
                    frontier.push(child);
                }
            }
        }
    }

    return {};
};











namespace std {

template<typename State>
struct hash<std::pair<State, double>> {
    using argument_type = std::pair<State, double>;
    using result_type = std::size_t;

    // forward State's hash instead of doing any extra work
    std::size_t operator()(const std::pair<State, double> &key) const {
        return std::hash<State>{}(key.first);
    }

};

} // end namespace std


#endif //AIMA_UNIFORM_SEARCH_H
