from typing import List

# 2026/06/14: 直接写出答案, 用时 5min.
# x ^ x = 0, x ^ 0 = x
def single_number(nums: List[int]) -> int:
    res = 0
    for num in nums:
        res = res ^ num
    return res


nums = [4, 1, 2, 1, 2]
print(single_number(nums))
