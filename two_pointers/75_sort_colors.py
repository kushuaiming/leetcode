from typing import List


# 2026/06/14: 双指针, 直接看答案.
def sort_colors(nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    left, right = 0, len(nums) - 1
    i = 0
    while i <= right:
        # 这里需要循环的原因是 nums[right] 是还没有遍历过的
        while i <= right and nums[i] == 2:
            nums[i], nums[right] = nums[right], nums[i]
            right -= 1

        # 这里不需要循环的原因是 nums[left] 是已经遍历过的
        if nums[i] == 0:
            nums[i], nums[left] = nums[left], nums[i]
            left += 1

        i += 1


nums = [2, 0, 2, 1, 1, 0]
sort_colors(nums)
print(nums)
