#include <iostream>
#include <vector>

// 2024/01/10: 直接抄答案.
// [0, first - 1]是已经填过数的, [first, length - 1]是待填数的
void Backtrack(std::vector<std::vector<int>>& result, std::vector<int>& output,
               int first, int length) {
  if (first == length) {
    result.push_back(output);
    return;
  }
  for (int i = first; i < length; ++i) {
    std::swap(output[i], output[first]);
    Backtrack(result, output, first + 1, length);
    std::swap(output[i], output[first]);
  }
}

std::vector<std::vector<int>> Permute(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  Backtrack(result, nums, 0, nums.size());
  return result;
}

// 2024/01/10: 直接抄答案
// 如果需要字典序排列, 则需要用is_visited数组进行记录是否已访问过.
std::vector<std::vector<int>> res;
std::vector<int> temp;
std::vector<int> is_visited;
void Backtrack2(const std::vector<int>& nums) {
  if (temp.size() == nums.size()) {
    res.push_back(temp);
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (is_visited[i]) {
      continue;
    }
    temp.push_back(nums[i]);
    is_visited[i] = true;
    Backtrack2(nums);
    is_visited[i] = false;
    temp.pop_back();
  }
}

std::vector<std::vector<int>> Permute2(std::vector<int>& nums) {
  is_visited.resize(nums.size(), 0);
  Backtrack2(nums);
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 2};
  std::vector<std::vector<int>> result = Permute(nums);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[0].size(); ++j) {
      std::cout << result[i][j] << '\t';
    }
    std::cout << std::endl;
  }
  return 0;
}
