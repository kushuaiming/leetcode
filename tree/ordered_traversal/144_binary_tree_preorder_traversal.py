from typing import List, Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node


# 2026/05/19: 自己实现递归和迭代版本
def preorder(root: Optional[TreeNode], res: List[int]) -> None:
    if root is None:
        return
    res.append(root.val)
    preorder(root.left, res)
    preorder(root.right, res)


def preorder_traversal1(root: Optional[TreeNode]) -> List[int]:
    res = []
    preorder(root, res)
    return res


def preorder_traversal2(root: Optional[TreeNode]) -> List[int]:
    res = []
    stack = []

    if root is None:
        return res
    stack.append(root)
    while len(stack) > 0:
        curr = stack.pop()
        res.append(curr.val)
        if curr.right is not None:
            stack.append(curr.right)
        if curr.left is not None:
            stack.append(curr.left)

    return res


root = [1, 2, 3, 4, 5, None, 8, None, None, 6, 7, 9]
root = create_tree_node(root)
print_tree_node(root)
print(preorder_traversal2(root))
