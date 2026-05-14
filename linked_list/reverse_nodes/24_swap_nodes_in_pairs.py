from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional


# 2026/05/14: 自己实现递归.
def swap_pairs(head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None or head.next is None:
        return head

    prev = head
    curr = prev.next
    next = curr.next
    curr.next = prev
    prev.next = swap_pairs(next)
    return curr


head = [1]
head = create_list_node(head)
print_list_node(swap_pairs(head))
