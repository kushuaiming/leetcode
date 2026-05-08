from typing import List


# 2026/05/08: 直接看答案.
# 要点是要能想到要 DP 做.
def max_sub_array(nums: List[int]) -> int:
    dp = [0] * len(nums)
    dp[0] = nums[0]
    for i in range(1, len(nums)):
        dp[i] = max(dp[i - 1], 0) + nums[i]
    return max(dp)


nums = [1]
print(max_sub_array(nums))
