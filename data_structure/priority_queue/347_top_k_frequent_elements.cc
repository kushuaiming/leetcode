#include <queue>
#include <unordered_map>
#include <vector>

// 2024/01/12: 不看答案自己实现.

std::vector<int> TopKFrequent(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> hash_map;
  for (int num : nums) {
    ++hash_map[num];
  }

  std::priority_queue<std::pair<int, int>> pq;
  for (const auto& data : hash_map) {
    pq.push(std::make_pair(data.second, data.first));
  }

  std::vector<int> res;
  for (int i = 0; i < k; ++i) {
    res.push_back(pq.top().second);
    pq.pop();
  }
  return res;
}
