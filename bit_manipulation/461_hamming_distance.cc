#include <iostream>

// 对两个数进行按位异或, 统计有多少个1即可.
int HammingDistance(int x, int y) {
  int diff = x ^ y;
  int ans = 0;
  while (diff) {
    ans += diff & 1;
    diff >>= 1;
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::cout << HammingDistance(1, 4) << std::endl;
  return 0;
}
