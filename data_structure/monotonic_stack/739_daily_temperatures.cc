#include <iostream>
#include <stack>
#include <vector>

// 2024/01/21: 自己做出来.
// 2024/01/12: 看了答案提示的情况下做出来了.

// 维护一个存储下标的单调栈, 从栈底到栈顶的下标对应的温度列表中的温度依次递减.
std::vector<int> DailyTemperatures(const std::vector<int>& temperatures) {
  int n = temperatures.size();
  std::vector<int> res(n, 0);
  std::stack<int> stk;
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
      res[stk.top()] = i - stk.top();
      stk.pop();
    }
    stk.push(i);
  }
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> res = DailyTemperatures(temperatures);
  for (int data : res) {
    std::cout << data << std::endl;
  }
  return 0;
}
