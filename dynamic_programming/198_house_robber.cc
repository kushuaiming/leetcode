#include <iostream>
#include <vector>

int Rob(std::vector<int>& nums) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return nums[0];
  }
  if (n == 2) {
    return std::max(nums[0], nums[1]);
  }
  int pre2 = nums[0];
  int pre1 = std::max(nums[0], nums[1]);
  for (int i = 2; i < n; ++i) {
    int cur = std::max(pre2 + nums[i], pre1);
    pre2 = pre1;
    pre1 = cur;
  }
  return pre1;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 3, 1};
  std::cout << Rob(nums) << std::endl;
}
