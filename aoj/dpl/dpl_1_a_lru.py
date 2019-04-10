import functools, sys


@functools.lru_cache(maxsize=None)
def rec(c):
    if c == 0:
        return 0
    ret = INF
    for coin in coins:
        if c - coin >= 0:
            ret = min(ret, rec(c-coin) + 1)
    return ret

INF = 10**6
N, M = map(int, input().split())
coins = [int(x) for x in input().split()]
sys.setrecursionlimit(INF)
print(rec(N))
