import functools
N, W = map(int, input().split())
v, w = [0] * N, [0] * N
for i in range(N):
    v[i], w[i] = map(int, input().split())


@functools.lru_cache(maxsize=None)
def rec(i, weight):
    if i == N:
        return 0
    elif weight + w[i] <= W:
        return max(rec(i+1, weight), rec(i+1, weight + w[i]) + v[i])
    else:
        return rec(i+1, weight)
print(rec(0, 0))
