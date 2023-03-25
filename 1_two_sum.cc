#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> TwoSum(const std::vector<int> nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {};
}

std::vector<int> TwoSumV2(const std::vector<int> nums, int target) {
  std::unordered_map<int, int> hash_table;
  for (int i = 0; i < nums.size(); ++i) {
    auto it = hash_table.find(target - nums[i]);
    if (it != hash_table.end()) {
      return {i, hash_table[target - nums[i]]};
    }
    hash_table[nums[i]] = i;
  }
  return {};
}

TEST(TwoSumTest, HandleNormalInput) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = {0, 1};
  EXPECT_EQ(TwoSum(nums, target), result);

  nums = {3, 2, 4};
  target = 6;
  result = {1, 2};
  EXPECT_EQ(TwoSum(nums, target), result);

  nums = {3, 3};
  target = 6;
  result = {0, 1};
  EXPECT_EQ(TwoSum(nums, target), result);
}

TEST(TwoSumV2Test, HandleNormalInput) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = {0, 1};
  EXPECT_EQ(TwoSumV2(nums, target), result);

  nums = {3, 2, 4};
  target = 6;
  result = {1, 2};
  EXPECT_EQ(TwoSumV2(nums, target), result);

  nums = {3, 3};
  target = 6;
  result = {0, 1};
  EXPECT_EQ(TwoSumV2(nums, target), result);
}
