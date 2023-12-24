// 二分查找, 时间复杂度为O(log(x))
#include <iostream>

int MySqrt(int x) {
  int left = 0;
  int right = x;
  // 关注循环的判断条件
  while (left <= right) {
    // 关注mid的计算方法
    int mid = left + (right - left) / 2;
    if (static_cast<long long>(mid) * mid == x) {
      return mid;
    } else if (static_cast<long long>(mid) * mid < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return right;
}

// 牛顿迭代法: https://en.wikipedia.org/wiki/Newton%27s_method
// x_n+1 = x_n - f(x) / f'(x)
// 这里f(x) = x^2 - C
int NewtonMethodSqrt(int x) {
  if (x == 0) {
    return 0;
  }

  double C = x; // C > sqrt(x) && C <= x
  double x0 = x;
  while (true) {
    double xi = 0.5 * (x0 + C / x0);
    if (std::abs(x0 - xi) < 1e-7) {
      break;
    }
    x0 = xi;
  }
  return static_cast<int>(x0);
}

int main(int argc, char* argv[]) {
  int x = 8;
  std::cout << MySqrt(x) << std::endl;
  return 0;
}
