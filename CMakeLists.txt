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
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
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

add_executable(
  455_assign_cookies
  455_assign_cookies.cc
)
target_link_libraries(
  455_assign_cookies
  GTest::gtest_main
)
gtest_discover_tests(455_assign_cookies)