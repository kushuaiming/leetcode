from typing import List


# 2026/05/11: 自己写出答案, 时间复杂度和空间复杂度都是 O(n).
def product_except_self(nums: List[int]) -> List[int]:
    left_products, right_products, res = (
        [0] * len(nums),
        [0] * len(nums),
        [0] * len(nums),
    )

    left_products[0] = 1
    for i in range(1, len(nums)):
        left_products[i] = left_products[i - 1] * nums[i - 1]

    right_products[-1] = 1
    for i in range(len(nums) - 2, -1, -1):
        right_products[i] = right_products[i + 1] * nums[i + 1]

    for i in range(0, len(nums)):
        res[i] = left_products[i] * right_products[i]

    return res


nums1 = [1, 2, 3, 4]
nums2 = [-1, 1, 0, -3, 3]
print(product_except_self(nums1))
print(product_except_self(nums2))
