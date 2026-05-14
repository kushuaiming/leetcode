from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional


def revers_list(head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    curr = head
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    return prev


# 2026/05/14: 自己实现, 采用双重递归, 下次可以尝试 reverse_k_group 使用循环实现.
def reverse_k_group(head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if head is None:
        return None

    curr = head

    for i in range(k - 1):
        curr = curr.next
        if curr is None:
            return head
    next_group = curr.next
    curr.next = None
    reversed_list = revers_list(head)
    head.next = reverse_k_group(next_group, k)
    return reversed_list


head = [1, 2, 3, 4, 5]
k = 2
head = create_list_node(head)
print_list_node(reverse_k_group(head, k))
