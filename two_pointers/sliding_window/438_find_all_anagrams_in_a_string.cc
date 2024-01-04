#include <string>
#include <vector>

// 2024/01/04: 看答案写出来.
std::vector<int> FindAnagrams(std::string s, std::string p) {
  int s_size = s.size();
  int p_size = p.size();
  if (s_size < p_size) {
    return std::vector<int>();
  }

  std::vector<int> s_count(26, 0);
  std::vector<int> p_count(26, 0);
  std::vector<int> res;
  for (int i = 0; i < p_size; ++i) {
    ++s_count[s[i] - 'a'];
    ++p_count[p[i] - 'a'];
  }
  if (s_count == p_count) {
    res.push_back(0);
  }

  for (int i = 0; i < s_size - p_size; ++i) {
    --s_count[s[i] - 'a'];
    ++s_count[s[i + p_size] - 'a'];
    if (s_count == p_count) { // 可以直接比较两个vector是否相等.
      res.push_back(i + 1);
    }
  }
  return res;
}
