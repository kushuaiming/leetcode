#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// BFS
std::vector<std::vector<int>> UpdateMatrix(
    const std::vector<std::vector<int>>& mat) {
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

// Dynamic Programming
// 这里的 i 和 j 的循环条件和状态转移方程容易写错
// 不可以一个循环计算完成, 必须循环4遍
std::vector<std::vector<int>> UpdateMatrix2(
    const std::vector<std::vector<int>>& mat) {
  const int m = mat.size();
  const int n = mat[0].size();
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT32_MAX / 2));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 0) {
        dp[i][j] = 0;
      }
    }
  }
  // 只有水平向左和竖直向上移动
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - 1 >= 0) {
        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
      }
      if (j - 1 >= 0) {
        dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }
  // 只有水平向左和竖直向下移动
  for (int i = m - 1; i >= 0; --i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < m) {
        dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + 1);
      }
      if (j - 1 >= 0) {
        dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }
  // 只有水平向右和竖直向上移动
  for (int i = 0; i < m; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      if (i - 1 >= 0) {
        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
      }
      if (j + 1 < n) {
        dp[i][j] = std::min(dp[i][j], dp[i][j + 1] + 1);
      }
    }
  }
  // 只有水平向右和竖直向下移动
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (i + 1 < m) {
        dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + 1);
      }
      if (j + 1 < n) {
        dp[i][j] = std::min(dp[i][j], dp[i][j + 1] + 1);
      }
    }
  }
  return dp;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  std::vector<std::vector<int>> distance = UpdateMatrix2(mat);
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[0].size(); ++j) {
      std::cout << distance[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
