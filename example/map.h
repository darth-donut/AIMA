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
    Map(std::string dot) : dot_(std::move(dot)) {
        parse_dot();
    }
private:
    void parse_dot();
private:
    std::string dot_;
    std::unordered_map<std::string, std::vector<std::string>> map;
};


}

#endif //AIMA_MAP_H

