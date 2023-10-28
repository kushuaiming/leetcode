#include <iostream>
#include <vector>

// 0-1背包问题: 限定每种物品只能选0个或者1个.
// N个物品和容量为W的背包.
// 求可以装得物品的最大价值.
int knapsack0(const std::vector<int>& weights, const std::vector<int>& values,
             int N, int W) {
  // dp[i][j]表示前i件物品体积不超过j的情况下能达到的最大价值.
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
  for (int i = 1; i <= N; ++i) {
    const int weight = weights[i - 1];
    const int value = values[i - 1];
    for (int j = 1; j <= W; ++j) {
      if (j >= weight) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight] + value);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
      std::cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << std::endl;
    }
  }
  return dp[N][W];
}

// 空间压缩, 需要逆向遍历
int knapsack1(const std::vector<int>& weights, const std::vector<int>& values,
              int N, int W) {
  // dp[j]表示前i件物品体积不超过j的情况下能达到的最大价值.
  std::vector<int> dp(W + 1, 0);
  for (int i = 1; i <= N; ++i) {
    const int weight = weights[i - 1];
    const int value = values[i - 1];
    for (int j = W; j >= weight; --j) {
      dp[j] = std::max(dp[j], dp[j - weight] + value);
    }
  }
  return dp[W];
}

// 完全背包问题: 不限定每种物品的数量
int knapsack2(const std::vector<int>& weights, const std::vector<int>& values,
             int N, int W) {
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
  for (int i = 1; i <= N; ++i) {
    const int weight = weights[i - 1];
    const int value = values[i - 1];
    for (int j = 1; j <= W; ++j) {
      if (j >= weight) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight] + value);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
      std::cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << std::endl;
    }
  }
  return dp[N][W];
}

// 空间压缩, 需正向遍历
int knapsack3(const std::vector<int>& weights, const std::vector<int>& values,
              int N, int W) {
  // dp[j]表示前i件物品体积不超过j的情况下能达到的最大价值.
  std::vector<int> dp(W + 1, 0);
  for (int i = 1; i <= N; ++i) {
    const int weight = weights[i - 1];
    const int value = values[i - 1];
    for (int j = weight; j <= W; ++j) {
      dp[j] = std::max(dp[j], dp[j - weight] + value);
    }
  }
  return dp[W];
}


int main(int argc, char* argv[]) {
  const std::vector<int> weights = {5, 4, 5, 3, 2};
  const std::vector<int> values = {10, 5, 8, 4, 10};
  const int N = 5;
  const int W = 15;
  std::cout << knapsack0(weights, values, N, W) << std::endl;
  std::cout << knapsack1(weights, values, N, W) << std::endl;
  std::cout << knapsack2(weights, values, N, W) << std::endl;
  std::cout << knapsack3(weights, values, N, W) << std::endl;
  return 0;
}
