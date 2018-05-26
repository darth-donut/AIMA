//
// @author: jiahong
// @date  : 24/05/18 12:27 AM
//

#ifndef AIMA_PRIORITY_QUEUE_H
#define AIMA_PRIORITY_QUEUE_H


#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cassert>

namespace aima {

template<typename T, typename Comparator = std::less<>>
class PriorityQueue {
public:
    using const_iterator = typename std::unordered_set<T>::const_iterator;
    using iterator = typename std::unordered_set<T>::iterator;

    PriorityQueue(Comparator cmp = Comparator()) : cmp_(cmp) {}

    iterator find(const T &key) {
        return set_.find(key);
    }

    const_iterator find(const T &key) const {
        return set_.find(key);
    }

    const_iterator cbegin() const { return set_.cbegin(); }

    iterator begin() { return set_.begin(); }

    const_iterator cend() const { return set_.cend(); }

    iterator end() { return set_.end(); }

    void push(const T &key) {
        set_.insert(key);
        auto res = set_.find(key);
        assert(res != set_.cend());
        ptrs_.push_back(&(*res));
        sieve_up(ptrs_.size() - 1);
    }

    void pop() {
        using std::swap;
        auto del = ptrs_.front();
        swap(ptrs_.front(), ptrs_.back());
        ptrs_.pop_back();
        sieve_down();
        set_.erase(*del);
    }

    const T &top() const {
        // would never EVER EVERRR happen!
//        if (set_.find(*ptrs_.front()) == set_.cend()) {
//            throw std::logic_error("Whoopsie dasies");
//        }
        assert(set_.find(*ptrs_.front()) != set_.cend());
        return *ptrs_.front();
    }

    const T &top() {
        // would never EVER EVERRR happen!
//        if (set_.find(*ptrs_.front()) == set_.cend()) {
//            throw std::logic_error("Whoopsie dasies");
//        }
        assert(set_.find(*ptrs_.front()) != set_.cend());
        return *ptrs_.front();
    }

    void heapify() {
        Comparator cmp_local = cmp_;
        std::make_heap(ptrs_.begin(), ptrs_.end(), [&cmp_local](const auto &a, const auto &b) {
            return(cmp_local(*a, *b));
        });
    }

    bool empty() const {
        assert(set_.empty() == ptrs_.empty());
        return set_.empty();
    }

    void remove(const T& key) {
        if (set_.find(key) != set_.cend()) {
            // there's only one of key in vector, stop as soon as we see it - use find instead of remove (which
            // runs throughout the vector (waste of iterations)
            auto ptr = std::find_if(ptrs_.cbegin(), ptrs_.cend(), [&key](const auto &p) {
                return key == *p;
            });
            assert(ptr != ptrs_.cend());
            ptrs_.erase(ptr, ptr + 1);
            set_.erase(key);
            heapify();
        }
    }

    constexpr typename std::unordered_set<T>::size_type size() const  {
        return set_.size();
    }



private:
    // a vector of pointers that maps to an unordered set (hence the constness)
    using MVector = std::vector<const T *>;
    std::unordered_set<T> set_;
    MVector ptrs_;
    Comparator cmp_;

private:
    void sieve_up(typename MVector::size_type n);

    void sieve_down(typename MVector::size_type n = 0);
};

}   // end namespace aima

template<typename T, typename Comparator>
void aima::PriorityQueue<T, Comparator>::sieve_up(typename MVector::size_type n) {
    // parent node is n/2
    if (n > 0) {
        auto parent = n / 2;
        // if lhs is < rhs (if parent is smaller than child node)
        if (cmp_(*ptrs_[parent], *ptrs_[n])) {
            using std::swap;
            swap(ptrs_[parent], ptrs_[n]);
            sieve_up(parent);
        }
    }
}

template<typename T, typename Comparator>
void aima::PriorityQueue<T, Comparator>::sieve_down(typename MVector::size_type n) {
    // confirm that we're not out of bounds, and has at least one child (left node)
    if (n < ptrs_.size() && n * 2 < ptrs_.size()) {
        typename std::vector<T *>::size_type fav_child;
        if ((fav_child = n * 2) < ptrs_.size()) {
            //                                          left node   <   right node
            if (fav_child + 1 < ptrs_.size() && cmp_(*ptrs_[n * 2], *ptrs_[n * 2 + 1]) ) {
                // favour the right node (larger node)
                ++fav_child;
            }

            // if parent < (best)child, swap them and sieve downwards recursively
            if (cmp_(*ptrs_[n], *ptrs_[fav_child])) {
                using std::swap;
                swap(ptrs_[n], ptrs_[fav_child]);
                sieve_down(fav_child);
            }
        }
        // no child, nothing to compare
    }

}

#endif //AIMA_PRIORITY_QUEUE_H
