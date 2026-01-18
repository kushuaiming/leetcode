from typing import List

# 2026/01/18: 完全自己实现.
def trap(height: List[int]) -> int:
    left_max_height_list = []
    left_max_height = 0
    for h in height:
        left_max_height_list.append(left_max_height)
        left_max_height = max(h, left_max_height)

    right_max_height_list = []
    right_max_height = 0
    for h in reversed(height):
        right_max_height_list.append(right_max_height)
        right_max_height = max(h, right_max_height)
    right_max_height_list.reverse()

    result = 0
    for index in range(len(height)):
        result += max(min(left_max_height_list[index], right_max_height_list[index]) - height[index], 0)

    return result

height = [4,2,0,3,2,5]
print(trap(height))
