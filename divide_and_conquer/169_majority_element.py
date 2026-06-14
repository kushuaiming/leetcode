from collections import defaultdict
from typing import List

# 2026/06/14: 自己写出哈希表版本.
def majority_element(nums: List[int]) -> int:
    num_counts = defaultdict(int)
    for num in nums:
        num_counts[num] += 1
        if num_counts[num] > len(nums) // 2:
            return num

# 2026/06/14: Boyer-Moore 投票算法, 直接抄答案.
# 不同的两个数同归于尽, 其他所有数都和众数不一样. 因为众数比其他加起来都要多, 即使最坏情况, 其他所有数都和众数同归于尽, 那最后剩下的也一定是众数.
def majority_element(nums: List[int]) -> int:
    candidate = -1
    count = 0

    for num in nums:
        if count == 0:
            candidate = num

        if num == candidate:
            count += 1
        else:
            count -= 1
    
    return candidate

nums = [2, 2, 1, 1, 1, 2, 2]
print(majority_element(nums))