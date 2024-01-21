#include <algorithm>
#include <vector>

// 2024/01/11: 自己不看答案写出来.

int FindMin(std::vector<int>& nums) {
  int left = 0, right = nums.size() - 1;
  // 注意: 考虑到没有旋转的情况, 初始化为第一个数.
  int min_num = nums.front();
  while (left <= right) {
    int mid = left + (right - left) / 2;
    min_num = std::min(min_num, nums[mid]);
    if (nums[mid] >= nums.front()) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return min_num;
}
