//
// @author: jiahong
// @date  : 20/05/18 2:11 AM
//

#ifndef AIMA_STRING_OPS_H
#define AIMA_STRING_OPS_H

#include <string>
#include <vector>

namespace aima {

std::vector<std::string> split(const std::string &str, const std::string &key = " ");

std::vector<std::string>
split(const std::string &str, const std::string &key) {
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

} // end namespace aima

#endif //AIMA_STRING_OPS_H
