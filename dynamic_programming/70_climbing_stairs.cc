#include <iostream>
int ClimbStairs(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }
  int pre_pre = 1;
  int pre = 2;
  int result = 0;
  for (int i = 0; i < n - 2; ++i) {
    result = pre + pre_pre;
    pre_pre = pre;
    pre = result;
  }
  return result;
}

int main(int argc, char* argv[]) {
  constexpr int n = 3;
  std::cout << ClimbStairs(n) << std::endl;
  return 0;
}