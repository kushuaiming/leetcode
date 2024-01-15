#include <iostream>
#include <vector>

namespace {

constexpr int kHasBeenVisited = -1;

}  // namespace

int Dfs(std::vector<std::vector<int>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
      grid[i][j] != 1) {
    return 0;
  }
  grid[i][j] = kHasBeenVisited;
  return 1 + Dfs(grid, i - 1, j) + Dfs(grid, i + 1, j) + Dfs(grid, i, j - 1) +
         Dfs(grid, i, j + 1);
}

int MaxAreaOfIsland(std::vector<std::vector<int>>& grid) {
  if (grid.empty() || grid[0].empty()) {
    return 0;
  }
  int max_area = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 1) {
        max_area = std::max(max_area, Dfs(grid, i, j));
      }
    }
  }
  return max_area;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  std::vector<std::vector<int>> grid1 = {};
  std::cout << MaxAreaOfIsland(grid) << std::endl;
  return 0;
}
