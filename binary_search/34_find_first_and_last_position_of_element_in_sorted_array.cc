// 二分查找
// 寻找left_index即为在数组中寻找第一个大于等于target的下标
// 寻找right_index即为在数组中寻找第一个大于target的下标, 然后将下标减1
#include <iostream>
#include <limits>
#include <vector>

// [left, right]
int BinarySearch(std::vector<int>& nums, int target, bool lower) {
  int left = 0;
  int right = static_cast<int>(nums.size()) - 1;
  int answer = static_cast<int>(nums.size());
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] > target || (lower && nums[mid] >= target)) {
      right = mid - 1;
      answer = mid;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}

// [left, right)
int BinarySearchV2(std::vector<int>& nums, int target, bool lower) {
  int left = 0;
  int right = nums.size();
  int answer = static_cast<int>(nums.size());
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] > target || (lower && nums[mid] >= target)) {
      answer = mid;
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}

std::vector<int> SearchRange(std::vector<int>& nums, int target) {
  int left_index = BinarySearch(nums, target, true);
  int right_index = BinarySearch(nums, target, false) - 1;
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
