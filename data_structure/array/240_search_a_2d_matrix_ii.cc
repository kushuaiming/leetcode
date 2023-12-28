#include <iostream>
#include <vector>

// 关键: 从右上角或者左下角开始查找
// 具体实现并不难.
bool SearchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
  const int m = matrix.size();
  const int n = matrix[0].size();
  int i = 0, j = n - 1;
  while (i < m && j >= 0) {
    if (matrix[i][j] < target) {
      ++i;
    } else if (matrix[i][j] > target) {
      --j;
    } else {
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15},
                                          {2, 5, 8, 12, 19},
                                          {3, 6, 9, 16, 22},
                                          {10, 13, 14, 17, 24},
                                          {18, 21, 23, 26, 30}};
  std::cout << SearchMatrix(matrix, 2) << std::endl;
  return 0;
}
