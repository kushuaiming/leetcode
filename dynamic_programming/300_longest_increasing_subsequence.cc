#include <iostream>
#include <vector>

int LengthOfLIS(const std::vector<int>& nums) {
  // dp[i] represents the length of longest increasing subsequence ended with
  // nums[i].
  std::vector<int> dp(nums.size(), 1);
  int length_of_lis = 0;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    length_of_lis = std::max(length_of_lis, dp[i]);
    std::cout << "dp[" << i << "]: " << dp[i] << std::endl;
  }
  return length_of_lis;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  std::cout << LengthOfLIS(nums) << std::endl;
  return 0;
}