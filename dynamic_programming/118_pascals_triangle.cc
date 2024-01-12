#include <vector>

// 2024/01/12: 自己实现

std::vector<std::vector<int>> Generate(int num_rows) {
  std::vector<std::vector<int>> results;
  for (int i = 0; i < num_rows; ++i) {
    std::vector<int> result(i + 1, 1);
    for (int j = 1; j < i; ++j) {
      result[j] = results[i - 1][j] + results[i - 1][j - 1];
    }
    results.push_back(result);
  }
  return results;
}
