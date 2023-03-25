#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

int FindContentChildren(std::vector<int>& children, std::vector<int>& cookies) {
  std::sort(children.begin(), children.end());
  std::sort(cookies.begin(), cookies.end());
  int count = 0;
  int i = 0;
  int j = 0;
  while (i < children.size() && j < cookies.size()) {
    if (children[i] <= cookies[j]) {
      ++j;
      ++count;
    }
    ++i;
  }
  return count;
}

TEST(FindContentChildrenTest, HandleNormal) {
  std::vector<int> children = {1, 2, 3};
  std::vector<int> cookies = {1, 1};
  int count = 1;
  EXPECT_EQ(FindContentChildren(children, cookies), count);

  children = {1, 2};
  cookies = {1, 2, 3};
  count = 2;
  EXPECT_EQ(FindContentChildren(children, cookies), count);
}

TEST(FindContentChildrenTest, HandleCorner) {
  std::vector<int> children = {};
  std::vector<int> cookies = {1, 1};
  int count = 0;
  EXPECT_EQ(FindContentChildren(children, cookies), count);

  children = {1, 2};
  cookies = {};
  count = 0;
  EXPECT_EQ(FindContentChildren(children, cookies), count);
}

TEST(FindContentChildrenTest, HandleUnordered) {
  std::vector<int> children = {3, 1, 2};
  std::vector<int> cookies = {1, 1};
  int count = 1;
  EXPECT_EQ(FindContentChildren(children, cookies), count);
}
