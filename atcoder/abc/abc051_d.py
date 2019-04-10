N, M = map(int, input().split())
INF = 10 ** 9
adjs = [[INF] * N for _ in range(N)]
for i in range(N):
    adjs[i][i] = 0
edges = []
for _ in range(M):
    a, b, c = map(lambda x: int(x) - 1, input().split())
    c += 1
    edges.append((a, b, c))
    adjs[a][b] = adjs[b][a] = c

for k in range(N):
    for i in range(N):
        for j in range(N):
            adjs[i][j] = min(adjs[i][j], adjs[i][k] + adjs[k][j])

print(sum(adjs[a][b] != c and adjs[b][a] != c for a, b, c in edges))
