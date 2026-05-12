from typing import List


# 2026/05/12: 自己写出答案
# 关键在与推导出旋转后的坐标, row = col, col = n - 1 - row.
def rotate(matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    if not matrix or not matrix[0]:
        return

    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - 1 - i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = temp


matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix2 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
rotate(matrix1)
rotate(matrix2)
print(matrix1)
print(matrix2)
