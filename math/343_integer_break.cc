#include <cmath>
#include <vector>

// 2024/01/10: 集度面试问到了, 直接抄答案.
int IntegerBreak(int n) {
  if (n <= 3) {
    return n - 1;
  }
  int quotient = n / 3;
  int remainder = n % 3;
  if (remainder == 0) {
    return static_cast<int>(std::pow(3, quotient));
  } else if (remainder == 1) {
    return static_cast<int>(std::pow(3, quotient - 1) * 4);
  } else {
    return static_cast<int>(std::pow(3, quotient) * 2);
  }
}

// 动态规划, 直接抄答案
int IntegerBreak2(int n) {
  std::vector<int> dp(n + 1);
  for (int i = 2; i <= n; i++) {
    int cur_max = 0;
    for (int j = 1; j < i; j++) {
      cur_max = std::max(cur_max, std::max(j * (i - j), j * dp[i - j]));
    }
    dp[i] = cur_max;
  }
  return dp[n];
}
