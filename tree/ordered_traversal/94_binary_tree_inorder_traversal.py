from typing import Optional, List
from tree.tree_node import TreeNode, create_tree_node


def inorder(root: Optional[TreeNode], res: List) -> None:
    if root is None:
        return
    inorder(root.left, res)
    res.append(root.val)
    inorder(root.right, res)


def inorder_traversal(root: Optional[TreeNode]) -> List[int]:
    res = []
    inorder(root, res)
    return res


# 2026/05/15: 直接看答案, 迭代版本.
def inorder_traversal2(root: Optional[TreeNode]) -> List[int]:
    res = []
    stack = []
    while root or len(stack) > 0:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        res.append(root.val)
        root = root.right
    return res


root = [1, None, 2, 3]
root = create_tree_node(root)
print(inorder_traversal2(root))
