from typing import Optional
from linked_list.list_node import ListNode, create_cycle_list


# 2026/05/13: 自己写出答案, 时间空间复杂度都是 O(n).
def has_cycle(head: Optional[ListNode]) -> bool:
    hash_map = set()
    curr = head
    while curr is not None:
        if curr in hash_map:
            return True
        hash_map.add(curr)
        curr = curr.next

    return False


# 2026/05/13: 快慢指针, 直接抄答案.
def has_cycle2(head: Optional[ListNode]) -> bool:
    if head is None or head.next is None:
        return False
    # 避免初始状态两指针相等, 这是 Floyd's Cycle Detection 的标准实现方式.
    # 也可以将初始 Fast & Slow 状态设置成相等, 使用 while True + break 的方式进行判断.
    fast = head.next
    slow = head
    while fast != slow:
        if fast.next is None or fast.next.next is None:
            return False
        fast = fast.next.next
        slow = slow.next
    return True


head = [3, 2, 0, -4]
pos = 1
head = create_cycle_list(head, pos)
print(has_cycle2(head))
