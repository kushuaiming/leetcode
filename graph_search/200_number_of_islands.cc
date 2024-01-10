#include <queue>
#include <vector>

// 2024/01/10: 自己不看答案实现.
int NumIslands(const std::vector<std::vector<char>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  std::vector<std::vector<int>> is_visited(m, std::vector<int>(n, 0));
  int res = 0;
  std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1' && !is_visited[i][j]) {
        ++res;
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(i, j));
        while (!q.empty()) {
          std::pair<int, int> temp = q.front();
          q.pop();
          for (const auto& direction : directions) {
            int new_row = temp.first + direction[0];
            int new_col = temp.second + direction[1];
            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
                !is_visited[new_row][new_col] &&
                grid[new_row][new_col] == '1') {
              q.push(std::make_pair(new_row, new_col));
              is_visited[new_row][new_col] = 1;
            }
          }
        }
      }
    }
  }
  return res;
}