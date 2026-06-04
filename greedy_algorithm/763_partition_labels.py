from typing import List


# 2026/06/04: 根据答案写出贪心算法
def partition_labels2(s: str) -> List[int]:
    end_positions = [-1] * 26
    for i in range(len(s)):
        end_positions[ord(s[i]) - ord("a")] = max(
            i, end_positions[ord(s[i]) - ord("a")]
        )

    start, end = 0, 0
    res = []
    for i in range(len(s)):
        end = max(end_positions[ord(s[i]) - ord("a")], end)
        if i == end:
            res.append(end - start + 1)
            start = i + 1
    return res


# 2026/06/04: 自己写出了合并区间的方法.
def partition_labels1(s: str) -> List[int]:
    position = {}
    for i in range(len(s)):
        if s[i] not in position:
            position[s[i]] = (i, i)
        else:
            left = position[s[i]][0]
            right = position[s[i]][1]
            position[s[i]] = (min(left, i), max(right, i))

    sorted_positions = [
        list(v) for _, v in sorted(position.items(), key=lambda x: x[1][0])
    ]
    print(sorted_positions)

    results = []
    results.append(sorted_positions[0])
    for i in range(1, len(sorted_positions)):
        interval = sorted_positions[i]
        if interval[0] < results[-1][1]:
            results[-1][1] = max(results[-1][1], interval[1])
        else:
            results.append(interval)

    results = [result[1] - result[0] + 1 for result in results]
    return results


s1 = "ababcbacadefegdehijhklij"
s2 = "eccbbbbdec"
print(partition_labels2(s1))
