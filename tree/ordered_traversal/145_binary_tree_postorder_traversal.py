from typing import List, Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node


# 2026/05/19: 直接抄答案.
def postorder_traversal(self, root: Optional[TreeNode]) -> List[int]:
    res = []
    if root is None:
        return res

    stack = []
    prev = None
    stack.append(root)
    while root and len(stack) > 0:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        if root.right is None or root.right == prev:
            res.append(root.val)
            prev = root
            root = None
        else:
            stack.append(root)
            root = root.right
    return res


root = [1, 2, 3, 4, 5, None, 8, None, None, 6, 7, 9]
