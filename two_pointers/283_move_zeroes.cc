#include <vector>

// 2024/01/03: 直接看答案
void MoveZeroes(std::vector<int>& nums) {
  int prev = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == 0) {
      continue;
    }
    std::swap(nums[prev++], nums[i]);
  }
}
