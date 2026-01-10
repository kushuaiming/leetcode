from typing import List

# 2026/01/10 直接参考现有思路.
def longest_consecutive(nums: List[int]) -> int:
    if not nums:
        return 0

    nums_set = set(nums)
    longest_break = 0

    for num in nums_set: # 注意这里要使用 nums_set, 而不是原来的 nums
        if num - 1 not in nums_set:
            break_count = 1
            while num + 1 in nums_set:
                break_count += 1
                num += 1
            longest_break = max(longest_break, break_count)

    return longest_break
