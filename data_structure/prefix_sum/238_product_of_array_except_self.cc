#include <vector>

// 2024/01/05: 直接看答案

std::vector<int> productExceptSelf(std::vector<int>& nums) {
  // 关键思路: 左右乘积列表
  int n = nums.size();
  std::vector<int> left(n, 0);
  std::vector<int> right(n, 0);
  left[0] = 1;
  for (int i = 1; i < n; ++i) {
    left[i] = left[i - 1] * nums[i - 1];
  }
  right[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    right[i] = right[i + 1] * nums[i + 1];
  }
  std::vector<int> res(n, 0);
  for (int i = 0; i < n; ++i) {
    res[i] = left[i] * right[i];
  }
  return res;
}
