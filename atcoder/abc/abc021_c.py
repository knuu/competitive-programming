N = int(input())
a, b = map(lambda x: int(x)-1, input().split())
M = int(input())
road = [list(map(lambda x: int(x)-1, input().split())) for _ in range(M)]

town = [[] for _ in range(N)]
for x, y in road:
    town[x].append(y)
    town[y].append(x)

dist = [10**9 for _ in range(N)]
dist[a] = 0

import queue
q = queue.Queue()
q.put(a)

while q.qsize():
    f = q.get()
    for t in town[f]:
        if dist[f] + 1 < dist[t]:
            dist[t] = dist[f] + 1
            q.put(t)

dag = [[] for _ in range(N)]
for f in range(N):
    for t in town[f]:
        if dist[t] == dist[f] + 1:
            dag[f].append(t)

q = queue.Queue()

dp = [0 for _ in range(N)]
dp[a] = 1
q.put(a)

check = [False for _ in range(N)]
 
while q.qsize():
    f = q.get()
    for t in dag[f]:
        dp[t] += dp[f]
        dp[t] %= 10**9 + 7
        if not check[t]:
            q.put(t)
            check[t] = True

print(dp[b])
