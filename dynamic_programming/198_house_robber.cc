#include <iostream>
#include <vector>

// 2024/01/12: 不看答案自己实现.

int Rob(std::vector<int>& nums) {
  if (nums.size() == 1) {
    return nums[0];
  }
  int n = nums.size();
  int pre_pre = nums[0];
  int pre = std::max(nums[0], nums[1]);
  for (int i = 2; i < nums.size(); ++i) {
    int cur = std::max(pre, pre_pre + nums[i]);
    pre_pre = pre;
    pre = cur;
  }
  return pre;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 3, 1};
  std::cout << Rob(nums) << std::endl;
}
