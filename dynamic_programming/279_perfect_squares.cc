#include <vector>

#include "limits.h"

// 2024/01/12: 自己实现

int numSquares(int n) {
  std::vector<int> dp(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    int minn = INT_MAX;
    for (int j = 1; j * j <= i; ++j) { // 无需开根号, 直接比较
      minn = std::min(minn, dp[i - j * j]);
    }
    dp[i] = minn + 1;
  }
  return dp[n];
}