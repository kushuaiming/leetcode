from typing import List


# 2026/05/11: 自己写出答案, 但是这种方式空间复杂度为 O(n), 不满足需求.
def first_missing_positive(nums: List[int]) -> int:
    nums_set = set(nums)
    nums_set.add(0)
    res_list = []
    for num in nums_set:
        if num >= 0 and num + 1 not in nums_set:
            res_list.append(num + 1)
    return min(res_list)


# 2026/05/11: 直接抄答案.
# 1. 对于一个长度为 N 的数组, 其中没有出现的最小正整数只能在[1, N + 1]中.
# 2. 使用原始数组作为哈希表以实现空间复杂度为常数级别.
def first_missing_positive2(nums: List[int]) -> int:
    length = len(nums)
    for i in range(length):
        if nums[i] < 1 or nums[i] > length:
            nums[i] = length + 1

    for num in nums:
        abs_num = abs(num)
        if abs_num >= 1 and abs_num <= length:
            nums[abs_num - 1] = -abs(nums[abs_num - 1])

    for i in range(length):
        if nums[i] > 0:
            return i + 1

    return length + 1


nums1 = [1, 2, 0]
nums2 = [3, 4, -1, 1]
nums3 = [7, 8, 9, 11, 12]

print(first_missing_positive2(nums1))
print(first_missing_positive2(nums2))
print(first_missing_positive2(nums3))
