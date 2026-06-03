import heapq


# 2026/06/03: 自己实现.
class MedianFinder:

    def __init__(self):
        self.left_max_priority_queue = []
        self.right_min_priority_queue = []

    def add_num(self, num: int) -> None:
        if not self.left_max_priority_queue:
            heapq.heappush(self.left_max_priority_queue, -num)
        else:
            if num <= -self.left_max_priority_queue[0]:
                heapq.heappush(self.left_max_priority_queue, -num)
            else:
                heapq.heappush(self.right_min_priority_queue, num)

        if len(self.left_max_priority_queue) < len(self.right_min_priority_queue):
            right_top = heapq.heappop(self.right_min_priority_queue)
            heapq.heappush(self.left_max_priority_queue, -right_top)
        elif len(self.left_max_priority_queue) > len(self.right_min_priority_queue) + 1:
            left_top = -heapq.heappop(self.left_max_priority_queue)
            heapq.heappush(self.right_min_priority_queue, left_top)

    def find_median(self) -> float:
        if len(self.left_max_priority_queue) > len(self.right_min_priority_queue):
            left = -self.left_max_priority_queue[0]
            return left
        else:
            left = -self.left_max_priority_queue[0]
            right = self.right_min_priority_queue[0]
            return (left + right) / 2


obj = MedianFinder()
obj.add_num(1)
obj.add_num(2)
print(obj.find_median())
obj.add_num(3)
print(obj.find_median())
