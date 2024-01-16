#include <unordered_map>
#include <vector>

// 需要和面试官确认以下几个问题:
// 1. 是否可以修改数组.
// 2. 有几个重复的数字, 是否需要返回所有重复的数字.
// 3. 是否要求空间复杂度为O(1).
// 4. 是否要求时间复杂度为O(n).

// 2024/01/16: 自己实现哈希表法
int FindDuplicate(std::vector<int>& nums) {
  std::unordered_map<int, int> hash_table;
  for (int num : nums) {
    ++hash_table[num];
    if (hash_table[num] >= 2) {
      return num;
    }
  }
  return -1;
}

// 2024/01/13: 直接看答案, 二分法.
// 不能找出所有的重复的数字.
int FindDuplicate1(std::vector<int>& nums) {
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

// 2024/01/16: 直接看答案, 重新整理快慢指针的思路.
// 2024/01/13: 直接看答案, 快慢指针.
// 只能找到其中一个重复的数字.
// reference: https://leetcode.cn/problems/find-the-duplicate-number/solutions/58841/287xun-zhao-zhong-fu-shu-by-kirsche/
int FindDuplicate3(std::vector<int>& nums) {
  int slow = 0, fast = 0;
  while (1) {
    slow = nums[slow];
    fast = nums[nums[fast]];
    if (slow == fast) {
      break;
    }
  }
  slow = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

// 2024/01/16: 交换节点的方法, 适用于允许修改原数组的情况
int FindDuplicate4(std::vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    while (nums[i] - 1 != i) {
      if (nums[i] == nums[nums[i] - 1]) {
        return nums[i];
      }
      std::swap(nums[i], nums[nums[i] - 1]);
    }
  }
  return -1;
}
