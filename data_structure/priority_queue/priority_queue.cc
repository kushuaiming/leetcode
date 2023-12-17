#include <priority_queue.h>

#include <algorithm>

void PriorityQueue::push(int k) {
  heap_.push_back(k);
  Swim(heap_.size() - 1);
}

void PriorityQueue::pop() {
  heap_[0] = heap_.back();
  heap_.pop_back();
  Sink(0);
}

void PriorityQueue::Swim(int pos) {
  while (pos > 1 && heap_[pos / 2] < heap_[pos]) {
    std::swap(heap_[pos / 2], heap_[pos]);
    pos /= 2;
  }
}

void PriorityQueue::Sink(int pos) {
  const int n = heap_.size();
  while (2 * pos <= n) {
    int i = 2 * pos;
    if (i < n && heap_[i] < heap_[i + 1]) {
      ++i;
    }
    if (heap_[pos] >= heap_[i]) {
      break;
    }
    std::swap(heap_[pos], heap_[i]);
    pos = i;
  }
}
