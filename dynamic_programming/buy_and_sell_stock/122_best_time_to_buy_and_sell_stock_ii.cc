#include <vector>

// 可以交易无限次
int MaxProfit(const std::vector<int>& prices) {
  int max_profit = 0;
  for (int i = 1; i < prices.size(); ++i) {
    if (prices[i] > prices[i - 1]) {
      max_profit += prices[i] - prices[i - 1];
    }
  }
  return max_profit;
}

// buy[i]第i天持有股票时(可以是今天买的, 也可以是之前买的)获取的最大利润.
// sell[i]第i天不持有股票时(可以是今天卖的, 也可以是之前卖的)获取的最大利润.
// 假设手续费在卖的时候产生
int MaxProfit2(std::vector<int>& prices, int fee) {
  int n = prices.size();
  std::vector<int> sell(n);
  std::vector<int> buy(n);
  sell[0] = 0, buy[0] = -prices[0];
  for (int i = 1; i < n; ++i) {
    buy[i] = std::max(buy[i - 1], sell[i - 1] - prices[i]);
    sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
  }
  return sell[n - 1];
}
