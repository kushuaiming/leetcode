from typing import List


# 2026/06/08: 自己实现. 转化成 0-1 背包问题.
def can_partition(nums: List[int]) -> bool:
    total_value = sum(nums)
    if total_value % 2 != 0:
        return False

    target_value = total_value // 2
    # dp[i][j] 表示拿前 i 个数, 是否能正好组成 j.
    dp = [[False] * (target_value + 1) for _ in range(len(nums) + 1)]
    for i in range(len(nums) + 1):
        dp[i][0] = True
    for i in range(1, len(nums) + 1):
        num = nums[i - 1]
        for j in range(1, target_value + 1):
            if j >= num:
                dp[i][j] = dp[i - 1][j - num] or dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[-1][-1]


nums = [1, 5, 11, 5]
print(can_partition(nums))
