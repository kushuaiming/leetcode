#include <algorithm>
#include <vector>

// 2024/01/12: 直接看答案.

// 关键思路: 想到用两个dp数组同时存储最大乘积和最小乘积.
int MaxProduct(std::vector<int>& nums) {
  std::vector<int> max_f(nums), min_f(nums);
  for (int i = 1; i < nums.size(); ++i) {
    max_f[i] =
        std::max({max_f[i - 1] * nums[i], min_f[i - 1] * nums[i], nums[i]});
    min_f[i] =
        std::min({min_f[i - 1] * nums[i], max_f[i - 1] * nums[i], nums[i]});
  }
  return *std::max_element(max_f.begin(), max_f.end());
}
