//
// @author: jiahong
// @date  : 25/05/18 12:08 AM
//

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

#include "priority_queue.h"
#include "catch.hpp"



TEST_CASE("Priority queue works on numerical data", "[TPQ1]") {
    SECTION("Priority queue - insertion obeys max heap property") {
        std::size_t iterations = 100'000;
        std::size_t seed = 123'456;
        std::mt19937 mersenne(seed);
        std::uniform_int_distribution<int> idist;
        aima::PriorityQueue<int> queue;

        for (auto i = 0; i < iterations; ++i) {
            auto n = idist(mersenne);
            while (queue.find(n) != queue.cend()) {
                n = idist(mersenne);
            }
            queue.push(n);
        }


        std::vector<int> flatten;
        flatten.reserve(iterations);

        while (!queue.empty()) {
            auto tmp = queue.top();
            queue.pop();
            flatten.push_back(tmp);
        }

        REQUIRE(std::is_heap(flatten.cbegin(), flatten.cend()));
    }

    SECTION("Priority queue - insertion obeys min heap property") {
        std::size_t iterations = 100'000;
        std::size_t seed = 123'456;
        std::mt19937 mersenne(seed);
        std::uniform_int_distribution<int> idist;
        auto cmp = std::greater<>{};
        aima::PriorityQueue<int, decltype(cmp)> queue(cmp);

        for (auto i = 0; i < iterations; ++i) {
            auto n = idist(mersenne);
            while (queue.find(n) != queue.cend()) {
                n = idist(mersenne);
            }
            queue.push(n);
        }


        std::vector<int> flatten;
        flatten.reserve(iterations);

        while (!queue.empty()) {
            auto tmp = queue.top();
            queue.pop();
            flatten.push_back(tmp);
        }

        REQUIRE(std::is_heap(flatten.cbegin(), flatten.cend(), cmp));
    }

    SECTION("Priority queue - deletion obeys min heap property") {
        std::size_t iterations = 10'000;
        std::size_t seed = 123'456;
        std::mt19937 mersenne(seed);
        std::uniform_int_distribution<int> idist;
        auto cmp = std::greater<>{};
        aima::PriorityQueue<int, decltype(cmp)> queue(cmp);

        std::vector<int> random_elements;

        for (auto i = 0; i < iterations; ++i) {
            auto n = idist(mersenne);
            while (queue.find(n) != queue.cend()) {
                n = idist(mersenne);
            }
            queue.push(n);
            if (idist(mersenne) % 2) {
                random_elements.push_back(n);
            }
        }


        // delete random elements
        for (const auto i : random_elements) {
            queue.remove(i);
        }

        std::vector<int> flatten;
        flatten.reserve(iterations);

        while (!queue.empty()) {
            auto tmp = queue.top();
            queue.pop();
            flatten.push_back(tmp);
        }

        REQUIRE(std::is_heap(flatten.cbegin(), flatten.cend(), cmp));
    }

    SECTION("Priority queue - deletion obeys max heap property") {
        std::size_t iterations = 10'000;
        std::size_t seed = 123'456;
        std::mt19937 mersenne(seed);
        std::uniform_int_distribution<int> idist;
        aima::PriorityQueue<int> queue;

        std::vector<int> random_elements;

        for (auto i = 0; i < iterations; ++i) {
            auto n = idist(mersenne);
            while (queue.find(n) != queue.cend()) {
                n = idist(mersenne);
            }
            queue.push(n);
            if (idist(mersenne) % 2) {
                random_elements.push_back(n);
            }
        }


        // delete random elements
        for (const auto i : random_elements) {
            queue.remove(i);
        }

        std::vector<int> flatten;
        flatten.reserve(iterations);

        while (!queue.empty()) {
            auto tmp = queue.top();
            queue.pop();
            flatten.push_back(tmp);
        }

        REQUIRE(std::is_heap(flatten.cbegin(), flatten.cend()));
    }
}
