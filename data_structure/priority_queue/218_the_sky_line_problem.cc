#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

// 2023/12/30 直接抄答案, 思路和实现都较为难
std::vector<std::vector<int>> GetSkyLine(
    const std::vector<std::vector<int>>& buildings) {
  auto cmp = [](const std::pair<int, int>& left,
                const std::pair<int, int>& right) {
    return left.second < right.second;
  };
  // 优先队列里存放的是建筑的右边缘信息和高度信息.
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(cmp)>
      q(cmp);

  // boundaries里面存放的是所有建筑的左右边缘信息.
  std::vector<int> boundaries;
  for (const auto& building : buildings) {
    boundaries.emplace_back(building[0]);
    boundaries.emplace_back(building[1]);
  }
  std::sort(boundaries.begin(), boundaries.end());

  std::vector<std::vector<int>> ret;
  int n = buildings.size(), index = 0;
  for (int boundary : boundaries) {
    while (index < n && buildings[index][0] <= boundary) {
      q.emplace(buildings[index][1], buildings[index][2]);
      ++index;
    }
    while (!q.empty() && q.top().first <= boundary) {
      q.pop();
    }
    int maxn = q.empty() ? 0 : q.top().second;
    if (ret.size() == 0 || maxn != ret.back()[1]) {
      ret.push_back({boundary, maxn});
    }
  }
  return ret;
}
