#include <iostream>
#include <vector>

// 2024/01/11: 直接抄答案.
// [0, first - 1]是已经使用过的数, [first, nums.size() - 1]是未使用过的数.
void Backtrack(std::vector<std::vector<int>>& res, std::vector<int>& nums,
               std::vector<int>& output, int first) {
  res.push_back(output);
  if (output.size() == nums.size()) {
    return;
  }
  for (int i = first; i < nums.size(); ++i) {
    output.push_back(nums[i]);
    Backtrack(res, nums, output, i + 1);
    output.pop_back();
  }
}

std::vector<std::vector<int>> Subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> res;
  std::vector<int> output;
  Backtrack(res, nums, output, 0);
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> res = Subsets(nums);
  for (const std::vector<int>& subset : res) {
    for (int data : subset) {
      std::cout << data << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
