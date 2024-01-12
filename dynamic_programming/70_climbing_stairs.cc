#include <iostream>

// 2024/01/12: 自己实现
int ClimbStairs(int n) {
  if (n <= 1) {
    return 1;
  }
  int pre = 1;
  int pre_pre = 1;
  for (int i = 0; i < n - 1; ++i) {
    int cur = pre + pre_pre;
    pre_pre = pre;
    pre = cur;
  }
  return pre;
}

int main(int argc, char* argv[]) {
  constexpr int n = 3;
  std::cout << ClimbStairs(n) << std::endl;
  return 0;
}