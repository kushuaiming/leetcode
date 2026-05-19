from typing import List, Optional
from tree.tree_node import TreeNode, print_tree_node


# 2026/05/19: 自己写出递归算法.
def build_tree(preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    if len(preorder) == 0:
        return None

    root_val = preorder[0]
    root = TreeNode(root_val)
    mid = inorder.index(root_val)
    root.left = build_tree(preorder[1 : mid + 1], inorder[:mid])
    root.right = build_tree(preorder[mid + 1 :], inorder[mid + 1 :])
    return root


preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]
root = build_tree(preorder, inorder)
print_tree_node(root)
