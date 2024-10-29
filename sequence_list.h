//
// Created by Anis Han on 2024/1/25.
//

#ifndef CPPPROJECT01_SEQUENCE_LIST_H
#define CPPPROJECT01_SEQUENCE_LIST_H

#include "linear_list.h"
#include <stdexcept>
#include <algorithm>

template <typename T>
class SequenceList : public LinearList<T> {

private:
    int size_;
    int capacity_;
    T *elements_;
    const int BLOCK = 5;

    auto maintain(int i) -> void {

        if (size_ >= capacity_) {
            T *temp = nullptr;
            capacity_ += BLOCK;
            temp = new T[capacity_];
            std::copy(elements_, elements_ + i, temp);
            std::copy(elements_ + i, elements_ + size_, temp + i + 1);
            delete[] elements_;
            elements_ = temp;
        } else {
            for (int j = size_ - 1; j >= i; --j) {
                elements_[j + 1] = elements_[j];
            }
        }
        size_++;
    }


public:
    SequenceList() {
        size_ = 0;
        elements_ = new T[BLOCK];
        capacity_ = BLOCK;
    }

    auto clear() -> void override {
        size_ = 0;
    }

    auto isEmpty() -> bool override {
        return size_ == 0;
    }

    auto length() -> int override {
        return size_;
    }

    auto get(int i) -> T override {
        if (i >= size_ || i < 0) throw std::out_of_range("out of range");
        return elements_[i];
    }

    auto insert(int i, T t) -> void override {
        if (i > size_ || i < 0) throw std::out_of_range("out of range");
        maintain(i);
        elements_[i] = t;
    }

    auto insert(T t) -> void override {
        maintain(size_);
        elements_[size_ - 1] = t;
    }

    auto remove(int i) -> T override {
        if (i >= size_ || i < 0) throw std::out_of_range("out of range");
        T temp = elements_[i];
        for (int j = i; j < size_ - 1; ++j) {
            elements_[j] = elements_[j + 1];
        }
        --size_;
        return temp;
    }

    auto find(T t) -> int override {
        int result = -1;
        for (int i = 0; i < size_; ++i) {
            if (elements_[i] == t) {
                result = i;
                break;
            }
        }
        return result;
    }


};

#endif //CPPPROJECT01_SEQUENCE_LIST_H
