//
// @author: jiahong
// @date  : 20/05/18 3:17 PM
//

#include <algorithm>
#include <iostream>

#include "romania.h"
#include "string_ops.h"

void
aima::Romania::setup() {
    add("Oradea", "Zerind", 71);
    add("Oradea", "Sibiu", 151);
    add("Zerind", "Arad", 75);
    add("Arad", "Sibiu", 140);
    add("Arad", "Timisoara", 118);
    add("Timisoara", "Lugoj", 111);
    add("Lugoj", "Mehadia", 70);
    add("Mehadia", "Drobeta", 75);
    add("Drobeta", "Craiova", 120);
    add("Craiova", "Rimnicu Vilcea", 146);
    add("Craiova", "Pitesti", 138);
    add("Sibiu", "Fagaras", 99);
    add("Sibiu", "Rimnicu Vilcea", 80);
    add("Rimnicu Vilcea", "Pitesti", 87);
    add("Fagaras", "Bucharest", 211);
    add("Pitesti", "Bucharest", 101);
    add("Bucharest", "Giurgiu", 90);
    add("Bucharest", "Urziceni", 85);
    add("Urziceni", "Hirsova", 98);
    add("Urziceni", "Vaslui", 142);
    add("Hirsova", "Eforie", 86);
    add("Vaslui", "Iasi", 92);
    add("Iasi", "Neami", 87);
}

std::vector<std::string>
aima::RomaniaMap::actions(const aima::Romania &state) const {
    auto neighbours = romania_.neighbours(state.whereami());
    std::vector<std::string> actions;
    // extract weights from the pairs (we don't need them)
    std::transform(neighbours.cbegin(),
                   neighbours.cend(),
                   std::back_inserter(actions),
                   [](auto pair) {
        return pair.first;
    });
    return actions;
}

aima::Romania
aima::RomaniaMap::successor(const aima::Romania &state, const std::string &action) const {
    auto child = state;
    child.advance(action);
    return child;
}

std::ostream
&aima::operator<<(std::ostream &os, const aima::Romania &romania) {
    return os << aima::join(romania.path_.cbegin(), romania.path_.cend(), " -> ");
}
