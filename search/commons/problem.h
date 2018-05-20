//
// @author: jiahong
// @date  : 19/05/18 4:26 PM
//

#ifndef AIMA_PROBLEM_H
#define AIMA_PROBLEM_H

#include<vector>

template<typename State, typename Action>
class Problem {
public:
    /// given a state, return all possible actions that the provided state can take
    /// \param state
    ///         State where possible actions should be returned by this function
    /// \return std::vector<A>
    ///         A vector of actions that can be taken from the provided "start" state
    virtual std::vector<Action> actions(const State &state) const = 0;

    /// given a state and action, apply the action on the state and return the successor node
    /// \param state
    ///         State where the action should be applied to
    /// \param action
    ///         Action that should be applied to state
    /// \return state
    ///         A brand new successor state (state is not modified) as a result of applying action to state
    virtual State successor(const State &state, const Action &action) const = 0;

    /// given a state, checks if it is (one of / the) goal state
    /// \param state
    ///         State that should be checked for a goal state
    /// \return bool
    ///         Indication of whether or not state is a goal state
    virtual bool goal(const State &state) const = 0;

    /// returns the initial state of this problem
    /// \return state
    ///         A brand new initial state object
    virtual State initial_state() const = 0;
};

#endif //AIMA_PROBLEM_H
