#include <bitset>
#include <iostream>
#include <string>

// 问题转化成
// 1. 这个数是2的密函数
// 2. 这个数1的位值必须为奇数位
bool IsPowerOfFour(int n) {
  return n > 0 && !(n & (n - 1)) && (n & 0b01010101010101010101010101010101);
}

int main(int argc, char* argv[]) {
  std::cout << IsPowerOfFour(16) << std::endl;
  return 0;
}
