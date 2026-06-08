from typing import List


# 2026/06/08: 自己实现. 这里不设置 dummy 更简单.
def length_of_lis(nums: List[int]) -> int:
    # dp[i] 表示以 i 结尾的最长升序长度.
    dp = [1] * len(nums)
    res = 0
    for i in range(len(nums)):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
        res = max(res, dp[i])
    return res


nums = [10, 9, 2, 5, 3, 7, 101, 18]
nums = [1, 3, 6, 7, 9, 4, 10, 5, 6]
print(length_of_lis(nums))
