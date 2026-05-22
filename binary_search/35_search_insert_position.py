from typing import List


# 2026/05/22: 自己写出来.
def search_insert(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1  # [left, right]

    while left <= right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            return mid

    return left


# 补充左闭右开的版本, [left, right)
def search_insert2(nums: List[int], target: int) -> int:
    left, right = 0, len(nums)

    while left < right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid
        else:
            return mid

    return left


nums = [1, 3, 5, 6]
target = 4
print(search_insert2(nums, target))
