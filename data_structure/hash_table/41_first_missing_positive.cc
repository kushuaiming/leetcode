#include <cmath>
#include <vector>

// 2024/01/14: 直接抄答案.
// 对于一个长度为N的数组, 其中没有出现的最小正整数只能在[1, N + 1]中.
// 使用原始数组作为哈希表.
int FirstMissingPositive(std::vector<int>& nums) {
  int n = nums.size();
  // 1. 把不在[1, n]的所有的数都修改成大于n的数, 比如n+1.
  for (int i = 0; i < n; ++i) {
    if (nums[i] < 1 || nums[i] > n) {
      nums[i] = n + 1;
    }
  }

  // 2.1 遍历数组中的每个数x, 由于其可能被打上了标记, 所以取绝对值.
  // 2.2 判断x是否在[1, n]内, 如果在, 给相应的位置打上标记.
  for (int i = 0; i < n; ++i) {
    int x = std::abs(nums[i]);
    if (x >= 1 && x <= n) {
      if (nums[x - 1] > 0) {
        nums[x - 1] = -nums[x - 1];
      }
    }
  }

  // 3. 如果每一个数都是负数, 那么答案是n+1, 否则是i+1.
  int res = n + 1;
  for (int i = 0; i < n; ++i) {
    if (nums[i] > 0) {
      return i + 1;
    }
  }
  return res;
}

// 2024/01/14: 直接抄答案, 采用置换的方法.(本质上也是标记)
int FirstMissingPositive2(std::vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
      std::swap(nums[nums[i] - 1], nums[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (nums[i] != i + 1) {
      return i + 1;
    }
  }
  return n + 1;
}
