#include <numeric>
#include <vector>

class UnionFind {
 public:
  UnionFind(int n) : id_(n) { std::iota(id_.begin(), id_.end(), 0); }

  // 查找给定节点的祖先
  int Find(int p) const {
    while (p != id_[p]) {
      p = id_[p];
    }
    return p;
  }

  void Union(int p, int q) { id_[Find(p)] = id_[Find(q)]; }

  bool IsConnected(int p, int q) const { return Find(p) == Find(q); }

 private:
  std::vector<int> id_;
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
