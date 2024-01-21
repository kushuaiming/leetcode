// 二分查找
// 寻找left_index即为在数组中寻找第一个大于等于target的下标
// 寻找right_index即为在数组中寻找第一个大于target的下标, 然后将下标减1
// 在cpp标准库中有对应的lower_bound和upper_bound函数
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// 2024/01/11: 参考了一下答案, 不是完全自己写出来.
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
  return left;
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
  return left;
}

std::vector<int> SearchRange(std::vector<int>& nums, int target) {
  int left_index = lower_bound(nums, target);
  int right_index = upper_bound(nums, target) - 1;
  // 关键: 注意这里的判断顺序.
  if (left_index <= right_index && right_index < nums.size() &&
      nums[left_index] == target && nums[right_index] == target) {
    return std::vector<int>{left_index, right_index};
  }
  return std::vector<int>{-1, -1};
}

// 2024/01/21: 自己调用相关库函数实现了一遍.
// 注意一些特殊测试用例, 比如[[1]], 1; [[2, 2]], 2;
std::vector<int> SearchRange(std::vector<int>& nums, int target) {
  auto lower_bound = std::lower_bound(nums.begin(), nums.end(), target);
  auto upper_bound = std::upper_bound(nums.begin(), nums.end(), target);
  int left_index = std::distance(nums.begin(), lower_bound);
  int right_index = std::distance(nums.begin(), upper_bound) - 1;
  if (left_index <= right_index && right_index < nums.size() &&
      nums[left_index] == target && nums[right_index] == target) {
    return std::vector<int>{left_index, right_index};
  }
  return std::vector<int>{-1, -1};
}

int main(int argc, char* argv[]) {
  std::vector<int> nums{5, 7, 7, 8, 8, 10};
  std::vector<int> result = SearchRange(nums, 3);
  std::cout << result[0] << ' ' << result[1] << std::endl;
  return 0;
}
