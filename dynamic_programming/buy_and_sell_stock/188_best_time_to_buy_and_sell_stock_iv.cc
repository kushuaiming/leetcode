#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

//只可以交易k次
// 官方解法:
// buy[i][j]表示对于数组price[0,...,i]中的价格而言, 进行恰好j笔交易,
// 并且当前手上持有一只股票, 这种情况下的最大利润.
// sell[i][j]表示恰好进行j笔交易, 并且当前手上不持有股票, 这种情况下的最大利润.
// 注意: sell一次才算一次交易, 之后再buy不sell, 交易次数不变.
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
    buy[i][0] = std::max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
    for (int j = 1; j <= k; ++j) {
      buy[i][j] = std::max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
      sell[i][j] = std::max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
    }
  }
  return *std::max_element(sell[days - 1].begin(), sell[days - 1].end());
}

// 高赞题解:
// 定义买一次再卖一次才算一次交易.
// k从0开始, buy[0]发生再sell[0]之前, sell[0]发生在buy[1]之前.
// buy[k]是持有第k次交易的股票时(可以是今天买的, 也可以是之前买的)获取的最大利润.
// sell[k]是不持有第k次交易的股票时(可以是今天卖的, 也可以是之前卖的)获取的最大利润. 
// buy数组的长度即为k, buy[0]和sell[0]都需要维护, 最后返回sell[k-1].
int MaxProfit2(int k, const std::vector<int>& prices) {
  const int days = prices.size();
  if (days < 2 || k == 0) {
    return 0;
  }
  std::vector<int> buy(k, -prices[0]);
  std::vector<int> sell(k, -prices[0]);
  for (int i = 1; i < days; ++i) {
    buy[0] = std::max(buy[0], -prices[i]);
    sell[0] = std::max(sell[0], buy[0] + prices[i]);
    for (int j = 1; j < k; ++j) {
      buy[j] = std::max(buy[j], sell[j - 1] - prices[i]);
      sell[j] = std::max(sell[j], buy[j] + prices[i]);
    }
  }
  return sell[k - 1];
}

int main(int argc, char* argv[]) {
  const std::vector<int> prices = {3, 2, 6, 5, 0, 3};
  const int k = 2;
  std::cout << MaxProfit(k, prices) << std::endl;
  return 0;
}
