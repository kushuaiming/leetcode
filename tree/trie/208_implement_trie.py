# 2026/05/21: 直接抄答案
class Trie:

    def __init__(self):
        self.children = [None] * 26  # 注: 用 None 进行初始化.
        self.is_end = False

    def insert(self, word: str) -> None:
        node = self  # 用 self 来初始化 node.
        for ch in word:
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                node.children[ch] = Trie()
            node = node.children[ch]
        node.is_end = True

    def search_prefix(self, prefix: str) -> "Trie":  # 这里的返回类型需要前向引用
        node = self
        for ch in prefix:
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                return None
            node = node.children[ch]
        return node

    def search(self, word: str) -> bool:
        node = self.search_prefix(word)
        return node is not None and node.is_end

    def starts_with(self, prefix: str) -> bool:
        return self.search_prefix(prefix) is not None


trie = Trie()
trie.insert("apple")
print(trie.search("apple"))  # 返回 True
print(trie.search("app"))  # 返回 False
print(trie.starts_with("app"))  # 返回 True
trie.insert("app")
print(trie.search("app"))  # 返回 True
