#include <vector>

// 2024/01/18: 直接看答案. 做完55的基础上在来做此题.
// 维护当前能够到达的最大下标位置, 记为边界end.
// 从左到右遍历数组, 到达边界时, 更新边界并将跳跃次数增加 1.
int Jump(std::vector<int>& nums) {
  int max_pos = 0, n = nums.size(), end = 0, step = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (max_pos >= i) {
      max_pos = std::max(max_pos, i + nums[i]);
      if (i == end) {
        end = max_pos;
        ++step;
      }
    }
  }
  return step;
}