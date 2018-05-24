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
#include <cassert>

#include "problem.h"
#include "map.h"

namespace aima {

class Romania : public Map {

friend std::ostream &operator<<(std::ostream &os, const Romania &romania);
friend struct std::hash<Romania>;

public:
    Romania() = default;
    explicit Romania(const std::string &initial_state)
            : Map("Romania"),
              current_state_(initial_state) {

        setup();
        path_.push_back(initial_state);
    };

    std::vector<std::pair<std::string, double>> neighbours(const std::string &current_state) const {
        return map_.at(current_state);
    }
    const std::string &whereami() const { return current_state_; }
    std::string &whereami() { return current_state_; }

    void advance(const std::string &location) {
        current_state_ = location;
        if (!path_.empty()) {
            auto parent = map_[path_.back()];
            // get the std::pair<> between parent and this child node for the second element (path cost)
            auto key = std::find_if(parent.cbegin(), parent.cend(), [&location](const auto &p) {
                return p.first == location;
            });
            // it has to exist
            assert(key != parent.cend());
            cost_ = key->second;
            ccost_ += cost_;
        }
        path_.push_back(location);
    }

    const std::vector<std::string> &path() const { return path_; }

    bool operator==(const Romania &other) const {
        // do NOT compare paths, they are just the solution (path).
        // two "Romanias" are equal if they are in the same node
        return current_state_ == other.current_state_;
    }

    bool operator!=(const Romania &other) const { return !(*this == other); }

    constexpr double cost() const noexcept { return cost_; }

    constexpr double ccost() const noexcept { return ccost_; }

private:
    void setup();

private:
    std::string current_state_;
    std::vector<std::string> path_;
    // cost from most immediate parent
    double cost_ = 0;
    // cumulative cost
    double ccost_ = 0;
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
    Romania initial_state() const override { return Romania(initial_); }
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
