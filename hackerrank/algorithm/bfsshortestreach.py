import heapq
for i in range(int(input())):
    V, E = map(int, input().split())
    edge = [[] for _ in range(V)]
    for _ in range(E):
        fr, to = map(lambda x: int(x)-1, input().split())
        edge[fr].append(to)
        edge[to].append(fr)
    s = int(input()) - 1
    dist = [float('inf')] * V
    dist[s] = 0
    pque = [(0, s)]
    while pque:
        now_dist, now_node = heapq.heappop(pque)
        if dist[now_node] < now_dist: continue
        for next_node in edge[now_node]:
            if now_dist + 6 < dist[next_node]:
                dist[next_node] = now_dist + 6
                heapq.heappush(pque, (dist[next_node], next_node))
    print(*[-1 if x == float('inf') else x for x in dist if x])
