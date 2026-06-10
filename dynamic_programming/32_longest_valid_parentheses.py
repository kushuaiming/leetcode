# 2026/06/10: 直接看答案
def longest_valid_parentheses(s: str) -> int:
    # dp[i] 表示以 i 结尾的有效最长子串的长度.
    dp = [0] * len(s)

    res = 0
    for i in range(len(s)):
        if s[i] == "(" or i == 0:
            continue

        if s[i - 1] == "(":
            dp[i] = dp[i - 2] + 2
        else:
            if i - dp[i - 1] - 1 >= 0 and s[i - dp[i - 1] - 1] == "(":
                dp[i] = dp[i - 1] + 2
                if i - dp[i - 1] - 2 >= 0:
                    dp[i] += dp[i - dp[i - 1] - 2]

        res = max(res, dp[i])
    return res


s = ")()())"
print(longest_valid_parentheses(s))
