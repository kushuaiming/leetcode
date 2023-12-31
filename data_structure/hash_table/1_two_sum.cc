#include <unordered_map>
#include <vector>

// 2023/12/31 可以自己写出来
std::vector<int> TwoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hash;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (hash.find(target - nums[i]) != hash.end()) {
      return {i, hash[target - nums[i]]};
    }
    hash[nums[i]] = i; // 关键是key-value的设计.
  }
  return {};
}
