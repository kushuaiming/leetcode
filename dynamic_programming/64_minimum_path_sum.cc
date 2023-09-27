#include <iostream>
#include <vector>

int MinPathSum(const std::vector<std::vector<int>>& grid) {
  const int m = grid.size();
  const int n = grid[0].size();
  std::vector<int> dp(n, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) {
        dp[j] = grid[i][j];
      } else if (i == 0) {
        dp[j] = grid[i][j] + dp[j - 1];
      } else if (j == 0) {
        dp[j] = grid[i][j] + dp[j];
      } else {
        dp[j] = grid[i][j] + std::min(dp[j - 1], dp[j]);
      }
    }
  }
  return dp[n - 1];
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  std::cout << MinPathSum(grid) << std::endl;
  return 0;
}
