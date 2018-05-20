//
// @author: jiahong
// @date  : 20/05/18 3:17 PM
//

#ifndef AIMA_ROMANIA_H
#define AIMA_ROMANIA_H


#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "commons/problem.h"
#include "map.h"

namespace aima {

class Romania : public Map {

friend std::ostream &operator<<(std::ostream &os, const Romania &romania);
friend struct std::hash<Romania>;

public:
    Romania() = default;
    Romania(std::string initial_state) : Map("Romania"), current_state_(std::move(initial_state)) {
        setup();
        // DO NOT USE initial_state here!!! it's been moved in constructor list
        path_.push_back(current_state_);
    };
    std::vector<std::pair<std::string, double>> neighbours(const std::string &current_state) const {
        return map_.at(current_state);
    }
    const std::string &whereami() const { return current_state_; }
    std::string &whereami() { return current_state_; }

    void advance(const std::string &location) {
        current_state_ = location;
        path_.push_back(location);
    }

    const std::vector<std::string> &path() const { return path_; }

    bool operator==(const Romania &other) const {
        // do NOT compare paths, they are just the solution (path).
        // two "Romanias" are equal if they are in the same node
        return current_state_ == other.current_state_;
    }

    bool operator!=(const Romania &other) const { return !(*this == other); }

private:
    void setup();

private:
    std::string current_state_;
    std::vector<std::string> path_;
};


class RomaniaMap : public Problem<Romania, std::string> {
public:
    RomaniaMap(std::string initial, std::string goal) :
            initial_(std::move(initial)),
            goal_(std::move(goal)),
            romania_(initial) {}
    std::vector<std::string> actions(const Romania &state) const override;
    Romania successor(const Romania &state, const std::string &action) const override;
    bool goal(const Romania &state) const override { return state.whereami() == goal_; }
    Romania initial_state() const override { return initial_; }
private:
    std::string goal_;
    std::string initial_;
    Romania romania_;
};


std::ostream &operator<<(std::ostream &os, const Romania &romania);

}   // end namespace aima













namespace std {

template<>
struct hash<aima::Romania> {
    typedef size_t result_type;
    typedef aima::Romania argument_type;

    size_t operator()(const aima::Romania &romania) const {
        size_t res = 17;
        res = res * 31 + hash<string>{}(romania.current_state_);
//         consistency with operator==(), do NOT compare paths
//        for (const auto &p : romania.path_) {
//            res = res * 31 + hash<string>{}(p);
//        }
        return res;
    }
};

}   // end namepsace std

#endif //AIMA_ROMANIA_H
