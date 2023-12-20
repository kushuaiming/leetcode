#include <iostream>
#include <string>
#include <vector>

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
