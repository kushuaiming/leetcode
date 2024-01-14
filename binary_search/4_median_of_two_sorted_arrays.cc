#include <vector>

// 2024/01/14: 直接看答案, 边界条件较多, 需要细心.

// 注意这里的k是指第k个数(假设下标从1开始).
int GetKthElement(const std::vector<int>& nums1, const std::vector<int>& nums2,
                  int k) {
  // 主要思路: 要找到第 k (k>=1) 小的元素, 那么就取 pivot1 = nums1[k/2-1] 和
  // pivot2 = nums2[k/2-1] 进行比较. 这里的 "/" 表示整除.
  // nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
  // nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
  // 取 pivot = min(pivot1, pivot2), 两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个 
  // 这样 pivot 本身最大也只能是第 k-1 小的元素
  // 如果 pivot = pivot1, 那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素.
  // 把这些元素全部"删除", 剩下的作为新的 nums1 数组
  // 如果 pivot = pivot2, 那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素.
  // 把这些元素全部 "删除", 剩下的作为新的 nums2 数组
  // 由于我们 "删除" 了一些元素(这些元素都比第 k 小的元素要小), 因此需要修改 k 的值，减去删除的数的个数.

  int m = nums1.size();
  int n = nums2.size();
  int index1 = 0, index2 = 0;

  while (true) {
    // 边界情况
    if (index1 == m) {
      return nums2[index2 + k - 1];
    }
    if (index2 == n) {
      return nums1[index1 + k - 1];
    }
    if (k == 1) {
      return std::min(nums1[index1], nums2[index2]);
    }

    // 正常情况
    int new_index1 = std::min(index1 + k / 2 - 1, m - 1);
    int new_index2 = std::min(index2 + k / 2 - 1, n - 1);
    int pivot1 = nums1[new_index1];
    int pivot2 = nums2[new_index2];
    if (pivot1 <= pivot2) {
      k -= new_index1 - index1 + 1;
      index1 = new_index1 + 1;
    } else {
      k -= new_index2 - index2 + 1;
      index2 = new_index2 + 1;
    }
  }
}

double FindMedianSortedArrays(std::vector<int>& nums1,
                              std::vector<int>& nums2) {
  int total_length = nums1.size() + nums2.size();
  if (total_length % 2 == 1) {
    return GetKthElement(nums1, nums2, (total_length + 1) / 2);
  } else {
    return (GetKthElement(nums1, nums2, total_length / 2) +
            GetKthElement(nums1, nums2, total_length / 2 + 1)) /
           2.0;
  }
}

// 2024/01/14: 自己实现了合并数组之后计算中位数的版本.
double FindMedianSortedArrays(std::vector<int>& nums1,
                              std::vector<int>& nums2) {
  int m = nums1.size();
  int n = nums2.size();
  std::vector<int> nums;
  int pointer1 = 0, pointer2 = 0;
  while (pointer1 < m && pointer2 < n) {
    if (nums1[pointer1] < nums2[pointer2]) {
      nums.push_back(nums1[pointer1++]);
    } else {
      nums.push_back(nums2[pointer2++]);
    }
  }
  if (pointer1 == m) {
    while (pointer2 < n) {
      nums.push_back(nums2[pointer2++]);
    }
  }
  if (pointer2 == n) {
    while (pointer1 < m) {
      nums.push_back(nums1[pointer1++]);
    }
  }

  if ((m + n) % 2 == 0) {
    return (nums[(m + n) / 2] + nums[(m + n) / 2 - 1]) / 2.0;
  } else {
    return nums[(m + n) / 2];
  }
}
