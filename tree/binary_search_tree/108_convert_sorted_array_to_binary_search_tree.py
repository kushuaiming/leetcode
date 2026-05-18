from typing import List, Optional
from tree.tree_node import TreeNode, print_tree_node


# 2026/05/18: 自己写出答案
def sorted_array_to_bst(nums: List[int]) -> Optional[TreeNode]:
    if len(nums) == 0:
        return None
    counts = len(nums)
    mid = counts // 2
    node = TreeNode(nums[mid])
    node.left = sorted_array_to_bst(nums[:mid])
    node.right = sorted_array_to_bst(nums[mid + 1 :])
    return node


nums = [-10, -3, 0, 5, 9]
print_tree_node(sorted_array_to_bst(nums))
