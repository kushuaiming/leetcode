from typing import List


def generate(num_rows: int) -> List[List[int]]:
    if num_rows == 0:
        return []

    res = []
    for i in range(1, num_rows + 1):
        layer = [1] * i
        for j in range(1, i - 1):
            layer[j] = res[-1][j - 1] + res[-1][j]
        res.append(layer)

    return res


num_rows = 1
print(generate(num_rows))
