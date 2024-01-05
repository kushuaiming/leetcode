#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// 2024/01/05: 自己写出来贪心算法, 但是是逆序. 维护未来最高价格.

// 只可以交易一次
int MaxProfit(const std::vector<int>& prices) {
  int history_min_price = std::numeric_limits<int>::max();
  int max_profit = 0;
  for (int i = 0; i < static_cast<int>(prices.size()); ++i) {
    max_profit = std::max(max_profit, prices[i] - history_min_price);
    history_min_price = std::min(history_min_price, prices[i]);
  }
  return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  std::cout << MaxProfit(prices) << std::endl;
  return 0;
}
