from typing import List


# 2026/05/08: 直接看答案
# 使用 List 对左区间进行排序.
def merge(intervals: List[List[int]]) -> List[List[int]]:
    intervals.sort(key=lambda p: p[0])

    result = []
    for interval in intervals:
        if result and interval[0] <= result[-1][1]:
            result[-1][1] = max(result[-1][1], interval[1])
        else:
            result.append(interval)
    return result


intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
print(merge(intervals))
