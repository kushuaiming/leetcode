#include <iostream>
#include <vector>

// Fisher-Yates
class Solution {
 public:
  Solution(std::vector<int> nums) : origin_(std::move(nums)) {}

  const std::vector<int>& reset() { return origin_; }

  std::vector<int> shuffle() {
    if (origin_.empty()) {
      return {};
    }
    std::vector<int> shuffled(origin_);
    const int n = origin_.size();
    // 正向洗牌
    for (int i = 0; i < n; ++i) {
      // 关键公式: 每次从剩余的牌中([i, n)的下标中)选一个放在i的位置.
      const int j = i + rand() % (n - i);
      std::swap(shuffled[i], shuffled[j]);
    }
    // // 或者反向洗牌
    // for (int i = n - 1; i >= 0; --i) {
    //   std::swap(shuffled[i], shuffled[rand() % (i + 1)]);
    // }
    return shuffled;
  }

 private:
  std::vector<int> origin_;
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 3};
  Solution solution(nums);

  std::vector<int> shuffled_nums = solution.shuffle();
  for (int shuffled_num : shuffled_nums) {
    std::cout << shuffled_num << "\t";
  }
  std::cout << std::endl;

  const std::vector<int>& reseted_nums = solution.reset();
  for (int reseted_num : reseted_nums) {
    std::cout << reseted_num << "\t";
  }
  std::cout << std::endl;

  return 0;
}
