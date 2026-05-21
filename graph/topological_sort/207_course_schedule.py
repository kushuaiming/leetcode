from collections import defaultdict, deque
from typing import List


# 2026/05/21: 直接抄答案, 解析见 210
def can_finish1(num_courses: int, prerequisites: List[List[int]]) -> bool:
    edges = defaultdict(list)
    is_visited = [0] * num_courses  # 0: 未访问, 1: 正在访问, 2: 已访问
    valid = True

    for prerequisite in prerequisites:
        edges[prerequisite[1]].append(prerequisite[0])

    def dfs(u: int) -> None:
        nonlocal valid
        is_visited[u] = 1
        for v in edges[u]:
            if is_visited[v] == 0:
                dfs(v)
            elif is_visited[v] == 1:
                valid = False
                return
        is_visited[u] = 2

    for i in range(num_courses):
        if valid and not is_visited[i]:
            dfs(i)

    return valid


# 2026/05/21: 直接抄答案, 解析见 210
def can_finish2(num_courses: int, prerequisites: List[List[int]]) -> bool:
    edges = defaultdict(list)
    indeg = [0] * num_courses
    result = []

    for prerequisite in prerequisites:
        edges[prerequisite[1]].append(prerequisite[0])
        indeg[prerequisite[0]] += 1

    queue = deque([u for u in range(num_courses) if indeg[u] == 0])
    while queue:
        u = queue.popleft()
        for v in edges[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                queue.append(v)
        result.append(u)

    return len(result) == num_courses


num_courses = 2
prerequisites = [[1, 0], [0, 1]]
print(can_finish2(num_courses, prerequisites))
