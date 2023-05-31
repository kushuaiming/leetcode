// 将数组从中间分开成左右两部分的时候, 一定有一部分的数组是有序的
#include <iostream>
#include <vector>

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
    if (nums[mid] >= nums[0]) {
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