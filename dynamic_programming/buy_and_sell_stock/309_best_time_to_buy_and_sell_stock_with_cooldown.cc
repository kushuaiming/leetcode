#include <iostream>
#include <vector>

int MaxProfit(std::vector<int>& prices) {
  if (prices.empty()) {
    return 0;
  }

  int n = prices.size();
  // buy[i]: 手上持有股票的最大收益
  // freeze[i]: 手上不持有股票, 并且处于冷冻期中的累计最大收益, 第i天卖出股票了.
  // sell[i]: 手上不持有股票, 并且不在冷冻期中的累计最大收益, 第i天没有卖出股票.
  std::vector<int> buy(n, 0);
  std::vector<int> freeze(n, 0);
  std::vector<int> sell(n, 0);
  buy[0] = -prices[0];
  for (int i = 1; i < n; ++i) {
    buy[i] = std::max(buy[i - 1], sell[i - 1] - prices[i]);
    freeze[i] = buy[i - 1] + prices[i];
    sell[i] = std::max(freeze[i - 1], sell[i - 1]);
  }
  return std::max(freeze[n - 1], sell[n - 1]);
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

int main(int argc, char* argv[]) {
  std::vector<int> prices = {1, 2, 3, 0, 2};
  std::cout << MaxProfit(prices) << std::endl;
  return 0;
}
