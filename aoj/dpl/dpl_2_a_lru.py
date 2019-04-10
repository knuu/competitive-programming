import functools


@functools.lru_cache(maxsize=None)
def rec(state, v):
    if state == (1 << V) - 1 and v == 0:
        return 0
    ret = INF
    for c, w in edge[v]:
        if not (state >> c & 1):
            ret = min(ret, rec(state | 1 << c, c) + w)
    return ret

INF = 10**6
V, E = map(int, input().split())
edge = [[] for _ in range(V)]
for _ in range(E):
    s, t, w = map(int, input().split())
    edge[s].append((t, w))
ans = rec(0, 0)
print(ans if ans != INF else -1)
