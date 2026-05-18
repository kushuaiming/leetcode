from tree.tree_node import TreeNode, create_tree_node
from typing import Optional, Tuple

# 2026/05/18: 自己实现直接递归版本, 也可以中序遍历后看得到的数组 List 是否严格升序.
flag = True


def get_min_max(root: Optional[TreeNode]) -> Tuple[int, int]:
    global flag
    if root is None:
        return float("inf"), float("-inf")

    value = root.val
    left_min_value, left_max_value = get_min_max(root.left)
    right_min_value, right_max_value = get_min_max(root.right)
    if value <= left_max_value or value >= right_min_value:
        flag = False
    return min(value, left_min_value, right_min_value), max(
        value, left_max_value, right_max_value
    )


def is_valid_bst(root: Optional[TreeNode]) -> bool:
    get_min_max(root)
    return flag


root = [5, 1, 4, None, None, 3, 6]
root = create_tree_node(root)
print(is_valid_bst(root))
