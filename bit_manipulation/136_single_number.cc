#include <vector>

// 2024/01/13: 自己做出来, 2min

// 利用 x ^ x = 0, x ^ 0 = x的特点.
int SingleNumber(const std::vector<int>& nums) {
  int ans = 0;
  for (int num : nums) {
    ans ^= num;
  }
  return ans;
}
