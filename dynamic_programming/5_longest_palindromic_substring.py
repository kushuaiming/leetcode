# 2026/06/13: 自己写出来, 用时 21min.
def longest_palindrome(s: str) -> str:
    # dp[i, j] 表示 [i, j] 是否是回文字串
    dp = [[False] * len(s) for _ in range(len(s))]

    max_length = -1
    result = ""
    for i in reversed(range(len(s))):
        for j in range(i, len(s)):
            if j == i:
                dp[i][j] = True
            elif j == i + 1:
                dp[i][j] = s[i] == s[j]
            else:
                dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]

            if dp[i][j] and j - i + 1 > max_length:
                max_length = max(max_length, j - i + 1)
                result = s[i : j + 1]

    return result


s = "babad"
s = "cbbd"
print(longest_palindrome(s))
