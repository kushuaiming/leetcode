#include <vector>

// 原题: 输出从0到n的所有数的二进制表示的1的个数: 位运算 + 动态规划
std::vector<int> CountBits(int n) {
  std::vector<int> dp(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
    // 等价于 dp[i] = dp[i & (i -1)] + 1;
  }
  return dp;
}

// 只计算n的二进制表示的1的个数
int CountBits2(int n) {
  int res = 0;
  int flag = 1;
  while (flag) {
    if (n & flag) {
      ++res;
    }
    flag = flag << 1;
  }
  return res;
}

// 每次去除最低位的1
int CountBits3(int n) {
  int res = 0;
  while (n) {
    n &= (n - 1);
    ++res;
  }
  return res;
}
