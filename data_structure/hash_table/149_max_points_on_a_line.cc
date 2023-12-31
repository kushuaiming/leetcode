#include <unordered_map>
#include <vector>

// 一条线可以由一个点和斜率而唯一确定.
// 对于每个点, 我们对其它点建立哈希表, key 设计为斜率, value 设计为同一斜率的点的数量.
// 另外也要考虑斜率不存在和重复坐标的情况.
int MaxPoints(const std::vector<std::vector<int>>& points) {
  std::unordered_map<double, int> hash;
  int max_count = 0;
  int same_x = 0;
  for (int i = 0; i < static_cast<int>(points.size()); ++i) {
    same_x = 0;
    for (int j = i + 1; j < static_cast<int>(points.size()); ++j) {
      if (points[i][0] == points[j][0]) {
        ++same_x;
      } else {
        const double dx = points[i][0] - points[j][0];
        const double dy = points[i][1] - points[j][1];
        ++hash[dy / dx];
      }
    }
    max_count = std::max(max_count, same_x + 1);
    for (auto item : hash) {
      max_count = std::max(max_count, item.second + 1);
    }
    hash.clear();  // 不要忘记clear
  }
  return max_count;
}
