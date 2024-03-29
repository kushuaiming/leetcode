常见的位预算符号包括: "^"按位异或, "&"按位与, "|"按位或, "~"取反, "<<"算术左移, ">>"算术右移

|     ^      |     &     |     \|     |
|    ----    |    ----   |    ----    |
| x ^ 0 = x  | x & 0 = 0 | x \| 0 = x |
| x ^ 1 = ~x | x & 1 = x | x \| 1 = 1 |
| x ^ 1 = ~x | x & x = x | x \| x = x |

- n&(n-1)可以**去除**n的位级表示中最低的那一位, 例如对于二进制1111 0100, 减去1得到1111 0011, 两个数按位与得到1111 0000.
  - n & (n-1) == 0 说明n是2的幂
  - 不断使用 n &= (n - 1)直到为0, 可以计算n的二进制中1的个数
- n&(-n)可以**得到**n的位级表示中最低的那一位, 例如对于二进制1111 0100, 取负得到0000 1100, 两个数按位与得到0000 0100.
- 巧妙利用Mask
  - ```int mask = 0b01010101010101010101010101010101```
  - 利用Mask判断奇数位是否有1: ```n & mask```
  - 交换奇数偶数位的值:```n >> 1 & mask | (n & mask) << 1```

## 刷题顺序
- 338. 比特位计数
- 461. 汉明距离