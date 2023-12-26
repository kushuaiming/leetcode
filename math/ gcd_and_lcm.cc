// 最大公因数(greatest common divisor, gcd).
int Gcd(int a, int b) { return b == 0 ? a : Gcd(b, a % b); }

// 最小公倍数(least common multiple, lcm).
int Lcm(int a, int b) { return a * b / Gcd(a, b); }

// 扩展欧几里得算法(extended gcd)
// 在求得a和b最大公因数的同时, 也得到它们的系数x和y, 使得ax+by=gcd(a,b)
int Xgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1, gcd = Xgcd(b, a % b, x1, y1);
  x = y1, y = x1 - (a / b) * y1;
  return gcd;
}
