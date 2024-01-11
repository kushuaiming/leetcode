#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 2024/01/11: 在做了46和78的基础上, 自己写出来了.
std::unordered_map<char, std::string> hash_table = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
void Backtrack(const std::string& digits, std::vector<std::string>& res,
               std::string& output, int first) {
  if (output.size() == digits.size()) {
    res.push_back(output);
    return;
  }
  for (int i = first; i < digits.size(); ++i) {
    std::string num_to_string = hash_table[digits[i]];
    for (char c : num_to_string) {
      output.push_back(c);
      Backtrack(digits, res, output, i + 1);
      output.pop_back();
    }
  }
}

std::vector<std::string> LetterCombinations(std::string digits) {
  std::vector<std::string> res;
  std::string output;
  if (digits.size() == 0) {
    return res;
  }
  Backtrack(digits, res, output, 0);
  return res;
}

int main(int argc, char* argv[]) {
  std::string digits = "23";
  std::vector<std::string> res = LetterCombinations(digits);
  for (const std::string s : res) {
    std::cout << s << std::endl;
  }
  return 0;
}
