#include <iostream>
#include <string>
#include <vector>

// 2024/01/13: 不看答案自己做出来. 难点在与状态转移方程的推导.

int LongestCommonSubsequence(const std::string& text1,
                             const std::string& text2) {
  const int m = text1.size();
  const int n = text2.size();
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (text1[i - 1] == text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
      std::cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << std::endl;
    }
  }
  return dp[m][n];
}

int main(int argc, char* argv[]) {
  std::string text1 = "abcde";
  std::string text2 = "ace";
  std::cout << LongestCommonSubsequence(text1, text2) << std::endl;
  return 0;
}
