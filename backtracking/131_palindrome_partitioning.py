from typing import List


# 2026/05/22: 直接抄答案.
# 回溯 + 动态规划预处理
def partition1(s: str) -> List[List[str]]:
    n = len(s)

    # f[i][j] 表示子串 s[i..j] 是否为回文.
    f = [[True] * n for _ in range(n)]
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            f[i][j] = (s[i] == s[j]) and f[i + 1][j - 1]

    results = []
    result = []

    def dfs(i: int) -> None:
        if i == n:
            results.append(result[:])
            return

        for j in range(i, n):
            if f[i][j]:
                result.append(s[i : j + 1])
                dfs(j + 1)
                result.pop()

    dfs(0)
    return results


s = "aab"
print(partition1(s))
