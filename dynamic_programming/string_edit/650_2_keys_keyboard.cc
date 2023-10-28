#include <vector>

int MinStep(int n) {
  std::vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    // 这里可以优化成 j * j <= i.
    for (int j = 1; j < i; ++j) {
      if (i % j == 0) {
        dp[i] = dp[j] + i / j;
      }
    }
  }
  return dp[n];
}