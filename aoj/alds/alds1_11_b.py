def dfs(v, cnt):
    D[v] = cnt
    cnt += 1
    for c in edge[v]:
        if D[c] == -1:
            cnt = dfs(c, cnt)
    F[v] = cnt
    cnt += 1
    return cnt


V = int(input())
edge = [[] for _ in range(V)]
for _ in range(V):
    u, _, *v = map(lambda x: int(x)-1, input().split())
    edge[u] = sorted(v)
D, F = [-1] * V, [-1] * V
c = 1
for i in range(V):
    if D[i] == -1:
        c = dfs(i, c)
for i, (d, f) in enumerate(zip(D, F)):
    print(i+1, d, f)
