from typing import List

# 2026/01/11 思路代码可以自己实现, 注意 List 中交换两个元素的写法.
def move_zeroes(nums: List[int]) -> None:
    i0 = 0
    for i in range(len(nums)):
        if nums[i]:
            nums[i0], nums[i] = nums[i], nums[i0]
            i0 += 1

nums = [0,1,0,3,12]
print(nums)
move_zeroes(nums)
print(nums)
