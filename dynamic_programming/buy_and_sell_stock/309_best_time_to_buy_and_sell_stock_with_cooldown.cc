#include <vector>

// 用状态机来解决复杂的状态转移问题
int MaxProfit(const std::vector<int>& prices) {
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
    buy[i] = s2[i - 1] - prices[i];
    s1[i] = std::max(buy[i - 1], s1[i - 1]);
    sell[i] = std::max(buy[i - 1], s1[i - 1]) + prices[i];
    s2[i] = std::max(s2[i - 1], sell[i - 1]);
  }
  return std::max(sell[days - 1], s2[days - 1]);
}
