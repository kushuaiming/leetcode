from typing import List


# 2026/06/08: 直接看答案.
def max_product(nums: List[int]) -> int:
    min_dp, max_dp = list(nums), list(nums)

    for i in range(1, len(nums)):
        min_dp[i] = min(min_dp[i - 1] * nums[i], max_dp[i - 1] * nums[i], nums[i])
        max_dp[i] = max(min_dp[i - 1] * nums[i], max_dp[i - 1] * nums[i], nums[i])
    return max(max_dp)


nums = [2, 3, -2, 4]
print(max_product(nums))
