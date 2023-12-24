#include <algorithm>
#include <iostream>
#include <vector>

int FindContentChildren(std::vector<int>& children, std::vector<int>& cookies) {
  std::sort(children.begin(), children.end());
  std::sort(cookies.begin(), cookies.end());
  int count = 0;
  int i = 0;
  int j = 0;
  while (i < children.size() && j < cookies.size()) {
    if (children[i] <= cookies[j]) {
      ++j;
      ++count;
    }
    ++i;
  }
  return count;
}

int main(int argrc, char* argv[]) {
  std::vector<int> g{1, 2, 3};
  std::vector<int> s{1, 1};
  std::cout << FindContentChildren(g, s) << std::endl;
}
