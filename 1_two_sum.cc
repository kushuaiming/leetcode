#include <iostream>
#include <vector>

std::vector<int> TwoSum(const std::vector<int> nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> results = TwoSum(nums, target);
  for (int result : results) {
    std::cout << result << std::endl;
  }
  return 0;
}
