#include <algorithm>
#include <limits>
#include <vector>

// 把自己代入一个: 可以每天观察和记录收益情况和可以无限反悔重买的情景
// 关键是记录历史最低价
int maxProfit(const std::vector<int>& prices) {
  int history_min_price = std::numeric_limits<int>::max();
  int max_profit = 0;
  for (int i = 0; i < static_cast<int>(prices.size()); ++i) {
    max_profit = std::max(max_profit, prices[i] - history_min_price);
    history_min_price = std::min(history_min_price, prices[i]);
  }
  return max_profit;
}
