#include <algorithm>
#include <vector>

// 2024/01/04: 完全自己写出dp方法
int MaxSubArray(std::vector<int>& nums) {
  int n = nums.size();
  // dp[i]: 以i结尾的连续数组的最大值.
  std::vector<int> dp(n, 0);
  dp[0] = nums[0];
  int res = nums[0];
  for (int i = 1; i < n; ++i) {
    dp[i] = nums[i] + std::max(dp[i - 1], 0);
    res = std::max(res, dp[i]);
  }
  return res;
}
