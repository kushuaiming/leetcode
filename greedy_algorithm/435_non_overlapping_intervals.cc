#include <algorithm>
#include <iostream>
#include <vector>

// 贪心策略: 优先保留结尾小且不相交的区间.
// 具体实现方法: 先把区间按照结尾的大小进行增序排序,
// 每次选择结尾最小且和前一个选择的区间不重叠的区间.
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

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  std::cout << EraseOverlapIntervals(intervals) << std::endl;
}
