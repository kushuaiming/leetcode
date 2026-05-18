from collections import deque
from typing import Optional
from tree.tree_node import TreeNode, create_tree_node


# 2026/05/18: 自己写出迭代版本, 可以参考 C++ 的迭代版本对放入 queue 的 None 的顺序进行优化.
def is_symmetric(root: Optional[TreeNode]) -> bool:
    queue = deque()
    queue.append(root)

    while len(queue) > 0:
        count = len(queue)
        layer_res = []
        for _ in range(count):
            curr = queue.popleft()
            if curr is not None:
                layer_res.append(curr.val)
                queue.append(curr.left)
                queue.append(curr.right)
            else:
                layer_res.append(float("inf"))

        for i in range(count // 2):
            if layer_res[i] != layer_res[count - i - 1]:
                return False

    return True


def check(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
    if left is None and right is None:
        return True

    if left is None or right is None:
        return False

    if left.val != right.val:
        return False

    return check(left.left, right.right) and check(left.right, right.left)


def is_symmetric2(root: Optional[TreeNode]) -> bool:
    if root is None:
        return True
    return check(root.left, root.right)


root = [1, 2, 2, 3, 5, 4, 3]
root = create_tree_node(root)
print(is_symmetric2(root))
