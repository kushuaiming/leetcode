from typing import List


# 2026/06/02 直接看答案 [left, right]
# 思路同 33, 只考虑有序的一边, 考虑完则排除这部分区间.
def find_min(nums: List[int]) -> int:
    left, right = 0, len(nums) - 1

    min_num = float("inf")
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] >= nums[0]:
            min_num = min(min_num, nums[left])
            left = mid + 1
        else:
            min_num = min(min_num, nums[mid])
            right = mid - 1
    return min_num


nums1 = [4, 5, 6, 7, 0, 1, 2]
nums2 = [5, 1, 2, 3, 4]
print(find_min(nums2))
