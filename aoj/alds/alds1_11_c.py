from collections import deque
V = int(input())
edge = [[] for _ in range(V)]
for _ in range(V):
    u, _, *v = map(lambda x: int(x)-1, input().split())
    edge[u] = v
dist = [-1] * V
dist[0] = 0
que = deque([0])

while len(que):
    v = que.popleft()
    for c in edge[v]:
        if dist[c] == -1:
            dist[c] = dist[v] + 1
            que.append(c)
for i, d in enumerate(dist):
    print(i+1, d)
