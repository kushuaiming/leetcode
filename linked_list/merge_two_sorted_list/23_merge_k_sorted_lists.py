from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional, List


# 2026/05/15: 自己实现分治合并.
def merge_two_lists(
    head1: Optional[ListNode], head2: Optional[ListNode]
) -> Optional[ListNode]:
    dummy_node = ListNode(0)
    prev = dummy_node
    while head1 is not None or head2 is not None:
        if head1 is None:
            prev.next = head2
            return dummy_node.next
        if head2 is None:
            prev.next = head1
            return dummy_node.next
        if head1.val < head2.val:
            prev.next = head1
            prev = head1
            head1 = head1.next
        else:
            prev.next = head2
            prev = head2
            head2 = head2.next
    return dummy_node.next


def merge_k_lists(lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    if len(lists) == 0:
        return None
    if len(lists) == 1:
        return lists[0]

    mid = len(lists) // 2
    left_list = merge_k_lists(lists[0:mid])
    right_list = merge_k_lists(lists[mid:])
    return merge_two_lists(left_list, right_list)


lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
lists_node = []
for list in lists:
    lists_node.append(create_list_node(list))
print_list_node(merge_k_lists(lists_node))
