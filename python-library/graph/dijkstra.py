# G: vec of (to, cost)
# V: num of vecs
def dijkstra(s):
    """Dijkstra's algorithm : find the shortest path from s
       s: start point
    """

    que = PQueue()
    d = [INF for _ in range(V)] # distance
    d[s] = 0
    que.push((0, s))

    while not que.qsize():
        dist, v = que.get()
        dist = abs(dist)
        if d[v] < dist: continue
        for to, cost in G[v]:
            if d[v] + cost < d[to]:
                d[to] = d[v] + cost
                que.put((-d[to], to))
