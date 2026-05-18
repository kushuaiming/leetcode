from typing import Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node


# 2026/05/18: 自己写出来, 根据答案进行简化.
def invert_tree(root: Optional[TreeNode]) -> Optional[TreeNode]:
    if root is None:
        return None

    left = invert_tree(root.left)
    right = invert_tree(root.right)
    root.left = right
    root.right = left
    return root


root = [4, 2, 7, 1, 3, 6, 9]
root = create_tree_node(root)
print_tree_node(root)
root = invert_tree(root)
print_tree_node(root)
