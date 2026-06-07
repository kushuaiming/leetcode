from typing import List

# 0-1 背包问题.
def knapsack_0_1(weights: List[int], values: List[int], N: int, W: int) -> int:
    # dp[i][j] 表示只能选前 i 件物品且重量不超过 j 的情况下能达到的最大价值.
    dp = [[0] * (W + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        weight = weights[i - 1]
        value = values[i - 1]
        for j in range(1, W + 1):
            if j >= weight:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value)
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[-1][-1]

# 完全背包问题.
def knapsack_unbounded(weights: List[int], values: List[int], N: int, W: int) -> int:
    # dp[i][j] 表示只能选前 i 件物品且重量不超过 j 的情况下能达到的最大价值.
    dp = [[0] * (W + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        weight = weights[i - 1]
        value = values[i - 1]
        for j in range(1, W + 1):
            if j >= weight:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight] + value) # 和 0-1 背包的代码唯一区别.
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[-1][-1]

weights = [5, 4, 5, 3, 2]
values = [10, 5, 8, 4, 10]
N = 5
W = 15
print(knapsack_0_1(weights, values, N, W))