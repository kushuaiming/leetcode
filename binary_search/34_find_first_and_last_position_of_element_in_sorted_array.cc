// 二分查找
// 寻找left_index即为在数组中寻找第一个大于等于target的下标
// 寻找right_index即为在数组中寻找第一个大于target的下标, 然后将下标减1
// 在cpp标准库中有对应的lower_bound和upper_bound函数
#include <iostream>
#include <limits>
#include <vector>

// [left, right]
int lower_bound(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] >= target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int upper_bound(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left - 1;
}

// [left, right)
int lower_bound2(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] >= target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int upper_bound2(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left - 1;
}

std::vector<int> SearchRange(std::vector<int>& nums, int target) {
  int left_index = lower_bound(nums, target);
  int right_index = upper_bound(nums, target);
  if (left_index <= right_index && right_index < nums.size() &&
      nums[left_index] == target && nums[right_index] == target) {
    return std::vector<int>{left_index, right_index};
  }
  return std::vector<int>{-1, -1};
}

int main(int argc, char* argv[]) {
  std::vector<int> nums{5, 7, 7, 8, 8, 10};
  std::vector<int> result = SearchRange(nums, 8);
  std::cout << result[0] << ' ' << result[1] << std::endl;
  return 0;
}
