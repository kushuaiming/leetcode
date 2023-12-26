#include <cmath>
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

// 利用质数的性质, 进一步优化该算法
int CountPrimes2(int n) {
  if (n <= 2) {
    return 0;
  }
  std::vector<int> prime(n, 1);
  int i = 3, sqrtn = std::sqrt(n), count = n / 2;  // 偶数一定不是质数
  while (i <= sqrtn) {  // 最小质因子一定小于等于开方数
    for (int j = i * i; j < n; j += 2 * i) {  // 避免偶数和重复遍历
      if (prime[j] == 1) {
        --count;
        prime[j] = 0;
      }
    }
    do {
      i += 2;
    } while (i <= sqrtn && prime[i] == 0);  // 避免偶数和重复遍历
  }
  return count;
}
