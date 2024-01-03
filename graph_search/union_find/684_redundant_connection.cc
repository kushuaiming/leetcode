#include <numeric>
#include <vector>

// 2024/01/03: 直接抄答案.

class UnionFind {
 public:
  // iota函数可以把数组初始化为0到n-1.
  UnionFind(int n) : ids_(n) { std::iota(ids_.begin(), ids_.end(), 0); }

  // 查找给定节点的祖先
  int Find(int p) const {
    while (p != ids_[p]) {
      p = ids_[p];
    }
    return p;
  }

  void Union(int p, int q) { ids_[Find(p)] = ids_[Find(q)]; }

  bool IsConnected(int p, int q) const { return Find(p) == Find(q); }

 private:
  std::vector<int> ids_;
};

std::vector<int> FindRedundantConnection(
    const std::vector<std::vector<int>>& edges) {
  int n = edges.size();
  UnionFind union_find(n + 1);
  for (const auto& edge : edges) {
    int u = edge[0];
    int v = edge[1];
    if (union_find.IsConnected(u, v)) {
      return edge;
    }
    union_find.Union(u, v);
  }
  return {-1, -1};
}
