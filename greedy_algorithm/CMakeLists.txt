cmake_minimum_required(VERSION 3.14)
project(my_project)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

add_executable(
  135_candy
  135_candy.cc
)
add_executable(
  455_assign_cookies
  455_assign_cookies.cc
)
add_executable(
  605_can_place_flowers
  605_can_place_flowers.cc
)