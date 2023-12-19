#include <list>
#include <vector>

int Hash(int key, int table_size) { return key % table_size; }

template <typename T>
class HashTable {
 public:
  HashTable(int size = 31) {
    hash_table_.reserve(size);
    hash_table_.resize(size);
  }

  ~HashTable() {}

  bool Contains(const T& obj) const {
    const int hash_value = MyHash(obj);
    const std::list<T>& slot = hash_table_[hash_value];
    std::list<T>::const_iterator it = slot.cbegin();
    while (it != slot.cend()) {
      if (*it == obj) {
        break;
      }
      ++it;
    }
    return it != slot.cend();
  }

  bool Insert(const T& obj) {
    if (Contains(obj)) {
      return false;
    }
    const int hash_value = MyHash(obj);
    std::list<T>& slot = hash_table_[hash_value];
    slot.push_front(obj);
    return true;
  }

  bool Remove(const T& obj) {
    std::list<T>& slot = hash_table_[MyHash(obj)];
    auto it = std::find(slot.begin(), slot.end(), obj);
    if (it == slot.end()) {
      return false;
    }
    slot.erase(it);
    return true;
  }

 private:
  int MyHash(const T& obj) const { return Hash(obj, hash_table_.size()); }

  std::vector<std::list<T>> hash_table_;
};
