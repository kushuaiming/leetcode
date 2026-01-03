from typing import List

# 2026/01/03: 思路 OK, 实现上要注意 enumerate 的用法. 存储的时候 num 作为 key, index 作为 value.
def two_sum(nums: List[int], target: int) -> List[int]:
      hash_map = {}
      for i, num in enumerate(nums):
          if target - num in hash_map:
              return [i, hash_map[target - num]]
          else:
              hash_map[num] = i

nums = [2, 7, 11, 15]
target = 9
print(two_sum(None, nums, target))  # Output: [1, 0]
