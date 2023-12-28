#include <bitset>
#include <cstdint>
#include <iostream>

// 使用算术左移和右移实现翻转
uint32_t ReverseBits(uint32_t n) {
  uint32_t ans = 0;
  for (int i = 0; i < 32; ++i) {
    // 先挪出空位, 后赋值.
    ans <<= 1;
    ans += n & 1;
    n >>= 1;
  }
  return ans;
}

// 分治策略
uint32_t ReverseBitsV2(uint32_t n) {
  // M代表Mask的含义
  constexpr uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
  constexpr uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
  constexpr uint32_t M4 = 0x0f0f0f0f;  // 00001111000011110000111100001111
  constexpr uint32_t M8 = 0x00ff00ff;  // 00000000111111110000000011111111

  // 优先级: (<< >>) & ^ |
  n = n >> 1 & M1 | (n & M1) << 1;  // 交换奇数位和偶数位
  n = n >> 2 & M2 | (n & M2) << 2;
  n = n >> 4 & M4 | (n & M4) << 4;
  n = n >> 8 & M8 | (n & M8) << 8;
  return n >> 16 | n << 16;  // 交换左半边和右半边
}

int main(int argc, char* argv[]) {
  uint32_t n = 0b11111111111111111111111111111101;
  uint32_t reversed_n = ReverseBits(n);
  std::cout << std::oct << reversed_n << std::endl;
  std::cout << std::dec << reversed_n << std::endl;
  std::cout << std::hex << reversed_n << std::endl;
  std::cout << std::bitset<sizeof(reversed_n) * 8>(reversed_n) << std::endl;
  return 0;
}
