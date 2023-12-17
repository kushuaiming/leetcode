#include <vector>

class PriorityQueue {
 public:
  int top() { return heap_[0]; }
  void push(int k);
  void pop();

 private:
  void Swim(int pos);
  void Sink(int pos);
  std::vector<int> heap_;
};
