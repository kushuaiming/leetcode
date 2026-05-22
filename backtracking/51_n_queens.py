from typing import List


# 2026/05/22: 直接抄答案
def solve_n_queens(n: int) -> List[List[str]]:
    column = set()
    main_diagonal = set()  # 要用 set, 同时要能发现主对角线 i - j 是相同的.
    anti_diagonal = set()  # 要用 set, 同时要能发现副对角线 i + j 是相同的.

    results = []
    result = [-1 for _ in range(n)]

    def createboard(result: List[int]) -> List[List[int]]:
        board = []
        for i in range(n):
            row = ["."] * n
            row[result[i]] = "Q"
            board.append("".join(row))  # 注意这里的实现方式.
        return board

    def backtracking(i: int) -> None:
        nonlocal result

        if i == n:
            results.append(createboard(result[:]))
            return

        for j in range(n):
            if j in column or i - j in main_diagonal or i + j in anti_diagonal:
                continue
            result[i] = j
            column.add(j)
            main_diagonal.add(i - j)
            anti_diagonal.add(i + j)
            backtracking(i + 1)
            result[i] = -1
            column.remove(j)
            main_diagonal.remove(i - j)
            anti_diagonal.remove(i + j)

    backtracking(0)
    return results


n = 4
print(solve_n_queens(n))
