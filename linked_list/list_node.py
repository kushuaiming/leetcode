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


# 2026/05/13: 注意 .join 的用法.
def print_list_node(head: ListNode) -> None:
    vals = []
    curr = head
    while curr:
        vals.append(str(curr.val))
        curr = curr.next
    print(" -> ".join(vals))
