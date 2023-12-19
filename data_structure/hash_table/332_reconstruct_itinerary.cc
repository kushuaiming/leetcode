#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> FindItinerary(
    std::vector<std::vector<std::string>>& tickets) {
  // key: start point, value: multi end point.
  std::unordered_map<std::string, std::multiset<std::string>> hash_table;
  for (const auto& ticket : tickets) {
    hash_table[ticket[0]].insert(ticket[1]);
  }

  std::vector<std::string> ans;
  std::stack<std::string> s;
  s.push("JFK");
  while (!s.empty()) {
    const std::string next = s.top();
    if (hash_table[next].empty()) {
      ans.emplace_back(next);
      s.pop();
    } else {
      s.push(*hash_table[next].begin());
      hash_table[next].erase(hash_table[next].begin());
    }
  }

  // 将结果逆序得到从起点到终点的顺序.
  std::reverse(ans.begin(), ans.end());

  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<std::string>> tickets1 = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  std::vector<std::vector<std::string>> tickets2 = {{"JFK", "SFO"},
                                                    {"JFK", "ATL"},
                                                    {"SFO", "ATL"},
                                                    {"ATL", "JFK"},
                                                    {"ATL", "SFO"}};
  std::vector<std::vector<std::string>> tickets3 = {
      {"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
  std::vector<std ::string> ans = FindItinerary(tickets3);
  for (const std::string& ticket : ans) {
    std::cout << ticket << std::endl;
  }
  return 0;
}
