//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_HEAP_H
#define CPPPROJECT01_HEAP_H

#include <algorithm>
#include <stdexcept>
#include <iostream>
template<typename T>
class Heap {
public:
    T *array_;
    int size_;
    int capacity_;
public:
    explicit Heap(int n): array_{new T[n]}, capacity_{n}, size_{0} {}

    auto insert(T t) -> void {
        if (capacity_ - 1 <= size_) throw std::overflow_error("low capacity");
        int index = ++size_;
        array_[index] = t;
        while (index > 1) {

            if (array_[index / 2] < array_[index]) {
                std::swap(array_[index / 2], array_[index]);
                index /= 2;
            } else {
                break;
            }

        }

    }

    auto delete_max() -> T {
//        p();
        if (size_ == 0) throw std::out_of_range("nothing here");
        std::swap(array_[size_--], array_[1]);
        //p();
        int index = 1;
        while (index <= size_ / 2) {
            if (index * 2 + 1 > size_) {
                std::swap(array_[index], array_[index * 2]);
                index *= 2;
                continue;
            }

            if (array_[index * 2] > array_[index * 2 + 1]) {
                std::swap(array_[index], array_[index * 2]);
                index *= 2;
            } else {
                std::swap(array_[index], array_[index * 2 + 1]);
                index = index * 2 + 1;
            }
//            p();
        }
        return array_[size_ + 1];
    }

    auto p() -> void {
        for (int i = 1; i <= size_; ++i) {
            std::cout << array_[i] << " ";
        }
        std::cout << "\n";
    };


    auto size() -> int {
        return size_ - 1;
    }

    ~Heap() {
        delete[] array_;
    }
};

#endif //CPPPROJECT01_HEAP_H
