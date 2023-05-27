#include <gtest/gtest.h>

#include <vector>

void Merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  if (n == 0) {
    return;
  }
  if (m == 0) {
    nums1 = nums2;
    return;
  }
  if (m + n != nums1.size()) {
    return;
  }
  int p1 = m - 1;
  int p2 = n - 1;
  int p = nums1.size() - 1;
  while (p > 0) {
    if (nums1[p1] > nums2[p2]) {
      nums1[p] = nums1[p1];
      --p1;
    } else if (nums1[p1] <= nums2[p2]) {
      nums1[p] = nums2[p2];
      --p2;
    }
    --p;
  }
}

TEST(MergeTest, HandleNormal) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  std::vector<int> nums2 = {2, 5, 6};
  int n = 3;
  std::vector<int> result = {1, 2, 2, 3, 5, 6};
  Merge(nums1, m, nums2, n);
  EXPECT_EQ(nums1, result);

  nums1 = {1};
  m = 1;
  nums2 = {};
  n = 0;
  result = {1};
  Merge(nums1, m, nums2, n);
  EXPECT_EQ(nums1, result);
}

TEST(MergeTest, HandleConer) {
  std::vector<int> nums1 = {1};
  int m = 1;
  std::vector<int> nums2 = {};
  int n = 0;
  std::vector<int> result = {1};
  Merge(nums1, m, nums2, n);
  EXPECT_EQ(nums1, result);

  nums1 = {0};
  m = 0;
  nums2 = {1};
  n = 1;
  result = {1};
  Merge(nums1, m, nums2, n);
  EXPECT_EQ(nums1, result);
}