//
// @author: jiahong
// @date  : 27/05/18 5:39 PM
//

#ifndef AIMA_IDS_H
#define AIMA_IDS_H

#include <optional>
#include "problem.h"
#include "dfs.h"

namespace aima {

template<typename State, typename Action>
std::optional<State> ids(const Problem<State, Action> &problem);


}       // end namespace aima


template<typename State, typename Action>
std::optional<State>
aima::ids(const Problem<State, Action> &problem) {
    // assumes that there's a solution in the state space, otherwise, the loop will run indefinitely
    // i.e. it is complete if there's a solution
    for (double depth = 0; ; ++depth) {
        auto res = depth_limited_search(problem, depth);
        if (res) {
            return res;
        }
    }

}

#endif //AIMA_IDS_H
