#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
 public:
  LRUCache(int capacity) : size_(capacity) {}

  int get(int key) {
    auto it = hash_.find(key);
    if (it == hash_.end()) {
      return -1;
    }
    cache_.splice(cache_.begin(), cache_, it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    auto it = hash_.find(key);
    if (it != hash_.end()) {
      it->second->second = value;
      return cache_.splice(cache_.begin(), cache_, it->second);
    }
    cache_.insert(cache_.begin(), std::make_pair(key, value));
    hash_[key] = cache_.begin();
    if (cache_.size() > size_) {
      hash_.erase(cache_.back().first);
      cache_.pop_back();
    }
  }

 private:
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash_;
  std::list<std::pair<int, int>> cache_;
  int size_;
};

int main(int argc, char* argv[]) {
  LRUCache* lru_cache = new LRUCache(2);
  lru_cache->put(1, 1);                         // 缓存是 {1=1}
  lru_cache->put(2, 2);                         // 缓存是 {1=1, 2=2}
  std::cout << lru_cache->get(1) << std::endl;  // 返回 1
  lru_cache->put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  std::cout << lru_cache->get(2) << std::endl;  // 返回 -1 (未找到)
  lru_cache->put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  std::cout << lru_cache->get(1) << std::endl;  // 返回 -1 (未找到)
  std::cout << lru_cache->get(3) << std::endl;  // 返回 3
  std::cout << lru_cache->get(4) << std::endl;  // 返回 4
  return 0;
}
