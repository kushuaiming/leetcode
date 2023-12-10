#include <iostream>
#include <vector>

// 每次只考虑四个间隔90度的位置, 可以进行O(1)额外空间的旋转.
// 关键: 对于矩阵中第i行的第j个元素, 旋转后它出现在倒数第i列的第j个位置.
// 即对于矩阵中的元素matrix[row][col], 旋转后它的新位置为matrix[col][n-row-1].
void Rotate(std::vector<std::vector<int>>& matrix) {
  int temp = 0;
  const int n = matrix.size();
  for (int i = 0; i < (n + 1) / 2; ++i) {
    for (int j = i; j < n - i - 1; ++j) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[n - j - 1][i];
      matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
      matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
      matrix[j][n - i - 1] = temp;
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  Rotate(matrix);
  for (const auto& col : matrix) {
    for (int value : col) {
      std::cout << value << '\t';
    }
    std::cout << std::endl;
  }
  return 0;
}
