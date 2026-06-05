from typing import List


def rob(nums: List[int]) -> int:
    dp = [0] * len(nums)

    for i in range(len(nums)):
        if i == 0:
            dp[i] = nums[i]
            continue
        if i == 1:
            dp[i] = max(nums[i], nums[i - 1])
            continue
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

    return dp[-1]


nums1 = [1, 2, 3, 1]
nums2 = [2, 7, 9, 3, 1]
nums3 = [0]
print(rob(nums3))
