# 2026/06/13: 自己写出答案
def unique_paths(m: int, n: int) -> int:
    dp = [[0] * n for _ in range(m)]
    for i in range(m):
        dp[i][0] = 1
    for i in range(n):
        dp[0][i] = 1

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    return dp[-1][-1]

m = 3
n = 7
print(unique_paths(m, n))