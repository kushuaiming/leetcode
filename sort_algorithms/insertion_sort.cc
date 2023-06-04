#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& nums) {
  for (int j = 1; j < nums.size(); ++j) {
    int key = nums[j];
    int i = j - 1;
    while (i >= 0 && nums[i] > key) {
      nums[i + 1] = nums[i];
      --i;
    }
    nums[i + 1] = key;
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  InsertionSort(nums);
  for (int num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}
