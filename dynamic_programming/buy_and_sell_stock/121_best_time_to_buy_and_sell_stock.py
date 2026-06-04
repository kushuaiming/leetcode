from typing import List


# 2026/06/04: 自己写出答案.
def max_profit(prices: List[int]) -> int:
    dp = [0] * len(prices)  # dp[i] 表示以 i 结尾的最大利润.

    min_price = prices[0]
    for i in range(1, len(prices)):
        dp[i] = max(dp[i - 1], prices[i] - min_price)
        min_price = min(min_price, prices[i])

    return dp[-1]


prices1 = [7, 1, 5, 3, 6, 4]
prices2 = [7, 6, 4, 3, 1]
prices3 = [1, 2]
print(max_profit(prices3))
