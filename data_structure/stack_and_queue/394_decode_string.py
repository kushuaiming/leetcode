# 2026/06/02: 完全自己实现.
def decode_string(s: str) -> str:
    stack = []

    for c in s:
        if "0" <= c <= "9":
            if len(stack) > 0 and "0" <= stack[-1] <= "9":
                stack[-1] += c
            else:
                stack.append(c)
        elif "a" <= c <= "z":
            if len(stack) > 0 and "a" <= stack[-1] <= "z":
                stack[-1] += c
            else:
                stack.append(c)
        elif c == "[":
            stack.append(c)
        elif c == "]":
            temp_str = ""
            while len(stack) > 0 and stack[-1] != "[":
                temp_str = stack.pop() + temp_str
            stack.pop()
            count = int(stack.pop())
            temp_str = temp_str * count
            stack.append(temp_str)

    return "".join(stack)


s1 = "3[a]2[bc]"
s2 = "3[a2[c]]"
s3 = "2[abc]3[cd]ef"
s4 = "abc3[cd]xyz"
print(decode_string(s4))
