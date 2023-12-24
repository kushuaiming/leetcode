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
