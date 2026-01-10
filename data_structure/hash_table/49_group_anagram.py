from typing import List

# 2026/01/10 思路没问题, 实现上要注意 ord 的使用, 同时注意字典的 key 不能是 List, 只能是 Tuple.
def word_letter_count(word: str) -> tuple:
    word_letter_counts = [0] * 26
    for letter in word:
        word_letter_counts[ord(letter) - ord('a')] += 1
    return tuple(word_letter_counts)

def group_anagrams(strs: List[str]) -> List[List[str]]:
    anagram_dict = {}
    for word in strs:
        counts = word_letter_count(word)
        if counts not in anagram_dict:
            anagram_dict[counts] = [word]
        else:
            anagram_dict[counts].append(word)
    
    return list(anagram_dict.values())

# 2026/01/10: 更主流的做法, 用排序后的字符串作为字典的 key, 这里要注意要先排序后拼接回字符串. 注意最后返回值的写法.
def group_anagrams2(strs: List[str]) -> List[List[str]]:
    anagram_dict = {}
    for word in strs:
        sorted_word = "".join(sorted(word))
        if sorted_word not in anagram_dict:
            anagram_dict[sorted_word] = []

        anagram_dict[sorted_word].append(word)

    return list(anagram_dict.values())

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
group_anagrams_result = group_anagrams2(strs)
print(group_anagrams_result)
