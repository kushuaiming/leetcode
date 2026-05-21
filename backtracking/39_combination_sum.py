from typing import List


# 2026/05/21: 自己写出答案
def combination_sum(candidates: List[int], target: int) -> List[List[int]]:
    results = []
    result = []
    cummulate_sum = 0

    def backtracking(start: int) -> None:
        nonlocal cummulate_sum
        if cummulate_sum == target:
            results.append(result[:])
            return
        elif cummulate_sum > target:
            return

        for i in range(start, len(candidates)):
            cummulate_sum += candidates[i]
            result.append(candidates[i])
            backtracking(i)
            cummulate_sum -= candidates[i]
            result.pop()

    backtracking(0)
    return results


candidates = [2, 3, 5]
target = 8
print(combination_sum(candidates, target))
