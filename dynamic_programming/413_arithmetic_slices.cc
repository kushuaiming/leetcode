#include <iostream>
#include <numeric>
#include <vector>

// 注意审题: 子数组是连续的
// dp[i]: 以nums[i]结尾的等差数列的个数.
int NumberOfArithmeticSlices(std::vector<int>& nums) {
  int n = nums.size();
  if (n < 3) {
    return 0;
  }
  std::vector<int> dp(n, 0);
  for (int i = 2; i < n; ++i) {
    if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
      dp[i] = dp[i - 1] + 1;
    }
  }
  return std::accumulate(dp.begin(), dp.end(), 0);
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::cout << NumberOfArithmeticSlices(nums) << std::endl;
  return 0;
}
