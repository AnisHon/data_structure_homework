//
// Created by happy on 24-10-29.
//

#ifndef CPPPROJECT01_STACK_H
#define CPPPROJECT01_STACK_H


#include <stdexcept>
#include "sequence_list.h"

template <class T>
class Stack {
    
public:
    void push(const T &t) {
        list.insert(t);
    }
    
    T top() {
        if (list.length() == 0) {
            throw std::runtime_error("Stack underflow error");
        }
        return list.get(list.length() - 1);
    }
    
    T pop() {
        if (list.length() == 0) {
            throw std::runtime_error("Stack underflow error");
        }

        return list.remove(list.length() - 1);;
    }

    bool empty() {
        return list.length() != 0;
    }
    
    
private:
    SequenceList<T> list;
    
};


#endif //CPPPROJECT01_STACK_H
