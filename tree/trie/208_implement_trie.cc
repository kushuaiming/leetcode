#include <iostream>
#include <string>
#include <vector>

// 2023/12/22: 直接拷贝过来的, 从评论来看, 考的频率较高, 需要注意.
class Trie {
 public:
  Trie() : children_(26), is_end_(false) {}

  void Insert(const std::string& word) {
    Trie* node = this;
    for (char ch : word) {
      ch -= 'a';
      if (node->children_[ch] == nullptr) {
        node->children_[ch] = new Trie();
      }
      node = node->children_[ch];
    }
    node->is_end_ = true;
  }

  bool Search(const std::string& word) {
    Trie* node = this->SearchPrefix(word);
    return node != nullptr && node->is_end_;
  }

  bool StartWith(const std::string& prefix) {
    return this->SearchPrefix(prefix) != nullptr;
  }

 private:
  Trie* SearchPrefix(const std::string& prefix) {
    Trie* node = this;
    for (char ch : prefix) {
      ch -= 'a';
      if (node->children_[ch] == nullptr) {
        return nullptr;
      }
      node = node->children_[ch];
    }
    return node;
  }

  std::vector<Trie*> children_;
  bool is_end_;
};

int main(int argc, char* argv[]) {
  Trie trie;
  trie.Insert("apple");
  std::cout << "search apple: " << trie.Search("apple") << std::endl;
  std::cout << "search app: " << trie.Search("app") << std::endl;
  std::cout << "start with app: " << trie.StartWith("app") << std::endl;
  trie.Insert("app");
  std::cout << "search app: " << trie.Search("app") << std::endl;
  return 0;
}
