#include <iostream>
#include <queue>
#include <vector>

enum class Color {
  kUnColored,
  kRed,
  kGreen,
};

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

// 2024/01/03: 自己实现.
// 深度优先遍历
void Dfs(std::vector<std::vector<int>>& graph, int curr,
         std::vector<Color>& colors, bool& is_valid) {
  for (int adjacent : graph[curr]) {
    if (colors[adjacent] == Color::kUnColored) {
      colors[adjacent] =
          colors[curr] == Color::kRed ? Color::kGreen : Color::kRed;
      Dfs(graph, adjacent, colors, is_valid);
    } else if (colors[adjacent] == colors[curr]) {
      is_valid = false;
      return;
    }
  }
}

bool IsBipartite2(std::vector<std::vector<int>>& graph) {
  std::vector<Color> colors(graph.size(), Color::kUnColored);
  bool is_valid = true;
  for (int i = 0; i < graph.size(); ++i) {
    if (colors[i] == Color::kUnColored) {
      colors[i] == Color::kRed;
      Dfs(graph, i, colors, is_valid);
    }
  }
  return is_valid;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  std::cout << IsBipartite(graph) << std::endl;
  return 0;
}
