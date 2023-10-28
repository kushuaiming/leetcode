#include <iostream>
#include <string>
#include <vector>

// 三维0-1背包问题
int FindMaxForm(const std::vector<std::string>& strs, int m, int n) {
  // dp[i][j][k]表示前i个物品, 0的数量小与等于j个, 1的数量小与等与k个.
  std::vector<std::vector<std::vector<int>>> dp(
      strs.size() + 1,
      std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));
  for (int i = 1; i <= strs.size(); ++i) {
    const std::string str = strs[i - 1];
    int zero_counts = 0;
    int one_counts = 0;
    for (int l = 0; l < str.size(); ++l) {
      if (str[l] == '0') {
        ++zero_counts;
      } else if (str[l] == '1') {
        ++one_counts;
      }
    }
    std::cout << "i: " << i << ", zero_counts: " << zero_counts
              << ", one_counts: " << one_counts << std::endl;
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= n; ++k) {
        if (j < zero_counts || k < one_counts) {
          dp[i][j][k] = dp[i - 1][j][k];
        } else {
          dp[i][j][k] = std::max(
              dp[i - 1][j][k], dp[i - 1][j - zero_counts][k - one_counts] + 1);
        }
        std::cout << "j: " << j << ", k: " << k << ", dp[i][j][k] = "
                  << dp[i][j][k] << std::endl;
      }
    }
  }
  return dp[strs.size()][m][n];
}

int main(int argc, char* argv[]) {
  const std::vector<std::string> strs = {"01", "0", "1"};
  const int m = 1;
  const int n = 1;
  std::cout << FindMaxForm(strs, m, n);
  return 0;
}