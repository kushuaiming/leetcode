from linked_list.list_node import ListNode, create_list_node, print_list_node
from typing import Optional, List


class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


def create_node(nums: List) -> Optional[Node]:
    dummy = Node(0)
    curr = dummy

    for num in nums:
        curr.next = Node(num)
        curr = curr.next

    return dummy.next


def create_random_node(head: List[List]) -> Optional[None]:
    nums = [item[0] for item in head]
    random = [item[1] for item in head]
    length = len(nums)
    node_list = create_node(nums)

    hash_map = {}
    curr = node_list
    for i in range(length):
        if curr is None:
            break
        hash_map[i] = curr
        curr = curr.next

    for i in range(length):
        hash_map[i].random = hash_map[random[i]] if random[i] is not None else None

    return node_list


# 2026/05/14: 自己写, 但是用了 AI 进行 Debug.
def copy_random_list(head: "Optional[Node]") -> "Optional[Node]":
    hash_map = {}
    dummy_new_head = Node(0)
    curr = head
    new_curr = dummy_new_head
    while curr is not None:
        new_node = Node(curr.val)
        new_curr.next = new_node
        hash_map[curr] = new_node
        curr = curr.next
        new_curr = new_curr.next

    for key, value in hash_map.items():
        value.random = hash_map[key.random] if key.random is not None else None

    return dummy_new_head.next


head = [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]
head = create_random_node(head)
new_head = copy_random_list(head)
new_head
