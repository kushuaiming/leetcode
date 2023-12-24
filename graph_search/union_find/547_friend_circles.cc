#include <iostream>
#include <vector>

class UnionFind {
 public:
  UnionFind(int n) {
    id_.resize(n);
    for (int i = 0; i < n; ++i) {
      id_[i] = i;
    }
  }

  int Find(int p) {
    while (id_[p] != p) {
      p = id_[p];
    }
    return p;
  }

  void Union(int p, int q) { id_[Find(p)] = id_[Find(q)]; }

  int RootNumber() {
    int counts = 0;
    for (int i = 0; i < id_.size(); ++i) {
      if (id_[i] == i) {
        ++counts;
      }
    }
    return counts;
  }

 private:
  std::vector<int> id_;
};

int FindCircleNum(std::vector<std::vector<int>>& is_connected) {
  const int n = is_connected.size();
  UnionFind union_find(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (is_connected[i][j] == 1) {
        union_find.Union(i, j);
      }
    }
  }
  return union_find.RootNumber();
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> is_connected = {
      {1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  std::cout << FindCircleNum(is_connected) << std::endl;
  return 0;
}
