from typing import Optional
from typing import List
from list_node import ListNode


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


def has_cycle2(head: Optional[ListNode]) -> bool:
    if head is None or head.next is None:
        return False
    fast = head.next
    slow = head
    while fast != slow:
        if fast.next is None or fast.next.next is None:
            return False
        fast = fast.next.next
        slow = slow.next
    return True


def create_cycle_list(nums: List, pos: int) -> Optional[ListNode]:
    dummy = ListNode(0)
    curr = dummy
    cycle_node = None
    for i in range(len(nums)):
        curr.next = ListNode(nums[i])
        curr = curr.next
        if i == pos:
            cycle_node = curr
        if i == len(nums) - 1:
            curr.next = cycle_node

    return dummy.next


head = [3, 2, 0, -4]
pos = 1
head = create_cycle_list(head, pos)
print(has_cycle2(head))
