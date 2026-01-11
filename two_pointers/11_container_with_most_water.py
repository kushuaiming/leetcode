from typing import List

# 2026/01/11: 自己写出来.
def max_area(height: List[int]) -> int:
    left = 0
    right = len(height) - 1
    result = 0

    while left < right:
        area = (right - left) * min(height[left], height[right])
        result = max(result, area)
        if (height[left] <= height[right]):
            left += 1
        else:
            right -= 1

    return result

height = [1,8,6,2,5,4,8,3,7]
print(max_area(height))
