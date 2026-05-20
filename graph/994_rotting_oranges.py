from collections import deque
from typing import List

# 2026/05/20: 自己实现, 除了使用 fresh_count 来判断是否都腐烂了.
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def oranges_rotting(grid: List[List[int]]) -> int:
    if len(grid) == 0 or len(grid[0]) == 0:
        return -1
    m, n = len(grid), len(grid[0])

    rotted_oranges = deque()
    # is_visited = [[False for _ in range(n)] for _ in range(m)]
    fresh_count = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 2:
                rotted_oranges.append((i, j))
            elif grid[i][j] == 1:
                fresh_count += 1

    if fresh_count == 0:
        return 0

    res = -1
    while len(rotted_oranges) > 0:
        res += 1
        for _ in range(len(rotted_oranges)):
            rotted_orange = rotted_oranges.popleft()
            for direction in directions:
                row = rotted_orange[0] + direction[0]
                col = rotted_orange[1] + direction[1]
                if (
                    row >= 0
                    and row < m
                    and col >= 0
                    and col < n
                    and grid[row][col] == 1
                ):
                    grid[row][col] = 2
                    rotted_oranges.append((row, col))
                    fresh_count -= 1
    return res if fresh_count == 0 else -1


grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]  # res = 4
grid2 = [[0, 0, 1, 0], [0, 1, 2, 1], [1, 2, 1, 0], [0, 1, 0, 0]]  # res = 1
print(oranges_rotting(grid))
print(oranges_rotting(grid2))
