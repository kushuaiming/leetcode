from typing import List


# 2026/05/21: 自己写出来.
def generateParenthesis(n: int) -> List[str]:
    results = []
    result = []

    left_parenthesis_count = 0
    right_parenthesis_count = 0

    def backtracking() -> None:
        nonlocal left_parenthesis_count
        nonlocal right_parenthesis_count
        if left_parenthesis_count == n and right_parenthesis_count == n:
            results.append("".join(result))
            return

        if left_parenthesis_count < n:
            result.append("(")
            left_parenthesis_count += 1
            backtracking()
            result.pop()
            left_parenthesis_count -= 1

        if left_parenthesis_count > right_parenthesis_count:
            result.append(")")
            right_parenthesis_count += 1
            backtracking()
            result.pop()
            right_parenthesis_count -= 1

    backtracking()
    return results


n = 3
print(generateParenthesis(n))
