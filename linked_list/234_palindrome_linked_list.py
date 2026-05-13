import sys, os

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from typing import Optional
from list_node import ListNode, create_list_node, print_list_node


# 2026/05/13: 自己实现时间 O(n), 空间 O(n).
def is_palindrome(head: Optional[ListNode]) -> bool:
    nums = []
    curr = head
    while curr:
        nums.append(curr.val)
        curr = curr.next

    for i in range(len(nums) // 2):
        if nums[i] != nums[len(nums) - 1 - i]:
            return False
    return True


# 2026/05/13: 直接看答案
# 通过递归可以反向遍历节点. 时间复杂度 O(n), 由于递归会使用堆栈空间, 所以空间复杂度 O(n).
def is_palindrome2(head: Optional[ListNode]) -> bool:
    front_pointer = head

    def recursively_check(current_node=head) -> bool:
        if current_node is not None:
            if not recursively_check(current_node.next):
                return False
            if front_pointer.val != current_node.val:
                return False
            front_pointer = front_pointer.next
        return True

    return recursively_check()


# 2026/05/13: 直接抄答案.
# 找到前半部分链表的尾节点 -> 反转后半部分链表 -> 判断是否回文 -> 恢复链表 -> 返回结果
def is_palindrome3(head: Optional[ListNode]) -> bool:
    if head is None:
        return True

    first_half_end = end_of_first_half(head)
    second_half_start = reverse_list(first_half_end.next)

    result = True
    first_position = head
    second_position = second_half_start
    while result and second_position is not None:  # 注意这里的结束条件.
        if first_position.val != second_position.val:
            result = False
        first_position = first_position.next
        second_position = second_position.next
    first_half_end.next = reverse_list(second_half_start)
    return result


def end_of_first_half(head: Optional[ListNode]) -> Optional[ListNode]:
    fast, slow = head, head
    while fast.next is not None and fast.next.next is not None:
        fast = fast.next.next
        slow = slow.next
    return slow


def reverse_list(head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    curr = head
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    return prev


head = [1, 2, 2, 2, 1]
head = create_list_node(head)
print_list_node(head)
print(is_palindrome3(head))
