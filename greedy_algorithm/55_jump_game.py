from typing import List


# 2026/06/04: 直接看答案
def can_jump(nums: List[int]) -> bool:
    max_position = 0
    for i in range(len(nums)):
        if i > max_position:
            return False
        max_position = max(max_position, i + nums[i])
        if max_position >= len(nums) - 1:
            return True
    return False


nums1 = [2, 3, 1, 1, 4]
nums2 = [3, 2, 1, 0, 4]
nums3 = [3, 0, 8, 2, 0, 0, 1]
print(can_jump(nums3))
