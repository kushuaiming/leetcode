cmake_minimum_required(VERSION 3.14)
project(my_project)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        03597a01ee50ed33e9dfd640b249b4be3799d395
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# add_executable(
#   1_two_sum
#   1_two_sum.cc
# )
# target_link_libraries(
#   1_two_sum
#   GTest::gtest_main
# )
# gtest_discover_tests(1_two_sum)

# add_executable(
#   88_merge_sorted_array
#   88_merge_sorted_array.cc
# )
# target_link_libraries(
#   88_merge_sorted_array
#   GTest::gtest_main
# )
# gtest_discover_tests(88_merge_sorted_array)

# add_executable(
#   135_candy
#   135_candy.cc
# )
# target_link_libraries(
#   135_candy
#   GTest::gtest_main
# )
# gtest_discover_tests(135_candy)

# add_executable(
#   167_two_sum_II
#   167_two_sum_II.cc
# )
# target_link_libraries(
#   167_two_sum_II
#   GTest::gtest_main
# )
# gtest_discover_tests(167_two_sum_II)

add_executable(
  76_minimum_window_substring
  76_minimum_window_substring.cc
)