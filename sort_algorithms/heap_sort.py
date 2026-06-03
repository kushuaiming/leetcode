from typing import List


# 2026/06/03: 直接抄答案
# 通过让 nums[i] 的值在最大堆中逐级下降, 从而使下标 i 为根结点的子树重新遵循最大堆的性质.
def max_heapify(nums: List, i: int, heap_size: int) -> None:
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i
    if left < heap_size and nums[left] > nums[largest]:
        largest = left
    if right < heap_size and nums[right] > nums[largest]:
        largest = right
    if largest != i:
        nums[i], nums[largest] = nums[largest], nums[i]
        max_heapify(nums, largest, heap_size)


# 建堆, 对于所有的非叶子节点, 维护堆的性质.
# heap_size // 2, heap_size // 2 - 1, ..., heap_size - 1 都是叶子节点.
def build_max_heap(nums: List, heap_size: int) -> None:
    for i in range(heap_size // 2 - 1, -1, -1):
        max_heapify(nums, i, heap_size)


# 最大元素总在 nums[0] 中, 让它与 nums[i] 互换, 就可以让元素到正确位置.
def heap_sort(nums: List) -> None:
    heap_size = len(nums)
    build_max_heap(nums, heap_size)
    for i in range(len(nums) - 1, 0, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heap_size -= 1
        max_heapify(nums, 0, heap_size)


nums = [2, 7, 0, 44, 3, 5]
heap_sort(nums)
print(nums)
