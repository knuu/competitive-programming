import functools


@functools.lru_cache(maxsize=None)
def rec(l, r):
    # [l, r)
    if l+1 == r:
        return 0
    ret = INF
    for mid in range(l+1, r):
        ret = min(ret, rec(l, mid) + rec(mid, r) + R[l] * R[mid] * C[r-1])
    return ret

INF = 10**9
N = int(input())
R, C = [], []
for i in range(N):
    r, c = map(int, input().split())
    R.append(r), C.append(c)
print(rec(0, N))
