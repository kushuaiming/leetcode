from typing import List
from collections import deque

# 2026/05/07: 直接抄答案.

# deque 的使用, 包括 append & pop.
def max_sliding_Window(nums: List[int], k: int) -> List[int]:
    dq = deque()

    res = []
    for i, num in enumerate(nums):
        if dq and dq[0] == i - k:
            dq.popleft()

        while dq and nums[dq[-1]] < num:
            dq.pop()

        dq.append(i)

        if i >= k - 1:
            res.append(nums[dq[0]])
    return res

nums = [1,3,-1,-3,5,3,6,7]
k = 3
print(max_sliding_Window(nums, k))
