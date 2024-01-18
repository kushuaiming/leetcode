#include <algorithm>
#include <vector>

// 2024/01/13: 直接看答案

void NextPermutation(std::vector<int>& nums) {
  // 1. 从后向前找到第一个nums[i] < nums[i + 1]的位置
  // 关键特征: [i+1, n)必然是下降排列.
  int i = nums.size() - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) {
    --i;
  }

  // 2. 从后向前找到第一个nums[j] > nums[i]的位置并交换.
  if (i >= 0) {
    int j = nums.size() - 1;
    while (j > i && nums[i] >= nums[j]) {
      --j;
    }
    std::swap(nums[i], nums[j]);
  }

  // 3. 重新排序i之后的数, 由于这些数一定是降序, 所以只需要reverse即可以得到升序.
  std::reverse(nums.begin() + i + 1, nums.end());
}
