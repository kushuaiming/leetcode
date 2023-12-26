#include <iostream>
#include <sstream>
#include <string>
#include <vector>

constexpr int kAddition = -1;
constexpr int kSubtraction = -2;
constexpr int kMultiplication = -3;

// 在递归前+1, 在递归后-1, 用于打log调试.
int recursion_times = 0;

void PrintTab() {
  for (int i = 0; i < recursion_times; ++i) {
    std::cout << '\t';
  }
}

void Print(const std::vector<int>& results, const std::string& source) {
  PrintTab();
  std::cout << source << ": ";
  for (int result : results) {
    std::cout << result << ' ';
  }
  std::cout << std::endl;
}

// 2023/11/11 第一次刷
// 利用分治思想, 把加括号转化为, 对于每个运算符号, 先处理两侧的数学表达式,
// 再处理此运算符号
std::vector<int> DiffWaysToCompute(const std::string& expression) {
  std::vector<int> ways;
  for (int i = 0; i < expression.size(); ++i) {
    const char c = expression[i];
    if (c == '+' || c == '-' || c == '*') {
      ++recursion_times;
      std::vector<int> left = DiffWaysToCompute(expression.substr(0, i));
      std::vector<int> right = DiffWaysToCompute(expression.substr(i + 1));
      --recursion_times;
      Print(left, "left");
      Print(right, "right");
      for (int l : left) {
        for (int r : right) {
          switch (c) {
            case '+':
              ways.push_back(l + r);
              break;
            case '-':
              ways.push_back(l - r);
              break;  // 要记得写break.
            case '*':
              ways.push_back(l * r);
              break;
            default:
              break;
          }
        }
      }
    }
  }
  if (ways.empty()) {
    ways.push_back(std::stoi(expression));
  }
  Print(ways, "ways");
  return ways;
}

// 动态规划, dp[j][i]表示data里[j, i]的数据所有的可能的表达式结果.
std::vector<int> DiffWaysToComputeV2(const std::string& expression) {
  std::vector<int> data;
  std::vector<int> ops;
  int num = 0;
  char op = ' ';
  // 最后补一个'+', 方便解析, 不影响最终的结果.
  std::istringstream ss(expression + "+");
  while (ss >> num && ss >> op) {
    data.push_back(num);
    ops.push_back(op);
  }
  const int n = data.size();
  std::vector<std::vector<std::vector<int>>> dp(
      n, std::vector<std::vector<int>>(n, std::vector<int>()));
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      if (i == j) {
        dp[j][i].push_back(data[i]);
        continue;
      }
      // 遍历从j到i之间的每一个字符, 计算左表达式和右表达式可能产生的结果.
      for (int k = j; k < i; ++k) {
        for (auto left : dp[j][k]) {
          for (auto right : dp[k + 1][i]) {
            int val = 0;
            switch (ops[k]) {
              case '+':
                val = left + right;
                break;
              case '-':
                val = left - right;
                break;
              case '*':
                val = left * right;
                break;
              default:
                break;
            }
            dp[j][i].push_back(val);
          }
        }
      }
    }
  }
  return dp[0][n - 1];
}

int main(int argc, char* argv[]) {
  const std::string expression = "2-1-1";
  std::vector<int> results = DiffWaysToComputeV2(expression);
  for (int result : results) {
    std::cout << result << " ";
  }
  std::cout << std::endl;
  return 0;
}
