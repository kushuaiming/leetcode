# 2026/06/13: 不看答案自己实现, 用时 19min.
def longest_common_subsequence(text1: str, text2: str) -> int:
    # dp[i, j] 表示 text1 以 i 结尾, text2 以 j 结尾的最长公共字串的长度.
    m, n = len(text1), len(text2)
    dp = [[0] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                dp[i][j] = int(text1[i] == text2[j])
            elif i == 0:
                dp[i][j] = max(int(text1[i] == text2[j]), dp[i][j - 1])
            elif j == 0:
                dp[i][j] = max(int(text1[i] == text2[j]), dp[i - 1][j])
            else:
                dp[i][j] = max(
                    int(text1[i] == text2[j]) + dp[i - 1][j - 1],
                    dp[i - 1][j],
                    dp[i][j - 1],
                )
    return dp[-1][-1]


text1 = "abcde"
text2 = "ace"
print(longest_common_subsequence(text1, text2))
