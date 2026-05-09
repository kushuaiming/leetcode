from typing import List
import math

# 2026/05/09: 直接看答案.


# 交换两个元素 a, b = b, a
# 下标为 i 的元素放在 (i + k) mod n 的位置.
# 需要遍历的次数为 gcd(n, k) GCD(Greatest Common Divisor)最大公约数.
def rotate1(nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    rotate_count = math.gcd(len(nums), k)
    for i in range(rotate_count):
        curr = i
        next = -1
        temp = nums[i]
        while next != i:
            next = (curr + k) % len(nums)
            temp, nums[next] = nums[next], temp
            curr = next


def reverse(nums: List[int], start: int, end: int):
    while start < end:
        nums[start], nums[end] = nums[end], nums[start]
        start += 1
        end -= 1


# 数组翻转法, 先将所有元素翻转, 然后把前 k 个元素翻转, 再把右边剩余的元素翻转.
def rotate2(nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    k %= len(nums)  # 必须, 用于处理 k > len(nums) 的情况
    reverse(nums, 0, len(nums) - 1)
    reverse(nums, 0, k - 1)
    reverse(nums, k, len(nums) - 1)


nums1 = [1, 2, 3, 4, 5, 6, 7]
rotate1(nums1, 3)
print(nums1)

nums2 = [-1, -100, 3, 99]
rotate2(nums2, 2)
print(nums2)
