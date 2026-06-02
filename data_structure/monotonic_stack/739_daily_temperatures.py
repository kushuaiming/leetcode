from typing import List


# 2026/06/02: 自己写出来.
def daily_temperatures(temperatures: List[int]) -> List[int]:
    answers = [0] * len(temperatures)
    monotonic_stack = []

    for i, temperature in enumerate(temperatures):
        while (
            len(monotonic_stack) > 0 and temperature > temperatures[monotonic_stack[-1]]
        ):
            answers[monotonic_stack[-1]] = i - monotonic_stack[-1]
            monotonic_stack.pop()

        monotonic_stack.append(i)

    return answers


temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
print(daily_temperatures(temperatures))
