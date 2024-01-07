#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> MatrixProduct(
    const std::vector<std::vector<int>>& matrix1,
    const std::vector<std::vector<int>>& matrix2) {
  int m1 = matrix1.size();
  int n1 = matrix1[0].size();
  int m2 = matrix2.size();
  int n2 = matrix2[0].size();
  if (n1 != m2) {
    return {};
  }
  std::vector<std::vector<int>> res(m1, std::vector<int>(n2, 0));
  for (int i = 0; i < m1; ++i) {
    for (int j = 0; j < n1; ++j) {
      for (int k = 0; k < n2; ++k) {
        res[i][k] += matrix1[i][j] * matrix2[j][k];
      }
    }
  }
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> matrix1 = {{1, 1, 2}, {3, 4, 6}};
  std::vector<std::vector<int>> matrix2 = {{1, 4}, {5, 3}, {8, 7}};
  std::vector<std::vector<int>> res = MatrixProduct(matrix1, matrix2);
  return 0;
}
