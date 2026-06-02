# 2026/06/02: 参考了一下答案, 关键在与多一个 min_stack.
class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = [float("inf")]

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.min_stack.append(min(val, self.min_stack[-1]))

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def get_min(self) -> int:
        return self.min_stack[-1]


obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.get_min())
obj.pop()
print(obj.top())
print(obj.get_min())
