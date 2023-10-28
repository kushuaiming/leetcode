#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int MinDistance(const std::string& word1, const std::string& word2) {
  const int m = word1.size();
  const int n = word2.size();
  // dp[i][j]表示word1的前i个字母和word2的前j个字母之间的编辑距离.
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (int i = 0; i <= m; ++i) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= n; ++i) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
      }
      std::cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << std::endl;
    }
  }
  return dp[m][n];
}

int main(int argc, char* argv[]) {
  const std::string word1 = "horse";
  const std::string word2 = "ros";
  std::cout << MinDistance(word1, word2) << std::endl;
  return 0;
}
