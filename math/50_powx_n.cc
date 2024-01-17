// 2024/01/17: 直接看答案
// 快速幂 + 递归, 本质是分治算法.
double QuickMul(double x, long long N) {
  if (N == 0) {
    return 1.0;
  }
  double y = QuickMul(x, N / 2);
  return N % 2 == 0 ? y * y : y * y * x;
}

// 2024/01/17: 直接看答案
// 快速幂 + 迭代, 本质是分治算法.
// 例子77的二进制表示是1001101, 拆分成x * x^4 * x^8 * x^64
double QuickMul2(double x, long long N) {
  double res = 1.0;
  // 贡献的初始值为 x
  double x_contribute = x;
  // 在对 N 进行二进制拆分的同时计算答案
  while (N > 0) {
    if (N % 2 == 1) {
      // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
      res *= x_contribute;
    }
    // 将贡献不断地平方
    x_contribute *= x_contribute;
    // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
    N /= 2;
  }
  return res;
}

// 注意x == 0和同时为0的边界条件.
double MyPow(double x, int n) {
  long long N = n;
  return N >= 0 ? QuickMul(x, N) : 1.0 / QuickMul(x, -N);
}
