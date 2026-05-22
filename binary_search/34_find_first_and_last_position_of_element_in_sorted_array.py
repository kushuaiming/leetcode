from typing import List


# 2026/05/22: 直接看答案. [left, right]
def lower_bound(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return left


def upper_bound(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2
        if nums[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1

    return left


def search_range(nums: List[int], target: int) -> List[int]:
    lower = lower_bound(nums, target)
    upper = upper_bound(nums, target) - 1
    if (
        lower <= upper
        and upper < len(nums)
        and nums[lower] == target
        and nums[upper] == target
    ):
        return [lower, upper]
    else:
        return [-1, -1]


nums = [5, 7, 7, 8, 8, 10]
target = 8
