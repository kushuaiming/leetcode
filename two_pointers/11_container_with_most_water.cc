#include <algorithm>
#include <vector>

// 2024/01/03: 自己只写出暴力解法, 会超时.

// 思路不容易想到, 实现简单.
int MaxArea(std::vector<int>& height) {
  int left = 0, right = height.size() - 1;
  int res = 0;
  while (left < right) {
    res = std::max(res, (right - left) * std::min(height[left], height[right]));
    if (height[left] < height[right]) {
      ++left;
    } else {
      --right;
    }
  }
  return res;
}
