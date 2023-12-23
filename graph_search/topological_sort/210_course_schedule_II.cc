#include <algorithm>
#include <queue>
#include <vector>

enum class NodeStatus {
  kUnvisited,
  kSearching,
  kSearched,
};

// 存储有向图
std::vector<std::vector<int>> edges;
// 标记每个节点的状态
std::vector<NodeStatus> node_status;
// 用数组模拟栈
std::vector<int> result;
// 判断有向图中是否有环
bool valid = true;

void DFS(int u) {
  node_status[u] = NodeStatus::kSearching;
  // 搜索相邻节点, 如果有环, 则立刻停止搜索.
  for (int v : edges[u]) {
    if (node_status[v] == NodeStatus::kUnvisited) {
      // 如果未搜索, 那么搜索相邻节点.
      DFS(v);
      if (!valid) {
        return;
      }
    } else if (node_status[v] == NodeStatus::kSearching) {
      // 如果搜索中, 说明找到了环.
      valid = false;
      return;
    }
  }
  // 节点标记成已完成并入栈.
  node_status[u] = NodeStatus::kSearched;
  result.push_back(u);
}

// DFS: 用一个栈来存储所有已经搜索完成的节点
// 关键存储节点的访问状态和判断是否有环.
std::vector<int> FindOrder(int num_course,
                           const std::vector<std::vector<int>> prerequisites) {
  edges.resize(num_course);
  node_status.resize(num_course);
  for (const auto& prerequisite : prerequisites) {
    edges[prerequisite[1]].push_back(prerequisite[0]);
  }
  for (int i = 0; i < num_course; ++i) {
    if (node_status[i] == NodeStatus::kUnvisited) {
      DFS(i);
    }
    if (!valid) {
      return {};
    }
  }
  std::reverse(result.begin(), result.end());
  return result;
}

std::vector<int> indeg;
// BFS: 关键是想到利用入度来辅助判断该节点(课程)是否可以选择了.
std::vector<int> FindOrder(int num_course,
                           const std::vector<std::vector<int>> prerequisites) {
  edges.resize(num_course);
  indeg.resize(num_course);
  for (const auto& prerequisite : prerequisites) {
    edges[prerequisite[1]].push_back(prerequisite[0]);
    ++indeg[prerequisite[0]];
  }

  std::queue<int> q;
  for (int i = 0; i < num_course; ++i) {
    // 将所有入度为0的节点放入队列中
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    result.push_back(u);
    for (int v : edges[u]) {
      --indeg[v];
      if (indeg[v] == 0) {
        // 此时可以选v对应的课程了.
        q.push(v);
      }
    }
  }

  if (result.size() != num_course) {
    return {};
  }
  return result;
}