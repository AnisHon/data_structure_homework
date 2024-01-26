add_library(TreeLib BinaryTree.h BinarySearchTree.h test.cpp
        avl_tree.h
        binary_search_tree_map.h
        binary_tree_map.h
)

target_link_libraries(TreeLib compiler_flags)
target_include_directories(TreeLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")



