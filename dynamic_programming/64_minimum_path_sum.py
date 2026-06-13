from typing import List

# 2026/06/13: 不看答案自己完成.
def min_path_sum(grid: List[List[int]]) -> int:
    # dp[i][j] 表示从左上角到 i, j 的最小路径最小值.
    m, n = len(grid), len(grid[0])
    dp = [[0] * n for _ in range(m)]

    dp[0][0] = grid[0][0]
    for i in range(1, m):
        dp[i][0] = dp[i - 1][0] + grid[i][0]
    for i in range(1, n):
        dp[0][i] = dp[0][i - 1] + grid[0][i]

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

    return dp[-1][-1]


grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
print(min_path_sum(grid))
