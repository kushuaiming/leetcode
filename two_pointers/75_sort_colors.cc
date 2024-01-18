#include <vector>

// 2024/01/18: 直接看答案, 选择此方法进行记忆.
void SortColors(std::vector<int>& nums) {
  int left = 0, right = nums.size() - 1;
  for (int i = 0; i <= right; ++i) {
    // 这里需要循环的原因是nums[right]是还没有遍历过的.
    while (i <= right && nums[i] == 2) {
      std::swap(nums[i], nums[right--]);
    }
    // 这里不需要循环的原因是nums[left]是已经遍历过的.
    if (nums[i] == 0) {
      std::swap(nums[i], nums[left++]);
    }
  }
}

// 2024/01/13: 自己实现双指针, 8min.
void SortColors(std::vector<int>& nums) {
  int left = -1, right = nums.size();
  for (int i = 0; i < nums.size() && i < right; ++i) {
    if (nums[i] == 0) {
      std::swap(nums[++left], nums[i]);
    } else if (nums[i] == 2) {
      std::swap(nums[--right], nums[i]);
      --i;
    }
  }
}
