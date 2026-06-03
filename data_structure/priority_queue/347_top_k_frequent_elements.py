from collections import Counter
from typing import List
import heapq


# 2026/06/02: 直接抄答案.
def topk_frequent(nums: List[int], k: int) -> List[int]:
    counts = Counter(nums)

    heap = []
    for key, val in counts.items():
        if len(heap) < k:
            heapq.heappush(heap, (val, key))
        else:
            if val > heap[0][0]:
                heapq.heappop(heap)
                heapq.heappush(heap, (val, key))

    return [key for _, key in heap]


nums = [1, 2, 1, 2, 1, 2, 3, 1, 3, 2]
k = 2
print(topk_frequent(nums, k))
