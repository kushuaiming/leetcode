#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> UpdateMatrix(
    const std::vector<std::vector<int>>& mat) {
  std::vector<std::vector<int>> dp;
  const int m = mat.size();
  const int n = mat[0].size();
  std::vector<std::vector<int>> distance(m, std::vector<int>(n, 0));
  std::vector<std::vector<int>> is_visited(m, std::vector<int>(n, 0));
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 0) {
        queue.push(std::make_pair(i, j));
        is_visited[i][j] = 1;
      }
    }
  }

  const std::vector<std::vector<int>> directions = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  while (!queue.empty()) {
    const std::pair<int, int> position = queue.front();
    queue.pop();
    for (const auto& direction : directions) {
      const int i = position.first + direction[0];
      const int j = position.second + direction[1];
      if (i >= 0 && i < m && j >= 0 && j < n && is_visited[i][j] == 0) {
        distance[i][j] = distance[position.first][position.second] + 1;
        is_visited[i][j] = 1;
        queue.push(std::make_pair(i, j));
      }
    }
  }

  return distance;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  std::vector<std::vector<int>> distance = UpdateMatrix(mat);
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[0].size(); ++j) {
      std::cout << distance[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
