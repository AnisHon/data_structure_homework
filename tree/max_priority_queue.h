//
// Created by Anis Han on 2024/1/27.
//

#ifndef CPPPROJECT01_MAX_PRIORITY_QUEUE_H
#define CPPPROJECT01_MAX_PRIORITY_QUEUE_H

#include "heap.h"
#include <iostream>

template<typename T>
class MaxPriorityQueue {

    struct Element {
        T t;

        bool operator<(const Element &rhs) const {
            return t < rhs.t;
        }

        bool operator>(const Element &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const Element &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const Element &rhs) const {
            return !(*this < rhs);
        }

        friend std::ostream &operator<<(std::ostream &os, Element &node) {
            os << node.t;
            return os;
        }

        explicit Element(T v):t{v} {}
        explicit Element() {}

    };

    Heap<Element> heap_;

public:
    explicit MaxPriorityQueue():heap_{100} {};

    auto pop() -> T {
        return heap_.delete_max().t;
    }

    auto push_back(T t) -> void {
        heap_.insert(Element(t));
    }

    auto size() -> int {
        return heap_.size();
    }

    auto empty() -> bool {
        return heap_.size() < 0;
    }



};

#endif //CPPPROJECT01_MAX_PRIORITY_QUEUE_H
