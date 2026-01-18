from typing import List

# 2026/01/18 自己实现, 注意去重的处理.
def three_sum(nums: List[int]) -> List[List[int]]:
    nums.sort()

    results = []

    for first in range(len(nums)):
        second = first + 1
        third = len(nums) - 1
        result = []
        if first > 0 and nums[first] == nums[first - 1]:
            continue
        while second < third:
            if second > first + 1 and nums[second] == nums[second - 1]:
                second += 1
                continue
            if third < len(nums) - 1 and nums[third] == nums[third + 1]:
                third -= 1
                continue
            if nums[second] + nums[third] + nums[first] < 0:
                second += 1
            elif nums[second] + nums[third] + nums[first] > 0:
                third -= 1
            else:
                result = [nums[first], nums[second], nums[third]]
                results.append(result)
                second += 1

    return results

nums = [0,1,1]
print(three_sum(nums))
