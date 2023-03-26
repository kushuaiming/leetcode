#include <gtest/gtest.h>

#include <numeric>
#include <vector>

int Candy(const std::vector<int>& ratings) {
  int size = static_cast<int>(ratings.size());
  if (size < 2) {
    return size;
  }
  std::vector<int> nums(size, 1);
  for (int i = 1; i < size; ++i) {
    if (ratings[i] > ratings[i - 1]) {
      nums[i] = nums[i - 1] + 1;
    }
  }
  for (int i = size - 1; i > 0; --i) {
    if (ratings[i] < ratings[i - 1]) {
      nums[i - 1] = std::max(nums[i - 1], nums[i] + 1);
    }
  }
  return std::accumulate(nums.begin(), nums.end(), 0);
}

TEST(CandyTest, HandleNormal) {
  std::vector<int> ratings = {1, 0, 2};
  int candy_count = 5;
  EXPECT_EQ(Candy(ratings), candy_count);

  ratings = {1, 2, 2};
  candy_count = 4;
  EXPECT_EQ(Candy(ratings), candy_count);
}
