from collections import OrderedDict


# 2026/05/15: 直接抄答案, 用 Python 自带的 OrderedDict 实现.
class LRUCache(OrderedDict):  # LRU means Least Recently Used.

    def __init__(self, capacity: int):
        super().__init__()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self:
            return -1
        self.move_to_end(key)
        return self[key]

    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False)


# 2026/05/15: 直接抄答案, 哈希表 + 双向链表.
class DoubleLinkedNode:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache2:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0

        self.head = DoubleLinkedNode()
        self.tail = DoubleLinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head

        self.cache = {}

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key not in self.cache:
            node = DoubleLinkedNode(key, value)
            self.cache[key] = node
            self._add_to_head(node)
            self.size += 1
            if self.size > self.capacity:
                removed = self._remove_tail()
                self.cache.pop(removed.key)
                self.size -= 1
        else:
            node = self.cache[key]
            node.value = value
            self._move_to_head(node)

    def _add_to_head(self, node: DoubleLinkedNode) -> None:
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def _remove_node(self, node: DoubleLinkedNode) -> None:
        node.prev.next = node.next
        node.next.prev = node.prev

    def _move_to_head(self, node: DoubleLinkedNode) -> None:
        self._remove_node(node)
        self._add_to_head(node)

    def _remove_tail(self) -> None:
        node = self.tail.prev
        self._remove_node(node)
        return node


lru_cache = LRUCache2(2)
lru_cache.put(1, 1)  # 缓存是 {1=1}
lru_cache.put(2, 2)  # 缓存是 {1=1, 2=2}
lru_cache.get(1)  # 返回 1
lru_cache.put(3, 3)  # 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lru_cache.get(2)  # 返回 -1 (未找到)
lru_cache.put(4, 4)  # 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lru_cache.get(1)  # 返回 -1 (未找到)
lru_cache.get(3)  # 返回 3
lru_cache.get(4)  # 返回 4
