N, M = map(int, input().split())
graph = [[] for _ in range(N)]
E = [list(map(lambda x: int(x)-1, input().split())) for _ in range(M)]
for u, v in E:
    graph[u].append(v)
    graph[v].append(u)

town = [0 for _ in range(N)]
def dfs(fr, n):
    for to in graph[fr]:
        if town[to] == 0:
            town[to] = n
            dfs(to, n)

cnt = 0
for i in range(N):
    if town[i] == 0:
        cnt += 1
        town[i] = cnt
        dfs(i, cnt)

ans = 0
for i in range(cnt):
    e, v = 0, 0
    V = [0] * N
    for u, v in E:
        if town[u] == i+1:
            e += 1
            V[u] = 1
            V[v] = 1
    if e == sum(V) - 1 or sum(V) == 0:
        ans += 1
print(ans)
