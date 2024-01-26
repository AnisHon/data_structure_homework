//
// Created by Anis Han on 2024/1/25.
//

#ifndef CPPPROJECT01_LINEAR_LIST_H
#define CPPPROJECT01_LINEAR_LIST_H


template <typename T>
class LinearList {

public:

    virtual auto clear() -> void = 0;

    virtual auto isEmpty() -> bool =0;

    virtual auto length() -> int = 0;

    virtual auto get(int i) -> T = 0;

    virtual auto insert(int i, T t) -> void = 0;

    virtual auto insert(T t) -> void = 0;

    virtual auto remove(int i) -> T = 0;

    virtual auto find(T t) -> int = 0;

};


#endif //CPPPROJECT01_LINEAR_LIST_H
