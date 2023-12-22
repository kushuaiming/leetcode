cmake_minimum_required(VERSION 3.10)
project(my_project)
set(CMAKE_CXX_STANDARD 14)

add_executable(
  105_construct_binary_tree_from_preorder_and_inorder_traversal
  105_construct_binary_tree_from_preorder_and_inorder_traversal.cc tree_node.cc
)

target_include_directories(105_construct_binary_tree_from_preorder_and_inorder_traversal
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)
