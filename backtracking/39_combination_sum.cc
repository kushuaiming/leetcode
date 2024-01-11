#include <iostream>
#include <vector>

// 2024/01/11: 自己完全写出来.
void Backtrack(std::vector<int>& candidates, int target,
               std::vector<std::vector<int>>& res, std::vector<int>& output,
               int sum, int first) {
  if (sum == target) {
    res.push_back(output);
    return;
  }
  if (first == candidates.size()) {
    return;
  }
  int counts = (target - sum) / candidates[first];
  for (int i = 0; i <= counts; ++i) {
    for (int j = 0; j < i; ++j) {
      output.push_back(candidates[first]);
      sum += candidates[first];
    }
    Backtrack(candidates, target, res, output, sum, first + 1);
    for (int j = 0; j < i; ++j) {
      sum -= candidates[first];
      output.pop_back();
    }
  }
}

std::vector<std::vector<int>> CombinationSum(std::vector<int>& candidates,
                                             int target) {
  std::vector<std::vector<int>> res;
  std::vector<int> output;
  Backtrack(candidates, target, res, output, 0, 0);
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<int> candidates = {2, 3, 6, 7};
  std::vector<std::vector<int>> res = CombinationSum(candidates, 7);
  for (const std::vector<int>& subset : res) {
    for (int data : subset) {
      std::cout << data << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
