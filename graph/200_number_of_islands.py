from typing import List


# 2026/05/20: 自己不看答案实现.
def dfs(
    grid: List[List[str]], row: int, col: int, is_visited: List[List[bool]]
) -> None:
    m, n = len(grid), len(grid[0])
    if row < 0 or row >= m or col < 0 or col >= n:
        return

    if grid[row][col] == "0" or is_visited[row][col]:
        return

    is_visited[row][col] = True
    dfs(grid, row - 1, col, is_visited)
    dfs(grid, row + 1, col, is_visited)
    dfs(grid, row, col - 1, is_visited)
    dfs(grid, row, col + 1, is_visited)


def num_islands(grid: List[List[str]]) -> int:
    m, n = len(grid), len(grid[0])
    is_visited = [[False for _ in range(n)] for _ in range(m)]
    res = 0

    for i in range(m):
        for j in range(n):
            if grid[i][j] == "1" and not is_visited[i][j]:
                res += 1
                dfs(grid, i, j, is_visited)

    return res


grid = [
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "0"],
]
print(num_islands(grid))
