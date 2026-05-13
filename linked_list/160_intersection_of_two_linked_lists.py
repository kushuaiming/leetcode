from typing import Optional, List, Tuple


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def create_intersect_list(
    listA: List, listB: List, skipA: int, skipB: int
) -> Tuple[ListNode, ListNode]:
    dummy_a = ListNode(0)
    cur_a = dummy_a
    for i in range(skipA):
        cur_a.next = ListNode(listA[i])
        cur_a = cur_a.next

    # 创建共享的交叉部分（从 listA[skipA:] 构建）
    for i in range(skipA, len(listA)):
        cur_a.next = ListNode(listA[i])
        cur_a = cur_a.next

    # 创建 listB 的前 skipB 个节点
    dummy_b = ListNode(0)
    cur_b = dummy_b
    for i in range(skipB):
        cur_b.next = ListNode(listB[i])
        cur_b = cur_b.next

    # 将 listB 的尾部指向 listA 的交叉节点
    node_a = dummy_a.next
    for _ in range(skipA):
        node_a = node_a.next
    cur_b.next = node_a

    return dummy_a.next, dummy_b.next


# 2026/05/13: 直接抄答案, 双指针.
def get_intersection_node(headA: ListNode, headB: ListNode) -> Optional[ListNode]:
    head_a, head_b = headA, headB
    while head_a != head_b:
        head_a = head_a.next if head_a else headB
        head_b = head_b.next if head_b else headA
    return head_a


# 2026/05/13: 直接抄答案, 哈希表
def get_intersection_node2(headA: ListNode, headB: ListNode) -> Optional[ListNode]:
    hash_map = set()
    head_a = headA
    while head_a:
        hash_map.add(head_a)
        head_a = head_a.next

    head_b = headB
    while head_b:
        if head_b in hash_map:
            return head_b
        head_b = head_b.next

    return None


listA = [4, 1, 8, 4, 5]
listB = [5, 6, 1, 8, 4, 5]
skipA = 2
skipB = 3

headA, headB = create_intersect_list(listA, listB, skipA, skipB)
print(get_intersection_node2(headA, headB).val)
