#include <vector>

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
