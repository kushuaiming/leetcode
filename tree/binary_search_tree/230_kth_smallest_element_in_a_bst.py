from typing import Optional, List
from tree.tree_node import TreeNode, create_tree_node


# 2026/05/18: 自己写出答案.
def inorder_traversal(root: Optional[TreeNode], inorder_res: List) -> None:
    if root is None:
        return

    inorder_traversal(root.left, inorder_res)
    inorder_res.append(root.val)
    inorder_traversal(root.right, inorder_res)


def kth_smallest(root: Optional[TreeNode], k: int) -> int:
    inorder_res = []
    inorder_traversal(root, inorder_res)
    return inorder_res[k - 1]


root = [3, 1, 4, None, 2]
k = 3
root = create_tree_node(root)
print(kth_smallest(root, k))
