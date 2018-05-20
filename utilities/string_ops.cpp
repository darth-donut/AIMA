//
// @author: jiahong
// @date  : 20/05/18 4:45 PM
//

#include <string>
#include <vector>

#include "string_ops.h"


std::vector<std::string>
aima::split(const std::string &str, const std::string &key) {
    std::string::size_type ind = 0;
    std::string::size_type start = 0;
    std::vector<std::string> tokens;
    while ((ind = str.find(key, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, ind - start));
        start = ind + 1;
    }
    tokens.push_back(str.substr(start, ind));
    return tokens;
}

