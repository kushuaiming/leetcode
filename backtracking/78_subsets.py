from typing import List


# 2026/05/21: 自己写出来.
def subsets(nums: List[int]) -> List[List[int]]:
    def backtracking(length: int, start: int) -> None:
        if len(result) == length:
            results.append(result[:])
            return

        for i in range(start, len(nums)):
            result.append(nums[i])
            backtracking(length, i + 1)
            result.pop()

    results = []
    result = []
    for i in range(len(nums) + 1):
        backtracking(i, 0)
    return results


nums = [1, 2, 3]
print(subsets(nums))
