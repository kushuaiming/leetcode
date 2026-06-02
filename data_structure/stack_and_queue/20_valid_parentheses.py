# 2026/06/02: 自己写出来
def is_valid(s: str) -> bool:
    stack = []

    for c in s:
        if c == "(" or c == "[" or c == "{":
            stack.append(c)
        elif c == ")":
            if len(stack) == 0 or stack[-1] != "(":
                return False
            else:
                stack.pop()
        elif c == "]":
            if len(stack) == 0 or stack[-1] != "[":
                return False
            else:
                stack.pop()
        elif c == "}":
            if len(stack) == 0 or stack[-1] != "{":
                return False
            else:
                stack.pop()

    return len(stack) == 0


s = "()[]{}"
print(is_valid(s))
