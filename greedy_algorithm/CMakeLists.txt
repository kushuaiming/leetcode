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
#   135_candy
#   135_candy.cc
# )
# target_link_libraries(
#   135_candy
#   GTest::gtest_main
# )
# gtest_discover_tests(135_candy)

# add_executable(
#   435_non_overlapping_intervals
#   435_non_overlapping_intervals.cc
# )
# target_link_libraries(
#   435_non_overlapping_intervals
#   GTest::gtest_main
# )
# gtest_discover_tests(435_non_overlapping_intervals)

# add_executable(
#   455_assign_cookies
#   455_assign_cookies.cc
# )
# target_link_libraries(
#   455_assign_cookies
#   GTest::gtest_main
# )
# gtest_discover_tests(455_assign_cookies)