import math


# 2026/06/05: 自己实现, debug 了一下.
def num_squares(n: int) -> int:
    dp = [float("inf")] * (n + 1)
    dp[0] = 0
    for i in range(1, n + 1):
        for j in range(1, int(math.sqrt(i)) + 1):
            dp[i] = min(dp[i - j * j] + 1, dp[i])
    return dp[-1]


print(num_squares(12))
print(num_squares(13))
