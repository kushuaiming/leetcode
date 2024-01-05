#include <vector>

// 2024/01/05: 自己写出了空间O(mn)的算法. 看答案思路写出了O(1)空间的算法.

// 利用第0行和第0列存储0的信息.
void SetZeroes(std::vector<std::vector<int>>& matrix) {
  bool flag_col0 = false;
  bool flag_row0 = false;
  for (int i = 0; i < matrix.size(); ++i) {
    if (matrix[i][0] == 0) {
      flag_col0 = true;
    }
  }
  for (int j = 0; j < matrix[0].size(); ++j) {
    if (matrix[0][j] == 0) {
      flag_row0 = true;
    }
  }
  for (int i = 1; i < matrix.size(); ++i) {
    for (int j = 1; j < matrix[0].size(); ++j) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  for (int i = 1; i < matrix.size(); ++i) {
    for (int j = 1; j < matrix[0].size(); ++j) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }
  if (flag_col0) {
    for (int i = 0; i < matrix.size(); ++i) {
      matrix[i][0] = 0;
    }
  }
  if (flag_row0) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      matrix[0][j] = 0;
    }
  }
}
