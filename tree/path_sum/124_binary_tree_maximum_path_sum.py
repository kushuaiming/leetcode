from typing import Optional
from tree.tree_node import TreeNode, create_tree_node

res = float("-inf")


# 2026/05/20: 不看答案自己实现.
# 包括 root 节点且只选择左子树或者右子树其中一个的最大值.
def max_sum_include_root(root: Optional[TreeNode]) -> int:
    global res
    if root is None:
        return 0

    left_max_sum = max_sum_include_root(root.left)
    right_max_sum = max_sum_include_root(root.right)
    res = max(res, root.val + max(left_max_sum, 0) + max(right_max_sum, 0))
    return root.val + max(left_max_sum, right_max_sum, 0)


def max_path_sum(root: Optional[TreeNode]) -> int:
    max_sum_include_root(root)
    return res


# root = [-10, 9, 20, None, None, 15, 7]
# root = create_tree_node(root)
# print(max_path_sum(root))

root2 = [5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1]
root2 = create_tree_node(root2)
print(max_path_sum(root2))
