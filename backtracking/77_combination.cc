#include <iostream>
#include <vector>

void Backtrack(std::vector<std::vector<int>>& result, std::vector<int>& output,
               int cur, int n, int k) {
  if (output.size() == k) {
    result.push_back(output);
    return;
  }

  if (cur > n) {
    return;
  }

  // Consider current position.
  output.push_back(cur);
  Backtrack(result, output, cur + 1, n, k);
  output.pop_back();
  // Ignore current position.
  Backtrack(result, output, cur + 1, n, k);
}

std::vector<std::vector<int>> Combine(int n, int k) {
  std::vector<std::vector<int>> result;
  std::vector<int> output;
  Backtrack(result, output, 1, n, k);
  return result;
}

int main(int argc, char* argv[]) {
  int n = 4;
  int k = 2;
  std::vector<std::vector<int>> result = Combine(n, k);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[0].size(); ++j) {
      std::cout << result[i][j] << '\t';
    }
    std::cout << std::endl;
  }
  return 0;
}
