from typing import List


# 2026/06/08: 前两天做过背包之后自己写出答案.
# 做复杂了, 可以直接用一维数组. dp[i] 表示前 i 个字符串能否用 word_dict 表示.
def word_break(s: str, word_dict: List[str]) -> bool:
    # dp[i] 表示 s[0, i) 能否用 word_dict 表示.

    dp = [False] * (len(s) + 1)
    dp[0] = True

    for i in range(1, len(s) + 1):
        for word in word_dict:
            if i >= len(word):
                if s[i - len(word) : i] == word:
                    dp[i] = dp[i] or dp[i - len(word)]
    return dp[-1]


s = "applepenapple"
word_dict = ["apple", "pen"]
s = "dogs"
word_dict = ["dog", "s", "gs"]
print(word_break(s, word_dict))
