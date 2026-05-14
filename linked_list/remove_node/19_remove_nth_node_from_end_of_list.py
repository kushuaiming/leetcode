from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional


# 2026/05/14: 不看答案自己实现, 计算链表长度.
def remove_nth_from_end(head: Optional[ListNode], n: int) -> Optional[ListNode]:
    count = 0
    curr = head
    while curr:
        count += 1
        curr = curr.next
    del_pos = count - n

    curr = head
    prev = ListNode(0)
    count = 0
    while curr:
        if count == del_pos:
            prev.next = curr.next
            if count == 0:
                return prev.next
            else:
                return head
        prev = curr
        curr = curr.next
        count += 1


# 2026/05/14: 看答案思路后自己实现, 利用栈的先进后出的效果.
def remove_nth_from_end2(head: Optional[ListNode], n: int) -> Optional[ListNode]:
    stack = []
    dummy = ListNode(0, head)
    curr = dummy
    while curr:
        stack.append(curr)
        curr = curr.next

    for i in range(n):
        stack.pop()

    prev = stack[-1]
    prev.next = prev.next.next
    return dummy.next


head = [1, 2, 3, 4, 5]
n = 5
head = create_list_node(head)
print_list_node(remove_nth_from_end2(head, n))
