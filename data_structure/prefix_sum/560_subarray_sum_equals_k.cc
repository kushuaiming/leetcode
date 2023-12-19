#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

// 此方法会超时.
int SubarraySum(std::vector<int>& nums, int k) {
  std::vector<int> sums(nums.size() + 1, 0);
  std::partial_sum(nums.begin(), nums.end(), sums.begin() + 1);
  int ans = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    for (int j = i; j < static_cast<int>(nums.size()); ++j) {
      if (sums[j + 1] - sums[i] == k) {
        ++ans;
      }
    }
  }
  return ans;
}

int SubarraySum2(std::vector<int>& nums, int k) {
  int count = 0, prefix_sum = 0;
  std::unordered_map<int, int> hash_map;
  hash_map[0] = 1;
  for (int num : nums) {
    prefix_sum += num;
    count += hash_map[prefix_sum - k];
    ++hash_map[prefix_sum];
  }
  return count;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 3};
  std::cout << SubarraySum2(nums, 3) << std::endl;
  return 0;
}
