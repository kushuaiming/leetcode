#include <algorithm>
#include <vector>

// 2024/01/04: 可以不看答案自己写出来.

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
  auto cmp = [](const std::vector<int>& left, const std::vector<int>& right) {
    if (left[0] < right[0]) {
      return true;
    } else if (left[0] > right[0]) {
      return false;
    } else {
      return left[1] < right[1];
    }
  };
  // 必要步骤: 进行排序, 可以不自己写cmp.
  std::sort(intervals.begin(), intervals.end(), cmp);
  std::vector<std::vector<int>> res;
  // 也可以直接与res.back进行比较.
  int left = intervals[0][0], right = intervals[0][1];
  for (const auto& interval : intervals) {
    if (interval[0] <= right && interval[1] >= left) {
      left = std::min(left, interval[0]);
      right = std::max(right, interval[1]);
    } else {
      res.push_back({left, right});
      left = interval[0];
      right = interval[1];
    }
  }
  res.push_back({left, right});
  return res;
}
