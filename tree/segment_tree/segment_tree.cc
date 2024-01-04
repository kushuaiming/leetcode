#include <algorithm>
#include <numeric>
#include <vector>

// reference:
// https://zh.wikipedia.org/zh-cn/%E7%B7%9A%E6%AE%B5%E6%A8%B9_(%E5%84%B2%E5%AD%98%E5%8D%80%E9%96%93)#:~:text=%E7%BA%BF%E6%AE%B5%E6%A0%91%EF%BC%88%E8%8B%B1%E8%AF%AD%EF%BC%9ASegment%20tree,%E6%9F%90%E4%B8%80%E7%82%B9%E7%9A%84%E6%89%80%E6%9C%89%E5%8C%BA%E9%97%B4%E3%80%82&text=%E6%98%AF%E7%AC%A6%E5%90%88%E6%9D%A1%E4%BB%B6%E7%9A%84%E5%8C%BA%E9%97%B4%E6%95%B0%E9%87%8F%E3%80%82
template <typename T>
class SegMinTree {
 public:
  // 新建一个最小值线段树用于处理[0, n)的数据
  SegMinTree(int n) : N(n), values_(4 * n), deltas_(4 * n) {}

  // 返回指定位置的数据
  T Get(int index) const { return GetRangeMin(index, index + 1); }

  // 将数据写入指定位置
  void Set(int index, T value) {
    IncrementRange(index, index + 1, value - Get(index));
  }

  // 返回区间上的最小值
  T GetRangeMin(int start, int end) const {
    return Query(FullSegment(), start, end);
  }

  // 对一段区间上的所有值加上同一个增量
  void IncrementRange(int start, int end, T delta) {
    Increment(FullSegment(), start, end, delta);
  }

 private:
  struct Segment {
    int id;
    int start;
    int end;

    bool Overlaps(int start, int end) const {
      return (this->start < end) && (this->end > start);
    }
    bool IsIn(int start, int end) const {
      return (start <= this->start) && (this->end <= end);
    }
    Segment Left() const {
      return {.id = id * 2, .start = start, .end = (start + end + 1) / 2};
    }
    Segment Right() const {
      return {.id = id * 2 + 1, .start = (start + end + 1) / 2, .end = end};
    }
  };

  Segment FullSegment() const { return {.id = 1, .start = 0, .end = N}; }

  T Query(const Segment& segment, int start, int end) const {
    if (!segment.Overlaps(start, end)) {
      return std::numeric_limits<T>::max();
    }
    if (segment.IsIn(start, end)) {
      return values_[segment.id];
    }
    // 处理部分重合的情况
    T children_value = std::min(Query(segment.Left(), start, end),
                                Query(segment.Right(), start, end));
    return deltas_[segment.id] + children_value;
  }

  // 返回segment里面的新的最小值(跟[start, end)无关).
  T Increment(const Segment& segment, int start, int end, T delta) {
    if (!segment.Overlaps(start, end)) {
      return values_[segment.id];
    }
    if (!segment.IsIn(start, end)) {
      values_[segment.id] += delta;
      delta_[segment.id] += delta;
      return values_[segment.id];
    }
    // 处理部分重合的情况
    T value = std::min(Increment(segment.Left(), start, end, delta),
                       Increment(segment.Right(), start, end, delta));
    value += deltas_[segment.id];
    values_[segment.id] = value;
    return value;
  }

  const int N;
  std::vector<T> values_;
  std::vector<T> deltas_;  // deltas_[id] 里的值只用于子节点.
};
