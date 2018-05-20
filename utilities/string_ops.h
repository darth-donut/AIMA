//
// @author: jiahong
// @date  : 20/05/18 2:11 AM
//

#ifndef AIMA_STRING_OPS_H
#define AIMA_STRING_OPS_H

#include <string>
#include <vector>
#include <algorithm>

namespace aima {

/// splits (tokenizes) the string based on key
/// \param str string to be tokenzied
/// \param key key to use as token separator
/// \return std::vector<std:;string> of tokens
std::vector<std::string> split(const std::string &str, const std::string &key = " ");


/// joins the string together, with key as the separator. For example,
/// std::vector<std::string> v = {"1", "2", "3"};
/// join(v.start(), v.end(), ",") returns "1,2,3"
/// \tparam It random access iterator
/// \param start starting iterator
/// \param finish ending iterator (one-off last element), just like end() function/method
/// \param key string used to merge the tokens
/// \return std::string
template<typename It>
std::string
join(It start, It finish, const std::string &key);


} // end namespace aima




template<typename It>
std::string
aima::join(It start, It finish, const std::string &key) {
    std::string string_builder;
    for (auto tok = start; tok != finish - 1; ++tok) {
        string_builder += *tok + key;
    }
    string_builder += *(finish - 1);
    return string_builder;
}


#endif //AIMA_STRING_OPS_H
