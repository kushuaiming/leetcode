#include <iostream>
#include <vector>

// [0, first - 1]是已经填过数的, [first, length - 1]是待填数的
void Backtrack(std::vector<std::vector<int>>& result, std::vector<int>& output,
               int first, int length) {
  if (first == length) {
    result.push_back(output);
    return;
  }
  for (int i = first; i < length; ++i) {
    std::swap(output[i], output[first]);
    Backtrack(result, output, first + 1, length);
    std::swap(output[i], output[first]);
  }
}

std::vector<std::vector<int>> Permute(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  Backtrack(result, nums, 0, nums.size());
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2};
  std::vector<std::vector<int>> result = Permute(nums);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[0].size(); ++j) {
      std::cout << result[i][j] << '\t';
    }
    std::cout << std::endl;
  }
  return 0;
}
