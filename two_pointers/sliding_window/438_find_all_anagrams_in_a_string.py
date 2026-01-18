from typing import List
from collections import defaultdict

# 2026/01/18 自己写出来.
def find_anagrams(s: str, p: str) -> List[int]:
    hash_table = defaultdict(int)

    result = []
    if len(s) < len(p):
        return result

    for index in range(len(p)):
        hash_table[s[index]] += 1
        hash_table[p[index]] -= 1

    for start_index in range(len(s) - len(p) + 1):
        if all(val == 0 for val in hash_table.values()):
            result.append(start_index)

        hash_table[s[start_index]] -= 1
        if start_index != len(s) - len(p):
            hash_table[s[start_index + len(p)]] += 1

    return result

s = "baa"
p = "aa"

print(find_anagrams(s, p))
