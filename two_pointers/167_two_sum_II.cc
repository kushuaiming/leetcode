#include <gtest/gtest.h>

#include <vector>

std::vector<int> TwoSum(const std::vector<int>& numbers, int target) {
  if (numbers.size() < 2) {
    return {};
  }
  int left = 0;
  int right = numbers.size() - 1;
  while (left < right) {
    if (numbers[left] + numbers[right] == target) {
      return {left + 1, right + 1};
    } else if (numbers[left] + numbers[right] < target) {
      ++left;
    } else if (numbers[left] + numbers[right] > target) {
      --right;
    }
  }
  return {};
}

TEST(TwoSumTest, HandleNormal) {
  std::vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = {1, 2};
  EXPECT_EQ(TwoSum(numbers, target), result);
}
