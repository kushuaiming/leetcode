cmake_minimum_required(VERSION 3.10)
project(my_project)
set(CMAKE_CXX_STANDARD 14)

add_executable(
  208_implement_trie
  trie/208_implement_trie.cc tree_node.cc
)

target_include_directories(208_implement_trie
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)
