from typing import List

# 2026/06/07: 复习了背包问题之后自己写出来.
def coin_change(coins: List[int], amount: int) -> int:
    # dp[i][j] 表示只用前 i 类钱币且价值正好为 j 所需最小数量.
    dp = [[float("inf")] * (amount + 1) for _ in range(len(coins) + 1)]

    for i in range(1, len(coins) + 1):
        dp[i][0] = 0

    for i in range(1, len(coins) + 1):
        coin = coins[i - 1]
        for j in range(1, amount + 1):
            if j >= coin:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coin] + 1)
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[-1][-1] if dp[-1][-1] != float("inf") else -1

coins = [1, 2, 5]
amount = 11

coins = [2]
amount = 3
print(coin_change(coins, amount))