from collections import deque
from typing import List, Optional
from tree.tree_node import TreeNode, create_tree_node, print_tree_node


# 2026/05/19: 自己写出来, 使用层次遍历.
def right_side_view(root: Optional[TreeNode]) -> List[int]:
    res = []
    if root is None:
        return res

    queue = deque()
    queue.append(root)
    while len(queue) > 0:
        count = len(queue)
        for i in range(count):
            curr = queue.popleft()
            if i == count - 1:
                res.append(curr.val)
            if curr.left is not None:
                queue.append(curr.left)
            if curr.right is not None:
                queue.append(curr.right)

    return res


root = [1, 2, 3, 4, None, None, None, 5]
root = create_tree_node(root)
print(right_side_view(root))
