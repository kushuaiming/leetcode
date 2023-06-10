#include <iostream>
#include <vector>

int Partition(std::vector<int>& nums, int left, int right) {
  int pivot = nums[right];
  int i = left - 1;
  for (int j = left; j < right; ++j) {
    if (nums[j] <= pivot) {
      ++i;
      std::swap(nums[i], nums[j]);
    }
  }
  std::swap(nums[i + 1], nums[right]);
  return i + 1;
}

// [left, right]
int QuickSelect(std::vector<int>& nums, int left, int right, int k) {
  int p = Partition(nums, left, right);
  if (p == nums.size() - k) {
    return nums[p];
  }
  if (p > nums.size() - k) {
    return QuickSelect(nums, left, p - 1, k);
  } else {
    return QuickSelect(nums, p + 1, right, k);
  }
}

int FindKthLargest(std::vector<int>& nums, int k) {
  return QuickSelect(nums, 0, nums.size() - 1, k);
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  std::cout << FindKthLargest(nums, 2) << std::endl;
  return 0;
}
