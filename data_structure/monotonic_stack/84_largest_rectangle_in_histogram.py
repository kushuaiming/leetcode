from typing import List


# 2026/06/02: 直接抄答案:
# 1. 对于每个柱子, 找到左边第一个小于本柱子高度的位置.
# 2. 对于每个柱子, 找到右边第一个小于本注子高速的位置.
# 3. 对于每个柱子, 以其高度得到的最大矩形为 height * (right - left - 1)
def largest_rectangle_area(heights: List[int]) -> int:
    n = len(heights)

    mono_stack = []
    left = [-1] * n
    for i in range(n):
        while mono_stack and heights[mono_stack[-1]] >= heights[i]:
            mono_stack.pop()
        left[i] = mono_stack[-1] if mono_stack else -1
        mono_stack.append(i)

    mono_stack = []
    right = [n] * n
    for i in range(n - 1, -1, -1):
        while mono_stack and heights[mono_stack[-1]] >= heights[i]:
            mono_stack.pop()
        right[i] = mono_stack[-1] if mono_stack else n
        mono_stack.append(i)

    ans = max((right[i] - left[i] - 1) * heights[i] for i in range(n)) if n > 0 else 0
    return ans


heights = [2, 1, 5, 6, 2, 3]
print(largest_rectangle_area(heights))
