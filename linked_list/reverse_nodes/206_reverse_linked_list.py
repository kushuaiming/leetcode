import sys, os

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from typing import Optional
from list_node import ListNode, create_list_node, print_list_node


# 2026/05/13: 自己写出来.
def reverse_list(head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    curr = head
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    return prev


# 2026/05/13: 递归, 直接看答案.
def reverse_list2(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next:
        return head

    new_head = reverse_list2(head.next)
    head.next.next = head
    head.next = None
    return new_head


nums = [1, 2, 3, 4, 5]
head = create_list_node(nums)
print_list_node(head)
head = reverse_list2(head)
print_list_node(head)
