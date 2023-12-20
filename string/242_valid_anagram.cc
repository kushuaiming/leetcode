#include <string>
#include <unordered_map>
#include <vector>

bool IsAnagram(const std::string& s, const std::string& t) {
  // 需要有不相等的判断.
  if (s.size() != t.size()) {
    return false;
  }
  std::vector<int> counts(26, 0);
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    ++counts[s[i] - 'a'];
    --counts[t[i] - 'a'];
  }
  for (int count : counts) {
    if (count) {
      return false;
    }
  }
  return true;
}
