#include <algorithm>
#include <unordered_map>
#include <vector>

// 2024/01/13: 自己写出哈希表法, 5min
int MajorityElement1(std::vector<int>& nums) {
  std::unordered_map<int, int> hash_table;
  int n = nums.size() / 2;
  for (int num : nums) {
    ++hash_table[num];
    if (hash_table[num] > n) {
      return num;
    }
  }
  return -1;
}

// 排序.
int MajorityElement2(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  return nums[nums.size() / 2];
}

// 随机化
int MajorityElement3(std::vector<int>& nums) {
  while (true) {
    int candidate = nums[rand() % nums.size()];
    int count = 0;
    for (int num : nums)
      if (num == candidate) ++count;
    if (count > nums.size() / 2) return candidate;
  }
  return -1;
}

// 分治.
int CountInRange(std::vector<int>& nums, int target, int low, int high) {
  int count = 0;
  for (int i = low; i <= high; ++i)
    if (nums[i] == target) ++count;
  return count;
}

int MajorityElementRec(std::vector<int>& nums, int low, int high) {
  if (low == high) return nums[low];
  int mid = (low + high) / 2;
  int left_majority = MajorityElementRec(nums, low, mid);
  int right_majority = MajorityElementRec(nums, mid + 1, high);
  if (CountInRange(nums, left_majority, low, high) > (high - low + 1) / 2)
    return left_majority;
  if (CountInRange(nums, right_majority, low, high) > (high - low + 1) / 2)
    return right_majority;
  return -1;
}

int MajorityElement4(std::vector<int>& nums) {
  return MajorityElementRec(nums, 0, nums.size() - 1);
}

// Boyer-Moore 投票
// 如果候选人不是 maj 则 maj  会和其他非候选人一起反对 会反对候选人, 所以候选人一定会下台(maj==0时发生换届选举)
// 如果候选人是 maj, 则 maj 会支持自己, 其他候选人会反对, 同样因为 maj 票数超过一半, 所以 maj 一定会成功当选.

// 投票算法: 可以看成水果消消乐, 不同的水果两两消失. 最后剩余的一定是超过半数的水果.
int MajorityElement5(std::vector<int>& nums) {
  int candidate = -1;
  int count = 0;
  for (int num : nums) {
    if (num == candidate)
      ++count;
    else if (--count < 0) {
      candidate = num;
      count = 1;
    }
  }
  return candidate;
}
