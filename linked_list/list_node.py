from typing import Optional, List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def create_list_node(nums: List) -> Optional[ListNode]:
    dummy = ListNode(0)
    curr = dummy

    for num in nums:
        curr.next = ListNode(num)
        curr = curr.next

    return dummy.next


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


# 2026/05/13: 注意 .join 的用法.
def print_list_node(head: ListNode) -> None:
    vals = []
    curr = head
    while curr:
        vals.append(str(curr.val))
        curr = curr.next
    vals.append("N")
    print(" -> ".join(vals))
