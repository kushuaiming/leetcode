from typing import List


# 2026/05/22: 自己写出答案
def search_matrix(matrix: List[List[int]], target: int) -> bool:
    if matrix is None or matrix[0] is None:
        return False

    m, n = len(matrix), len(matrix[0])
    i, j = 0, n - 1
    while i < m and j >= 0:
        if matrix[i][j] < target:
            i += 1
        elif matrix[i][j] > target:
            j -= 1
        else:
            return True

    return False


matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
target = 4
print(search_matrix(matrix, target))
