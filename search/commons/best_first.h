//
// @author: jiahong
// @date  : 22/05/18 1:49 AM
//

#ifndef AIMA_UNIFORM_SEARCH_H
#define AIMA_UNIFORM_SEARCH_H



#include <optional>
#include "problem.h"
#include "priority_queue.h"


namespace aima {

/// Generic *graph* best-first search. The available derivatives are A*, uniform-cost, and greedy-best first search.
/// They can be achieved by tuning the Cost Function and Cost Update functions. For example:
/// The following examples assumes a problem definition of RomanianMap and States with (class) Romania.
///
///   A* - Cost Function should return f(x) = g(x) + h(x) where g(x) is the cost from source to current node x, and
///        h(x) is the estimated (admissible) cost from current node x to goal node
///
///        Similarly, Update Function should update f(x) = g(x) + h(x)
///
///        Complete: Yes, if solution exists and b is finite (b = branching factor)
///
///        Optimal: Yes, if heuristic function h(x) is consistent (best-fist is a graph search -> requires consistency)
///                 Note that the tree version will only require admissibility. (Due to revisiting explored nodes)
///
///        Time complexity: Depends on heuristic, better if heuristic is dominant
///
///        Space complexity: Depends on heuristic, better if heuristic is dominant
///
///        Example code:
///           auto res = best_first(problem, [](const Romania &s) {
///                                            return s.ccost() + s.goal_estimate("Sibiu");
///                                          },
///                                          [](Romania &node, const Romania &cost_copy) {
///                                              node.set_ccost(cost_copy.ccost() + cost_copy.goal_estimate("Sibiu"));
///                                          });
///   Uniform cost search - Cost Function should return g(x) - cost from source to current node x
///
///                         Update Function should update g(x)
///
///                         Complete: Yes, if solution exists, b(ranching factor) > 0, and epsilon > 0 (epsilon = min path cost)
///
///                         Optimal: Yes, if path costs are non-negative
///
///                         Time complexity: O(b^(C/epsilon+1)) where C = optimal total path cost and epsilon is the min path cost
///
///                         Space complexity: O(b^(C/epsilon+1)) where C = optimal total path cost and epsilon is the min path cost
///
///                         Note for time and space complexity, when epsilon = 1, it becomes O(b^(d+1)), i.e. a BFS with
///                         an extra depth. (Only returned as solution if popped from frontier, which takes +1 depth)
///
///   Greedy best first search - Cost Function should return h(x) - cost from source to current node x
///
///                         Update Function should update h(x)
///
///                         Complete: Yes (because our best-first is a graph version, would be NO if it's tree)
///
///                         Optimal: No
///
///                         Time complexity: Depends on heuristic (Generally O(b^m))
///
///                         Space complexity: Depends on heuristic (Generally O(b^m))
/// \tparam State state type
/// \tparam Action action type
/// \tparam CostUpdate Function
/// \tparam CostFunc Function
/// \param problem Problem definition
/// \param cost_func cost function
/// \param cost_update cost update function
/// \return goal state if present, otherwise an empty optional object
template<typename State, typename Action, typename CostFunc>
std::optional<State> best_first(const Problem<State, Action> &problem, CostFunc cost_func);

}       // end namespace aima

template<typename State, typename Action, typename CostFunc>
std::optional<State> aima::best_first(const Problem<State, Action> &problem,
                                       CostFunc cost_func) {
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
