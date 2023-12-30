#include <algorithm>
#include <iostream>
#include <vector>

// 当下标从0开始时.
// index为p的父节点为(p - 1) / 2
// index为p的左子节点为 2 * p + 1, 右子节点为 2 * p + 2.
class PriorityQueue {
 public:
  // 获得最大值
  int top() { return heap_[0]; }

  // 插入任意值: 把新的数字放在最后一位, 然后上浮.
  void push(int k) {
    heap_.push_back(k);
    Swim(heap_.size() - 1);
  }

  // 删除最大值: 把最后一个数字挪到开头, 然后下沉.
  void pop() {
    heap_[0] = heap_.back();
    heap_.pop_back();
    Sink(0);
  }

 private:
  // 上浮
  void Swim(int pos) {
    while (pos > 0) {
      if (heap_[(pos - 1) / 2] >= heap_[pos]) {
        break;
      }
      std::swap(heap_[(pos - 1) / 2], heap_[pos]);
      pos = (pos - 1) / 2;
    }
  }
  // 下沉
  void Sink(int pos) {
    const int n = heap_.size();
    while (2 * pos + 1 < n) {
      int child = 2 * pos + 1;
      if (child + 1 < n && heap_[child] < heap_[child + 1]) {
        ++child;
      }
      if (heap_[child] > heap_[pos]) {
        std::swap(heap_[child], heap_[pos]);
        pos = child;
      } else {
        break;
      }
    }
  }
  std::vector<int> heap_;
};

int main(int argc, char* argv[]) {
  PriorityQueue priority_queue;
  priority_queue.push(1);
  priority_queue.push(9);
  priority_queue.push(5);
  priority_queue.push(11);
  priority_queue.push(0);
  std::cout << priority_queue.top() << std::endl;
  priority_queue.pop();
  std::cout << priority_queue.top() << std::endl;
  return 0;
}
