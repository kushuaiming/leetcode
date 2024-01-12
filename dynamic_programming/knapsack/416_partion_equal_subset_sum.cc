#include <iostream>
#include <numeric>
#include <vector>

// 2024/01/12: 自己写出来了.

// 思路转换: 给定一个只包含正整数的非空数组, 判断是否可以从数组中选出一些数字,
// 使得这些数字的和等于整个数组的元素和的一半.
bool CanPartion(const std::vector<int>& nums) {
  const int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2) {
    return false;
  }
  const int target = sum / 2;
  int n = nums.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= target; ++j) {
      if (j < nums[i - 1]) {
        dp[i][j] = dp[i - 1][j] == 1 ? 1 : 0;
      } else {
        dp[i][j] =
            (dp[i - 1][j] == 1 || dp[i - 1][j - nums[i - 1]] == 1) ? 1 : 0;
      }
    }
  }
  return dp[n][target] == 1;
}

// 空间压缩
bool CanPartion2(const std::vector<int>& nums) {
  const int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2) {
    return false;
  }
  const int target = sum / 2;
  int n = nums.size();
  std::vector<int> dp(target + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = target; j >= nums[i - 1]; --j) {
      dp[j] = (dp[j] == 1 || dp[j - nums[i - 1]] == 1) ? 1 : 0;
    }
  }
  return dp[target] == 1;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 5};
  std::cout << CanPartion2(nums) << std::endl;
  return 0;
}
