#include <vector>

int MaxProfit(std::vector<int>& prices) {
  if (prices.empty()) {
    return 0;
  }

  int n = prices.size();
  // f[i][0]: 手上持有股票的最大收益
  // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
  // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
  std::vector<std::vector<int>> f(n, std::vector<int>(3));
  f[0][0] = -prices[0];
  for (int i = 1; i < n; ++i) {
    f[i][0] = std::max(f[i - 1][0], f[i - 1][2] - prices[i]);
    f[i][1] = f[i - 1][0] + prices[i];
    f[i][2] = std::max(f[i - 1][1], f[i - 1][2]);
  }
  return std::max(f[n - 1][1], f[n - 1][2]);
}

// 用状态机来解决复杂的状态转移问题
int MaxProfit2(const std::vector<int>& prices) {
  int days = prices.size();
  if (days < 2) {
    return 0;
  }
  std::vector<int> buy(days);
  std::vector<int> sell(days);
  std::vector<int> s1(days);
  std::vector<int> s2(days);
  s1[0] = buy[0] = -prices[0];
  sell[0] = s2[0] = 0;
  for (int i = 1; i < days; ++i) {
    // 由于当前状态只和前一天的状态有关, 所以顺序不关键.
    buy[i] = s2[i - 1] - prices[i];
    s1[i] = std::max(buy[i - 1], s1[i - 1]);
    sell[i] = std::max(buy[i - 1], s1[i - 1]) + prices[i];
    s2[i] = std::max(s2[i - 1], sell[i - 1]);
  }
  return std::max(sell[days - 1], s2[days - 1]);
}
