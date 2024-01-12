#include <climits>
#include <vector>

// 2024/01/12: 复习了背包问题, 且调试了25min完成.
// 完全背包问题
int CoinChange(std::vector<int>& coins, int amount) {
  // dp[i][j]: 可以使用第i个coin, 总价值正好为j.
  int m = coins.size();
  std::vector<std::vector<int>> dp(m + 1,
                                   std::vector<int>(amount + 1, INT_MAX));
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= amount; ++j) {
      if (j == 0) {
        dp[i][j] = 0; // 粗心! = 而非 == 
        continue;
      }
      if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX) {
        dp[i][j] = std::min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
      }
      dp[i][j] = std::min(dp[i][j], dp[i - 1][j]); // 粗心! 需要取小.
    }
  }
  return dp[m][amount] == INT_MAX ? -1 : dp[m][amount];
}

int main(int argc, char* argv[]) {
  std::vector<int> coins = {1,2,5};
  CoinChange(coins, 11);
  return 0;
}