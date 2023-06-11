# LeetCode
The algorithms form [Leetcode](https://leetcode.cn/).
## 原则
- 重点在于理解并记忆现有的解题思路, 而不是自己想.
- 关注算法本身的复杂度, 而不是打败了多少...的数据
- 思路 + 代码细节两条腿走路
- 主要关注最常见的算法, 冷门的解决方式在面试时不会得到认可
- 题目阅读时要明确函数的输入和输出
## 代码编写
- 由于刷题时会看各个不同来源的讲解, 代码风格会很不一样, 所以需要自己做好统一.
- 代码清晰程度 > 代码简洁程度
### 命名
- 返回的结果可以命名为result或者answer
- 左右区间的命名可以从如下中选择
  - left / right
  - start(begin) / end
  - first / last
## 算法
### 二分查找Binary Search
- 需要明确区间的开闭性, 左闭右开(满足C++/Python的语言习惯)或者左闭右闭(便于处理边界条件).
- 直接用(right + left) / 2可能在计算加法时出现溢出, left + (right - left) / 2可以避免这种情况.