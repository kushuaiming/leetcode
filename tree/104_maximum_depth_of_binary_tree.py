from collections import deque
from typing import Optional
from tree.tree_node import TreeNode, create_tree_node


# 2026/05/18: 自己写出递归.
def max_depth(root: Optional[TreeNode]) -> int:
    if root is None:
        return 0

    return max(max_depth(root.left), max_depth(root.right)) + 1


# 2026/05/18: 自己写出循环, Python 中把 deque 当作 queue 使用.
def max_depth2(root: Optional[TreeNode]) -> int:
    if root is None:
        return 0

    dq = deque()
    dq.append(root)
    depth = 0
    while len(dq) != 0:
        depth += 1
        count = len(dq)
        for _ in range(count):
            curr = dq.popleft()
            if curr.left is not None:
                dq.append(curr.left)
            if curr.right is not None:
                dq.append(curr.right)

    return depth


root = [3, 9, 20, None, None, 15, 7]
root = create_tree_node(root)
print(max_depth2(root))
