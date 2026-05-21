from typing import List

# 2026/05/21: 自己写出来
results = []


def backtracking(nums: List[int], is_visited: List[int], result: List[int]) -> None:
    global results
    if len(nums) == len(result):
        results.append(result[:])  # 注意这里要添加一份潜拷贝
        return

    for i, num in enumerate(nums):
        if is_visited[i] == 0:
            result.append(num)
            is_visited[i] = 1
            backtracking(nums, is_visited, result)
            result.pop()
            is_visited[i] = 0


def permute(nums: List[int]) -> List[List[int]]:
    if not nums:
        return []

    is_visited = [0] * len(nums)
    result = []
    backtracking(nums, is_visited, result)
    return results


nums = [1, 2, 3]
print(permute(nums))
