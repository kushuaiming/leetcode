#include <iostream>
#include <vector>

// buy[i]第i天持有股票时(可以是今天买的, 也可以是之前买的)获取的最大利润.
// sell[i]第i天不持有股票时(可以是今天卖的, 也可以是之前卖的)获取的最大利润.
// 假设手续费在卖的时候产生
int MaxProfit(std::vector<int>& prices, int fee) {
  int n = prices.size();
  std::vector<int> sell(n);
  std::vector<int> buy(n);
  sell[0] = 0, buy[0] = -prices[0];
  for (int i = 1; i < n; ++i) {
    buy[i] = std::max(buy[i - 1], sell[i - 1] - prices[i]);
    sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i] - fee);
  }
  return sell[n - 1];
}

int main(int argc, char* argv[]) {
  std::vector<int> prices = {1, 3, 2, 8, 4, 9};
  std::cout << MaxProfit(prices, 2) << std::endl;
  return 0;
}
