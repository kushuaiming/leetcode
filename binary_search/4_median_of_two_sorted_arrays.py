from typing import List


# 2026/06/01: 直接抄答案
def get_kth_element(nums1: List[int], nums2: List[int], k: int) -> int:
    m, n = len(nums1), len(nums2)
    index1, index2 = 0, 0

    while True:
        if index1 == m:
            return nums2[index2 + k - 1]
        if index2 == n:
            return nums1[index1 + k - 1]
        if k == 1:
            return min(nums1[index1], nums2[index2])

        new_index1 = min(index1 + k // 2 - 1, m - 1)
        new_index2 = min(index2 + k // 2 - 1, n - 1)
        pivot1 = nums1[new_index1]
        pivot2 = nums2[new_index2]
        if pivot1 <= pivot2:
            k -= new_index1 - index1 + 1
            index1 = new_index1 + 1
        else:
            k -= new_index2 - index2 + 1
            index2 = new_index2 + 1


# 2026/06/02: 直接抄答案
def find_median_sorted_arrays(nums1: List[int], nums2: List[int]) -> float:
    total_length = len(nums1) + len(nums2)
    if total_length % 2 == 1:
        return get_kth_element(nums1, nums2, (total_length + 1) // 2)
    else:
        return (
            get_kth_element(nums1, nums2, total_length // 2)
            + get_kth_element(nums1, nums2, total_length // 2 + 1)
        ) / 2


nums1 = [1, 2]
nums2 = [3, 4]
print(find_median_sorted_arrays(nums1, nums2))
