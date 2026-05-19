from typing import Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node


# 2026/05/19: 自己写出来, 前序遍历的同时展开.
def flatten(root: Optional[TreeNode]) -> None:
    """
    Do not return anything, modify root in-place instead.
    """
    if root is None:
        return

    stack = []
    prev = TreeNode(0)
    stack.append(root)
    while len(stack) > 0:
        curr = stack.pop()
        prev.right = curr
        prev.left = None
        prev = curr
        if curr.right is not None:
            stack.append(curr.right)
        if curr.left is not None:
            stack.append(curr.left)


root = [1, 2, 5, 3, 4, None, 6]
root = create_tree_node(root)
print_tree_node(root)
flatten(root)
print_tree_node(root)
