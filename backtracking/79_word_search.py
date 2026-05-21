from typing import List


def exist(board: List[List[str]], word: str) -> bool:
    is_exist = False
    if not board or not board[0]:
        return is_exist

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    m, n = len(board), len(board[0])

    result = []
    is_visited = [[0 for i in range(n)] for i in range(m)]
    word_index = 0

    def backtracking(row: int, col: int) -> None:
        nonlocal is_exist, word_index, is_visited
        if row < 0 or row >= m or col < 0 or col >= n or word_index >= len(word):
            return

        if is_visited[row][col]:
            return

        if board[row][col] != word[word_index]:
            return

        if word_index == len(word) - 1:
            is_exist = True
            return

        is_visited[row][col] = 1
        result.append(board[row][col])
        for direction in directions:
            row = row + direction[0]
            col = col + direction[1]
            word_index += 1
            backtracking(row, col)
            word_index -= 1
            row = row - direction[0]
            col = col - direction[1]
        is_visited[row][col] = 0
        result.pop()

    for i in range(m):
        for j in range(n):
            backtracking(i, j)

    return is_exist


board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "ABCCED"
print(exist(board, word))
