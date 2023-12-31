#include <iostream>
#include <numeric>
#include <vector>

// 思路: 前缀和
// 代码实现: 为了方便求差, prefix_sum_要在最开始放一个0.
class NumArray {
 public:
  NumArray(std::vector<int>& nums) : prefix_sum_(nums.size() + 1, 0) {
    std::partial_sum(nums.begin(), nums.end(), prefix_sum_.begin() + 1);
  }

  int SumRange(int left, int right) {
    return prefix_sum_[right + 1] - prefix_sum_[left];
  }

 private:
  std::vector<int> prefix_sum_;
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray* obj = new NumArray(nums);
  const int param_1 = obj->SumRange(0, 2);
  std::cout << param_1 << std::endl;
  return 0;
}
