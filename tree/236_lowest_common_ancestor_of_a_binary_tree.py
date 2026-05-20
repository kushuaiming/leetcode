from tree.tree_node import TreeNode, create_tree_node
from typing import Optional

res = None


# 2026/05/20: 直接抄答案.
# 判断 p 或者 q 是否在整颗树里面.
def check(
    root: Optional[TreeNode], p: Optional[TreeNode], q: Optional[TreeNode]
) -> bool:
    global res

    if root is None:
        return False

    left_son = check(root.left, p, q)
    right_son = check(root.right, p, q)
    if (left_son and right_son) or (
        (root.val == p.val or root.val == q.val) and (left_son or right_son)
    ):
        res = root

    return left_son or right_son or root.val == p.val or root.val == q.val


def lowest_common_ancestor(
    root: Optional[TreeNode], p: Optional[TreeNode], q: Optional[TreeNode]
) -> Optional[TreeNode]:
    check(root, p, q)
    return res


root = [3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]
p = 5
q = 1
root = create_tree_node(root)
