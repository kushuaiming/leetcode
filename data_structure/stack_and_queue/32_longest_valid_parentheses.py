# 2026/06/10: 直接看答案
# 始终保持栈底元素为当前已经遍历过的元素中"最后一个没有被匹配的右括号的下标".
def longest_valid_parentheses(s: str) -> int:
    res = 0
    stack = []
    stack.append(-1)

    for i in range(len(s)):
        if s[i] == "(":
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                res = max(res, i - stack[-1])

    return res


s = ")()())"
print(longest_valid_parentheses(s))
