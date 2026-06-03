from typing import List
import heapq


def heapify(nums: List[int], i: int, heap_size: int) -> None:
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i
    if left < heap_size and nums[left] > nums[largest]:
        largest = left
    if right < heap_size and nums[right] > nums[largest]:
        largest = right
    if largest != i:
        nums[i], nums[largest] = nums[largest], nums[i]
        heapify(nums, largest, heap_size)


def heap_sort(nums: List[int]) -> None:
    heap_size = len(nums)
    # build max heap
    for i in range(heap_size // 2 - 1, -1, -1):
        heapify(nums, i, heap_size)
    # sort
    for i in range(heap_size - 1, 0, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heapify(nums, 0, i)


# 2026/06/02: 直接抄答案, 解析可以参考 heap_sort.
def find_kth_largest2(nums: List[int], k: int) -> int:
    heap_sort(nums)
    return nums[-k]


# 2026/06/02: 基于堆的实现, 但是出题人意图是要自己实现堆排序.
def find_kth_largest(nums: List[int], k: int) -> int:
    max_heap = []
    for num in nums:
        heapq.heappush(max_heap, -num)

    for _ in range(k - 1):
        heapq.heappop(max_heap)

    return -heapq.heappop(max_heap)


nums1 = [3, 2, 1, 5, 6, 4]
k1 = 2
nums2 = [3, 2, 3, 1, 2, 4, 5, 5, 6]
k2 = 4
print(find_kth_largest2(nums1, k1))
print(nums1)
