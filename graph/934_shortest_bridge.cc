#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// The problem is equivalent to calculate shortest length between two islands.
int ShortestBridge(std::vector<std::vector<int>>& grid) {
  const int n = grid.size();
  const std::vector<std::vector<int>> directions = {
      {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  std::vector<std::pair<int, int>> island;
  std::queue<std::pair<int, int>> queue;

  constexpr int kHasBeenVisited = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      // The Value of grid could be 1, 0, -1.
      if (grid[i][j] == 1) {
        // Find first island.
        queue.emplace(i, j);
        grid[i][j] = kHasBeenVisited;
        while (!queue.empty()) {
          const std::pair<int, int> queue_front = queue.front();
          queue.pop();
          island.emplace_back(queue_front.first, queue_front.second);
          for (const auto& direction : directions) {
            int next_x = queue_front.first + direction[0];
            int next_y = queue_front.second + direction[1];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n &&
                grid[next_x][next_y] == 1) {
              queue.emplace(next_x, next_y);
              grid[next_x][next_y] = kHasBeenVisited;
            }
          }
        }
        // Find shortest length to second island.
        for (auto&& island_point : island) {
          queue.emplace(island_point.first, island_point.second);
        }
        int step = 0;
        while (!queue.empty()) {
          // The queue's size is changing while bfs, so should store it in size.
          int size = queue.size();
          for (int i = 0; i < size; ++i) {
            const auto queue_front = queue.front();
            queue.pop();
            for (const auto& direction : directions) {
              int next_x = queue_front.first + direction[0];
              int next_y = queue_front.second + direction[1];
              if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
                if (grid[next_x][next_y] == 0) {
                  queue.emplace(next_x, next_y);
                  grid[next_x][next_y] = kHasBeenVisited;
                } else if (grid[next_x][next_y] == 1) {
                  return step;
                }
              }
            }
          }
          ++step;
        }
      }
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
  std::vector<std::vector<int>> grid2 = {{1, 1, 1, 1, 1},
                                         {1, 0, 0, 0, 1},
                                         {1, 0, 1, 0, 1},
                                         {1, 0, 0, 0, 1},
                                         {1, 1, 1, 1, 1}};
  std::cout << ShortestBridge(grid2) << std::endl;
  return 0;
}
