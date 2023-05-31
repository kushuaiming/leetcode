#include <iostream>
#include <vector>

int Partition(std::vector<int>& nums, int start, int end) {
  int pivot_element = nums[end];
  int i = start - 1;
  for (int j = start; j < end; ++j) {
    if (nums[j] <= pivot_element) {
      ++i;
      std::swap(nums[i], nums[j]);
    }
  }
  std::swap(nums[i+1], nums[end]);
  return i + 1;
}

// [start, end]
void QuickSort(std::vector<int>& nums, int start, int end) {
  if (start < end) {
    int p = Partition(nums, start, end);
    QuickSort(nums, start, p - 1);
    QuickSort(nums, p + 1, end);
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  QuickSort(nums, 0, nums.size() - 1);
  for (int num : nums) {
    std::cout << num << std::endl;
  }
}