def dfs(v, bit):
    if (bit, v) in memo:
        return memo[(bit, v)]
    ret = D[v]
    for i in range(N):
        if A[v][i] and not (bit >> i & 1):
            ret = max(ret, dfs(i, bit | 1 << i) + D[v])
    memo[(bit, v)] = ret
    return ret

N, K = map(int, input().split())
D = [int(input()) for i in range(N)]
A = [[False] * N for i in range(N)]
for _ in range(K):
    x, y = map(lambda x: int(x)-1, input().split())
    A[x][y] = A[y][x] = True
memo = dict()
print(max(dfs(i, 1 << i) for i in range(N)))
