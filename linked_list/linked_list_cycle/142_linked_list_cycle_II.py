from linked_list.list_node import ListNode, create_cycle_list
from typing import Optional


# 2026/05/14: 自己写出哈希表的解法.
def detect_cycle(head: Optional[ListNode]) -> Optional[ListNode]:
    hash_map = set()
    curr = head
    while curr:
        if curr in hash_map:
            return curr
        hash_map.add(curr)
        curr = curr.next

    return None


# 2026/05/14: 快慢指针, 看思路实现. 这是典型的思路难推理, 但是实现简单.
def detect_cycle2(head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None:
        return None
    fast, slow = head, head
    while True:
        if fast.next is None or fast.next.next is None:
            return None
        fast = fast.next.next
        slow = slow.next
        if fast == slow:
            break

    fast = head
    while fast != slow:
        fast = fast.next
        slow = slow.next

    return slow


head = [3, 2, 0, -4]
pos = 1
head = create_cycle_list(head, pos)
print(detect_cycle2(head).val)
