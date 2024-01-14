#include <string>
#include <unordered_set>
#include <vector>

// 2024/01/14: 直接看答案

// 关键思路: 三个方向判断是否有其他皇后.
std::unordered_set<int> column;
std::unordered_set<int> diagonal1; // row + column为定值
std::unordered_set<int> diagonal2; // row - column为定值
int N;
std::vector<int> queens;
std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> SolveNQueens(int n) {
  N = n;
  queens.resize(N, -1);
  Backtrack(0);
  return res;
}

void Backtrack(int row) {
  if (row == N) {
    res.emplace_back(GenerateBoard());
    return;
  }
  for (int i = 0; i < N; ++i) {
    if (column.count(i) || diagonal1.count(row + i) ||
        diagonal2.count(row - i)) {
      continue;
    }
    column.insert(i);
    diagonal1.insert(row + i);
    diagonal2.insert(row - i);
    queens[row] = i;
    Backtrack(row + 1);
    column.erase(i);
    diagonal1.erase(row + i);
    diagonal2.erase(row - i);
    queens[row] = -1;
  }
}

std::vector<std::string> GenerateBoard() {
  std::vector<std::string> board;
  for (int i = 0; i < N; ++i) {
    std::string row = std::string(N, '.');
    row[queens[i]] = 'Q';
    board.push_back(row);
  }
  return board;
}
