from collections import defaultdict, deque
from typing import List


# 2026/05/21: 直接抄答案
# 深度优先遍历, DFS.
def find_order1(num_courses: int, prerequisites: List[List[int]]) -> List[int]:
    edges = defaultdict(list)  # 注意这里 edges 的初始化方式.
    visited = [0] * num_courses  # 0 = 未搜索, 1 = 搜索中, 2 = 已完成.
    result = list()  # 用数组模拟栈
    valid = True  # 判断是否有环

    for prerequisite in prerequisites:
        edges[prerequisite[1]].append(prerequisite[0])

    def dfs(u: int) -> None:
        nonlocal valid
        visited[u] = 1
        for v in edges[u]:
            if visited[v] == 0:
                dfs(v)
                if not valid:
                    return
            elif visited[v] == 1:
                valid = False
                return
        visited[u] = 2
        result.append(u)

    for i in range(num_courses):
        if valid and not visited[i]:
            dfs(i)

    if not valid:
        return list()

    return result[::-1]  # 下标 0 为栈底, 所以需要反序输出.


# 2026/05/21: 直接抄答案
# 广度优先遍历, BFS.
def find_order2(num_courses: int, prerequisites: List[List[int]]) -> List[int]:
    edges = defaultdict(list)
    indeg = [0] * num_courses  # 关键: 存储每个节点的入度.
    result = []

    for prerequisite in prerequisites:
        edges[prerequisite[1]].append(prerequisite[0])
        indeg[prerequisite[0]] += 1

    queue = deque([u for u in range(num_courses) if indeg[u] == 0])

    while queue:  # 判空可以直接写, 不需要判断 len 长度.
        u = queue.popleft()
        result.append(u)
        for v in edges[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                queue.append(v)

    if len(result) != num_courses:
        return []

    return result


num_courses = 4
prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
print(find_order1(num_courses, prerequisites))
