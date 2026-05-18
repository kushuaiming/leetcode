from collections import deque
from tree.tree_node import TreeNode, create_tree_node, print_tree_node
from typing import Optional, List


# 2026/05/18: 自己写出来.
def level_order(root: Optional[TreeNode]) -> List[List[int]]:
    res = []
    if root is None:
        return res

    queue = deque()
    queue.append(root)
    while len(queue) > 0:
        layer = []
        count = len(queue)
        for _ in range(count):
            curr = queue.popleft()
            layer.append(curr.val)
            if curr.left is not None:
                queue.append(curr.left)
            if curr.right is not None:
                queue.append(curr.right)
        res.append(layer)

    return res


root = [3, 9, 20, None, None, 15, 7]
root = create_tree_node(root)
print_tree_node(root)
print(level_order(root))
