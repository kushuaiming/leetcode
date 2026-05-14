from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional


# 2026/05/14: 不看答案自己写出来了.
def add_two_numbers(
    l1: Optional[ListNode], l2: Optional[ListNode]
) -> Optional[ListNode]:
    dummy = ListNode(0)
    prev = dummy
    carry = 0
    while l1 and l2:
        num = (l1.val + l2.val + carry) % 10
        carry = (l1.val + l2.val + carry) // 10
        prev.next = ListNode(num)
        prev = prev.next
        l1 = l1.next
        l2 = l2.next

    while l1:
        num = (l1.val + carry) % 10
        carry = (l1.val + carry) // 10
        prev.next = ListNode(num)
        prev = prev.next
        l1 = l1.next

    while l2:
        num = (l2.val + carry) % 10
        carry = (l2.val + carry) // 10
        prev.next = ListNode(num)
        prev = prev.next
        l2 = l2.next

    if carry == 1:
        prev.next = ListNode(carry)

    return dummy.next


l1 = [9, 9, 9, 9, 9, 9, 9]
l2 = [9, 9, 9, 9]
l1 = create_list_node(l1)
l2 = create_list_node(l2)
print_list_node(l1)
print_list_node(l2)
print_list_node(add_two_numbers(l1, l2))
