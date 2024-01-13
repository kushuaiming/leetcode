#include <vector>

// 2024/01/13: 直接看答案, 二分法.
int FindDuplicate(std::vector<int>& nums) {
  int n = nums.size();
  int left = 1, right = n - 1, res = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    // 关键步骤: 寻找第一个count[i] > i的数.
    int count = 0;
    for (int i = 0; i < n; ++i) {
      count += nums[i] <= mid;
    }
    if (count > mid) {
      right = mid - 1;
      res = mid;
    } else {
      left = mid + 1;
    }
  }
  return res;
}

// 2024/01/13: 直接看答案, 二进制的方法.
int FindDuplicate2(std::vector<int>& nums) {
  int n = nums.size(), ans = 0;
  // 确定二进制下最高位是多少
  int bit_max = 31;
  while (!((n - 1) >> bit_max)) {
    bit_max -= 1;
  }
  for (int bit = 0; bit <= bit_max; ++bit) {
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] & (1 << bit)) {
        x += 1;
      }
      if (i >= 1 && (i & (1 << bit))) {
        y += 1;
      }
    }
    if (x > y) {
      ans |= 1 << bit;
    }
  }
  return ans;
}

// 2024/01/13: 直接看答案, 快慢指针.
int FindDuplicate3(std::vector<int>& nums) {
  int slow = 0, fast = 0;
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  slow = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
