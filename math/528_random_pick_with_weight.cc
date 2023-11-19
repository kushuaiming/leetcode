#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>

// 前缀和 + 二分法
class Solution {
 public:
  Solution(std::vector<int>& w)
      : gen_(std::random_device{}()),
        dis_(1, std::accumulate(w.begin(), w.end(), 0)) {
    std::partial_sum(w.begin(), w.end(), std::back_inserter(pre_));
  }

  int PickIndex() {
    int x = dis_(gen_);
    return std::lower_bound(pre_.begin(), pre_.end(), x) - pre_.begin();
  }

 private:
  std::mt19937 gen_;                       // 伪随机数产生器，用于产生高性能的随机数
  std::uniform_int_distribution<int> dis_; // 随机数分布
  std::vector<int> pre_;
};

int main(int argc, char* argv[]) {
  std::vector<int> weight = {3, 1, 2, 4};
  Solution solution(weight);
  const int index = solution.PickIndex();
  std::cout << "index: " << index << std::endl;
  return 0;
}
