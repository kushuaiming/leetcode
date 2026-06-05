# 2026/06/05: 直接抄答案, 用滚动数组的方式
def climb_stairs(n: int) -> int:
    p, q, r = 0, 0, 1
    for _ in range(n):
        p = q
        q = r
        r = p + q
    return r


# 2026/06/05: 自己实现, 但是可以对空间进行优化.
def climb_stairs(n: int) -> int:
    if n == 1:
        return 1
    elif n == 2:
        return 2

    dp = [0] * n
    dp[0] = 1
    dp[1] = 2

    for i in range(2, n):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[-1]


n = 3
print(climb_stairs(1))
