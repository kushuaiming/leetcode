#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// 关键1: 用哈希表记录起止机场, 其中 key 是起始机场, value 是一个多重集合, 表示对应的终止机场.
// 因为一个人可能坐过重复的线路, 所以我们需要使用多重集合存储重复值.
// 关键2: 存储完成之后, 我们可以利用栈来恢复从终点到起点飞行的顺序.
// 关键3: 最后将结果逆序得到从起点到终点的顺序.
std::vector<std::string> FindItinerary(
    const std::vector<std::vector<std::string>>& tickets) {
  std::unordered_map<std::string, std::multiset<std::string>> hash_table;
  for (const auto& ticket : tickets) {
    hash_table[ticket[0]].insert(ticket[1]);
  }

  std::vector<std::string> res;
  std::stack<std::string> s;
  s.push("JFK");
  while (!s.empty()) {
    const std::string next = s.top();
    if (hash_table[next].empty()) {
      res.emplace_back(next);
      s.pop();
    } else {
      s.push(*hash_table[next].begin());
      hash_table[next].erase(hash_table[next].begin());
    }
  }

  std::reverse(res.begin(), res.end());

  return res;
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
  std::vector<std ::string> res = FindItinerary(tickets3);
  for (const std::string& ticket : res) {
    std::cout << ticket << std::endl;
  }
  return 0;
}
