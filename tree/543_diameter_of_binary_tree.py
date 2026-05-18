from typing import Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node

diameter = 0


# 2026/05/18: 自己写出来了, 但是 height 调用重复导致超出时间限制, 应该先保存.
def height(root: Optional[TreeNode]) -> int:
    if root is None:
        return 0
    left_height = height(root.left)
    right_height = height(root.right)
    diameter = max(diameter, left_height + right_height)
    return max(left_height, right_height) + 1


def diameter_of_binary_tree(root: Optional[TreeNode]) -> int:
    height(root)
    return diameter


root = [
    4,
    -7,
    -3,
    None,
    None,
    -9,
    -3,
    9,
    -7,
    -4,
    None,
    6,
    None,
    -6,
    -6,
    None,
    None,
    0,
    6,
    5,
    None,
    9,
    None,
    None,
    -1,
    -4,
    None,
    None,
    None,
    -2,
]
root = create_tree_node(root)
print_tree_node(root)
print(diameter_of_binary_tree(root))
