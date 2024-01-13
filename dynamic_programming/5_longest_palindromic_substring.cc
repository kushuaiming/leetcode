#include <string>
#include <vector>

// 2024/01/13: 自己写出来

std::string LongestPalindrome(std::string s) {
  int n = s.size();
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (j == i + 1) {
        dp[i][j] = s[i] == s[j];
      } else {
        dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]);
      }
    }
  }
  int max_length = 0;
  std::string res;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (dp[i][j] && j - i + 1 > max_length) {
        max_length = j - i + 1;
        res = s.substr(i, j - i + 1);
      }
    }
  }
  return res;
}
