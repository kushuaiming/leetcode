from typing import List


def bubble_sort(nums: List) -> None:
    for i in range(len(nums) - 1):
        for j in range(len(nums) - 1, i, -1):
            if nums[j] < nums[j - 1]:
                nums[j], nums[j - 1] = nums[j - 1], nums[j]


nums = [2, 7, 0, 44, 3, 5]
print(nums)
bubble_sort(nums)
print(nums)
