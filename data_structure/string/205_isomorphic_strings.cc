#include <iostream>
#include <string>
#include <vector>

// 记录两个字符串每个位置字符第一次(或上一次)出现的位置,
// 如果两个字符串相同位置的字符与它们第一次(或上一次)出现的位置一样,
// 那么这两个字符串同构.
bool IsIsomorphic(const std::string& s, const std::string& t) {
  // 初始化的值不能是index可能会出现的数.
  std::vector<int> s_index(256, -1);
  std::vector<int> t_index(256, -1);
  for (int i = 0; i < s.size(); ++i) {
    if (s_index[s[i]] != t_index[t[i]]) {
      return false;
    }
    s_index[s[i]] = t_index[t[i]] = i;
  }
  return true;
}

int main(int argc, char* argv[]) {
  const std::string s = "paper";
  const std::string t = "title";
  std::cout << IsIsomorphic(s, t) << std::endl;
  return 0;
}
