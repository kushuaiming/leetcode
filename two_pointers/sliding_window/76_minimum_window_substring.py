# 2026/05/08: 直接抄答案
# 要点:
# 1. Python 3.10 值后的版本可以用 Counter, 无需自己 Dict 实现.
# 2. 区间为 [left, right], 即左右都是闭区间.


from collections import Counter


def min_window(s: str, t: str) -> str:
    count_s = Counter()
    count_t = Counter(t)

    ans_left, ans_right = -1, len(s)
    left, right = 0, 0
    while right < len(s):
        count_s[s[right]] += 1
        while count_s >= count_t:
            if ans_right - ans_left > right - left:
                ans_right = right
                ans_left = left
            count_s[s[left]] -= 1
            left += 1
        right += 1

    return "" if ans_left < 0 else s[ans_left : ans_right + 1]


s = "ADOBECODEBANC"
t = "ABC"
print(min_window(s, t))
