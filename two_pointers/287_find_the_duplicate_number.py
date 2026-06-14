# 2026/06/14: 直接抄答案

# 我们对 nums 数组建图, 每个位置 i 连一条 i→nums[i] 的边.
# 由于存在的重复的数字 target, 因此 target 这个位置一定有起码两条指向它的边,
# 因此整张图一定存在环, 且我们要找到的 target 就是这个环的入口.
# 那么整个问题就等价于 142. 环形链表 II
def find_duplicate(nums):
    slow = 0
    fast = 0
    # 第一阶段: 找到环内相遇点
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break
    # 第二阶段: 寻找环入口(重复数)
    slow = 0
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    return slow
