# 2026/06/13: 自己写出来, 用时 20min.
def min_distance(word1: str, word2: str) -> int:
    m, n = len(word1), len(word2)
    # dp[i, j] 表示 word1[0 : i], word[0 : j] 的 min_distance.
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            else:
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1)
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
    return dp[-1][-1]

word1 = "intention"
word2 = "execution"
print(min_distance(word1, word2))
