#include <algorithm>
#include <vector>

// 2024/01/05: 直接看答案.

// 关键思路: 对于每个可以到达的位置x, 它使得x+1, x+2,..., x+nums[x]也可以到达.
// 依次遍历数组中的每一个位置并实时维护最远可以到达的位置.
// 如果最远可以到达的位置大于等于数组中的最后一个位置, 说明可以到达.
bool CanJump(std::vector<int>& nums) {
  int max_position = 0;
  const int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (i > max_position) {
      return false;
    }
    max_position = std::max(max_position, i + nums[i]);
    if (max_position >= n - 1) {
      return true;
    }
  }
  return false;
}
