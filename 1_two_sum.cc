#include <gtest/gtest.h>

#include <iostream>
#include <vector>

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

TEST(TwoSumTest, TwoSumIndex) {
  std::vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  std::vector<int> result1 = {0, 1};
  EXPECT_EQ(TwoSum(nums1, target1), result1);

  std::vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  std::vector<int> result2 = {1, 2};
  EXPECT_EQ(TwoSum(nums2, target2), result2);

  std::vector<int> nums3 = {3, 3};
  int target3 = 6;
  std::vector<int> result3 = {0, 1};
  EXPECT_EQ(TwoSum(nums3, target3), result3);
}
