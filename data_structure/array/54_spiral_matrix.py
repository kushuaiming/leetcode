from typing import List


# 2026/05/12: 直接抄答案
# 按层模拟, 通过直接定义上下左右使得代码更清晰.
# 难点在与想清楚在模拟的时候要遍历哪些元素.
def spiral_order(matrix: List[List[int]]) -> List[int]:
    if not matrix or not matrix[0]:
        return list()

    res = []
    m, n = len(matrix), len(matrix[0])
    left, right = 0, n - 1
    top, bottom = 0, m - 1

    while left <= right and top <= bottom:
        for col in range(left, right + 1):
            res.append(matrix[top][col])
        for row in range(top + 1, bottom + 1):
            res.append(matrix[row][right])
        if left < right and top < bottom:
            for col in range(right - 1, left - 1, -1):
                res.append(matrix[bottom][col])
            for row in range(bottom - 1, top, -1):
                res.append(matrix[row][left])
        left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1

    return res


matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix2 = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
print(spiral_order(matrix1))
print(spiral_order(matrix2))
