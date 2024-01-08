#include <vector>

// 2024/01/07: 不看答案自己写出来.

bool SearchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  int m = matrix.size();
  int n = matrix[0].size();
  int left = 0, right = m * n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int i = mid / n;
    int j = mid % n;
    if (matrix[i][j] < target) {
      left = mid + 1;
    } else if (matrix[i][j] > target) {
      right = mid - 1;
    } else {
      return true;
    }
  }
  return false;
}