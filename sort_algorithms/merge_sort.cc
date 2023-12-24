#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// Merge [left, mid] and [mid + 1, right]
void Merge(std::vector<int>& nums, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  std::vector<int> left_nums;
  std::vector<int> right_nums;
  left_nums.reserve(n1 + 1);
  right_nums.reserve(n2 + 1);
  for (int i = 0; i < n1; ++i) {
    left_nums[i] = nums[left + i];
  }
  for (int i = 0; i < n2; ++i) {
    right_nums[i] = nums[mid + i + 1];
  }
  left_nums[n1] = INT_MAX;
  right_nums[n2] = INT_MAX;
  int i = 0;
  int j = 0;
  for (int k = left; k <= right; ++k) {
    if (left_nums[i] <= right_nums[j]) {
      nums[k] = left_nums[i];
      ++i;
    } else {
      nums[k] = right_nums[j];
      ++j;
    }
  }
}

// [left, right]
void MergeSort(std::vector<int>& nums, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    Merge(nums, left, mid, right);
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  MergeSort(nums, 0, nums.size() - 1);
  for (int num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}
