#include <vector>

#include "limits.h"

int numSquares(int n) {
  std::vector<int> dp(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    int minn = INT_MAX;
    for (int j = 1; j * j <= i; ++j) {
      minn = std::min(minn, dp[i - j * j]);
    }
    dp[i] = minn + 1;
  }
  return dp[n];
}