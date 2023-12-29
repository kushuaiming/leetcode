#include <stack>
#include <string>

// 从左往右遍历, 每当遇到左括号便放入栈内,
// 遇到右括号则判断其和栈顶的括号是否统一类型, 是则从栈内取出左括号,
// 否则说明字符串不合法.
bool IsValid(const std::string& s) {
  std::stack<int> stack;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push(c);
    } else {
      if (stack.empty()) {
        return false;
      }
      char top = stack.top();
      if (c == ')' && top != '(') {
        return false;
      }
      if (c == ']' && top != '[') {
        return false;
      }
      if (c == '}' && top != '{') {
        return false;
      }
      stack.pop();
    }
  }
  return stack.empty(); // 注意返回的值
}
