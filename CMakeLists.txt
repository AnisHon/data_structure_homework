cmake_minimum_required(VERSION 3.26)
project(CPPproject01 VERSION 1.1)


add_library(compiler_flags INTERFACE
        tree/test.cpp
        linear_list/stack.h)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
set(link_dir
        avl_tree.hpp
        basic_algorithm.cpp
        basic_algorithm.h
        red_black_tree.hpp
        util/binary_tree_util.hpp
        sort_algorithm.cpp
        sort_algorithm.h
        linear_list/linear_list.h
        linear_list/sequence_list.h
        linear_list/forward_list.h
        linear_list/symbol_list.h
        linear_list/order_symbol_list.h
)

add_executable(CPPproject01 main.cpp
        ${link_dir}
)

target_link_libraries(CPPproject01 PUBLIC TreeLib compiler_flags)
target_include_directories(CPPproject01 PUBLIC linear_list ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(tree)




