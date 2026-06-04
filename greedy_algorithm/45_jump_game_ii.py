from typing import List


# 2026/06/04: 直接看答案
def jump(nums: List[int]) -> int:
    max_position, end, step = 0, 0, 0
    for i in range(len(nums) - 1):
        if i <= max_position:
            max_position = max(max_position, i + nums[i])
            if i == end:
                end = max_position
                step = step + 1
    return step


nums1 = [2, 3, 1, 1, 4]
nums2 = [2, 3, 0, 1, 4]
print(jump(nums1))
