#include <algorithm>
#include <iostream>
#include <vector>

void Selection(std::vector<int>& nums) {
  for (int i = 0; i < nums.size() - 1; ++i) {
    int min_index = i;
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] < nums[min_index]) {
        min_index = j;
      }
    }
    std::swap(nums[i], nums[min_index]);
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  std::cout << "Selection sort: " << std::endl;
  Selection(nums);
  for (int num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}