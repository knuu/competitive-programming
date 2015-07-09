V = int(input())
E = int(input())
dist = [[float('inf')] * V for _ in range(V)]
for i in range(V): dist[i][i] = 0
for _ in range(E):
    a, b, c, d = map(int, input().split(','))
    dist[a-1][b-1], dist[b-1][a-1] = c, d
fr, to, money, cost = map(int, input().split(','))
for k in range(V):
    for i in range(V):
        for j in range(V):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
print(money-cost-dist[fr-1][to-1]-dist[to-1][fr-1])
