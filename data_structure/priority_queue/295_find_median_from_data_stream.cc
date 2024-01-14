#include <queue>

// 2024/01/14: 有思路, 但是实现看了答案.
class MedianFinder {
 public:
  MedianFinder() {}

  void AddNum(int num) {
    if (left_pq.empty() || num <= left_pq.top()) {
      left_pq.push(num);
      if (right_pq.size() + 1 < left_pq.size()) {
        right_pq.push(left_pq.top());
        left_pq.pop();
      }
    } else {
      right_pq.push(num);
      if (right_pq.size() > left_pq.size()) {
        left_pq.push(right_pq.top());
        right_pq.pop();
      }
    }
  }

  double FindMedian() {
    if (left_pq.size() > right_pq.size()) {
      return left_pq.top();
    }
    return (left_pq.top() + right_pq.top()) / 2.0;
  }

 private:
  // 注意两个优先队列的定义.
  std::priority_queue<int, std::vector<int>, std::less<int>> left_pq;
  std::priority_queue<int, std::vector<int>, std::greater<int>> right_pq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->AddNum(num);
 * double param_2 = obj->FindMedian();
 */
