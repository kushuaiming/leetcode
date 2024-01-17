// 将数组从中间分开成左右两部分的时候, 一定有一部分的数组是有序的
#include <iostream>
#include <vector>

// 2024/01/11: 基本自己写出来了, 细节上看了一下答案, 具体见下面的注释.
// [left, right]
int Search(const std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (target == nums[mid]) {
      return mid;
    }
    // 判断哪部分的数组是有序的
    // 这里写的是和数组的第一个数(&最后一个数)比较.
    // 实际上也可以和nums[left](& nums[right])比较.
    if (nums[mid] >= nums.front()) {
      if (target >= nums.front() && target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (target > nums[mid] && target <= nums.back()) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  int target = 8;
  std::cout << Search(nums, target) << std::endl;
  return 0;
}
