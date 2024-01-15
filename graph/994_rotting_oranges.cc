#include <queue>
#include <vector>

// 2024/01/10: 看了一下答案的思路, 自己实现.
int OrangesRotting(std::vector<std::vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  std::queue<std::pair<int, int>> q;
  int fresh_oranges_count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 2) {
        q.push(std::make_pair(i, j));
        grid[i][j] = 0;
      } else if (grid[i][j] == 1) {
        ++fresh_oranges_count;
      }
    }
  }

  if (fresh_oranges_count == 0) {
    return 0;
  }

  std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int res = -1;
  while (!q.empty()) {
    int size = q.size();
    ++res;
    for (int i = 0; i < size; ++i) {
      std::pair<int, int> front = q.front();
      q.pop();
      for (const auto& direction : directions) {
        int new_row = front.first + direction[0];
        int new_col = front.second + direction[1];
        if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
            grid[new_row][new_col] == 1) {
          --fresh_oranges_count;
          q.push(std::make_pair(new_row, new_col));
          grid[new_row][new_col] = 0;
        }
      }
    }
  }
  return fresh_oranges_count == 0 ? res : -1;
}