from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional


def merge_list(
    head1: Optional[ListNode], head2: Optional[ListNode]
) -> Optional[ListNode]:
    dummy = ListNode(0)
    prev = dummy
    while head1 is not None or head2 is not None:
        if head1 is None:
            prev.next = head2
            return dummy.next
        if head2 is None:
            prev.next = head1
            return dummy.next
        if head1.val < head2.val:
            prev.next = head1
            prev = head1
            head1 = head1.next
        else:
            prev.next = head2
            prev = head2
            head2 = head2.next
    return dummy.next


# 2026/05/15: 自己实现归并排序.
def sort_list(head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None or head.next is None:
        return head

    fast, slow = head, head
    while fast.next and fast.next.next:
        fast = fast.next.next
        slow = slow.next

    left_list_node = head
    right_list_node = slow.next
    slow.next = None
    left_list_node = sort_list(left_list_node)
    right_list_node = sort_list(right_list_node)
    return merge_list(left_list_node, right_list_node)


head = [4, 2, 1]
head = create_list_node(head)
print_list_node(sort_list(head))
