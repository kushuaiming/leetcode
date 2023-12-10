#include <vector>

std::vector<int> CountBits(int n) {
  std::vector<int> dp(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
  }
  return dp;
}