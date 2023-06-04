#include <algorithm>
#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& nums) {
  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = nums.size() - 1; j > i; --j) {
      if (nums[j] < nums[j - 1]) {
        std::swap(nums[j], nums[j - 1]);
      }
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  std::cout << "Begin bubble sort: " << std::endl;
  BubbleSort(nums);
  for (int num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}