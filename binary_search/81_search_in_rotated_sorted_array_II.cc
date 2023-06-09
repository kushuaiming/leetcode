#include <iostream>
#include <vector>

// [left, right]
bool Search(std::vector<int> nums, int target) {
  if (nums.size() == 0) {
    return false;
  }
  int left = 0.0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      return true;
    }
    // 此时无法判断哪边是有序的
    if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
      ++left;
      --right;
    } else if (nums[mid] >= nums[left]) {
      if (target >= nums[left] && target <= nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (target >= nums[mid] && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 0, 1, 1, 1};
  int target = 0;
  std::cout << Search(nums, target) << std::endl;
  return 0;
}