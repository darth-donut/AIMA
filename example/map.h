//
// @author: jiahong
// @date  : 20/05/18 2:03 AM
//

#ifndef AIMA_MAP_H
#define AIMA_MAP_H

#include <string>
#include <utility>
#include <vector>
#include <unordered_map>


namespace aima {

class Map {
public:
    Map() = default;
    Map(std::string name) : name_(std::move(name)) {}
    void add(const std::string &from, const std::string &to, double weight = .0, bool undirected = true) {
        map_[from].push_back({to, weight});
        if (undirected) {
            map_[to].push_back({from, weight});
        }
    }
    virtual ~Map() = default;
protected:
    std::string name_;
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> map_;
};


}

#endif //AIMA_MAP_H

