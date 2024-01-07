#include <vector>

// 2024/01/07: 直接抄答案.
// 模拟, 用一个 visited 数组来判断是否访问过.
std::vector<int> SpiralOrder(const std::vector<std::vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  if (rows == 0 || cols == 0) {
    return {};
  }
  std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
  int total = rows * cols;
  std::vector<int> res(total);
  int direction_index = 0;
  int row = 0, col = 0;
  for (int i = 0; i < total; ++i) {
    res[i] = matrix[row][col];
    visited[row][col] = 1;
    int next_row = row + directions[direction_index][0];
    int next_col = col + directions[direction_index][1];
    if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols ||
        visited[next_row][next_col] == 1) {
      direction_index = (direction_index + 1) % 4;
    }
    row += directions[direction_index][0];
    col += directions[direction_index][1];
  }
  return res;
}

// 按层模拟. 记忆此方法, 因为其不需要额外的空间.
std::vector<int> SpiralOrder2(std::vector<std::vector<int>>& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return {};
  }
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> res;
  int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
  while (left <= right && top <= bottom) {
    for (int col = left; col <= right; ++col) {
      res.push_back(matrix[top][col]);
    }
    for (int row = top + 1; row <= bottom; ++row) {
      res.push_back(matrix[row][right]);
    }
    if (left < right && top < bottom) {
      for (int col = right - 1; col > left; --col) {
        res.push_back(matrix[bottom][col]);
      }
      for (int row = bottom; row > top; --row) {
        res.push_back(matrix[row][left]);
      }
    }
    ++left;
    --right;
    ++top;
    --bottom;
  }
  return res;
}
