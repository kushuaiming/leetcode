#include <vector>

// 从1到n遍历, 假设当前遍历到m, 则把所有小于n的, 且是m的倍数的整数标为和数;
// 遍历完成后, 没有被标为和数的数字即为质数.
int CountPrimes(int n) {
  if (n <= 2) {
    return 0;
  }
  std::vector<int> prime(n, 1);
  int count = n - 2;  // 去掉不是质数的0和1
  for (int i = 2; i < n; ++i) {
    if (prime[i] == 1) {
      for (int j = i * 2; j < n; j += i) {
        if (prime[j] == 1) {
          prime[j] = 0;
          --count;
        }
      }
    }
  }
  return count;
}
