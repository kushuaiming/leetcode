#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// buy[i][j]表示对于数组price[0,...,i]中的价格而言, 进行恰好j笔交易,
// 并且当前手上持有一只股票, 这种情况下的最大利润.
// sell[i][j]表示恰好进行j笔交易, 并且当前手上不持有股票, 这种情况下的最大利润.
int MaxProfit(int k, const std::vector<int>& prices) {
  const int days = prices.size();
  if (days < 2) {
    return 0;
  }
  k = std::min(k, days / 2);
  std::vector<std::vector<int>> buy(days, std::vector<int>(k + 1));
  std::vector<std::vector<int>> sell(days, std::vector<int>(k + 1));
  buy[0][0] = -prices[0];
  sell[0][0] = 0;
  for (int i = 1; i <= k; ++i) {
    buy[0][i] = sell[0][i] = INT_MIN / 2;
  }
  for (int i = 1; i < days; ++i) {
    for (int j = 1; j <= k; ++j) {
      buy[i][j] = std::max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
      sell[i][j] = std::max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
    }
  }
  return *std::max_element(sell[days - 1].begin(), sell[days - 1].end());
}

int main(int argc, char* argv[]) {
  const std::vector<int> prices = {3, 2, 6, 5, 0, 3};
  const int k = 2;
  std::cout << MaxProfit(k, prices) << std::endl;
  return 0;
}
