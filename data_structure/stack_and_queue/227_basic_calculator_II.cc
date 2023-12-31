#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// 关键: 用一个 vector 模拟栈, 这样方便对最后一个数进行计算.
int Calculate(const std::string& s) {
  std::vector<int> stk;
  char pre_sign = '+';
  int num = 0;
  const int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (std::isdigit(s[i])) {
      num = num * 10 + static_cast<int>(s[i] - '0');
    }
    if (!std::isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
      switch (pre_sign) {
        case '+': {
          stk.push_back(num);
          break;
        }
        case '-': {
          stk.push_back(-num);
          break;
        }
        case '*': {
          stk.back() *= num;
          break;
        }
        case '/': {
          stk.back() /= num;
          break;
        }
        default:
          break;
      }
      pre_sign = s[i];
      num = 0;
    }
  }
  return std::accumulate(stk.begin(), stk.end(), 0);
}

int main(int argc, char* argv[]) {
  const std::string s = "3+2*2";
  const std::string s2 = "42";
  std::cout << Calculate(s2) << std::endl;
  return 0;
}
