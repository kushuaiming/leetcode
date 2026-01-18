from collections import defaultdict
from typing import List

# 2026/01/18 [left, right), 此方法会超时
def subarray_sum(nums: List[int], k: int) -> int:
    sum_list = [0]
    acculate_sum = 0
    for num in nums:
        acculate_sum += num
        sum_list.append(acculate_sum)

    res = 0
    for left in range(len(nums)):
        for right in range(left + 1, len(nums) + 1):
            interval_sum = sum_list[right] - sum_list[left]
            if interval_sum == k:
                res += 1

    return res

# 2026/01/18 抄答案, 思路分析见 .cc 文件.
def subarray_sum2(nums: List[int], k: int) -> int:
    result = 0
    prefix_sum = 0
    hash_table = defaultdict(int)

    hash_table[0] = 1

    for num in nums:
        prefix_sum += num
        result += hash_table[prefix_sum - k]
        hash_table[prefix_sum] += 1

    return result

nums = [1,2,3]
k = 3
print(subarray_sum2(nums, k))
