#include <vector>

// 2024/01/13: 直接看答案, 二分法.
int FindDuplicate(std::vector<int>& nums) {
  int n = nums.size();
  int left = 1, right = n - 1, res = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    // 关键步骤: 寻找第一个count[i] > i的数.
    int count = 0;
    for (int i = 0; i < n; ++i) {
      count += nums[i] <= mid;
    }
    if (count > mid) {
      right = mid - 1;
      res = mid;
    } else {
      left = mid + 1;
    }
  }
  return res;
}