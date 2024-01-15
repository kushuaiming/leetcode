#include <iostream>
#include <vector>

namespace {

const std::vector<std::vector<int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

}  // namespace

void Dfs(std::vector<std::vector<int>>& heights,
         std::vector<std::vector<bool>>& is_visited, int i, int j) {
  if (is_visited[i][j]) {
    return;
  }
  is_visited[i][j] = true;
  for (const auto& direction : directions) {
    if (i + direction[0] >= 0 && i + direction[0] < heights.size() &&
        j + direction[1] >= 0 && j + direction[1] < heights[0].size()) {
      if (heights[i + direction[0]][j + direction[1]] >= heights[i][j]) {
        Dfs(heights, is_visited, i + direction[0], j + direction[1]);
      }
    }
  }
}

// 需要逆向思维, 从两个大洋向上流, 这样只要对矩形四条边进行搜索.
std::vector<std::vector<int>> PacificAtlantic(
    std::vector<std::vector<int>>& heights) {
  std::vector<std::vector<int>> results;
  std::vector<std::vector<bool>> is_pacific(
      heights.size(), std::vector<bool>(heights[0].size(), false));
  std::vector<std::vector<bool>> is_atlantic(
      heights.size(), std::vector<bool>(heights[0].size(), false));
  for (int i = 0; i < heights.size(); ++i) {
    Dfs(heights, is_pacific, i, 0);
  }
  for (int j = 0; j < heights[0].size(); ++j) {
    Dfs(heights, is_pacific, 0, j);
  }
  for (int i = 0; i < heights.size(); ++i) {
    Dfs(heights, is_atlantic, i, heights[0].size() - 1);
  }
  for (int j = 0; j < heights[0].size(); ++j) {
    Dfs(heights, is_atlantic, heights.size() - 1, j);
  }

  for (int i = 0; i < heights.size(); ++i) {
    for (int j = 0; j < heights[0].size(); ++j) {
      if (is_pacific[i][j] && is_atlantic[i][j]) {
        results.push_back({i, j});
      }
    }
  }
  return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> heights = {{1, 2, 2, 3, 5},
                                           {3, 2, 3, 4, 4},
                                           {2, 4, 5, 3, 1},
                                           {6, 7, 1, 4, 5},
                                           {5, 1, 1, 2, 4}};
  std::vector<std::vector<int>> results = PacificAtlantic(heights);
  for (const auto& result : results) {
    std::cout << result[0] << '\t' << result[1] << std::endl;
  }

  return 0;
}
