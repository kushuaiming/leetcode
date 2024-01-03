#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// 2024/01/03: 看答案写出来.
// 关键在与哈希表key的设计
std::vector<std::vector<std::string>> groupAnagrams(
    std::vector<std::string>& strs) {
  std::unordered_map<std::string, std::vector<std::string>> hash_table;
  for (const std::string& str : strs) {
    std::string key = str;
    std::sort(key.begin(), key.end());
    hash_table[key].push_back(str);
  }
  std::vector<std::vector<std::string>> res;
  for (auto it = hash_table.begin(); it != hash_table.end(); ++it) {
    res.push_back(it->second);
  }
  return res;
}
