#include <iostream>
#include <queue>
#include <vector>

enum class Color {
  kUnColored,
  kRed,
  kGreen,
};

// TODO: 用深度优先遍历进行实现
bool IsBipartite(const std::vector<std::vector<int>>& graph) {
  const int node_size = graph.size();
  std::vector<Color> color(node_size, Color::kUnColored);
  for (int i = 0; i < node_size; ++i) {
    if (color[i] == Color::kUnColored) {
      color[i] = Color::kRed;
      std::queue<int> q;
      q.push(i);
      while (!q.empty()) {
        const int front = q.front();
        q.pop();
        Color color_neighbor =
            (color[front] == Color::kRed) ? Color::kGreen : Color::kRed;
        for (int neighbor : graph[front]) {
          if (color[neighbor] == Color::kUnColored) {
            color[neighbor] = color_neighbor;
            q.push(neighbor);
          } else if (color[neighbor] != color_neighbor) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  std::cout << IsBipartite(graph) << std::endl;
  return 0;
}
