from collections import defaultdict

# 2026/01/18 看答案写出
# 注意是不含重复字符, 所以只能用哈希表, 不能用含 26 个数的 List 表示.
# hash_table 的 value 有 0, 1, 2 三种状态, 所以必须用 int 类型, 不能用 bool 类型.
# 如果希望字典的 Value 有默认初始值, 要用 defaultdict.
# 区间采用左闭右闭, 即 [left, right], 所以当 left == right, result 计算结果为 1.

def length_of_longest_sub_string(s: str) -> int:
    hash_table = defaultdict(int)
    left = 0
    right = 0
    result = 0

    while right < len(s):
        hash_table[s[right]] += 1

        while (hash_table[s[right]] > 1 and left <= right):
            hash_table[s[left]] -= 1
            left += 1

        result = max(result, right - left + 1)
        right += 1

    return result

s = " "
print(length_of_longest_sub_string(s))
