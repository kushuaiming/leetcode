#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

int EraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }

  auto compare = [](const std::vector<int>& left,
                    const std::vector<int>& right) {
    return left.back() < right.back();
  };
  std::sort(intervals.begin(), intervals.end(), compare);
  int count = 0;
  int max_right_number = intervals[0][1];
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i][0] >= max_right_number) {
      max_right_number = intervals[i][1];
    } else {
      ++count;
    }
  }
  return count;
}

TEST(EraseOverlapIntervalsTest, HandleNormal) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  int count = 1;
  EXPECT_EQ(EraseOverlapIntervals(intervals), count);

  intervals = {{1, 2}, {1, 2}, {1, 2}};
  count = 2;
  EXPECT_EQ(EraseOverlapIntervals(intervals), count);

  intervals = {{1, 2}, {2, 3}};
  count = 0;
  EXPECT_EQ(EraseOverlapIntervals(intervals), count);
}

TEST(EraseOverlapIntervalsTest, HandleEmpty) {
  std::vector<std::vector<int>> intervals = {};
  int count = 0;
  EXPECT_EQ(EraseOverlapIntervals(intervals), count);
}
