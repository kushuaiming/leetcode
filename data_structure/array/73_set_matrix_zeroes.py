from typing import List


# 2026/05/11: 自己写出了空间 O(mn) 的算法.
# 空间 O(1), 把矩阵的第 0 行和第 0 列用来存储是否要清零此行(列)的信息.
def set_zeroes(matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    if len(matrix) == 0 or len(matrix[0]) == 0:
        return

    row_to_be_clear = set()
    col_to_be_clear = set()
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
                row_to_be_clear.add(i)
                col_to_be_clear.add(j)

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if i in row_to_be_clear or j in col_to_be_clear:
                matrix[i][j] = 0


matrix1 = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
matrix2 = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
set_zeroes(matrix1)
set_zeroes(matrix2)
print(matrix1)
print(matrix2)
