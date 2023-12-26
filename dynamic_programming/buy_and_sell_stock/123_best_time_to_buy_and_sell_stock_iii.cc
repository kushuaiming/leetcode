#include <vector>

// 只可以交易2次
int MaxProfit(const std::vector<int>& prices) {
  const int days = prices.size();
  if (days < 2) {
    return 0;
  }
  std::vector<int> buy(2, -prices[0]);
  std::vector<int> sell(2, -prices[0]);
  for (int i = 1; i < days; ++i) {
    buy[0] = std::max(buy[0], -prices[i]);
    sell[0] = std::max(sell[0], buy[0] + prices[i]);
    buy[1] = std::max(buy[1], sell[0] - prices[i]);
    sell[1] = std::max(sell[1], buy[1] + prices[i]);
  }
  return sell[1];
}