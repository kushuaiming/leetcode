#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::vector<std::string>> SolveNQueens(int n) {
  auto solutions = std::vector<std::vector<std::string>>();
  auto queens = std::vector<int>(n, -1);
  // 三个方向判断是否有其他皇后.
  auto columns = std::unordered_set<int>();
  auto diagonals1 = std::unordered_set<int>();
  auto diagonals2 = std::unordered_set<int>();
  Backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
  return solutions;
}

void Backtrack(std::vector<std::vector<std::string>> &solutions,
               std::vector<int> &queens, int n, int row,
               std::unordered_set<int> &columns,
               std::unordered_set<int> &diagonals1,
               std::unordered_set<int> &diagonals2) {
  if (row == n) {
    std::vector<std::string> board = GenerateBoard(queens, n);
    solutions.push_back(board);
  } else {
    for (int i = 0; i < n; i++) {
      if (columns.find(i) != columns.end()) {
        continue;
      }
      int diagonal1 = row - i; // 从左上到右下, 行下标列下标之差相等
      if (diagonals1.find(diagonal1) != diagonals1.end()) {
        continue;
      }
      int diagonal2 = row + i; // 从左下到右上, 行下标列下标之和相等
      if (diagonals2.find(diagonal2) != diagonals2.end()) {
        continue;
      }
      queens[row] = i;
      columns.insert(i);
      diagonals1.insert(diagonal1);
      diagonals2.insert(diagonal2);
      Backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
      queens[row] = -1;
      columns.erase(i);
      diagonals1.erase(diagonal1);
      diagonals2.erase(diagonal2);
    }
  }
}

std::vector<std::string> GenerateBoard(std::vector<int> &queens, int n) {
  auto board = std::vector<std::string>();
  for (int i = 0; i < n; i++) {
    std::string row = std::string(n, '.');
    row[queens[i]] = 'Q';
    board.push_back(row);
  }
  return board;
}
