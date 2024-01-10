#include <cmath>

// 2024/01/10: 集度面试问到了, 直接抄答案.
int IntegerBreak(int n) {
  if (n <= 3) {
    return n - 1;
  }
  int quotient = n / 3;
  int remainder = n % 3;
  if (remainder == 0) {
    return static_cast<int>(std::pow(3, quotient));
  } else if (remainder == 1) {
    return static_cast<int>(std::pow(3, quotient - 1) * 4);
  } else {
    return static_cast<int>(std::pow(3, quotient) * 2);
  }
}
