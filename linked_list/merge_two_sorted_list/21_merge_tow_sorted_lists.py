from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional


# 2026/05/14: 自己写出来
def merge_two_lists(
    list1: Optional[ListNode], list2: Optional[ListNode]
) -> Optional[ListNode]:
    if list1 is None:
        return list2
    elif list2 is None:
        return list1

    if list1.val < list2.val:
        curr = list1
        merged_head = merge_two_lists(list1.next, list2)
    else:
        curr = list2
        merged_head = merge_two_lists(list1, list2.next)
    curr.next = merged_head
    return curr


# 2026/05/14: 看答案实现一遍
def merge_two_lists2(
    list1: Optional[ListNode], list2: Optional[ListNode]
) -> Optional[ListNode]:
    dummy = ListNode(0)
    prev = dummy
    while list1 and list2:
        if list1.val < list2.val:
            prev.next = list1
            list1 = list1.next
        else:
            prev.next = list2
            list2 = list2.next
        prev = prev.next

    prev.next = list1 if list1 else list2
    return dummy.next


l1 = [1, 2, 4]
l2 = [1, 3, 4]
l1 = create_list_node(l1)
l2 = create_list_node(l2)
print_list_node(l1)
print_list_node(l2)
print_list_node(merge_two_lists2(l1, l2))
