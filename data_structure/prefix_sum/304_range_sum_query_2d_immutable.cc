#include <iostream>
#include <vector>

class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>>& matrix)
      : region_(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0)) {
    for (int i = 1; i <= static_cast<int>(matrix.size()); ++i) {
      for (int j = 1; j <= static_cast<int>(matrix[0].size()); ++j) {
        region_[i][j] = region_[i - 1][j] + region_[i][j - 1] -
                        region_[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int SumRegion(int row1, int col1, int row2, int col2) {
    return region_[row2 + 1][col2 + 1] - region_[row2 + 1][col1] -
           region_[row1][col2 + 1] + region_[row1][col1];
  }

 private:
  std::vector<std::vector<int>> region_;
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> matrix = {{3, 0, 1, 4, 2},
                                          {5, 6, 3, 2, 1},
                                          {1, 2, 0, 1, 5},
                                          {4, 1, 0, 1, 7},
                                          {1, 0, 3, 0, 5}};
  const int row1 = 2, col1 = 1, row2 = 4, col2 = 3;

  NumMatrix* obj = new NumMatrix(matrix);
  int param_1 = obj->SumRegion(row1, col1, row2, col2);
  std::cout << param_1 << std::endl;
  return 0;
}
