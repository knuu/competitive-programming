from collections import deque
K = int(input())
INF = 10 ** 6
dist = [INF] * K

deq = deque()
deq.append((1, 0))
while True:
    v, d = deq.popleft()
    if dist[v] != INF:
        continue
    if v == 0:
        print(d + 1)
        break
    dist[v] = d
    if dist[(v + 1) % K] == INF:
        deq.append(((v + 1) % K, d + 1))
    if dist[v * 10 % K] == INF:
        deq.appendleft((v * 10 % K, d))
