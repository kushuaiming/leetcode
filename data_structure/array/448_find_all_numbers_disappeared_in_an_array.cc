#include <cmath>
#include <vector>

// 利用数组建立n个桶, 把所有重复出现的位值进行标记, 然后再遍历一遍数组,
// 即可找到没有出现过的数字
// 1. 可以将该数标记为负数, 遍历的时候取绝对值.
// 2. 也可将该数加n, 遍历的时候取模
std::vector<int> FindDisappearedNumbers(std::vector<int>& nums) {
  for (int num : nums) {
    const int pos = std::abs(num) - 1;
    if (nums[pos] > 0) {
      nums[pos] = -nums[pos];
    }
  }
  std::vector<int> result;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      result.emplace_back(i + 1);
    }
  }
  return result;
}