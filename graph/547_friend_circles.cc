#include <iostream>
#include <vector>

void Dfs(std::vector<std::vector<int>>& is_connected,
         std::vector<int>& is_visited, int city_counts, int i) {
  if (is_visited[i] == 1) {
    return;
  }
  is_visited[i] = 1;
  for (int j = 0; j < city_counts; ++j) {
    if (j == i) {
      continue;
    }
    if (is_connected[i][j] == 1) {
      Dfs(is_connected, is_visited, city_counts, j);
    }
  }
}

int FindCircleNum(std::vector<std::vector<int>>& is_connected) {
  if (is_connected.empty()) {
    return 0;
  }
  const int city_counts = is_connected.size();
  int province_counts = 0;
  std::vector<int> is_visited(city_counts, 0);
  for (int i = 0; i < city_counts; ++i) {
    if (is_visited[i] == 0) {
      ++province_counts;
      Dfs(is_connected, is_visited, city_counts, i);
    }
  }
  return province_counts;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> is_connected = {
      {1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  std::cout << FindCircleNum(is_connected) << std::endl;
  return 0;
}
