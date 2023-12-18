cmake_minimum_required(VERSION 3.26)
project(CPPproject01)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPPproject01 main.cpp
        avl_tree.hpp
        basic_algorithm.cpp
        basic_algorithm.h
        black_red_tree.hpp
        util/binary_tree_util.hpp
)
