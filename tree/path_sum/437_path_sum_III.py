from typing import Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node


# 2026/05/19: 直接抄答案.
def path_sum_start_with_root(root: Optional[TreeNode], target_sum: int) -> int:
    if root is None:
        return 0

    count = 1 if root.val == target_sum else 0
    count += path_sum_start_with_root(root.left, target_sum - root.val)
    count += path_sum_start_with_root(root.right, target_sum - root.val)
    return count


def path_sum(root: Optional[TreeNode], target_sum: int) -> int:
    if root is None:
        return 0

    return (
        path_sum_start_with_root(root, target_sum)
        + path_sum(root.left, target_sum)
        + path_sum(root.right, target_sum)
    )


root = [10, 5, -3, 3, 2, None, 11, 3, -2, None, 1]
root = create_tree_node(root)
target_sum = 8
print(path_sum(root, target_sum))
