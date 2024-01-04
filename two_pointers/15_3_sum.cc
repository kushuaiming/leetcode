#include <algorithm>
#include <vector>

// 2024/01/03: 看官方题解的思路之后自己实现.

// 关键思路要能想到排序.
// 注意去重的处理, 在每一层不能有相同的数字.
std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums) {
  int n = nums.size();
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> res;
  for (int first = 0; first < n; ++first) {
    if (first != 0 && nums[first] == nums[first - 1]) {
      continue;
    }
    int third = n - 1;
    for (int second = first + 1; second < n; ++second) {
      if (second != first + 1 && nums[second] == nums[second - 1]) {
        continue;
      }
      while (third > second && nums[first] + nums[second] + nums[third] > 0) {
        --third;
      }
      if (third > second && nums[first] + nums[second] + nums[third] == 0) {
        res.push_back({nums[first], nums[second], nums[third]});
      }
    }
  }
  return res;
}
